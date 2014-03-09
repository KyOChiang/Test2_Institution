#include <stdio.h>
#include "Stack.h"
#include "LinkedList.h"
#include "Institution.h"
Stack stack; // Global variable to be extern in header.

/* 
 * Reverse the order of institution
 * Input:
 * 		inputList	a list of institutions
 *		outputList	list of institutions in reversed order
 * Return:
 *		the number of institutions reversed
 */
int Institution_reverse(LinkedList *inputList, LinkedList *outputList){
	
	Institution *storeList; // Temporary storage for inputList and outputList
	int noOfReversed = 0;
	int i;

	if(inputList->head == NULL) {
		return 0;
	}
	else{
		for(;(storeList = (Institution *)List_removeHead(inputList)) != NULL;noOfReversed++){
			Stack_push(&stack, storeList); // Remove the first institution from list and push into first stack
		}

		for(i = 0; i < noOfReversed; i++) { // Remove the last institution from stack and put into first list
			storeList = Stack_pop(&stack);
			List_addTail(outputList, storeList);
		}
	}
	return noOfReversed;
}

/* Compare if institutions are the same type
 * Input:
 *		elem1	is a pointer to institution
 *		type	is a pointer to UniversityCollege
 * Return:
 *		1	Institution type match with expected type
 *		0	if not the same type
 */
int isUniversityCollege(void *elem1, void *type) {
	// Cast between pointer type
	Institution *institution = (Institution *) elem1;
	InstitutionType *institutionType = (InstitutionType *) type;

	if(institution->type == *institutionType)
		return 1;
	else
		return 0;
}

/* Compare and get the UniversityCollegeType
 *	Input:
 *		inputList	is a list of institutions
 *		outputList	is a output list of selected institutions
 *		criterion	is a pointer to the criterion for selection
 * Return:
 *		The number of UniversityCollege Type institution selected 
 */
int Institution_select(LinkedList *inputList, LinkedList *outputList,
						void *criterion, int (*compare)(void *, void *)){
	void *storeList;
	int noOfInstitutionSelected = 0;
	int i;
	
	if(inputList->head == NULL) {
		return 0;
	}
	else{
		for(;(storeList = (Institution *)List_removeHead(inputList)) != NULL;){
			if(compare(storeList, criterion)) {
			Stack_push(&stack, storeList);
			noOfInstitutionSelected++; // Only pushed the matching institutions into the stack
			}
		}

		for(i = 0; i < noOfInstitutionSelected; i++) { // Remove the last institution from stack and put into first list
			storeList = Stack_pop(&stack);
			List_addTail(outputList, storeList);
		}
	}
	return noOfInstitutionSelected;
}