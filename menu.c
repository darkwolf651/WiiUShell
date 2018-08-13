#include "video.h"
#include "menu.h"
#include "draw.h"
#include "theme.h"
#include "IO.h"
#include <coreinit/screen.h>
#include <vpad/input.h>
#include <coreinit/time.h>
#include <coreinit/systeminfo.h>
#include <coreinit/thread.h>
#include <sysapp/launch.h>
#include <whb/sdcard.h>


int backgroundColor = 0x3366ff00;
int headerColor = 0x33339900;

void DrawIntro(){

    OSScreenPutFontEx(0, 20, 7, "Welcome to YourMenu!");
    OSScreenPutFontEx(0, 16, 8, "Press A on the DRC to continue to Main Menu.");

    OSScreenPutFontEx(1, 20, 7, "Hello World! This is the DRC.");
    OSScreenPutFontEx(1, 16, 8, "Press A on DRC to Continue to Main Menu.");
}

void DrawThemeMenu(){

    int i = 3;

    VPADStatus vpad;
    int error;

    for (;;){

        CleanBuffer();

        DrawBackground(backgroundColor);
        DrawRectangle(0, 0, 1280, 80, headerColor);

        OSScreenPutFontEx(0, 0, 0, "OPTIONS/THEMES");
        OSScreenPutFontEx(0, 2, 3, "Blue");
        OSScreenPutFontEx(0, 2, 4, "Red");
        OSScreenPutFontEx(0, 2, 5, "Green");
        OSScreenPutFontEx(0, 2, 6, "Dark");
        OSScreenPutFontEx(0, 2, 7, "Back");

        OSScreenPutFontEx(1, 0, 0, "OPTIONS/THEMES");
        OSScreenPutFontEx(1, 2, 3, "Blue");
        OSScreenPutFontEx(1, 2, 4, "Red");
        OSScreenPutFontEx(1, 2, 5, "Green");
        OSScreenPutFontEx(1, 2, 6, "Dark");
        OSScreenPutFontEx(1, 2, 7, "Back");


        OSScreenPutFontEx(0, 0, i, "->");
        OSScreenPutFontEx(1, 0, i, "->");
        VPADRead(0, &vpad, 1, &error);
            if (!error){
                if(vpad.trigger & VPAD_BUTTON_DOWN && i < 7){
                    ++i;
                }
                if(vpad.trigger & VPAD_BUTTON_UP && i > 3){
                    --i;
                }
                if (vpad.trigger & VPAD_BUTTON_A && i == 7){
                    break;
                }
                if (vpad.trigger & VPAD_BUTTON_A && i == 3){
                    themeBlue(&backgroundColor, &headerColor);
                }
                 if (vpad.trigger & VPAD_BUTTON_A && i == 4){
                    themeRed(&backgroundColor, &headerColor);
                }
                 if (vpad.trigger & VPAD_BUTTON_A && i == 5){
                    themeGreen(&backgroundColor, &headerColor);
                }
                 if (vpad.trigger & VPAD_BUTTON_A && i == 6){
                    themeDark(&backgroundColor, &headerColor);
                }
            }
            VidRefresh();
            OSSleepTicks(OSMillisecondsToTicks(16.67));
    }
}

void DrawOptionsMenu(){

    int i = 3;

    VPADStatus vpad;
    int error;

    for (;;){

        CleanBuffer();

        DrawBackground(backgroundColor);
        DrawRectangle(0, 0, 1280, 80, headerColor);

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
                if (vpad.trigger & VPAD_BUTTON_A && i == 5){
                    DrawThemeMenu();
                }
            }
            VidRefresh();
            OSSleepTicks(OSMillisecondsToTicks(16.67));
    }
}

void DrawDebugMenu(){

    int i = 3;

    VPADStatus vpad;
    int error;

    for (;;){

        CleanBuffer();

        DrawBackground(backgroundColor);
        DrawRectangle(0, 0, 1280, 80, headerColor);

        OSScreenPutFontEx(0, 0, 0, "DEBUG");
        OSScreenPutFontEx(0, 2, 3, "SAVEEXSIST");
        OSScreenPutFontEx(0, 2, 4, "SAVEREAD");
        OSScreenPutFontEx(0, 2, 5, "SAVEWRITE");
        OSScreenPutFontEx(0, 2, 6, "SAVECREATE");
        OSScreenPutFontEx(0, 2, 7, "SDMOUNTPATH");
        OSScreenPutFontEx(0, 2, 8, "Back");

        OSScreenPutFontEx(1, 0, 0, "DEBUG");
        OSScreenPutFontEx(1, 2, 3, "SAVEEXSIST");
        OSScreenPutFontEx(1, 2, 4, "SAVEREAD");
        OSScreenPutFontEx(1, 2, 5, "SAVEWRITE");
        OSScreenPutFontEx(1, 2, 6, "SAVECREATE");
        OSScreenPutFontEx(1, 2, 7, "SDMOUNTPATH");
        OSScreenPutFontEx(1, 2, 8, "Back");


        OSScreenPutFontEx(0, 0, i, "->");
        OSScreenPutFontEx(1, 0, i, "->");
        VPADRead(0, &vpad, 1, &error);
            if (!error){
                if(vpad.trigger & VPAD_BUTTON_DOWN && i < 8){
                    ++i;
                }
                if(vpad.trigger & VPAD_BUTTON_UP && i > 3){
                    --i;
                }
                if(vpad.trigger & VPAD_BUTTON_A && i == 3){
                    if(initSave() == 1){
                        OSScreenPutFontEx(0, 20, 3, "SUCCESS");
                        OSScreenPutFontEx(1, 20, 3, "SUCCESS");
                    }else{
                        OSScreenPutFontEx(0, 20, 3, "NOT FOUND");
                        OSScreenPutFontEx(1, 20, 3, "NOT FOUND");
                    }
                }
                if (vpad.trigger & VPAD_BUTTON_A && i == 7){
                    OSScreenPutFontEx(0, 20, 7, WHBGetSdCardMountPath());
                    OSScreenPutFontEx(1, 20, 7, WHBGetSdCardMountPath());
                }
                if (vpad.trigger & VPAD_BUTTON_A && i == 8){
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

        DrawBackground(backgroundColor);
        DrawRectangle(0, 0, 1280, 80, headerColor);

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
                if (vpad.trigger & VPAD_BUTTON_A && i == 4){
                    DrawDebugMenu();
                }
                if (vpad.trigger & VPAD_BUTTON_A && i == 6){
                    break;
                }
            }
            VidRefresh();
            OSSleepTicks(OSMillisecondsToTicks(16.67));
    }

}
