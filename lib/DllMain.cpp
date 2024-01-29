#include <Windows.h>
#pragma comment(lib, "user32.lib")

BOOL APIENTRY DllMain(HMODULE hMod, DWORD reason, LPVOID reserved) {
  if (reason == DLL_PROCESS_ATTACH) {
    MessageBoxA(nullptr, "INJECTED", "", MB_OK);
  }
  return TRUE;
}
