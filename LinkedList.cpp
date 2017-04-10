//
//  LinkedList.cpp
//  Algorithms
//
//  Created by Fatih Baloglu on 10/04/2017.
//  Copyright © 2017 Fatih Baloglu. All rights reserved.
//

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <time.h>

using namespace std;

template <class List>
class LinkedList
{
private:
    List data;
    int length;
    LinkedList<List>* head;
    LinkedList<List>* tail;
    LinkedList<List>* next;
    LinkedList<List>* prev;
    LinkedList* partition(LinkedList *, LinkedList *);
    void _quickSort(LinkedList* , LinkedList *);
    
    LinkedList* merge(LinkedList* , LinkedList*);
    LinkedList* mergesort(LinkedList*);
    LinkedList* split(LinkedList*);
    
    inline void swap(LinkedList *first, LinkedList *second) { second->data = (first->data + second->data) - (first->data = second->data); }
    
    inline bool isbefore(List, List);
    inline void stringswap(LinkedList *first, LinkedList *second) { List temp; temp = first->data; first->data = second->data; second->data = temp; }
    void ascsort();
public:
    LinkedList();
    ~LinkedList();
    void addNext(List);
    void insertAfter(List, List);
    void addfromHead(List);
    void printList();
    void removeData(List);
    void deletefromHead();
    void deletefromTail();
    inline int getlength() { return length; }
    
    void quickSort();
    void mergeSort();
    void ascendingsort();
};

template<class List>
LinkedList<List>::LinkedList() : head(NULL), tail(NULL), next(NULL), prev(NULL), length(0) {}

template<class List>
LinkedList<List>::~LinkedList()
{
    LinkedList<List> *temp = head, *temp2;
    while(temp != NULL)
    {
        temp2 = temp;
        delete temp2;
        temp = temp->next;
    }
}

template<class List>
void LinkedList<List>::addNext(List value)
{
    LinkedList *temp = new LinkedList;
    temp->data = value;
    if(head == NULL)
    {
        head = temp;
        tail = temp;
    }
    else
    {
        temp->prev = tail;
        tail->next = temp;
        tail = temp;
    }
    length++;
}

template<class List>
void LinkedList<List>::addfromHead(List value)
{
    LinkedList *temp = new LinkedList;
    temp->data = value;
    if(head == NULL)
    {
        head = temp;
        tail = temp;
    }
    else
    {
        temp->next = head;
        head = temp;
    }
    length++;
}

template<class List>
void LinkedList<List>::insertAfter(List after, List value)
{
    LinkedList *temp = new LinkedList;
    LinkedList *temp2 = head, *temp3;
    temp->data = value;
    while(temp2 != NULL)
    {
        if(temp2->data == after)
        {
            temp3 = temp2->next;
            temp2->next = temp;
            temp->prev = temp2;
            temp->next = temp3;
            temp3->prev = temp;
        }
        temp2 = temp2->next;
    }
    length++;
}

template<class List>
void LinkedList<List>::deletefromHead()
{
    if(head == NULL) cout << "List is empty!!";
    else
    {
        LinkedList *temp = head;
        head = head->next;
        delete temp;
    }
}

template<class List>
void LinkedList<List>::deletefromTail()
{
    if(head == NULL) cout << "List is empty!!";
    else
    {
        LinkedList *temp = tail;
        tail = tail->prev;
        delete temp;
    }
}

template<class List>
void LinkedList<List>::removeData(List value)
{
    LinkedList *temp = head, *temp2;
    bool flag = false;
    while(temp != NULL)
    {
        if(temp->data == value)
        {
            flag = true;
            temp2 = temp;
            temp = temp->prev;
            temp->next = temp2->next;
            temp = temp2->next;
            temp->prev = temp2->prev;
            delete temp2;
        }
        temp = temp->next;
    }
    if(!flag) cout << "There is not such a value of : " << value << endl;
    else length--;
}

template<class List>
void LinkedList<List>::printList()
{
    LinkedList *temp = head;
    while(temp != NULL)
    {
        cout << temp->data << "\t";
        temp = temp->next;
    }
    cout << endl;
}

template<class List>
LinkedList<List>* LinkedList<List>::partition(LinkedList *a, LinkedList *b)
{
    int x  = b->data;
    LinkedList *c = a->prev;
    for (LinkedList *d = a; d != b; d = d->next)
    {
        if (d->data <= x)
        {
            c = (c == NULL)? a : c->next;
            swap(c, d);
        }
    }
    c = (c == NULL)? a : c->next;
    swap(c, b);
    return c;
}

template<class List>
void LinkedList<List>::_quickSort(LinkedList* a, LinkedList *b)
{
    if (b != NULL && a != b && a != b->next)
    {
        LinkedList *c = partition(a, b);
        _quickSort(a, c->prev);
        _quickSort(c->next, b);
    }
}

template<class List>
void LinkedList<List>::quickSort()
{
    _quickSort(head, tail);
}

template<class List>
LinkedList<List>* LinkedList<List>::merge(LinkedList *first, LinkedList *second)
{
    if (!first)
        return second;
    
    if (!second)
        return first;
    
    if (first->data < second->data)
    {
        first->next = merge(first->next,second);
        first->next->prev = first;
        first->prev = NULL;
        return first;
    }
    else
    {
        second->next = merge(first,second->next);
        second->next->prev = second;
        second->prev = NULL;
        return second;
    }
}

template<class List>
LinkedList<List>* LinkedList<List>::mergesort(LinkedList *temp)
{
    if (!temp || !temp->next)
        return temp;
    LinkedList *second = split(temp);
    temp = mergesort(temp);
    second = mergesort(second);
    
    return merge(temp,second);
}

template<class List>
LinkedList<List>* LinkedList<List>::split(LinkedList *temp)
{
    LinkedList *fast = temp, *slow = temp;
    while (fast->next && fast->next->next)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    LinkedList *temp2 = slow->next;
    slow->next = NULL;
    return temp2;
}

template<class List>
void LinkedList<List>::mergeSort()
{
    mergesort(head);
}

template<class List>
void LinkedList<List>::ascendingsort()
{
    if(head == NULL) cout << "List is empty!!" << endl;
    else ascsort();
}

template<class List>
void LinkedList<List>::ascsort()
{
    LinkedList *temp = head;
    while(temp->next != NULL)
    {
        LinkedList *temp2 = temp->next;
        while(temp2 != NULL)
        {
            if (isbefore(temp->data, temp2->data))
                stringswap(temp, temp2);
            temp2 = temp2->next;
        }
        temp = temp->next;
    }
}

template<class List>
inline bool LinkedList<List>::isbefore(List first, List second)
{
    if(strcmp(first.c_str(), second.c_str()) > 0) return true;
    else return false;
}
