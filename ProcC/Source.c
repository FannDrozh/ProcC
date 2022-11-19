#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <Windows.h>
#include <tchar.h>
#define PATH L"..\x64\Debug\doch_proc.exe"

main() 
{
	system("chcp 1251 > nul");
	printf("***Квадратное уравнение*** \n");
	FILE* file; FILE* otv;
	otv = fopen("Otvet.txt", "w+");
	char line[254];
	float a, b, c;
	a = 0; b = 0; c = 0;
	if ((file = fopen("Znach.txt", "r")))
	{
		fgets(line, 254, file);
		//A
		int probelA = 0;
		int umnA = 1;
		int numA = 1;
		double Apr = 0;
		for (int i = 0; i < 254; i++)
		{
			if (line[i] != 32)
			{
				probelA++;
			}
			else
			{
				break;
			}
		}
		for (int i = probelA - 1; i >= 0; i--)
		{
			if (line[i] == 46)
			{
				for (int j = 0; j < probelA - 1; j++)
				{
					numA = numA * 10;
				}
				a = a / numA;
				umnA = 1;
			}
			else
			{
				if (line[0] == 45)
				{
					if (line[i] != 45)
					{
						Apr = line[i] - '0';
						a += Apr * umnA;
						umnA = umnA * 10;
					}
					else
					{
						a = a * -1;
					}
				}
				else
				{
					Apr = line[i] - '0';
					a += Apr * umnA;
					umnA = umnA * 10;
				}
			}
		}
		//B
		int probelB = probelA;
		int umnB = 1;
		int numB = 1;
		double Bpr = 0;	
		for (int i = probelA + 1; i < 255; i++)
		{
			if (line[i] != 32)
			{
				probelB++;
			}
			else
			{
				break;
			}
		}
		for (int i = probelB; i >= probelA + 1; i--)
		{
			if (line[i] == 46)
			{
				for (int j = 0; j < probelB - 1; j++)
				{
					numB = numB * 10;
				}
				b = b / numB;
				umnB = 1;
			}
			else
			{
				if (line[0] == 45)
				{
					if (line[i] != 45)
					{
						Bpr = line[i] - '0';
						b += Bpr * umnB;
						umnB = umnB * 10;
					}
					else
					{
						b = b * -1;
					}
				}
				else
				{
					Bpr = line[i] - '0';
					b += Bpr * umnB;
					umnB = umnB * 10;
				}
			}
		}
		//C
		int probelC = probelB;
		int umnC = 1;
		int numC = 1;
		double Cpr = 0;
		for (int i = probelB + 2; i < 255; i++)
		{
			if (line[i] != -52)
			{
				probelC++;
			}
			else
			{
				break;
			}
		}
		for (int i = probelC; i >= probelB + 2; i--)
		{
			if (line[i] == 46)
			{
				for (int j = 0; j < probelC - 1; j++)
				{
					numC = numC * 10;
				}
				c = c / numC;
				umnC = 1;
			}
			else
			{
				if (line[0] == 45)
				{
					if (line[i] != 45)
					{
						Cpr = line[i] - '0';
						c += Cpr * umnC;
						umnC = umnC * 10;
					}
					else
					{
						c = c * -1;
					}
				}
				else
				{
					Cpr = line[i] - '0';
					c += Cpr * umnC;
					umnC = umnC * 10;
				}
			}
		}
		STARTUPINFO si;
		PROCESS_INFORMATION pi;
		ZeroMemory(&si, sizeof(si));
		si.cb = sizeof(si);
		ZeroMemory(&pi, sizeof(pi));
		char str[4];
		str[0] = &PATH;
		str[1] = a;
		str[2] = b;
		str[3] = c;
		LPWSTR lp = &PATH;
		if (!CreateProcess(str, lp, NULL, NULL, FALSE, 0, CREATE_NEW_CONSOLE, NULL, &si, &pi))
		{
			printf("CreateProcess failed (%d).\n", GetLastError());
		}
		WaitForSingleObject(pi.hProcess, INFINITE);
		CloseHandle(pi.hProcess);
		CloseHandle(pi.hThread);

	}
}