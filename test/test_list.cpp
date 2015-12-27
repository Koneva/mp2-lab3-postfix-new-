#include "list.hpp"

#include <gtest.h>

TEST(List, can_create_list) {
    List<int>* list;
    ASSERT_NO_THROW(list = new List<int>);
}

TEST(List, can_get_pointer_on_first_node) {
    List<int>* list = new List<int>;
    ASSERT_NO_THROW(list -> GetFirst());
}

TEST(List, created_list_is_empty) {
    List<int>* list = new List<int>;
    EXPECT_EQ(0, list -> GetFirst());
}

TEST(List, can_push_key) {
    List<int>* list = new List<int>;
    ASSERT_NO_THROW( list -> PushStart(2));
}

TEST(List, push_key) {
    List<int>* list = new List<int>;
    list -> PushStart(2);
    list -> PushStart(3);
    EXPECT_EQ(3, list -> GetFirst() -> key);
}

TEST(List, compare_non_equal_lists_return_false) {
    List<int>* list = new List<int>;
    List<int>* list1 = new List<int>;

    list -> PushStart(2);
    list1 -> PushStart(1);
    list -> PushStart(3);
    list1 -> PushStart(3);
    EXPECT_NE(list1, list);
}

TEST(List, can_copy_list) {
    List<int>* list = new List<int>;
    list -> PushStart(3);
    list -> PushStart(4);
    ASSERT_NO_THROW(List<int>* list1 = new List<int>(*list));
}

TEST(List, can_find_key) {
    List<int>* list = new List<int>;
    list -> PushStart(3);
    list -> PushStart(4);
    ASSERT_NO_THROW(list -> Search(3));
}

TEST(List, find_return_pNode) {
    List<int>* list = new List<int>;
    list -> PushStart(3);
    list -> PushStart(4);
    EXPECT_EQ(list -> GetFirst() -> Next, list -> Search(3));
}

TEST(List, throws_when_key_was_not_found) {
    List<int>* list = new List<int>;
    list -> PushStart(3);
    list -> PushStart(4);
    ASSERT_ANY_THROW(list -> Search(5));
}

TEST(List, can_push_key_after_findkey) {
    List<int>* list = new List<int>;
    list -> PushStart(3);
    list -> PushStart(4);
	Node<int> *elem = new Node<int>;
	elem -> key = 5;
    ASSERT_NO_THROW(list -> PushAfter(4, elem));
}

TEST(List, throws_when_findKey_does_not_exist_PA) {
    List<int>* list = new List<int>;
    list -> PushStart(3);
    list -> PushStart(4);
	Node<int> *elem = new Node<int>;
	elem -> key = 5;
    ASSERT_ANY_THROW(list -> PushAfter(7, elem));
}

TEST(List, can_push_key_at_the_end_of_list) {
    List<int>* list = new List<int>;
    list -> PushStart(3);
    list -> PushStart(4);
    ASSERT_NO_THROW(list -> PushEnd(5));
}

TEST(List, pushEnd_works_properly) {
    List<int>* list = new List<int>;
    list -> PushStart(3);
    list -> PushStart(4);
    list -> PushEnd(5);
    List<int>* list1 = new List<int>;
    list1 -> PushStart(5);
    list1 -> PushStart(3);
    list1 -> PushStart(4);
    EXPECT_EQ(*list1, *list);
}

TEST(List, can_remove_node_by_key) {
    List<int>* list = new List<int>;
    list -> PushStart(3);
    list -> PushStart(4);
    ASSERT_NO_THROW(list -> Remove(3));
}

TEST(List, remove_works_properly) {
    List<int>* list = new List<int>;
    list -> PushStart(3);
    list -> PushStart(5);
    list -> PushStart(4);
    list -> Remove(5);
    List<int>* list1 = new List<int>;
    list1 -> PushStart(3);
    list1 -> PushStart(4);
    EXPECT_EQ(*list1, *list);
}

TEST(List, throws_when_findKey_does_not_exist_RM) {
    List<int>* list = new List<int>;
    list -> PushStart(3);
    list -> PushStart(4);
    ASSERT_ANY_THROW(list -> Remove(7));
}


TEST(List, pushBefore_works_properly) {
    List<int>* list = new List<int>;
    list -> PushStart(3);
    list -> PushStart(4);
    list -> PushStart(2);
	Node<int> *elem = new Node<int>;
	elem -> key = 5;
    list -> PushBefore(3, elem);
    List<int>* list1 = new List<int>;
    list1 -> PushStart(3);
    list1 -> PushStart(5);
    list1 -> PushStart(4);
    list1 -> PushStart(2);
    list -> Print();
    list1 -> Print();
    EXPECT_EQ(*list1, *list);
}

TEST(List, throws_when_findKey_does_not_exist_PB) {
    List<int>* list = new List<int>;
    list -> PushStart(3);
    list -> PushStart(4);
	Node<int> *elem = new Node<int>;
	elem -> key = 5;
    ASSERT_ANY_THROW(list -> PushBefore(7, elem));
}

TEST(List, pushAfter_END_works_properly) {
    List<int>* list = new List<int>;
    list -> PushStart(3);
    list -> PushStart(4);
	Node<int> *elem = new Node<int>;
	elem -> key = 5;
    list -> PushAfter(3, elem);
    List<int>* list1 = new List<int>;
    list1 -> PushStart(5);
    list1 -> PushStart(3);
    list1 -> PushStart(4);
    EXPECT_EQ(*list1, *list);
}

TEST(List, remove_START_works_properly) {
    List<int>* list = new List<int>;
    list -> PushStart(3);
    list -> PushStart(4);
    list -> PushStart(5);
    list -> Remove(5);
    List<int>* list1 = new List<int>;
    list1 -> PushStart(3);
    list1 -> PushStart(4);
    EXPECT_EQ(*list1, *list);
}

TEST(List, remove_END_works_properly) {
    List<int>* list = new List<int>;
    list -> PushStart(3);
    list -> PushStart(5);
    list -> PushStart(4);
    list -> Remove(3);
    List<int>* list1 = new List<int>;
    list1 -> PushStart(5);
    list1 -> PushStart(4);
    EXPECT_EQ(*list1, *list);
}