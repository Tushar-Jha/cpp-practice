#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int value)
    {
        data = value;
        left = NULL;
        right = NULL;
    }
};

Node *buildTree(Node *root)
{
    cout << "Enter the data " << endl;
    int data;
    cin >> data;
    root = new Node(data);

    if (data == -1)
    {
        return NULL;
    }

    cout << "Enter data to insert in left of " << data << endl;
    root->left = buildTree(root->left);
    cout << "Enter data to insert in right of " << data << endl;
    root->right = buildTree(root->right);
    return root;
}

void levelOrder(Node *root)
{
    if (root == NULL)
        return;
    queue<Node *> q;
    Node *curr;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        curr = q.front();
        if (curr == NULL)
        {
            q.push(NULL);
            q.pop();
            if (q.front() == NULL)
            {
                return;
            }
            cout << endl;
        }
        else
        {
            cout << curr->data << " ";
            q.pop();

            if (curr->left)
                q.push(curr->left);
            if (curr->right)
                q.push(curr->right);
        }
    }
}

void preorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    stack<Node *> s;
    s.push(root);
    while (!s.empty())
    {
        Node *curr = s.top();
        cout << curr->data << " ";
        s.pop();
        if (curr->right)
        {
            s.push(curr->right);
        }
        if (curr->left)
        {
            s.push(curr->left);
        }
    }
}

void postorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    stack<Node *> s;
    stack<int> res;
    s.push(root);
    while (!s.empty())
    {
        Node *curr = s.top();
        s.pop();
        res.push(curr->data);
        if (curr->left)
        {
            s.push(curr->left);
        }
        if (curr->right)
        {
            s.push(curr->right);
        }
    }
    while (!res.empty())
    {
        cout << res.top() << " ";
        res.pop();
    }
}

int height(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    return max(height(root->left), height(root->right)) + 1;
}

void inorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    stack<Node *> s;
    Node *curr = root;
    while (!s.empty() || curr != NULL)
    {
        while (curr != NULL)
        {
            s.push(curr);
            curr = curr->left;
        }
        curr = s.top();
        s.pop();
        cout << curr->data << " ";
        curr = curr->right;
    }
}


int diameter(Node* root,int &height){
    if(root==NULL)return 0;
    int lh=0;
    int rh=0;
    int ldia=diameter(root->left,lh);
    int rdia=diameter(root->right,rh);
    height=max(lh,rh)+1;
    return max(lh+rh+1,max(ldia,rdia));
}

bool isBalanced(Node* root,int &height){
    if(root==NULL)return true;
    int lh=0;
    int rh=0;
    bool left=isBalanced(root->left,lh);
    bool right=isBalanced(root->right,rh);

    height=max(lh,rh)+1;

    if(abs(lh-rh)<=1 && left && right){
        return true;
    }else{
        return false;
    }
}

vector<int> zigZagTraversal(Node* root){
    vector<int>res;
    if(roott==NULL)return res;
    queue<Node*>q;
    q.push(root);
    bool leftToRight=true;
    while(!q.empty()){
        vector<int>temp;
        int size=q.size();
        while(size--){
            Node* curr=q.front();
            q.pop();
            temp.push_back(curr->data);
            if(curr->left)q.push(curr->left);
            if(curr->right)q.push(curr->right);
        }
        if(leftToRight==false){
            reverse(temp.begin(),temp.end());
        }
        for(auto i:temp){
            res.push_back(i);
        }
        leftToRight=!leftToRight;
    }
    return res;
}

vector<int> reverseLevelOrder(Node* root){
    vector<int>result;
    if(root==NULL)return result;
    queue<Node*>q;
    q.push(root);
    while(!q.empty()){
            Node* curr=q.front();
            q.pop();
            result.insert(result.begin(),curr->data);
            if(curr->right)q.push(curr->right);
            if(curr->left)q.push(curr->left);
    }
    return result;
}

int main()
{
    Node *root;
    root = buildTree(root);
    inorder(root);
    return 0;
}