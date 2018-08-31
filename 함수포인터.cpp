#pragma once
#include <windows.h>

#pragma once
#include <Windows.h>
#include "../ClassDll/CChapter.h"

//Define the function prototype
typedef int(*fnMul)(int	& a, int& b);

int main()
{
	HINSTANCE dllHandle = NULL;
	fnMul _pMul = NULL;

	//Load the dll and keep the handle to it
	dllHandle = LoadLibrary("ClassDll.dll");

	//If the handle is valid, try to get the function address.
	if (NULL != dllHandle)
	{
		//Get pointer to our function using GetProcAddress:
		_pMul = (fnMul)GetProcAddress(dllHandle, "mul");

		int a = 100;
		int b = 200;
		int result = _pMul(a, b);

		//Free the Library:
		FreeLibrary(dllHandle);
	}
}