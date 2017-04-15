//
//  BinaryTree.cpp
//  Algorithms
//
//  Created by Fatih Baloglu on 11/04/2017.
//  Copyright © 2017 Fatih Baloglu. All rights reserved.
//

#include <iostream>

using namespace std;

class BTree
{
private:
    int data;
    BTree *right, *left, *root;
    
    void insert(int value, BTree *leaf)
    {
        if(value < leaf->data)
        {
            if(leaf->left != NULL)
                insert(value,leaf->left);
            else
            {
                leaf->left = new BTree;
                leaf->left->data = value;
                leaf->left->left = NULL;
                leaf->left->right = NULL;
            }
        }
        else if(value > leaf->data)
        {
            if(leaf->right != NULL)
                insert(value,leaf->right);
            else
            {
                leaf->right = new BTree;
                leaf->right->data = value;
                leaf->right->left = NULL;
                leaf->right->right = NULL;
            }
        }
    }
    
    
    BTree *search(int value, BTree *leaf)
    {
        if(leaf != NULL)
        {
            if(value == leaf->data)
                return leaf;
            if(value < leaf->data)
                return search(value, leaf->left);
            else
                return search(value, leaf->right);
        }
        else return NULL;
    }
    void destroytree(BTree *leaf)
    {
        if(leaf != NULL)
        {
            destroytree(leaf->left);
            destroytree(leaf->right);
            delete leaf;
        }
    }
    
    void depthfirtsSearch(BTree *leaf)
    {
        if(leaf)
        {
            if(leaf->left)
            {
                depthfirtsSearch(leaf->left);
            }
            if(leaf->right)
            {
                depthfirtsSearch(leaf->right);
            }
            cout << leaf->data << "\t";
        }
    }
    
    int nodecount(BTree *leaf)
    {
        if (leaf == NULL)
            return 0;
        else
        {
            int count = 1;
            count += nodecount(leaf->left);
            count += nodecount(leaf->right);
            return count;
        }
    }
    
    void postorder(BTree *leaf)
    {
        if (leaf != NULL)
        {
            postorder(leaf->left);
            postorder(leaf->right);
            cout << leaf->data << "\t";
        }
    }
    
    void preorder(BTree *leaf)
    {
        if (leaf != NULL)
        {
            cout << leaf->data << "\t";
            preorder(leaf->left);
            preorder(leaf->right);
        }
    }
    
    void inorder(BTree *leaf)
    {
        if (leaf != NULL)
        {
            inorder(leaf->left);
            cout << leaf->data << "\t";
            inorder(leaf->right);
        }
    }
public:
    BTree() : right(NULL), left(NULL), root(NULL) {}
    ~BTree() { destroytree(); }
    
    void insert(int value)
    {
        if(root != NULL)
            insert(value, root);
        else
        {
            root = new BTree;
            root->data = value;
            root->left = NULL;
            root->right = NULL;
        }
    }
    BTree *search(int value)
    {
        return search(value, root);
    }
    inline void destroytree() { destroytree(root); }
    inline void printTree() { depthfirtsSearch(root); }
    inline int nodecount() { return nodecount(root); }
    inline void postorder() { postorder(root); }
    inline void preorder() { preorder(root); }
    inline void inorder() { inorder(root); }
};
