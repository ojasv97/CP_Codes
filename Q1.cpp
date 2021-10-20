#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
        int data;
        Node *next;
        Node(int data){
            this->data = data;
            this->next = nullptr;
        }
};
class Linked_list{
    public:
        Node* head;
        Linked_list(){
            this->head = nullptr;
        }
        Node* insert(int data){
            if(this->head==nullptr){
                Node *temp = new Node(data);
                head = temp;
            }
            else{
                Node *p = this->head;
                while(p->next!=nullptr){p = p->next;}
                Node *temp = new Node(data);
                p->next = temp;
            }
            return this->head;
        }
        void display(){
            cout<<"In straight order"<<endl;
            Node *p = this->head;
            while(p!=nullptr){cout<<p->data<<" ";p = p->next;}
            cout<<endl;
        }
        void reverse_display(Node* p){
            if(p->next==nullptr){
                cout<<"In reversed order"<<endl;
                cout<<p->data<<" ";
            }
            else{
                reverse_display(p->next);
                cout<<p->data<<" ";
            }
        }
};
int main(){
    Linked_list l = Linked_list();
    l.insert(4);
    l.insert(5);
    l.insert(3);
    l.insert(9);
    l.display();
    l.reverse_display(l.head);
    return 0;
}