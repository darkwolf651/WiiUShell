#include "theme.h"

void themeBlue(int *backgroundColor, int *headerColor){
    *backgroundColor = 0x3366ff00;
    *headerColor = 0x33339900;
}

void themeRed(int *backgroundColor, int *headerColor){
    *backgroundColor = 0x99000400;
    *headerColor = 0xe6000800;
}

void themeGreen(int *backgroundColor, int *headerColor){
    *backgroundColor = 0x33660000;
    *headerColor = 0x73e60000;
}

void themeDark(int *backgroundColor, int *headerColor){
    *backgroundColor = 0x00000000;
    *headerColor = 0x97979700;
}
