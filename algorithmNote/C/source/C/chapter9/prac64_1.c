/* 
 *------------------ 
 *    4N 마방진    *
 *------------------ 
 */ 
#include <stdio.h> 

#define N 8       /* 4N 방진 (n=4, 8, 12, 16, ...) */ 

int main(void) 
{ 
	int bangjin[N+1][N+1], i, j; 

	for (j=1; j<=N; j++) { 
		for (i=1; i<=N; i++) { 
			if (j%4==i%4 || (j%4+i%4)%4==1) 
				bangjin[i][j]=(N+i-1)*N-j+1; 
			else 
					bangjin[i][j]=(i-1)*N+j; 
		} 
	} 

	printf("       4N 마방진 (N=%d)\n", N); 
	for (i=1; i<=N; i++) { 
		for (j=1; j<=N; j++) 
			printf("%4d", bangjin[i][j]); 
		printf("\n"); 
	} 

	return 0;
} 
