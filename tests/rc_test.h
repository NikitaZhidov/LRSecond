#ifndef RC_H
#define RC_H

#include <gtest/gtest.h>

extern "C" {
#include "text/text.h"
#include "text/_text.h"
#include "common.h"
}

TEST(rcTest, positive) {
    char line1[] = "this_line1";
    char line2[] = "this_line2";
    char line3[] = "this_line3";

    text test_text = create_text();
    append_line(test_text, line1);
    append_line(test_text, line2);
    append_line(test_text, line3);

    int test_length = test_text->length - 1;

    int i = 0;
    node* test_iter = test_text->begin;
    while (i != 2){
        test_iter = test_iter->next;
        i++;
    }

    m(test_text, 1, 0);

    rc(test_text);

    if (test_iter == test_text->cursor->line)
        SUCCEED();
    else
        FAIL();

    ASSERT_EQ((int)test_text->length, test_length);
}

TEST(rcTest, negative1) {
    char line1[] = "this_line1";
    char line2[] = "this_line2";
    char line3[] = "this_line3";

    text test_text = create_text();
    append_line(test_text, line1);
    append_line(test_text, line2);
    append_line(test_text, line3);

    int test_length = test_text->length - 1;

    int i = 0;
    node* test_iter = test_text->begin;
    while (i != 1){
        test_iter = test_iter->next;
        i++;
    }

    m(test_text, 2, 0);

    rc(test_text);

    if (test_iter == test_text->cursor->line)
        SUCCEED();
    else
        FAIL();

    ASSERT_EQ((int)test_text->length, test_length);
}

TEST(rcTest, negative2) {
    text test_text = create_text();

    int test_length = test_text->length;

    rc(test_text);

    if (NULL == test_text->cursor->line)
        SUCCEED();
    else
        FAIL();

    ASSERT_EQ((int)test_text->length, test_length);
}

TEST(rcTest, negative3) {
    char line1[] = "this_line1";
    text test_text = create_text();
    append_line(test_text, line1);

    int test_length = test_text->length - 1;

    rc(test_text);

    if (NULL == test_text->cursor->line)
        SUCCEED();
    else
        FAIL();

    ASSERT_EQ((int)test_text->length, test_length);
}

#endif // RC_H
