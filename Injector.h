#include <Windows.h>
#include <iostream>
#include <TlHelp32.h>

typedef struct tagProcess {
  std::string processName;
  DWORD processId;
  HANDLE processHandle;
} Process, * lpProcesss;

enum class Returns {
  Invalid,
  Error_unexpected,
  process_quited,
  unknown,
  Success
};

Returns FindProcessByName(const char* Name, lpProcesss process);