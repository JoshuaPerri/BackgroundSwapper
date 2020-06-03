#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


typedef struct imageData {
    int num;
    int type;                // 1 = .png   2 = .jpg
    char imageName[100];
    char imagePath[200];
} image;

int randInt(int, int);