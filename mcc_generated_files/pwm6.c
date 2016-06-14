 /**
   PWM6 Generated Driver File
 
   @Company
     Microchip Technology Inc.
 
   @File Name
     pwm6.c
 
   @Summary
     This is the generated driver implementation file for the PWM6 driver using MPLAB(c) Code Configurator
 
   @Description
     This source file provides implementations for driver APIs for PWM6.
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
 
 /**
   Section: Included Files
 */

 #include <xc.h>
 #include "pwm6.h"

 /**
   Section: PWM Module APIs
 */

 void PWM6_Initialize(void)
 {
     // Set the PWM to the options selected in the MPLAB(c) Code Configurator.
     // PWM6POL active_hi; PWM6OUT disabled; PWM6EN enabled; 
     PWM6CON = 0x80;
     
     // PWM6DCH 2; 
     PWM6DCH = 0x02;
     
     // PWM6DCL 1; 
     PWM6DCL = 0x40;
     
 }

 void PWM6_LoadDutyValue(uint16_t dutyValue)
 {
     // Writing to 8 MSBs of PWM duty cycle in PWMDCH register
     PWM6DCH = (dutyValue & 0x03FC)>>2;
     
     // Writing to 2 LSBs of PWM duty cycle in PWMDCL register
     PWM6DCL = (dutyValue & 0x0003)<<6;
 }
 /**
  End of File
 */
