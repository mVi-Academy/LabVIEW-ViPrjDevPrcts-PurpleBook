// dllmain.cpp : Defines the entry point for the DLL application.
#include "pch.h"

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
       // Initialize once for each new process.
       // Return FALSE if fail DLL load.            
        break;
    case DLL_THREAD_ATTACH:
        // Thread-specific initialization.
        break;
    case DLL_THREAD_DETACH:
        // Thread-specificcleanup.            
        break;
    case DLL_PROCESS_DETACH:
        // Perform any necessary cleanup.
        break;
    }
    return TRUE;
}

