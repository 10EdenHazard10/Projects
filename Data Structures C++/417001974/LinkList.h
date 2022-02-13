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
//  Copyright KMax Studios 2020
//  



#ifndef LinkList_h
#define LinkList_h

#include <iostream>
#include "Node.h"


using namespace std;

class LinkList {
    
private:
    Node *front, *back;
    int num_elements;
  
public:
    void createANode(int number, string first, string last, string major, float gpa);
    
    void createABackNode(int number, string first, string last, string major, float gpa);
    
    void addAtBack(int number, string first, string last, string major, float gpa);
    
    void addAtFront(int number, string first, string last, string major, float gpa);
    
    void insertAtPosition(int number, string first, string last, string major, float gpa, int atPos);
    
    string displayBack();
    
    string displayFront();
    
    void traverseList(int number, string first, string last, string major, float gpa);
    
    string deleteAtFront();
    
    string deleteAtBack();
    
    string displayTheList();
    
    void searchList(int number, string first, string last, string major, float gpa);
    bool searchList(int number) ;
    
    Node* getFront();
    
    Node* getBack();
    
    void PQueue(int number, string first, string last, string major, float gpa);
    
    void specRemove(int id);
    
    void rmvhead()
    {
        front = back =  NULL;
        num_elements= 0;
        
    }
    
    void setnum_elements(int x){num_elements = x;}
    
    LinkList() {
        front = NULL;
        back = NULL;
        num_elements = 0;
    }
    
    ~LinkList();
    
    int size();
    bool isEmpty();
};

//===========================================================================//
//                   Member functions' definition                            //
//===========================================================================//

// Done
void LinkList::addAtFront(int number, string first, string last, string major, float gpa) {
    
    
    
    Node* tmp = new Node(number, first, last, major, gpa);
    tmp -> setNextPtr(front);
    front = tmp;
    num_elements++;
}


// Done
void LinkList::createANode(int number, string first, string last, string major, float gpa) {
    Node *tmp = new Node(number, first, last, major, gpa);
    
    
    if (front == NULL) {
        front = back = tmp;
        front -> setNextPtr(NULL);
    }
    else {
        tmp -> setNextPtr(front);
        front = tmp;
        
    }
    num_elements++;
}


void LinkList::insertAtPosition(int number, string first, string last, string major, float gpa, int atPos) {
    Node *tmp = new Node(number, first, last, major, gpa);
    if (atPos == -1 || atPos > num_elements) {
        cout << " This is out of range";
        return;
    }
    Node*next = front;
    Node*cur = new Node;
    
    if (atPos == 1) {
        addAtFront(number, first, last, major, gpa);
        return;
    }
    
    for (int i = 0; i <= num_elements; i++) {
        
        if (atPos == i) {
            cur = next;
            next = next -> getNextPtr();
            cur -> setNextPtr(tmp);
            tmp -> setNextPtr(next);
            
        }
        
        //next = next -> getNextPtr();
    }
    num_elements++;
}

void LinkList::addAtBack(int number, string first, string last, string major, float gpa) {
    if (front == NULL) {
        cout << "Out of range";
        return;
    }
    
    
    Node *tmp = new Node(number, first, last, major, gpa);
    Node *s = front;
    while (s->getNextPtr() != NULL) {
        s = s -> getNextPtr();
    }
    tmp -> setNextPtr(NULL);
    s -> setNextPtr(tmp);
    back = tmp;
    num_elements++;
    
}

string LinkList::deleteAtFront() {
    if (front == NULL) {
        cout  << "out of range";
        return "Empty";
        
    }
    string theString = " ";
    Node *delPtr = new Node;
    Node *tmp = new Node;
    tmp = front;
    theString = front -> getRecord();
    front = front -> getNextPtr();
    delPtr = tmp;
    free(delPtr);
    num_elements--;
    
    return theString;
}

string LinkList::deleteAtBack() {
    if (back == NULL) {
        
        return "out of range";
        
    }
    string theString = "";
    Node *tmp = new Node();
    Node *s = front;
    while (s->getNextPtr() != NULL) {
        tmp = s;
        s = s -> getNextPtr();
        theString = s->getRecord();
    }
    back = tmp;
    free(s);
    tmp -> setNextPtr(NULL);
    
    
    
    return theString;
    
    
    num_elements--;
}

string LinkList::displayFront() {
    if (front == NULL) {
        return "Nothing at the front of the list, Please add to front first.";
        
    }
    Node*tmp = new Node;
    tmp = front;
    
    return tmp -> getRecord();
}



string LinkList::displayBack() {
    if (back == NULL) {
        return "Please add to back first.";
    }
    Node *tmp = back;
    
    return tmp -> getRecord();
}

string LinkList::displayTheList() {
    if (front == NULL) {
        
        return "List is Empty";
    }
    
    Node *tmp = new Node;
    tmp = front;
    string record;
    
    
    while (tmp != NULL) {
        cout << tmp->getRecord() << "-> ";
        record.append(tmp->getRecord());
        record.append("\n");
        tmp=tmp->getNextPtr();
        
    }
   
    
    return record;
}

int LinkList::size() {
    return num_elements;
}

bool LinkList::isEmpty() {
     if(front == NULL)
         return true;
         else
             return false;
}

LinkList::~LinkList() {
    front = NULL;
    back = NULL;
}

void LinkList::searchList(int number, string first, string last, string major, float gpa) 
{
    
    Node *tmp = new Node(number, first, last, major, gpa);
    int counter = 0;
    tmp = front;
    stringstream ss;
    ss << number << ", " << first << " " << last << ", " << major << " " << gpa;
    string theStr = ss.str();
    while (tmp != NULL) {
        
        counter++;
        if (tmp -> getRecord() == theStr) {
            cout << "Element " << tmp -> getRecord();
            cout << " found at position " << counter << endl;
            return;
        }
        tmp = tmp -> getNextPtr();
        
        
    }
    
    
    cout << "Element " << theStr << " not found" << endl;
}




bool LinkList::searchList(int number) 
{
    
    Node *tmp = new Node(number);
    int counter = 0;
    tmp = front;
    stringstream ss;
    ss << number ;
    string theStr = ss.str();
    while (tmp != NULL) {
        
        counter++;
        if (tmp -> getRecordint() == theStr) {
            cout << "Element " << tmp -> getRecord();
            cout << " found at position " << counter << endl;
            return true;
        }
        tmp = tmp -> getNextPtr();
        
        
    }
    
    
    cout << "Element " << theStr << " not found" << endl;
    return false;
}







void LinkList::traverseList(int number, string first, string last, string major, float gpa) {
    Node* ptr = new Node(number, first, last, major, gpa);
    Node* cur = front -> getNextPtr();
    Node *prev = front;
    
    while ( cur != NULL && number >= cur->getID() )
    {
        cur = cur->getNextPtr();
        prev = prev->getNextPtr();
    }
    if (cur == NULL)
        prev->setNextPtr(ptr);
    else
    {
        ptr->setNextPtr(cur);
        prev->setNextPtr(ptr);
    }
    num_elements++;
    
    
    
    
}

Node* LinkList::getBack() {
    return back;
}

Node* LinkList::getFront() {
    return front;
}
void LinkList::PQueue(int number, string first, string last, string major, float gpa){
    
    Node* ptr = new Node(number, first, last, major, gpa);
    Node* cur = front -> getNextPtr();
    Node *prev = front;
    
    while ( cur != NULL && number >= cur->getID() )
    {
        cur = cur->getNextPtr();
        prev = prev->getNextPtr();
    }
    if (cur == NULL)
        prev->setNextPtr(ptr);
    else
    {
        ptr->setNextPtr(cur);
        prev->setNextPtr(ptr);
    }
    num_elements++;
}



void LinkList::specRemove(int id) {
    Node* prev = front;

   if(prev->getID() == id)
   {
       front = prev->getNextPtr();
       delete prev;
       return;
   }
    
    
    while (prev != NULL && prev->getNextPtr() != NULL)
    {
        
        
        if (prev->getNextPtr()->getID() == id) 
        {
            Node* tempPtr = prev->getNextPtr();
            prev->setNextPtr(tempPtr->getNextPtr());
            delete tempPtr;
            return;
        }

        prev = prev->getNextPtr();
    }
}
#endif /* LinkList_hpp */
