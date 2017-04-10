//
//  Queue.cpp
//  Algorithms
//
//  Created by Fatih Baloglu on 10/04/2017.
//  Copyright © 2017 Fatih Baloglu. All rights reserved.
//

#include <iostream>

using namespace std;

template<class queue>
class Queue
{
private:
    queue data;
    Queue<queue> *head;
    Queue<queue> *next;
public:
    Queue();
    ~Queue();
    void enqueue(queue);
    void dequeue();
    void printqueue();
};

template<class queue>
Queue<queue>::Queue() : head(NULL), next(NULL) {}

template<class queue>
Queue<queue>::~Queue()
{
    Queue<queue> *temp = head, *temp2;
    while(temp != NULL)
    {
        temp2= temp;
        temp = temp->next;
        delete temp;
    }
}

template<class queue>
void Queue<queue>::enqueue(queue value)
{
    Queue *temp = new Queue;
    temp->data = value;
    if(head == NULL)
    {
        head = temp;
    }
    else
    {
        Queue *temp2 = head;
        while(temp2->next != NULL)
        {
            temp2 = temp2->next;
        }
        temp2->next = temp;
    }
}

template<class queue>
void Queue<queue>::dequeue()
{
    if(head == NULL) cout << "Queue is empty!!";
    else
    {
        Queue *temp = head;
        head = head->next;
        delete temp;
    }
}

template<class queue>
void Queue<queue>::printqueue()
{
    if(head == NULL) cout << "Queue is empty!!";
    else
    {
        Queue *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << "\t";
            temp = temp->next;
        }
        cout << endl;
    }
}
