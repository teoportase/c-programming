/*
* The program receives 5 arguments: engine_on, floor_pos, door_pos, brake1, brake2.
* It stores the values of these arguments into one byte (8 bits).
*
* This code is adapted from my group's solution to Exercise 4 in WP2, as it is asking for the same thing.
* 
* Purpose: Bitpacking
* Course: DIT633
* Author: Teodora Portase
* (c) 2024
*/

// Include section
#include <stdio.h>  // For printf

// Declare a new type byte that is an unsigned char (exactly 8 bits)
typedef unsigned char byte;

// Function declarations

byte setBit(byte variable, int bitNumber);      // Check the Java doc for the function
int getBit(byte variable, int bitNumber);       // Check the Java doc for the function
void bin2hex(byte binaryNumber);                // Check the Java doc for the function
int isDigit(char* string);                      // Check the Java doc for the function

/**
 * The main method of the program.
 * @param argc the number of arguments the program receives. Always 1 or greater
 * @param argv an array of arguments (string) the program receives. argv[0] is always the executable's location
 * @returns - 0 if the program ends successfully or due to a expected error
 * @returns - a positive integer if an unexpected error occurs
*/
int main(int argc, char* argv[]) {
    // If the program has an invalid number of arguments, immediately print error message and exit the program.
    if (argc != 6) {
        // Print error message
        printf("Invalid number of arguments. Program accepts 6 arguments.\n");
        // Print format message
        printf("Format: <executable-file> <engine_on> <floor_pos> <door_pos> <brake1> <brake2>");
        // Exit program
        return 0;
    }

    // Iterate through all the additional arguments (engine_on etc.)
    for (int i=1; i<=5; i++) {
        // If any additional argument is not a digit
        if (!isDigit(argv[i])) {
            // Print error message
            printf("Invalid value found. Additional arguments besides executable can only be digits (0-9).");
            // Exit program
            return 0;
        }
    }

    // Declare a byte variable to store the binary value of the input. Initializes as 0
    byte output;

    // Check if the engine is on
    if (argv[1][0] == '1') {
        // Set bit 7 (most significant bit)
        output = setBit(output, 7);
    }
    // If the value of engine_on is neither 1 nor 0
    else if(argv[1][0] != '0') {
        // Print error message
        printf("Invalid engine state. Only 0 (off) or 1 (on).");
        // Exit program
        return 0;
    }

    // Check the possible values of floor_pos (argv[2])
    switch(argv[2][0]) {
        // If the value of the floor_pos is 0, there is no need to set the bit as it is already 0.
        // End the switch statement
        case '0': break;
        // If the floor_pos is 1
        case '1': {
            // Set bit 4, so the trio dedicated to floor_pos is '001' (1 in binary)
            output = setBit(output, 4);
            // End switch case
            break;
        }
        // If the floor_pos is 2
        case '2': {
            // Set bit 5, so the trio dedicated to floor_pos is '010' (2 in binary)
            output = setBit(output, 5);
            // End switch case
            break;
        }
        // If the floor_pos is 3
        case '3': {
            // Set bits 4 & 5, so the trio dedicated to floor_pos is '011' (3 in binary)
            output = setBit(output, 4);     // Set bit 4
            output = setBit(output, 5);     // Set bit 5
            // End switch case
            break;
        }
        // If the floor_pos is 4
        case '4': {
            // Set bit 6, so the trio dedicated to floor_pos is '100' (4 in binary)
            output = setBit(output, 6);
            // End switch case
            break;
        }
        // If the floor_pos is 5
        case '5': {
            // Set bit 4 & 6, so the trio dedicated to floor_pos is '101' (5 in binary)
            output = setBit(output, 4);     // Set bit 4
            output = setBit(output, 6);     // Set bit 6
            // End switch case
            break;
        }
        // If the floor_pos is 6
        case '6': {
            // Set bit 5 & 6, so the trio dedicated to floor_pos is '110' (6 in binary)
            output = setBit(output, 5);     // Set bit 5
            output = setBit(output, 6);     // Set bit 6
            // End switch case
            break;
        }
        // If the floor_pos is 7
        case '7': {
            // Set all allocated bits, so the trio dedicated to floor_pos is '111' (7 in binary)
            output = setBit(output, 4);     // Set bit 4
            output = setBit(output, 5);     // Set bit 5
            output = setBit(output, 6);     // Set bit 6
            // End switch case
            break;
        }
        // If the key position is anything else
        default: {
            // Print error message
            printf("Invalid floor position. Only 0 to 7.");
            // Exit program
            return 0;
        }
    }

    // Check the possible values of door_pos (argv[3])
    switch(argv[3][0]) {
        // If the value of the door_pos is 0, there is no need to set the bit as it is already 0.
        // End the switch statement.
        case '0': break;
        // If the door_pos is 1
        case '1': {
            // Set bit 2, so the pair dedicated to key_pos is '01' (1 in binary)
            output = setBit(output, 2);
            // End switch case
            break;
        }
        // If the key position is anything else
        // The assignment description said the door can only be open or closed, so one allocated bit goes unused
        default: {
            // Print error message
            printf("Invalid door position. Only 0 or 1.");
            // Exit program
            return 0;
        }
    }

    // Check if the value for brake1 is 1
    if (argv[4][0] == '1') {
        // Set the least significant bit (LSB) (0)
        output = setBit(output, 1);
    }
    // If the value of brake1 is neither 1 nor 0
    else if(argv[4][0] != '0') {
        // Print error message
        printf("Invalid brake1 value. Only 0 or 1.");
        // Exit program
        return 0;
    }

    // Check if the value for brake2 is 1
    if (argv[5][0] == '1') {
        // Set the least significant bit (LSB) (0)
        output = setBit(output, 0);
    }
    // If the value of brake2 is neither 1 nor 0
    else if(argv[5][0] != '0') {
        // Print error message
        printf("Invalid brake2 value. Only 0 or 1.");
        // Exit the program
        return 0;
    }

    // Convert the byte to hexadecimal
    bin2hex(output);

    // Exit program
    return 0;
}

// Function definitions

/**
 * Sets the given bit in a byte to 1. If the bit was already 1, it returns the number.
 * @param variable the binary number
 * @param bitNumber the index of the bit to be set
 * @returns The number (byte) if the bit was already set to 1 or gives the new number with the bit set.
*/
byte setBit(byte variable, int bitNumber) {
    // Return the number if bit is set or the new number with the given bit set
    return variable | (1 << bitNumber);
}

/**
 * Gets a given bit from a binary number.
 * @param variable the binary number
 * @param bitNumber the index of the bit to get
 * @returns The bit (int) requested.
*/
int getBit(byte variable, int bitNumber) {
    // Returns only the bit needed using bit shifting
    return (variable >> bitNumber) & 1;
}

/**
 * A function to convert a binary number to hexadecimal (lowercase). Prints the final result.
 * @param binaryNumber the number (byte) to be converted.
*/
void bin2hex(byte binaryNumber) {
    // Initialize the number to store the decimal representation of the binary number
    int number = 0;
    // Start at base 2^0 = 1 as it reads right to left
    int base = 1;

    // Iterate through the 8 bits of the byte
    for(int i=0; i<8; i++) {
        // If the current bit is 0
        if (getBit(binaryNumber, i) == 0) {
            // Increase the base only
            base *= 2;
        }
        // If the current bit is 1
        else if (getBit(binaryNumber, i) == 1) {
            // Add the power of 2 to the number
            number += 1*base;
            // Increase the base
            base *= 2;
        }
    }
    // Convert the decimal number to hexadecimal and print it
    printf("0x%x", number);
}

/**
 * Checks if a given string is a digit (0-9)
 * @param string value to be checked
 * @returns - 1 if true (It is a number from 0 to 9)
 * @returns - 0 if false (It is not a number from 0 to 9)
*/
int isDigit(char* string) {
    // Iterate through all the characters in the string until the null character is encountered
    for(int i=0; string[i] != '\0'; i++) {
        // If the number in the string has more than one integer, it is not a digit
        if (i > 0) {
            // Return false
            return 0;
        }
        // If the character is anything but a digit
        if (string[i] < '0' || string[i] > '9') {
            // Return false
            return 0;
        }
    }

    // Else, return true
    return 1;
}