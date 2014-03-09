#ifndef Institution_H
#define Institution_H
#include "LinkedList.h"
#include "Stack.h"
extern Stack stack; // Let testable file that include this header file\
					   to be able use the global variable declare in src

typedef enum {Unknown, University, UniversityCollege, College}InstitutionType;
typedef enum {NO_ERROR, ERROR_YEAR_AFTER_2014} ErrorYearMessage;

typedef struct Institution_t{
	char *name;
	char *address;
	unsigned long postcode;
	unsigned long int telephone;
	InstitutionType type;
	int yearEstablished;
}Institution;

int Institution_reverse(LinkedList *inputList, LinkedList *outputList);
int isUniversityCollege(void *elem1, void *type);
int Institution_select(LinkedList *inputList, LinkedList *outputList, \
void *criterion, int (*compare)(void *, void *));
int wasEstablishedBefore(void *elem, void *year);

#endif // Institution_H
