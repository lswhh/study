/*
 * -----------------------------------------
 *      ��͸� �̿��� ���� Ž�� Ʈ�� #2    *
 * -----------------------------------------
 */

#include <stdio.h>
#include <malloc.h>
#include <string.h>

struct tnode {
    struct tnode *left;     /* ���� �κ�Ʈ���� ����Ű�� ������ */
    char name[12];          /* �̸� */
    struct tnode *right;    /* ������ �κ�Ʈ���� ����Ű�� ������ */
};

struct tnode *talloc(void);
struct tnode *gentree(struct tnode *,char *);
struct tnode *search(struct tnode *,char *);

int main(void)
{
    char key[12];
    struct tnode *root,*p;

    root=NULL;                      /* Ʈ�� ���� */
    while (scanf("%s",key)!=EOF) {
        root=gentree(root,key);
    }

    rewind(stdin);
    while (printf("Search name -->"),scanf("%s",key)!=EOF) {
        if ((p=search(root,key))!=NULL)
            printf("%s �� ã�ҽ��ϴ�.\n",p->name);
        else
            printf("ã�� �� �߽��ϴ�.\n");
    }

    return 0;
}

struct tnode *search(struct tnode *p,char *key)  /* Ʈ�� Ž�� */
{
    if (p==NULL || strcmp(key,p->name)==0)
        return p;
    if (strcmp(key,p->name)<0)
        return search(p->left,key);
    else
        return search(p->right,key);
}

struct tnode *gentree(struct tnode *p,char *w)  /* Ʈ���� �����ϴ� ��� ȣ�� */
{
    if (p==NULL) {
        p=talloc();
        strcpy(p->name,w);
        p->left=p->right=NULL;
    }
    else if (strcmp(w,p->name)<0)
        p->left=gentree(p->left,w);
    else
        p->right=gentree(p->right,w);
    return p;
}

struct tnode *talloc(void)     /* �޸� �Ҵ� */
{
    return (struct tnode *)malloc(sizeof(struct tnode));
}
