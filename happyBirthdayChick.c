/*
 * Written with love by telekobold for schauerstoff
 * 
 * The MIT License (MIT)
 * 
 * (c) 2020 Michael Merz <mail@telekobold.de> 
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#ifdef linux
#include <unistd.h>
#define SLEEP usleep(250000)
#define CLEAR "clear"
#elif _WIN32
#include <windows.h>
#define SLEEP Sleep(500)
#define CLEAR "cls"
#endif

// MAX_DISTANCE: The maximum way the chick walks on the screen; should be matched on the screen width.
#define MAX_DISTANCE 80
// MAX_WISHES: The maximum number of withes the chick says on a single walk; should be matched to MAX_DISTANCE.
#define MAX_WISHES 6
#define WISH_DISPLAY_DURATION 6 // should be matched to MAX_DISTANCE


// char arrays for a chick without a speech bubble:
const char *c_0 = "    _---_\n\0";
const char *c_1 = "   / o__o\\\n\0";
const char *c_2 = "   \\  \\/ /\n\0";
const char *c_3 = "___/     \\_\n\0";
const char *c_4 = "\\-         )\n\0";
const char *c_5 = " \\        /\n\0";
const char *c_6 = "  \\______/\n\0";
const char *c_7 = "   |    | \n\0";
const char *c_8 = "  /|\\  /|\\\n\0";

// char arrays for a chick with a "piiiep" speech bubble:
// (cs1 = "chick with speech bubble 1")
const char *cs1_0 = "    _---_     ______\n\0";
const char *cs1_1 = "   / o__o\\  /        \\\n\0";
const char *cs1_2 = "   \\  \\/ / <  piiiep! |\n\0";
const char *cs1_3 = "___/     \\_ \\ ______ /\n\0";
const char *cs1_4 = "\\-         )\n\0";
const char *cs1_5 = " \\        /\n\0";
const char *cs1_6 = "  \\______/\n\0";
const char *cs1_7 = "   |    | \n\0";
const char *cs1_8 = "  /|\\  /|\\\n\0";

// char arrays for a chick with a "happy birthday" speech bubble:
// (cs2 = "chick with speech bubble 2")
const char *cs2_0 = "    _---_     _________________________________\n\0";
const char *cs2_1 = "   / o__o\\  /                                   \\\n\0";
const char *cs2_2 = "   \\  \\/ / <  Happy birthday, schauerstoffi <3   |\n\0";
const char *cs2_3 = "___/     \\_ \\ _________________________________ /\n\0";
const char *cs2_4 = "\\-         )\n\0";
const char *cs2_5 = " \\        /\n\0";
const char *cs2_6 = "  \\______/\n\0";
const char *cs2_7 = "   |    | \n\0";
const char *cs2_8 = "  /|\\  /|\\\n\0";

        
// printArr: Prints all the content of a char array ("a string").
void printArr(const char *arr){
    for(; *arr != '\0'; arr++){
        putchar(*arr);
    }
}

// spaces: Returns a char array ("a string") consisting of distance spaces.
void spaces(const unsigned distance){
    for(unsigned i = 0; i < distance; i++){
        putchar(' ');
    }
}

// chickWithoutSpeechBubble: Prints a chick without speech bubble with distance to the left side of the screen.
void chickWithoutSpeechBubble(const unsigned distance){
    spaces(distance);
    printArr(c_0);
    spaces(distance);
    printArr(c_1);
    spaces(distance);
    printArr(c_2);
    spaces(distance);
    printArr(c_3);
    spaces(distance);
    printArr(c_4);
    spaces(distance);
    printArr(c_5);
    spaces(distance);
    printArr(c_6);
    spaces(distance);
    printArr(c_7);
    spaces(distance);
    printArr(c_8);
}

// chickWithSpeechBubble1: Prints a chick with a "piiiep" speech bubble with distance to the left side of the screen.
void chickWithSpeechBubble1(const unsigned distance){
    spaces(distance);
    printArr(cs1_0);
    spaces(distance);
    printArr(cs1_1);
    spaces(distance);
    printArr(cs1_2);
    spaces(distance);
    printArr(cs1_3);
    spaces(distance);
    printArr(cs1_4);
    spaces(distance);
    printArr(cs1_5);
    spaces(distance);
    printArr(cs1_6);
    spaces(distance);
    printArr(cs1_7);
    spaces(distance);
    printArr(cs1_8);
}

// chickWithSpeechBubble2: Prints a chick with a "happy birthday" speech bubble with distance to the left side of the screen.
void chickWithSpeechBubble2(const unsigned distance){
    spaces(distance);
    printArr(cs2_0);
    spaces(distance);
    printArr(cs2_1);
    spaces(distance);
    printArr(cs2_2);
    spaces(distance);
    printArr(cs2_3);
    spaces(distance);
    printArr(cs2_4);
    spaces(distance);
    printArr(cs2_5);
    spaces(distance);
    printArr(cs2_6);
    spaces(distance);
    printArr(cs2_7);
    spaces(distance);
    printArr(cs2_8);
}

// randNumGen: Fills randNumbers with randNumbersSize random numbers between lower and upper.
void randNumGen(const unsigned lower, const unsigned upper, unsigned *randNumbers, const unsigned randNumbersSize){
    srand((unsigned) time(0)); // Seed rand()'s random number generator using the current UNIX system time in milliseconds (on UNIX systems).
    for(unsigned i = 0; i < randNumbersSize; i++){
        // Generate a number between lower and upper and add it to the current index position in randNumbers:
        randNumbers[i] = (rand() % (upper - lower + 1)) + lower;
    }
}

// contains: returns 1 if numbers contains number, 0 otherwise.
unsigned contains(const unsigned *numbers, const unsigned numbersSize, const unsigned number){
    for(unsigned i = 0; i < numbersSize; i++){
        if(numbers[i] == number){
            return 1;
        }
    }
    return 0;
}


// Makes a chick walk horizontally across the screen, saying "piiiep" and wishing schauerstoffi a happy birthday <3
int main(void){
    
    const unsigned randNumbersLength = MAX_WISHES * 2;
    unsigned randNumbers[randNumbersLength];
    unsigned alternateWithesCounter = 1;
    unsigned entered = 0;
    unsigned displayDurationCounter = 0;
    
    while(1){
        randNumGen(0, MAX_DISTANCE, randNumbers, MAX_WISHES); // Re-fill randNumbers with new random numbers
        
        for(unsigned distance = 0; distance < MAX_DISTANCE; distance++){
            // Show each wish WISH_DISPLAY_DURATION walk steps long.
            if(!entered && contains(randNumbers, MAX_WISHES, distance)){
                entered = 1;
                // Show the two withes ("piiiep" and "happy birthday") in alternate order.
                if(alternateWithesCounter == 0){
                    alternateWithesCounter = 1;
                } else {
                    alternateWithesCounter = 0;
                }
            }
            if(entered && displayDurationCounter < WISH_DISPLAY_DURATION){
                if(alternateWithesCounter == 0){
                    chickWithSpeechBubble1(distance);
                } else {
                    chickWithSpeechBubble2(distance);
                }
                displayDurationCounter++;
            } else {
                chickWithoutSpeechBubble(distance);
                entered = 0;
                displayDurationCounter = 0;
            }
            SLEEP;
            system(CLEAR);
        }
    }

    return 0;
}
