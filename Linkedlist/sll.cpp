#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Node{
    public:
        int data;
        Node* next;
        Node(int value){
            this->data=value;
            this->next=NULL;
        }
};

void insertAtBeginning(Node* &head,Node* &tail,int data){
    if(head==NULL){
        Node* newNode= new Node(data);
        head=newNode;
        tail=newNode;
        return;
    }
    Node* newNode= new Node(data);
    newNode->next=head;
    head=newNode;
}

void insertAtEnd(Node* &head,Node* &tail,int data){
    if(tail==NULL){
        Node* newNode= new Node(data);
        head=newNode;
        tail=newNode;
        return;
    }
    Node* newNode=new Node(data);
    tail->next=newNode;
    tail=newNode;
}

void insertAtpos(Node* &head,Node* &tail,int pos,int data){
    if(pos==1){
        insertAtBeginning(head,tail,data);
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
    Node* newNode=new Node(data);
    newNode->next=temp->next;
    temp->next=newNode;

}

void reverse(Node* &head,Node* &tail){
    Node* prev=NULL;
    Node* curr=head;
    Node* forward;
    while(curr!=NULL){
        forward=curr->next;
        curr->next=prev;
        prev=curr;
        curr=forward;
    }
    Node* temp=head;
    head=prev;
    tail=temp;
}

Node* reverseRec(Node* &head){
    
}

void deleteAtpos(Node* &head,Node* &tail,int pos){
    if(pos==1){
        Node*temp= head;
        head=head->next;
        delete temp;
        return;
    }
    Node* curr=head;
    Node* prev;
    int i=1;
    while(i<pos){
        prev=curr;
        curr=curr->next;
        i++;
    }
    if(curr->next==NULL){
        prev->next=NULL;
        tail=prev;
        delete curr;
        return;
    }
    prev->next=curr->next;
    curr->next=NULL;
    delete curr;
}

void printList(Node* &head){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}

int main(){

    Node* head=NULL;
    Node* tail=NULL;
    insertAtBeginning(head,tail,10);
    insertAtBeginning(head,tail,12);
    insertAtBeginning(head,tail,17);
    insertAtBeginning(head,tail,16);
    insertAtEnd(head,tail,15);
    insertAtpos(head,tail,2,3);
    insertAtpos(head,tail,7,4);
    deleteAtpos(head,tail,4);
    deleteAtpos(head,tail,6);
    reverse(head,tail);
    printList(head);
    return 0;
}