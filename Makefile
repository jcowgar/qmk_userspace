.PHONY: mini42 mini42-flash zilpzalp minidox charybdis sugarglider atreus crkbd crkbd-flash q8 all-boards

# Detect OS and set RPI-RP2 mount path
UNAME := $(shell uname)
ifeq ($(UNAME), Darwin)
    RPI_RP2_PATH := /Volumes/RPI-RP2
else
    RPI_RP2_PATH := /run/media/$(USER)/RPI-RP2
endif

# Keyboard compile targets
mini42:
	qmk compile -kb controllerworks/mini42 -km jeremy

mini42-flash: mini42
	@echo "Waiting for RPI-RP2 volume to appear..."
	@while [ ! -d "$(RPI_RP2_PATH)" ]; do \
		sleep 0.5; \
	done
	@echo "RPI-RP2 detected! Copying firmware..."
	@cp controllerworks_mini42_jeremy.uf2 $(RPI_RP2_PATH)/
	@echo "Firmware copied. Keyboard will reboot automatically."

zilpzalp:
	qmk compile -kb kilipan/zilpzalp -km jeremy

minidox:
	qmk compile -kb maple_computing/minidox/rev1 -km jeremy

charybdis:
	qmk compile -kb bastardkb/charybdis/4x6/v2/splinky_3 -km jeremy

sugarglider:
	qmk compile -kb mechwild/sugarglider/f401 -km jeremy_colemak

atreus:
	qmk compile -kb keyboardio/atreus -km jeremy

crkbd:
	qmk compile -kb crkbd/rev4_1/standard -km jeremy

crkbd-flash: crkbd
	@echo "Waiting for RPI-RP2 volume to appear..."
	@while [ ! -d "$(RPI_RP2_PATH)" ]; do \
		sleep 0.5; \
	done
	@echo "RPI-RP2 detected! Copying firmware..."
	@cp crkbd_rev4_1_standard_jeremy.uf2 $(RPI_RP2_PATH)/
	@echo "Firmware copied. Keyboard will reboot automatically."

q8:
	qmk compile -kb keychron/q8/ansi -km jeremy

# Build all keyboards
all-boards: mini42 zilpzalp minidox charybdis sugarglider atreus crkbd q8
