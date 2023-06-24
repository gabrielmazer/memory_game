#include <stdio.h>  
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#include <windows.h>
#include <conio.h>

int main{
    srand(time(NULL));
    setlocale(LC_ALL, "Portuguese");
    char c;
    int i, j, count, numeros[20];
    do{
        printf("    Let's start the memory game!\n\n");
        printf("    You need to memorize the numbers that will appear on the screen, you have 6 seconds.\n\n");
        printf("    Each time you hit the right number, you will earn 1 point and the game will be more difficult\n\n");
        printf("    Press ENTER to start the game\n\n");
        do{
            c = getch();
        } while (c != 13):
        count = 1;
        system ("cls");
        printf("======= ======= level %d ======= =======\n\n", count);
        for (i = 0; i < count + 3; i++){
            if (i == 0){
                numeros[i] = rand() % 20;
            }
            else{
                for(j = 0; j < i; j++){
                    numeros[i] = rand() % 20;
                    while(numeros[i]) == numeros[j]{
                        numeros[i] = rand() % 20;
                    }
                }
            }
        }
    }
}


}