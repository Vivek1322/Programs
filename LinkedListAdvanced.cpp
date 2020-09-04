#include<bits/stdc++.h>

using namespace std;

class node{
   public:
    int data;
    node * next;

    node(){}
    node(int d){
        data = d;
        next = NULL;
    }
};

void insertAtTail(node* &head, int val){
    if(head==NULL){
        head = new node(val);
        return;
    }
    node * temp = head;
    while(temp->next!=NULL){
        temp= temp->next;
    }
    node * tempo = new node (val);
    temp->next = tempo;
    return;

}

node * mid(node* head){
    if(head==NULL){
        return NULL;
    }
    if(head->next==NULL){
        return head;
    }
    node * slow = head;
    node * fast = head->next;
    while(fast->next!=NULL && fast->next->next!=NULL){
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;

}

node * merge(node * a, node * b){
    ///Base case
    if(a==NULL){
        return b;
    }
    if(b==NULL){
        return a;
    }

    node * c;
    if(a->data<b->data){
        c = a;
        c->next = merge(a->next,b);
    }
    else{
        c = b;
        c->next = merge(a,b->next);
    }
    return c;

}

node* mergeSort(node* head){
    ///Base case
    if(head==NULL || head->next == NULL){
        return head;
    }
    node * m = mid(head);
    node* a = head;
    node * b = m->next;
    m->next = NULL;

    a = mergeSort(a);
    b = mergeSort(b);

    return merge(a,b);

}

node* reverseList(node * head){
    node * p = NULL;
    node * c = head;
    node * n;
    while(c!=NULL){
        n = c->next;
        c->next = p;
        p = c;
        c = n;
    }
    head = p;
    return head;
}

void kReverse(node * &head, int k){
    if(head==NULL || head->next == NULL){
        return;
    }
    node * temp = head;
    while(k-1>0){
        temp = temp->next;
        k--;
    }
    node * a = head;
    node * b = temp->next;
    temp->next = NULL;

    temp = head;
    head = reverseList(a);
    temp->next = reverseList(b);
}

void append(node * &head, int terms){
    if(head==NULL){
        return;
    }
    node * slow = head;
    node * fast = head;
    for(int i=0;i<terms;i++){
        if(fast->next==NULL){
            break;
        }
        fast = fast->next;
    }
    while(fast->next!=NULL){
        fast = fast->next;
        slow = slow->next;
    }
    fast->next = head;
    head = slow->next;
    slow->next = NULL;
}

bool detectCycle(node * head){
    if(head==NULL){
        return false;
    }
    node * slow = head;
    node * fast = head;
    while(fast->next!=NULL && fast->next->next!=NULL){
        fast = fast->next->next;
        slow = slow->next;
        if(slow==fast){
            return true;
        }
    }
    return false;
}

void print(node* head){
    while(head!=NULL){
        cout<<head->data<<"->";
        head = head->next;
    }
    cout<<endl;
    return;
}

void revPrint(node * head){
    if(head==NULL)
        return;
    revPrint(head->next);
    cout<<head->data<<"->";
}

int main(){

    node * head = NULL;

    for(int i=1;i<=7;i++){
        insertAtTail(head, i);
    }
    print(head);
    revPrint(head);
    cout<<endl;
    append(head, 3);
    print(head);

    head = mergeSort(head);
    print(head);

    //head->next->next->next->next = head;

    if(detectCycle(head))
        cout<<"Cycle is present in the linked list.\n";
    else
        cout<<"No cycle is present in the linked list.\n";

    kReverse(head,4);
    print(head);

    return 0;
}
