/* 
 * File:   MatrixImaging.c
 * Author: MacLean
 *
 * Created on September 16, 2012, 12:36 PM
 * Last edited October 28, 2012, 5:48 PM
 */

/** C O N F I G U R A T I O N   B I T S ******************************/

#pragma config FOSC = INTIO67
#pragma config WDTEN = OFF, LVP = OFF, MCLRE = OFF


/** I N C L U D E S **************************************************/
#include "p18f45k20.h"
#include "delays.h"
#include "MatrixImaging.h"


/** D E C L A R A T I O N S ******************************************/

#pragma udata

unsigned int y;
unsigned int x;

#pragma romdata



/*
 *First ever Image:
 *
 *                                  {{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
 *                                  {0,0,0,0,1,0,0,1,0,1,1,1,1,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
 *                                  {0,0,0,0,1,0,0,1,0,0,1,1,0,0,1,1,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,0},
 *                                  {0,0,0,0,1,1,1,1,0,0,1,1,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
 *                                  {0,0,0,0,1,1,1,1,0,0,1,1,0,0,1,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0},
 *                                  {0,0,0,0,1,0,0,1,0,0,1,1,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0},
 *                                  {0,0,0,0,1,0,0,1,0,1,1,1,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
 *                                  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
 *                                  {0,0,0,0,1,0,0,0,1,1,1,0,0,1,0,0,1,0,1,0,0,0,1,1,1,1,0,1,1,0,0,0},
 *                                  {0,0,0,0,1,0,0,0,1,0,0,1,0,1,0,0,1,0,1,0,0,0,1,0,0,0,0,1,1,0,0,0},
 *                                  {0,0,0,0,1,0,0,0,1,1,1,0,0,1,0,0,1,0,1,0,0,0,1,1,1,0,0,1,0,0,0,0},
 *                                  {0,0,0,0,1,0,0,0,1,0,1,0,0,1,0,0,1,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0},
 *                                  {0,0,0,0,1,0,0,0,1,0,0,1,0,0,1,1,0,0,1,1,1,0,1,1,1,1,0,1,0,0,0,0},
 *                                  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
 *                                  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
 *                                  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}}
 */

const rom unsigned char imageBW[16] [32] = {
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 5, 7, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 5, 5, 5, 5, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 7, 5, 5, 5, 5, 5, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 7, 7, 7, 7, 7, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 5, 7, 7, 7, 0, 7, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 5, 0, 0, 0, 0, 0, 0, 5, 5, 5, 7, 7, 7, 7, 7, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 5, 5, 0, 0, 0, 0, 0, 0, 5, 5, 5, 7, 7, 7, 7, 7, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 5, 5, 0, 5, 0, 0, 0, 0, 0, 0, 5, 5, 5, 7, 7, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 5, 5, 0, 0, 7, 7, 7, 7, 7, 7, 7, 5, 5, 5, 7, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 5, 5, 5, 0, 7, 7, 6, 7, 7, 7, 7, 7, 5, 5, 7, 7, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 5, 5, 0, 7, 6, 7, 6, 7, 7, 7, 7, 7, 7, 7, 7, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 5, 5, 0, 0, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 5, 0, 0, 0, 0, 7, 7, 7, 0, 0, 0, 0, 7, 7, 7, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 7, 7, 0, 0, 0, 0, 0, 0, 7, 7, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 7, 0, 0, 0, 0, 0, 0, 7, 7, 0, 0, 0, 0}
};

#pragma code

void main() {

    TRISD = 0b00000000; // PORTD bits to output (0)
    TRISC = 0b00000000; // PORTC bits to output (0)

    OSCCON = 0x70; // IRCFx = 111 (16 MHz)
    OSCTUNEbits.PLLEN = 1; // x4 PLL enabled = 64MHz

    clear(); // Set all output to 0

    while (1) {
        // index for y position on matrix
        for (y = 0; y != 8; y++) {
            switch (y) {
                case 0:
                    pinA = 0;
                    pinB = 0;
                    pinC = 0;
                    break;
                case 1:
                    pinA = 1;
                    pinB = 0;
                    pinC = 0;
                    break;
                case 2:
                    pinA = 0;
                    pinB = 1;
                    pinC = 0;
                    break;
                case 3:
                    pinA = 1;
                    pinB = 1;
                    pinC = 0;
                    break;
                case 4:
                    pinA = 0;
                    pinB = 0;
                    pinC = 1;
                    break;
                case 5:
                    pinA = 1;
                    pinB = 0;
                    pinC = 1;
                    break;
                case 6:
                    pinA = 0;
                    pinB = 1;
                    pinC = 1;
                    break;
                case 7:
                    pinA = 1;
                    pinB = 1;
                    pinC = 1;
                    break;
            }
            //index for x position on matrix
            for (x = 0; x != 32; x++) {
                //read ROM image data and output to matrix
                B8Colour(imageBW[y][x], imageBW[y + 8][x]);
                CLK = 1;
                CLK = 0;
            }
            LAT = 1;
            LAT = 0;
            Delay1KTCYx(1); //uncomment to toggle brightness of LEDs
            clearLEDs();
        }
    }
}