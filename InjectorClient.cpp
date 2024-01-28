#include <iostream>
#include "Injector.h"

int main() {
  Process MinecraftProcess;
  if (FindProcessByName("Minecraft.windows.exe", &MinecraftProcess) == (Returns::Error_unexpected || Returns::Invalid)) {

  }
  HANDLE McHandle = OpenProcess(PROCESS_ALL_ACCESS, FALSE, MinecraftProcess.processId);
  return 0;
}