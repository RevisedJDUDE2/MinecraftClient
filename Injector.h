#include <Windows.h>
#include <iostream>
#include <TlHelp32.h>

typedef struct tagProcess {
  std::string processName;
  unsigned int processId;
  HANDLE processHandle;
} Process, * lpProcesss;

enum class Returns {
  Invalid,
  Error_unexpected,
  process_quited,
  unknown
};

Returns FindProcessByName(const char* Name, lpProcesss process);