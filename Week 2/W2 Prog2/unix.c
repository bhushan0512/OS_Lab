#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<dirent.h>

void main()
{
    int c;
    printf("1.copy\n2.list\n3.grep\n4.exit\n");
    do
    {
        printf("enter your choice\n");
        scanf("%d",&c);
        switch(c)
        {
            case 1:cps();
                break;
            case 2: lss();
                  break;
            case 3:greps();
                 break;
            case 4:exit(0);
                    break;
        }
    }while(c!=5);
}
void cps()
{
    char ch, source_file[25], target_file[25];
    FILE *source, *target;
    printf("Enter name of file to copy\n");
    scanf("%s",&source_file);

    source = fopen(source_file, "r");

        if( source == NULL )
        {
            printf("Press any key to exit...\n");
            exit(EXIT_FAILURE);
        }

    printf("Enter name of target file\n");
    scanf("%s",&target_file);
    target = fopen(target_file, "w");
    if( target == NULL )
    {
        fclose(source);
        printf("Press any key to exit...\n");
        exit(EXIT_FAILURE);
    }
    while( ( ch = fgetc(source) ) != EOF )
        fputc(ch, target);
        printf("File copied successfully.\n");
        fclose(source);
        fclose(target);
}
void lss()
{
        DIR *d;

    struct dirent *dir;

    d = opendir(".");

    if (d)

    {

        while ((dir = readdir(d)) != NULL)

        {

            printf("%s\n", dir->d_name);

        }

        closedir(d);

    }
}
void greps()
{

        char fn[10], pat[10], temp[200];
        FILE *fp;
        printf("\n Enter file name : ");
        scanf("%s", fn);
        printf("Enter the pattern: ");
        scanf("%s", pat);
        fp = fopen(fn, "r");
        while (!feof(fp))
        {
            fgets(temp, sizeof(fp), fp);
            if (strcmp(temp, pat))
                printf("%s", temp);
        }
    fclose(fp);

}

