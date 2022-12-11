#define _CRT_SECURE_NO_WARNINGS
#include <Windows.h>
#include <malloc.h>
#include <stdio.h>
#include <time.h>
int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR pCmdLine, int nCmdShow)
{
	HKEY hKey = NULL;
	if (RegOpenKeyW(HKEY_CURRENT_USER, NULL, &hKey) != ERROR_SUCCESS)//��������� ������ HKEY_CURRENT_USER
	{
		MessageBox(NULL, L"� ������ ��������� �������� ��������", L"����������", MB_OK);
		return 0;
	}
	HKEY tmp = NULL;
	if (RegCreateKey(hKey, L"MyKey", &tmp) == ERROR_SUCCESS)//������� ����
	{
		MessageBox(NULL, L"���� ������� ������", L"����������", MB_OK);
	}
	time_t  ttime = time(NULL);
	LPSTR str = calloc(100, 1);
	sprintf(str, "%s", asctime(localtime(&ttime)));
	DWORD StrParamLen = wcslen(str);
	if (RegSetValueExA(tmp, "MyStrParam", NULL, REG_SZ, str, StrParamLen * sizeof(WCHAR)) == ERROR_SUCCESS)
	{
		MessageBoxA(NULL, "�������� �������� ������� ������ � ��� ��������� ��������", "����������", MB_OK);
	}
	LPDWORD DataType = NULL;
	LPDWORD Datalen = 512;
	LPWSTR StrValue = malloc(512);
	if (RegGetValueW(hKey, L"MyKey", L"MyStrParam", RRF_RT_ANY, &DataType, StrValue, &Datalen) == ERROR_SUCCESS)
	{
		MessageBox(NULL, StrValue, L"�������� ���������", MB_OK);
	}
	else
	{
		MessageBoxA(NULL, "���-�� ����� �� ���", "����������", MB_OK);
	}

	RegCloseKey(tmp);
	RegCloseKey(hKey);
	return 0;
}

