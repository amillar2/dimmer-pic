/**
  Generated Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This is the main file generated using MPLAB(c) Code Configurator

  Description:
    This header file provides implementations for driver APIs for all modules selected in the GUI.
    Generation Information :
        Product Revision  :  MPLAB(c) Code Configurator - v3.00
        Device            :  PIC16F18313
        Driver Version    :  2.00
    The generated drivers are tested against the following:
        Compiler          :  XC8 1.35
        MPLAB             :  MPLAB X 3.20
*/

/*
Copyright (c) 2013 - 2015 released Microchip Technology Inc.  All rights reserved.

Microchip licenses to you the right to use, modify, copy and distribute
Software only when embedded on a Microchip microcontroller or digital signal
controller that is integrated into your product or third party product
(pursuant to the sublicense terms in the accompanying license agreement).

You should refer to the license agreement accompanying this Software for
additional information regarding your rights and obligations.

SOFTWARE AND DOCUMENTATION ARE PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
EITHER EXPRESS OR IMPLIED, INCLUDING WITHOUT LIMITATION, ANY WARRANTY OF
MERCHANTABILITY, TITLE, NON-INFRINGEMENT AND FITNESS FOR A PARTICULAR PURPOSE.
IN NO EVENT SHALL MICROCHIP OR ITS LICENSORS BE LIABLE OR OBLIGATED UNDER
CONTRACT, NEGLIGENCE, STRICT LIABILITY, CONTRIBUTION, BREACH OF WARRANTY, OR
OTHER LEGAL EQUITABLE THEORY ANY DIRECT OR INDIRECT DAMAGES OR EXPENSES
INCLUDING BUT NOT LIMITED TO ANY INCIDENTAL, SPECIAL, INDIRECT, PUNITIVE OR
CONSEQUENTIAL DAMAGES, LOST PROFITS OR LOST DATA, COST OF PROCUREMENT OF
SUBSTITUTE GOODS, TECHNOLOGY, SERVICES, OR ANY CLAIMS BY THIRD PARTIES
(INCLUDING BUT NOT LIMITED TO ANY DEFENSE THEREOF), OR OTHER SIMILAR COSTS.
 */
#define DELAY_TIME 5
#include "mcc_generated_files/mcc.h"

/*
                         Main application
 */
void main(void)
{
    // initialize the device
    SYSTEM_Initialize();

    // When using interrupts, you need to set the Global and Peripheral Interrupt Enable bits
    // Use the following macros to:

    // Enable the Global Interrupts
    //INTERRUPT_GlobalInterruptEnable();

    // Enable the Peripheral Interrupts
    //INTERRUPT_PeripheralInterruptEnable();

    // Disable the Global Interrupts
    //INTERRUPT_GlobalInterruptDisable();

    // Disable the Peripheral Interrupts
    //INTERRUPT_PeripheralInterruptDisable();
    uint8_t     readDummy = 0; //dummy variable for SPI read
    uint8_t     addr = 0; //address 0-PWM5 1-PWM6
    uint8_t     data = 0; //PWM setting 0-256
    uint8_t     pwm5 = 0; //PWM5 setting
    uint8_t     pwm6 = 0; //PWM6 setting
    //Gamma correction table
    const uint16_t cie[256] = {
        0, 0, 1, 1, 2, 2, 3, 3, 4, 4, 
        4, 5, 5, 6, 6, 7, 7, 8, 8, 8, 
        9, 9, 10, 10, 11, 11, 12, 12, 13, 13, 
        14, 15, 15, 16, 17, 17, 18, 19, 19, 20, 
        21, 22, 22, 23, 24, 25, 26, 27, 28, 29, 
        30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 
        41, 42, 43, 44, 46, 47, 48, 50, 51, 52, 
        54, 55, 57, 58, 60, 61, 63, 65, 66, 68, 
        70, 71, 73, 75, 77, 79, 81, 83, 85, 87, 
        89, 91, 93, 95, 97, 99, 101, 104, 106, 108, 
        110, 113, 115, 118, 120, 123, 125, 128, 130, 133, 
        136, 138, 141, 144, 147, 150, 153, 155, 158, 161, 
        164, 168, 171, 174, 177, 180, 184, 187, 190, 194, 
        197, 201, 204, 208, 211, 215, 219, 222, 226, 230, 
        234, 238, 242, 246, 250, 254, 258, 262, 266, 271, 
        275, 279, 284, 288, 292, 297, 302, 306, 311, 316, 
        320, 325, 330, 335, 340, 345, 350, 355, 360, 365, 
        371, 376, 381, 387, 392, 398, 403, 409, 414, 420, 
        426, 432, 438, 443, 449, 455, 462, 468, 474, 480, 
        486, 493, 499, 506, 512, 519, 525, 532, 539, 546, 
        552, 559, 566, 573, 580, 588, 595, 602, 609, 617, 
        624, 632, 639, 647, 654, 662, 670, 678, 686, 694, 
        702, 710, 718, 726, 735, 743, 751, 760, 768, 777, 
        786, 794, 803, 812, 821, 830, 839, 848, 857, 867, 
        876, 885, 895, 904, 914, 924, 933, 943, 953, 963, 
        973, 983, 993, 1003, 1014, 1023};
    PWM5_LoadDutyValue(cie[pwm5]);
    PWM6_LoadDutyValue(cie[pwm6]);
    while (1)
    {
        addr = SPI1_Exchange8bit(readDummy);//read address 0-PWM5 1-PWM6
        data = SPI1_Exchange8bit(readDummy);//read pwm setting
        //blocking calls to perform gradual pwm set. consider adding handshake with esp?
        if (addr==0) {
            while (pwm5<data) {
                pwm5++;
                PWM5_LoadDutyValue(cie[pwm5]);
                __delay_ms(DELAY_TIME);
            }
            while (pwm5>data) {
                pwm5--;
                PWM5_LoadDutyValue(cie[pwm5]);
                __delay_ms(DELAY_TIME);
            }
        }
        else if (addr==1) {
            while (pwm6<data) {
                pwm6++;
                PWM6_LoadDutyValue(cie[pwm6]);
                __delay_ms(DELAY_TIME);
            }
            while (pwm6>data) {
                pwm6--;
                PWM6_LoadDutyValue(cie[pwm6]);
                __delay_ms(DELAY_TIME);
            }
        }
        
    }
}
/**
 End of File
*/