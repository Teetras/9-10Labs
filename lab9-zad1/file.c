//������� 10: ������� ��������� ���� F1 �� �����, ��� �� 10 ����� � �������� � ����
//����������.����������� � ���� F2 ������ �� ������ �� F1, ������� �� �������� ����.
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
		if (strpbrk(str, ds) == NULL) {//����� �������� �� �� � ������ ���������� 
			fputs(str, f2);
		}
	}
	
	fclose(f2);
	fclose(f);
}