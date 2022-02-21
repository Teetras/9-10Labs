//Вариант 10: Создать текстовый файл F1 не менее, чем из 10 строк и записать в него
//информацию.Скопировать в файл F2 только те строки из F1, которые не содержат цифр.
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<conio.h>
#include<string.h>

int main() {
	char str[255];
	int a;
	FILE* f, * f2;
	if (!(f = fopen("test.txt", "w+"))) {
		printf("net dostupa k file");
	}
	puts("skolko strok vvedem?");
	scanf("%d", &a);
	puts("Vvedite  stroki");

	getchar();
	for (int i = 0; i < a;i++) {
		gets_s(str, 255);

		fprintf(f, "%s\n", str);
	}
	rewind(f);
	f2 = fopen("test2.txt", "w");const char ds[] = "0123456789";
	while (fgets(str, 255, f) != NULL) {
		if (strpbrk(str, ds) == NULL) {//поиск символов из дс в строке поочередно 
			fputs(str, f2);
		}
	}
	
	fclose(f2);
	fclose(f);
}