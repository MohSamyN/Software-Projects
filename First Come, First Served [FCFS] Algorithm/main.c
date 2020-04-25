#include <stdio.h>
#include <stdlib.h>
#include "src.h"


int main()
{
    unsigned int Algorithm = 3;
    printf("\tRound Robin and First Come First Served Scheduling Algorithms\n");
    printf("\t=============================================================\n");
    GetData("Tasks.txt");
    while(Algorithm != 0)
    {
        printf("\nChoose the Required Algorithm (1: RR, 2: FCFS or 0: Terminate): ");
        scanf("%d", &Algorithm);
        if(Algorithm == 1)
        {
            printf("\n\t\t\tRound Robin Algorithm\n");
            printf("\t\t\t=====================\n");
            ProcessesTiming(Algorithm);
            Calculations(Algorithm);
        }
        else if(Algorithm == 2)
        {
            printf("\n\t\t\tFirst Come First Served Algorithm\n");
            printf("\t\t\t=================================\n");
            ProcessesTiming(Algorithm);
            Calculations(Algorithm);
        }
        else if(Algorithm == 0)
        {
            printf("\nEnd of Program.\n");
        }
        else
        {
            printf("Wrong Entry, Please Try Again.\n");
        }
    }
    return 0;
}
