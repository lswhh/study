/* 
 * --------------------------------------- 
 *     2 ~ N ������ ��� �Ҽ��� ����     * 
 * --------------------------------------- 
 */ 

#include <stdio.h> 
#include <math.h> 

#define NUM 1000 

int main(void) 
{ 
    static int prime[NUM/2+1]; 
    int i,n,m=0,Limit; 

    for (n=2;n<=NUM;n++){ 
        Limit=(int)sqrt(n); 
        for (i=Limit;i>1;i--){ 
            if (n%i == 0) 
                break; 
        } 
        if (i==1) 
            prime[m++]=n; 
    } 

    printf("2 ~ %d ������ �Ҽ�\n", NUM); 
    for (i=0;i<m;i++) 
        printf("%5d",prime[i]); 

    printf("\n");
    
    return 0;
} 
