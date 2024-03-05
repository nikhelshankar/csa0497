#include<stdio.h>

struct st {
    char dname[10];
    char sdname[10][10];
    char fname[10][10][10];
    int ds, sds[10];
} dir[10];

int main() {
    int i, j, k, n;
    
    printf("Enter the number of directories: ");
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) {
        printf("Enter directory %d name: ", i + 1);
        scanf("%s", dir[i].dname);
        
        printf("Enter the number of subdirectories for %s: ", dir[i].dname);
        scanf("%d", &dir[i].ds);
        
        for (j = 0; j < dir[i].ds; j++) {
            printf("Enter subdirectory %d name: ", j + 1);
            scanf("%s", dir[i].sdname[j]);
            
            printf("Enter the number of files in %s: ", dir[i].sdname[j]);
            scanf("%d", &dir[i].sds[j]);
            
            for (k = 0; k < dir[i].sds[j]; k++) {
                printf("Enter file %d name: ", k + 1);
                scanf("%s", dir[i].fname[j][k]);
            }
        }
    }
    
    printf("\nDirectory name\tSize\tSubdirectory\tSize\tFiles\n");
    printf("*********************************************************\n");
    
    for (i = 0; i < n; i++) {
        printf("%s\t\t", dir[i].dname);
        printf("%d\t", dir[i].ds);
        
        for (j = 0; j < dir[i].ds; j++) {
            printf("\t%s\t\t", dir[i].sdname[j]);
            printf("%d\t", dir[i].sds[j]);
            
            for (k = 0; k < dir[i].sds[j]; k++) {
                printf("%s\t", dir[i].fname[j][k]);
            }
            printf("\n\t\t\t");
        }
        printf("\n");
    }
    
    return 0;
}

