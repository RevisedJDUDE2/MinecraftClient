#include <Windows.h>
#include <iostream>
#include <TlHelp32.h>

typedef struct tagProcess {
  std::string processName;
  DWORD processId;
  HANDLE processHandle;
} Process, * lpProcesss;

enum class ErrorCode {
  Invalid_Handle,
  Null,
  Sucess,
  Allocation_Failed,
  ITERATOR
};

struct DLL_INFORMATION {
  char *PATH;
  unsigned int SIZE_LEN;
};

ErrorCode FindProcessByName(const char* Name, lpProcesss process);

ErrorCode AllocateDll(DLL_INFORMATION di);

void InitializeInject(lpProcesss proc, DLL_INFORMATION di);

void Inject(lpProcesss proc, DLL_INFORMATION di);