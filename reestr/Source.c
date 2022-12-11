#define _CRT_SECURE_NO_WARNINGS
#include <Windows.h>
#include <malloc.h>
#include <stdio.h>
#include <time.h>
int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR pCmdLine, int nCmdShow)
{
	HKEY hKey = NULL;
	if (RegOpenKeyW(HKEY_CURRENT_USER, NULL, &hKey) != ERROR_SUCCESS)//открывает раздел HKEY_CURRENT_USER
	{
		MessageBox(NULL, L"В работе программы возникла проблема", L"Информация", MB_OK);
		return 0;
	}
	HKEY tmp = NULL;
	if (RegCreateKey(hKey, L"MyKey", &tmp) == ERROR_SUCCESS)//создаем ключ
	{
		MessageBox(NULL, L"Ключ успешно создан", L"Информация", MB_OK);
	}
	time_t  ttime = time(NULL);
	LPSTR str = calloc(100, 1);
	sprintf(str, "%s", asctime(localtime(&ttime)));
	DWORD StrParamLen = wcslen(str);
	if (RegSetValueExA(tmp, "MyStrParam", NULL, REG_SZ, str, StrParamLen * sizeof(WCHAR)) == ERROR_SUCCESS)
	{
		MessageBoxA(NULL, "Числовой параметр успешно создан и ему присвоено значение", "Информация", MB_OK);
	}
	LPDWORD DataType = NULL;
	LPDWORD Datalen = 512;
	LPWSTR StrValue = malloc(512);
	if (RegGetValueW(hKey, L"MyKey", L"MyStrParam", RRF_RT_ANY, &DataType, StrValue, &Datalen) == ERROR_SUCCESS)
	{
		MessageBox(NULL, StrValue, L"Значение параметра", MB_OK);
	}
	else
	{
		MessageBoxA(NULL, "Что-то пошло не так", "Информация", MB_OK);
	}

	RegCloseKey(tmp);
	RegCloseKey(hKey);
	return 0;
}

