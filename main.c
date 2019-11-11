/*
 * File:   main.c
 * Description: Flashes third brake light
 * 
 * Project: ThirdBrakeLightFlasher
 * Author: John Combs
 * Date: December 23, 2015
 */

#include <xc.h>
#include "config.h"

void delay_ms(unsigned short b) {
    do {
        b--;
        __delay_ms(1);
    } while(b);
}

void main(void) {
    TRISIObits.TRISIO2 = 0x00;
    
    while (1) {
        for (char i = 0; i < 3; i++) {
            GP2 = 0x01;
            delay_ms(350);
            GP2 = 0x00;
            delay_ms(350);
        }
        
        GP2 = 0x01;
        delay_ms(2000);
        GP2 = 0x00;
        delay_ms(300);
    }
    
    return;
}
