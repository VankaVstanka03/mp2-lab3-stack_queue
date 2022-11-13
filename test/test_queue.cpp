#include <gtest.h>
#include "queue.h"

TEST(queue, can_create_queue) {
	ASSERT_NO_THROW(queue<int> a);
}

TEST(queue, can_create_queue_with_parametr) {
	ASSERT_NO_THROW(queue<int> a(5));
}

TEST(queue, can_push_correctly) {
	queue<int> a(10);

	EXPECT_EQ(10, a.front());
}

TEST(queue, can_pop) {
	queue<int> a(10);

	a.pop();

	EXPECT_EQ(0, a.sz_of_q());
	ASSERT_ANY_THROW(a.front());
}

TEST(queue, cant_pop_empty_queue) {
	queue<int> a;

	ASSERT_ANY_THROW(a.pop());
}

TEST(queue, can_understand_that_queue_is_empty) {
	queue<int> a;

	EXPECT_EQ(true, a.empty());
}

TEST(queue, can_understand_that_queue_is_not_empty) {
	queue<int> a(10);

	EXPECT_EQ(false, a.empty());
}

TEST(queue, do_resize_if_it_needed) {
	queue<int> a;

	a.push(1);
	a.push(2);
	a.push(3);
	a.push(4);
	a.push(5);

	ASSERT_NO_THROW(a.push(6));
	EXPECT_EQ(6, a.sz_of_q());
	EXPECT_EQ(10, a.sz_of_d());
}

TEST(queue, dont_do_resize_if_start_of_queue_is_empty) {
	queue<int> a;

	a.push(1);
	a.push(2);
	a.push(3);
	a.push(4);
	a.push(5);

	a.pop();
	a.pop();

	a.push(11);
	a.push(12);

	EXPECT_EQ(5, a.sz_of_d());
}

TEST(queue, dont_do_resize_if_pop_and_push_equal) {
	queue<int> a;
	size_t num_of_resize = 0;

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			a.push(j + i);
		}
		for (int k = 0; k < 5; k++) {
			a.pop();
		}
		if (a.sz_of_d() != 5) {
			num_of_resize++;
		}
	}
	EXPECT_EQ(0, num_of_resize);
}

TEST(queue, do_right_numbers_of_resizes_without_pops) {
	queue<int> a;
	//size_t num_of_resize = 0;

	for (int i = 0; i < 40; i++) {
		a.push(i);
		if (i == 5) {
			EXPECT_EQ(10, a.sz_of_d());
		}
		else if (i == 10) {
			EXPECT_EQ(20, a.sz_of_d());
		}
		else if (i == 20) {
			EXPECT_EQ(40, a.sz_of_d());
		}
	}
}

TEST(queue, combination_of_pushes_and_pops_without_resize) {
	queue<int> a;

	std::vector<int> test_numbers(20);
	for (int i = 0; i < 20; i++) {
		test_numbers[i] = 20 - i;
	}
	for (int i = 0; i < 20; i++) {
		a.push(test_numbers[i]);
		if (i == 4) {
			for (int j = 0; j < 5; j++) {
				a.pop();
			}
			EXPECT_EQ(5, a.sz_of_d());
		}
		else if (i == 9) {
			for (int j = 0; j < 5; j++) {
				a.pop();
			}
			EXPECT_EQ(5, a.sz_of_d());
		}
		else if (i == 14) {
			for (int j = 0; j < 5; j++) {
				a.pop();
			}
			EXPECT_EQ(5, a.sz_of_d());
		}
		else if (i == 19) {
			for (int j = 0; j < 5; j++) {
				a.pop();
			}
			EXPECT_EQ(5, a.sz_of_d());
		}
	}
	EXPECT_EQ(0, a.sz_of_q());
}

//TEST(queue, do_smth) {
//	queue<int> t;
//
//	t.push(0);
//	t.push(1);
//	t.push(2);
//	t.push(3);
//	t.push(4);
//
//	for (int i = 0; i < t.size_of_data; i++) {
//		std::cout << t.data[i] << " ";
//	}
//	std::cout << "\n";
//
//	t.pop();
//	t.pop();
//
//	for (int i = 0; i < t.size_of_data; i++) {
//		std::cout << t.data[i] << " ";
//	}
//	std::cout << "\n";
//
//	t.push(0);
//	t.push(1);
//
//	for (int i = 0; i < t.size_of_data; i++) {
//		std::cout << t.data[i] << " ";
//	}
//	std::cout << "\n";
//
//	t.pop();
//	t.pop();
//	t.pop();
//	t.pop();
//	t.pop();
//	
//	for (int i = 0; i < t.size_of_data; i++) {
//		std::cout << t.data[i] << " ";
//	}
//	std::cout << "\n";
//
//	t.push(0);
//	t.push(1);
//	t.push(2);
//	t.push(3);
//	t.push(4);
//
//	for (int i = 0; i < t.size_of_data; i++) {
//		std::cout << t.data[i] << " ";
//	}
//	std::cout << "\n";
//	
//}