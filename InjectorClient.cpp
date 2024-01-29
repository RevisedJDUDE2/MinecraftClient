#include <iostream>
#include "Injector.h"

int main() {
  Process MinecraftProcess;
  if (FindProcessByName("Minecraft.Windows.exe", &MinecraftProcess) == Returns::Error_unexpected || FindProcessByName("Minecraft.Windows.exe", &MinecraftProcess) == Returns::Invalid) {
    std::cout << "Error: Cannot find proc or the first proc is null\n";
  }
  HANDLE McHandle = OpenProcess(PROCESS_ALL_ACCESS, FALSE, MinecraftProcess.processId);
  return 0;
}