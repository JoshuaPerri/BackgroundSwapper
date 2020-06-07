#include "background.h"

// Creates a list
image *createList(int size) {
    image *imageList = malloc(sizeof(image) * size);
    return(imageList);
}


// Gets the number of images in the file
int getSize(FILE *file) {
    char c;
    int i;

    i = 0;
    while ((c = fgetc(file)) != EOF) {
        if (c == '\n') {
            i++;
        }
    }
    i++;

    rewind(file);
    return(i);

}


// Fills the list with the information in the file
void fillList(image *imageList, FILE *file, int size) {
    char line[MAX_LINE];

    for (int i = 0; i < size; i++) {

        getLine(line, file);
        imageList[i].num = getNum(line);

        chopFront(line);
        trim(line);
        strcpy(imageList[i].path, line);

    }

}


// Gets a new line from the file
int getLine(char *string, FILE *file) {
    char c;
    int i;

    i = 0;
    c = fgetc(file);
    while ((c != '\n') && (c != EOF) && (i < 199)) {

        string[i] = c;

        i++;
        c = fgetc(file);
    }
    string[i] = '\0';


    if (c == '\n') {
        return(0);
    } else if (c == EOF) {
        return(1);
    } else {
        return(2);
    }
}


// Gets the number at the start of a line
int getNum(char *line) {
    int i, num, multiplier;

    i = 0;
    while (line[i] >= '0' && line[i] <= '9') {
        i++;
    }
    i--;

    multiplier = 1;
    num = 0;
    for (int j = i; j >= 0; j--) {
        num += (line[j] - '0') * multiplier;
        multiplier *= 10;
    }

    return(num);

}


// Removes the number from the start of the line, leaving only the file name
void chopFront(char *string) {
    int n, i;

    n = 0;
    while (string[n] != ' ') {
        n++;
    }

    i = 0;
    while (string[i + n] != '\0') {
        string[i] = string[i + n];
        i++;
    }
    string[i] = '\0';

}


// Trims spaces from the file name
void trim(char *string) {
    int i, j;

    i = 0;
    while (string[i] == ' ') {
        j = 0;
        while (string[j+1] != '\0') {
            string[j] = string[j+1];
            j++;
        }
        i++;
    }
    string[j] = '\0';


    i = 0;
    while (string[i] != '\0') {
        i++;
    }
    i--;

    while (string[i] == ' ') {
        string[i] = '\0';
        i--;
    }

}