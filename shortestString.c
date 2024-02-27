/*
* The program receives 5 strings from the console and stores them in an array.
* It finds the shortest string and removes it from the array.
*
* 
* Purpose: String array manipulation
* Course: DIT633
* Author: Teodora Portase
* (c) 2024
*/

// Include section
#include <stdio.h>  // For printf, fgets
#include <stdlib.h> // For malloc

// Define section
#define ARR_SIZE 5      // Set max array size
#define BUFFER_SIZE 300 // Set buffer size

// Function declarations
void removeShortestString(char** array);    // Remove the shortest string in an array and print the remaining elements
int findShortestString(char** array);       // Find the shortest string in an array
void removeString(char** array, int index); // Remove a string from an array and print it

/**
 * The main method of the program. Accepts no parameters.
 * 
 * @returns - 0 if the program ends successfully or due to a expected error
 * @returns - a positive integer if an unexpected error occurs
*/
int main(void) {
    // Initialize array of strings
    char* array[ARR_SIZE];

    // Reads the input strings and stores them in the array if valid
    for(int i=0; i<ARR_SIZE; i++) {
        // Print prompt message
        printf("Enter string %d: ", i+1);
        // Create a variable for the input string
        char input[BUFFER_SIZE];
        // Read the input
        fgets(input, sizeof(input), stdin);

        // Allocate enough memory in the array for the new string
        array[i] = malloc(sizeof(input));
        
        // Iterate through the inputted string
        for (int j=0; input[j] != '\0'; j++) {
            // Add the current character of the input string to the array
            array[i][j] = input[j];

            // If this is the second to last character (last one is always the null character)
            if (input[j+1] == '\0' || input[j+1] == '\n') {
                // Set the last character as the null character
                array[i][j+1] = '\0';
                // End the loop
                break;
            }
        }
    }

    // Remove the shortest string and print the remaining elements
    removeShortestString(array);

    // Exit program
    return 0;
}

/**
 * Remove the shortest string from a given array of strings.
 * @param array the array of strings on which to operate
*/
void removeShortestString(char** array) {
    // Find the index of the shortest string and store it
    int shortestString = findShortestString(array);

    // Print the shortest string
    printf("Shortest string removed: %s\n", array[shortestString]);

    // Remove the shortest string given its index
    removeString(array, shortestString);

    // Print out the remaining elements of the array
    printf("Array after removal:\n");
    // Iterate through the remaining elements of the array
    for(int i=0; i<ARR_SIZE-1; i++) {
        // Print every element one by one
        printf("%s\n", array[i]);
    }
}

/**
 * Finds the shortest string in a given array.
 * @param array the array of strings on which to operate
 * @returns The index of the shortest string in the array. If there are multiple with the same length, it will return the first one it finds.
*/
int findShortestString(char** array) {
    // The index of the shortest string. Started at 0 for the first string
    int shortestString = 0;
    // The length of the shortest string. Started at BUFFER_SIZE.
    int shortestLength = BUFFER_SIZE;

    // Iterate through the strings in the array
    for (int i=0; i<ARR_SIZE; i++) {
        // Initialize the current string's length as 0
        int length = 0;
        // Iterate through the characters of the string
        for (int j=0; array[i][j] != '\0'; j++) {
            // Increase the variable for the length of the string by 1
            length++;
        }

        // If the length of this string is shorter than that of the current shortest length
        if (length < shortestLength) {
            // Make the shortest length this string's length
            shortestLength = length;
            // Change the index of the shortest string to match the current string's index
            shortestString = i;
        }
    }

    // Return the index of the shortest string
    return shortestString;
}

/**
 * Remove a given element from an array of strings.
 * @param array the array of strings on which to operate
 * @param index the index of the element to remove
*/
void removeString(char** array, int index) {
    // Iterate through the array starting from the element after the one to remove
    for (int i=index+1; i<ARR_SIZE; i++) {
        // Realocate the previous spot to the length of the next element
        array[i-1] = realloc(array[i-1], sizeof(array[i]));

        // Iterate through the string
        for (int j=0; array[i][j] != '\0'; j++) {
            // Copy the character into the previous spot in the array
            array[i-1][j] = array[i][j];

            // If it is the second to last character
            if (array[i][j+1] == '\0') {
                // Terminate the string with a null character
                array[i-1][j+1] = '\0';
                // Break out of the loop
                break;
            }
        }
    }
}