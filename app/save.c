/**
 * load.c -- функция загрузки текста из файла
 * 
 * Copyright (c) 2017, Alexander Borodin <aborod@petrsu.ru>
 *
 * This code is licensed under a MIT-style license.
 */

#include <stdio.h>
#include "common.h"
#include "text/text.h"
#include <assert.h>

static void save_line(int index, char *contents, int cursor, void *data);

/**
 * Загружает содержимое указанного файла
 */
void save(text txt, char *filename)
{
    FILE *f;
    
    /* Открываем файл для записи, контролируя ошибки */
    if ((f = fopen(filename, "w")) == NULL) {
        printf("The file %s cannot be saved\n", filename);
    }

    process_forward(txt, save_line, (void*)f);

    fclose(f);

}

static void save_line(int index, char *contents, int cursor, void *data)
{
    FILE* f = (FILE*)data;
    
    /* Функция обработчик всегда получает существующую строку */
    assert(contents != NULL);
    
    /* Декларируем неиспользуемые параметры */
    UNUSED(index);
    UNUSED(cursor);

    fprintf(f, "%s", contents);
}
