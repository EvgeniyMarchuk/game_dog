#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int main()
{
    char mas[10][21];   //21 because we have 20 characters '#' and the string has a character '\0'
    int i;
    char key;
    int ox, oy;
    int apple_x = 5, apple_y = 3;
    int total = 0;
    int x = 10, y = 5;


    do
    {
        printf("Total: %d\n", total);
        sprintf(mas[0], "####################"); //here we are building a walls for our locations
        for(int j = 1; j < 9; j++)
        {
            sprintf(mas[j], "#                  #");
        }

        sprintf(mas[9], "####################");

        mas[y]      [x]       = '@';
        mas[apple_y][apple_x] = '*';

        for(int i = 0; i < 10; i++)
            printf("%s\n", mas[i]);

        if(total >= 10 && total < 20)
            printf("Beginner");
        else if (total >= 20 && total < 30)
            printf("COOL DUDE");
        else if(total >= 40 && total < 80)
            printf("AMAZING, you are profi!");
        else if(total >= 80)
            printf("Please, stop...");

        key = getch();

        int ox = x;
        int oy = y;

        if     (key == 'w') y--;
        else if(key == 's') y++;
        else if(key == 'a') x--;
        else if(key == 'd') x++;

        if(mas[y][x] == '#'){
            x = ox;
            y = oy;
        }

        if (x == apple_x && y == apple_y){
            apple_x = rand() % 19 + 1;    //here we are used multiply on 1.0 to /
            apple_y = rand() % 8 + 1;    //convert number returned by rand() in double
            total++;
        }

        system("cls");
    }
    while(key != 'e');
    return 0;
}
