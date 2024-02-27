/*
* The program asks for the size of two matrices (number of rows and columns).
* It then asks for the values within those two matrices, and prints out the sum of the two.
* If it encounters any errors, an appropriate error message will appear.
* 
* Purpose: Matrices and pointers in C
* Course: DIT633
* Author: Teodora Portase
* (c) 2024
*/


// Include section
#include <stdio.h>  // For printf, getchar
#include <stdlib.h> // For atoi
#include <string.h> // For strcmp

// Define section
#define MAX_SIZE 4

// Function declarations

void readInput(char input[], int i);                                    // Reads user input
int storeSize(char* string, int* rows, int* columns);                   // Stores the size of the matrices using user input
int storeMatrix(char* string, int row_nr, int col_nr, int matrix[]);    // Stores values for matrix using user input
int getNumber(char* string, int start, int end);                        // Converts a substring to its integer counterpart

/**
* Main method of the program. Accepts no parameters
* @returns - 0 if program is successful/encounters expected error
* @returns - a positive integer if an unexpected error occurs
**/
int main(void) {
    // Declare variables for the sizes of the matrices
    int row_nr, col_nr;
    // Declare pointer for row_nr
    int* pRow = &row_nr;
    // Declare pointer for col_nr
    int* pCol = &col_nr;
    // Variable for the input buffer
    char input[20];
    // Index used when reading input
    int i = 0;

    // Print matrix size prompt
    printf("Input the size of the matrix: ");
    // Read user input
    readInput(input, i);

    // If the string to int conversion of the size gives an error code
    if(storeSize(input, pRow, pCol) == -1) {
        // Print error message
        printf("Invalid matrix size. Only 2, 3, or 4.");
        // Exit program
        return 0;
    }

    // Create matrix variables (as arrays) given size from input
    int matrix1[row_nr*col_nr];
    // Variable for matrix 2
    int matrix2[row_nr*col_nr];

    // Print matrix1 element prompt
    printf("Input elements of matrix 1: ");
    // Reset the index counter to 0
    i=0;
    // Read user input
    readInput(input, i);

    // Check if there are any problems storing the values in the matrix
    if(storeMatrix(input, row_nr, col_nr, matrix1) == -1) {
        // Print error message
        printf("Invalid number of elements or element type.");
        // Exit program
        return 0;
    }

    // Print matrix2 element prompt
    printf("Input elements of matrix 2: ");
    // Reset the index counter to 0
    i=0;
    // Read user input
    readInput(input, i);

    // Check if there are any problems storing the values in the matrix
    if(storeMatrix(input, row_nr, col_nr, matrix2) == -1) {
        // Print error message
        printf("Invalid number of elements or element type.");
        // Exit program
        return 0;
    }

    // Print addition start message
    printf("The sum is:\n");

    // Adding the matrices
    int colCounter = 0;
    // Iterate through each row
    for (int i=0; i<row_nr*col_nr; i++) {
        // Print the sum of the elements in the same position in both matrices + a space
        printf("%d ", matrix1[i] + matrix2[i]);
        // Increment the counter for the column
        colCounter++;

        // If the column counter is greater than or equal to the max number of columns
        if (colCounter >= col_nr) {
            // Print an EOL character between rows
            printf("\n");
            // Reset the column counter
            colCounter = 0;
        }
    }

    // Exit program
    return 0;
}

// Function definitions

/**
 * Reads user input until EOL character is found.
 * @param input array (char) in which to store the user input
 * @param i the index for the array as well as what is used for exiting the loop
*/
void readInput(char input[], int i) {
    // Read user input until exit condition is met
    while (i != -1){
        // Read the next character of the user input and store it
        input[i] = getchar();

        // If the read character was the EOL character
        if (input[i] == '\n') {
            // Change it to the NULL character (for the end of the input string)
            input[i] = '\0';
            // Change i to trigger the exit condition
            i = -1;
        }
        // If the character is not the EOL character
        else {
            // Increment the index
            i++;
        }
    }
}

/**
 * Saves the value of the matrix size (number of rows and columns) gotten from an input string.
 * Accepts only row/column size of 2, 3, or 4.
 * 
 * @param string the string containing the row and column size values. Format is assumed to be "<row_nr> <col_nr>".
 * @param rows a pointer to the variable storing the number of rows of the matrix
 * @param columns a pointer to the variable storing the number of columns of the matrix
 * 
 * @returns - 0 if the values are saved successfully
 * @returns - -1 if some error occurs
*/
int storeSize(char* string, int* rows, int* columns) {
    // Pseudo-booleans checking if the value for rows/columns has been checked
    // This is to avoid the user inputting multiple values instead of 2 for the matrix size
    int rows_saved = 0, columns_saved = 0;
    // Iterates through the input string until null character is encountered
    for (int i=0; string[i] != '\0'; i++) {
        // If the read character is a space
        if (string[i] == ' ') {
            // Ignore it, and move on to checking the next character
            continue;
        }
        // If the character read is not a number between 2 to 4
        else if (string[i] < '2' || string[i] > '4') {
            // Return error code
            return -1;
        }
        // If the value for rows hasn't been saved yet (it is stored first)
        else if (!rows_saved) {
            // Store the size from user input (ASCII value - the difference until its integer value)
            *rows = string[i] - 48;
            // Change rows_saved to true
            rows_saved = 1;
        }
        // If the value for columns hasn't been saved yet (it is stored after row size)
        else if (!columns_saved) {
            // Store the size from user input (ASCII value - the difference until its integer value)
            *columns = string[i] - 48;
            // Change columns_saved to true
            columns_saved = 1;
        }
        // In any other scenario
        else {
            // Break the loop
            break;
        }
    }

    // If the values for row size and column size were stored
    if (rows_saved && columns_saved) {
        // Return success exit code
        return 0;
    }
    // If one of the values wasn't stored, or neither was stored
    else {
        // Return error code
        return -1;
    }
}

/**
 * Saves the values of a matrix size gotten from an input string.
 * Accepts only row_nr * col_nr elements.
 * 
 * @param string the string containing the values of the matrix. Values are assumed to be from left to right, then top to bottom.
 * @param row_nr the number of rows the matrix has
 * @param col_nr the number of columns the matrix has
 * @param matrix a pointer to an array (int) of size [row_nr*col_nr] that stores the values that are given in the string
 * 
 * @returns - 0 if the values are saved successfully
 * @returns - -1 if some error occurs
*/
int storeMatrix(char* string, int row_nr, int col_nr, int matrix[]) {
    // Counts the number of elements inputted 
    int elementCounter = 0;
     // Pseudo-boolean to remember if a number is negative. To avoid inputs like "-1-1" being valid
    int isNegative = 0;
    // Stores the starting index of the current number being read
    int start_nr = 0;

    // Iterates through the input string until null character is encountered
    for(int i=0; string[i] != '\0'; i++) {
        // If the read character is a space
        if (string[i] == ' ') {
            // If there is room for another element and there are no double spaces
            if (elementCounter < (row_nr * col_nr) && string[i-1] != ' '){
                // Get the number as an integer and update the matrix with its value
                matrix[elementCounter] = getNumber(string, start_nr, i);
            }
            // Increment the element counter
            elementCounter++;
            // Change isNegative to false to reset for the next number
            isNegative = 0;
            // Change the starting index to the next character
            start_nr = i+1;
        }
        // If the character read is a dash and the number is not marked as negative
        else if (string[i] == '-' && !isNegative) {
            // Check if the dash is in the correct position (avoids inputs like "1-1" being valid)
            if(i>0 && string[i-1] == ' ') {
                // Change isNegative to true
                isNegative = 1;
            }
            // If the negative sign positioning is not respected
            else {
                // Return error code
                return -1;
            }
        }
        // If the character read is a digit
        else if (string[i] >= '0' && string[i] <= '9') {
            // Check if it is the final character
            if (string[i+1] == '\0') {
                // If there is still room in the matrix
                if (elementCounter < (row_nr * col_nr)) {
                    // Get the number as an integer and update the matrix with its value
                    matrix[elementCounter] = getNumber(string, start_nr, i);
                }
                // Increment the element counter
                elementCounter++;
            }
        }
        // If character is any other invalid input
        else {
            // Return error code
            return -1;
        }
    }

    // If the number of elements matches the number of max elements allowed
    if (elementCounter == (row_nr * col_nr)) {
        // Return success code
        return 0;
    }
    // If it does not match
    else {
        // Return error code
        return -1;
    }
}

/**
 * Converts a given substring into an integer.
 * 
 * @param string the string from which to take the substring
 * @param start the starting index for the substring
 * @param end one more than the ending index wanted
 * 
 * @returns The substring as an integer
*/
int getNumber(char* string, int start, int end) {
    // If there is only one character to check
    if (start == end) {
        // Return the integer value of the digit using ASCII value to integer conversion for digits
        return string[start] - 48;
    }

    // Create a substring with length based on the given parameters
    char substring[end-start+1];
    // Create the index for the substring
    int index = 0;

    // Iterate through the original string from the start position to end position
    for(int i=start; i<=end; i++) {
        // If the character from the original string is the last one to be read
        if(i == end) {
            // Add a NULL character at the end of the substring
            substring[index] = '\0';
        }
        // Otherwise
        else {
            // Copy the character from the original string to the substring
            substring[index] = string[i];
            // Increment the substring's index
            index++;
        }
    }

    // Return the integer version of the substring
    return atoi(substring);
}