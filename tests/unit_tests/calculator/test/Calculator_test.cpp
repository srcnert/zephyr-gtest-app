#include <gtest/gtest.h>
#include "Calculator.h"

// Test fixture for Calculator
class CalculatorTest : public ::testing::Test {
    protected:
        Calculator* calculator;

        // SetUp runs before each test.
        void SetUp() override {
            calculator = new Calculator();
        }

        // TearDown runs after each test.
        void TearDown() override {
            delete calculator;
        }
};

// Basic test: check if addition works
TEST_F(CalculatorTest, AddTest) {
    int result = calculator->add(2, 3);
    EXPECT_EQ(5, result); // Verify that 2 + 3 = 5
}

// Another test: check if multiplication works
TEST_F(CalculatorTest, MultiplyTest) {
    int result = calculator->multiply(2, 3);
    EXPECT_EQ(6, result); // Verify that 2 * 3 = 6
}

// To test failure scenarios, uncomment this:
// TEST_F(CalculatorTest, AddFailTest) {
//     int result = calculator->add(2, 3);
//     EXPECT_EQ(6, result); // This should fail and show how failure works in the test
// }