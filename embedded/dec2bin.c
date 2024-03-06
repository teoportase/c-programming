/*
* This program checks for an integer argument. If an invalid argument/number of arguments is provided, the program responds appropriately.
* The program will print the number, its binary representation, and the number of 0s and 1s in its binary form. Leading 0s do not count.
*
* Main method Java docs style derived from DIT633 Lecture 2 bits and bytes exercise by Miroslaw Staron
* (https://github.com/miroslawstaron/DIT632_lecture_week_2/blob/master/bits_and_bytes.c)
* 
* Purpose: Working with bits and bytes using C.
* Course: DIT633
* Author: Teodora Portase
* (c) 2024
*/

// Include section
#include <stdio.h> // For basic functions like printf
#include <stdlib.h> // For string to int (atoi) method
#include <string.h> // For strlen method

/*
* Main method of the program
* @param argc  number of arguments (at least 1)
* @param argv[]  array of arguments (Strings)
* @returns - 0 if ok, positive integer when an error occurs
*/
int main(int argc, char* argv[]) {
    // Checks if the program receives one additional argument
    if (argc == 2) {
        // Iterate through characters of argument
        for (int i=0; i<strlen(argv[1]); i++) {
            // Check if the character is between 0 and 9 using their ASCII values (48 for 0 and 57 for 9)
            if(argv[1][i] < 48 || argv[1][i] > 57) {
                // Print error message
                printf("Error: Invalid number.");
                // Exit program
                return 0;
            }
        }

        // Cast string argument to integer
        unsigned int number = atoi(argv[1]);
        // Print the number
        printf("Number: %d\n", number);
        // Print its binary representation & add the '0b'
        printf("Binary: 0b");

        // Variable to store binary representation
        unsigned int binaryNum = 0;
        // Create counter variables for amount of 0s and 1s and set value to 0
        int counter0 = 0, counter1 = 0;

        // Check if number is 0 since it is a special case
        if (number == 0) {
            // Increase counter to count the last 0
            counter0++;
        }
        // Otherwise follow procedure for every other number
        else {
            // An alternative to a boolean. Set to true (1) as all 0s encountered first are leading 0s
            short leading0s = 1;

            // Iterate left to right through the bits of the number
            for (int i=31; i>=0; i--) {
                // Store the current first bit(s)
                int firstBit = number >> i;
                
                // Check if the current first bit(s) is not set
                if ((firstBit & 1) == 0) {
                    // Check found 0 is not a leading zero
                    if (leading0s != 1) {
                        // Increase the number of 0s
                        counter0++;
                        // Update binary representation to include 0
                        printf("0");
                    }
                }
                // If the first bit is 1, enter here
                else {
                    // Update the counter for 1s
                    counter1++;
                    // Update the binary representation to include 1
                    printf("1");
                    // Since first a 1 was encountered, further 0s are not leading
                    leading0s = 0;
                }
            }
        }

        // Enter new line
        printf("\n");
        // Print the number of 0s
        printf("Number of 0s: %d\n", counter0);
        // Print the number of 1s
        printf("Number of 1s: %d\n", counter1);

    }
    // Otherwise prints error message
    else {
        // Error message
        printf("Error: No number provided. Please provide a number as a command line argument.");
    }

    return 0; // Exit program
}