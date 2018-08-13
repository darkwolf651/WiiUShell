#include <coreinit/screen.h>

#include "draw.h"

void DrawRectangle(int x1, int y1, int x2, int y2, int color){

    int a;
    int i;

    for (i = 0; i < (y2-y1); ++i){
        for(a = 0; a < (x2-x1); ++a){
            OSScreenPutPixelEx(0, a + x1, i + y1, color);
            OSScreenPutPixelEx(1, a + x1, i + y1, color);
        }
    }


}

void DrawBackground(int color){
    OSScreenClearBufferEx(0, color);
    OSScreenClearBufferEx(1, color);
}


void DrawCircle(int cx, int cy, int r, int color){

}

