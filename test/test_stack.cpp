#include <gtest.h>
#include "stack.h"
#include <iostream>

TEST(stack, can_create_stack) {
	ASSERT_NO_THROW(stack<int> a);
}

TEST(stack, can_create_stack_with_start_parametr) {
	ASSERT_NO_THROW(stack<int> a(0));
}

TEST(stack, can_return_size) {
	stack<int> a(5);

	EXPECT_EQ(1, a.sz());
}

TEST(stack, can_view_elem_on_the_top_with_not_zero_size) {
	stack<int> a(5);
	EXPECT_EQ(5, a.top());
}

TEST(stack, cant_view_elem_on_the_top_with_zero_size) {
	stack<int> a;
	ASSERT_ANY_THROW(a.top());
}

TEST(stack, can_push) {
	stack<int> a;

	ASSERT_NO_THROW(a.push(0));
	EXPECT_EQ(0, a.top());
}

TEST(stack, can_pop_stack_with_not_zero_size) {
	stack<int> a(10);
	a.push(5);

	ASSERT_NO_THROW(a.pop());
	EXPECT_EQ(10, a.top());
}

TEST(stack, cant_pop_stack_with_zero_size) {
	stack<int> a;

	ASSERT_ANY_THROW(a.pop());
}

TEST(stack, can_understand_that_stack_is_empty) {
	stack<int> a;

	EXPECT_EQ(true, a.empty());
}

TEST(stack, can_understand_that_stack_is_not_empty) {
	stack<int> a(10);

	EXPECT_EQ(false, a.empty());
}

TEST(stack, many_pushes_and_pops) {
	stack<int> a;
	laba3::vector<int> test_numbers(50);
	laba3::vector<int> loop_passes(100);
	for (int i = 0; i < 50; i++) {
		test_numbers[i] = i;
	}
	for (int i = 0; i < 100; i++) {
		loop_passes[i] = i % 50;
	}


	for (int i = 0; i < 100; i++) {
		a.push(test_numbers[loop_passes[i]]);
	}

	for (int i = 99; i > 0; i--) {
		EXPECT_EQ(test_numbers[loop_passes[i]], a.top());
		a.pop();
	}
	EXPECT_EQ(test_numbers[0], a.top());
}