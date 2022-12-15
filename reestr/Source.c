#define _CRT_SECURE_NO_WARNINGS
#include <Windows.h>
#include <malloc.h>
#include <stdio.h>
#include <time.h>

HANDLE hConsole;

int main()
{
	system("chcp 1251>nul");
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csb;
	GetConsoleScreenBufferInfo(hConsole, &csb);

	SHORT a = 12;
	COORD CORD = { a,a };
	csb.dwSize = CORD;
	SetConsoleTextAttribute(hConsole, csb.wAttributes);

	HKEY hKey = NULL;
	if (RegOpenKeyW(HKEY_CURRENT_USER, NULL, &hKey) != ERROR_SUCCESS)//открывает раздел HKEY_CURRENT_USER
	{
		return 0;
	}
	HKEY tmp = NULL;
	if (RegCreateKey(hKey, L"MyKey", &tmp) == ERROR_SUCCESS)//создаем ключ
	{
	}
	while (1)
	{
		Sleep(1000);
		LPDWORD DataType = NULL;
		LPDWORD Datalen = 512;
		LPWSTR StrValue = malloc(1);
		LPDWORD DataType1 = NULL;
		LPDWORD Datalen1 = 512;
		LPWSTR StrValue1 = malloc(1);
		LPDWORD DataType2 = NULL;
		LPDWORD Datalen2 = 512;
		LPWSTR StrValue2 = malloc(100);
		if (RegGetValueW(hKey, L"MyKey", L"MyStrParam1", RRF_RT_ANY, &DataType, StrValue, &Datalen) == ERROR_SUCCESS)
		{

		}
		else
		{
			MessageBoxA(NULL, "Что-то пошло не так", "Информация", MB_OK);
		}
		if (RegGetValueW(hKey, L"MyKey", L"MyStrParam", RRF_RT_ANY, &DataType1, StrValue1, &Datalen1) == ERROR_SUCCESS)
		{

		}
		else
		{
			MessageBoxA(NULL, "Что-то пошло не так", "Информация", MB_OK);
		}
		if (RegGetValueW(hKey, L"MyKey", L"MyStrParam2", RRF_RT_ANY, &DataType2, StrValue2, &Datalen2) == ERROR_SUCCESS)
		{

		}
		else
		{
			MessageBoxA(NULL, "Что-то пошло не так", "Информация", MB_OK);
		}
		CONSOLE_FONT_INFOEX fontInfo;
		if (StrValue2[0] == L'1')
		{
			fontInfo.dwFontSize.Y = 10;
			SetCurrentConsoleFontEx(hConsole, TRUE, &fontInfo);
		}
		if (StrValue2[0] == L'2')
		{
			fontInfo.dwFontSize.Y = 20;
			SetCurrentConsoleFontEx(hConsole, TRUE, &fontInfo);
		}
		if (StrValue2[0] == L'3')
		{
			fontInfo.dwFontSize.Y = 40;
			SetCurrentConsoleFontEx(hConsole, TRUE, &fontInfo);
		}
		if (StrValue1[0] == L'1')
		{


			// эта строка нужна
			fontInfo.cbSize = sizeof(fontInfo);
			//wcsncpy(L"Lucida Console", fontInfo.FaceName, LF_FACESIZE);

			wcscpy(fontInfo.FaceName, L"Monofur");

		}
		if (StrValue1[0] == L'2')
		{

			// эта строка нужна
			fontInfo.cbSize = sizeof(fontInfo);
			//wcsncpy(L"Lucida Console", fontInfo.FaceName, LF_FACESIZE);

			wcscpy(fontInfo.FaceName, L"MS Gothic");
			SetCurrentConsoleFontEx(hConsole, TRUE, &fontInfo);
		}
		if (StrValue1[0] == L'3')
		{
			// эта строка нужна
			fontInfo.cbSize = sizeof(fontInfo);
			//wcsncpy(L"Lucida Console", fontInfo.FaceName, LF_FACESIZE);

			wcscpy(fontInfo.FaceName, L"Lucida Console");
			SetCurrentConsoleFontEx(hConsole, TRUE, &fontInfo);
		}
		if (StrValue[0] == 'r')
		{
			SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);

		}
		if (StrValue[0] == 'g')
		{
			SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		}


		time_t  ttime = time(NULL);
		LPSTR str1 = calloc(100, 1);
		sprintf(str1, "%s", asctime(localtime(&ttime)));
		printf("%s", str1);
		LPSTR str = calloc(100, 1);
		scanf_s("%s", str);
		sprintf(str, "%s", str);
		DWORD StrParamLen = wcslen(str);
		//printf("%s", "Выберите цвет шрифта (r - красный,g - зеленый)");
		if (RegSetValueExA(tmp, "MyStrParam1", NULL, REG_SZ, str, StrParamLen * sizeof(WCHAR)) == ERROR_SUCCESS)
		{


		}
		LPSTR str0 = calloc(100, 1);
		scanf_s("%s", str0);
		sprintf(str0, "%s", str0);
		DWORD StrParamLen0 = wcslen(str0);
		//printf("%s", "Выберите шрифт (1 - Monofur,2 - Proggy, 3 - Courier)");
		if (RegSetValueExA(tmp, "MyStrParam", NULL, REG_SZ, str0, StrParamLen0 * sizeof(WCHAR)) == ERROR_SUCCESS)
		{




		}
		LPSTR str00 = calloc(100, 1);
		scanf_s("%s", str00);
		sprintf(str00, "%s", str00);
		DWORD StrParamLen00 = wcslen(str00);
		//printf("%s", "Выберите шрифт (1 - Monofur,2 - Proggy, 3 - Courier)");
		if (RegSetValueExA(tmp, "MyStrParam2", NULL, REG_SZ, str00, StrParamLen00 * sizeof(WCHAR)) == ERROR_SUCCESS)
		{


		}
	}

	RegCloseKey(tmp);
	RegCloseKey(hKey);
	return 0;







	//HKEY hKey = NULL;
	//if (RegOpenKeyW(HKEY_CURRENT_USER, NULL, &hKey) != ERROR_SUCCESS)//открывает раздел HKEY_CURRENT_USER
	//{
	//	MessageBox(NULL, L"В работе программы возникла проблема", L"Информация", MB_OK);
	//	return 0;
	//}
	//HKEY tmp = NULL;
	//if (RegCreateKey(hKey, L"MyKey", &tmp) == ERROR_SUCCESS)//создаем ключ
	//{
	//	MessageBox(NULL, L"Ключ успешно создан", L"Информация", MB_OK);
	//}
	//time_t  ttime = time(NULL);
	//LPSTR str = calloc(100, 1);
	//sprintf(str, "%s", asctime(localtime(&ttime)));
	//DWORD StrParamLen = wcslen(str);
	//if (RegSetValueExA(tmp, "MyStrParam", NULL, REG_SZ, str, StrParamLen * sizeof(WCHAR)) == ERROR_SUCCESS)
	//{
	//	MessageBoxA(NULL, "Числовой параметр успешно создан и ему присвоено значение", "Информация", MB_OK);
	//}
	//LPDWORD DataType = NULL;
	//LPDWORD Datalen = 512;
	//LPWSTR StrValue = malloc(512);
	//if (RegGetValueW(hKey, L"MyKey", L"MyStrParam", RRF_RT_ANY, &DataType, StrValue, &Datalen) == ERROR_SUCCESS)
	//{
	//	MessageBox(NULL, StrValue, L"Значение параметра", MB_OK);
	//}
	//else
	//{
	//	MessageBoxA(NULL, "Что-то пошло не так", "Информация", MB_OK);
	//}

	//RegCloseKey(tmp);
	//RegCloseKey(hKey);
	return 0;
}

