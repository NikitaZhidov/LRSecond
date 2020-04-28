#ifndef M_H
#define M_H

#include <gtest/gtest.h>

extern "C" {
#include "text/text.h"
#include "text/_text.h"
#include "common.h"
}

TEST(mTest, positive) {          
     const int test_line = 2;
     const int test_pos = 6;

     int i = 0;

     char line1[] = "this_line1";
     char line2[] = "this_line2";
     char line3[] = "this_line3";

     text test_text = create_text();
     append_line(test_text, line1);
     append_line(test_text, line2);
     append_line(test_text, line3);

     m(test_text, test_line, test_pos);

     auto test_line_iter = test_text->begin;
     while( ++i <= test_line)
         test_line_iter = test_line_iter->next;


     ASSERT_EQ(test_text->cursor->position, test_pos);
     ASSERT_STREQ(test_text->cursor->line->contents, test_line_iter->contents);
}

TEST(mTest, negative1){
    char line1[] = "this_line1";
    char line2[] = "this_line2";
    char line3[] = "this_line3";

    text test_text = create_text();
    append_line(test_text, line1);
    append_line(test_text, line2);
    append_line(test_text, line3);

    m(test_text, 100, 6);

    auto last_line = test_text->end;

    if (test_text->cursor->line == last_line)
        SUCCEED();
    else
        FAIL();

    }

TEST(mTest, negative2){
    char line1[] = "this_line1";
    char line2[] = "this_line2";
    char line3[] = "this_line3";

    text test_text = create_text();
    append_line(test_text, line1);
    append_line(test_text, line2);
    append_line(test_text, line3);

    auto crsr_line = test_text->begin;

    m(test_text, -10, 6);

    if (test_text->cursor->line == crsr_line)
        SUCCEED();
    else
        FAIL();

    }

TEST(mTest, negative3){
    char line1[] = "this_line1";
    char line2[] = "this_line2";
    char line3[] = "this_line3";

    text test_text = create_text();
    append_line(test_text, line1);
    append_line(test_text, line2);
    append_line(test_text, line3);

    m(test_text, 0, 100);

    int last_position = strlen(test_text->begin->contents) - 1;

    ASSERT_EQ(last_position, test_text->cursor->position);
}

TEST(mTest, negative4){
    char line1[] = "this_line1";
    char line2[] = "this_line2";
    char line3[] = "this_line3";

    text test_text = create_text();
    append_line(test_text, line1);
    append_line(test_text, line2);
    append_line(test_text, line3);

    m(test_text, 100, 100);

    int last_position = strlen(test_text->begin->contents) - 1;
    auto last_line = test_text->end;

    ASSERT_EQ(last_position, test_text->cursor->position);

    if (test_text->cursor->line == last_line)
        SUCCEED();
    else
        FAIL();
}

TEST(mTest, negative5){
    text test_text = create_text();
    m(test_text, 100, 100);

    if (test_text->cursor->line == NULL)
        SUCCEED();
    else
        FAIL();

    ASSERT_EQ(test_text->cursor->position, 0);
}

#endif // M_H
