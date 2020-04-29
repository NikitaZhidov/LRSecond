/**
 * process_forward.c -- реализует обобщенную функцию обработки текста
 *
 * Copyright (c) 2017, Alexander Borodin <aborod@petrsu.ru>
 *
 * This code is licensed under a MIT-style license.
 */

#include "_text.h"
#include <string.h>

/**
 * Обрабатывает список, применяя заданную функцию к каждой строке
 * 
 * @param txt текст
 * @param process функция-обработчик
 * @returns none
 */
void m(text txt, int number_l, int number_p)
{   
    node *currentl = txt->begin;
    if (txt->length == 0){
        printf("%s\n", "No lines");
        return;
    }

    int i = 0;
    int countlines = txt->length;

    if (number_l > (countlines-1)){
        printf("Invalid values (Max line: %d)\n", countlines-1);
        currentl = txt->end;
    }
    else if (number_l < 0){
            printf("Invalid valuse (Min line: 0)\n");
            currentl = txt->begin;
    }
    else{
        while(i != number_l){
            currentl = currentl->next;
            i++;
        }
    }
    txt->cursor->line = currentl;

    if (number_p > (int)strlen(currentl->contents)-1){
        printf("Invalid values (Max position: %d)\n", (int)strlen(currentl->contents)-1);
        txt->cursor->position = strlen(currentl->contents)-1;
        return;
    }

    if (number_p < 0){
        printf("Invalid values (Min position: 0)\n");
        txt->cursor->position = 0;
        return;
    }


    txt->cursor->position = number_p;
}
