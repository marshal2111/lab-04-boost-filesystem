// Copyright 2021 Your Name <your_email>

#include <stdexcept>

#include <gtest/gtest.h>

#include <broker.hpp>

TEST(Example, EmptyTest) {
    EXPECT_THROW(example(), std::runtime_error);
}
