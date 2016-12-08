// Lab_5.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <iostream>
#include <time.h>




unsigned  Simple(int z[], int a)
{
	int i = 0, k = 0, d = 1, j = 0;
	for (i = 0; i < a; i++)
	{
		d = 1;
		if (z[i] == 1) d = 0;
		for (j = 2; j*j <= z[i]; j++) 
		{
			if (z[i]%j == 0) d=0;
		}
		if (d == 1) k = k + 1;
	}

	return k;
}



int main(int argc, char *argv[])
{
	int a, b, k;


	if (argc < 3) 
	{
		printf_s("An error in the command line parameters is not enough to define the source data.Press any key to end\n");
		system("pause");
		return 1;
	}
	
	if (sscanf_s(argv[1], "%d", &a) < 1) 
	{
		printf_s("Error, wrong format of the first input parameter. Press any key to end\n");
		system("pause");
		return 1;
	}
	if (sscanf_s(argv[2], "%d", &b) < 1) 
	{
		printf_s("Error, wrong format of the first input parameter.Press any key to end\n");
		system("pause");
		return 1;
	}


	int *z;
	z = (int *)malloc(a * sizeof(int));

	int i = 0;
	srand(time(NULL));
	for (i = 0; i < a; i++)
	{
		z[i] = 1 + rand() % 200;
		printf_s("\n %2d   ", z[i]);
	}


	k = Simple(z, a);
	if (k < b) printf_s("\n False statement");
	else printf_s("\n True statement");


	
	system("pause");

    return 0;
}

