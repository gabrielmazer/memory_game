#include <stdio.h> 
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <conio.h>
#include <string.h>
//------------------------------------------------------------------------------------------------------
void gotoxy(int x, int y) {
    COORD pos = { x, y };
    HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(output, pos);
}
//------------------------------------------------------------------------------------------------------
int SetColor (char color) {
  HANDLE h;
  h = GetStdHandle (STD_OUTPUT_HANDLE);
  return SetConsoleTextAttribute (h,color);
}
//------------------------------------------------------------------------------------------------------
void reprocessing(int lifes, int level){
    char c;
    do{
        gotoxy(8,6);
        printf("Press: <ENTER> to use one life and keep at this level"
                " | <F1> to go back to beginning | <ESC> to quit");
        c = getch();
    } while(c != 13 && c != 27 && c != 59);
    if (c == 13){
        if(lifes > 0){
            switch(level){
                case 2: system("cls");
                        levelB(lifes);
                        break;
            }
        }
        else{
            gotoxy(10,8);
            printf("You run out of lifes! Press <ESC> to quit or <F1> to start over");
            do{
                c = getch();
            } while (c != 27 && c != 59);
            if (c == 27)
                exit(0);
            else{
                system("cls");
                main();
            }
        }
   }
}

//------------------------------------------------------------------------------------------------------

void presentation(int op){
    char level, w[1][10], c;
    switch(op){
        case 1: level = 'A';
                strcpy(w[0], "numbers");
                system("color 01");
                break;
        case 2: level = 'B';
                strcpy(w[0], "words");
                system("color 17");
                break;
        case 3: level = 'C';
                strcpy(w[0], "especials");
                system("color 20");
                break;
    }
    system("color 00");
    printf("        Welcome to level %c!\n\n", level);
    printf("        You need to memorize the %s that will appear on the screen, you have 5 seconds.\n\n", w[0]);
    printf("        Each time you hit the right %s, you will earn 1 point and the game will be more difficult\n\n", w[0]);
    printf("        Press ENTER to start the game or ESC to exit");
    do{c = getch();} while (c != 13 && c != 27);
    if (c == 27){
        printf("Are you sre you want to exit? You will lose your progress");
        c = getch();
        if(c == 27)
            exit(0);
    }
    system("cls");
    fflush(stdout);

}
//------------------------------------------------------------------------------------------------------
void seconds(){
    int k;
    printf("\n\n");
    for(k = 5; k >= 0; k--){
       printf("\r%30.d", k);
       fflush(stdout);
       sleep(1);
    }
}
//------------------------------------------------------------------------------------------------------

void levelA(int lifes, int *points){
    int i, j, fail = 0, posi = 10, count, answer, number[20];
    char c;
    presentation(1);
      count = 1;
      system ("cls");
      do{
        printf("        ======= ======= level A%d ======= =======\n\n\n", count);
        for (i = 0; i < count + 2; i++){
            if (i == 0){
                number[i] = rand() % 20;
            }
            else{
                for(j = 0; j < i; j++){
                number[i] = rand() % 20;
                while(number[i] == number[j] || number[i] == 0)
                    number[i] = rand() % 20;
                }
            }
            printf("%10.d", number[i]);
        }
        seconds();
        system("cls");
        printf("        ======= ======= level A%d ======= =======\n\n", count);
        for(i = 0; i < count + 2; i++){
            gotoxy(posi,3);
            scanf("%d", &answer);
            if(answer == number[i]){
                gotoxy(posi,4);
                printf("Correct!\n");
                posi += 10;
                (*points)++;
            }
            else{
                gotoxy(posi,4);
                printf("Wrong ;(");
                gotoxy(posi,5);
                printf("The correct answer was %d\n\n", number[i]);
                i = count + 2;
                fail = 1;
                lifes--;
                reprocessing(lifes, 1);
            }
        }
        fflush(stdout);
        posi = 10;
        system("cls");
        count++;
    } while(fail != 1 && count < 2);
}




void levelB(int lifes, int *points){
    int i, position[20], result, count = 1, posi = 10, fail = 0;
    char guess[15];
    presentation(2);
    system("cls");
    char c, word[23][15] = {"hardware", "computer", "network", "memory", "linux", "keyboard", "java"
    , "internet", "firewall", "encryption", "debug", "binary", "algorithm", "byte", "cache", "virus",
    "terminal", "software", "ram", "web", "xml", "json", "logic", "url"};
    do{
        printf("        ======= ======= level B%d ======= =======\n\n", count);
        for(i = 0; i < count + 2; i++){
            position[i] = rand() % 23;
            gotoxy(posi,3);
            printf("%s     ", word[position[i]]);
            posi += 10;
        }
        seconds();
        system("cls");
        printf("        ======= ======= level B%d ======= =======\n\n", count);
        posi = 10;
        for(i = 0; i < count + 2; i++){
            gotoxy(posi,3);
            scanf("%s", guess);
            result = stricmp(guess, word[position[i]]);
            if (result == 0){
                gotoxy(posi,4);
                printf("Correct!\n");
                posi += 10;
                (*points)++;
            }
            else{
                gotoxy(posi,4);
                printf("Wrong ;(");
                gotoxy(posi,5);
                printf("The correct answer was %s\n", word[position[i]]);
                i = count + 2;
                fail = 1;
                lifes--;
                reprocessing(lifes, 2);
            }
        }
        fflush(stdout);
        posi = 10;
        system("cls");
        count++;
    } while (fail != 1 && count < 2);
}

void levelC(){
    presentation(3);
    int i, n, fail = 0, count = 1, posi = 10;
    int position[24];
    char c, especial[24][15] = {"<ESC>", "<ENTER>", "F1", "F2", "F3", "F4", "F5", "F6"
    ,                        "F7", "F8", "!", "&", "*", ")", "?", "#", "+", "=", ":", ";", "$", "[", "]", ">", "<"};
    int  esp[24] = {27, 13, 59, 60, 61, 62, 63, 64, 65, 66, 33, 38, 42, 41, 63, 35, 43, 61, 58, 36
    ,91, 93, 62, 60};
    char guessC[24];
    do{
        printf("        ======= ======= level C%d ======= =======\n\n", count);
        for(i = 0; i < count + 2; i++){
            position[i] = rand() % 23;
            gotoxy(posi,3);
            printf("%s     ", especial[position[i]]);
            posi += 10;
        }
        seconds();
        system("cls");
        printf("        ======= ======= level C%d ======= =======\n\n", count);
        posi = 10;
        for(i = 0; i < count + 2; i++){
            gotoxy(posi,3);
            guessC[i] = getch();
            if(guessC[i] <= 0)
                guessC[i] = getch();
            if (guessC[i] == esp[position[i]]){
                printf("%s", especial[position[i]]);               
                gotoxy(posi,5);
                printf("Correct!\n");
                posi += 10;
            }
            else{
                gotoxy(posi,5);
                printf("You type wrong, the right asnwer was %s ", especial[position[i]]);
                i = count + 2;
                fail = 1;
                do{
                    gotoxy(8,6);
                    printf("Press ENTER to start again or ESC to exit\n ");
                    c = getch();
                } while(c != 13 && c != 27);
                if (c == 13){
                    count = 0;
                    fail = 0;
                }
            }
        }
        fflush(stdout);
        posi = 10;
        system("cls");
        count++;

    } while (fail != 1 && count < 5);
}


int main(){
    int lifes = 3, points = 0;
    srand(time(NULL));
    levelA(lifes, &points);
    levelB(lifes, &points);
    printf("you have %d points", points);
    levelC(lifes);
}   