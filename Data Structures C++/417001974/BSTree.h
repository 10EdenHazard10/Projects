//
//  BSTree.h
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
#ifndef BSTree_h
#define BSTree_h



class BinarySearchNode {
private:
    int ID;
    string fName;
    string lName;
    string major;
    float gpa;
    
    
public:
    BinarySearchNode* Left;
    BinarySearchNode* Right;
    
    // Constructors
    BinarySearchNode(void) {ID = gpa = 0; fName = lName = major = ""; Right = Left = NULL;}
    BinarySearchNode(int Id, string first, string last, string maj, float mark);
    
    // Mutators
    void setID ( int Id ) {ID = Id;}
    void setFName(string first ) {fName = first;}
    void setLName(string last ) {lName = last;}
    void setMajor(string maj ) {major = maj;}
    void setGPA(float  mark) {gpa = mark;}
    
    
    // Accessors
    int getID(void) {return ID;}
    string getFName() {return fName;}
    string getLName() {return lName;}
    string getMajor() {return major;}
    float getGPA() {return gpa;}
    
    
}; //End of Definitions
BinarySearchNode::BinarySearchNode(int Id, string first, string last, string maj, float mark) {
    ID = Id;
    fName = first;
    lName = last;
    major = maj;
    gpa = mark;
    
    Right=Left=NULL;
}

class BSTree {
private:
    BinarySearchNode* root;
    
    BinarySearchNode* insertHelper(BinarySearchNode*, int, string, string, string, float);
    BinarySearchNode* deleteNode(BinarySearchNode*, int);
    string inOrderHelper(BinarySearchNode*);
    string preOrderHelper(BinarySearchNode*);
    string postOrderHelper(BinarySearchNode*);
    
    
public:
    BSTree() {root = NULL;}
    
    ~BSTree() {root = NULL;}
    
    // Mutators
    void insert(int Id, string first, string last, string maj, float mark) {root = insertHelper(root, Id, first, last, maj, mark);}
    void remove (int Id) {root = deleteNode(root, Id);}
    string toString(int num);
    string to_String(float i);
    // Accessors
    BinarySearchNode *getRoot() {return root;}
    string preOrder() {return preOrderHelper(root);}
    string postOrder() {return postOrderHelper(root);}
    string inOrder() {return inOrderHelper(root);}
    string getLeftID(BinarySearchNode*);
    string getRightID(BinarySearchNode*);
    bool isEmpty();
    //Display All Nodes
    string showLevels ();
};



BinarySearchNode* BSTree::insertHelper(BinarySearchNode* ptr, int Id, string first, string last, string maj, float mark) {
    if (ptr == NULL) {
        ptr = new BinarySearchNode(Id, first, last, maj, mark);
    }
    else {
        if (Id > ptr->getID()) {
            ptr->Right = insertHelper(ptr->Right, Id, first, last, maj, mark);
        }
        else {
            ptr->Left = insertHelper(ptr->Left, Id, first, last, maj, mark);
        }
    }
    
    return ptr;
}

BinarySearchNode* BSTree::deleteNode(BinarySearchNode* ptr, int Id) {
    BinarySearchNode* next;
    if (ptr == NULL) {
        return NULL;
    }
    else {
        if (Id > ptr->getID()) {
            ptr->Right = deleteNode(ptr->Right, Id);
        }
        else if (Id < ptr->getID()) {
            ptr->Left = deleteNode(ptr->Left, Id);
        }
        else {
            if (ptr->Right != NULL) {
                next = ptr->Right;
                while(next->Left != NULL){
                    next = next->Left;
                }
                ptr->setID(next->getID());
                ptr->setFName(next->getFName());
                ptr->setLName(next->getLName());
                ptr->setMajor(next->getMajor());
                ptr->setGPA(next->getGPA());
               
                
                ptr->Right = deleteNode(ptr->Right, ptr->getID());
            }
            else {
                return (ptr->Left);
            }
        }
    }
    return ptr;
}

bool BSTree::isEmpty()
{
    if(root == NULL)
        return true;
    else
        return false;
    
}

string BSTree::inOrderHelper(BinarySearchNode* ptr) {
    string str = "";
    
    if (ptr != NULL) {
        str.append(inOrderHelper(ptr->Left));
        
        str.append(toString(ptr->getID()));
        str.append(" [");
        str.append(getLeftID(ptr));
        str.append(", ");
        str.append(getRightID(ptr));
        str.append("]\t  ");
        
        string FName = ptr->getFName();
       
            FName.append(" ");
        
        str.append(FName);
        
        string LName = ptr->getLName();
        
            LName.append(" ");
       
        str.append(LName);
        
        string theMajor = ptr->getMajor();
        
            theMajor.append(" ");
        
        str.append(theMajor);
        
        string theGPA = to_String(ptr->getGPA());
     
            theGPA.append(" ");
        
        str.append(theGPA);
        
        
        str.append("\n");
        str.append(inOrderHelper(ptr->Right));
    }
    return str;
}

string BSTree::preOrderHelper(BinarySearchNode* ptr) {
    string str = "";
    
    if ( ptr != NULL )
    {
        str.append( toString( ptr->getID() ) );
        str.append(" [");
        str.append( getLeftID(ptr) );
        str.append(", ");
        str.append( getRightID(ptr) );
        str.append("]\t   ");
        
        string fName = ptr->getFName();
        
            fName.append(" ");
        
        str.append( fName );
        
        string lName = ptr->getLName();
        
            lName.append(" ");
        
        str.append( lName );
        
        string theMajor = ptr->getMajor();
        
            theMajor.append(" ");
        
        str.append( theMajor );
        
        string theGPA = to_String(ptr->getGPA());
        
            theGPA.append(" ");
        
        str.append( theGPA) ;
        
                
        
        str.append( "\n");
        
        str.append( preOrderHelper(ptr->Left) );
        str.append( preOrderHelper(ptr->Right) );
    }
    return str;
}

string BSTree::postOrderHelper(BinarySearchNode* ptr) {
    string str = "";
    
    if ( ptr != NULL )
    {
        str.append( postOrderHelper(ptr->Left) );
        str.append( postOrderHelper(ptr->Right) );
       
        str.append( toString( ptr->getID() ) );
        str.append(" [");
        str.append( getLeftID(ptr) );
        str.append(", ");
        str.append( getRightID(ptr) );
        str.append("]\t   ");
        
        string fName = ptr->getFName();
        
        fName.append(" ");
        
        str.append( fName );
        
        string lName = ptr->getLName();
        
        lName.append(" ");
        
        str.append( lName );
        
        string theMajor = ptr->getMajor();
        
        theMajor.append(" ");
        
        str.append( theMajor );
        
        
        string theGPA = to_String(ptr->getGPA());
        
            theGPA.append(" ");
        
        str.append( theGPA );
        
        
        
        
        str.append( "\n");
        
        
    }
    return str;
    
}

string BSTree::toString(int num) {
    stringstream ss;
    ss << num;
    return ss.str();
}

string BSTree::to_String (float i)
{
    std::stringstream ss;
    ss << i;
    return ss.str();
}

string BSTree::getRightID(BinarySearchNode* cur) {
    BinarySearchNode* right = cur->Right;
    if (right == NULL) {
        return "NULL     ";
    }
    else {
        return toString(right->getID());
    }
}

string BSTree::getLeftID(BinarySearchNode* cur) {
    BinarySearchNode* left = cur->Left;
    if (left == NULL) {
        return "NULL     ";
    }
    else {
        return toString(left->getID());
    }
}




#endif /* BSTree_h */
