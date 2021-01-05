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

TreeNode *Min(TreeNode *root)
{
    while (root->left != NULL)
        root = root->left;
    return root;
}

struct TreeNode *Delete(struct TreeNode *root, int data)
{
    if (root == NULL)
        return root;
    else if (data < root->data)
        root->left = Delete(root->left, data);
    else if (data > root->data)
        root->right = Delete(root->right, data);
    else
    {
        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            root = NULL;
        }
        else if (root->left == NULL)
        {
            struct TreeNode *temp = root;
            root = root->right;
            delete temp;
        }
        else if (root->right == NULL)
        {
            struct TreeNode *temp = root;
            root = root->left;
            delete temp;
        }
        else
        {
            struct TreeNode *temp = Min(root->right);
            root->data = temp->data;
            root->right = Delete(root->right, temp->data);
        }
    }
    return root;
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
        root = Delete(root, second_input[i]);
        preOrder(root);
        cout << endl;
        inOrder(root);
        cout << endl;
        postOrder(root);
        cout << endl;
        cout << endl;
    }
}