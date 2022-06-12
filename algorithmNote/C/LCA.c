// https://www.hackerrank.com/challenges/binary-search-tree-lowest-common-ancestor/problem?isFullScreen=true&h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=trees

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

struct node {
    
    int data;
    struct node *left;
    struct node *right;
  
};

struct node* insert( struct node* root, int data ) {
		
	if(root == NULL) {
	
        struct node* node = (struct node*)malloc(sizeof(struct node));

        node->data = data;

        node->left = NULL;
        node->right = NULL;
        return node;
	  
	} else {
      
		struct node* cur;
		
		if(data <= root->data) {
            cur = insert(root->left, data);
            root->left = cur;
		} else {
            cur = insert(root->right, data);
            root->right = cur;
		}
	
		return root;
	}
}
void preorder(struct node* root)
{
    if ( root == NULL )
    {
        return;
    }
    printf("(%d) ", root->data);
    preorder(root->left);
    preorder(root->right);
}
// depth of root is 0
int getDepth( struct node* root, int data)
{
    int sDepth;
    int sIsFound = 0;
    struct node* node = root;

    sDepth = 0;
    while ( node != NULL )
    {
        if ( node->data == data )
        {
            sIsFound = 1;
            break; 
        }
        else if ( data < node->data )
        {
            node = node->left;
        }
        else
        {
            node = node->right;
        }
        sDepth++;
    }
    if ( sIsFound != 1 )
    {
        sDepth = -1;
    }
    return sDepth;
}

/* you only have to complete the function given below.  
node is defined as  

struct node {
    
    int data;
    struct node *left;
    struct node *right;
  
};

*/
typedef struct pnode pnode;
struct pnode {
    int data;
    struct node * orgNodePtr;
    pnode *parent;
    pnode *left;
    pnode *right;
  
};

pnode* insertp( pnode* parent,  struct node* orgNodePtr ) {
		
	if(parent == NULL) {
	
        pnode* node = (pnode*)malloc(sizeof(pnode));

        node->data = orgNodePtr->data;
        node->parent = node;
        node->orgNodePtr = orgNodePtr;
        node->left = NULL;
        node->right = NULL;
        return node;
	  
	} else {
      
		pnode* cur;
		
		if(orgNodePtr->data <= parent->data) {
            cur = insertp(parent->left, orgNodePtr);
            parent->left = cur;
            cur->parent = parent;
		} else {
            cur = insertp(parent->right, orgNodePtr);
            parent->right = cur;
            cur->parent = parent;
		}
	
		return parent;
	}
}
pnode* makePnodeTree( struct node* nodeParent, pnode* root )
{
    int sDepth;
    int sIsFound = 0;
    struct node* node = nodeParent;
    pnode* pNode = NULL;
    if ( nodeParent == NULL )
    {
        return NULL;
    }
    pNode = insertp(root, nodeParent);
    makePnodeTree(nodeParent->left, pNode);
    makePnodeTree(nodeParent->right, pNode);
    return pNode;
}
void preorderP(pnode* root)
{
    if ( root == NULL )
    {
        return;
    }
    printf("(%d) ", root->data);
    preorderP(root->left);
    preorderP(root->right);
}
pnode* getNode(pnode* root, int data)
{
    int sDepth;
    int sIsFound = 0;
    pnode* node = root;

    sDepth = 0;
    while ( node != NULL )
    {
        if ( node->data == data )
        {
            sIsFound = 1;
            break; 
        }
        else if ( data < node->data )
        {
            node = node->left;
        }
        else
        {
            node = node->right;
        }
    }
    if ( sIsFound != 1 )
    {
        node = NULL;
    }
    return node;
}
struct node *lca( struct node *root, int v1, int v2 ) {
    pnode *sPRoot;
    int v1Depth = 0;
    int v2Depth = 0;
    pnode* v1ParentPtr = NULL;
    pnode* v2ParentPtr = NULL;

    sPRoot = makePnodeTree(root, NULL);
    preorder(root);
    preorderP(sPRoot);
    v1Depth = getDepth(root, v1);
    v2Depth = getDepth(root, v2);
    v1ParentPtr = getNode(sPRoot, v1);
    v2ParentPtr = getNode(sPRoot, v2);

    while ( v1Depth > v2Depth )
    {
        v1ParentPtr = v1ParentPtr->parent;
        v1Depth--;
    }

    while ( v1Depth < v2Depth )
    {
        v2ParentPtr = v2ParentPtr->parent;
        v2Depth--;
    }

    while ( v1ParentPtr != v2ParentPtr )
    {
        v1ParentPtr = v1ParentPtr->parent;
        v2ParentPtr = v2ParentPtr->parent;
    }
    return v1ParentPtr->orgNodePtr;
}


int main() {
  
    struct node* root = NULL;
    
    int t;
    int data;

    // scanf("%d", &t);

    // while(t-- > 0) {
    //     scanf("%d", &data);
    //     root = insert(root, data);
    // }
    int datas[] = { 5, 3, 8, 2, 4, 6, 7 };
    int v1=7, v2=3;

    // int datas[] = {4, 2, 3, 1, 7, 6};
  	// int v1 = 1;
  	// int v2 = 7;

    for (t = 0; t < sizeof(datas)/sizeof(int); t++)
        root = insert(root,datas[t]);
  
  	//scanf("%d%d", &v1, &v2);
	struct node *ans = lca(root, v1, v2);
  	printf("%d", ans->data);
  	
    return 0;
}
// 6
// 4 2 3 1 7 6
// 1 7