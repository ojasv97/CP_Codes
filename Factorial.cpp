#include<bits/stdc++.h>
using namespace std;
struct node{
    int data;
    node* next = nullptr;
    node* prev = nullptr;
};
node* calculate(int x,node* tail, node* head){
  int carry = 0;
  node* temp = head;
  while(temp!=nullptr){
    int prod = (temp->data)*x + carry;
    temp->data = prod%10;
    carry = prod/10;
    temp=temp->next;
  }
  while(carry)
  {
    node* n = new node();
    n->prev = tail;
    tail->next = n;
    n->data = carry%10;
    tail = n;
    carry = carry/10;
  }
  return tail;
}
int main(){
    int n;
    cout<<"Enter the number"<<endl;
    cin>>n;
    node* head = new node();
    head->data=1;
    node* tail = head;
    for(int i=2;i<=n;i++){
      tail = calculate(i,tail,head);
    }
    while(tail!=nullptr){
        cout<<tail->data;
        tail=tail->prev;
    }
    cout<<"\n";
    return 0;
}
