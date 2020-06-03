#include "background.h"

/*image *createList(int size) {
    image *imageList = malloc(sizeof(image) * size);
    return(imageList);
}*/

/*image *fillList(image *imageList, FILE *file, int size) {
    char current[200];
    char c;
    int i, j, k;

    while (c = fgetc(file) != EOF) {
        if (c == '{') {
            while (c = fgetc(file) != '}') {
                j=0;
                if (c == '=') {
                    current[j] = c;
                } else {    
                    current[j] = '\0';
                    j++;
                }
                    
            }
            i++;
        }
    }

    for (i = 0; i < size; i++) {
        for (j = 0; j < 4; j++) {
            while (fgetc(file) != '{') {}

            k = 0;
            while ((c = fgetc(file)) != '}') {
                current[k] = c;
                k++;
            }
            current[k] = '\0';

            switch (j) {

                case 0:
                    imageList[i].number = atoi(c);
                case 1:
                    strcpy(imageList[i].imageName, current);
                case 2:
                    strcpy(imageList[i].imagePath, current);

            }

        }
    } 
} */

/*void trim(char *string) {
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
    }

    i = 0;
    while (string[i] != '\0') {
        i++;
    }
    i--;

    while (string[i] == ' ') {

        string[i] = '\0';
        i--;
    }

}*/

int randInt(int min, int max) {
    int r;

    srand(time(0));

    r = ((double)rand() / RAND_MAX) * (max - min) + min;

    return (r);
}

