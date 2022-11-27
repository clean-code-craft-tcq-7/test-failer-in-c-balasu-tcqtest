#include <stdio.h>
#include <assert.h>
#include <string.h>
#include "misaligned_config.h"

#ifdef UNIT_TEST
colorPairInfo testColorPair[MAX_COLOR_PAIR_POSSIBLE];
#endif

const char* majorColor[] = {"White", "Red", "Black", "Yellow", "Violet"};
const char* minorColor[] = {"Blue", "Orange", "Green", "Brown", "Slate"};

int printColorMap() {

    int i = 0, j = 0, testIdx = 0;
    for(i = 0; i < 5; i++) {
        for(j = 0; j < 5; j++) {
            printf("%d | %s | %s\n", i * 5 + j, majorColor[i], minorColor[i]);
#ifdef UNIT_TEST
            testColorPair[testIdx].pairNum = i * 5 + j;
            testColorPair[testIdx].majorColor = majorColor[i];
            testColorPair[testIdx].minorColor = minorColor[i];
            testIdx++;
#endif
        }
    }
    return i * j;
}

int main() {
    int result = printColorMap();
    assert(result == 25);
    // Similary all pairs shall be evaluated using the testColorPair variable
    //assert(testColorPair[0].pairNum == 1);
    assert(strcmp(testColorPair[0].majorColor, "White") == 0);
    assert(strcmp(testColorPair[0].minorColor, "Blue") == 0);
    
    assert(strcmp(testColorPair[0].majorColor, "White") == 0);
    assert(strcmp(testColorPair[0].minorColor, "Orange") == 0);
    
    printf("All is well (maybe!)\n");
    return 0;
}
