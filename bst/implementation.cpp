#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Node
{

public:
    int data;
    Node *left;
    Node *right;

    Node(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};

Node *insertIntoBST(Node *root, int d)
{
    if (root == NULL)
    {
        root = new Node(d);
        return root;
    }
    if (d > root->data)
    {
        root->right = insertIntoBST(root->right, d);
    }
    else
    {
        root->left = insertIntoBST(root->left, d);
    }
    return root;
}

Node* minValue(Node* root){
    if(root==NULL){
        return NULL;
    }
    Node* temp=root;
    while(temp->left!=NULL){
        temp=temp->left;
    }
    return temp;
}

Node* maxValue(Node* root){
    if(root==NULL){
        return NULL;
    }
    Node* temp=root;
    while(temp->right!=NULL){
        temp=temp->right;
    }
    return temp;
}


Node* deleteFromBST(Node* root,int key){
    if(root==NULL){
        return NULL;
    }
    if(root->data==key){

        //0 child
        if(root->left==NULL && root->right==NULL){
            delete root;
            return NULL;
        }

        //1 child
        else if(root->left!=NULL && root->right==NULL){
            Node* temp=root->left;
            delete root;
            return temp;
        }
        else if(root->right!=NULL && root->left==NULL){
            Node* temp=root->right;
            delete root;
            return temp;
        }

        //2 chidren

        else if(root->left!=NULL && root->right!=NULL){
            Node* miniValFromRight=minValue(root->right);
            root->data=miniValFromRight->data;
            root->right= deleteFromBST(root->right,miniValFromRight->data);
            return root;
        }
    }
    else if(root->data<key){
        root->right=deleteFromBST(root->right,key);
    }else{
        root->left=deleteFromBST(root->left,key);
    }
    return root;
}

void takeInput(Node *&root)
{
    int data;
    cin >> data;

    while (data != -1)
    {
        root = insertIntoBST(root, data);
        cin >> data;
    }
}

void inorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

bool searchInBST(Node *root, int x)
{
    if (root == NULL)
        return false;
    if (root->data == x)
        return true;
    else if (root->data < x)
        return searchInBST(root->right, x);
    else
        return searchInBST(root->left, x);
}

int main()
{

    Node *root = NULL;
    takeInput(root);
    cout << endl;
    inorder(root);

    cout<<endl;

    deleteFromBST(root,30);
    inorder(root);

    return 0;
}