#include <stdio.h>
#include "include/lab1.h"
#include "include/lab2.h"
#include "include/lab3.h"
#include "include/lab4.h"
#include "include/lab5.h"
#include "include/lab6.h"

void show_menu(){
    printf("\n LAB \n");
    printf("1. Lab 1 (Bas)\n");
    printf("2. Lab 2 (Bas)\n");
    printf("3. Lab 3 (Bas)\n");
    printf("4. Lab 4 (Bas)\n");
    printf("5. Lab 5 (Bas)\n");
    printf("6. Lab 6 (Bas)\n");
    printf("0. Exit\n");
    printf("Choose: ");
}

int main() {
    int choice;
    do {
        show_menu();
        scanf("%d", &choice);
        while (getchar() != '\n'); // очистка буфера
        switch(choice) {
            case 1: lab1_bas(); break;
            case 2: lab2_bas(); break;
            case 3: lab3_bas(); break;
            case 4: lab4_bas(); break;
            case 5: lab5_bas(); break;
            case 6: lab6_bas(); break;
            case 0: printf("Exiting\n"); break;
            default: printf("Eror.\n");
        }
    } while(choice != 0);
    return 0;
}

