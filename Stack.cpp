//
//  Stack.cpp
//  Algorithms
//
//  Created by Fatih Baloglu on 10/04/2017.
//  Copyright © 2017 Fatih Baloglu. All rights reserved.
//

#include <iostream>

using namespace std;

template<class stack>
class Stack
{
private:
    stack data;
    Stack<stack> *next;
    Stack<stack> *head;
public:
    Stack();
    ~Stack();
    void push(stack);
    void pop();
    stack top();
    void printstack();
    bool empty();
};

template<class stack>
Stack<stack>::Stack() : head(NULL), next(NULL) {}

template<class stack>
Stack<stack>::~Stack()
{
    Stack<stack> *temp = head, *temp2;
    while(temp != NULL)
    {
        temp2 = temp;
        temp = temp->next;
        delete temp;
    }
}

template<class stack>
void Stack<stack>::push(stack value)
{
    Stack *temp = new Stack;
    temp->data = value;
    if(head == NULL)
    {
        head = temp;
    }
    else
    {
        temp->next = head;
        head = temp;
    }
}

template<class stack>
void Stack<stack>::pop()
{
    if(head == NULL) cout << "Stack is empty!!";
    else
    {
        Stack *temp = head;
        head = head->next;
        delete temp;
    }
}

template<class stack>
stack Stack<stack>::top()
{
    if(head == NULL) return NULL;
    else return head->data;
}

template<class stack>
void Stack<stack>::printstack()
{
    if(head == NULL) cout << "Stack is empty!!";
    else
    {
        Stack *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << "\t";
            temp = temp->next;
        }
        cout << endl;
    }
}

template<class stack>
bool Stack<stack>::empty()
{
    if(head == NULL) return true;
    else return false;
}
