#include "Injector.h"

ErrorCode::codes FindProcessByName(const char* Name, lpProcesss process) {
  PROCESSENTRY32 proc;
  HANDLE procHandle;
  procHandle = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
  if (procHandle == INVALID_HANDLE_VALUE) {
    process->processHandle = nullptr;
    return ErrorCode::Invalid_Handle;
  };
  proc.dwSize = sizeof(PROCESSENTRY32);
  if (!Process32First(procHandle, &proc)) {
    process->processHandle = nullptr;
    return ErrorCode::Null;
  }
  do {
    if (strcmp(proc.szExeFile, Name) == 0) {
      process->processHandle = procHandle;
      process->processId = proc.th32ProcessID;
      return ErrorCode::Sucess;
    }
    //if (proc.szExeFile == Name) {
    //  process->processHandle = procHandle;
    //  process->processId = proc.th32ProcessID;
    //  return Returns::Success;
    //}
  } while (Process32Next(procHandle, &proc));
  CloseHandle(procHandle);
}
