#include "Injector.h"

ErrorCode FindProcessByName(const char* Name, lpProcesss process) {
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

ErrorCode AllocateDll(DLL_INFORMATION di) {
  di.SIZE_LEN = sizeof(di.PATH) + 1;
  return ErrorCode::Sucess;
}

HANDLE RemoteThreadCOPY{};
LPVOID RemoteBufferCOPY;
VOID* loadlibCOPY;

void InitializeInject(lpProcesss proc, DLL_INFORMATION di) {
  DWORD pid = proc->processId;
  HANDLE procHandle = proc->processHandle;
  HANDLE remoteThread{};
  LPVOID remoteBuffer;

  HMODULE Kernel32DLL = GetModuleHandle("Kernel32");
  VOID* loadlib = GetProcAddress(Kernel32DLL, "LoadLibraryA");

  remoteBuffer = VirtualAllocEx(procHandle, NULL, di.SIZE_LEN, (MEM_RESERVE | MEM_COMMIT), PAGE_EXECUTE_READWRITE);
  RemoteBufferCOPY = remoteBuffer;
  RemoteThreadCOPY = remoteThread;
  loadlibCOPY = &loadlib;
}

void Inject(lpProcesss proc, DLL_INFORMATION di) {
  WriteProcessMemory(proc->processHandle, RemoteBufferCOPY, di.PATH, di.SIZE_LEN, NULL);
  RemoteThreadCOPY = CreateRemoteThread(proc->processHandle, NULL, 0, (LPTHREAD_START_ROUTINE)loadlibCOPY, RemoteBufferCOPY, 0, NULL);
}
