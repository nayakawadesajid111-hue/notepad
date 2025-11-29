#ifndef file_H
#define file_H

#define MAX_FILES 100



typedef struct {
    char name_of_file[50];
} FileName;

typedef struct {
    FileName files[MAX_FILES];
    int filecount;
} FileList;

void createnewfile(FileList*notepad);
void openfile(FileList*notepad);
void deletefile(FileList*notepad);
void saveAndExit(FileList*notepad);
void initialize(FileList*notepad);
void listoffile(FileList*notepad);

#endif

