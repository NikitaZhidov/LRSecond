/**
 * append_line.c -- функции для добавления строк
 * 
 * Copyright (c) 2017, Alexander Borodin <aborod@petrsu.ru>
 *
 * This code is licensed under a MIT-style license.
 */

#include "_text.h"


void rc(text txt)
{
    txt->cursor->position = 0;
    node *prev;
    node *nextl;
    int flag = 0;

    if (txt->length == 0) {
        printf("%s\n", "No lines");     
        return;
    }	

    if (txt->length == 1){
        free(txt->cursor->line);
        txt->cursor->line = NULL;
        txt->length--;
        return;
    }

    prev = txt->cursor->line->previous;
    nextl = txt->cursor->line->next;
    if (prev != NULL){
        prev->next = txt->cursor->line->next;
        flag = 1;
    }
    if (nextl != NULL){
        nextl->previous = txt->cursor->line->previous;
        flag = 2;
    }
    
    txt->cursor->position = 0;
    free(txt->cursor->line);

    if (flag == 1)
        txt->cursor->line = prev;
    else if (flag == 2)
        txt->cursor->line = nextl;

    txt->length--;
}




