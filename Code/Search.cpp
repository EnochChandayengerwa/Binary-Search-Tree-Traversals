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

bool Search(TreeNode *root, int data)
{
    if (root == NULL)
    {
        return false;
    }
    else if (root->data == data)
    {
        return true;
    }
    else if (data <= root->data)
    {
        return Search(root->left, data);
    }
    else
    {
        return Search(root->right, data);
    }
}

int main()
{
    TreeNode *root = NULL;
    vector<int> first_input;
    vector<int> second_input;
    int data, sdata;

    cin >> data;
    while (data != -1)
    {
        first_input.push_back(data);
        cin >> data;
    }
    for (int i = 0; i < first_input.size(); i++)
    {
        root = Insert(root, first_input[i]);
    }

    cin >> sdata;
    while (sdata != -1)
    {
        second_input.push_back(sdata);
        cin >> sdata;
    }
    for (int i = 0; i < second_input.size(); i++)
    {
        if (Search(root, second_input[i]))
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }
}