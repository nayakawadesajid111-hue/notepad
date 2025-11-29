#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "file.h"
#include "filenameloader.h"

void initialize(FileList *notepad)
{
    notepad->filecount = 0;
    loadfilenameFromFile(notepad);
}
void saveAndExit(FileList *notepad)
{
    savefilenameToFile(notepad); // Save contacts to file
    exit(EXIT_SUCCESS);          // Exit the program
}

int namecheck(char *filename, FileList *notepad)
{
    for (int i = 0; i < notepad->filecount; i++)
    {
        if (strcmp(filename, notepad->files[i].name_of_file) == 0)
        {
            return 1;
        }
    }
    return 0;
}
void createnewfile(FileList *notepad)
{
    char filename[50];
    int check = -1;
    do
    {
        printf("Enter the file name : ");
        scanf(" %49[^\n]", filename);
        // check extention present or not
        char exstr[] = ".txt";
        char *ptr = strstr(filename, exstr);
        if (ptr == NULL)
        {
            printf("Added default extention(.txt)\n");
            strcat(filename, exstr);
        }
        check = namecheck(filename, notepad);

    } while (check == 1);

    FILE *fp = fopen(filename, "w");
    if (fp == NULL)
    {
        printf("Mermory not available use\n");
        return;
    }
    printf("_________________________________________________________________________\n");
    getchar();

    int ch;
    while (1)
    {

        ch = getchar();

        if (ch == 27)
        { // ESC key
            break;
        }

        fputc(ch, fp); // write character to file
    }
    printf("_________________________________________________________________________\n");

    fclose(fp);

    char save;
    printf("Do you want save file : ");
    scanf(" %c", &save);
    if (save == 'y' || save == 'Y')
    {
        strcpy(notepad->files[notepad->filecount].name_of_file, filename);
        printf("%s\n", notepad->files[0].name_of_file);
        (notepad->filecount)++;
        printf("changes saved\n");
    }
    else
    {
        char confirm;
        printf("Are you sure ?\n ");
        scanf(" %c", &confirm);
        if (confirm == 'y' || confirm == 'Y')
        {
            remove(filename);
        }
        else
        {
            if (confirm == 'n' || confirm == 'N')
            {
                strcpy(notepad->files[notepad->filecount].name_of_file, filename);
                (notepad->filecount)++;
            }
        }
    }
}

void openfile(FileList *notepad)
{
}
void deletefile(FileList *naotepad)
{
}
