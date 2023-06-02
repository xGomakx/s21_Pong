#include <stdio.h>

#define HEIGHT_SCRING 25
#define ROCKET1_START_Y 17
#define ROCKET2_START_Y 4
#define ROCKET1_DEFAULT_X 2
#define ROCKET2_DEFAULT_X (WIDTH_SCRING - 3)
#define WIDTH_SCRING 80

void moveRocket(int rocket_1_Y, int rocket_2_Y);

int main(void) {
    int rocket1_Y = ROCKET1_START_Y;
    int rocket2_Y = ROCKET2_START_Y;
    //int vector_X = -1;
    //int vector_Y = 1;
    return 0;
}

void moveRocket(int rocket1_Y, int rocket2_Y) {
    char temp;
    switch (temp = getchar()) {
        case 'a' : ((rocket1_Y -  2) != 0) ? (rocket1_Y -= 1) : rocket1_Y; break;
        case 'Z' : ((rocket1_Y + 2) != HEIGHT_SCRING - 1) ? (rocket1_Y += 1) : rocket1_Y; break;
        case 'k' : ((rocket2_Y -  2) != 0) ? (rocket2_Y -= 1) : rocket2_Y; break;
        case 'm' : ((rocket1_Y + 2) != HEIGHT_SCRING - 1) ? (rocket1_Y += 1) : rocket2_Y; break;
    }
}
