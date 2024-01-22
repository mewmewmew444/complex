#include <gtest/gtest.h>
#include "complex.h"
#include "complex.cpp"

TEST(ComplexTests, constructor) {

    complex_number num(1.4,2.7);

    EXPECT_DOUBLE_EQ(num.get_real(), 1.4);
    EXPECT_DOUBLE_EQ(num.get_im(),2.7);
}

TEST(ComplexTests, get_real) {

    complex_number num(4,7);

    EXPECT_EQ(num.get_real(), 4);
}

TEST(ComplexTests, get_im) {

    complex_number num(29,404);

    EXPECT_EQ(num.get_im(), 404);
}

TEST(ComplexTests, set_real) {

    complex_number num(-8429.23, 948);

    num.set_real(98298.2);

    EXPECT_FLOAT_EQ(num.get_real(), 98298.2);
}

TEST(ComplexTests, set_im) {

    complex_number num(-930, 1);

    num.set_im(2983.0);

    EXPECT_FLOAT_EQ(num.get_im(), 2983.0);
}

TEST(ComplexTests, sum_of_two) {

    complex_number num(-930, 1);
    complex_number num1(930, -1);

    complex_number sum = num + num1;

    EXPECT_EQ(sum.get_real(), 0);
    EXPECT_EQ(sum.get_im(), 0);
}

TEST(ComplexTests, raznost) {

    complex_number num(21, 1);
    complex_number num1(-3, 11);

    complex_number razn = num - num1;

    EXPECT_EQ(razn.get_real(), 24);
    EXPECT_EQ(razn.get_im(), -10);
}

TEST(ComplexTests, proizvedenie) {

    complex_number num(2, 1);
    complex_number num1(8, -1);

    complex_number pro = num * num1;

    EXPECT_EQ(pro.get_real(), 17);
    EXPECT_EQ(pro.get_im(), 6);
}

TEST(ComplexTests, delenie) {

    complex_number num(5, 2);
    complex_number num1(7, 1);
    complex_number num2(0, 0);

    complex_number del = num / num1;

    EXPECT_DOUBLE_EQ(del.get_real(), 0.74);
    EXPECT_DOUBLE_EQ(del.get_im(),0.18);
    EXPECT_THROW(num / num2, std::runtime_error);
}

TEST(ComplexTests, uvelichenie) {

    complex_number num(-930, 1);
    complex_number num1(930, -1);

    num += num1;

    EXPECT_EQ(num.get_real(), 0);
    EXPECT_EQ(num.get_im(), 0);
}

TEST(ComplexTests, umenshenie) {

    complex_number num(21, 1);
    complex_number num1(-3, 11);

    num -= num1;

    EXPECT_EQ(num.get_real(), 24);
    EXPECT_EQ(num.get_im(), -10);
}

TEST(ComplexTests, priumnojenie) {

    complex_number num(2, 1);
    complex_number num1(8, -1);

    num *= num1;

    EXPECT_EQ(num.get_real(), 17);
    EXPECT_EQ(num.get_im(), 6);
}

TEST(ComplexTests, delna) {

    complex_number num(5, 2);
    complex_number num1(7, 1);
    complex_number num2(0, 0);

    num /= num1;

    EXPECT_DOUBLE_EQ(num.get_real(), 0.74);
    EXPECT_DOUBLE_EQ(num.get_im(),0.18);
    EXPECT_THROW(num / num2, std::runtime_error);
}

TEST(ComplexTests, sravnenie) {

    complex_number num(-1, 999);
    complex_number num1(-1, 999);
    complex_number num2(9, -3);

    EXPECT_TRUE(num == num1);
    EXPECT_FALSE(num == num2);
}

TEST(ComplexTests, sravnenieWithDouble) {
    complex_number num(-1.0, 0.0);
    complex_number num1(-1, 999);
    double a = -1.0;
    double b = -987789.0;

    EXPECT_TRUE(num == a);
    EXPECT_FALSE(num == b);
    EXPECT_FALSE(num1 == b);
}

TEST(ComplexTests, abs) {

    complex_number num(3, 4);

    double absolut = num.Abs();

    EXPECT_EQ(absolut, 5);
}

TEST(ComplexNumTestSuite, pow) {

    complex_number num(-3, 2);

    complex_number otv = num.Pow(3);

    EXPECT_DOUBLE_EQ(otv.get_real(), 9.0);
    EXPECT_DOUBLE_EQ(otv.get_im(), 46.0);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}