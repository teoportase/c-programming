/*
* This program checks for an argument that will become a name. If there is no name provided, the program responds appropriately.
* The name can be between 3 and 50 characters long. If all conditions are met, the program greets the user using the provided name.
* 
* Purpose: Exercising writing code in C.
* Course: DIT633
* Author: Teodora Portase
* (c) 2024
*/

// Include section
#include <stdio.h>		// for input and output
#include <string.h>		// for strlen()

// Since we need the name argument, I'm using the verbose main method
int main(int argc, char *argv[]) {
	// If there is no additional argument provided, the only argument will be the executable name, so the size will be 1
	if (argc == 1) {
		printf("No command line argument provided, please provide a name. ");	// This is the error message for this case as taken from Canvas
	}
	// Checks if the length of the name is more than 50 characters long, as that is not allowed by this program
	else if (strlen(argv[1]) > 50) {
		printf("Name too long, max 50 characters");								// This is the error message for this case as taken from Canvas
	}
	// Checks if the length of the name is less than 3 characters long, as that is not allowed by this program
	else if (strlen(argv[1]) < 3) {
		printf("Name too short, min 3 characters");								// This is the error message for this case as taken from Canvas
	}
	// If all other cases are successful, print the success message.
	else {
		printf("Hello %s, how is your day today?", argv[1]);					// Prints the success message
	}

	return (0); // Exit program
}