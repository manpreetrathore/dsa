#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node* next;
    node* prev;

    node(int val){
        data = val;
        next = NULL;
        prev = NULL;
    }


};

void Display(node* head){
    node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" -> ";
        temp = temp->next;
    }
    cout<<endl;

}

void insertAtHead(node* &head, int val){
    node* n = new node(val);

    n->next = head;
    if(head!=NULL){
    head->prev = n;}
    head = n;

}

void insertAtTail(node* &head, int val){
    node* n = new node(val);
    node* temp = head;
    if(head==NULL){
        insertAtHead(head, val);
        return;
    }
    while(temp->next!=NULL){
        temp = temp->next;        
    }
    temp->next = n;
    n->prev = temp;
    
}

void deleteAtHead(node* &head){
    node* todelete = head;
    head = head->next;
    head->prev = NULL;
    delete todelete;

}

void deletion(node* &head, int pos){
    node* temp = head;
    int count = 1;
    if(pos==1){
        deleteAtHead(head);
        return;
    }
    while(count!=pos){
        temp = temp->next;
        count++;
    }
    
    temp->prev->next = temp->next;
    if(temp->next!=NULL){
    temp->next->prev = temp->prev;}
    delete temp;
}
int main(){
    node* head = NULL;
    insertAtTail(head,1);
    insertAtTail(head,2);
    insertAtTail(head,3);
    insertAtTail(head,4);
    insertAtTail(head,5);
    insertAtTail(head,6);
    Display(head);
    insertAtHead(head,7);
    Display(head);
    deletion(head,1);
    Display(head);

    return 0;
}