#include <iostream>
#include "Injector.h"

int main() {
  Process MinecraftProcess;
  FindProcessByName("Minecraft.windows.exe", &MinecraftProcess);
  HANDLE McHandle = OpenProcess(PROCESS_ALL_ACCESS, FALSE, MinecraftProcess.processId);
  return 0;
}