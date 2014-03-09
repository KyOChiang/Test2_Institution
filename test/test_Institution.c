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

void test_isUniversityCollege_should_return_1_if_same_type_0_for_different_type() {
	// Setup institution type
	Institution institution[4] = {{.type = Unknown},{.type = University},
								  {.type = UniversityCollege}, {.type = College}};

	InstitutionType institutionType[4] = {Unknown,University,UniversityCollege,College};
	
	TEST_ASSERT_EQUAL(1, isUniversityCollege(&institution[0], &institutionType[0]));
	TEST_ASSERT_EQUAL(1, isUniversityCollege(&institution[1], &institutionType[1]));
	TEST_ASSERT_EQUAL(1, isUniversityCollege(&institution[2], &institutionType[2]));
	TEST_ASSERT_EQUAL(1, isUniversityCollege(&institution[3], &institutionType[3]));
	TEST_ASSERT_EQUAL(0, isUniversityCollege(&institution[0], &institutionType[3]));
	TEST_ASSERT_EQUAL(0, isUniversityCollege(&institution[1], &institutionType[2]));
	TEST_ASSERT_EQUAL(0, isUniversityCollege(&institution[2], &institutionType[1]));
	TEST_ASSERT_EQUAL(0, isUniversityCollege(&institution[3], &institutionType[0]));
}

void test_Institution_select_the_university_college_only() {
	Institution institution[4] = {{.type = Unknown},{.type = University},
								  {.type = UniversityCollege}, {.type = College}};

	LinkedList institutionList;
	LinkedList selectedInst;
	institutionList.head = &institution[0];
	institutionList.tail = &institution[3];
	InstitutionType instType = UniversityCollege;

	int compareTypeStatus;

	// Only Institution[2] match the type and will be push to stack
	// before the selectedInst generated.
	List_removeHead_ExpectAndReturn(&institutionList, &institution[0]);

	List_removeHead_ExpectAndReturn(&institutionList, &institution[1]);

	List_removeHead_ExpectAndReturn(&institutionList, &institution[2]);
	Stack_push_Expect(&stack, &institution[2]);

	List_removeHead_ExpectAndReturn(&institutionList, &institution[3]);

	List_removeHead_ExpectAndReturn(&institutionList, NULL);

	Stack_pop_ExpectAndReturn(&stack, &institution[2]);
	List_addTail_Expect(&selectedInst, &institution[2]);

	// Call SUT
	compareTypeStatus = Institution_select(&institutionList, &selectedInst,
											&instType, isUniversityCollege);

	TEST_ASSERT_EQUAL(1, compareTypeStatus);
}

void test_Institution_select_the_university_only() {
	Institution institution[4] = {{.type = Unknown},{.type = University},
								  {.type = UniversityCollege}, {.type = College}};

	LinkedList institutionList;
	LinkedList selectedInst;
	institutionList.head = &institution[0];
	institutionList.tail = &institution[3];
	InstitutionType instType = University;

	int compareTypeStatus;

	// Only Institution[1] match the type and will be push to stack
	// before the selectedInst generated.
	List_removeHead_ExpectAndReturn(&institutionList, &institution[0]);

	List_removeHead_ExpectAndReturn(&institutionList, &institution[1]);
	Stack_push_Expect(&stack, &institution[1]);

	List_removeHead_ExpectAndReturn(&institutionList, &institution[2]);

	List_removeHead_ExpectAndReturn(&institutionList, &institution[3]);

	List_removeHead_ExpectAndReturn(&institutionList, NULL);

	Stack_pop_ExpectAndReturn(&stack, &institution[1]);
	List_addTail_Expect(&selectedInst, &institution[1]);

	// Call SUT
	compareTypeStatus = Institution_select(&institutionList, &selectedInst,
											&instType, isUniversityCollege);

	TEST_ASSERT_EQUAL(1, compareTypeStatus);
}

void test_Institution_select_the_college_only() {
	Institution institution[4] = {{.type = Unknown},{.type = University},
								  {.type = UniversityCollege}, {.type = College}};

	LinkedList institutionList;
	LinkedList selectedInst;
	institutionList.head = &institution[0];
	institutionList.tail = &institution[3];
	InstitutionType instType = College;

	int compareTypeStatus;

	// Only Institution[3] match the type and will be push to stack
	// before the selectedInst generated.
	List_removeHead_ExpectAndReturn(&institutionList, &institution[0]);

	List_removeHead_ExpectAndReturn(&institutionList, &institution[1]);

	List_removeHead_ExpectAndReturn(&institutionList, &institution[2]);

	List_removeHead_ExpectAndReturn(&institutionList, &institution[3]);
	Stack_push_Expect(&stack, &institution[3]);

	List_removeHead_ExpectAndReturn(&institutionList, NULL);

	Stack_pop_ExpectAndReturn(&stack, &institution[3]);
	List_addTail_Expect(&selectedInst, &institution[3]);

	// Call SUT
	compareTypeStatus = Institution_select(&institutionList, &selectedInst,
											&instType, isUniversityCollege);

	TEST_ASSERT_EQUAL(1, compareTypeStatus);
}

void test_wasEstablishedBefore_should_get_1_if_the_institution_was_established_before_year_1980\
and_get_0_if_the_institution_was_established_after_year_1980() {
	Institution institution[6] = {{.yearEstablished = 1924},{.yearEstablished = 1938},
								  {.yearEstablished = 1952},{.yearEstablished = 1967},
								  {.yearEstablished = 1999},{.yearEstablished = 2014}};

	int specificYear = 1980;
	int compareStatus;

	compareStatus = wasEstablishedBefore(&institution[0], &specificYear);
	TEST_ASSERT_EQUAL(1, compareStatus);
	compareStatus = wasEstablishedBefore(&institution[1], &specificYear);
	TEST_ASSERT_EQUAL(1, compareStatus);
	compareStatus = wasEstablishedBefore(&institution[2], &specificYear);
	TEST_ASSERT_EQUAL(1, compareStatus);
	compareStatus = wasEstablishedBefore(&institution[3], &specificYear);
	TEST_ASSERT_EQUAL(1, compareStatus);
	compareStatus = wasEstablishedBefore(&institution[4], &specificYear);
	TEST_ASSERT_EQUAL(0, compareStatus);
	compareStatus = wasEstablishedBefore(&institution[5], &specificYear);
	TEST_ASSERT_EQUAL(0, compareStatus);
}

void test_wasEstablishedBefore_throw_an_exception_for_institution_established_after_year_2014() {
	Institution institution = {.yearEstablished = 2015};

	int specificYear = 1980;
	int compareStatus;

	CEXCEPTION_T ERR;

	Try {
	compareStatus = wasEstablishedBefore(&institution, &specificYear);
	} Catch(ERR) {
	TEST_ASSERT_EQUAL(ERROR_YEAR_AFTER_2014, ERR);
	}
	// TEST_ASSERT_EQUAL(0,compareStatus); Not testable because has no return value
}

void test_wasEstablishedBefore_not_throw_an_exception_for_institution_established_before_year_2014() {
	Institution institution = {.yearEstablished = 1967};

	int specificYear = 1980;
	int compareStatus;

	CEXCEPTION_T ERR;

	Try {
	compareStatus = wasEstablishedBefore(&institution, &specificYear);
	} Catch(ERR) {
	TEST_ASSERT_EQUAL(ERROR_YEAR_AFTER_2014, ERR);
	}
	TEST_ASSERT_EQUAL(1,compareStatus);
}

void test_Institution_select_and_obtain_institution_establish_before_year2014(){
	
	Institution institution[6] = {{.yearEstablished = 1924},{.yearEstablished = 1938},
								  {.yearEstablished = 1952},{.yearEstablished = 1967},
								  {.yearEstablished = 1999},{.yearEstablished = 2013}};

	int specificYear = 1980;
	int compareStatus;
	int numberOfSelectedInstitution;
	LinkedList institutionList;
	LinkedList selectedInst;
	
	CEXCEPTION_T ERR;
	//Expect only institution[n], where n = 0->3 will be selected
	List_removeHead_ExpectAndReturn(&institutionList, &institution[0]);
	Stack_push_Expect(&stack, &institution[0]);

	List_removeHead_ExpectAndReturn(&institutionList, &institution[1]);
	Stack_push_Expect(&stack, &institution[1]);

	List_removeHead_ExpectAndReturn(&institutionList, &institution[2]);
	Stack_push_Expect(&stack, &institution[2]);
	
	List_removeHead_ExpectAndReturn(&institutionList, &institution[3]);
	Stack_push_Expect(&stack, &institution[3]);
	
	List_removeHead_ExpectAndReturn(&institutionList, &institution[4]);
	
	List_removeHead_ExpectAndReturn(&institutionList, &institution[5]);
	
	List_removeHead_ExpectAndReturn(&institutionList, NULL);

	Stack_pop_ExpectAndReturn(&stack, &institution[3]);
	List_addTail_Expect(&selectedInst, &institution[3]);
	
	Stack_pop_ExpectAndReturn(&stack, &institution[2]);
	List_addTail_Expect(&selectedInst, &institution[2]);
	
	Stack_pop_ExpectAndReturn(&stack, &institution[1]);
	List_addTail_Expect(&selectedInst, &institution[1]);
	
	Stack_pop_ExpectAndReturn(&stack, &institution[0]);
	List_addTail_Expect(&selectedInst, &institution[0]);
	
	// Call SUT
	Try {
	numberOfSelectedInstitution = Institution_select(&institutionList, &selectedInst,
						                             &specificYear,wasEstablishedBefore);
	} Catch (ERR) {
	TEST_ASSERT_EQUAL(ERROR_YEAR_AFTER_2014, ERR);
	}
	TEST_ASSERT_EQUAL(4,numberOfSelectedInstitution);
	
}