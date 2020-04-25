#ifndef SRC_H_INCLUDED
#define SRC_H_INCLUDED

#define Processes_No           6 //number of processes  al global variables kolha mo3tmdeen 3leh mosh 3aref 23'iroh

#define OneTimeIO       0
#define MultipleTimeIO  1
#define IO_Selector     OneTimeIO


/* Global Variables */
unsigned int ArrivalInit[Processes_No];
unsigned int Arrival[Processes_No];
unsigned int TotalInit[Processes_No];
unsigned int Total[Processes_No];
unsigned int ElapsedInit[Processes_No];
unsigned int Elapsed[Processes_No];
unsigned int IO[Processes_No];
unsigned int IOInit[Processes_No];
unsigned int ProcessSort[Processes_No];

/* Functions' Declarations */
void GetData(char *FileName);
void ProcessesTiming(unsigned char Algorithm);
void Calculations(unsigned char Algorithm);

#endif // SRC_H_INCLUDED
