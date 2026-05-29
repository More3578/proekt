#include <stdio.h>
#define N 10
#include "../include/lab5.h"


void lab5_bas() {
    int x[N];
    int i;
    int is_arithmetic = 1;  // флаг: 1 - прогрессия, 0 — не прогрессия
    int diff;               // разность прогрессии

    // ввод массива
    printf(" \n", N);
    for (i = 0; i < N; i++) {
        if (scanf("%d", &x[i]) != 1) {
            printf("error\n");
            return 1;
        }
    }

    // вычисление разности прогрессии (разность между 1‑м и 0‑м элементами)
    diff = x[1] - x[0];

    // проверка, что все последующие разности равны diff
    for (i = 2; i < N; i++) {
        if (x[i] - x[i - 1] != diff) {
            is_arithmetic = 0;  // если разность не совпадает, прогрессии нет
            break;  // прерываем цикл — дальнейшая проверка не нужна
        }
    }

    // вывод результата
    if (is_arithmetic)
        printf("is progressia\n");
    else
        printf("is not progressia\n");
}
