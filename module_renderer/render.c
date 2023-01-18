// RENDERING MODULE - SWITCHES FRAME BUFFERS AND DISPLAYS STUFF

#ifndef             __ENGINE_RENDERER_
#define             __ENGINE_RENDERER_

#include "../common_inc.h"

u8 renderer_display () { // Display function for the renderer
    // NOTE: Before performing a buffer swap, you must first call 
    // DrawSync() then VSync(). As the names suggests these functions waits 
    // for the GPU to complete any drawing operations and waits for the 
    // vblank period respectively. Waiting for DrawSync() is important as 
    // it makes sure that the GPU has completed drawing any primitives as 
    // otherwise you may get flicker or possibly instability. Waiting for 
    // VSync() is also important as it not only caps your program loop to 
    // the TV refresh rate (60fps for NTSC, 50 for PAL) but it also 
    // prevents screen tearing which will happen if you swap buffers 
    // without waiting for the v-blank period. 

    DrawSync (0);
    VSync (0);

    db = !db; // Flip buffer counter

    PutDispEnv (&disp[db]); // Apply environments with new buffer value
    PutDrawEnv (&draw[db]);

    SetDispMask (1); // Enable display

    return 0;
}

#endif