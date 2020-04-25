#include <stdio.h>
#include "src.h"


void GetData(char *FileName)
{
    unsigned char Count = 0;
    unsigned char Index = 0;
    unsigned char Loop = 0;
    unsigned int Number = 0;
    printf("Input Test Cases:\n");
    printf("----------------\n");
    printf("Process ID\tArrival Time\tTotal Time\tElapsed Time\tI/O Time\n");
    FILE *f;
    f = fopen(FileName, "r");// r--->read
    while(feof(f) == 0)//lma btwsl lel nhaya be t return  non zero
    {
        if(fgetc(f) == 'x')
        {
            break;
        }
        else
        {
            fscanf(f, "%d", &Number);
            if((Count % 6) == 0)
            {
                Index = Number;
                ProcessSort[Loop] = Index;//al update al gded 3mlt al index bta3 al process zie ma hwah fe al file
                Loop++;
            }
            else if((Count % 6) == 1)  // hwah 3momn bi discard al space
            {
                printf("P[%d]", Index);
                ArrivalInit[Index] = Number;
                printf("\t\t%d", ArrivalInit[Index]);
            }
            else if((Count % 6) == 2)
            {
                TotalInit[Index] = Number;
                printf("\t\t%d", TotalInit[Index]);
            }
            else if((Count % 6) == 3)
            {
                ElapsedInit[Index] = Number;
                printf("\t\t%d", Elapsed[Index]);
            }
            else if((Count % 6) == 4)
            {
                IOInit[Index] = Number;
                printf("\t\t%d\n", IOInit[Index]);
            }
            else
            {
            }
            Count++;
        }
    }
    fclose(f);//b2fel al file 7maya
    Number = 0;
    for(Loop = 0; Loop < Processes_No; Loop++)
    {
        ArrivalInit[ProcessSort[Loop]] += Number; //from time relative to time instant md5l m3aha al process sort -INCEPTION-
        Number = ArrivalInit[ProcessSort[Loop]];
    }
}

void ProcessesTiming(unsigned char Algorithm) //public
{
    unsigned char i;
    unsigned char j;
    unsigned char k;
    unsigned char l;
    unsigned int Time = 0;
    unsigned char ReadyQueue = 0;
    unsigned int Temp = 1;
    unsigned int Queue[30];
    for(i = 0; i < Processes_No; i++)
    {
        Arrival[i] = ArrivalInit[i];//copy array to keep a copy for later use
        Total[i] = TotalInit[i];
        IO[i] = IOInit[i];
        Elapsed[i] = ElapsedInit[i];
    }
    printf("Gant Chart:\n");
    printf("----------\n");
    printf("Start Time\tProcess ID\tEnd Time\n");
    if(Algorithm == 1)
    {
        i = 0;
        j = 0;
        k = 0;
        l = 0;
        while(Temp != 0)
        {
            Temp = 2;
            for(i = 0; i < Processes_No; i++)
            {
                if((Arrival[i] <= ReadyQueue) && (Total[i] != 0))
                {
                    Queue[j] = i;
                    j++;
                }
                else
                {
                }
            }
            if((Arrival[Queue[k]] <= Time) && (Total[Queue[k]] != 0))//time dh 2le hwah al time line
            {
                printf("%d\t", Time);
                if(Total[Queue[k]] > Temp) // al condition al tane 3shan mikonsh feh time bel negative lma 2tr7 al time left mn al elpased time
                {
                    Time += Temp;//hzwd al value bta3t al time line 23ml add 3leha al value bta3t al elapse we uupdate al value
                    Total[Queue[k]] -= Temp;
                    Arrival[Queue[k]] = Time;//h3ml update lel arrival time al gded b3d ma al process 5lst al IO
                    printf("\tP[%d]\t", Queue[k]);
                }
                else
                {
                    Time += Total[Queue[k]];//25r mra al process httnfz fh3ml update lel time line kolow 7ta wa7da mfish IO
                    Arrival[Queue[k]] = Time;
                    Total[Queue[k]] = 0;
                    printf("\tP[%d]*\t", Queue[k]);
                }
                printf("\t%d\n", Time);
                ReadyQueue = Arrival[Queue[k]];
                k++;
            }
            else
            {
            }            //}
            Temp = 0;
            for(i = 0; i < Processes_No; i++)
            {
                Temp += Total[i];//hfdl 23de 3la al array kolha low be zero kol element m3naha 2ne wslt lel nhaya we mfesh time left fh3ml break lel while loop 2tl3 fo2 23'ir al value bta3t al temp
            }
        }
    }
    else if(Algorithm == 2)
    {
        while(Temp != 0)
        {
            Temp = 65535;//3shan unsigned char 2kbr 7aga 65535
            for(i = 0; i < Processes_No; i++)
            {
                if(Arrival[i] < Temp)
                {
                    ReadyQueue = i;
                    Temp = Arrival[i];
                }
                else
                {
                }
            }
            for(i = ReadyQueue; i < Processes_No; i++)
            {
                if((Arrival[i] <= Time) && (Total[i] != 0))//time dh 2le hwah al time line
                {
                    printf("%d\t", Time);
                    if(((Elapsed[i] > 0) || (IO[i] > 0)) && (Total[i] > Elapsed[i])) // al condition al tane 3shan mikonsh feh time bel negative lma 2tr7 al time left mn al elpased time
                    {
                        Time += Elapsed[i];//hzwd al value bta3t al time line 23ml add 3leha al value bta3t al elapse we uupdate al value
                        Total[i] -= Elapsed[i];
                        Arrival[i] = Time + IO[i];//h3ml update lel arrival time al gded b3d ma al process 5lst al IO
                        printf("\tP[%d]\t", i);
                    }
                    else
                    {
                        Time += Total[i];//25r mra al process httnfz fh3ml update lel time line kolow 7ta wa7da mfish IO
                        Arrival[i] = Time;
                        Total[i] = 0;
                        printf("\tP[%d]*\t", i);
                    }
                    printf("\t%d\n", Time);
                    #if IO_Selector == OneTimeIO//select mode al code al 2deem aw al code al gded
                    Elapsed[i] = 0;
                    IO[i] = 0;
                    #endif // IO_Selector
                    break;
                }
                else
                {
                }
            }
            if(i >= Processes_No)
            {
                printf("%d\t", Time); //3shan 2zpot al free time al cpu mosh la2e 2ie process
                printf("\tFree\t");
                Time++;
                printf("\t%d\n", Time);
            }
            else
            {
            }
            Temp = 0;
            for(i = 0; i < Processes_No; i++)
            {
                Temp += Total[i];//hfdl 23de 3la al array kolha low be zero kol element m3naha 2ne wslt lel nhaya we mfesh time left fh3ml break lel while loop 2tl3 fo2 23'ir al value bta3t al temp
            }
        }
    }
    else
    {
    }
}

void Calculations(unsigned char Algorithm)
{
    unsigned char i;
    unsigned char Turnaround[Processes_No];
    unsigned char Waiting[Processes_No];
    float TurnaroundAverage = 0;
    float WaitingAverage = 0;
    printf("\nTurnaround and Waiting Time Calculations:\n");
    printf("----------------------------------------\n");
    printf("Process ID\tTurnaround\tWaiting\n");
    for(i = 0; i < Processes_No; i++)
    {
        printf("P[%d]", i);
        if(Algorithm == 1)
        {
            Turnaround[i] = (Arrival[i] - 2) - ArrivalInit[i];//arrival dh fe al 25er b2a al completion time - arrival time al 2sase
            Waiting[i] = Turnaround[i] - TotalInit[i];//lazem 2tr7 al IO 3shan mosh h3tbr al io waiting
        }
        else if(Algorithm == 2)
        {
            Turnaround[i] = Arrival[i] - ArrivalInit[i];//arrival dh fe al 25er b2a al completion time - arrival time al 2sase
            Waiting[i] = Turnaround[i] - (TotalInit[i] + IOInit[i]);//lazem 2tr7 al IO 3shan mosh h3tbr al io waiting
        }
        else
        {
        }
        printf("\t\t%d", Turnaround[i]);
        TurnaroundAverage += Turnaround[i];
        printf("\t\t%d\n", Waiting[i]);
        WaitingAverage += Waiting[i];
    }
    TurnaroundAverage /= Processes_No;
    WaitingAverage /= Processes_No;
    printf("----------------------------------------\n");
    printf("Average Turnaround Time\t\t%f\n", TurnaroundAverage);
    printf("Average Waiting Time\t\t%f\n", WaitingAverage);
}

