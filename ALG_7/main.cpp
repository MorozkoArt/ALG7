#define _CRT_SECURE_NO_WARNINGS
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "list.h"

int main()
{
	setlocale(LC_ALL, "Ru");
	int v = 0;
	FILE* VD;
	list* V = NULL;
	if ((VD = fopen("VD.txt", "r")) == NULL)
	{
		printf("�� ������� ������� ����");
		getchar();
		return 0;
	}
	while (fscanf(VD, "%d", &v) != EOF){
		V = addLast(V, v);
	}
	printf("����������������� ������: ");
	print(V);
	sortIncr(V);
	printf("\n��������������� ������:   ");
	print(V);
}
