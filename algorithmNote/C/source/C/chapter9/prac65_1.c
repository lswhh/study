/* 
 *----------------------------------- 
 *    전략이 있는 가위바위보 게임   *
 *----------------------------------- 
 */ 

#include <stdio.h> 

int main(void) 
{ 
	int man, computer, C, M, judge;       /* 전략표 */ 
	static int table[3][3][3] = {  {{0,0,0}, {0,0,0}, {0,0,0}}, 
							       {{0,0,0}, {0,0,0}, {0,0,0}}, 
							       {{0,0,0}, {0,0,0}, {0,0,0}}}, 
					     hist[3] = {0,0,0}; /* 승패의 도수 */ 
	static char *hand[3] = {"가위", "바위", "보"}; 

	C=M=0; 
	while (1) 
	{ 
		if (table[C][M][0]>table[C][M][1] && table[C][M][0] > table[C][M][2]) 
			computer=0; 
		else if (table[C][M][1]>table[C][M][2]) 
			computer=1; 
		else 
			computer=2; 

		printf("0:가위 1:바위 2:보\n"); 
		printf("당신의 손 : "); scanf("%d", &man); 

		printf("컴퓨터의 손 : %s\n", hand[computer]); 

		judge=(computer-man+3)%3;    /* 판정 */ 
		switch (judge) { 
			case 0: printf("비김\n"); 
				table[C][M][(computer+1)%3]++; 
				break; 
			case 1: printf("컴퓨터의 승리\n"); 
				table[C][M][computer]++; 
				break; 
			case 2: printf("당신의 승리\n"); 
				table[C][M][computer]--; 
				break; 
		} 
		M=man;           /* 바로 전 상태를 보존 */ 
		C=computer; 

		hist[judge]++; 
		printf("--- %d승 %d패 %d무 --- \n\n", hist[2], hist[1], hist[0]); 
	} 

	return 0;
} 

