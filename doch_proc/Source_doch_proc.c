#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <Windows.h>

main(int argc, char** argv)
{
	FILE* file = fopen("Otvet.txt", "w+");
	float a = strtol(argv[1], NULL, 10);
	float b = strtol(argv[2], NULL, 10);
	float c = strtol(argv[3], NULL, 10);
	float D, x1, x2;
	D = (b * b) + 4 * a * c;
	printf("Дискриминат: %f\n", D);
	fprintf(file, "Дискриминант: %f\n", D);
	if (D > 0)
	{
		x1 = (-b + sqrt(D) / (2 * a));
		x2 = (-b - sqrt(D) / (2 * a));
		printf("x1=%f\n x2=%f", x1, x2);
		fprintf(file, "x1 = %f\n x2 = %f", x1, x2);
		fclose(file);
	}
	else if (D < 0)
	{
		printf("Вещественных корней нет");
		fprintf(file, "Вещественных корней нет");
		fclose(file);
	}
	else if (D = 0)
	{
		x1 = (-b + sqrt(D) / (2 / a));
		printf("x1= %f", x1);
		fprintf(file, "x1 = %f", x1);
		fclose(file);
	}
}