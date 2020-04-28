#include "save_test.h"
#include "m_test.h"
#include "rc_test.h"
#include "mwbb.h"
#include "sEmpty_test.h"

#include <gtest/gtest.h>


int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
