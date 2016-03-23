# Welcome
This repo contains sample codes for a Raspberry PI custom shield, which has an Arduino Pro Mini board on top of it.
Raspberry PI and Arduino communicate over I2C interface and a custom protocol.

## I2C command structure
Every command is 3 bytes long: Action / Object / Value

### Get command list
---
#### **Check status**
* Request: 0x01 0x00 0x00
* Response: 1 byte (1=OK)

#### **Get battery level**
* Request: 0x02 0x00 0x00
* Response: 1 byte (battery level %)

#### **Get RFID card ID**
* Request: 0x03 0x00 0x00
* Response: 4 bytes (card ID)

### Set command list
---
#### **LED**
* Request: 
    * 0x81 (LED) 
    * 0xXX (XX = LED number: 01 = 1st LED / 02 = 2nd LED)
    * 0x00 = OFF / 0x01 = ON

#### **LED bar**
* Request: 
    * 0x82 (LED bar) 
    * 0x01 (LED bar number) 
    * 0xXX (XX = %)

#### **Speaker**
* Request: 
    * 0x83 (Speaker) 
    * 0x01 (Speaker number) 
    * 0xXX (XX = melody ID)

#### **Test (Blinks all attached LEDs)**
* Request: 
    * 0x84 (Test) 
    * 0x00 (not used) 
    * 0x00 (not used)
