#include <iostream>
#include <Windows.h>

int main() 
{
	const LPCSTR WINDOW_NAME = "Clicker Heroes";
	double value = 200;
	LPVOID adress = (LPVOID)0x0E7E21B8;

	HWND hwnd = FindWindowA(NULL, WINDOW_NAME);

	if (hwnd == NULL)
	{
		std::cout << "Can`t find the window " << WINDOW_NAME << std::endl;
		Sleep(1000);
		exit(-1);
	}
	else
	{
		std::cout << "Found Window " << WINDOW_NAME << std::endl;
		DWORD process_id;
		GetWindowThreadProcessId(hwnd, &process_id);
		HANDLE handle = OpenProcess(PROCESS_ALL_ACCESS, FALSE, process_id);

		if (process_id == NULL) {
			std::cout << "Can`t obtain the process " << process_id << std::endl;
			Sleep(3000);
			exit(-1);
		}
		else
		{
			WriteProcessMemory(handle, adress, &value, sizeof(value), 0);
			std::cout << "Succsessfuly changed value to " << value << " in " << adress << std::endl;
		}
	}

	return 0;
}