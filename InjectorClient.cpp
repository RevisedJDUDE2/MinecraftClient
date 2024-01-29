#include <iostream>
#include "Injector.h"

int main() {
  Process MinecraftProcess;
  if (FindProcessByName("Minecraft.Windows.exe", &MinecraftProcess) == ErrorCode::Invalid_Handle ||
    FindProcessByName("Minecraft.Windows.exe", &MinecraftProcess) == ErrorCode::Null) {
    std::cout << "Error: Cannot find proc or the first proc is null\n";
  }
  HANDLE McHandle = OpenProcess(PROCESS_ALL_ACCESS, FALSE, MinecraftProcess.processId);
  return 0;
}