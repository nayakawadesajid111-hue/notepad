/*Project name : Notepad using c language*/
#include <stdio.h>

int main()
{
    int option = 0;
    do
    {
        printf("%32s","Notepad\n");
        printf("1. New\n");
        printf("2. Open\n");
        printf("3. Delete\n");
        printf("4. Exit\n");
        printf("Enter option : ");
        scanf("%d", &option);

        switch (option)
        {
        case 1:
            // New txt file creation
            break;
        case 2:
            // opening file
            break;
        case 3:
            // Delete the file
            break;
        case 4:
            // Exit
            break;
        default:
            printf("Invalid option\n");
            break;
        }
    } while (option > 6);
}
