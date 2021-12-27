#include <iostream>
#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *parent;
    Node *left;
    Node *right;
    int color;
    int c;
};

typedef Node *NodePtr;
int getCount(NodePtr root)
{
    if(root == nullptr)
    {
        return 0;
    }
    else
    {
        return root->c;
    }
}
class RedBlackTree
{
private:
    NodePtr root;
    NodePtr TNULL;

public:
    RedBlackTree()
    {
        TNULL = new Node;
        TNULL->color = 0;
        TNULL->left = nullptr;
        TNULL->right = nullptr;
        TNULL->c=0;
        root = TNULL;

    }

    void leftRotate(NodePtr x)
    {
        NodePtr y = x->right;
        x->right = y->left;
        if (y->left != TNULL)
        {
            y->left->parent = x;
        }
        y->parent = x->parent;
        if (x->parent == nullptr)
        {
            this->root = y;
        }
        else if (x == x->parent->left)
        {
            x->parent->left = y;
        }
        else
        {
            x->parent->right = y;
        }
        y->left = x;
        x->parent = y;
        x->c =getCount(x);
        y->c =getCount(y);
    }

    void rightRotate(NodePtr x)
    {
        NodePtr y = x->left;
        x->left = y->right;
        if (y->right != TNULL)
        {
            y->right->parent = x;
        }
        y->parent = x->parent;
        if (x->parent == nullptr)
        {
            this->root = y;
        }
        else if (x == x->parent->right)
        {
            x->parent->right = y;
        }
        else
        {
            x->parent->left = y;
        }
        y->right = x;
        x->parent = y;
        x->c =getCount(x);
        y->c =getCount(y);
    }
    int search(NodePtr root,int value)
    {
        int l=0;
        if(root == nullptr)
        {
            return -1;
        }
        NodePtr n= this->root;
        while(n!=TNULL)
        {
            if (n->data==value)
            {
                return l+n->left->c+1;
            }
            else if (n->data < value)
            {
                l+=n->left->c+1;
                n=n->right;
            }
            else
            {
                n=n->left;
            }
        }
        return -1;
    }

    // Inserting a node
    void insert(int key)
    {
        NodePtr node = new Node;
        node->parent = nullptr;
        node->data = key;
        node->left = TNULL;
        node->right = TNULL;
        node->color = 1;
        node->c = 1;
        NodePtr y = nullptr;
        NodePtr x = this->root;

        while (x != TNULL)
        {
            y = x;
            (x->c)++;
            if (node->data < x->data)
            {
                x = x->left;

            }
            else
            {
                x = x->right;
            }
        }

        node->parent = y;
        if (y == nullptr)
        {
            root = node;
        }
        else if (node->data < y->data)
        {
            y->left = node;
        }
        else
        {
            y->right = node;
        }

        if (node->parent == nullptr)
        {
            node->color = 0;
            return;
        }

        if (node->parent->parent == nullptr)
        {
            return;
        }


    }

    NodePtr getRoot()
    {
        return this->root;
    }


};

int main()
{
    RedBlackTree bst;
    int n;
    cin >> n;
    string output="";
    for (int i=0; i<n; i++)
    {
        int a,b;
        cin >> a >>b;
        if (a==1)
        {
            bst.insert(b);
        }
        if (a==2)
        {
            cout << "output: " << bst.search(bst.getRoot(),b) <<endl;
        }
    }
}
