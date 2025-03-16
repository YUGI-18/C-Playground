#include <stdio.h>
#include <string.h>
#include "Functions.h"

char theatre[10][10] = {""};
char theatremovie[10][10][10] = {""};
char seats[10][10][10][10][1] = {""};
int seatspos;
int theatre1;
char movie[10];
int movie1;
int availablemovie;
int availabletheatre;
char utheatre[10];

void addtheatre()
{
    int add;

    while (1)
    {
        printf("\nEnter the theatre name :");
        char temp[10];
        for (int i = 0; i <= 10; i++)
        {
            if (strlen(theatre[i]) == 0)
            {
                scanf("%s", &temp);
                for (int j = 0; j < 10; j++)
                {
                    if (!strcmp(theatre[j], temp))
                    {
                        printf("Theatre already exist !!!\n\n");
                        break;
                    }
                    else
                    {
                        strcpy(theatre[i], temp);
                        printf("-----Theatre Added Successfully-----\n\n");
                        availabletheatre++;
                        strcpy(temp, "");
                        printf("Now add seats for the theatre \n");
                        seatspos = i;

                        addseats();
                        break;
                    }
                }

                break;
            }
        }
        printf("\n1 to add another theatre\n2 to exit :");
        scanf("%d", &add);
        switch (add)
        {
        case 1:
            continue;
            ;

        case 2:
            break;
        }
        break;
    }
}
void addmovie()
{
    char temptheatre[10];

    if (availabletheatre == 0)
    {
        printf("\nFirst add a theatre to add movies !!!\n\n");
    }

    else
    {
        printf("\nIn Which theatre you want to add movies :");
        listalltheatre();
        int x = 0;
        int theatrepos;
        while (1)
        {
            scanf("%s", &temptheatre);
            for (int i = 0; i < 10; i++)
            {
                if (!strcmp(theatre[i], temptheatre))
                {
                    theatrepos = i;
                    while (1)
                    {
                        printf("Enter the movie name :");
                        char tempmovie[10];
                        for (int j = 0; j <= 10; j++)
                        {
                            if (strlen(theatremovie[theatrepos][j]) == 0)
                            {
                                scanf("%s", &tempmovie);
                                for (int k = 0; k < 10; k++)
                                {
                                    if (!strcmp(theatremovie[theatrepos][k], tempmovie))
                                    {
                                        printf("Movie already exist on this Theatre !!!\n\n");
                                        break;
                                    }
                                    else
                                    {
                                        strcpy(theatremovie[theatrepos][j], tempmovie);
                                        printf("-----Movie Added Successfully-----\n\n");
                                        availablemovie++;
                                        strcpy(tempmovie, "");
                                        break;
                                    }
                                }

                                break;
                            }
                        }
                        int add;
                        printf("1 to add another movie\n2 to exit :");
                        scanf("%d", &add);
                        switch (add)
                        {
                        case 1:
                            continue;
                            ;

                        case 2:
                            break;
                        }
                        break;
                    }
                    x++;
                    break;
                }
            }
            if (x == 0)
            {
                printf("Enter a valid theatre name :");
            }
            else
            {
                break;
            }
        }
    }
}
void addseats()
{
    memset(seats, '\0', sizeof(seats));
    int row;
    int column;

    printf("\nEnter no.of.rows of the seats :");
    scanf("%d", &row);
    printf("\nEnter no.of.columns of the seats :");
    scanf("%d", &column);
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < row; j++)
        {
            for (int k = 0; k < column; k++)
            {
                strcpy(seats[seatspos][i][j][k], "O");
            }
        }
    }
    printf("-----seats created successfully with %d rows and %d columns-----\n\n", row, column);
}

void printseats(int theatre1, int movie1)
{

    int x;

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (seats[theatre1][movie1][i][j][0] != '\0')
            {

                printf("| %c |", seats[theatre1][movie1][i][j][0]);
                x++;
            }
        }
        if (x != 0)
        {
            printf("\n");
            x = 0;
        }
    }
}

void bookseats(int theatre1, int movie1)
{
    int row;
    int column;
    int noofseats;

    printf("\nO -> Available Seats\nX -> Booked Seats\n");
    printseats(theatre1, movie1);
    printf("Enter no of seats to book :");
    scanf("%d", &noofseats);
    for (int i = 0; i < noofseats; i++)
    {
        while (1)
        {
            printf("Enter the row to book seat no %d:", i + 1);
            scanf("%d", &row);
            printf("\nEnter the column to book seat no %d:", i + 1);
            scanf("%d", &column);
            row--;
            column--;

            if (seats[theatre1][movie1][row][column][0]=='O')
            {
                seats[theatre1][movie1][row][column][0]='X';
                printf("-----Seat no %d booked successfully-----\n", i + 1);
                printseats(theatre1, movie1);
                break;
            }
            printf("This seat is already booked\nBook any other seat !!!\n\n");
        }
    }
    printf("-----%d Seats booked for ( %s ) Movie in the ( %s ) Theatre-----\n\n", noofseats, theatremovie[theatre1][movie1], theatre[theatre1]);
}
void listalltheatre()
{
    int i = 0;
    while (strlen(theatre[i]) != 0)
    {
        printf("%s , ", theatre[i]);

        i++;
    }
    printf("\n");
}
void listallmovies()
{
    char tempmovie[10][10] = {""};
    int x = 0;
    int y = 0;

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (strcmp(theatremovie[i][j], ""))
            {
                for (int k = 0; k < 10; k++)
                {
                    if (!strcmp(tempmovie[k], theatremovie[i][j]))
                    {
                        break;
                    }
                    else
                    {
                        printf("%s , ", theatremovie[i][j]);
                        strcpy(tempmovie[x], theatremovie[i][j]);
                        x++;
                        break;
                    }
                }
            }
        }
    }
    printf("\n");
}
void theatreselection()
{

    if (availabletheatre == 0)
    {
        printf("There is no theatre to View !!!\n\n");
    }

    else
    {
        printf("\nWhich theatre you want to book tickets\n");
        char temptheatre[10];
        int x = 0;
        int theatrepos;
        char tempmov[10];
        while (1)
        {
            scanf("%s", &temptheatre);
            for (int i = 0; i < 10; i++)
            {
                if (!strcmp(theatre[i], temptheatre))
                {
                    theatrepos = i;
                    theatre1 = i;
                    while (1)
                    {
                        printf("Which movie ticket you want to book\n");
                        listmovies(theatre1);
                        scanf("%s", &tempmov);
                        for (int i = 0; i < 10; i++)
                        {
                            if (!strcmp(theatremovie[theatre1][i], tempmov))
                            {
                                movie1 = i;
                                bookseats(theatre1, movie1);
                            }
                        }

                        break;
                    }
                    x++;
                    break;
                }
            }
            if (x == 0)
            {
                printf("enter a valid theatre name :");
            }
            else
            {
                break;
            }
        }
    }
}
void movieselection()
{
    if (availablemovie == 0)
    {
        printf("There is no movie to View !!!\n\n");
    }
    else
    {

        int x = 0;
        int moviepos;

        char temptheatre[10];
        while (1)
        {
            printf("\nWhich movie you want to Watch\n\n");
            scanf("%s", &movie);
            for (int i = 0; i < 10; i++)
            {
                for (int j = 0; j < 10; j++)
                {
                    if (!strcmp(theatremovie[i][j], movie))
                    {
                        x++;
                        printf("Theatre's that has %s running are:\n", movie);
                        listtheatre(movie);
                        printf("Which theatre you want to book Tickets\n\n");
                        scanf("%s", &utheatre);
                        for (int i = 0; i < 10; i++)
                        {
                            if (!strcmp(utheatre, theatre[i]))
                            {
                                theatre1 = i;
                            }
                        }
                        for (int i = 0; i < 10; i++)
                        {
                            if (!strcmp(movie, theatremovie[theatre1][i]))
                            {
                                movie1 = i;
                            }
                        }
                        bookseats(theatre1, movie1);

                        break;
                    }
                }
            }
            if (x == 0)
            {
                printf("enter a valid movie name !!! \n\n");
            }
            else
            {
                break;
            }
        }
    }
}
void listmovies(int theatre1)
{
    printf("\nMovies running in %s are \n", theatre[theatre1]);
    for (int i = 0; i < 10; i++)
    {
        if (strcmp(theatremovie[theatre1][i], ""))
        {
            printf("%s , ", theatremovie[theatre1][i]);
        }
    }
    printf("\n");
}
void listtheatre(char movie[10])
{
    char tempthea[10][10] = {""};

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (!strcmp(theatremovie[i][j], movie))
            {
                strcpy(tempthea[i], theatre[i]);
            }
        }
    }
    for (int i = 0; i < 10; i++)
    {
        if (strcmp(tempthea[i], ""))
        {
            printf("%s ,", tempthea[i]);
        }
    }
    printf("\n");
}
