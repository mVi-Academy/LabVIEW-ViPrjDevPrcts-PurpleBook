#include "extcode.h"
#include <windows.h>

_declspec(dllexport) void WinHWND(char *name, HWND *output);
_declspec(dllexport) void WinHWND(char *name, HWND *output)
{
  int i;
  /* Get the HWND of the "name" window. */
  *output = FindWindow(NULL, name);
  for(i = 0; i < 10; i++)
  {
    /* Flash the "name" window on and off 5 times. */
    FlashWindow(*output, TRUE);
    Sleep(100);
  }
}
