/************************************************************************
*file: argz.c
*synopsis: The argz functions use malloc/realloc to allocate/grow argz vectors, and so any argz
* vector creating using these functions may be freed by using free; conversely, any argz
* function that may grow a string expects that string to have been allocated using malloc
* (those argz functions that only examine their arguments or modify them in place will work
* on any sort of memory). All argz functions that do memory allocation have a return type
* of error_t, and return 0 for success, and ENOMEM if an allocation error occurs.
* These functions are declared in the include file "argz.h".
*related files: "argz.h"
*author: MarIO
*written: 10/09/2017
*last modified: 03/10/2017
************************************************************************/

//#include "stdafx.h"
#include "argz.h"

/*
The argz_create_sep function converts the null-terminated string string into an
argz vector (returned in argz and argz len) by splitting it into elements at every
occurrence of the character sep.
*/

error_t argz_create_sep(const char *string, int sep, char **argz, size_t *argz_len) {
	size_t i = 0; char *pt = NULL;
	if ((NULL != string) && (0 != *argz_len) && (NULL == *argz)) {
		if (NULL == (*argz = malloc((*argz_len + 1) * sizeof(char)))) {
			return ERROR;
		}
		else {
			if (NULL == (pt=memmove(*argz, string, *argz_len + 1))) {
				return ERROR;
			}
			while (NULL != (pt = strrchr(*argz, sep))) {
				 *pt = '\0';
			} 
			return OK;
		}	
	}
	else {
		return ERROR;
	}
}

//Returns the number of elements in the argz vector.
int argz_count(const char *argz, size_t arg_len) {
	size_t i = 0;
	int counter = 0;
	if ((NULL != argz) && (0 != arg_len)) {
		for (i = 0; i < arg_len + 1; i++) {
			if ('\0' == argz[i]) {
				counter++;
			}
		}
		return counter;
	}
	else {
		return -1;  /* means the pointer was empty or the length of pointer is 0 */
	}
}

//The argz_add function adds the string str to the end of the argz vector // *argz, and updates *argz and *argz_len accordingly.
error_t argz_add(char **argz, size_t *argz_len, const char *str) {
	size_t i = *argz_len;
	char *buff = NULL;
	if ((NULL != *argz) && (NULL != str) && (0 != *argz_len)) {
		if (NULL == (buff = malloc((*argz_len + 1) * sizeof(char)))) {
			return ERROR;
		}
		else {
			if (NULL == memmove(buff, *argz, *argz_len + 1)) {
				free(buff);
				return ERROR;
			}
			else{
				*argz_len += strlen(str);
				if (NULL == (*argz = realloc(*argz, *argz_len + 2))) {
					free(buff);
					return ERROR;
				}
				else {
					if (NULL == memmove(*argz, buff, i + 1)) {
						free(buff);
						return ERROR;
					}
					else {
						free(buff);
					}
					if (NULL == memmove(*argz + i + 1, str, strlen(str) + 1)) {
						return ERROR;
					}
					return OK;
				}
			}
		}
	}
	else {
		return ERROR;
	}
}

/*If entry points to the beginning of one of the elements in the argz vector *argz, the argz_delete function will remove this entry and reallocate *argz, modifying *argz and *argz_len accordingly. Note that as destructive argz functions usually reallocate their argz argument, pointers into argz vectors such as entry will then become invalid.
*/
error_t argz_delete(char **argz, size_t *argz_len, char *entry) {
	int  j = 0;
	char *buff = NULL, *pt = *argz, *pt1 = NULL;
	if ((NULL != *argz) && (0 != *argz_len)) {
		if (NULL == (buff = malloc((*argz_len + 1) * sizeof(char)))) {
			return ERROR;
		}
		else {
			while (pt < *argz + *argz_len) {
				if (strcmp(pt, entry) != 0) {
					if (NULL == (pt1 = memmove(buff + j, pt, strlen(pt) + 1))) {
						return ERROR;
					}
					j += strlen(pt) + 1;
				}
				pt += strlen(pt) + 1;
			}
			*argz_len = j;
			if (NULL == (*argz = realloc(*argz, *argz_len + 1))) {
				free(buff);
				return ERROR;
			}
			else {
				if (NULL == (pt1 = memmove(*argz, buff, *argz_len + 1))) {
					free(buff);
					return ERROR;
				}
				else {
					free(buff);
					return OK;
				}
			}
		}
	}
	else {
		return ERROR;
	}
}

/*
The argz_insert function inserts the string entry into the argz vector *argz at a point just before the existing element pointed to by before, reallocating *argz and updating *argz and *argz_len. If before is 0, entry is added to the end instead (as if by argz_add). Since the first element is in fact the same as *argz, passing in *argz as the value of before will result in entry being inserted at the beginning.
*/
error_t argz_insert(char **argz, size_t *argz_len, char *before, const char *entry) {
	size_t buff_len = *argz_len, before_counter = 0, i = 0;
	char *buff = NULL, *pt = NULL, *pt1 = NULL;
	if ((NULL != *argz) && (0 != *argz_len) && (NULL != entry)) {
		if (NULL == (buff = malloc((buff_len + 1) * sizeof(char)))) {
			return ERROR;
		}
		else {
			if (NULL == (pt = memmove(buff, *argz, *argz_len + 1))) {
				return ERROR;
			}
			pt = buff;
			while (pt < buff + buff_len) {
				if (0 == strcmp(pt, before)) {
					before_counter++;
				}
				pt += strlen(pt) + 1;
			}
			if (0 != before_counter) {
				*argz_len += before_counter * (strlen(entry) + 1);
			}
			else {
				free(buff);
				return OK;
			}
			if (NULL == (*argz = realloc(*argz, *argz_len + 1))) {
				free(buff);
				return ERROR;
			}
			else {
				pt = buff;
				while (buff < pt + buff_len) {
					if (0 == strcmp(buff, before)) {
						if (NULL == (pt1 = memmove(*argz + i, entry, strlen(entry) + 1))) {
							free(buff);
							return ERROR;
						}
						i += strlen(entry) + 1;
					}
					if (NULL == (pt1 = memmove(*argz + i, buff, strlen(buff) + 1))) {
						free(buff);
						return ERROR;
					}
					i += strlen(buff) + 1;
					buff += strlen(buff) + 1;
				}
			}
			buff = pt;
			free(buff);
			return OK;
		}
	}
	else {
		return ERROR;
	}
}

/*
The argz_next function provides a convenient way of iterating over the elements in the argz vector argz. It returns a pointer to the next element in argz after the element entry, or 0 if there are no elements following entry. If entry is 0, the first element of argz is returned.
This behavior suggests two styles of iteration:
char *entry = 0;
while ((entry = argz_next (argz, argz_len, entry)))
action;
(the double parentheses are necessary to make some C compilers shut up about what they consider a questionable while-test) and:
char *entry;
for (entry = argz; entry; entry = argz_next (argz, argz_len, entry))
action;
Note that the latter depends on argz having a value of 0 if it is empty (rather than a pointer to an empty block of memory); this invariant is maintained for argz vectors created by the functions here.
*/
char * argz_next(char *argz, size_t argz_len, const char *entry) {
	if ((NULL != argz) && (0 != argz_len)) {
		if (NULL == entry) {
			return argz;
		}
		else {
			while (argz != entry) {
				argz += strlen(argz) + 1;
			}
			if (argz + strlen(argz) + 1 >= argz + argz_len) {
				return (argz + argz_len + 1);
			}
			else {
				return (argz + strlen(argz) + 1);
			}
		}
	}
	else{
		return (argz + argz_len + 1);
	}
}

/*
Replace the string str in argz with an element with, reallocating argz as
necessary.
*/
error_t argz_replace(char **argz, size_t *argz_len, const char *str, const char *with) {
	int buff_len = *argz_len;
	char *buff = NULL, *pt = NULL, *pt1 = NULL;
	if ((NULL != *argz) && (0 != *argz_len) && (NULL != str)) {
		if (NULL == (buff = malloc((buff_len + 2 - strlen(str) + strlen(with)) * sizeof(char)))) {
			return ERROR;
		}
		else {
			if (NULL == (pt = strstr(*argz, str))) {
				return OK;
			}
			else {
				if (NULL == (pt1 = memmove(buff, *argz, pt - *argz - 1))) {
					return ERROR;
				}
				if (NULL == (pt1 = memmove(buff + (pt - *argz), with, strlen(with) + 1))) {
					return ERROR;
				}
				if (NULL == (pt1 = memmove(buff + (pt - *argz) + strlen(with) + 1, *argz + (pt - *argz) + strlen(str), *argz_len - (pt - *argz) - strlen(str)))) {
					return ERROR;
				}
				*argz_len = buff_len - strlen(str) + strlen(with);
				if (NULL == (*argz = realloc(*argz, *argz_len + 1))) {
					free(buff);
					return ERROR;
				}
				else {
					if (NULL == (pt1 = memmove(*argz, buff, *argz_len + 1))) {
						return ERROR;
					}
					free(buff);
					return OK;
				}
			}
		}
	}
	else {
		return ERROR;
	}
}

/*prints argz vector */
void argz_print(const char *argz, size_t argz_len) {
	char *ptr = argz;
	if ((NULL != argz) && (0 != argz_len)) {
		printf("The current line is:\" ");
		while(argz < ptr + argz_len) {
			printf("%s ", argz);
			argz += strlen(argz) + 1;
		}
		printf("\"\n");
	}
	else {
		printf("\nPointer to vector is empty or Vector is empty\n\n");
	}
	ptr = NULL;
}
