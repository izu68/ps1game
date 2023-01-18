// ENGINE INITIALIZATION MODULE (INIT GPU AND OTHER THINGS)

#ifndef             __ENGINE_INIT_C_
#define             __ENGINE_INIT_C_

#include "../common_inc.h"
#include "stdlib.h"

static u16 init_gfx () {
    ResetGraph (0); // This resets the GPU and enables interrupts
    // NOTE: Resetting the GPU also maks out video output,
    //       making the screen black. Useful for transitioning
    //       into the program.

    if (GetVideoMode() == 0) { // Execute if GPU is NTSC
        // Configure pair of DISPENVS
        SetDefDispEnv (&disp[0], 0, 0, 320, 240);   // Set buffer 1
        SetDefDispEnv (&disp[1], 0, 240, 320, 240); // Buffer 2 just below

        // Configure pair of DRAWENVs for the DISPENVs
        SetDefDrawEnv (&draw[0], 0, 240, 320, 240); 
        SetDefDrawEnv (&draw[1], 0, 0, 320, 240);
    }
    else { // Execute if GPU is PAL (setup is a bit different)
        // Configure pair of DISPENVS
        // NOTE: Y is 256 because the PAL video signal is taller in res
        SetDefDispEnv (&disp[0], 0, 0, 320, 256);   // Set buffer 1
        SetDefDispEnv (&disp[1], 0, 240, 320, 256); // Buffer 2 just below

        disp[0].screen.y = 24; // offset to center the picture vertically
        disp[1].screen.y = disp[0].screen.y;
        
        SetVideoMode(MODE_PAL); // Forces PAL video standard

        // Configure pair of DRAWENVs for the DISPENVs
        SetDefDrawEnv (&draw[0], 0, 256, 320, 256); // adjust taller res
        SetDefDrawEnv (&draw[1], 0, 0, 320, 256);
    }

    u8 random_color[3];
    random_color[0] = rand() % (255 + 1 - 0) + 0;
    random_color[1] = rand() % (255 + 1 - 0) + 0;
    random_color[2] = rand() % (255 + 1 - 0) + 0;
    setRGB0(&draw[0], random_color[0], random_color[1], random_color[2]); // Set BKG color for testing
    setRGB0(&draw[1], random_color[0], random_color[1], random_color[2]);

    draw[0].isbg = 1; // Enable BKG clear
    draw[1].isbg = 1;

    PutDispEnv (&disp[0]); // Apply DISPENV to screen (first buffer)
    PutDrawEnv (&draw[0]); // Apple DRAWENV to screen       =

    db = 0; // Make sure the buffer index starts with zero

    return 0;
}

u8 engine_spark () {
    init_gfx ();

    return 0;
}

#endif