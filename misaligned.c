#include <stdio.h>
#include <assert.h>
#include <string.h>
#include "misaligned_test.h"

colorPairInfo testColorPair[MAX_COLOR_PAIR_POSSIBLE];

int printColorMap() {
    const char* majorColor[] = {"White", "Red", "Black", "Yellow", "Violet"};
    const char* minorColor[] = {"Blue", "Orange", "Green", "Brown", "Slate"};
    int i = 0, j = 0, testIdx = 0;
    for(i = 0; i < 5; i++) {
        for(j = 0; j < 5; j++) {
            printf("%d | %s | %s\n", i * 5 + j, majorColor[i], minorColor[i]);
            testColorPair[testIdx].pairNum = i * 5 + j;
            strncpy(testColorPair[testIdx].majorColor, majorColor[i], strlen(majorColor[i]));
            strncpy(testColorPair[testIdx].minorColor, minorColor[i], strlen(minorColor[i]));
        }
    }
    return i * j;
}

int main() {
    int result = printColorMap();
    assert(result == 25);
    
    assert(testColorPair[0].pairNum == 1);
    assert(strcmp(testColorPair[0].majorColor, "White") == 0);
    assert(strcmp(testColorPair[0].majorColor, "Blue") == 0);
    
    printf("All is well (maybe!)\n");
    return 0;
}
