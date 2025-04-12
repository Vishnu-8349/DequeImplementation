#include<iostream>
using namespace std;
class Node{
public:
    int val;
    Node* next;
    Node* prev;
    Node(int val){
        this->val=val;
        this->prev=NULL;
        this->next=NULL;
    }
};
class Deque{
public:
    Node* head;
    Node* tail;
    int s;
    Deque(){
        head=tail=NULL;
        this->s=0;
    }

    void pushBack(int val){
        Node* temp = new Node(val);
        if(s==0) head=tail=temp;
        else{
            tail->next=temp;
            temp->prev=tail;
            tail=temp;
        }
        s++;
    }

    void pushFront(int val){
        Node* temp = new Node(val);
        if(s==0) head=tail=temp;
        else{
            temp->next=head;
            head->prev=temp;
            head=temp;
        }
        s++;
    }
    void popFront(){
        if(s==0){
            cout<<"Deque is empty"<<endl;
            return;
        }
        else if(s==1){
            head=head->next;
            if(head!=NULL) head->prev=NULL;  //extra  (basically for the whose size is one)
            if(head==NULL) tail=NULL;
        }
        else{
            head=head->next;
            head->prev=NULL;
        }
        s--;
    }

    void popBack(){
        if(s==0){
            cout<<"Deque is empty"<<endl;
            return;
        }
        else if(s==1){
            tail=tail->prev;
            if(tail!=NULL) tail->next=NULL;    //extra
            if(tail==NULL) head=NULL;
        }
        else{
            tail=tail->prev;
            tail->next=NULL;
        }
        s--;
    }
    int front(){
        if(s==0){
            cout<<"Deque is empty!"<<endl;
            return -1;
        }
        return head->val;
    }
    int back(){
        if(s==0){
            cout<<"Deque is empty!"<<endl;
            return -1;
        }
        return tail->val;
    }
    bool isEmpty(){
        if(s==0) return true;
        return false;
    }
    int size(){
        return s;
    }
    void display(){
        Node* temp = head;
        while(temp!=NULL){
            cout<<temp->val<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
};
int main(){
    Deque q;
    q.popBack();
    q.pushBack(10);
    q.pushBack(20);
    q.pushBack(30);
    q.pushBack(40);
    q.display();
    q.pushFront(1);
    q.display();
    q.popFront();
    q.display();
    q.popBack();
    q.display();
}