SOURCE_DIR = ../../..
BINPATH = ~/gcc-arm-none-eabi/bin
PROJ_PATH ?= ../../../project/mt7687_hdk/apps/iot_sdk/GCC
CONFIG_PATH ?= .

CFLAGS += -I$(PROJ_PATH)/../inc
CFLAGS += -I../../../$(CONFIG_PATH)
CFLAGS += -DMTK_FW_VERSION=\"$(MTK_FW_VERSION)\"

FEATURE    ?= feature.mk

include $(PROJ_PATH)/$(FEATURE)

# Gloabl Config
-include $(SOURCE_DIR)/.config
# IC Config
-include $(SOURCE_DIR)/config/chip/$(IC_CONFIG)/chip.mk
# Board Config
-include $(SOURCE_DIR)/config/board/$(BOARD_CONFIG)/board.mk

# Project name
TARGET_LIB=libbsp

BUILD_DIR = Build
OUTPATH = Build

# Sources
-include wifi/src_protected/module.mk
include wifi/src/module.mk
include init/src/module.mk

RELEASE_TARGET_LIB_PATH := $(SOURCE_DIR)/driver/board/mt76x7_hdk/lib/$(TARGET_LIB).a

C_OBJS = $(C_FILES:%.c=$(BUILD_DIR)/%.o)

.PHONY: all $(TARGET_LIB).a

all: $(TARGET_LIB).a merge_lib
	@echo Build $< Done

merge_lib: $(TARGET_LIB).a

include $(SOURCE_DIR)/.rule.mk

clean:
	rm -rf $(OUTPATH)/$(TARGET_LIB).a
	rm -rf $(BUILD_DIR)
