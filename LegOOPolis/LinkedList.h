#pragma once

#include <iostream>
#include <exception>
#include <cassert>

template <class T>

class Node{

public:
    Node<T> *pNext;
    T data;
};


template <class T>

class LinkedList {
    Node<T> *pHead;
    int size;

public:
    LinkedList(){
        pHead = nullptr;
        size = 0;
    }

    void insertAtEnd(T data){
        try {
            Node<T> *pNewNode = new Node<T>;

            pNewNode->pNext = nullptr;
            pNewNode->data = data;

            if(!pHead){
                pHead = pNewNode;
            } else{
                Node<T> *pNode = pHead;
                while(pNode->pNext){
                    pNode = pNode->pNext;
                }
                pNode->pNext = pNewNode;
            }
        } catch (std::exception& e){
            std::cout << "Couldn't allocate memory for Node. Program will abort!" << std::endl;
            exit(1);
        }

        size++;
    }

    int getSize(){
        /*
        int count = 0;

        Node<T> *pNode = pHead;
        while(pNode){
            count++;
            pNode = pNode->pNext;
        }

        return count;
         */
        return size;
    }

    // Method which determines if a Node containing the parameter's data exists
    bool nodeExists(T data){
        Node<T> *pNode = pHead;
        for (int i = 0; i < size; i++) {
            if (pNode->data == data) {
                return true;
            }
            pNode = pNode->pNext;
        }
        return false;
    }

    // Method which returns the index of the Node, which contains the parameter's data, in the List
    int nodeIndex(T data){
        Node<T> *pNode = pHead;
        for (int i = 0; i < size; i++) {
            if (pNode->data == data){
                return i;
            }
            pNode = pNode->pNext;
        }
        // this return statement should never be executed since the program always checks if such a node
        // with the argument's data exists first before calling this method
        return -1;
    }

    void deleteNodeAtIndex(int index){
        if (index < size){
            if (index == 0){
                Node<T> *pNode = pHead;
                pHead = pNode->pNext;
                delete(pNode);
            } else {
                Node<T> *pNode = pHead;
                Node<T> *prevNode;

                for (int i = 0; i < index; i++) {
                    prevNode = pNode;
                    pNode = pNode->pNext;
                }

                prevNode->pNext = pNode->pNext;
                delete (pNode);
            }

            size--;
        } else {
            std::cout << "index is out of bounds" << std::endl;
        }
    }

    void deleteLinkedList(){
        /*
        Node<T> *pNode = pHead;
        while(pNode){
            delete(pNode);
            pNode = pNode->pNext;
        }
        */
        for (int i = size-1; i >= 0; i--) {
            deleteNodeAtIndex(i);
        }
    }

    Node<T> getNodeAtIndex (int index){
        assert (index < size);

        Node<T> *pNode = pHead;

        for (int i = 0; i < index; i++) {
            pNode = pNode->pNext;
        }

        return *pNode;
    }
};
