/* 
 *------------------------------------- 
 *     ������ �ִ� ���������� ����    *
 *------------------------------------- 
 */ 
#include <stdio.h> 

int main(void) 
{ 
	int man, computer, M, judge; 
	static int table[3][3] = {   {0,0,0}, /* ����ǥ */ 
	   					  	     {0,0,0}, 
							     {0,0,0}}, 
					   hist[3] = {0,0,0}; /* ������ ���� */ 
	static char *hand[3] = {"����", "����", "��"}; 

	M=0; 
	while (1) { 
		if (table[M][0]>table[M][1] && table[M][0]>table[M][2]) 
			computer=1; 
		else if (table[M][1]>table[M][2]) 
			computer=2; 
		else 
			computer=0; 

		printf("0: ����  1: ����  2: ��\n"); 
		printf("����� �� : "); scanf("%d", &man); 
		printf("��ǻ���� �� : %s\n", hand[computer]); 

		judge = (computer-man+3)%3; 
		switch (judge) { 
			case 0: printf("���\n"); break; 
			case 1: printf("��ǻ���� ��\n"); break; 
			case 2: printf("����� ��\n"); break; 
		} 
		hist[judge]++; 
		table[M][man]++;           /* �н� */ 
		M=man; 
		printf("--- %d�� %d�� %d�� ---\n\n", hist[2], hist[1], hist[0]); 
	} 

	return 0;
} 

