//
//  deque.h
//
//  417001974
//  
//  Created by Kofi McCollin with the use of Dr. John Charley's Code
//
//
//  This Software or code may not be distributed with the intent 
//  of attaning monetary gain
//  This Software can be distrubited with the permission of the 
//  proprietary owner
//
//  Copyright KMax Studios 2020
//  

#ifndef deque_h
#define deque_h
#include "LinkList.h"
#include <iostream>
#include <string>

using namespace std;

class Deque {
private:
    LinkList deque;
    
public:
    bool isEmpty();
    int Size();
    string begin();
    string end();
    string display();
    void push_back(int number, string first, string last, string major, float gpa);
    
    void push_front(int number, string first, string last, string major, float gpa);
    
    string pop_front();
    string pop_back();
    
    void insert(int number, string first, string last, string major, float gpa, int atPos);
    void clear();
    void sRemove(int id) {    deque.specRemove(id);}
    //bool isEmpty(){deque.isEmpty();}
    ~Deque();
    
};

//===========================================================================//
//                   Member functions' definition                            //
//===========================================================================//

bool Deque::isEmpty() {
    if (deque.size() == 0) {
        return true;
    }
    return false;
}

int Deque::Size() {
    cout << "the size is " << deque.size() << endl;
    return deque.size();
}

string Deque::begin() {
    cout << "the front of the double ended queue is: " << deque.displayFront() << endl;
    return deque.displayFront();
}

string Deque::end() {
    cout << "the back of the double ended queue is: " << deque.displayBack() << endl;
    return deque.displayBack();
}

void Deque::push_back(int number, string first, string last, string major, float gpa) {
    if (deque.size() == 0) {
        deque.createANode(number, first, last, major, gpa);
        return;
    }
    deque.addAtBack(number, first, last, major, gpa);
}

void Deque::push_front(int number, string first, string last, string major, float gpa) {
    if (deque.size() == 0) {
        deque.createANode(number, first, last, major, gpa);
        return;
    }
    deque.addAtFront(number, first, last, major, gpa);
}

string Deque::pop_front() {
     return deque.deleteAtFront();
}

string Deque::pop_back() {
    return deque.deleteAtBack();
}

void Deque::insert(int number, string first, string last, string major, float gpa, int atPos) {
    deque.insertAtPosition(number, first, last, major, gpa, atPos);
    
}

string Deque::display() {
    return deque.displayTheList();
}

void Deque::clear() {
    while (deque.size() != 0) {
        deque.deleteAtFront();
    }
}

Deque::~Deque() {
    deque.~LinkList();
}
#endif /* deque_h */
