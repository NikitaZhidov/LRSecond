#ifndef SOE_H
#define SOE_H

#include <gtest/gtest.h>

extern "C" {
#include "text/text.h"
#include "text/_text.h"
#include "common.h"
}

TEST(soEmtptyTest, positive) {
    char line1[] = "this_line1\n";
    char line2[] = "  ";
    char line3[] = "this_line3";

    char out_line[] = "this_line1\nthis_line3";
    char out_line_test[25];

    FILE* f;
    int i = 0;
    char sym;

    text test_text = create_text();
    append_line(test_text, line1);
    append_line(test_text, line2);
    append_line(test_text, line3);

    showonempty(test_text);

    if ( (f = fopen("soEmptyLog.txt", "r")) == NULL)
        FAIL();

    while( (sym = fgetc(f)) != EOF ){
        out_line_test[i] = sym;
        i++;
    }

    fclose(f);

    remove("soEmptyLog.txt");

    ASSERT_STREQ(out_line, out_line_test);
}

TEST(soEmtptyTest, negative1) {
    char out_line[] = "";
    char out_line_test[25] = "";

    FILE* f;
    int i = 0;
    char sym;

    text test_text = create_text();

    showonempty(test_text);

    if ( (f = fopen("soEmptyLog.txt", "r")) == NULL)
        FAIL();

    while( (sym = fgetc(f)) != EOF ){
        out_line_test[i] = sym;
        i++;
    }

    fclose(f);

    remove("soEmptyLog.txt");

    ASSERT_STREQ(out_line, out_line_test);
}

TEST(soEmtptyTest, negative2) {
    char line1[] = "  ";
    char line2[] = "  ";
    char line3[] = "  ";

    char out_line[] = "";
    char out_line_test[25] = "";

    FILE* f;
    int i = 0;
    char sym;

    text test_text = create_text();
    append_line(test_text, line1);
    append_line(test_text, line2);
    append_line(test_text, line3);

    showonempty(test_text);

    if ( (f = fopen("soEmptyLog.txt", "r")) == NULL)
        FAIL();

    while( (sym = fgetc(f)) != EOF ){
        out_line_test[i] = sym;
        i++;
    }

    fclose(f);

    remove("soEmptyLog.txt");

    ASSERT_STREQ(out_line, out_line_test);
}


#endif // SOE_H
