# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## Overview

This is a QMK userspace repository that maintains custom keyboard layouts/keymaps separately from the main QMK firmware repository. It uses QMK's external userspace feature to manage keymaps for multiple keyboards.

## Build System

### Development Environment Setup

This repository includes a Nix flake for reproducible development environments:

```bash
# Enter development shell (requires Nix with flakes enabled)
nix develop

# Initialize QMK environment (first time only)
qmk-init
```

The Nix flake provides helper scripts:
- `qmk-init`: Configure QMK to use this userspace
- `build-crkbd`: Build crkbd/rev4_1 firmware
- `build-all`: Build all configured keyboards
- `flash-crkbd`: Build and flash crkbd/rev4_1
- `flash <keyboard> <keymap>`: Build and flash any keyboard

### Building Firmware

**Using QMK CLI directly:**
```bash
# Compile a specific keyboard
qmk compile -kb crkbd/rev4_1/standard -km jeremy

# Compile all keyboards defined in qmk.json
qmk userspace-compile
```

**Using Makefile shortcuts:**
```bash
make crkbd          # Build crkbd
make mini42         # Build mini42
make zilpzalp       # Build zilpzalp
make minidox        # Build minidox
make charybdis      # Build charybdis
make sugarglider    # Build sugarglider
make atreus         # Build atreus
make q8             # Build Keychron Q8
make all-boards     # Build all keyboards
```

### Flashing Firmware

```bash
# Using QMK flash command
qmk flash -kb crkbd/rev4_1/standard -km jeremy

# Using Makefile (macOS-specific)
make crkbd-flash

# Using Nix helper scripts
flash-crkbd
flash crkbd/rev4_1/standard jeremy
```

### Managing Build Targets

Build targets are defined in `qmk.json`:

```bash
# Add a keyboard to build targets
qmk userspace-add -kb <keyboard> -km <keymap>

# Remove a keyboard from build targets
qmk userspace-remove -kb <keyboard> -km <keymap>

# List current build targets
qmk userspace-list
```

## Repository Structure

```
qmk_userspace/
├── keyboards/          # Keyboard-specific keymaps
│   ├── crkbd/
│   ├── controllerworks/mini42/
│   ├── kilipan/zilpzalp/
│   ├── maple_computing/minidox/
│   ├── bastardkb/charybdis/
│   ├── mechwild/sugarglider/
│   ├── keyboardio/atreus/
│   └── keychron/q8/
├── users/              # Shared user code (currently unused)
├── layouts/            # Layout-based keymaps (alternative to keyboard-specific)
├── qmk.json            # Build target configuration
├── flake.nix           # Nix development environment
└── Makefile            # Build shortcuts
```

## Keymap Architecture

All keymaps in this repository follow a consistent structure based on the crkbd layout:

### Keymap Files
Each keymap consists of:
- `keymap.c`: Main keymap definition with layers, custom keycodes, and processing logic
- `rules.mk`: Feature flags (e.g., `CAPS_WORD_ENABLE`, `COMBO_ENABLE`)
- `config.h`: Configuration overrides (optional)

### Common Patterns

**Layers:**
- `_COLEMAK`: Base layer using Colemak Mod-DH layout
- `_SYM`: Symbol layer (accessed via layer tap on Enter)
- `_NAV`: Navigation layer (accessed via layer tap on Space)
- `_NUM`: Number/numpad layer
- `_ADJUST`: Adjustment layer (tri-layer when both SYM and NAV active)
- `_TMUX`: Tmux control layer (custom implementation)

**Home Row Mods:**
All keymaps use home row mods with GUI/Alt/Ctrl/Shift on the home row (GACS configuration).

**Custom Features:**
- Combo support for frequently-used sequences (e.g., email, name, arrow operators)
- Custom Caps Word implementation that keeps hyphen as hyphen
- Tmux layer with dedicated keys for tmux window/pane management
- Layer taps for space (NAV) and enter (SYM)

## CI/CD

GitHub Actions automatically builds all keyboards on push:
- Uses QMK's official userspace build workflow
- Publishes firmware binaries to GitHub Releases
- Configured to use `qmk/qmk_firmware` master branch

To change the QMK firmware source, edit `.github/workflows/build_binaries.yaml`:
```yaml
with:
  qmk_repo: qmk/qmk_firmware
  qmk_ref: master
```

## Adding a New Keyboard

1. Create keymap: `qmk new-keymap -kb <keyboard> -km <name>`
2. Add to build targets: `qmk userspace-add -kb <keyboard> -km <name>`
3. (Optional) Add Makefile shortcut for convenience
4. Commit changes

The keymap will be created in `keyboards/<keyboard>/keymaps/<name>/`.

## Commit Message Style

Use Conventional Commits format with imperative mood:

**Format:**
```
<type>(<scope>): <subject in imperative mood>

<body with detailed explanation>
```

**Examples:**
```
feat(corne): add Apple Globe key to the map

Add support for AC_NEXT_KEYBOARD_LAYOUT_SELECT (Apple Globe key)
for switching keyboard layouts on macOS.

fix(crkbd): keep hyphen in Caps Word

Customize caps_word_press_user to prevent hyphen from becoming
underscore when Caps Word is active.
```

**Types:** feat, fix, docs, refactor, chore, test

## QMK Configuration

This userspace must be configured in QMK before use:

```bash
# Set overlay directory (from within this repository)
qmk config user.overlay_dir="$(realpath .)"

# Or use qmk-init helper script in Nix environment
qmk-init
```
