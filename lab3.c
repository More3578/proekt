#include <stdio.h>
#include "../include/lab3.h"


void lab3_bas() {

int c;
    int count = 0;
    int in_word = 0;
    char first_char = 0;
    char last_char = 0;
    int word_len = 0;
    printf("text:\n");
    while ((c = getchar()) != EOF){
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')){
            if (!in_word){
                in_word = 1;
                first_char = c;
                word_len = 1;}
            else{
                word_len++;}
            last_char = c;}
        else{
            if (in_word){
                in_word = 0;
                if (word_len > 0){
                    char first = (first_char >= 'A' && first_char <= 'Z') ?
                                first_char + ('a' - 'A') : first_char;
                    char last = (last_char >= 'A' && last_char <= 'Z') ?
                               last_char + ('a' - 'A') : last_char;
                            if (first == last){
                        count++;}}}}}
    printf("result: %d\n", count);
}
