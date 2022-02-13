//
//  stack.h
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
//  2020
//  


#ifndef stack_h
#define stack_h
#include "LinkList.h"
#include <iostream>
#include <string>

using namespace std;

class stack {
private:
    LinkList Stack;
    
public:
    bool isEmpty(); // tells us if the stack is empty.
    int Size(); // tells us the size of the Stack.
    string top(); // tells us the top of the the stack without removing it.
    void push(int number, string first, string last, string major, float gpa); // Pushes an element on the top of the stack.
    string displayStack(); // displays the elements in the stack.
    string pop(); // pops the top of the stack.
    void clear(); // clears the stack from the front.
    void searchStack(int number, string first, string last, string major, float gpa);
    bool searchStack(int number);
    ~stack();
    
    void sRemove(int id) {Stack.specRemove(id);}


};



//===========================================================================//
//                   Member functions' definition                            //
//===========================================================================//


bool stack::isEmpty() {
    if (Stack.size() == 0) {
        return true;
    }
    return false;
}

int stack::Size() {
    return Stack.size();
}

string stack::top() {
    cout << "The top of the stack is: ";
    cout << Stack.displayFront() << endl;
    return Stack.displayFront();
}

void stack::push(int number, string first, string last, string major, float gpa) {
    
    if (Stack.size() == 0) {
        Stack.createANode(number, first, last, major, gpa);
        return;
    }
    Stack.addAtFront(number, first, last, major, gpa);
    
    
}

string stack::pop() {
    
        return Stack.deleteAtFront();
    
}

void stack::clear() {
    while (Stack.size() != 0) {
        Stack.deleteAtFront();
    }
}



string stack::displayStack() {
    cout << "The Stack is " << endl;
    
    return Stack.displayTheList();
}

void stack::searchStack(int number, string first, string last, string major, float gpa) {
    Stack.searchList(number, first, last, major, gpa);
}

bool stack::searchStack(int number)
{
    return Stack.searchList(number);
}

stack::~stack() {
    Stack.~LinkList();
}
#endif /* stack_h */
