/************************************************************************
*file: argztest.c
*synopsis: This file is made for different tests with the functions, 
* provided from "argz.h"(prototypes) and "argz.c"(declarations)
*related files: "argz.h", "argz.c"
*author: MarIO
*written: 10/09/2017
*last modified: 03/10/2017
************************************************************************/

//#include "stdafx.h"
#include "argz.h"


int main() {
	const char *line = "/bin", *line1 = "usr=monty", *entry = NULL, *line2 = "PWD=/bin/monty";
	char * const string = "SHELL=/bin/bash:usr=monty:PWD=/bin/monty:LANG=en_US.UTF-8", *argz = NULL;
	int argz_len = strlen(string),rez;
	
	printf("The function \"argz_create_sep\" was called\n");
	if(ERROR == argz_create_sep(string, 58, &argz, &argz_len)){
		printf("\nERROR.Pointer to vector is not empty or size of line is 0 or Line is empty\n");
		printf("Or there might be problems with memory allocation or copying\n\n");
		printf("The function \"argz_create_sep\" has ended\n\n\n");
		return 1;
	}
	printf("String line:\n");
	printf("%s\n", string);
	printf("\n");
	printf("The function \"argz_print\" was called\n");
	argz_print(argz, argz_len);
	printf("\nThe function \"argz_print\" has ended\n");
	printf("The function \"argz_create_sep\" has ended\n\n\n");
	printf("The function \"argz_count\" was called\n");
	printf("The function \"argz_print\" was called\n");
	argz_print(argz, argz_len);
	printf("\nThe function \"argz_print\" has ended\n");
	rez = argz_count(argz, argz_len);
	if (-1 != rez) {
		printf("The ammount of an elements in the line is %d\n", rez);
	}
	else {
		printf("\nERROR.Vector is empty or Pointer to vector is empty");
		printf("The function \"argz_count\" has ended\n\n\n");
		free(argz);
		return 2;
	}
	printf("The function \"argz_count\" has ended\n\n\n");
	printf("The function \"argz_add\" was called\n");
	printf("The function \"argz_print\" was called\n");
	argz_print(argz, argz_len);
	printf("\nThe function \"argz_print\" has ended\n");
	if (ERROR == argz_add(&argz, &argz_len, line)) {
		printf("\nERROR.Pointer to vector is empty or size of line is 0 or Line is empty\n");
		printf("Or there might be problems with memory allocation/reallocation or copying\n\n");
		printf("The function \"argz_add\" has ended\n\n\n");
		free(argz);
		return 3;
	}
	printf("The string line is \"%s\"\n", line);
	printf("The function \"argz_print\" was called\n");
	argz_print(argz, argz_len);
	printf("\nThe function \"argz_print\" has ended\n");
	printf("The function \"argz_add\" has ended\n\n\n");
	printf("The function \"argz_delete\" was called\n");
	printf("The element for delete is \"%s\"\n", line1);
	printf("The function \"argz_print\" was called\n");
	argz_print(argz, argz_len);
	printf("\nThe function \"argz_print\" has ended\n");
	if (ERROR == argz_delete(&argz, &argz_len, line1)) {
		printf("\nERROR.Pointer to vector is empty or size of line is 0\n");
		printf("Or there might be problems with memory allocation/reallocation or copying\n\n");
		printf("The function \"argz_delete\" has ended\n\n\n");
		free(argz);
		return 4;
	}
	printf("The function \"argz_print\" was called\n");
	argz_print(argz, argz_len);
	printf("\nThe function \"argz_print\" has ended\n");
	printf("The function \"argz_delete\" has ended\n\n\n");
	printf("The function \"argz_insert\" was called\n");
	printf("The function \"argz_print\" was called\n");
	argz_print(argz, argz_len);
	printf("\nThe function \"argz_print\" has ended\n");
	printf("\nThe element for insertion is \"%s\"", line);
	printf("\nThe element before insertion is \"%s\"\n", line2);

	if (ERROR == argz_insert(&argz, &argz_len, line2, line)) {
		printf("\nERROR.Pointer to vector is empty or size of line is 0 or Line is empty\n");
		printf("Or there might be problems with memory allocation/reallocation or copying\n\n");
		printf("The function \"argz_insert\" has ended\n\n\n");
		free(argz);
		return 5;
	}
	printf("The function \"argz_print\" was called\n");
	argz_print(argz, argz_len);
	printf("\nThe function \"argz_print\" has ended\n");
	printf("The function \"argz_insert\" has ended\n\n\n");
	printf("The function \"argz_next\" was called\n");
	printf("The function \"argz_print\" was called\n");
	argz_print(argz, argz_len);
	printf("\nThe function \"argz_print\" has ended\n");
	while ((entry = argz_next(argz, argz_len, entry))){
		if (entry >= argz + argz_len) {
			break;
		}
		printf(" The current element is %s\n", entry);
	}
	printf("The function \"argz_next\" has ended\n\n\n");
	printf("The function \"argz_replace\" was called\n");
	printf("The function \"argz_print\" was called\n");
	argz_print(argz, argz_len);
	printf("\nThe function \"argz_print\" has ended\n");
	printf("\nThe replaced line is \"%s\"", line);
	printf("\nThe elementfor replacement is \"%s\"\n", line2);
	if (ERROR == argz_replace(&argz, &argz_len, line, line2)) {
		printf("\nERROR.Pointer to vector is empty or size of line is 0 or Line is empty\n");
		printf("Or there might be problems with memory allocation/reallocation or copying\n\n");
		printf("The function \"argz_insert\" has ended\n\n\n");
		free(argz);
		return 7;
	}
	printf("The function \"argz_print\" was called\n");
	argz_print(argz, argz_len);
	printf("\nThe function \"argz_print\" has ended\n");
	printf("The function \"argz_replace\" has ended\n\n\n");
	free(argz);
	while(getchar())
	return 0;
}
