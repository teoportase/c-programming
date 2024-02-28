/*
* The program receives one argument and gives the number in that position in the Fibonacci sequence (starting from 0).
* This program uses a linked list and only accepts positive integers (greater than or equal to 0).
*
* 
* Purpose: Fibonacci sequence
* Course: DIT633
* Author: Teodora Portase
* (c) 2024
*/

// Include section
#include <stdio.h>   // For printf
#include <stdlib.h>  // For malloc, free, atoi

// Define the structure for a linked list node
typedef struct LL_node {
    // The value of the node
    int value;
    // A pointer to the next node in the list
    struct LL_node* next;
} node;

// Function declarations
node* generateList(int listSize);

/**
 * The main method of the program.
 * @param argc the number of arguments the program receives. Always 1 or greater
 * @param argv an array of arguments (string) the program receives. argv[0] is always the executable's location
 * @returns - 0 if the program ends successfully or due to a expected error
 * @returns - a positive integer if an unexpected error occurs
*/
int main(int argc, char* argv[]) {
    // If the program does not have the accepted number of arguments
    if (argc != 2) {
        // Print error message
        printf("Invalid number of arguments.");
        // Exit program
        return 0;
    }

    // Iterate through the characters of the string argument
    for (int i=0; argv[1][i] != '\0'; i++) {
        // If any of the characters in the string is not a digit
        if ((argv[1][i] < '0' || argv[1][i] > '9') && argv[1][i] != '-') {
            // Print error message
            printf("Invalid input");
            // Exit program
            return 0;
        }
    }

    // Convert the string argument to an integer
    int number = atoi(argv[1]);

    // If the number is 0
    if (number == 0) {
        // Print 0
        printf("0");
        // Exit the program
        return 0;
    }

    // Define variables for head node and the node used for iterating through the list
    node *head, *current;
    // Generate the Fibonacci linked list with only the amount of numbers necessary & save the head of the list
    head = generateList(number);
    // Set the current node address to the head node address
    current = head;

    // While there are still nodes to iterate through
    while (current->next != NULL) {
        // Move to the next node
        current = current->next;
    }

    // The current node is now the last one (the one we need). Print out the needed value
    printf("%d", current->value);

    // Iterate through the nodes until null is encountered while making the current node the head node
    while ((current = head) != NULL) {
        // Set the head element to the next element
        head = current->next;
        // Free the memory used by the current code
        free(current);
    }

    // Exit program
    return 0;
}

node* generateList(int listSize) {
    // Declare variables to work in the linked list with
    node *head, *old, *new;
    int fibonacci = 1;
    // Allocate memory for the head/top node
    head = (node*) malloc(sizeof(node));
    // Set the next node address as null for now
    head->next = NULL;
    head->value = 0;
    old = head;

    // Iterate through the number of nodes needed
    for (int j = 2; j <= listSize; j++) {
        // Allocate memory for the new node
        new = (node*) malloc(sizeof(node));
        // Assign the value to the new node
        new->value = fibonacci;
        // Calculate the next number in the Fibonacci sequence
        fibonacci = fibonacci + old->value;
        // Point the previous node to the new one
        old->next = new;
        // Set the previous node to the current one to be use later
        old = new;
    }

    // Set the last node's pointer to the next node to NULL
    old->next = NULL;

    // Return the head node
    return head;
}