#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<locale.h>
#include "windows.h"

int zamema(char *st, int lot) {
	int j = 0;
	char t;
	while ((st[j]!='\0') &&(st[j+1] != '\0'))
	{
		t = st[j];
		st[j] = st[j + 1];
		st[j + 1] = t;
		j = j + 2;
	
	}
	

	printf("���������:\n%s", st);
return 0;
}
int udalenie(char *str, int loot) {
	char res[60]="";
	int j = 0,i;
	for (i = 0; i <loot; i++) {
		if (str[i] == ' ')
		{
			if (j == 0) continue;
			if (str[i + 1] == ' ') continue;
		}
		res[j] = str[i];
		j++;
	}
	i = strlen(res);
	if (res[i - 2] == ' ')
		res[i - 2] = '\0';

	printf("\n���������:%s\n", res);
	return 0;
}

int main() {
	setlocale(0, "rus");
	char zamfName[50];
	printf("������� 1\n");
	printf("������� �������� �����:");
	gets_s(zamfName, sizeof(zamfName));
	int i = 0;
	while (zamfName[i] != '.')
	{
		if (zamfName[i] == '\0') break;
		i++;
	}
	if (zamfName[i] == '.') {
		strcpy(zamfName + i, ".exe");
	}
	else 
	{
		strcat(zamfName , ".exe");

	}
	printf("%s\n", zamfName);

	Sleep(1000);
	printf("������� 2\n");
	char str[50];
	printf("������� ����������� ��� ������ ���� ��������������� �� ����� 'a':");
	gets_s(str, sizeof(str));
	i = 0;
	int counter=0;
	 char c = 'a';
	while (str[i]!='\0')
	{
		if ((str[i] == c && str[i + 1] == ' ')|| (str[i] == c && str[i + 1] == '\0')) { counter++; }
		i++;
	}
	printf("%d\n", counter);
	Sleep(1000);

	printf("������� 3\n");
	char FIO[60];
	printf("������� ��� ��� �����������\n");
	gets_s(FIO, sizeof(FIO));
	counter = 0;
	i = 0;
	while (FIO[i] != '\0')
	{
		if (FIO[i] != ' ' && FIO[i + 1] == ' ') { counter++; }
		if (counter==2) break;

		i++;
	}
	strcpy(FIO + (i+1), " ");
	printf("Hello, %s!\n", FIO);

	printf("������� 4\n");
	char s[60];
	printf("������� ������ ��� ������������� ������� �������� �������:\n");
	gets_s(s, sizeof(s));
	int lon=strlen(s);
	zamema(s,lon);

	printf("\n������� 5\n");
	char ST[60];
	printf("������� ������ ��� ��� �������� ������ ��������:\n");
	gets_s(ST, sizeof(ST));
	 lon = strlen(ST);
	udalenie(ST, lon);

}