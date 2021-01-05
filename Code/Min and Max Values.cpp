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

int Min(struct TreeNode *root)
{
    if (root == NULL)
        return -1;
    else
    {
        TreeNode *curr = root;
        while (curr->left != NULL)
        {
            curr = curr->left;
        }
        return curr->data;
    }
}

int Max(struct TreeNode *root)
{
    if (root == NULL)
        return -1;
    else
    {
        TreeNode *curr = root;
        while (curr->right != NULL)
        {
            curr = curr->right;
        }
        return curr->data;
    }
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

    cout << Min(root) << "\n"
         << Max(root) << endl;
}