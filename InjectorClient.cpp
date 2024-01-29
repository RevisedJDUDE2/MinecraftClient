#include <iostream>
#include "Injector.h"

int main(int argc, char *argv) {
  char DLL_PATH[MAX_PATH] = "C:\\McClient.dll"; //this is an invalid dll
  Process MinecraftProcess;
  if (FindProcessByName("notepad.exe", &MinecraftProcess) == ErrorCode::Invalid_Handle ||
    FindProcessByName("notepad.exe", &MinecraftProcess) == ErrorCode::Null) {
    std::cout << "Error: Cannot find proc or the first proc is null\n";
  }
  HANDLE McHandle = OpenProcess(PROCESS_ALL_ACCESS, FALSE, MinecraftProcess.processId);
  DLL_INFORMATION di;
  di.PATH = DLL_PATH;
  AllocateDll(di);
  InitializeInject(&MinecraftProcess, di);
  Inject(&MinecraftProcess, di);
  while (true) {
    if (GetAsyncKeyState(VK_ESCAPE)) {
      break;
    }
  }
  return 0;
}