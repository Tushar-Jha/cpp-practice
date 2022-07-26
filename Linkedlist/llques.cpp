#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

// reverse
Node *reverse(Node *head)
{
    if (head == NULL)
    {
        return NULL;
    }
    Node *curr = head;
    Node *prev = NULL;
    Node *forward = NULL;
    while (curr != NULL)
    {
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }
    return prev;
}

// reverse recursively
Node *revRec(Node *head)
{
    if (head == NULL)
    {
        return NULL;
    }
    Node *rest = revRec(head->next);
    head->next->next = head;
    head->next = NULL;
    return rest;
}

// find middle
Node *findMiddleNode(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    Node *slow = head;
    Node *fast = head;
    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}

// reverse in group of k
Node *reverseInK(Node *head, int k)
{
    if (head == NULL)
    {
        return NULL;
    }
    Node *prev = NULL;
    Node *curr = head;
    Node *forward = NULL;
    int count = 0;
    while (count < k || curr != NULL)
    {
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
        count++;
    }
    if (forward != NULL)
    {
        head->next = reverseInK(forward, k);
    }
    return prev;
}

// detect loop in a linked list
Node *detectLoop(Node *head)
{
    if (head == NULL)
        return NULL;

    Node *slow = head;
    Node *fast = head;

    while (fast != NULL || fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            break;
        }
    }
    slow = head;
    while (slow != fast)
    {
        slow = slow->next;
        fast = fast->next;
    }

    return slow;
}

// remove loop from a linkedList;
Node *removeLoop(Node *head)
{
    if (head == NULL)
    {
        return NULL;
    }

    Node *start = detectLoop(head);
    Node *temp = start;

    while (temp->next != start)
    {
        temp = temp->next;
    }

    temp->next = NULL;

    return head;
}

// remove duplicates from sorted linkedlist
Node *removeDupsSorted(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    Node *curr = head;
    while (curr != NULL && curr->next != NULL)
    {
        if (curr->data == curr->next->data)
        {
            Node *temp = curr->next;
            curr->next = temp->next;
            delete temp;
        }
    }
    return head;
}

Node* removeDupsUn(Node* head){
    if(head==NULL || head->next==NULL){
        return head;
    }
    unordered_map<int,bool>mp;
    Node* curr=head;
    Node* prev;
    while(curr!=NULL){
        if(mp[curr->data]==true){
            prev->next=curr->next;
            Node* temp=curr;
            delete(temp);
            curr=prev->next;
        }
        else{
            prev=curr;
            mp[curr->data]=true;
            curr=curr->next;
        }
    }
    return head;
}

int main()
{

    return 0;
}