//  417001974
//  Node.h
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


#ifndef NODE_H
#define NODE_H

// appending to string
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class Node
    {
        private:
            int idNo;
            string name;
            string surname;
        string Major;
        float Gpa;
        //string theSeason;
        
        
            Node* nextPtr;
        
        public:
            // Constructor functions
            Node();
            Node(int, string, string, string, float);
            Node(int);
        
            // Accessor functions;
            string getName();
            string getRecord();
            
            string getRecordint();
            // You need to write that function!
            string getMajor() {return Major;}
            int getID() { return idNo;}      // Inline function
            Node* getNextPtr() { return nextPtr;}   // Inline function
            string getSurname(){return surname;}
            float getGPA(){return Gpa;}
            //Mutator functions
            void setData(int, string, string, string, float);
            void setNextPtr(Node* ptr) { nextPtr = ptr;}   // Inline function
    };
#endif // NODE_H



//===========================================================================
//          Member functions' definition
//===========================================================================

Node::Node()
    {
        idNo = 0;
        name = "";
        surname = "";
        Major = "";
        Gpa = 0;
        
        nextPtr = NULL;
    }




Node::Node(int number, string first, string last, string major, float gpa)
    {
        idNo    = number;
        name    = first;
        surname = last;
        Major = major;
        Gpa = gpa;
       
        nextPtr = NULL;
    }
    
    
    
    Node::Node(int number)
    {
        idNo    = number;
    }




string Node::getName()
    {
        string nameStr = name;
        nameStr.append(" ");
        nameStr.append(surname);
        
        return nameStr;
    }




string Node::getRecord()
{
    string recStr = "";
    

    
    stringstream ss;
    ss << idNo << ", " << name << " " << surname << ", " << Major << " " << Gpa; 
    /***** Enter the code here ****/
    string recStrr = ss.str();
    recStr.append(recStrr);
    return recStr;
}




string Node::getRecordint()
{
    string recStr = "";
    

    
    stringstream ss;
    ss << idNo ; 
    /***** Enter the code here ****/
    string recStrr = ss.str();
    recStr.append(recStrr);
    return recStr;
}




void Node::setData(int number, string first, string last, string major, float gpa)
    {
        idNo    = number;
        name    = first;
        surname = last;
        Major = major;
        Gpa = gpa;
       
    }


