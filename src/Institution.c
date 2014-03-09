#include <stdio.h>
#include "Stack.h"
#include "LinkedList.h"
#include "Institution.h"
Stack stack; // Global variable to be extern in header.

/* 
 * Reverse the order of institution
 * Input:
 * 		inputList -> a list of institutions
 *		outputList -> list of institutions in reversed order
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

int isUniversityCollege(void *elem1, void *type) {
	// Cast between pointer type
	Institution *institution = (Institution *) elem1;
	InstitutionType *institutionType = (InstitutionType *) type;

	if(institution->type == *institutionType)
		return 1;
	else
		return 0;
}