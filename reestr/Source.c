#include <Windows.h>
#include <malloc.h>

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR pCmdLine, int nCmdShow)
{
	HKEY hKey = NULL;
	if (RegOpenKeyW(HKEY_CURRENT_USER, NULL, &hKey) != ERROR_SUCCESS)
	{
		MessageBox(NULL, L"� ������ ��������� �������� ��������", L"����������", MB_OK);
		return 0;
	}
	HKEY tmp = NULL;
	if (RegCreateKey(hKey, L"MyKey", &tmp) == ERROR_SUCCESS)
	{
		MessageBox(NULL, L"���� ������� ������", L"����������", MB_OK);
	}
	time_t mytime = time(NULL);
	char* time_str = ctime(&mytime);
	time_str[strlen(time_str) - 1] = '\0';
	LPSTR str = time_str;
	if (RegSetValueExW(tmp, L"MyStrParam", NULL, REG_LINK, &str, 4) == ERROR_SUCCESS)
	{
		MessageBoxA(NULL, L"�������� �������� ������� ������ � ��� ��������� ��������", "����������", MB_OK);
	}
	LPSTR StrValue;
	if (RegGetValueW(hKey, L"MyKey", L"MyStrParam", RRF_RT_ANY, &DataType, &StrValue, &Datalen) == ERROR_SUCCESS)
	{

	}
	return 0;
}