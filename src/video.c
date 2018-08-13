#include <coreinit/screen.h>
#include <coreinit/cache.h>
#include <coreinit/thread.h>
#include "video.h"

void VidInit()
{
    OSScreenInit();

    unsigned int buffer0size = OSScreenGetBufferSizeEx(0);
    unsigned int totalBufferSize = buffer0size + OSScreenGetBufferSizeEx(1);

    OSScreenSetBufferEx(0, (void*)0xF4000000);
    OSScreenSetBufferEx(1, (void*)(0xF4000000 + buffer0size));

    OSScreenEnableEx(0, 1);
    OSScreenEnableEx(1, 1);

    OSScreenClearBufferEx(0, 0x00000000);
    OSScreenClearBufferEx(0, 0x00000000);
}

void VidRefresh(){

    unsigned int buffer0size = OSScreenGetBufferSizeEx(0);
    unsigned int totalBufferSize = buffer0size + OSScreenGetBufferSizeEx(1);

    DCFlushRange((void*)0xF4000000, totalBufferSize);

    OSScreenFlipBuffersEx(0);
    OSScreenFlipBuffersEx(1);
}

void VidClear(){

    unsigned int buffer0size = OSScreenGetBufferSizeEx(0);
    unsigned int totalBufferSize = buffer0size + OSScreenGetBufferSizeEx(1);

    OSScreenClearBufferEx(0, 0x00000000);
    OSScreenClearBufferEx(1, 0x00000000);

    OSScreenFlipBuffersEx(0);
    OSScreenFlipBuffersEx(1);

    OSScreenClearBufferEx(0, 0x00000000);
    OSScreenClearBufferEx(1, 0x00000000);


    DCFlushRange((void*)0xF4000000, totalBufferSize);
}

void CleanBuffer(){

    OSScreenClearBufferEx(0, 0x00000000);
    OSScreenClearBufferEx(1, 0x00000000);

}
