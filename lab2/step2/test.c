#include <windows.h>

#pragma comment(lib, "user32.lib")

char code[] = {
0x55,						//push ebp
0x8B, 0xEC,					//mov ebp, esp
0x83, 0xEC, 0x20,			//sub esp,20
0xC6, 0x45, 0xE0, 0x49,		
0xC6, 0x45, 0xE1, 0x27,
0xC6, 0x45, 0xE2, 0x6D,		
0xC6, 0x45, 0xE3, 0x20,
0xC6, 0x45, 0xE4, 0x68,		
0xC6, 0x45, 0xE5, 0x61,
0xC6, 0x45, 0xE6, 0x63,		
0xC6, 0x45, 0xE7, 0x6B,
0xC6, 0x45, 0xE8, 0x65,		
0xC6, 0x45, 0xE9, 0x64,
0xC6, 0x45, 0xEA, 0x00,		
0x6A, 0x00,					//push 0
0x8D, 0x45, 0xE0,			//lea eax, dword ptr[ebp-20]
0x50,						//push eax
0x50,						//push eax
0x6A, 0x00,					//push 0
//0xA1, 0x9C, 0x50, 0x40, 0x00,	//mov eax, dword ptr[MessageBoxA]
0xB8, 0x11, 0xEA, 0xBC, 0x76,
0xFF, 0xD0,					//call eax
0x83, 0xC4, 0x20,			//add esp, 20

0x8B, 0xE5,					//mov esp, ebp
0x5D,						//pop ebp
0xC3						//ret
};
void main()
{
    int op;
	MessageBoxA(0,"","",0);
    VirtualProtect(&code[0], sizeof(code), PAGE_EXECUTE_READWRITE, &op);
    __asm {
       call offset code
    }
} 