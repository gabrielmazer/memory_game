#include <stdio.h>  
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <conio.h>
#include <string.h>

void gotoxy(int x, int y) {
    COORD pos = { x, y };
    HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(output, pos);
}

int SetColor (char color) {
  HANDLE h;
  h = GetStdHandle (STD_OUTPUT_HANDLE);
  return SetConsoleTextAttribute (h,color);
}

void presentation(){
    char c;
    system("color 00");
    printf("\033[32m        Let's start the memory game!\n\n");
    printf("        You need to memorize the numbers that will appear on the screen, you have 5 seconds.\n\n");
    printf("        Each time you hit the right number, you will earn 1 point and the game will be more difficult\n\n");
    printf("        Press ENTER to start the game\033[0m\n\n");
    do{c = getch();} while (c != 13);

}

void seconds(){
    int k;
    printf("\n\n");
    for(k = 5; k >= 0; k--){
       printf("\r%30.d", k);
       fflush(stdout);
       sleep(1);
    }
}

void levelA(){
    int i, j, posi = 10, count, answer, fail = 0, number[20];
    char c;
    presentation();
      count = 1;
      system ("cls");
      do{
        printf("        ======= ======= level A%d ======= =======\n\n", count);
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
                gotoxy(posi,5);
                printf("Correct!\n");
                posi += 10;
            }
            else{
                gotoxy(posi,4);
                printf("Wrong...");
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
        posi = 10;
        system("cls");
        count++;
    } while(fail != 1 && count < 2);
}


void levelB(){
    system("color 00");
    int i, j, position, count = 1, posi = 10, fail = 0;
    char c;
    char guess[15];
    printf("                \033[41m\033[30mWelcome to the level B!\n\n");
    printf("Now you need to memorize words that will appear on the screen, you have 5 seconds.\n\n");
    printf("Each time you hit the right word, you will earn 1 point and the game will be more difficult\n\n");
    printf("Press ENTER to start the game\033[0m\n\n");
    do{c = getch();} while (c != 13);
    system("cls");
    
    char word[23][15] = {"hardware", "computer", "network", "memory", "linux", "keyboard", "java"
    , "internet", "firewall", "encryption", "debug", "binary", "algorithm", "byte", "cache", "virus",
    "terminal", "software", "ram", "web", "xml", "json", "logic", "url"};
    
    SetColor (1);
    printf("        ======= ======= level B%d ======= =======\n\n", count);
    for(i = 0; i < count + 2; i++){
        position = rand() % 23;
        gotoxy(posi,3);
        printf("%s   ", word[position]);
        posi += 10;
    }
    seconds(SetColor (1));

    scanf("%d", &posi);
    for(i = 0; i < count + 2; i++){
        gotoxy(posi,3);
        fgets(guess, sizeof(guess), stdin);
        if (strcmp(guess, word[i]) == 0){
            gotoxy(posi,5);
            printf("Correct!\n");
            posi += 10;
        }
        else{
            gotoxy(posi,4);
            printf("Wrong...");
            i = count + 2;
            fail = 1; 
        }
    }

}


int main(){
    system("chcp 65001");
    srand(time(NULL));
    levelA();
    levelB();
}   