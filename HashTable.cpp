//
//  HashTable.cpp
//  Algorithms
//
//  Created by Fatih Baloglu on 10/04/2017.
//  Copyright © 2017 Fatih Baloglu. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

template<class hashkey, class hashdata>
class Hash
{
private:
    hashkey key;
    hashdata data;
public:
    Hash(hashkey first, hashdata second) : key (first), data(second) { }
    inline hashkey getKey() { return key; }
    inline hashdata getData() { return data; }
};

template<class hashkey, class hashdata>
class HashMap
{
private:
    int TABLE_SIZE;
    Hash<hashkey, hashdata> **table;
public:
    HashMap(int);
    ~HashMap();
    hashdata get(hashkey);
    void put(hashkey, hashdata);
};

template<class hashkey, class hashdata>
HashMap<hashkey, hashdata>::HashMap(int size)
{
    TABLE_SIZE = size;
    table = new Hash<hashkey, hashdata>*[TABLE_SIZE];
    for (int i = 0; i < TABLE_SIZE; i++)
        table[i] = NULL;
}

template<class hashkey, class hashdata>
hashdata HashMap<hashkey, hashdata>::get(hashkey key)
{
    hashkey hashvar = (key % TABLE_SIZE);
    while (table[hashvar] != NULL && table[hashvar]->getKey() != key)
        hashvar = (hashvar + 1) % TABLE_SIZE;
    if (table[hashvar] == NULL)
        return "";
    else
        return table[hashvar]->getData();
}

template<class hashkey, class hashdata>
void HashMap<hashkey, hashdata>::put(hashkey key, hashdata value)
{
    hashkey hashvar = (key % TABLE_SIZE);
    while (table[hashvar] != NULL && table[hashvar]->getKey() != key)
        hashvar = (hashvar + 1) % TABLE_SIZE;
    if (table[hashvar] != NULL)
        delete table[hashvar];
    table[hashvar] = new Hash<hashkey, hashdata>(key, value);
}

template<class hashkey, class hashdata>
HashMap<hashkey, hashdata>::~HashMap()
{
    for (int i = 0; i < TABLE_SIZE; i++)
        if (table[i] != NULL)
            delete table[i];
    delete[] table;
}
