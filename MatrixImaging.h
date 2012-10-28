/* 
 * File:   MatrixImaging.h
 * Author: MacLean
 *
 * Created on September 16, 2012, 12:26 AM
 * Last edited October 28, 2012, 5:48 PM
 */

#ifndef MATRIXIMAGING_H
#define	MATRIXIMAGING_H

#define pinA    LATCbits.LATC0
#define pinB    LATCbits.LATC1
#define pinC    LATCbits.LATC2

#define R1      LATDbits.LATD0
#define B1      LATDbits.LATD1
#define R2      LATDbits.LATD2
#define B2      LATDbits.LATD3
#define CLK     LATDbits.LATD4
#define G1      LATDbits.LATD6
#define G2      LATDbits.LATD5
#define LAT     LATDbits.LATD7

#pragma udata

int i;

#pragma code

void clear()
{
    LATDbits.LATD0 = 0;
    LATDbits.LATD1 = 0;
    LATDbits.LATD2 = 0;
    LATDbits.LATD3 = 0;
    LATDbits.LATD4 = 0;
    LATDbits.LATD5 = 0;
    LATDbits.LATD6 = 0;
    LATDbits.LATD7 = 0;
    LATCbits.LATC0 = 0;
    LATCbits.LATC1 = 0;
    LATCbits.LATC2 = 0;
    LATCbits.LATC3 = 0;
    LATCbits.LATC4 = 0;
    LATCbits.LATC5 = 0;
    LATCbits.LATC6 = 0;
    LATCbits.LATC7 = 0;
}

void setRow(char INPUT)
{
    switch (INPUT)
    {
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
}

void White (short TOGGLE1, short TOGGLE2)
{
    R1 = TOGGLE1;
    B1 = TOGGLE1;
    G1 = TOGGLE1;

    R2 = TOGGLE2;
    B2 = TOGGLE2;
    G2 = TOGGLE2;
}

void B8Colour(char TOGGLE1, char TOGGLE2)
{
    switch(TOGGLE1)
    {
        case 0:
            R1 = 0;
            G1 = 0;
            B1 = 0;
            break;
        case 1:
            R1 = 1;
            G1 = 0;
            B1 = 0;
            break;
        case 2:
            R1 = 0;
            G1 = 1;
            B1 = 0;
            break;
        case 3:
            R1 = 1;
            G1 = 1;
            B1 = 0;
            break;
        case 4:
            R1 = 0;
            G1 = 0;
            B1 = 1;
            break;
        case 5:
            R1 = 1;
            G1 = 0;
            B1 = 1;
            break;
        case 6:
            R1 = 0;
            G1 = 1;
            B1 = 1;
            break;
        case 7:
            R1 = 1;
            G1 = 1;
            B1 = 1;
            break;
    }
    switch(TOGGLE2)
    {
        case 0:
            R2 = 0;
            G2 = 0;
            B2 = 0;
            break;
        case 1:
            R2 = 1;
            G2 = 0;
            B2 = 0;
            break;
        case 2:
            R2 = 0;
            G2 = 1;
            B2 = 0;
            break;
        case 3:
            R2 = 1;
            G2 = 1;
            B2 = 0;
            break;
        case 4:
            R2 = 0;
            G2 = 0;
            B2 = 1;
            break;
        case 5:
            R2 = 1;
            G2 = 0;
            B2 = 1;
            break;
        case 6:
            R2 = 0;
            G2 = 1;
            B2 = 1;
            break;
        case 7:
            R2 = 1;
            G2 = 1;
            B2 = 1;
            break;
    }
}

void CLOCK ()
{
    CLK = 1;
    CLK = 0;
}

void LATCH ()
{
    LAT = 1;
    LAT = 0;
}

void clearLEDs()
{
    R1 = 0;
    R2 = 0;
    G1 = 0;
    G2 = 0;
    B1 = 0;
    B2 = 0;
    for(i = 0; i<32; i++)
    {
        CLOCK();
    }
    LATCH();
}

/*
#ifdef	__cplusplus
extern "C" {
#endif




#ifdef	__cplusplus
}
#endif*/

#endif	/* MATRIXIMAGING_H */

