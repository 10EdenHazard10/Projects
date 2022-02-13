//
//  pQueue.h
//
//  417001974
//  LinkList.h
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
//
/*************************************************************************
 *
 * 
 */

#ifndef pQueue_h
#define pQueue_h

#include "LinkList.h"
#include <iostream>
#include <string>

using namespace std;

class PQueue {
private:
    LinkList PQ;
    
public:
    bool isEmpty();
    int Size();
    string highestPriority();
    string end();
    string display();
    void push_back(int number, string first, string last, string major, float gpa);
    string pop_front();
    void clear();
    ~PQueue();
    bool searchPQueue(int);
    void removehead();
    void sRemove(int id) {    PQ.specRemove(id);}
};


//===========================================================================//
//                   Member functions' definition                            //
//===========================================================================//

bool PQueue::isEmpty() {
    if (PQ.size() == 0)
    {
        return true; 
        
    }
    return false;
}

int PQueue::Size() {
    return PQ.size();
}

void PQueue::push_back(int number, string first, string last, string major, float gpa) {
    
    
    
    
    
    if (PQ.size() == 0) {
        PQ.createANode(number, first, last, major, gpa);
        return;
    }
    if (number < PQ.getFront() -> getID()) {
        PQ.addAtFront(number, first, last, major, gpa);
        return;
    }
    if (number >= PQ.getFront() -> getID() && PQ.getFront() -> getNextPtr() == NULL) {
        PQ.addAtBack(number, first, last, major, gpa);
        return;
    }
    PQ.traverseList(number, first, last, major, gpa);
    
    
}

string PQueue::pop_front() {
    return PQ.deleteAtFront();
}

string PQueue::display() {
    return PQ.displayTheList();
}

void PQueue::clear() {
    while (Size() != 0) {
        pop_front();
    }
}

string PQueue::highestPriority() {
    return PQ.displayFront();
}

string PQueue::end() {
    return PQ.displayBack();
}

PQueue::~PQueue() {
    PQ.~LinkList();
}

bool PQueue::searchPQueue(int number)
{
    return (PQ.searchList(number));
}

void PQueue::removehead()
{
    PQ.rmvhead();
    
}


#endif /* pQueue_h */
