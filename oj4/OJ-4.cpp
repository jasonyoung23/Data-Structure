#include<bits/stdc++.h>
using namespace std;

class Node
{
public:
    int key;
    Node *left;
    Node *right;
    int height;
    int search;
};

int height(Node *N)
{
    if (N == NULL)
        return 0;
    return N->height;
}

int max(int a, int b)
{
    if (a>b) return a;
    else return b;
}

Node* newNode(int key)
{
    Node* node = new Node();
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    node->search = 1;
    return(node);
}

Node *rightRotate(Node *y)
{
    Node *x = y->left;
    Node *T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(height(y->left),
                    height(y->right)) + 1;
    x->height = max(height(x->left),
                    height(x->right)) + 1;
    return x;
}

Node *leftRotate(Node *x)
{
    Node *y = x->right;
    Node *T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(height(x->left),
                    height(x->right)) + 1;
    y->height = max(height(y->left),
                    height(y->right)) + 1;
    return y;
}

int getBalance(Node *N)
{
    if (N == NULL)
        return 0;
    return height(N->left) - height(N->right);
}

Node* insert(Node* node, int key)
{
    if (node == NULL)
        return(newNode(key));

    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else
        return node;
    node->height = 1 + max(height(node->left),height(node->right));
    int balance = getBalance(node);

    if (balance > 1 && key < node->left->key)
        return rightRotate(node);

    if (balance < -1 && key > node->right->key)
        return leftRotate(node);

    if (balance > 1 && key > node->left->key)
    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    if (balance < -1 && key < node->right->key)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
    return node;
}

void preOrder(Node *root, int hh)
{
    if(root != NULL)
    {
        root->search = hh;
        preOrder(root->left,hh+1);
        preOrder(root->right,hh+1);
    }
}

int getTotal(Node *root)
{
    if (root==NULL) return 0;
    int left = getTotal(root->left);
    int right = getTotal(root->right);
    return  root->search + left + right ;

}

int main()
{
    Node *root = NULL;
    string input;
    getline(cin, input);
    int arr[1000];
    int n = 0;
    int pos1=0;
    int pos2=0;
    while (pos2!=-1)
    {
        pos2 = input.find(' ',pos1);
        string strang = input.substr(pos1, pos2-pos1);
        pos1 = pos2+1;
        root = insert(root, stoi(strang));
        n++;
    }
    preOrder(root,1);
    int total = getTotal(root);
    cout<<total/n;
    return 0;
}
