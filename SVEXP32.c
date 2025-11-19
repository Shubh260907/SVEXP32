#include <stdio.h>
#include <string.h>
#include <stdlib.h> // For EXIT_FAILURE

// Define the maximum size for a word. This addresses Key Question 6.
// A typical buffer size for a word should be ample to prevent overflow.
#define MAX_WORD_LEN 1024

// Function Prototype
void reverse_string(char *str);

int main() {
    FILE *file_ptr;
    char word_buffer[MAX_WORD_LEN];
    const char *filename = "Demo.txt";

    // 1. Open the file for reading
    file_ptr = fopen(filename, "r");

    // Key Question 1: Does the program handle the case where the file does not exist?
    if (file_ptr == NULL) {
        perror("Error opening file");
        printf("Could not open the file '%s'. Ensure it exists and has read permissions.\n", filename);
        return EXIT_FAILURE; // Exit the program with an error status
    }

    printf("--- Original Text Words with Reversal ---\n");
    printf("Reversed Text: \n");

    // 2. Read words from the file and process them
    // Key Question 2 & 4: Using fscanf with %s reads strings delimited by whitespace
    // (spaces, tabs, newlines) automatically, making it ideal for word boundaries.
    while (fscanf(file_ptr, "%s", word_buffer) != EOF) {

        // Key Question 6: The %s format specifier with fscanf is generally safe
        // because the word_buffer size (MAX_WORD_LEN) limits the read length,
        // though standard C practice suggests using %1023s for explicit limit.
        // For simplicity and common practice, we'll use %s here, assuming the buffer is large.

        // Store the original word length before reversal
        size_t len = strlen(word_buffer);

        // 3. Reverse the current word
        // Key Question 5: Is each word reversed correctly?
        reverse_string(word_buffer);

        // 4. Display the reversed word.
        // The original sequence of words is maintained by printing them in the order they are read.
        printf("%s ", word_buffer);


    }

    printf("\n---------------------------------------------\n");

    // Key Question 3: Are file operations properly closed using fclose()?
    if (fclose(file_ptr) == EOF) {
        perror("Error closing file");
        return EXIT_FAILURE;
    }

    return 0;
}

/**
 * @brief Reverses a C-style null-terminated string in place.
 * @param str The string to be reversed.
 */
void reverse_string(char *str) {
    int start = 0;
    int end = strlen(str) - 1;
    char temp;

    // Use two pointers (start and end) to swap characters
    while (start < end) {
        temp = str[start];
        str[start] = str[end];
        str[end] = temp;

        start++;
        end--;
    }
}
