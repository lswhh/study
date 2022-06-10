/* 
 *------------------------------------- 
 *     전략이 있는 가위바위보 게임    *
 *------------------------------------- 
 */ 
#include <stdio.h> 

int main(void) 
{ 
	int man, computer, M, judge; 
	static int table[3][3] = {   {0,0,0}, /* 전략표 */ 
	   					  	     {0,0,0}, 
							     {0,0,0}}, 
					   hist[3] = {0,0,0}; /* 승패의 도수 */ 
	static char *hand[3] = {"가위", "바위", "보"}; 

	M=0; 
	while (1) { 
		if (table[M][0]>table[M][1] && table[M][0]>table[M][2]) 
			computer=1; 
		else if (table[M][1]>table[M][2]) 
			computer=2; 
		else 
			computer=0; 

		printf("0: 가위  1: 바위  2: 보\n"); 
		printf("당신의 손 : "); scanf("%d", &man); 
		printf("컴퓨터의 손 : %s\n", hand[computer]); 

		judge = (computer-man+3)%3; 
		switch (judge) { 
			case 0: printf("비김\n"); break; 
			case 1: printf("컴퓨터의 승\n"); break; 
			case 2: printf("당신의 승\n"); break; 
		} 
		hist[judge]++; 
		table[M][man]++;           /* 학습 */ 
		M=man; 
		printf("--- %d승 %d패 %d무 ---\n\n", hist[2], hist[1], hist[0]); 
	} 

	return 0;
} 

