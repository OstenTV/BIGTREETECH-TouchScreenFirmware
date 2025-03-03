#ifndef _PIN_TFT70_V3_0_H_  // modify to actual filename !!!
#define _PIN_TFT70_V3_0_H_  // modify to actual filename !!!

// MCU type (STM32F10x, STM32F2xx, STM32F4xx, GD32F20x, GD32F30x)
#ifndef MCU_TYPE
  #define MCU_TYPE
  #include "stm32f4xx.h"
#endif

// Portrait Mode support
// Comment the following line in case the TFT variant supports Portrait Mode
//#undef PORTRAIT_MODE

// LCD resolution, font and icon size
#ifndef TFT_RESOLUTION
  #define TFT_RESOLUTION
  #ifdef PORTRAIT_MODE
    #undef TFT70_V3_0  // if Portrait Mode, undefine TFT70_V3 in order to apply standard layout on Printing and Status Screen menus

    #include "./Resolution/TFT_480X800.h"
  #else
    #include "./Resolution/TFT_800X480.h"
  #endif
#endif

// Update folder for fonts and icons
#ifndef UPDATE_DIR
  #define UPDATE_DIR "TFT70"
#endif

// Hardware manufacturer
#ifndef HARDWARE_MANUFACTURER
  #define HARDWARE_MANUFACTURER "BIGTREETECH_"
#endif

// Hardware version config
#ifndef HARDWARE_VERSION
  #define HARDWARE_VERSION "TFT70_V3.0"
#endif

// Software manufacturer
#ifndef SOFTWARE_MANUFACTURER
  #define SOFTWARE_MANUFACTURER HARDWARE_VERSION"."
#endif

// XPT2046 Software SPI pins for touch screen
// It needs CS/SCK/MISO/MOSI for Software SPI and TPEN for pen interrupt
#define XPT2046_CS   PE6
#define XPT2046_SCK  PE5
#define XPT2046_MISO PE4
#define XPT2046_MOSI PE3
#define XPT2046_TPEN PC13

// W25Qxx SPI Flash Memory pins
#define W25Qxx_SPEED  0
#define W25Qxx_SPI    _SPI3
#define W25Qxx_CS_PIN PB6

// LCD interface
// Supported LCD drivers: [ST7789, SSD1963, RM68042, NT35310, ILI9488, ILI9341, ILI9325, HX8558, ST7796S]
#ifndef TFTLCD_DRIVER
  #define TFTLCD_DRIVER       SSD1963
  #define TFTLCD_DRIVER_SPEED 0x10     // SSD1963 needs slower speed
#endif

// Only for TFTLCD_DRIVER SSD1963
#ifndef SSD1963_LCD_PARA
  #define SSD1963_LCD_PARA
  #define SSD_DCLK_FREQUENCY  30   // 30Mhz

  #define SSD_HOR_PULSE_WIDTH 1
  #define SSD_HOR_BACK_PORCH  46
  #define SSD_HOR_FRONT_PORCH 210

  #define SSD_VER_PULSE_WIDTH 3
  #define SSD_VER_BACK_PORCH  33
  #define SSD_VER_FRONT_PORCH 22
#endif

// FSMC 8080 interface (high speed) or normal IO interface (low speed)
#ifndef STM32_HAS_FSMC
  #define STM32_HAS_FSMC
#endif

// LCD data 16bit or 8bit
#ifndef LCD_DATA_16BIT
  #define LCD_DATA_16BIT 1
#endif

// SERIAL_PORT:   communicating with host (Marlin, RRF etc...)
// SERIAL_PORT_X: communicating with other controllers (OctoPrint, ESP3D, other UART Touch Screen etc...)
#ifndef SERIAL_PORT
  #define SERIAL_PORT   _USART2  // default USART port
  #define SERIAL_PORT_2 _USART1
  #define SERIAL_PORT_3 _USART3
  #define SERIAL_PORT_4 _UART4
#endif

// Serial port for debugging
#ifdef SERIAL_DEBUG_ENABLED
  #define SERIAL_DEBUG_PORT SERIAL_PORT_3
#endif

// SD Card SPI pins
#ifndef SD_SPI_SUPPORT
  #define SD_SPI_SUPPORT
  #define SD_LOW_SPEED   7      // 2^(SPEED+1) = 256 frequency division
  #define SD_HIGH_SPEED  0      // 2 frequency division
  #define SD_SPI         _SPI1
  #define SD_CS_PIN      PA4
#endif

// SD Card CD Detect pin
#ifndef SD_CD_PIN
  #define SD_CD_PIN PC4
#endif

// USB Disk support
#ifndef USB_FLASH_DRIVE_SUPPORT
  #define USB_FLASH_DRIVE_SUPPORT
  #define USE_USB_OTG_FS
#endif

// Power Supply Auto Shutdown Detection pin
#ifndef PS_ON_PIN
  #define PS_ON_PIN PC12  // the string on TFT35 V3.0 board (PA12) is wrong, PC12 is the correct IO
#endif

// Filament Runout Detection pin
#ifndef FIL_RUNOUT_PIN
  #define FIL_RUNOUT_PIN PA15
#endif

// Buzzer PWM pin
#ifndef BUZZER_PIN
  #define BUZZER_PIN PD13
#endif

// LCD Backlight pins (adjust brightness with LED PWM)
#ifndef LCD_LED_PIN
  #define LCD_LED_PIN           PD12
  #define LCD_LED_PIN_ALTERNATE GPIO_AF_TIM4
  #define LCD_LED_PWM_CHANNEL   _TIM4_CH1
#endif

// Knob LED Color pins
#ifndef KNOB_LED_COLOR_PIN
  #define KNOB_LED_COLOR_PIN       PC7
  #define WS2812_FAST_WRITE_HIGH() GPIOC->BSRRL = 1 << 7
  #define WS2812_FAST_WRITE_LOW()  GPIOC->BSRRH = 1 << 7
#endif

// Neopixel LEDs number
#ifndef NEOPIXEL_PIXELS
  #define NEOPIXEL_PIXELS 2
#endif

// LCD Encoder pins
#ifndef LCD_ENCA_PIN
  #define LCD_ENCA_PIN   PA8
  #define LCD_ENCB_PIN   PC9
  #define LCD_BTN_PIN    PC8
  #define LCD_ENC_EN_PIN PC6
#endif

// ST7920 Emulator SPI pins
#define ST7920_EMULATOR  // uncomment to enable Marlin mode
#ifdef ST7920_EMULATOR
  #define ST7920_SPI _SPI2
#endif

// HD44780 Emulator pins
#define LCD2004_EMULATOR
#ifdef LCD2004_EMULATOR
  #define LCD_EN      PB15
  #define LCD_RS      PB12
  #define LCD_D4      PB13
  #define LCD_D5      PB14
  #define LCD_D6      PC7
  #define LCD_D7      PC6
  #define LCD_D4_PIN  GPIO_Pin_13
  #define LCD_D5_PIN  GPIO_Pin_14
  #define LCD_D6_PIN  GPIO_Pin_7
  #define LCD_D7_PIN  GPIO_Pin_6
  #define LCD_D4_PORT GPIOB
  #define LCD_D5_PORT GPIOB
  #define LCD_D6_PORT GPIOC
  #define LCD_D7_PORT GPIOC
#endif

#endif
