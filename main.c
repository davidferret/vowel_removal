#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define MAXSIZE 100

int isVowel(char c);
void dsmvwl(char str[]);
void saveToFile(char str[], const char *filename);
void loadFromFile(char str[], const char *filename);

int main(void) {
    char text[MAXSIZE], filename[50];
    int choice;
    
    printf("Choose input method:\n1 - Manual Entry\n2 - Load from File\nEnter choice: ");
    scanf("%d", &choice);
    getchar(); // Consume newline character
    
    if (choice == 2) {
        printf("Enter filename: ");
        scanf("%s", filename);
        getchar(); // Consume newline character
        loadFromFile(text, filename);
    } else {
        printf("Enter text to dsmvwl: ");
        fgets(text, MAXSIZE, stdin);
    }
    
    if (strcmp(text, "-1\n") == 0) {
        printf("Program Terminated!\n");
        return 0;
    }
    
    dsmvwl(text);
    printf("Output: %s\n", text);
    
    printf("Enter filename to save processed text: ");
    scanf("%s", filename);
    saveToFile(text, filename);
    
    return 0;
}

int isVowel(char c) {
    c = toupper(c);
    return (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');
}

void dsmvwl(char str[]) {
    int i, k = 0;
    char temp[MAXSIZE];
    for (i = 0; i < strlen(str); i++) {
        if (!isVowel(str[i])) {
            temp[k++] = str[i];
        }
    }
    temp[k] = '\0';
    strcpy(str, temp);
}

void saveToFile(char str[], const char *filename) {
    FILE *fp = fopen(filename, "w");
    if (!fp) {
        printf("Error saving file.\n");
        return;
    }
    fprintf(fp, "%s", str);
    fclose(fp);
    printf("Processed text saved to %s\n", filename);
}

void loadFromFile(char str[], const char *filename) {
    FILE *fp = fopen(filename, "r");
    if (!fp) {
        printf("Error opening file.\n");
        return;
    }
    fgets(str, MAXSIZE, fp);
    fclose(fp);
    printf("Text loaded from %s\n", filename);
}
