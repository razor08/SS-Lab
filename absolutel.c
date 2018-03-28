#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    char input[10];
    int start, length, address;
    FILE *fp1, *fp2;
    fp1 = fopen("input.dat", "r");
    fp2 = fopen("output.dat", "w");
    fscanf(fp1, "%s", input);
    while(strcmp(input, "E")!=0){
        if(strcmp(input, "H")==0) {
            fscanf(fp1, "%d", &start);
            fscanf(fp1, "%d", &length);
            fscanf(fp1, "%s", input);
            printf("\n%s\n", input);
            printf("In the header");
        }
        if (strcmp(input, "T")==0) {
            fscanf(fp1, "%d", &address);
            fscanf(fp1, "%s", input);
            fprintf(fp2, "%d\t%c%c\n", address, input[0], input[1]);
            fprintf(fp2, "%d\t%c%c\n", address+1, input[2], input[3]);
            fprintf(fp2, "%d\t%c%c\n", address+2, input[4], input[5]);
            address+=3;
            fscanf(fp1, "%s", input);
            printf("In the Text");
            printf("\n%s\n", input);
        }
        else {
            fprintf(fp2, "%d\t%c%c\n", address, input[0], input[1]);
            fprintf(fp2, "%d\t%c%c\n", address+1, input[2], input[3]);
            fprintf(fp2, "%d\t%c%c\n", address+2, input[4], input[5]);
            address+=3;
            fscanf(fp1, "%s", input);
            printf("Within the Text");
            printf("\n%s\n", input);
        }
        
    }
    fclose(fp1);
    fclose(fp2);
    printf("\nFINISHED\n");
    return 0;
}