// PS1 ENGINE - MAIN MODULE

#include <sys/types.h>      // Typedefs for LIBGTE and LIBGPU
#include <stdio.h>          // just in case I need STD stuff here

#include <libgte.h>         // GTE header, LIBGPU depends on it
#include <libetc.h>         // funcs for display control
#include <libgpu.h>         // GPU lib header

#include "engine_types.h"   // Custom types

#include "module_init/engine_init.c" // Engine initialization routines
#include "module_renderer/render.c"  // display funcs

int main () {
    engine_spark (); // Spark the engine

    while (1) { // Trap program in loop
        renderer_display ();
    }

    return 0;
}