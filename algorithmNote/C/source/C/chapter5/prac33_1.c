/*
 * ------------------------
 *      ť (������)     *
 * ------------------------
 */

#include <stdio.h>

int queuein(int);
int queueout(int *);
void disp(void);

#define MaxSize 100     /* ť ũ�� */
int queue[MaxSize];     /* ť */
int head=0,             /* ù ��° �����͸� ����Ű�� ������ */
    tail=0;             /* ������ �����͸� ����Ű�� ������ */
int queuein(int);
int queueout(int *);

int main(void)
{
    int c,n;

    printf("]");
    while ((c=getchar())!=EOF) {
        if (c == '\n') continue;
        switch (c) {
            case 'i':
            case 'I': printf("data--> ");
                      scanf("%d",&n);
                      if (queuein(n)==-1)
                          printf("ť�� ���� á���ϴ�.\n");
                      break;
            case 'o':
            case 'O': if (queueout(&n)==-1)
                          printf("ť�� ����ֽ��ϴ�.\n");
                      else
                          printf("queue data --> %d\n",n);
                      break;
            case 'l':
            case 'L': disp();
                      break;
        }
        printf("]");
    }

    return 0;
}

int queuein(int n)     /* ť�� �����͸� �����ϴ� �Լ� */
{
    if ((tail+1)%MaxSize !=head) {
        queue[tail]=n;
        tail++;
        tail=tail%MaxSize;
        return 0;
    }
    else
        return -1;      /* ť�� ���� á�� �� */
}

int queueout(int *n)    /* ť���� �����͸� �����ϴ� �Լ� */
{
    if (tail!=head) {
        *n=queue[head];
        head++;
        head=head%MaxSize;
        return 0;
    }
    else
        return -1;     /* ť�� ������� �� */
}

void disp(void)        /* ť�� ����� �����͸� ����ϴ� �Լ� */
{
    int i;

    i=head;
    while (i!=tail) {
        printf("%d\n",queue[i]);
        i++;
        i=i%MaxSize;
    }
}
