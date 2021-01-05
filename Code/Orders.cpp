#include <iostream>
#include <vector>
using namespace std;

struct TreeNode
{
    int data;
    TreeNode *left;
    TreeNode *right;
};

TreeNode *GetNewTreeNode(int data)
{
    TreeNode *newTreeNode = new TreeNode();
    newTreeNode->data = data;
    newTreeNode->left = newTreeNode->right = NULL;
    return newTreeNode;
}

void preOrder(struct TreeNode *root)
{
    if (root == NULL)
        return;
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

void inOrder(TreeNode *root)
{
    if (root == NULL)
        return;

    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

void postOrder(TreeNode *root)
{
    if (root == NULL)
        return;

    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}

TreeNode *Insert(TreeNode *root, int data)
{
    if (root == NULL)
    {
        root = GetNewTreeNode(data);
    }

    else if (data <= root->data)
    {
        root->left = Insert(root->left, data);
    }

    else
    {
        root->right = Insert(root->right, data);
    }
    return root;
}

int main()
{
    TreeNode *root = NULL;
    vector<int> input;
    int data;
    cin >> data;

    while (data != -1)
    {
        input.push_back(data);
        cin >> data;
    }

    for (int i = 0; i < input.size(); i++)
    {
        root = Insert(root, input[i]);
    }

    preOrder(root);
    cout << endl;
    inOrder(root);
    cout << endl;
    postOrder(root);
}