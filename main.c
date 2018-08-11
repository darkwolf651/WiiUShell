#include <coreinit/thread.h>
#include <coreinit/time.h>
#include <coreinit/screen.h>
#include <coreinit/cache.h>
#include <coreinit/systeminfo.h>
#include <coreinit/exit.h>
#include <vpad/input.h>
#include <whb/proc.h>

#include "video.h"
#include "menu.h"



int main(int argc, char **argv)
{
    WHBProcInit();
    VidInit();
    VPADInit();

    DrawIntro();
    VidRefresh();

    VPADStatus vpad;
    int error;

    for(;;) {
        VPADRead(0, &vpad, 1, &error);
        if (!error){
            if(vpad.hold & VPAD_BUTTON_A){
                VidClear();
                DrawMainMenu();
                break;
            }
        }
        OSSleepTicks(OSMillisecondsToTicks(16.67));
    }


    exit:
        VidClear();
        OSScreenShutdown();
        WHBProcShutdown();
        return 0;
}
