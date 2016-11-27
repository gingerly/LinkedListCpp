//
//  LinkedList.h
//  LinkedList
//
//  Created by Haris Jeelani on 11/27/16.
//  Copyright © 2016 Haris Jeelani. All rights reserved.
//

#ifndef LinkedList_h
#define LinkedList_h

#include <iostream>
#include <exceptions>

// Implement List Class using templates
template <typename T>
class List{
public:
    List();
    ~List();
    void InsertNode(const T &data);
    void RemoveLastNode(const T &data);
    void DisplayList();
    unsigned int Size() const;
    
private:
    template <typename T>
    struct Node{
        Node (const T &d) : data(d), next(NULL) {}
        T data;
        Node *next;
    };
    Node<T> *head;
    Node<T> *tail;
};

//Constructor
template <typename T>
List<T>::List():head(NULL),tail(NULL) {}

//Destructor
template <typename T>
List<T>::~List(){
    Clear();
}

//Insert a node into the List
template <typename T>
void List<T>::InsertNode(const T &data){
    if (head == NULL){
        head = new Node<T>(data);
        tail = head;
        return;
    }
    tail->next = new Node<T>(data);
    tail = tail->next;
    
}

// Remove the last node from the list
template <typename T>
void List<T>::RemoveLastNode(const T &data){
    //Empty List
    if (head==NULL){
        throw std::out_of_range("The List is Empty");
    }
    //List with one element
    if (head == tail){
        delete head;
        head = NULL;
        tail = NULL;
        return;
    }
    
    // Remove node
    Node<T> *current = head;
    while (current->next != tail){
        current = current->next;
    }
    
    delete tail;
    tail = current;
    tail->next = NULL;
}

// Print the complete List
template <typename T>
void List<T>::DisplayList(){
    if (head == NULL){
        throw std::out_of_range("The list is Empty");
    }
    while(head == tail){
        std::cout << head.data << endl;
    }
    return;
}

//Destrutor
template <typename T>
void List<T>::Clear(){
    Node<T> *current = head;
    while (head){
        current = head;
        head = head->next;
        delete current;
    }
    head = NULL;
    tail = NULL;
}
#endif /* LinkedList_h */
