#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include "windows.h"
#include"Header.h"
#include<locale.h>

int main() {
    setlocale(0, "rus");

 do{
        switch (menu())
        {
        case 1:enter();
            break;
        case 2:read();
            break;
        case 3: return 0;
            break;
        default:
            break;
        } system("PAUSE");
    } while (1) ;
    return 0;
}