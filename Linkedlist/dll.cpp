#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Node{
    public:
        int data;
        Node* prev;
        Node* next;
        Node(int value){
            this->data=value;
            this->prev=NULL;
            this->next=NULL;
        }
};

void insertAtBeg(Node* &head,Node* &tail, int data){
    if(head==NULL){
        Node* newNode=new Node(data);
        head=newNode;
        tail=newNode;
        return;
    }
    Node* newNode=new Node(data);
    newNode->next=head;
    head->prev=newNode;
    head=newNode;
}


void insertAtEnd(Node* &head,Node* &tail,int data){
    if(tail==NULL){
        Node* newNode=new Node(data);
        head=newNode;
        tail=newNode;
        return;
    }
    Node* newNode= new Node(data);
    tail->next= newNode;
    newNode->prev=tail;
    tail=newNode;
}

void insertAtpos(Node* &head,Node* &tail,int pos,int data){
    if(pos==1){
        insertAtBeg(head,tail,data);
        return;
    }
    Node* temp=head;
    int i=1;
    while(i<pos-1){
        temp=temp->next;
        i++;
    }
    if(temp->next==NULL){
        insertAtEnd(head,tail,data);
        return;
    }
    Node* newNode= new Node(data);
    newNode->next=temp->next;
    temp->next=newNode;
    newNode->prev=temp;
    temp=newNode->next;
    temp->prev=newNode;
}


void printList(Node* &head){
    Node* temp=head;
    cout<<endl;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}

void printListRev(Node* &tail){
    Node* temp=tail;
    cout<<endl;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->prev;
    }
}


int main(){

    Node* head=NULL;
    Node* tail=NULL;
    insertAtBeg(head,tail,10);
    insertAtBeg(head,tail,12);
    insertAtEnd(head,tail,90);
    insertAtpos(head,tail,4,17);
    insertAtpos(head,tail,4,20);
    printList(head);
    printListRev(tail);
    return 0;
}