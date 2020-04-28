/**
 * process_forward.c -- реализует обобщенную функцию обработки текста
 *
 * Copyright (c) 2017, Alexander Borodin <aborod@petrsu.ru>
 *
 * This code is licensed under a MIT-style license.
 */

#include "_text.h"
#include <string.h>



void mwbb(text txt)
{
    if (txt == NULL || txt->length == 0) {
        fprintf(stderr, "There are already no any lines in the text!\n");
        return;
    } 

    int i = txt->cursor->position;
    int flag = 0;

    if (txt->cursor->line->contents[i] == '\0' || txt->cursor->line->contents[i] == ' '){
	   printf("%s", "Сursor at the beginning of a word or cannot be moved\n");
    }
    else{
	flag = 1;
	    while( i != -1 && txt->cursor->line->contents[i] != ' ')
	    i--;		
    }

    if (flag){
        i++;
        txt->cursor->position = i;
    }
}
