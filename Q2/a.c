#define _GNU_SOURCE
#include <unistd.h>
#include <sys/syscall.h>
#include <stdio.h>
#include <stdlib.h>

#define SYS_kernel_2d_memcpy 451

int main() {
    int Column=2;
    int Ro=2;
    
    float Qwe1[2][2] = {{1.0,2.0},{3.0,4.0}};
    float abc2[2][2] = {{0.0,0.0},{0.0,0.0}};
    
    printf("These are the initial matices\n");
    int i=0;
    while(i<2){
        int j=0;
        while(j<2){
            printf("%lf ",Qwe1[i][j]);
            j++;
        }
        printf("\n");
        i++;
    }
    printf("\n");
    i=0;
    while(i<2){
        int j=0;
        while(j<2){
            printf("%lf ",abc2[i][j]);
            j++;
        }
        printf("\n");
        i++;
    }
    printf("\n");
    int res = syscall(SYS_kernel_2d_memcpy,Qwe1,abc2,Column,Ro);

    if(res < 0){
        printf("ERROR!");
        exit(1);
    }
    else{
        printf("These are the initial matices\n");
    int i=0;
    while(i<2){
        int j=0;
        while(j<2){
            printf("%lf ",Qwe1[i][j]);
            j++;
        }
        printf("\n");
        i++;
    }
    printf("\n");
    i=0;
    while(i<2){
        int j=0;
        while(j<2){
            printf("%lf ",abc2[i][j]);
            j++;
        }
        printf("\n");
        i++;
    }
    printf("\n");}
    return 0;
}
