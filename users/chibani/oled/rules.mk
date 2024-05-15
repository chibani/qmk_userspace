ifeq ($(strip $(OLED_ENABLE)), yes)
	SRC += $(USER_PATH)/oled/oled.c
    # ifeq ($(strip $(CUSTOM_OLED_DRIVER)), yes)
    #     OPT_DEFS += -DCUSTOM_OLED_DRIVER
        
    #     POST_CONFIG_H += $(USER_PATH)/oled/config.h
    # endif
    # ifeq ($(strip $(OLED_DISPLAY_TEST)), yes)
    #     OPT_DEFS += -DOLED_DISPLAY_TEST
    # endif
endif