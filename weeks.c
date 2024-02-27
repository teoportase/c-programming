/*
* The program asks for a starting week (1 to 5) and day of the week.
* It then prints all the following days like a calendar until week 5.
* 
* Purpose: Enums in C
* Course: DIT633
* Author: Teodora Portase
* (c) 2024
*/

// Include section
#include <stdio.h>  // For printf, scanf
#include <stdlib.h> // For atoi()
// #include <windows.h> // For Sleep()
#include <unistd.h> // For sleep()

// Enum declarations
// Enum for days of the week + Create variable for the day of the week
enum days_of_week {Monday = 1, Tuesday, Wednesday, Thursday, Friday, Saturday, Sunday, DAYS_TOTAL} day;
// Enum for number of weeks; Assigns value of 1 to w1, and the following weeks receive +1 to the value of the element before it
// Also, creates variable for week number
enum weeks {w1 = 1, w2, w3, w4, w5, WEEK_TOTAL} week;

// Function declarations
char* getDay(enum days_of_week day);             // Check Javadoc or after main()
int readInteger(char string[], char* prompt);    // Check Javadoc or after main()
int parseWeekNumber(int number);                 // Check Javadoc or after main()
int parseDay(int number);                        // Check Javadoc or after main()

/**
* Main method of the program. Accepts no parameters
* @returns - 0 if program is successful/encounters expected error
* @returns - a positive integer if an unexpected error occurs
**/
int main(void) {
    // Store the input in a buffer
    char input[10];
    // Store input as number
    int numberInput;

    // Read input and store in numberInput
    numberInput = readInteger(input, "Provide starting week (1 to 5): ");

    // Check if number is not a valid week number
    if (!parseWeekNumber(numberInput)) {
        // Print error message
        printf("Invalid week\n");
        // Exit program
        return 0;
    }

    // Read input and store in numberInput
    numberInput = readInteger(input, "Provide starting day (1 to 7, where Monday is 1): ");

    // Check if number is not a valid day number
    if (!parseDay(numberInput)) {
        // Print error message
        printf("Invalid day\n");
        // Exit program
        return 0;
    }

    // Iterate through weeks starting from the one from user input until the total number of weeks
    for (int i=week; i<WEEK_TOTAL; i++) {
        // Iterate through days of the week starting from user input (first iteration) or Monday (second iteration and beyond)
        for (int j=day; j<DAYS_TOTAL; j++) {
            // Print message to user
            printf("Week %d, %s\n", i, getDay(j));
            // Wait 1 second (1000 milliseconds) - Windows (requires #include <windows.h> instead of #include <unistd.h>)
            // Sleep(1000);
            // Wait 1 second - Linux; Codegrade runs on Linux?
            sleep(1);
        }
        // Reset day of the week to Monday to clear the user input one
        day = Monday;
    }

    // Exit program
    return 0;
}

/**
 * Converts the int enum value to a string for the user
 * @param day the integer value to be converted to a day of the week
 * @returns - string version of the day of the week
 * @returns - nothing if the number is outside the range of 1 to 7
*/ 
char* getDay(enum days_of_week day) {
    // Switch statement for value of day
    switch (day) {
        // If day is 1
        case Monday: return "Monday";
        // If day is 2
        case Tuesday: return "Tuesday";
        // If day is 3
        case Wednesday: return "Wednesday";
        // If day is 4
        case Thursday: return "Thursday";
        // If day is 5
        case Friday: return "Friday";
        // If day is 6
        case Saturday: return "Saturday";
        // If day is 7
        case Sunday: return "Sunday";
    }
}

/**
 * Method that checks if a given string is a number, and returns the number as an int if it is
 * @param string an array of characters representing the value being checked
 * @returns - the number if successful
 * @returns - -1 if unsuccessful
*/
int readInteger(char string[], char* prompt) {
    // Print prompt
    printf("%s", prompt);
    // Check that something is read
    if (scanf("%s", string) != 1) {
        // If nothing is read, return -1
        return -1;
    }

    // Return string as integer
    return atoi(string);
}

/**
*   Method that parses the input (week number) to its enum counterpart, and checks if its valid
*   @param number a number representing the value to be checked
*   @returns - 1 if the number is within the enum
*   @returns - 0 if number is not within enum
**/
int parseWeekNumber(int number) {
    // Go through possible values of number
    switch (number) {
        // If number is 1
        case 1: {
            // Week becomes week 1
            week = w1;
            // Return true
            return 1;
        }
        // If number is 2
        case 2: {
            // Week becomes week 2
            week = w2;
            // Return true
            return 1;
        }
        // If number is 3
        case 3: {
            // Week becomes week 3
            week = w3;
            // Return true
            return 1;
        }
        // If number is 4
        case 4: {
            // Week becomes week 4
            week = w4;
            // Return true
            return 1;
        }
        // If number is 5
        case 5: {
            // Week becomes week 5
            week = w5;
            // Return true
            return 1;
        }
        // If number is any other number, return false
        default: return 0;
    }
}

/**
*   Method that parses the input (day number) to its enum counterpart, and checks if its valid
*   @param number an integer representing the value to be converted
*   @returns - 1 if the number is within the enum
*   @returns - 0 if number is not within enum
**/
int parseDay(int number) {
    // Go through possible values of number
    switch (number) {
        // If number is 1
        case 1: {
            // Day becomes Monday
            day = Monday;
            // Return true
            return 1;
        }
        // If number is 2
        case 2: {
            // Day becomes Tuesday
            day = Tuesday;
            // Return true
            return 1;
        }
        // If number is 3
        case 3: {
            // Day becomes Wednesday
            day = Wednesday;
            // Return true
            return 1;
        }
        // If number is 4
        case 4: {
            // Day becomes Thursday
            day = Thursday;
            // Return true
            return 1;
        }
        // If number is 5
        case 5: {
            // Day becomes Friday
            day = Friday;
            // Return true
            return 1;
        }
        // If number is 6
        case 6: {
            // Day becomes Saturday
            day = Saturday;
            // Return true
            return 1;
        }
        // If number is 7
        case 7: {
            // Day becomes Sunday
            day = Sunday;
            // Return true
            return 1;
        }
        // If number is any other number, return false
        default: return 0;
    }
}