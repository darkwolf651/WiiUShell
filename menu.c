#include "video.h"
#include "menu.h"
#include <coreinit/screen.h>
#include <vpad/input.h>
#include <coreinit/time.h>
#include <coreinit/systeminfo.h>
#include <coreinit/thread.h>

void DrawIntro(){

    OSScreenPutFontEx(0, 20, 7, "Welcome to YourMenu!");
    OSScreenPutFontEx(0, 16, 8, "Press A on the DRC to continue to Main Menu.");

    OSScreenPutFontEx(1, 20, 7, "Hello World! This is the DRC.");
    OSScreenPutFontEx(1, 16, 8, "Press A on DRC to Continue to Main Menu.");

}


void DrawMainMenu(){

    int i = 3;

    VPADStatus vpad;
    int error;

    for (;;){

        CleanBuffer();

        OSScreenPutFontEx(0, 2, 0, "OPTIONS");
        OSScreenPutFontEx(0, 2, 3, "Start up");
        OSScreenPutFontEx(0, 2, 4, "Video");
        OSScreenPutFontEx(0, 2, 5, "Sound");
        OSScreenPutFontEx(0, 2, 6, "Wifi");


        OSScreenPutFontEx(0, 0, i, "->");
        VPADRead(0, &vpad, 1, &error);
            if (!error){
                if(vpad.trigger & VPAD_BUTTON_DOWN && i < 10){
                    ++i;
                }
                if(vpad.trigger & VPAD_BUTTON_UP && i > 3){
                    --i;
                }
                if (vpad.trigger & VPAD_BUTTON_HOME){
                    break;
                }
            }
            VidRefresh();
            OSSleepTicks(OSMillisecondsToTicks(16.67));
    }

}
