/**
 * show.c -- реализует команду вывода хранимого текста на экран
 *
 * Copyright (c) 2017, Alexander Borodin <aborod@petrsu.ru>
 *
 * This code is licensed under a MIT-style license.
 */

#include <stdio.h>
#include <assert.h>
#include <string.h>
#include "common.h"
#include "text/text.h"

void showonempty_line(int index, char *contents, int cursor, void *data);

/**
 * Выводит содержимое указанного файла на экран
 */
void showonempty(text txt)
{
    FILE *f;

    char filename[] = "soEmptyLog.txt";

    /* Открываем файл для записи, контролируя ошибки */
    if ((f = fopen(filename, "w")) == NULL) {
        printf("The file %s cannot be saved \n", filename);
    }

    /* Применяем функцию show_line к каждой строке текста */
    process_forward(txt, showonempty_line, (void*)f);
    printf("\n");

    fclose(f);
}

/**
 * Выводит содержимое указанного файла на экран
 */
void showonempty_line(int index, char *contents, int cursor, void *data)
{
    /* Функция обработчик всегда получает существующую строку */
    assert(contents != NULL);
    
    /* Декларируем неиспользуемые параметры */
    UNUSED(index);

    FILE* f = (FILE*)data;

    int i = 0;
    int j = 0;
   
    /*Проверка на пустые строки*/
    while(contents[j] == ' ')
        j++;
    if (contents[j+1] == '\0'){
        return;
    }
    if (strlen(contents) < 2){
        return;
    }

    /* Выводим строку на экран */
    if (cursor != -1){       
	while(i != cursor){
        fprintf(f, "%c", contents[i]);
	    printf("%c", contents[i]);
	    i++;
	}
	printf("%c", '|');
	while(contents[i] != '\0'){
        fprintf(f, "%c", contents[i]);
	    printf("%c", contents[i]);
	    i++;
        }
    }
    else{
        fprintf(f, "%s", contents);
        printf("%s", contents);
    }
 
}
