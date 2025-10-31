{
  description = "QMK firmware development environment";

  inputs = {
    nixpkgs.url = "github:NixOS/nixpkgs/nixos-unstable";
    flake-utils.url = "github:numtide/flake-utils";
  };

  outputs = { self, nixpkgs, flake-utils }:
    flake-utils.lib.eachDefaultSystem (system:
      let
        pkgs = nixpkgs.legacyPackages.${system};

        # Python environment with additional dependencies QMK might need
        pythonEnv = pkgs.python3.withPackages (ps: with ps; [
          pillow
          pygments
        ]);

        # Helper script to initialize QMK environment
        qmk-init = pkgs.writeShellScriptBin "qmk-init" ''
          set -e

          USERSPACE_DIR="$PWD"
          QMK_HOME="$(dirname "$PWD")/qmk_firmware"

          echo "QMK Development Environment Setup"
          echo "=================================="
          echo ""

          # Check if QMK firmware exists, if not, run qmk setup
          if [ ! -d "$QMK_HOME" ]; then
            echo "QMK firmware not found at $QMK_HOME"
            echo "Running 'qmk setup' to clone QMK firmware repository..."
            echo ""
            qmk setup -y -H "$QMK_HOME"
          else
            echo "✓ QMK firmware found at $QMK_HOME"
          fi

          # Configure QMK home directory
          echo ""
          echo "Configuring QMK home directory to: $QMK_HOME"
          qmk config user.qmk_home="$QMK_HOME"

          # Configure overlay directory
          echo "Configuring overlay directory to: $USERSPACE_DIR"
          qmk config user.overlay_dir="$USERSPACE_DIR"

          echo ""
          echo "QMK Configuration:"
          qmk config

          echo ""
          echo "✓ Setup complete!"
          echo ""
          echo "To build firmware for crkbd/rev4_1:"
          echo "  qmk compile -kb crkbd/rev4_1/standard -km jeremy"
          echo ""
          echo "To build all configured keyboards:"
          echo "  qmk userspace-compile"
        '';

        # Helper script to build crkbd firmware
        build-crkbd = pkgs.writeShellScriptBin "build-crkbd" ''
          echo "Building crkbd/rev4_1 firmware..."
          qmk compile -kb crkbd/rev4_1/standard -km jeremy
        '';

        # Helper script to build all userspace keyboards
        build-all = pkgs.writeShellScriptBin "build-all" ''
          echo "Building all configured keyboards..."
          qmk userspace-compile
        '';

        # Helper script to flash crkbd firmware
        flash-crkbd = pkgs.writeShellScriptBin "flash-crkbd" ''
          set -e

          FIRMWARE_FILE="crkbd_rev4_1_standard_jeremy.uf2"

          echo "╔════════════════════════════════════════════════════════════╗"
          echo "║  Flashing crkbd/rev4_1 Firmware                           ║"
          echo "╚════════════════════════════════════════════════════════════╝"
          echo ""

          # Build the firmware first
          echo "Building firmware..."
          qmk compile -kb crkbd/rev4_1/standard -km jeremy

          if [ ! -f "$FIRMWARE_FILE" ]; then
            echo "❌ Error: Firmware file $FIRMWARE_FILE not found!"
            exit 1
          fi

          echo ""
          echo "✓ Firmware built successfully: $FIRMWARE_FILE"
          echo ""
          echo "══════════════════════════════════════════════════════════════"
          echo "  Put your keyboard into bootloader mode now:"
          echo "    - Press RESET button, or"
          echo "    - Double-tap RESET button, or"
          echo "    - Hold BOOT while plugging in USB"
          echo "══════════════════════════════════════════════════════════════"
          echo ""
          echo "Waiting for bootloader drive to mount..."
          echo "(Press Ctrl+C to cancel)"
          echo ""

          # Common mount points for RP2040 bootloader
          MOUNT_POINTS=(
            "/media/$USER/RPI-RP2"
            "/run/media/$USER/RPI-RP2"
            "/mnt/RPI-RP2"
            "/media/RPI-RP2"
          )

          FOUND=false
          MOUNT_PATH=""

          # Poll for the drive to appear (check every second for 60 seconds)
          for i in {1..60}; do
            for mount_point in "''${MOUNT_POINTS[@]}"; do
              if [ -d "$mount_point" ]; then
                MOUNT_PATH="$mount_point"
                FOUND=true
                break 2
              fi
            done

            # Show a dot every second to indicate we're waiting
            echo -n "."
            sleep 1
          done

          echo ""
          echo ""

          if [ "$FOUND" = true ]; then
            echo "✓ Bootloader drive found at: $MOUNT_PATH"
            echo ""
            echo "Copying firmware..."
            cp -v "$FIRMWARE_FILE" "$MOUNT_PATH/"

            echo ""
            echo "✓ Firmware flashed successfully!"
            echo "  The keyboard will reboot automatically."
          else
            echo "❌ Timeout: Bootloader drive not found after 60 seconds."
            echo ""
            echo "   Please check:"
            echo "   - Keyboard is connected via USB"
            echo "   - Keyboard is in bootloader mode"
            echo "   - USB cable supports data transfer"
            echo ""
            echo "   You can manually flash by copying:"
            echo "   $FIRMWARE_FILE"
            echo "   to the RPI-RP2 drive when it appears."
            exit 1
          fi
        '';

        # Generic flash script for any keyboard
        flash = pkgs.writeShellScriptBin "flash" ''
          set -e

          if [ $# -lt 2 ]; then
            echo "Usage: flash <keyboard> <keymap>"
            echo ""
            echo "Example:"
            echo "  flash crkbd/rev4_1/standard jeremy"
            echo ""
            exit 1
          fi

          KEYBOARD="$1"
          KEYMAP="$2"

          echo "╔════════════════════════════════════════════════════════════╗"
          echo "║  QMK Flash Helper                                          ║"
          echo "╚════════════════════════════════════════════════════════════╝"
          echo ""
          echo "Keyboard: $KEYBOARD"
          echo "Keymap:   $KEYMAP"
          echo ""

          # Use QMK's built-in flash command which handles different bootloaders
          qmk flash -kb "$KEYBOARD" -km "$KEYMAP"
        '';

      in
      {
        devShells.default = pkgs.mkShell {
          buildInputs = with pkgs; [
            # QMK CLI
            qmk

            # Python environment for additional tools
            pythonEnv

            # Compilers and toolchains
            gcc-arm-embedded          # ARM GCC toolchain for STM32, RP2040, etc.
            pkgsCross.avr.buildPackages.gcc  # AVR GCC toolchain
            avrdude                   # AVR programmer

            # Build tools
            gnumake
            git

            # Flashing tools
            dfu-util                  # DFU flashing utility
            dfu-programmer            # Atmel DFU programmer
            teensy-loader-cli         # Teensy programmer

            # Additional utilities
            diffutils
            coreutils

            # Helper scripts
            qmk-init
            build-crkbd
            build-all
            flash-crkbd
            flash
          ];

          shellHook = ''
            export USERSPACE_DIR="$PWD"
            export QMK_HOME="$(dirname "$PWD")/qmk_firmware"

            echo ""
            echo "╔════════════════════════════════════════════════════════════╗"
            echo "║  QMK Firmware Development Environment                     ║"
            echo "╚════════════════════════════════════════════════════════════╝"
            echo ""
            echo "Userspace: $USERSPACE_DIR"
            echo "QMK Home:  $QMK_HOME"
            echo ""

            # Check if QMK is set up
            if [ ! -d "$QMK_HOME" ]; then
              echo "⚠  QMK firmware not found!"
              echo "   Run 'qmk-init' to set up the QMK environment"
              echo ""
            elif [ -z "$(qmk config user.overlay_dir 2>/dev/null | grep qmk_userspace)" ]; then
              echo "⚠  QMK overlay directory not configured!"
              echo "   Run 'qmk-init' to configure the environment"
              echo ""
            else
              echo "✓  QMK environment is configured"
              echo ""
            fi

            echo "Available commands:"
            echo "  qmk-init       - Initialize/verify QMK setup"
            echo ""
            echo "Build commands:"
            echo "  build-crkbd    - Build crkbd/rev4_1 firmware"
            echo "  build-all      - Build all configured keyboards"
            echo ""
            echo "Flash commands:"
            echo "  flash-crkbd    - Build and flash crkbd/rev4_1"
            echo "  flash <kb> <km> - Build and flash any keyboard"
            echo "  qmk flash      - QMK's built-in flash command"
            echo ""
            echo "Examples:"
            echo "  flash-crkbd"
            echo "  flash crkbd/rev4_1/standard jeremy"
            echo "  qmk compile -kb crkbd/rev4_1/standard -km jeremy"
            echo ""
          '';
        };
      }
    );
}
