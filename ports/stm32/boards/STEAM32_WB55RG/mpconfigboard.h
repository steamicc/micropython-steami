/* This file is part of the MicroPython project, http://micropython.org/
 * MIT License; Copyright (c) 2019 Damien P. George
 */

#define MICROPY_HW_BOARD_NAME       "STEAM32-WB55"
#define MICROPY_HW_MCU_NAME         "STM32WB55RGV6"

#define MICROPY_PY_PYB_LEGACY       (0)

#define MICROPY_HW_HAS_FLASH        (1)
#define MICROPY_HW_ENABLE_RTC       (1)
#define MICROPY_HW_ENABLE_RNG       (1)
#define MICROPY_HW_ENABLE_ADC       (1)
#define MICROPY_HW_ENABLE_USB       (0)
#define MICROPY_HW_HAS_SWITCH       (1)

// There is an external 32kHz oscillator
#define RTC_ASYNCH_PREDIV           (0)
#define RTC_SYNCH_PREDIV            (0x7fff)
#define MICROPY_HW_RTC_USE_LSE      (1)
#define MICROPY_HW_RTC_USE_US       (1)

// UART buses
#define MICROPY_HW_UART1_NAME       "UART2"
#define MICROPY_HW_UART1_TX         (pin_B6)
#define MICROPY_HW_UART1_RX         (pin_B7)

#define MICROPY_HW_LPUART1_NAME     "UART1"
#define MICROPY_HW_LPUART1_TX       (pin_B11)
#define MICROPY_HW_LPUART1_RX       (pin_B10)

// USART 1 is connected to the virtual com port on the MCU Interface
#define MICROPY_HW_UART_REPL        PYB_LPUART_1
#define MICROPY_HW_UART_REPL_BAUD   115200

// I2C buses
#define MICROPY_HW_I2C1_NAME        "I2CINT"  
#define MICROPY_HW_I2C1_SCL         (pin_B8)   
#define MICROPY_HW_I2C1_SDA         (pin_B9)   

#define MICROPY_HW_I2C3_NAME        "I2CEXT"
#define MICROPY_HW_I2C3_SCL         (pin_C0)   
#define MICROPY_HW_I2C3_SDA         (pin_C1)   

// SPI buses
#define MICROPY_HW_SPI1_NAME        "SPIINT"
#define MICROPY_HW_SPI1_NSS         (pin_D0)    
#define MICROPY_HW_SPI1_SCK         (pin_A1)    
//#define MICROPY_HW_SPI1_MISO        (pin_B4)    
#define MICROPY_HW_SPI1_MOSI        (pin_B5)    

#define MICROPY_HW_SPI2_NAME        "SPIEXT"
#define MICROPY_HW_SPI2_NSS         (pin_E4)
#define MICROPY_HW_SPI2_SCK         (pin_B13)
#define MICROPY_HW_SPI2_MISO        (pin_B14)
#define MICROPY_HW_SPI2_MOSI        (pin_B15)

// User switch; pressing the button makes the input go low
#define MICROPY_HW_USRSW_PIN        (pin_A7)
#define MICROPY_HW_USRSW_PULL       (GPIO_PULLUP)
#define MICROPY_HW_USRSW_EXTI_MODE  (GPIO_MODE_IT_FALLING)
#define MICROPY_HW_USRSW_PRESSED    (0)

// LEDs
#define MICROPY_HW_LED1             (pin_C12)
#define MICROPY_HW_LED2             (pin_C11)
#define MICROPY_HW_LED3             (pin_C10)
#define MICROPY_HW_LED_ON(pin)      (mp_hal_pin_high(pin))
#define MICROPY_HW_LED_OFF(pin)     (mp_hal_pin_low(pin))

// Bluetooth config
#define MICROPY_HW_BLE_UART_ID       (0)
#define MICROPY_HW_BLE_UART_BAUDRATE (115200)
