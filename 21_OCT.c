/* First you need to create a binary tree but the insertion of node is slightly different. if a key is divisible by 4 then it will be added at left side.else it will be added at right side. Now write a function to print the level order traversal for the above generated tree.

Input Format

The first line of input contains an integer T denoting the no of test cases. Then T test cases follow. Each test case contains two lines. The first line of each test case contains an integer N. Then in the next line are N space separated values of the array A[].*/
/*
Use linked list concept to solve the problem, otherwise you will be disqualified from the contest.
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
struct node {
    int key;
    struct node *left, *right;
};

struct node* newNode(int item)
{
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}
int height(struct node* node)
{
    if (node == NULL)
        return 0;
    else {
        int lheight = height(node->left);
        int rheight = height(node->right);
        if (lheight > rheight)
            return (lheight + 1);
        else
            return (rheight + 1);
    }
}
void printCurrentLevel(struct node* root, int level)
{
    if (root == NULL)
        return;
    if (level == 1)
        printf("%d ", root->key);
    else if (level > 1) {
        printCurrentLevel(root->left, level - 1);
        printCurrentLevel(root->right, level - 1);
    }
}
void printLevelOrder(struct node* root)
{
    int h = height(root);
    int i;
    for (i = 1; i <= h; i++)
        printCurrentLevel(root, i);
}
struct node* insert(struct node* node, int key)
{
    if (node == NULL)
        return newNode(key);
    if (key%4==0)
        node->left = insert(node->left, key);
    else if (key%4!=0)
        node->right = insert(node->right, key);
    return node;
}

int main()
{
    int tc;
    scanf("%d",&tc);
    while(tc--){
        int n;
        scanf("%d",&n);
        int arr[n];
        for(int i=0; i<n; i++)
            scanf("%d",&arr[i]);
        struct node* root = NULL;
        root = insert(root,arr[0]);
        for(int i=1; i<n;i++)
            insert(root,arr[i]);
        printLevelOrder(root);
        printf("\n");
    }
    return 0;
}
