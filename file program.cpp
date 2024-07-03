#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LEN 50
#define MAX_LINE_LEN 1000


//Muskan 
int main() {
    char filename[MAX_FILENAME_LEN];
    FILE *file;
    char line[MAX_LINE_LEN];
    int numLines = 0, numWords = 0, numChars = 0;

    printf("Enter the name of the file: ");
    fgets(filename, MAX_FILENAME_LEN, stdin);
    filename[strcspn(filename, "\n")] = '\0';

    file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    while (fgets(line, MAX_LINE_LEN, file) != NULL) {
        numLines++;
        numChars += strlen(line);

        int inWord = 0;
        for (int i = 0; line[i] != '\0'; i++) {
            if (line[i] == ' ' || line[i] == '\t' || line[i] == '\n') {
                inWord = 0;
            } else if (inWord == 0) {
                inWord = 1;
                numWords++;
            }
        }
    }

    fclose(file);

    printf("\nFile Analysis: %s\n", filename);
    printf("Total number of lines: %d\n", numLines);
    printf("Total number of words: %d\n", numWords);
    printf("Total number of characters: %d\n", numChars);

    return 0;
}

