#include<bits/stdc++.h>
using namespace std;

// Node of the Linked List
class Node{
    public:
        int data;
        Node *next;
        Node(int data){
            this->data = data;
            this->next = nullptr;
        }
};

// Linked List implementation.
class stackUsingLinkedList{
    public:
        Node* top;
        stackUsingLinkedList(){
            this->top = nullptr;
        }
        void push(int data){
            if(this->top==nullptr){
                Node *temp = new Node(data);
                top = temp;
            }
            else{
                Node *temp = new Node(data);
                temp->next = top;
                top = temp;
            }
        }

        int pop(){
            if(this->top==nullptr){
                cout<<"Stack is empty"<<endl;
            }
            else{
                int val = top->data;
                Node *temp = top;
                top = top->next;
                delete(temp);
                return val;
            }
            return -1;
        }

        void display(){
            cout<<"Top";
            Node* p = top;
            while(p){
                cout<<"--> "<<p->data<<" ";
                p=p->next;
            }
            cout<<endl;
        }
};

// Function to evaluate the result in evaluatePrefix function.
int evaluate(int op1, int op2, char opr){
    if(opr=='+'){
        return op1+op2;
    }
    else if(opr=='-'){
        return op1-op2;
    }
    else if(opr=='/'){
        return op1/op2;
    }
    else if(opr=='*'){
        return op1*op2;
    }
    return -1;
}

// Data type of the expression vector.
class valDataType{
    public:
        int value;
        char value_;
        bool isOperator = false;
        bool isOperand = false;
        valDataType(int value){
            this->value = value;
            this->isOperand=true;
        }
        valDataType(char value_){
            this->value_ = value_;
            this->isOperator = true;
        }
};

// Function to solve and prefix expression.

int evaluatePrefix(vector<valDataType> expr){
    // vector<valDataType> expr is a vector containing both operators and operands.
    stackUsingLinkedList st = stackUsingLinkedList();
    for(int i=expr.size()-1;i>=0;i--){
        if(expr[i].isOperand==true){
            st.push(expr[i].value);
        }
        else if(expr[i].isOperator==true){
            char opr = expr[i].value_;
            int op1 = st.pop();
            int op2 = st.pop();
            int res = evaluate(op1,op2,opr);
            st.push(res);
        }
    }
    return st.pop();
}

int main(){

// Showing the functioning of Stack using Linked List.

    stackUsingLinkedList st = stackUsingLinkedList();
    st.push(5);
    st.display();
    st.push(8);
    st.display();
    st.push(4);
    st.display();
    st.push(9);
    st.display();
    while(st.top!=nullptr){
        st.pop();
        st.display();
    }

// Evaluating a prefix expression using Stack.

    vector<valDataType> expr{'-','+','*',2,3,'*',5,4,9};
    int ans = evaluatePrefix(expr);
    cout<<ans;
    return 0;
}