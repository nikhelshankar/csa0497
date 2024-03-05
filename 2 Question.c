#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fptr1, *fptr2;
    char filename[100], c;

    printf("Enter the filename to open for reading: ");
    scanf("%s", filename);

    fptr1 = fopen(filename, "r");
    if (fptr1 == NULL) {
        printf("Cannot open file %s for reading\n", filename);
        exit(1);
    }

    printf("Enter the filename to open for writing: ");
    scanf("%s", filename);

    fptr2 = fopen(filename, "w");
    if (fptr2 == NULL) {
        printf("Cannot open file %s for writing\n", filename);
        fclose(fptr1);
        exit(1);
    }

    c = fgetc(fptr1);
    while (c != EOF) {
        fputc(c, fptr2);
        c = fgetc(fptr1);
    }

    printf("Contents copied to %s\n", filename);

    fclose(fptr1);
    fclose(fptr2);

    return 0;
}

