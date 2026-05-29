#include <stdio.h>
#include "../include/lab4.h"
#define YES 1
#define NO 0
#define MAXLINE 1000

void process_line(char buffer[]);

void lab4_bas() {

char line[MAXLINE];
    int i;
    char c;

    // ввод строки
    i = 0;
    while (i < MAXLINE - 1 && (c = getchar()) != '\n' && c != EOF)
    {
        line[i] = c;
        i++;
    }
    line[i] = '\0';

    process_line(line);

    // вывод строки
    i = 0;
    while (line[i] != '\0')
    {
        putchar(line[i]);
        i++;
    }
    putchar('\n');

    return 0;
}

void process_line(char buffer[])
{
    char c;          // текущий символ
    int flag;        // признак слова (YES/NO)
    int after_comma; // индикатор того, что мы после запятой
    int skipping;    // индикатор того, что пропускаем слово
    int i;           // позиция текущего символа исходной строки
    int pos;         // позиция текущего символа результирующей строки

    // Буфер для результата (чтобы не портить исходную строку)
    char result[MAXLINE];

    // начальные присваивания (инициализация)
    flag = NO;
    after_comma = NO;
    skipping = NO;
    i = 0;
    pos = 0;

    // цикл чтения символов из строки
    while (buffer[i] != '\0')
    {
        c = buffer[i]; // взять текущий символ из буфера

        if (c == ' ' || c == '.' || c == ',' || c == '\n')
        {
            // найден разделитель
            if (flag == YES)
            {
                // это первый разделитель после слова
                flag = NO;
                // если мы пропускали слово, то прекращаем пропуск
                if (skipping == YES)
                {
                    skipping = NO;
                    after_comma = NO;
                }
            }

            // если это запятая
            if (c == ',')
            {
                after_comma = YES;
                skipping = YES;  // следующее слово будем пропускать
            }

            // копируем разделитель, если не пропускаем
            if (skipping == NO)
            {
                result[pos] = c;
                pos++;
            }
        }
        else
        {
            // найдена буква
            if (flag == NO)
            {
                flag = YES;
            }

            // копируем букву, если не пропускаем
            if (skipping == NO)
            {
                result[pos] = c;
                pos++;
            }
        }
        i++;
    }

    // ВАЖНО: закрываем результирующую строку нулём
    result[pos] = '\0';

    // Копируем результат обратно в буфер (чтобы main его увидел)
    i = 0;
    while (result[i] != '\0')
    {
        buffer[i] = result[i];
        i++;
    }
    buffer[i] = '\0';
}
