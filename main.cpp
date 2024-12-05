#include <gtest/gtest.h>
#include <bitset>
#include <string>
#include <stdexcept>

int hamming_distance(const std::string& str1, const std::string& str2) {
    if (str1.size() != str2.size()) {
        throw std::invalid_argument("Strings must be of equal length.");
    }

    int distance = 0;
    for (size_t i = 0; i < str1.size(); i++) {
        distance += std::bitset<8>(str1[i] ^ str2[i]).count();
    }
    return distance;
}

TEST(HammingDistanceTest, EqualStrings) {
    EXPECT_EQ(hamming_distance("this is a test", "wokka wokka!!!"), 37);
}

TEST(HammingDistanceTest, IdenticalStrings) {
    EXPECT_EQ(hamming_distance("hello", "hello"), 0);
}

TEST(HammingDistanceTest, DifferentStrings) {
    EXPECT_EQ(hamming_distance("10101", "10011"), 3);
}

TEST(HammingDistanceTest, ThrowsOnDifferentLengths) {
    EXPECT_THROW(hamming_distance("short", "longer string"), std::invalid_argument);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

