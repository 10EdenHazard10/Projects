//
//  Heap.h
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

#ifndef Heap_h
#define Heap_h

// appending to string
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class BHNode
{
private:
    int idNo;
    string name;
    string surname;
    string major;
    float gpa;
    
    
    
    
    BHNode* nextPtr;
    
public:
    // Constructor functions
    BHNode() {idNo = gpa = 0; name = surname = major = ""; nextPtr = NULL;}
    BHNode(int error, float error1) {idNo = error; gpa = error1; name = surname = major = ""; nextPtr = NULL;}
    
    BHNode(int, string fn, string ln, string maj, float mark );
    
    // Accessor functions;
    int getID() {return idNo;}
    string getName() {return name;}
    string getSurname() {return surname;}
    string getMajor() {return major;}
    float getGPA() {return gpa;}
    BHNode* getNext()  {return nextPtr;}
    
    //Mutator Functions
    void setID(int id) {idNo = id;}
    void setFName(string fn) {name = fn;}
    void setLName(string ln) {surname = ln;}
    void setMajor(string maj) {major = maj;}
    void setMark(float mark) { gpa = mark;}
    
    void setNxt(BHNode* nx) {nextPtr = nx;}
    
    
};
//===========================================================================
//          Member functions' definition
//===========================================================================

BHNode::BHNode(int id, string fn, string ln, string maj, float mark) {
    idNo = id; name = fn; surname = ln; major = maj; gpa = mark; nextPtr = NULL;
}






class Heap
{
private:
    vector <BHNode*> elements;
    
public:
    // Constructor Function
    Heap () { elements.resize(1); }
    
    //void Purge ( void ) { string purge = sortMinHeap(); }
    
    // Mutator Functions
    void addMinHeap(int, string, string, string, float);   // Add to MinHeap
    void minHeapify(unsigned int);      // Heapify MinHeap
    void deleteMinHeapVal(int);         // Delete element from MinHeap
    void removeMinRoot();
    string sortMinHeap();
    string to_String ( int i );
    string to_String ( float i );
    
    void setData ( vector <BHNode*> data ) { elements = data; }
    
    //Accessor Function
    string displayHeap();
    string getLeftID  ( int  );
    string getRightID ( int  );
    int    Size       ( void )  { return elements.size(); }
    bool   find       ( int, string );
    int    getIDAt      ( int i ) { return elements[i]->getID();    }
    string getFnameAt ( int i ) { return elements[i]->getName(); }
    string getLnameAt ( int i ) { return elements[i]->getSurname(); }
    string getMajorAt ( int i ) { return elements[i]->getMajor(); }
    float  getGPAAt   ( int i ) { return elements[i]->getGPA();   }
    bool isEmpty(){return Size() <= 1;}
    
    vector <BHNode*> getData ( void ) { return elements; }
};

//===================================================================================
// Add new element to MinHeap
//===================================================================================
void Heap::addMinHeap(int id, string fn, string ln, string maj, float mark)
{
    BHNode* element = new BHNode(id, fn, ln, maj, mark);
    elements.push_back(element);
    minHeapify(elements.size() - 1);
}

//===================================================================================
// Recursive heapify function for a MinHeap
//===================================================================================
void Heap::minHeapify(unsigned int index)
{
    unsigned int left, right, minn;
    left = 2*index;
    right = (2*index) + 1;
    
    // Base case
    if (index == 0)
        return;
    
    // Check the children if they exist and pick the larger for swapping
    if ( left < elements.size() && elements[left]->getID() < elements[index]->getID() )
        minn = left;
    else
        minn = index;
    
    if ( right < elements.size() && elements[right]->getID() < elements[minn]->getID() )
        minn = right;
    
    if (minn != index)
    {
        BHNode* temp = elements[minn];
        elements[minn] = elements[index];
        elements[index] = temp;
        minHeapify(minn);
    }
    
    // Now check the parent, if it exists
    minHeapify(index/2);
}

//===================================================================================
// Delete function for a MinHeap
//===================================================================================
void Heap::deleteMinHeapVal(int id)
{
    int x = 1;
    
    while ( x < elements.size() )
    {
        if ( id == elements[x]->getID() )
        {
            elements[x] = elements[ (elements.size() - 1) ];
            
            elements.pop_back();
            
            minHeapify(x);              // parent
            minHeapify(2 * x);             // left child
            minHeapify((2 * x) + 1 );   // right child
            break;      //No need to search further
        }
        x++;
    }
}

//===================================================================================
// Remove root function for a MinHeap
//===================================================================================
void Heap::removeMinRoot()
{
    if (elements.size() < 2)
        return;
    else
    {
        elements[1] = elements[elements.size() - 1];
        elements.resize(elements.size() - 1);
        minHeapify(1);
    }
    
}

//===================================================================================
// Sort function for a MinHeap
//===================================================================================
string Heap::sortMinHeap()
{
    string str ="";
    
    while (elements.size() > 1)
    {
        str.append( to_String( elements[1]->getID() ) );
        str.append(" [");
        str.append( getLeftID(1) );
        str.append(", ");
        str.append( getRightID(1) );
        str.append("]\t   ");
        
        string FName = elements[1]->getName();
        while (FName.size() < 20)
        {
            FName.append(" ");
        }
        str.append( FName );
        
        string LName = elements[1]->getSurname();
        while (LName.size() < 20)
        {
            LName.append(" ");
        }
        str.append( LName );
        
        string theMajor = elements[1]->getMajor();
        while (theMajor.size() < 20)
        {
            theMajor.append(" ");
        }
        str.append( theMajor );
        
        string theGPA = to_String(elements[1]->getGPA());
        while (theGPA.size() < 20) {
            theGPA.append(" ");
        }
        str.append(theGPA);
        
        
        
        str.append("\n");
        
        removeMinRoot();
    }
    return str;
}

string Heap::to_String ( int i )
{
    stringstream ss;
    ss << i;
    return ss.str();
}

string Heap::displayHeap()
{
    string str = "";
    
    for (int x = 1; x < elements.size(); x++)
    {
        str.append( to_String( elements[x]->getID() ) );
        str.append(" [");
        str.append( getLeftID(x) );
        str.append(", ");
        str.append( getRightID(x) );
        str.append("]\t   ");
        
        string FName = elements[x]->getName();
        while (FName.size() < 20)
        {
            FName.append(" ");
        }
        str.append( FName );
        
        string LName = elements[x]->getSurname();
        while (LName.size() < 20)
        {
            LName.append(" ");
        }
        str.append( LName );
        
        string theMajor = elements[x]->getMajor();
        while (theMajor.size() < 20)
        {
            theMajor.append(" ");
        }
        str.append( theMajor );
        
        string theGPA = to_String(elements[x]->getGPA());
        while (theGPA.size() < 20) {
            theGPA.append(" ");
        }
        str.append(theGPA);
        
        
        str.append("\n");
    }
    return str;
}

string Heap::getLeftID ( int index )
{
    if ( ((2*index)+1) > elements.size() )
        return "NULL        ";
    else
        return to_String( elements[(2*index)]->getID() );
}



string Heap::getRightID ( int index )
{
    if ( ((2*index)+2) > elements.size() )
        return "        NULL";
    else
        return to_String( elements[(2*index)+1]->getID() );
}

bool Heap::find ( int id, string fn )
{
    for (int i = 1; i < elements.size(); i++)
    {
        if (elements[i]->getID() == id && elements[i]->getName() == fn)
            return true;
    }
    return false;
}





string Heap::to_String (float i)
{
    std::stringstream ss;
    ss << i;
    return ss.str();
}
#endif /* Heap_h */
