#include "video.h"
#include "menu.h"
#include <coreinit/screen.h>
#include <vpad/input.h>
#include <coreinit/time.h>
#include <coreinit/systeminfo.h>
#include <coreinit/thread.h>
#include <sysapp/launch.h>

void DrawIntro(){

    OSScreenPutFontEx(0, 20, 7, "Welcome to YourMenu!");
    OSScreenPutFontEx(0, 16, 8, "Press A on the DRC to continue to Main Menu.");

    OSScreenPutFontEx(1, 20, 7, "Hello World! This is the DRC.");
    OSScreenPutFontEx(1, 16, 8, "Press A on DRC to Continue to Main Menu.");

}

void DrawOptionsMenu(){

    int i = 3;

    VPADStatus vpad;
    int error;

    for (;;){

        CleanBuffer();

        OSScreenPutFontEx(0, 0, 0, "OPTIONS");
        OSScreenPutFontEx(0, 2, 3, "Video");
        OSScreenPutFontEx(0, 2, 4, "Wifi");
        OSScreenPutFontEx(0, 2, 5, "Theme");
        OSScreenPutFontEx(0, 2, 6, "Back");

        OSScreenPutFontEx(1, 0, 0, "OPTIONS");
        OSScreenPutFontEx(1, 2, 3, "Video");
        OSScreenPutFontEx(1, 2, 4, "Wifi");
        OSScreenPutFontEx(1, 2, 5, "Theme");
        OSScreenPutFontEx(1, 2, 6, "Back");


        OSScreenPutFontEx(0, 0, i, "->");
        OSScreenPutFontEx(1, 0, i, "->");
        VPADRead(0, &vpad, 1, &error);
            if (!error){
                if(vpad.trigger & VPAD_BUTTON_DOWN && i < 6){
                    ++i;
                }
                if(vpad.trigger & VPAD_BUTTON_UP && i > 3){
                    --i;
                }
                if (vpad.trigger & VPAD_BUTTON_A && i == 6){
                    break;
                }
            }
            VidRefresh();
            OSSleepTicks(OSMillisecondsToTicks(16.67));
    }
}

void DrawMainMenu(){

    int i = 3;

    VPADStatus vpad;
    int error;

    for (;;){

        CleanBuffer();

        OSScreenPutFontEx(0, 0, 0, "MAIN MENU");
        OSScreenPutFontEx(0, 2, 3, "Games");
        OSScreenPutFontEx(0, 2, 4, "Debug");
        OSScreenPutFontEx(0, 2, 5, "Options");
        OSScreenPutFontEx(0, 2, 6, "Exit");

        OSScreenPutFontEx(1, 0, 0, "MAIN MENU");
        OSScreenPutFontEx(1, 2, 3, "Games");
        OSScreenPutFontEx(1, 2, 4, "Debug");
        OSScreenPutFontEx(1, 2, 5, "Options");
        OSScreenPutFontEx(1, 2, 6, "Exit");


        OSScreenPutFontEx(0, 0, i, "->");
        OSScreenPutFontEx(1, 0, i, "->");
        VPADRead(0, &vpad, 1, &error);
            if (!error){
                if(vpad.trigger & VPAD_BUTTON_DOWN && i < 6){
                    ++i;
                }
                if(vpad.trigger & VPAD_BUTTON_UP && i > 3){
                    --i;
                }
                if (vpad.trigger & VPAD_BUTTON_HOME){
                    break;
                }
                if (vpad.trigger & VPAD_BUTTON_A && i == 5){
                    DrawOptionsMenu();
                }
                if (vpad.trigger & VPAD_BUTTON_A && i == 6){
                    break;
                }
            }
            VidRefresh();
            OSSleepTicks(OSMillisecondsToTicks(16.67));
    }

}
