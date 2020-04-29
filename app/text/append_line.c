/**
 * append_line.c -- функции для добавления строк
 * 
 * Copyright (c) 2017, Alexander Borodin <aborod@petrsu.ru>
 *
 * This code is licensed under a MIT-style license.
 */

#include "_text.h"

/**
 * Выделяет память под один элемент списка
 */
static node *create_node(const char *contents);


/**
 * Добавляет одну строку к тексту
 * @param txt текст
 * @param contents новая строка
 * @returns none
 */
void append_line(text txt, const char *contents)
{
    /* Если список пуст, создаем первый элемент */
    if (txt->length == 0) {
        txt->begin = txt->end = create_node(contents);
        txt->length = 1;
    /* иначе добавляем элемент в конец списка */
    } else {
        txt->end->next = create_node(contents);
        txt->end->next->previous = txt->end;
        txt->end = txt->end->next;        
        txt->length++;         
    }
    
    /* Устанавливаем курсор в конец добавленной строки */
    txt->cursor->line = txt->end;
    txt->cursor->position = strlen(txt->end->contents);
}


/*
 * Выделяет память под один элемент списка
 */
static node *create_node(const char *contents)
{  
    assert(contents != NULL);
    node* NullNode = NULL;
    node *nd;

    if ((nd = (node *) malloc(sizeof(node))) == NULL) {
        printf("Not enough memory!\n");
        return NullNode;
    }
    
    if (strlen(contents) > MAXLINE) {
        printf("Not enough memory!\n");
        return NullNode;
    }    

    strncpy(nd->contents, contents, MAXLINE);
    nd->contents[MAXLINE] = '\0';    
    nd->previous = NULL;
    nd->next = NULL;   
    
    return nd;
}
