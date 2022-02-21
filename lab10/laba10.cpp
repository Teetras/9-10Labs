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
	

	printf("Результат:\n%s", st);
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

	printf("\nРезультат:%s\n", res);
	return 0;
}

int main() {
	setlocale(0, "rus");
	char zamfName[50];
	printf("Задание 1\n");
	printf("Введите название файла:");
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
	printf("Задание 2\n");
	char str[50];
	printf("Введите предложение для поиска слов заканчивающихся на букву 'a':");
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

	printf("Задание 3\n");
	char FIO[60];
	printf("Введите ФИО для приветствия\n");
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

	printf("Задание 4\n");
	char s[60];
	printf("Введите строку для переставления местами соседние символы:\n");
	gets_s(s, sizeof(s));
	int lon=strlen(s);
	zamema(s,lon);

	printf("\nЗадание 5\n");
	char ST[60];
	printf("Введите строку для для удаления лишних пробелов:\n");
	gets_s(ST, sizeof(ST));
	 lon = strlen(ST);
	udalenie(ST, lon);

}