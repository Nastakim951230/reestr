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
	time_t mytime = time(NULL); //присваеваем текущее время
	char* time_str = ctime(&mytime);//переврдим время в текст и присваеваем time_str
	
	LPWSTR str = time_str;
	DWORD strLen = wcslen(str);
	if (RegSetValueExW(tmp, L"MyStrParam", NULL, REG_LINK, &str,strLen * sizeof(WCHAR)) == ERROR_SUCCESS)//проверяем сохранились ли данный в поле значения открытого ключа
	{
		MessageBoxA(NULL, L"Числовой параметр успешно создан и ему присвоено значение", "Информация", MB_OK);
	}
	LPWSTR StrValue=malloc(512);
	DWORD DataType = 0;
	DWORD Datalen = 512;
	if (RegGetValueW(hKey, L"MyKey", L"MyStrParam", RRF_RT_ANY, &DataType, &StrValue, &Datalen) == ERROR_SUCCESS)
	{
		
		MessageBox(NULL, StrValue, L"Значение параметра", MB_OK);
	}
	else
	{
		MessageBox(NULL, L"Что-то пошло не так", L"Информация", MB_OK);
	}

	RegCloseKey(tmp);
	RegCloseKey(hKey);
	return 0;
}

