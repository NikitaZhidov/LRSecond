/**
 * editor.c -- строковый текстовый редактор
 * 
 * Copyright (c) 2017, Alexander Borodin <aborod@petrsu.ru>
 *
 * This code is licensed under a MIT-style license.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <errno.h>

#include "text/text.h"
#include "common.h"


#define MAXLINE 255

int main()
{
    char cmdline[MAXLINE + 1];
    char *cmd;
    char *arg;
    char *arg2;
    char *end;
    long int argint;
    long int argint2;
    
    /* Создаем объект для представления текста */
    text txt = create_text();

    /* Цикл обработки команд */
    while (1) {
        printf("ed > ");

        /* Получаем команду */

        if (!fgets(cmdline, MAXLINE, stdin))
            printf("Error\n");
	
        /* Извлекаем имя команды */
        if ((cmd = strtok(cmdline, " \n")) == NULL) {
            continue;
        }

        /* Распознаем поддерживаемую команду */
        
        /* Завершаем работу редактора */
        if (strcmp(cmd, "quit") == 0) {
            fprintf(stderr, "Bye!\n");
            break;
        }

        /* Загружаем содержимое файла, заданного параметром */
        if (strcmp(cmd, "load") == 0) {
            if ((arg = strtok(NULL, " \n")) == NULL) {
                fprintf(stderr, "Usage: load filename\n");
            } else {
                load(txt, arg);
            }
            continue;
        }

	if (strcmp(cmd, "save") == 0) {
            if ((arg = strtok(NULL, " \n")) == NULL) {
                fprintf(stderr, "Usage: save filename\n");
            } else {
                save(txt, arg);
            }
            continue;
        }

	if (strcmp(cmd, "m") == 0) {
	    
	    arg = strtok(NULL, " \n");
	    arg2 = strtok(NULL, " \n");
	    if(arg == NULL ){
		fprintf(stderr, "Usage: m [number_line] [number_position]\n");
		continue;
		}
		
	    argint = strtol(arg, &end, 10);
        if(argint == LONG_MAX || argint == LONG_MIN){
            fprintf(stderr, "Invalid values\n");
            continue;
	      }
        else if(errno == ERANGE){
            fprintf(stderr, "Invalid values\n");
            continue;
          }
		else {		
            if(arg2 == NULL ){
                fprintf(stderr, "Usage: m [number_line] [number_position]\n");
                continue;
            }
		argint2 = strtol(arg2, &end, 10);
        if(argint2 == LONG_MAX || argint == LONG_MIN){
                fprintf(stderr, "Invalid values\n");
           }
        else if(errno == ERANGE){
	 	    fprintf(stderr, "Invalid values\n");
        }
		else {
		    m(txt, argint, argint2);               	
        }
    }
            continue;
        }


        /* Выводим текст */
        if (strcmp(cmd, "show") == 0) {
            show(txt);
            continue;
        }
	
	if (strcmp(cmd, "mwbb") == 0) {
            mwbb(txt);
            continue;
	}

	if (strcmp(cmd, "showonempty") == 0) {
            showonempty(txt);
            continue;
        }
	
	if (strcmp(cmd, "rc") == 0) {
            rc(txt);
            continue;
        }
        
        /* Если команда не известна */
        fprintf(stderr, "Unknown command: %s\n", cmd);
    }

    return 0;
}
