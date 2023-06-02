
//I WANT TO PLAY WITH YOU
//        YOUR FRIEND, AI
#include <stdio.h>
//#include <stdlib.h>


#define WIDHT 80
#define HEIGHT 25
#define TOP 1
#define BOTTOM 24
#define LEFT 1
#define RIGHT 79
#define X_SLAB_1 1
#define X_SLAB_2 78
#define MID 39

//             -1
//              ^
//              |
//      -1 <-- ball --> +1
//              |
//              V
//             +1

void clearScreen(void);
void Screen_Resolution(int x_Ball, int y_Ball, int y_Slab_1, int y_Slab_2, int score_1, int score_2);
int mv_Ball(int *x_Ball, int *y_Ball, int y_Slab_1, int y_Slab_2, int *x_vector, int *y_vector);
void mv_Slap(int *y_Slab_1, int *y_Slab_2);

int main() {
    //system("stty eol ' '");
    int y_Slab_1 = 12,          y_Slab_2 = 12,
        x_Ball = MID,            y_Ball = 13,
        x_vector = 1,           y_vector = 1,
        score_1 = 0,            score_2 = 0,    score;
    while(score_1 < 21 || score_2 < 21){
        Screen_Resolution(x_Ball, y_Ball, y_Slab_1, y_Slab_2, score_1, score_2);
        mv_Slap(&y_Slab_1, &y_Slab_2);
        score = mv_Ball(&x_Ball, &y_Ball, y_Slab_1, y_Slab_2, &x_vector, &y_vector);
        if(score == 0)
            score_2 += 7; //// !!!!!
        else if (score == 1)
            score_1 += 3;  ///!!!1
       else if (score_1 == 21 || score_2 == 21) {
           
           break; }
        printf("\n");
        clearScreen();
    }
    if (score_1 >= 21)
        printf("Congratulations to Player 1 \n");
    if (score_2 >= 21)
        printf("Congratulations to Player 2 \n");
    return 0;
}

void mv_Slap(int *y_Slab_1, int *y_Slab_2){
    char command;
    scanf("%c", &command);
    switch (command){
        case 'a': (*y_Slab_1 != TOP) ? (*y_Slab_1 -= 1) : *y_Slab_1; break;
        case 'z': (*y_Slab_1 != BOTTOM - 3) ? (*y_Slab_1 += 1) : *y_Slab_1; break;
        case 'k': (*y_Slab_2 != TOP) ? (*y_Slab_2 -= 1) : *y_Slab_2; break;
        case 'm': (*y_Slab_2 != BOTTOM - 3) ? (*y_Slab_2 += 1) : *y_Slab_2; break;
    }
}

int mv_Ball(int *x_Ball, int *y_Ball, int y_Slab_1, int y_Slab_2, int *x_vector, int *y_vector){
    // Check GOLL!
    if(*x_Ball == LEFT && *x_vector == - 1){
        *x_Ball = MID;
        *y_Ball = 12;
        *y_vector = 1;
        *x_vector = 1;
        return 0;
    }
    if(*x_Ball == RIGHT && *x_vector)
    {
        *x_Ball = MID;
        *y_Ball = 12;
        *y_vector = 1;
        *x_vector = -1;
        return 1;
    }
    // Check wall
    if(*y_Ball == TOP && *y_vector == -1)
        *y_vector = *y_vector ? 1 : -1;
    if(*y_Ball == BOTTOM - 1 && *y_vector == 1)
        *y_vector = *y_vector ? -1 : 1;
    // Check Slab 1
    if((*x_Ball - X_SLAB_1) == 1 && (*y_Ball == y_Slab_1 || *y_Ball - 1 == y_Slab_1 || *y_Ball - 2 == y_Slab_1)  && *x_vector == -1)
        *x_vector = *x_vector ? 1 : -1;
    // Check Slab 2
    if((X_SLAB_2 - *x_Ball) == 1 && (*y_Ball == y_Slab_2 || *y_Ball - 1 == y_Slab_2 || *y_Ball - 2 == y_Slab_2)  && *x_vector == 1)
        *x_vector = *x_vector ? -1 : 1;

    *x_Ball += *x_vector;
    *y_Ball += *y_vector;
    return -1;
}

void Screen_Resolution(int x_Ball, int y_Ball, int y_Slab_1, int y_Slab_2, int score_1, int score_2){
    char bordline_vert = '|';
    char bordline_gor = '-';
    char ball = '*';
    char space = ' ';
    //if (score_1 == 21 || score_2 == 21) {
        
    //}
    for (int y = 0; y < HEIGHT; y++) // развертка по строкам
    {
        for (int x = 0; x < WIDHT; x++){ // развертка по столбцам
            // Отрисовка боковых границ
            if (x == 0){
                printf("%c", bordline_vert); //левой
            }
            else if (x == WIDHT-1){
                printf("%c\n", bordline_vert); // правой
            }
            // Отрисовка горизонтальных границ
            else if ((y == 0 || y == HEIGHT-1) && (x > 0 && x < WIDHT - 1)){
                    printf("%c", bordline_gor);
            }
            // Отрисовка плит
            else if (x == X_SLAB_1 && (y == y_Slab_1 || y == y_Slab_1 + 1 || y == y_Slab_1 + 2)){
                printf("%c", bordline_vert);
            }else if (x == X_SLAB_2 && (y == y_Slab_2 || y == y_Slab_2 + 1 || y == y_Slab_2 + 2)){
                printf("%c", bordline_vert);
            }
            // Отрисовка средней грани
            else if (x == MID){
                if(x_Ball == MID && y == y_Ball)
                    printf("%c", ball);
                else
                    printf("%c", bordline_vert);
            }
            // Отрисовка шарика
            else if (x == x_Ball && y == y_Ball){
                printf("%c", ball);
            }
            else
                printf("%c", space);
        }
    }
    for (int y = 0; y < 2; y++) // развертка по строкам
    {
        for (int x = 0; x < WIDHT; x++){// развертка по столбцам
            // Отрисовка боковых границ
            if (x == 0){
                printf("%c", bordline_vert);
            }else if (x == WIDHT-1){
                 printf("%c\n", bordline_vert);
            }else if(x == 9 && y == 0){
                    printf("Player 1");
            }else if (x == 40 && y == 0){
                printf("Player 2");
            }else if(x == 19 && y == 0){
                printf("%d", score_1);
            }else if (x == 50 && y == 0){
                printf("%d", score_2);
            }else if ((y == 1) && x >= 0 && (x < WIDHT - 1)){
                printf("%c", bordline_gor);
            }
           else if (y == 0 && x > 64 && x < 79 && score_2 < 10) {
            }
           else if (y == 0 && x > 63 && x < 79 && score_2 >= 10){}
           else if (y == 0 && x > 31 && x < 33 && score_1 >= 10){}
            else
                printf("%c", space);
        }
    }
}
void clearScreen(void) {
    printf("\33[0d\33[2J");
}

