#include <Windows.h>
#include <iostream>
#include <TlHelp32.h>

typedef struct tagProcess {
  std::string processName;
  DWORD processId;
  HANDLE processHandle;
} Process, * lpProcesss;

struct ErrorCode {
  enum codes {
    Invalid_Handle,
    Null,
    Sucess,
    ITERATOR
  };
};

ErrorCode::codes FindProcessByName(const char* Name, lpProcesss process);