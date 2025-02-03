#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "RandomGenerator.h"  // This header should declare RandomGenerator and ZephyrRandomGenerator

// Google Mock class for RandomGenerator.
class MockRandomGenerator : public RandomGenerator {
public:
    // Mocks the virtual function getRandomNumber.
    MOCK_METHOD(int, getRandomNumber, (uint32_t* value), (override));
};

// Test for proper random number generation using the mock.
// Expects getRandomNumber to set value to 42 and return 0.
TEST(RandomGeneratorTest, MockRandomNumberGeneration) {
    MockRandomGenerator mockRandomGen;
    uint32_t expectedValue = 42;
    EXPECT_CALL(mockRandomGen, getRandomNumber(testing::_))
         .WillOnce(testing::DoAll(testing::SetArgPointee<0>(expectedValue),
                         testing::Return(0)));
                         
    uint32_t value = 0;
    int ret = mockRandomGen.getRandomNumber(&value);
    EXPECT_EQ((int) 0, ret);
    EXPECT_EQ((uint32_t) 42, value);
}

// Test for proper division by a random number.
TEST(RandomGeneratorTest, DivideByRandomNumberFunction) {
    MockRandomGenerator mockRandomGen;
    uint32_t expectedValue = 21;
    EXPECT_CALL(mockRandomGen, getRandomNumber(testing::_))
         .WillOnce(testing::DoAll(testing::SetArgPointee<0>(expectedValue),
                         testing::Return(0)));
    
    // Assuming devideByRandomNumber() divides the input by the random number.
    int result = mockRandomGen.devideByRandomNumber(42);
    EXPECT_EQ((int) 2, result);
}

// TEST(RandomGeneratorTest, DivideByZeroError) {
//     MockRandomGenerator mockRandomGen;
//     uint32_t expectedValue = 0;
//     EXPECT_CALL(mockRandomGen, getRandomNumber(testing::_))
//          .WillOnce(testing::DoAll(testing::SetArgPointee<0>(expectedValue),
//                          testing::Return(0)));

//     int result = mockRandomGen.devideByRandomNumber(100);

//     // You will not be able to reach there!
//     // You must see a USAGE FAULT error due to Division by zero!
//     EXPECT_EQ((int) 0, result);
// }
