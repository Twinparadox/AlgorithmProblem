#include <iostream>
#include <cstring>
#define MAXTREESIZE 4
using namespace std;

typedef struct TreeNode
{
	char color;
	struct TreeNode* link[MAXTREESIZE]; // 0:left-top 1:right-top 2:left-bottom 3:right-bottom
}TreeNode;

void AddTreeNode(char color)
{
	TreeNode* newnode = CreateNode(color);
	
}

TreeNode* CreateNode(char color)
{
	TreeNode* newnode = (TreeNode*)malloc(sizeof(TreeNode));
	newnode->color = color;
	for (int i = 0; i < MAXTREESIZE; i++)
		newnode->link[i] == NULL;
	return newnode;
}

int main()
{
	TreeNode* Root;
	char compress[1000];
	int len;
	int cnt = 0;
	int level = 0;
	
	cin >> compress;
	len = strlen(compress);

	for (int i = 0; i < len; i++)
	{
		if (compress[i] == 'w' || compress[i] == 'b')
			AddTreeNode(compress[i]);

	}
	return 0;
}
