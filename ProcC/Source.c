#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSTDC_NO_DEPRECATE
#include <stdio.h>
#include <math.h>
#include<stdlib.h>
#include <string.h>
#include <Windows.h>

#define PATH "C:\\Users\\БарашенковИТ\\source\\repos\\ProcC\\x64\\Debug\\doch_proc.exe"

typedef struct Koefs {
	float a;
	float b;
	float c;
	FILE* file;
} Koefs;

main() 
{
	system("chcp 1251 > nul");
	printf("***Квадратное уравнение*** \n");
	FILE* file;
	char a[5], b[5], c[5];
	int bool = 0;
	if ((file = fopen("Znach.txt", "r")))
	{
		fseek(file, 0, SEEK_END);
		long size = ftell(file);
		fseek(file, 0, SEEK_SET);
		char* text = calloc(size, 1);
		for (size_t i = 0; i < size; i++)
		{
			text[i] = fgetc(file);
		}
		for (size_t i = 0; i < size; i++)
		{
			if (text[i] == '\n') {
				bool = 1;
			}
			if (text[i] < -1 || text[i] >96) {
				printf("");
				return 1;
			}
		}
		fseek(file, 0, SEEK_SET);
		if (bool == 1) {
			fscanf(file, "%s\n%s\n%s", &a, &b, &c);
		}
		else
		{
			fscanf(file, "%s %s %s", &a, &b, &c);
		}
	}
		STARTUPINFO si = { 0 };
		PROCESS_INFORMATION pi = { 0 };
		DWORD d;
		ZeroMemory(&si, sizeof(si));
		si.cb = sizeof(si);
		ZeroMemory(&pi, sizeof(pi));
		char* koef = malloc(50);
		snprintf(koef, 50, "%s%c%s%c%s%c%s%c", a, ';', b, ';', c, ';', "Otvet.txt", ';');
		if (!CreateProcessA(PATH, koef, NULL, NULL, FALSE, NULL, NULL, NULL, &si, &pi))
		{
			printf("CreateProcess failed (%d).\n", GetLastError());
		}
		WaitForSingleObject(pi.hProcess, INFINITE);
		CloseHandle(pi.hProcess);
		CloseHandle(pi.hThread);
		GetExitCodeProcess(pi.hProcess, &d);

		if (d == 1) {
			HANDLE file = fopen("Otvet.txt", "r");
			char text[256];
			while ((fgets(text, 256, file)) != NULL)
			{
				printf("%s", text);
			};
		}
		return d;
}