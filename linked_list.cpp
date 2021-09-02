#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node* next;

    node(int val){
        data = val;
        next = NULL;
    }

};

void insertAtTail(node* &head, int val){

    
    node* n = new node(val);
    if(head==NULL){
        head = n;
        return;
    }
    
    node* temp = head;
    while(temp->next!=NULL){
        temp = temp->next;
    }
    temp->next = n;
}
void Display(node* head){
    node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" -> ";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}

void insertAtHead(node* &head,int val){
    node* n= new node(val);
    n->next = head;
    head = n;
}

bool search(node* head, int key){
    node* temp = head;
    while(temp!=NULL){
        if(temp->data==key){
            return true;
        }
        temp = temp->next;
    }
    return false;
}

void deleteAtHead(node* &head){
    node* todelete = head;
    head = head->next;
    delete todelete;
}
void deletion(node*  &head, int val){
    node* temp = head;
    if(head==NULL){
        return;
    }
    if(head->next==NULL){
        deleteAtHead(head);
        return;
    }
    if(head->next!=NULL && head->data==val){
        head = temp->next;
        delete temp;
        return;
    }
    while(temp->next->data!=val){
        temp = temp->next;
        }
    node* todelete = temp->next;
    temp->next = temp->next->next;
    delete todelete;
}

node* reverse(node* &head){
    node* prev = NULL;
    node* curr = head;
    node* nxt;
    while(curr!=NULL)
    {
        nxt = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nxt;

    }
    head = prev;
    return head;
}

node* reverseRecursive(node* &head){
    if(head==NULL || head->next ==NULL){
        return head;
    }
    node* newhead = reverseRecursive(head->next);
    head->next->next = head;
    head->next = NULL;
    return newhead;

}

node* reversek(node* &head, int k){
    node* prev = NULL;
    node* curr = head;
    node* nxt;
    int count = 0;
    ListNode* cursor = head;
    for(int i = 0; i < k; i++){
        if(cursor == nullptr) return head;
        cursor = cursor->next;
    }
    while(curr!=NULL && count<k){
        nxt = curr -> next;
        curr->next = prev;
        prev = curr;
        curr = nxt;
        count++; 
    }

    if(nxt!=NULL){
    head-> next = reversek(nxt,k);
    }
    return prev;
}

void makeCycle(node* &head, int pos){
    node* temp = head;
    node* startNode;
    int count = 1;
    while(temp->next!=NULL){
        if(count==pos){
            startNode=temp;
        }
        temp = temp->next;
        count++;
    }
    temp->next = startNode;
}
bool detectCycle(node* head){
    node* slow;
    node* fast;

    while(fast!=NULL && fast->next != NULL ){slow = slow->next;
    fast = fast->next->next;
    if(fast==slow){
        return true;
        }
    }
    return false;
}

void removeCycle(node* &head){
    node* slow=head;
    node* fast=head;
    do{
        slow = slow->next;
        fast = fast->next->next;

    }while(slow!=fast);
    fast = head;
    while(slow->next !=fast->next){
        slow=slow->next;
        fast = fast->next;
    }
    slow->next = NULL;
}

int length(node* head){
    int l=0;
    while(head!=NULL){
        l++;
        head= head->next;
    }
    return l;
}

node* kappend(node* &head, int k){
    node* newHead;
    node* newTail;
    node* tail=head;
    int l = length(head);
    int count = 1;
    k = k%l;
    while(tail->next!=NULL){
        if(count==l-k){
            newTail = tail;
        }
        if(count==l-k+1){
            newHead = tail;
        }
        tail = tail->next;
        count++;
    }
    newTail->next = NULL;
    tail->next = head;
    return newHead;
}

int intersection(node* &head1, node* &head2){
    int l1=length(head1);
    int l2 = length(head2);
    int d = 0;
    node* ptr1;
    node* ptr2;
    if(l1>l2){
        d=l1-l2;
        ptr1=head1;
        ptr2=head2;
    }
    else{
        d=l2-l1;
        ptr1=head2;
        ptr2=head1;
    }
    while(d){
        ptr1=ptr1->next;
        if(ptr1==NULL){
            return -1;
        }
        d--;
    }
    while(ptr1!=NULL && ptr2!=NULL){
        if(ptr1==ptr2){
            return ptr1->data;
        }
        ptr1= ptr1->next;
        ptr2 = ptr2->next;
    }
    return -1;
}

void intersect(node* &head1, node* &head2,int pos){
    node* temp1 = head1;
    pos--;
    while(pos--){
        temp1=temp1->next;
    }
    node* temp2 = head2;
    while(temp2->next!=NULL){
        temp2=temp2->next;
    }
    temp2->next = temp1;
}

node* merge(node* &head1, node* &head2){
    node* ptr1=head1;
    node* ptr2=head2;
    node* dummyNode = new node(-1);
    node* ptr3 = dummyNode;
    while(ptr1!=NULL && ptr2!=NULL){
        if(ptr1->data<ptr2->data){
            ptr3->next = ptr1;
            ptr1=ptr1->next;
        }
        else{
            ptr3->next = ptr2;
            ptr2 = ptr2->next;
        }
        ptr3 = ptr3->next;
    }
    while(ptr1!=NULL){
            ptr3->next = ptr1;
            ptr1 = ptr1->next;
            ptr3 = ptr3->next;
        }
    while(ptr2!=NULL){
        ptr3->next = ptr2;
        ptr2 = ptr2->next;
        ptr3 = ptr3->next;
    }
    return dummyNode->next;

}

node* mergeRecursive(node* &head1, node* &head2){
    if(head1==NULL){
        return head1;

    }
    if(head2==NULL){
        return head2;
    }
    
    node* result;

    if(head1->data<head2->data){
        result = head1;
        result->next = mergeRecursive(head1->next,head2);

    }
    if(head1->data>head2->data){
        result = head2;
        result->next = mergeRecursive(head1,head2->next);        
    }
    return result;
}

void evenAfterOdd(node* &head){
    node* odd = head;
    node* even = head->next;
    node* evenStart = even;
    while(odd->next!=NULL && even->next!=NULL){
        odd->next = even->next;
        odd = odd->next;
        even->next = odd->next;
        even = even->next;
        cout<<odd->data<<even->data<<endl;
        
    }
    odd->next = evenStart;
    if(odd->next!=NULL){
        even->next=NULL;
    }
}

int main(){
    node* head=NULL;
    insertAtTail(head,1);
    insertAtTail(head,11);
    insertAtTail(head,2);
    insertAtTail(head,3);
    insertAtHead(head,4);
    // Display(head);

    // cout<<search(head,3)<<endl;

    deletion(head,4);
    // Display(head);

    deleteAtHead(head);
    // Display(head);

    node* newhead = reverse(head);
    // Display(newhead);

    node* recur = reverseRecursive(newhead);
    // Display(recur);

    node* revK = reversek(recur, 3);
    Display(revK);


    // makeCycle(revK,2);
    // Display(revK);
    // cout<<detectCycle(revK)<<endl;

    // removeCycle(revK);
    // cout<<detectCycle(revK)<<endl;
    // Display(revK);
    
    node* newList = kappend(revK,2);
    // Display(newList);
    node* head1 = NULL;
    node* head2 = NULL;
   insertAtTail(head1,1);
   insertAtTail(head1,2);
   insertAtTail(head1,3);
   insertAtTail(head1,4);
   insertAtTail(head1,5);
   insertAtTail(head2,6);
   insertAtTail(head2,7);
   insertAtHead(head2,8);
   intersect(head1,head2,3);
//    Display(head1);
//    Display(head2);
//    cout<<intersection(head1,head2)<<endl;

    node* start1=NULL;
    node* start2=NULL;
    int a[]={1,4,5,7};
    int b[]={2,3,6};
    for(int i=0;i<4;i++){
        insertAtTail(start1,a[i]);
    }
    for(int i=0;i<3;i++){
        insertAtTail(start2,b[i]);
    }
    Display(start1);
    Display(start2);
    node* newStart = mergeRecursive(start1,start2);
    Display(newStart);

    evenAfterOdd(newStart);
    Display(newStart);
    return 0;
}