#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSTDC_NO_DEPRECATE
#include <stdio.h>
#include <math.h>
#include<stdlib.h>
#include <string.h>
#include <Windows.h>

#define PATH "..source\\repos\ProcC\\Debug\\doch_proc.exe"

main() 
{
	system("chcp 1251 > nul");
	printf("***Квадратное уравнение*** \n");
	FILE* file;
	char line[254];
	float x1, x2;
	float a, b, c, aost, bost , cost;
	a = 0; b = 0; c = 0; aost = 0, bost = 0, cost = 0;
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
		PROCESS_INFORMATION pi = { 0 };
		ZeroMemory(&si, sizeof(si));
		si.cb = sizeof(si);
		ZeroMemory(&pi, sizeof(pi));
		char* lp = malloc(150);
		char sta[20];
		char stb[20];
		char stc[20];
		char staOST[20];
		char stbOST[20];
		char stcOST[20];
		itoa(a, sta, 10);
		itoa(b, stb, 10);
		itoa(c, stc, 10);
		itoa(aost, staOST, 10);
		itoa(bost, stbOST, 10);
		itoa(cost, stcOST, 10);
		snprintf(lp, 100, "%s %s.%s %s.%s %s.%s", PATH, sta, staOST, stb, stbOST, stc, stcOST);
		if (!CreateProcess(NULL, lp, NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi))
		{
			printf("CreateProcess failed (%d).\n", GetLastError());
		}
		WaitForSingleObject(pi.hProcess, INFINITE);
		CloseHandle(pi.hProcess);
		CloseHandle(pi.hThread);

	}
}