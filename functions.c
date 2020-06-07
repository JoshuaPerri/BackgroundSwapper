#include "background.h"

// Generates a random integer between min and max
int randInt(int min, int max) {
    int r;

    srand(time(0));

    r = ((double)rand() / RAND_MAX) * (max - min) + min;

    return (r);
}

// 
void controller() {
    int choice, size;
    FILE *file = fopen("data", "r");
    image *imageList;

    if (file == NULL) {
        exit(0);
    }

    size = getSize(file);
    imageList = createList(size);
    fillList(imageList, file, size);

    fclose(file);



    printf("Welcome to background picker!\n");

    printf("\n");
    printf("Please type the number for the option you want:\n");
    printf("1. Pick a background\n");
    printf("2. Add a background\n");
    //printf("3. Cycle backgrounds\n");

    while (TRUE) {
        fscanf(stdin, "%d", &choice);

        if ((choice >= 1) && (choice <= 2)) {
            break;
        }

        printf("That number is not an option, try again:");

    }

    switch(choice) {
        case 1:
            pickBackground(imageList, size);
            break;
        case 2:
            addBackground(imageList, size);
            break;
        default:
            break;
    }

    free(imageList);

}

// Controls the pick background option
void pickBackground(image *imageList, int size) {
    char scriptPath[200] = "./changeScript ";
    int choice;

    printf("The available backgrounds are:\n");
    printAll(imageList, size);
    printf("Please enter the number of the image you want:");

    while (TRUE) {
        fscanf(stdin, "%d", &choice);

        if ((choice >= 1) && (choice <= size)) {
            choice--;
            break;
        }

        printf("That number is not an option, try again:");

    }
    strcat(scriptPath, imageList[choice].path);

    printf("%s\n", scriptPath);

    system(scriptPath);

}

// Prints all the images in the list
void printAll(image *imageList, int size) {
    for (int i = 0; i < size; i++) {
        printf(" %d - %s\n", imageList[i].num, imageList[i].path);
    }
}

// Controls the add background option
void addBackground(image *imageList, int size) {
    char imageName[200];
    FILE *file;
    printf("Please enter the exact name of the image you want to add:\n");
    fscanf(stdin, "%s", imageName);
    file = fopen("data", "a");

    if (file == NULL) {
        exit(0);
    }

    fprintf(file, "\n%d, %s", size+1, imageName);
    printf("Please add the file to the image folder\n");

    fclose(file);

}