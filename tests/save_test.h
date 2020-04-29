#ifndef SAVE_H
#define SAVE_H

#include <gtest/gtest.h>

extern "C" {
#include "text/text.h"
#include "common.h"
}

TEST(saveTest, positive) {
    /* Объявление имени записанного файла и строки, которая будет в этом файле*/
    char save_filename[] = "save_test.txt";
    char line1[] = "first_line";

    char test_str[15] = " ";
    FILE* f;

    text test_text;

    /*Создание текста, помещение его в файл, сохранение файла*/
    test_text = create_text();
    append_line(test_text, line1);
    save(test_text, save_filename);

    /* "Вытаскивание" строки из файла */
    if ((f = fopen(save_filename, "r")) == NULL)
        FAIL();

    if (!fgets(test_str, 15, f))
        printf("Error\n");

    fclose(f);
    if (remove(save_filename))
        FAIL();

    ASSERT_STREQ(line1, test_str);

}

#endif // SAVE_H
