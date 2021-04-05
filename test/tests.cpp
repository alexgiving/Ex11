// Copyright 2021 GHA Test Team
#include <gtest/gtest.h>
#include <string>
#include <cstdlib>
#include "train.h"

TEST(Train, test_add_cage) {
    Train train;
    size_t N = 15;
    for (size_t i = 0; i < N; ++i) {
        Cage* cage = new Cage();
        train.addCage(cage);
    }
    size_t expected = N;
    size_t result = train.getLength();
    EXPECT_EQ(expected, result);
}

TEST(Train, test_) {
    size_t N = 15;
    Train train;
    for (size_t i = 0; i < N; ++i) {
        Cage* cage = new Cage();
        train.addCage(cage);
    }
    size_t expected = train.checkLength();
    size_t result = train.getLength();
    EXPECT_EQ(expected, result);
}

TEST(Train, test3) {
    Train train;
    size_t N = 15;
    for (size_t i = 0; i < N; ++i) {
        Cage* cage = new Cage();
        train.addCage(cage);
    }
    size_t f1 = train.getLength();
    size_t M = 10;
    for (size_t i = 0; i < M; ++i) {
        Cage* cage = new Cage();
        train.addCage(cage);
    }
    size_t f2 = train.getLength();
    size_t expected = N + M;
    size_t result = f2;
    EXPECT_EQ(expected, result);
}
