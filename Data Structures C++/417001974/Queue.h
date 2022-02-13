//
//  Queue.h
//
//  417001974

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


#ifndef Queue_h
#define Queue_h

#include "LinkList.h"
#include <iostream>

using namespace std;

class Queue {
private:
    LinkList Listt;
    
public:
    ~Queue();
    int size(); //tells you the number of items in the ADT
    
    void enqueue(int number, string first, string last, string major, float gpa); //inserts item at the back of queue
    
    string dequeue(); //removes an item from the front of the queue
    
    bool isEmpty()
    {
        if(Listt.size()<=0)
            return true;
            else 
                return false;
        
    } //checks to see if ADT is empty
    
    string front(); //tells us the element at the front of the list without removing it
    
    string back(); // tells us the element at the back of the list without removing it
    
    void clear(); //makes the ADT empty
    
    string displayQueue(); // Displays items in queue
    
    void searchQueue(int number, string first, string last, string major, float gpa); // searches for element in Queue
    
    bool searchQueue(int number);
    
    
   void sRemove(int id);    
    
};

//===========================================================================//
//                   Member functions' definition                            //
//===========================================================================//

int Queue::size() {
    
    
    return Listt.size();
    
    
}

void Queue::searchQueue(int number, string first, string last, string major, float gpa) {
    Listt.searchList(number, first, last, major, gpa);
}

void Queue::enqueue(int number, string first, string last, string major, float gpa) {
    
    if (Listt.size() == 0) {
        Listt.createANode(number, first, last, major, gpa);
        return;
    }
    Listt.addAtBack(number, first, last, major, gpa);
    //return;
}

string Queue::dequeue() {
    
    
        return Listt.deleteAtFront();
    
}


string Queue::front() {
    
   
    return Listt.displayFront();
}

string Queue::back() {
    
    return Listt.displayBack();
}

void Queue::clear() {
    while (Listt.size() != 0) {
        Listt.deleteAtFront();
    }
}
string Queue::displayQueue() {
    
    
    return Listt.displayTheList();
}

Queue::~Queue() {
    Listt.~LinkList();
    Listt.setnum_elements(0);
}

bool Queue::searchQueue(int number)
{
    return (Listt.searchList(number));
}


void Queue::sRemove(int id) 

{
    Listt.specRemove(id);

}


#endif /* Queue_hpp */
