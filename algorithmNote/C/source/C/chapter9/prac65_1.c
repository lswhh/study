/* 
 *----------------------------------- 
 *    ������ �ִ� ���������� ����   *
 *----------------------------------- 
 */ 

#include <stdio.h> 

int main(void) 
{ 
	int man, computer, C, M, judge;       /* ����ǥ */ 
	static int table[3][3][3] = {  {{0,0,0}, {0,0,0}, {0,0,0}}, 
							       {{0,0,0}, {0,0,0}, {0,0,0}}, 
							       {{0,0,0}, {0,0,0}, {0,0,0}}}, 
					     hist[3] = {0,0,0}; /* ������ ���� */ 
	static char *hand[3] = {"����", "����", "��"}; 

	C=M=0; 
	while (1) 
	{ 
		if (table[C][M][0]>table[C][M][1] && table[C][M][0] > table[C][M][2]) 
			computer=0; 
		else if (table[C][M][1]>table[C][M][2]) 
			computer=1; 
		else 
			computer=2; 

		printf("0:���� 1:���� 2:��\n"); 
		printf("����� �� : "); scanf("%d", &man); 

		printf("��ǻ���� �� : %s\n", hand[computer]); 

		judge=(computer-man+3)%3;    /* ���� */ 
		switch (judge) { 
			case 0: printf("���\n"); 
				table[C][M][(computer+1)%3]++; 
				break; 
			case 1: printf("��ǻ���� �¸�\n"); 
				table[C][M][computer]++; 
				break; 
			case 2: printf("����� �¸�\n"); 
				table[C][M][computer]--; 
				break; 
		} 
		M=man;           /* �ٷ� �� ���¸� ���� */ 
		C=computer; 

		hist[judge]++; 
		printf("--- %d�� %d�� %d�� --- \n\n", hist[2], hist[1], hist[0]); 
	} 

	return 0;
} 

