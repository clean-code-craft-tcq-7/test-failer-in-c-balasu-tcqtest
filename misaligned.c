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
        }
    }
}
void printColorMap() {
    int i = 0;
    for(i = 0; i < MAX_COLOR_PAIR_POSSIBLE; i++) {
        printf("%d | %s | %s\n", i * 5 + j, majorColor[i], minorColor[i]);
    }
}

int main() {
    
    createColorPair();
    int result = printColorMap();
    assert(result == 25);
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
