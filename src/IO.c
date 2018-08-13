#include <whb/file.h>
#include <whb/sdcard.h>
#include "IO.h"
#include <stdio.h>
#include <coreinit/screen.h>

int initSave(){

    char *sdRootPath = NULL;
    char *settingsData = NULL;
    char path[256];

    sdRootPath = WHBGetSdCardMountPath();
    sprintf(path, "%s/wiiu/apps/WiiUShell/settings.txt", sdRootPath);
    settingsData = WHBReadWholeFile(path, NULL);

    if (!settingsData){
        return 0;
    }else{
    OSScreenPutFontEx(0, 20, 4, settingsData);
    OSScreenPutFontEx(1, 20, 4, settingsData);
    WHBFreeWholeFile(settingsData);
    settingsData = NULL;
        return 1;
    }
}

