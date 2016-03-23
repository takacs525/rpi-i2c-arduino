/*
 * ----------------------------------------------------------------------------
 * This is a MFRC522 library example; see https://github.com/miguelbalboa/rfid
 * for further details and other examples.
 * 
 * NOTE: The library file MFRC522.h has a lot of useful info. Please read it.
 * 
 * Typical pin layout used:
 * -----------------------------------------------------------------------------------------
 *             MFRC522      Arduino       Arduino   Arduino    Arduino          Arduino
 *             Reader/PCD   Uno           Mega      Nano v3    Leonardo/Micro   Pro Micro
 * Signal      Pin          Pin           Pin       Pin        Pin              Pin
 * -----------------------------------------------------------------------------------------
 * RST/Reset   RST          9             5         D9         RESET/ICSP-5     RST
 * SPI SS      SDA(SS)      10            53        D10        10               10
 * SPI MOSI    MOSI         11 / ICSP-4   51        D11        ICSP-4           16
 * SPI MISO    MISO         12 / ICSP-1   50        D12        ICSP-1           14
 * SPI SCK     SCK          13 / ICSP-3   52        D13        ICSP-3           15
 */

#define LED1_PIN             7    // for LED
#define LED2_PIN             8    // for LED
 
#define RST_PIN              9    // for RFID
#define SS_PIN              10    // for RFID


#define I2C_ADDRESS         66    // #42
#define I2C_IRQ_PIN         A1

#define SPEAKER_PIN          8    // for Tone

//LEDbar with 74HC595
#define LEDBAR_LATCH_PIN     3
#define LEDBAR_CLOCK_PIN     4
#define LEDBAR_DATA_PIN      2

#define LEDBAR_BARS         16

//battery
#define BATTERY_PIN         A0

