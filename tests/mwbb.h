#ifndef MWBB_H
#define MWBB_H

#include <gtest/gtest.h>

extern "C" {
#include "text/text.h"
#include "text/_text.h"
#include "common.h"
}

TEST(mwbbTest, positive) {          
     char line1[] = "this line1 line1";
     text test_text = create_text();
     append_line(test_text, line1);

     m(test_text, 0, 8);

     mwbb(test_text);

     ASSERT_EQ((int)test_text->cursor->position, 5);
}

TEST(mwbbTest, negative) {
     text test_text = create_text();

     mwbb(test_text);

     ASSERT_EQ((int)test_text->cursor->position, 0);
}

TEST(mwbbTest, negative2) {
     char line1[] = "this line1 line1";
     text test_text = create_text();
     append_line(test_text, line1);

     m(test_text, 0, 5);

     mwbb(test_text);

     ASSERT_EQ((int)test_text->cursor->position, 5);
}

TEST(mwbbTest, negative3) {
     char line1[] = "this line1 line1";
     text test_text = create_text();
     append_line(test_text, line1);

     m(test_text, 0, 4);

     mwbb(test_text);

     ASSERT_EQ((int)test_text->cursor->position, 4);
}

#endif // MWBB_H
