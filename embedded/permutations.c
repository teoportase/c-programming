/*
* The program receives a string as an argument, and it prints all the permutations of that string.
* The string cannot be more than 10 characters.
* 
* Purpose: Finding permutations of a string using pointers
* Course: DIT633
* Author: Teodora Portase
* (c) 2024
*/

// Include section
#include <stdio.h>  // For printf
#include <stdlib.h> // For malloc
#include <string.h> // For strcpy

// Function declarations

void permute(char* string, char** array, int* index, int start, int end);   // Recursive function for finding permutations
void swap(char* char1, char* char2);                                        // Swap two characters in a string
int calcFactorial(int number);                                              // Calculate the factorial of a number

/**
* Main method of the program.
* @param argc the number (int) of arguments given to the program. Always > 0.
* @param argv an array of arguments (string) given to the program. argv[1] is always the executable path.
* @returns - 0 if program is successful/encounters expected error
* @returns - a positive integer if an unexpected error occurs
**/
int main(int argc, char* argv[]) {
    // argv[1] = "ab";
    // argc++;

    // If there are not exactly two arguments (one for executable file and one for the input string)
    if (argc != 2) {
        // Print error message
        printf("Invalid number of arguments. Only one additional argument accepted.");
        // Exit program
        return 0;
    }

    // The length variable for the input string
    int length = 0;

    // Iterate through the input string
    for (int i=0; argv[1][i] != '\0'; i++) {
        // Increment the length
        length++;
    }

    // If the length of the string exceeds 10 characters
    if (length > 10) {
        // Print error message
        printf("Invalid number of characters. Maximum 10 characters.");
        // Exit program
        return 0;
    }

    // Create a pointer to the input string
    char* string = argv[1];
    // Declare variable for the number of permutations
    int nr_perms = calcFactorial(length);
    // Allocate memory for the array of permutations of the input string
    char** permutations = (char**) malloc(nr_perms*sizeof(char*));

    // Iterate for as many permutations as there are
    for(int i=0; i<nr_perms; i++) {
        // Allocate memory for each element of the permutations array
        permutations[i] = malloc(length+1 * sizeof(char));
    }

    // Print beginning of output message
    printf("All permutations of the string %s are: ", string);

    // Declare variable for the index in permutations
    int index = 0;
    // Generate permutations and add them in the array
    permute(string, permutations, &index, 0, length);

    // Iterate for as many permutations as there are
    for(int i=0; i<nr_perms; i++) {
        // Free memory for each element of the permutations array
        free(permutations[i]);
    }
    
    // Free the memory allocated to the large array of permutations
    free(permutations);

    // Exit program
    return 0;
}

/**
 * Generates all the permutations of a string/part of a string and stores them in an array.
 * @param string a pointer to the string on which to operate
 * @param array a pointer to an array of strings of permutations
 * @param start the place in the string from which to start when generating permutations (usually 0)
 * @param end the place in the string at which to end when generating permutations (usually string length)
*/
void permute(char* string, char** array, int* index, int start, int end) {
    if (start == end) {
        // Add current permutation to permutations array
        strcpy(array[*index], string);
        // Increase the value of index
        (*index)++;

        // Print the permutation for the user
        printf("%s   ", string);
        // End this iteration of the function
        return;
    }

    // Iterate through the string from character "start" to character "end"
    for (int i=start; i < end; i++) {
        // Swap the start character with the character in position i
        swap(string + start, string + i);
        // Find all permutations for this new string
        permute(string, array, index, start+1, end);
        // Swap the characters back
        swap(string + start, string + i);
    }
}

/**
 * Swaps two characters in a string.
 * 
 * @param char1 a pointer to the first character to swap
 * @param char2 a pointer to the second character to swap
*/
void swap(char* char1, char* char2) {
    // Store the value of character 1 in a temporary variable
    char temp = *char1;
    // Add the value of character 2 in the place of character 1
    *char1 = *char2;
    // Add the temporary value (char1's value) in the place of character 2
    *char2 = temp;
}

/**
 * Calculates the factorial of a number.
 * @param number an integer to operate with
 * @returns The factorial of the number parameter.
*/
int calcFactorial(int number) {
    // Start the product at the neutral factor (1)
    int product = 1;

    // Go through every number from 2 to the number given
    for (int i=2; i<=number; i++) {
        // Multiply the product by the current number
        product = product * i;
    }

    // Return the final product
    return product;
}