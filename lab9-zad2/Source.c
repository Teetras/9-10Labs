//9 Структура «Пациент»: фамилия, имя, отчество; домашний адрес; номер медицинской
//карты; номер страхового полиса.
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "windows.h"
#include <conio.h>
struct patient
{
    char name[100], NumPolis[40], NumMedCard[50];
};
int menu() {
    int c;
    printf("Menu:\n Vvod patienta-1\n Poisk patienta-2\n Pechat-3\n Dobavit' patienta-4\n Exit-5\n");
    scanf("%d", &c);
    return(c);
}
int vvod(FILE* f1, struct patient* a) {
    int n;
    printf("Poluchenie dostupa k file... \n");
    Sleep(2000);
    if ((f1 == NULL)) {
        printf("Net dostupa k file \n");
        return 0;

    }
    else printf("Dostup k file poluchen\n");
    Sleep(2000);
    printf("vvedite col-vo patientov\n");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        puts("Vvedite FIO patienta: ");
        getchar();
        gets_s(a[i].name, sizeof(a[i].name));

        printf("\n Vveli: %s\n", a[i].name);

        puts("Vvedite number med carti patienta: ");
        scanf("%s", a[i].NumMedCard);
        printf("\n Vveli: %s\n", a[i].NumMedCard);

        puts("Vvedite number polisa patienta: ");
        scanf("%s", a[i].NumPolis);
        printf("\n Vveli: %s\n", a[i].NumPolis);

        fwrite(&a[i], 1, sizeof(a[i]), f1);
    }
    fclose(f1);
}



int poisk(FILE* f1, struct patient* a) {
    printf("Poluchenie dostupa k file... \n");
    // Sleep(2000);
    if ((f1 = fopen("zadTwo.dat", "r")) == NULL) {
        printf("Net dostupa k file \n");
        return 0;

    }
    else printf("Dostup k file poluchen\n");
    //Sleep(2000);
    //занести в массив f1 ;
    int b = 0;
    printf("Vvedite nomer polisa patienta, kotorogo hotite nayti\n");
    char NumPolisSearch[40];
    getchar();
    gets_s(NumPolisSearch, sizeof(NumPolisSearch));

    int j = 0;
    while (fread(&a[j], sizeof(a[j]), 1, f1) == 1)
    {
        if (strcmp(NumPolisSearch, a[j].NumPolis) == 0) {
            printf("Patient:\n");
            printf("%s  %s  %s  \n", a[j].name, a[j].NumMedCard, a[j].NumPolis);b = 1;
        }
        j++;
    }
    if(b=0)
    {
        printf("\nPatient ne nayden\n ");
    }
    fclose(f1);
}

int add(FILE* f1, struct patient* a) {
   

  if (!(f1 = fopen("zadTwo.dat", "a")))
    {
        printf("File opening error\n");
    }
  else
  {
    int n;
    printf("vvedite col-vo patientov\n");
     scanf("%d", &n);
    for (int i = 0; i < n; i++) {
       puts("Vvedite FIO patienta: ");
       getchar();
       gets_s(a[i].name, sizeof(a[i].name));

       printf("\n Vveli: %s\n", a[i].name);

       puts("Vvedite number med carti patienta: ");
       scanf("%s", a[i].NumMedCard);
       printf("\n Vveli: %s\n", a[i].NumMedCard);

       puts("Vvedite number polisa patienta: ");
       scanf("%s", a[i].NumPolis);
       printf("\n Vveli: %s\n", a[i].NumPolis);

       fwrite(&a[i], 1, sizeof(a[i]), f1);
    }
    fclose(f1);
  }
}


int pechat(FILE* f1, struct patient* a) {
    printf("Poluchenie dostupa k file... \n");
    //Sleep(2000);
    if ((f1 = fopen("zadTwo.dat", "r")) == NULL) {
        printf("Net dostupa k file \n");
        return 0;

    }
    else printf("Dostup k file poluchen\n");

    int j = 0;
    printf("\nspisok:\n");
    while (fread(&a[j], sizeof(a[j]), 1, f1) == 1)
    {

        printf("%s  %s  %s  \n", a[j].name, a[j].NumMedCard, a[j].NumPolis);
        j++;
    }
    fclose(f1);
}

int main()
{
    struct patient mas[1000];
    int n;
    FILE* fa;
    char masss[155];
    fa = fopen("zadTwo.dat", "wb+");
   

    do {
        switch (menu())
        {
        case 1: vvod(fa, mas);
            break;
        case 2: poisk(fa, mas);
            break;
        case 3: pechat(fa, mas);
            break;
        case 4: add(fa, mas);
            break;
        case 5: return 0;
            break;
        default:
            break;
        } system("PAUSE");
    } while (1);

    fclose(fa);
   


    return 0;

}