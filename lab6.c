#include <stdio.h>
#define K 3
#define N 4
#include "../include/lab6.h"

void lab6_bas() {

int x[K][N];
    int i, j;
    int min_val, max_val;           // значения минимального и максимального элементов
    int min_row = 0, max_row = 0; // номера строк с минимальным и максимальным элементами

    // ввод массива
    for (i = 0; i < K; i++)
        for (j = 0; j < N; j++)
            scanf("%d", &x[i][j]);

    // инициализация min_val и max_val первым элементом массива
    min_val = x[0][0];
    max_val = x[0][0];

    // поиск минимального и максимального элементов и их строк
    for (i = 0; i < K; i++) {
        for (j = 0; j < N; j++) {
            if (x[i][j] < min_val) {
                min_val = x[i][j];
                min_row = i;
            }
            if (x[i][j] > max_val) {
                max_val = x[i][j];
                max_row = i;
            }
        }
    }

    // обмен строк: min_row и max_row
    if (min_row != max_row) { // если строки разные, выполняем обмен
        for (j = 0; j < N; j++) {
            int temp = x[min_row][j];
            x[min_row][j] = x[max_row][j];
            x[max_row][j] = temp;
        }
    }

    // вывод массива
    for (i = 0; i < K; i++) {
        for (j = 0; j < N; j++)
            printf("%4d ", x[i][j]);
        printf("\n");
    }
}
