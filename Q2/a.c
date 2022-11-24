#define _GNU_SOURCE
#include <unistd.h>
#include <sys/syscall.h>
#include <stdio.h>
#include <stdlib.h>

#define SYS_kernel_2d_memcpy 451

int main() {
    float Qwe1[2][2] = {{1.0,2.0},{3.0,4.0}};
    float abc2[2][2] = {{0.0,0.0},{0.0,0.0}};
    int Column=2;
    int Ro=2;
    int i=0;
    int j=0;
    printf("These are the initial matices\n");
    while(i<Column){
        while(j<Ro){
            printf("%lf ",Qwe1[i][j]);
            j++;
        }
        printf("\n");
        i++;
    }
    printf("\n");
    while(i<Column){
        while(j<Ro){
            printf("%lf ",abc2[i][j]);
            j++;
        }
        printf("\n");
        i++;
    }
    printf("\n");

    // for (int i = 0; i < 4; i++){
    //     for (int j = 0; j < 3; j++){
    //         printf("%lf ", MAT1[i][j]);
    //         }
    //     printf("\n");
    // }
    // printf("\n");

    // printf("This is the initial matrix2 is:\n");

    // for (int i = 0; i < 4; i++){
    //     for (int j = 0; j < 3; j++){
    //         printf("%lf ", MAT2[i][j]);
    //         }
    //     printf("\n");
    // }
    // printf("\n");

    int res = syscall(SYS_kernel_2d_memcpy,Qwe1,abc2,Column,Ro);

    if(res < 0){
        printf("ERROR!");
        exit(1);
    }
    else{
        printf("These are the final matices\n");
        while(i<Column){
        while(j<Ro){
            printf("%lf ",Qwe1[i][j]);
            j++;
        }
        printf("\n");
        i++;
        }
        printf("\n");
        while(i<Column){
            while(j<Ro){
                printf("%lf ",abc2[i][j]);
                j++;
            }
            printf("\n");
            i++;
        }
        printf("\n");

    }

    // printf("This is the final matrix1 is:\n");

    // for (int i = 0; i < 4; i++){
    //     for (int j = 0; j < 3; j++){
    //         printf("%lf ", MAT1[i][j]);
    //         }
    //     printf("\n");
    // }
    // printf("\n");

    // printf("This is the final matrix2 is:\n");

    // for (int i = 0; i < 4; i++){
    //     for (int j = 0; j < 3; j++){
    //         printf("%lf ", MAT2[i][j]);
    //         }
    //     printf("\n");
    // }
    // printf("\n");

    return 0;
}
