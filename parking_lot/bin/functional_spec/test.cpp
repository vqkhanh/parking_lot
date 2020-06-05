// test.cpp
#include "function_need_to_test.h"
#include <gtest/gtest.h>
 
TEST (write_lineTest, InvalidParam) { 
    EXPECT_EQ(-1, write_line(""));
}
 
TEST(write_lineTest, ValidParam) {
    EXPECT_EQ(0, write_line("a"));
    EXPECT_EQ(0, write_line("a b c"));
}
//
TEST(create_lotsTest, ValidParam) {
    EXPECT_EQ(0, create_lots("abc 3",4));
    EXPECT_EQ(0, create_lots("ab cd 5", 5));
}
//
TEST(parkingTest, ValidParam) {
    EXPECT_EQ(0, parking("abc cd 3",4));
    EXPECT_EQ(0, parking("ab cd 5", 3));
}
//
 
TEST(leaveTest, ValidParam) {
    EXPECT_EQ(0, leave("abc cd 3",4));
    EXPECT_EQ(0, leave("ab cd 5", 3));
}
//
TEST(parking_statusTest, ValidParam) {
    EXPECT_EQ(0, parking_status());
}
//
TEST (get_CMTest, InvalidParam) {
    EXPECT_EQ(-1, get_CM(""));
    EXPECT_EQ(-1, get_CM("abc"));
}
 
TEST(get_CMTest, ValidParam) {
    EXPECT_EQ(0, get_CM("park KA-01-HH-1234"));
}
//
TEST (read_filesTest, InvalidParam) {
    EXPECT_EQ(-1, read_files("aa","bb"));
    EXPECT_EQ(-1, read_files("abc",""));
}
 
int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
