/* 
 * ---------------------- 
 *      소수의 판정     * 
 * ---------------------- 
 */ 

#include <stdio.h> 
#include <math.h> 

int main(void) 
{ 
    int i,n,Limit; 

    while (printf("data? "),scanf("%d",&n)!=EOF) { 
        if (n>=2){ 
            Limit=(int)sqrt(n); 
            for (i=Limit;i>1;i--) { 
                if (n%i == 0) 
                    break; 
            } 
            if (i==1) 
                printf("소수\n"); 
            else 
                printf("소수가 아님\n"); 
        } 
    }
    
    return 0;
} 
