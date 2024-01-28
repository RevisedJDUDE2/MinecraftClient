#include "Injector.h"

Returns FindProcessByName(const char* Name, lpProcesss process) {
  PROCESSENTRY32 proc;
  HANDLE procHandle;
  procHandle = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
  if (procHandle == INVALID_HANDLE_VALUE) {
    process->processHandle = nullptr;
    return Returns::Error_unexpected;
  };
  proc.dwSize = sizeof(PROCESSENTRY32);
  if (!Process32First(procHandle, &proc)) {
    process->processHandle = nullptr;
    return Returns::Invalid;
  }
  do {

  } while (Process32Next(procHandle, &proc));
}
