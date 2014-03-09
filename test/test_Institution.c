#include "unity.h"
#include "Institution.h"
#include "mock_LinkedList.h"
#include "mock_Stack.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void test_Institution_reverse_must_reverse_2_Institution_order_in_list(){
	Institution institution[2];

	LinkedList originalList;
	LinkedList reversedList;
	int noOfReversed;
	originalList.head = &institution[0];
	originalList.tail = &institution[1];

	// Mocking
	List_removeHead_ExpectAndReturn(&originalList, &institution[0]);
	Stack_push_Expect(&stack, &institution[0]);

	List_removeHead_ExpectAndReturn(&originalList, &institution[1]);
	Stack_push_Expect(&stack, &institution[1]);

	List_removeHead_ExpectAndReturn(&originalList, NULL);

	Stack_pop_ExpectAndReturn(&stack, &institution[1]);
	List_addTail_Expect(&reversedList, &institution[1]);

	Stack_pop_ExpectAndReturn(&stack, &institution[0]);
	List_addTail_Expect(&reversedList, &institution[0]);

	// Call SUT
	noOfReversed = Institution_reverse(&originalList, &reversedList);

	TEST_ASSERT_EQUAL(2, noOfReversed);
}

void test_Institution_reverse_must_reverse_3_Institution_order_in_list(){
	Institution institution[3];

	LinkedList originalList;
	LinkedList reversedList;
	int noOfReversed;
	originalList.head = &institution[0];
	originalList.tail = &institution[2];

	// Mocking
	List_removeHead_ExpectAndReturn(&originalList, &institution[0]);
	Stack_push_Expect(&stack, &institution[0]);

	List_removeHead_ExpectAndReturn(&originalList, &institution[1]);
	Stack_push_Expect(&stack, &institution[1]);
	
	List_removeHead_ExpectAndReturn(&originalList, &institution[2]);
	Stack_push_Expect(&stack, &institution[2]);

	List_removeHead_ExpectAndReturn(&originalList, NULL);

	Stack_pop_ExpectAndReturn(&stack, &institution[2]);
	List_addTail_Expect(&reversedList, &institution[2]);
	
	Stack_pop_ExpectAndReturn(&stack, &institution[1]);
	List_addTail_Expect(&reversedList, &institution[1]);

	Stack_pop_ExpectAndReturn(&stack, &institution[0]);
	List_addTail_Expect(&reversedList, &institution[0]);

	// Call SUT
	noOfReversed = Institution_reverse(&originalList, &reversedList);

	TEST_ASSERT_EQUAL(3, noOfReversed);
}

void test_Institution_reverse_must_reverse_4_Institution_order_in_list(){
	Institution institution[4];

	LinkedList originalList;
	LinkedList reversedList;
	int noOfReversed;
	originalList.head = &institution[0];
	originalList.tail = &institution[3];

	// Mocking
	List_removeHead_ExpectAndReturn(&originalList, &institution[0]);
	Stack_push_Expect(&stack, &institution[0]);

	List_removeHead_ExpectAndReturn(&originalList, &institution[1]);
	Stack_push_Expect(&stack, &institution[1]);
	
	List_removeHead_ExpectAndReturn(&originalList, &institution[2]);
	Stack_push_Expect(&stack, &institution[2]);
	
	List_removeHead_ExpectAndReturn(&originalList, &institution[3]);
	Stack_push_Expect(&stack, &institution[3]);

	List_removeHead_ExpectAndReturn(&originalList, NULL);

	Stack_pop_ExpectAndReturn(&stack, &institution[3]);
	List_addTail_Expect(&reversedList, &institution[3]);
	
	Stack_pop_ExpectAndReturn(&stack, &institution[2]);
	List_addTail_Expect(&reversedList, &institution[2]);
	
	Stack_pop_ExpectAndReturn(&stack, &institution[1]);
	List_addTail_Expect(&reversedList, &institution[1]);

	Stack_pop_ExpectAndReturn(&stack, &institution[0]);
	List_addTail_Expect(&reversedList, &institution[0]);

	// Call SUT
	noOfReversed = Institution_reverse(&originalList, &reversedList);

	TEST_ASSERT_EQUAL(4, noOfReversed);
}


