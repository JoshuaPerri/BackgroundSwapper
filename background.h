#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LINE 200

#define FALSE 0
#define TRUE 1

typedef struct imageData {
    int num;
    char path[200];
} image;

int randInt(int, int);
void controller();
void pickBackground(image*, int);
void printAll(image*, int);
void addBackground(image*, int);

image *createList(int);
int getSize(FILE*);
void fillList(image*, FILE*, int);
int getLine(char*, FILE*);
int getNum(char*);
void chopFront(char*); 
void trim(char*);