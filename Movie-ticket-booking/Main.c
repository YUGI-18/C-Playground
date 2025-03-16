#include <stdio.h>
#include <string.h>
#include "Functions.h"

void admin();
void user();

void admin()
{
    while (1)
    {

        int var1;
        printf("\nWhat you want to do :\n");
        printf("1 to Add theatre\n2 to Add movie\n3 to exit :");
        scanf("%d", &var1);
        switch (var1)
        {
        case 1:
            addtheatre();
            continue;
        case 2:
            addmovie();
            continue;
        case 3:
            break;
        default:
            printf("Enter a valid input !!!\n\n");
            continue;
        }
        break;
    }
}
void user()
{
    while (1)
    {

        int var;
        printf("What you want to do :\n");
        printf("1 -> View Theatres\n2 -> View movies\n3 -> exit :");
        scanf("%d", &var);
        switch (var)
        {
        case 1:
            listalltheatre();
            theatreselection();
            continue;
        case 2:
            listallmovies();
            movieselection();
            continue;
        case 3:
            break;
        default:
            printf("Enter a valid input !!!\n\n");
            continue;
        }
        break;
    }
}

void main()
{

    printf("\n-----Welcome To Our Application-----\n\n");
    int var;
    while (1)
    {
        printf("-----Who are you ?-----\n\n");
        printf("Enter 1 if your a Admin\nEnter 2 if your a User\nEnter 3 if you want to Exit :");

        scanf("%d", &var);
        switch (var)
        {
        case 1:
            admin();
            continue;
        case 2:
            user();
            continue;
        case 3:
            break;
        default:
            printf("Enter a valid input !!!\n\n");
            continue;
        }
        printf("-----Thankyou Come Again-----\n\n");
        break;
    }
}
