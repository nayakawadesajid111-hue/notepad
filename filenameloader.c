#include <stdio.h>
#include "filenameloader.h"

void savefilenameToFile(FileList*notepad)
{
    FILE *fptr;
    fptr = fopen("savedfilenames.txt", "w");
    fprintf(fptr, "%d\n",notepad->filecount);
    for (int i = 0; i < notepad->filecount; i++)
    {
        fprintf(fptr, "%s\n", notepad->files[i].name_of_file);
    }
    fclose(fptr);
}

void loadfilenameFromFile(FileList*notepad)
{
    FILE *fptr;
    fptr = fopen("savedfilenames.txt", "r");
    fscanf(fptr, "%d\n", &notepad->filecount);
    for (int i = 0; i <notepad->filecount;i++)
    {
        fscanf(fptr,"%[^\n]\n",notepad->files[i].name_of_file);
    }
    if(fptr == NULL)
    {
        printf("File not available\n");
        return ;
    }
    fclose(fptr);
}
