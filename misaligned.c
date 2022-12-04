#include <stdio.h>
#include <assert.h>
#include <string.h>
#include "misaligned_config.h"

colorPairInfo colorPairData[MAX_COLOR_PAIR_POSSIBLE];

const char* majorColor[] = {"White", "Red", "Black", "Yellow", "Violet"};
const char* minorColor[] = {"Blue", "Orange", "Green", "Brown", "Slate"};

void createColorPair(void)
{
    int i = 0, j = 0;
    int dataIdx = 0;
    for(i = 0; i < 5; i++) {
        for(j = 0; j < 5; j++) {
            colorPairData[dataIdx].pairNum = (i * 5 + j) + 1;
            strcpy(colorPairData[dataIdx].majorColor, majorColor[i]);
            strcpy(colorPairData[dataIdx].minorColor, minorColor[j]);
            dataIdx++;
        }
    }
}

void formatColorPairString(char* colorPairStrBuff, int pairIdx)
{
    memset(colorPairStrBuff, 0, 50);
    char spaceAftrPairNum[5];
    if(colorPairData[pairIdx].pairNum < 10)
    {
        strcpy(spaceAftrPairNum,"  | ");
    }
    else
    {
        strcpy(spaceAftrPairNum ," | ");
    }

    sprintf(colorPairStrBuff, "%d%s%-6s | %s",colorPairData[pairIdx].pairNum,spaceAftrPairNum,colorPairData[pairIdx].majorColor, colorPairData[pairIdx].minorColor);
}
       
void printColorMap() {
    int i = 0;
    char colorPairStrBuff[50];
    for(i = 0; i < MAX_COLOR_PAIR_POSSIBLE; i++) {
        formatColorPairString(colorPairStrBuff, i);
        printf("%s\n", colorPairStrBuff);
    }
}

int main() {
    
    createColorPair();
    printColorMap();
    // Simivlary all pairs shall be evaluated using the testColorPair variable
    assert(colorPairData[0].pairNum == 1);
    assert(strcmp(colorPairData[0].majorColor, "White") == 0);
    assert(strcmp(colorPairData[0].minorColor, "Blue") == 0);
    assert(colorPairData[1].pairNum == 2);
    assert(strcmp(colorPairData[1].majorColor, "White") == 0);
    assert(strcmp(colorPairData[1].minorColor, "Orange") == 0);
    
    printf("All is well (maybe!)\n");
    return 0;
}
