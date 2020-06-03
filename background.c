#include "background.h"

int main () {
    int randNum = randInt(1, 3);
    char scriptPath[200] = "~/Background/changeScript ";
    char picturePath[200] = "~/Background/Images/";
    int i = 0;

    while (picturePath[i] != '\0') {
        i++;
    }
    picturePath[i] = randNum + '0';
    picturePath[i+1] = '\0';

    strcat(picturePath, ".jpg");

    strcat(scriptPath, picturePath);

    printf("%s\n", scriptPath);

    system(scriptPath);

    return(0);
}