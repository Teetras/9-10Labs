#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<malloc.h>
#include"windows.h"
#include"Header.h"
struct student
{
	char FIO[50];
	int yearofBirth, yearPos;
	int mark1, mark2, mark3;
};
static student* students, t;
static int n = 3, m = 4;
static	FILE  *f;
int menu() {
	int choice;
	f = fopen("laba.txt", "a");
	fclose(f);
	printf("1. ���� ���������� � ���������.\n");
	printf("2. �������� ���������� � ���������.\n");
	printf("3. �����.\n");
	printf("Enter your choice: ");
	scanf_s("%d", &choice);
	return (choice);
}

int enter() {
	students = (struct student*)malloc(m * sizeof(struct student));
	printf("������� ���������� � 4� ���������\n");
	register int i = 0;
	while (1)
	{
		if (i > n) {
			break;
		}
		printf("������� �%d\n", i + 1);
		printf("������� ������� � �������� ��������\n");
		getchar();
		gets_s(students[i].FIO, sizeof(students[i].FIO));
	
		printf("������� ��� �������� ��������\n");
		scanf_s("%d", &students[i].yearofBirth);
		

		printf("������� ��� ����������� ��������\n");
		scanf_s("%d", &students[i].yearPos);fprintf(f, "%d\n", students[i].yearPos);

		printf("������� ������ �� ������ ������ �� ���������: ������, ������ ����������, ����������� \n");
		scanf_s("%d%d%d", &students[i].mark1, &students[i].mark2, &students[i].mark3);
		

		printf("\n");
		i++;
	}	
	fclose(f);
	sort();
	return 0;

}

int sort() {
	register int i, j;
	for (i = 0;i < n;i++) {
		for (j = 0;j < n;j++) {
			if (strcmp(students[i].FIO, students[j].FIO) < 0) {
				t = students[j];
				students[j] = students[i];
				students[i] = t;
			}
		
		}
	}
	return 0;
}
int writeFile()
{ int i = 0;
	if (!(f = fopen("laba.txt", "w")))
	{
		printf("error");
	}
	else{
	while (1)
	{
		if (i > n) {
			break;
		}
		
		
		fprintf(f, "%s\n", students[i].FIO);
	
		fprintf(f, "%d\n", students[i].yearofBirth);

		
		fprintf(f, "%d\n", students[i].yearPos);

		fprintf(f, "%d %d %d\n", students[i].mark1, students[i].mark2, students[i].mark3);

		printf("\n");
		i++;
	}}

fclose(f);
return 0;
}
int read() {
	
	register int i = 0;
	printf("������ ���������:\n");
	if (!(f = fopen("laba.txt", "r")))
	{
		printf("error");
	}
	else {
	while (1)
	{
		if (i > n) {
			break;
		}
		printf("������� �%d\n", i + 1);
		fgets(students[i].FIO, sizeof(students[i].FIO) ,f);
		puts(students[i].FIO);
		fscanf(f,"%d", students[i].yearofBirth);
		printf("\n��� �������� ��������:%d\n", students[i].yearofBirth);
		fscanf(f, "%d", &students[i].yearPos);
		printf("��� ����������� ��������:%d\n", students[i].yearPos);
		fscanf(f, "%d", &students[i].mark1);
		fscanf(f, "%d",  &students[i].mark2);
		fscanf(f, "%d", &students[i].mark3);

		printf("������� ������ �� ������ ������ �� ���������: ������-%d, ������ ����������-%d, �����������-%d \n", students[i].mark1, students[i].mark2, students[i].mark3);
		printf("\n");

		i++;
	}
}
	return 0;
}