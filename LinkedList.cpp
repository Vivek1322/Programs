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

void insertAtK(node * &head, int val, int k){
    if(head==NULL){
        node * temp = new node(val);
        head = temp;
        return;
    }
    node * temp = head;
    int jumps = 0;

    while(jumps<k-2){
        if(temp->next == NULL){
            node * tempo = new node(val);
            temp->next = tempo;
            return;
        }
        temp = temp->next;
        jumps++;
    }
    node * tempo = new node(val);
    tempo->next = temp->next;
    temp->next = tempo;

    return;

}

node* deleteAtK(node * head, int k){
    if(head==NULL){
        return NULL;
    }
    if(k==1){
        ///delete
        node * temp = head;
        head = temp->next;
        delete temp;
        return head;
    }
    if(k==2){
        node * temp = head->next;
        head->next = temp->next;
        delete temp;
        return head;

    }
    head->next = deleteAtK(head->next, k-1);
    return head;

}

void duplicates(node* &head){
    node * temp = head;
    while(temp->next!=NULL){
        if(temp->data == temp->next->data){
            ///delete the next node
            node * del = temp->next;
            temp->next = del->next;
            delete del;
            continue;
        }
        temp = temp->next;
    }
    return;
}

int mid(node* head){
    if(head==NULL){
        return NULL;
    }
    if(head->next==NULL){
        return head->data;
    }
    node * slow = head;
    node * fast = head->next;
    while(fast->next!=NULL && fast->next->next!=NULL){
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow->data;

}

bool palindrome(node * head){
    if(head == NULL){
        return true;
    }
    stack<int> s;
    node * temp = head;
    while(head!=NULL){
        s.push(head->data);
        head = head->next;
    }
    while(temp!=NULL){
        if(s.top()!=temp->data)
            return false;
        temp = temp->next;
        s.pop();
    }
    return true;

}

node* recReverseList(node * head){
    node * temp = head;
    if(temp==NULL || temp->next==NULL){
        head = temp;
        return head;
    }
    head = recReverseList(temp->next);
    temp->next->next = temp;
    temp->next = NULL;

    return head;
}

void reverseList(node * &head){
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
}

void swapNodes(node* &head, int a, int b){
    if(a==1 && b==1)
        return;
    if(a>b){
        swapNodes(head, b, a);
        return;
    }
    node * temp1 = head;
    node * temp2 = head;
    int jumps =0;
    while(jumps<a-2){
        jumps++;
        temp1 = temp1->next;
    }
    jumps = 0;
    while(jumps<b-2){
        jumps++;
        temp2 = temp2->next;
    }
    if(a==1){
        node * m = temp1;
        node * n = temp2->next;
        node * p = n->next;
        n->next = m->next;
        temp2->next = m;
        m->next = p;
        head = n;
    }
    else{
        node * m = temp1->next;
        node * n = temp2->next;
        temp1->next = n;
        temp2->next = m;
        node * p = m->next;
        m->next = n->next;
        n->next = p;
    }
}

void print(node* head){
    while(head!=NULL){
        cout<<head->data<<"->";
        head = head->next;
    }
    cout<<endl;
    return;
}


int main(){

    node * head = NULL;
    for(int i=1;i<=7;i++){
        insertAtTail(head, i);
        if(i==7){
            insertAtTail(head, i);
        }
    }
    print(head);
    int m1 = mid(head);
    cout<<m1<<endl;
    insertAtK(head, 69, 6);
    print(head);
    int m2 = mid(head);
    cout<<m2<<endl;
    head = deleteAtK(head, 6);
    print(head);
    duplicates(head);
    print(head);
    reverseList(head);
    print(head);
    head = recReverseList(head);
    print(head);
    swapNodes(head, 2, 5);
    print(head);

    node * head2 = NULL;
    for(int i=1;i<5;i++){
        insertAtTail(head2, i);
    }
    for(int i=5;i>0;i--){
        insertAtTail(head2,i);
    }
    print(head2);
    if(palindrome(head2)){
        cout<<"Palindrome linked list";
    }
    else{
        cout<<"Not a palindrome linked list";
    }

    return 0;
}
