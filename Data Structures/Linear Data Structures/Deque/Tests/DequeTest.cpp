#include <gtest/gtest.h>
#include "../Deque.h"


TEST(DequeTest, DefaultConstructor) {
    Deque A;
    EXPECT_EQ(A.capacity(), INITIAL_CAPACITY);
    EXPECT_TRUE(A.empty());
}

TEST(DequeTest, ConstructorWithParameterCapacity) {
    Deque A(27);
    EXPECT_EQ(A.capacity(), 27);
    EXPECT_TRUE(A.empty());
}

TEST(DequeTest, CopyConstructor) {
    Deque A;

    for(size_t i=0; i < INITIAL_CAPACITY; i++) {
        A.push_back(i);
    }

    Deque B = A;

    EXPECT_TRUE(A == B);
}

TEST(DequeTest, CopyAssignmentOperator) {

    Deque A;

    for(size_t i=0; i < INITIAL_CAPACITY; i++) {
        A.push_back(i);
    }

    Deque B;
    B = A;

    EXPECT_TRUE(A == B);
}

TEST(DequeTest, Comparations) {
    Deque A,B;

    for(size_t i = 0; i < INITIAL_CAPACITY ; i++) {
        A.push_back(i);
        B.push_back(i);
    }

    EXPECT_TRUE(A == B);
    A.push_back(7);
    EXPECT_TRUE(A != B);
}

TEST(DequeTest, PushBackOneElement) {
    double value = 3.14;
    Deque A;
    A.push_back(value);

    EXPECT_DOUBLE_EQ(A[A.size()-1],value);
    EXPECT_DOUBLE_EQ(A[0],value);
    EXPECT_EQ(A.size(),1);
}

TEST(DequeTest, PushFrontOneElement) {
    double value = 3.14;
    Deque A;
    A.push_front(value);

    EXPECT_DOUBLE_EQ(A[0],value);
    EXPECT_DOUBLE_EQ(A[A.size()-1],value);
    EXPECT_EQ(A.size(),1);
}

TEST(DequeTest, PushBackMoreThanCapacityElements) {
    Deque A;
    for(size_t i = 0; i < 100000 ; i++) {
        A.push_back(i);
        EXPECT_DOUBLE_EQ(A[A.size()-1],i);
        EXPECT_DOUBLE_EQ(A[0],0);
        EXPECT_EQ(A.size(), i + 1);
    }
}

TEST(DequeTest, PushFrontMoreThanCapacityElements) {
    Deque A;
    for(size_t i = 0; i <  100000; i++) {
        A.push_front(i);
        EXPECT_DOUBLE_EQ(A[0],i);
        EXPECT_DOUBLE_EQ(A[A.size()-1],0);
        EXPECT_EQ(A.size(), i + 1);
    }
}

TEST(DequeTest, PopBack) {
    double values[2] = {3.14, 2.71};
    Deque A;
    A.push_back(values[0]);
    A.push_back(values[1]);
    A.pop_back();

    EXPECT_DOUBLE_EQ(A.back(),values[0]);
    EXPECT_EQ(A.size(), 1);
}

TEST(DequeTest, PopFront) {
    double values[2] = {3.14, 2.71};
    Deque A;
    A.push_front(values[0]);
    A.push_front(values[1]);
    A.pop_front();

    EXPECT_DOUBLE_EQ(A.front(),values[0]);
    EXPECT_EQ(A.size(), 1);
}

TEST(DequeTest, Clear) {
    Deque A;

    for(size_t i=0; i < INITIAL_CAPACITY; i++) {
        A.push_back(i);
    }

    A.clear();

    EXPECT_TRUE(A.empty());
    EXPECT_TRUE(A.data());

    for(size_t i=0; i < INITIAL_CAPACITY; i++) {
        A.push_back(i);
    }

    A.clear(true);

    EXPECT_TRUE(A.empty());
    EXPECT_EQ(A.capacity(),0);
    EXPECT_TRUE(!A.data());
}

TEST(DequeTest, ElementAt) {
    Deque A;
    EXPECT_THROW(A.at(0), std::out_of_range);
    EXPECT_THROW(A.at(-1), std::out_of_range);
    EXPECT_THROW(A.at(A.size()), std::out_of_range);
    EXPECT_THROW(A.back(), std::logic_error);
    EXPECT_THROW(A.front(), std::logic_error);

    for(size_t i=0; i < INITIAL_CAPACITY; i++) {
        A.push_back(i);
        EXPECT_DOUBLE_EQ(A.back(),i);
    }

    A.clear();

    for(size_t i=0; i < INITIAL_CAPACITY; i++) {
        A.push_front(i);
        EXPECT_DOUBLE_EQ(A.front(),i);
    }
}

TEST(DequeTest, Reserve) {
    Deque A;
    EXPECT_EQ(A.capacity(),INITIAL_CAPACITY);

    A.reserve(INITIAL_CAPACITY * 7);
    EXPECT_EQ(A.capacity(), INITIAL_CAPACITY * 7);
    EXPECT_TRUE(A.empty());
}