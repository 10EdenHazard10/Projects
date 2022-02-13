//
// 
//
//  417001974
//  Splay.h
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

#ifndef Splay_h
#define Splay_h
//#include <string>
//#include <sstream>
using namespace std;

class SplayNode {
private:
    int ID;
    string fName;
    string lName;
    string major;
    float gpa;
    
    
public:
    SplayNode* left;
    SplayNode* right;
    
    // Constructor functions
    SplayNode() {ID = gpa =0; fName = lName = major = ""; right = left = NULL;}
    SplayNode(int id, string first, string last, string maj, float mark);
    
    // Mutator functions
    void setID(int id) { ID = id;}
    void setFName(string fn) {fName = fn;}
    void setLName(string ln) {lName = ln;}
    void setMajor(string majj) {major = majj;}
    void setGpa(float markk) {gpa = markk;}
   
    
    
    //Accessor Functions
    int getID() {return ID;}
    string getFName() {return fName;}
    string getLName() {return lName;}
    string getMajor() {return major;}
    float getGpa() {return gpa;}
    
};

SplayNode::SplayNode ( int id, string fn, string ln, string majj, float markk )
{
    ID = id; fName = fn; lName = ln; major = majj; gpa = markk;  right = left = NULL;
}

class Splay {
    
private:
    
    SplayNode* root;
    
    //Helper Functions
    
    SplayNode* leftRotate(SplayNode* ptr);
    SplayNode* rightRotate(SplayNode* ptr);
    SplayNode* splay(SplayNode* ptr, int id);
    SplayNode* insertHelper(SplayNode* ptr, int id, string fn, string ln, string majj, float markk);
    SplayNode* removeHelper(SplayNode* ptr, int id);
    
    string inOrderHelper(SplayNode* ptr);
    string postOrderHelper(SplayNode* ptr);
    string preOrderHelper(SplayNode* ptr);
    
public:
    
    Splay(){root = NULL;}
    ~Splay(){root = NULL;}
    
    void insert(int id, string fn, string ln, string majj, float markk);
    void remove(int id) { root = removeHelper(root, id); }
    string inOrder() { return inOrderHelper(root); }
    string preOrder() { return preOrderHelper(root); }
    string postOrder() { return postOrderHelper(root); }
    string to_String ( int i );
    string to_String ( float f );
    SplayNode* getRoot ( void ) { return root; }
    string   getLeftID  ( SplayNode* );
    string   getRightID ( SplayNode* );
    bool isEmpty();
};


bool Splay::isEmpty()
{
    if(root == NULL)
        return true;
        else
            return false;
}


void Splay::insert(int id, string fn, string ln, string majj, float markk)
{
    root = insertHelper(root, id,fn,ln,majj,markk);
}

SplayNode* Splay::insertHelper(SplayNode* ptr, int id, string fn, string ln, string majj, float markk)
{
    SplayNode* newptr = new SplayNode(id,fn,ln,majj, markk);
    
    if(ptr == NULL)
    {
        ptr = newptr;
        return ptr;
        
    }
    
    SplayNode* prev = NULL;
    SplayNode* curr = ptr;
    
    if(id == curr -> getID())
    {
        return ptr;
        
    }
    
    while(curr != NULL)
    {
        prev = curr;
        
        if( id < curr -> getID())
        {
            
            curr = curr -> left;
            
        }
        else if( id > curr -> getID())
        {
            
            curr = curr -> right;
            
        }
        
    }//End While
    
    if(id < prev -> getID())
    {
        
        prev -> left = newptr;
    }
    else
    {
        prev -> right = newptr;
        
    }
    
    ptr = splay(ptr,id);
    
    return ptr;
    
    
}//End Insert Helper

SplayNode* Splay::removeHelper(SplayNode* ptr, int id)
{
    SplayNode* successor;
    
    if ( ptr == NULL)           // Node location is empty i.e. Node not found!
    {
        return NULL;
    }
    else
    {
        if ( id > ptr->getID() )                // Search in Right subtree
        {
            ptr->right = removeHelper(ptr->right, id);
        }
        else if( id < ptr->getID() )           // Search in Left subtree
        {
            ptr->left = removeHelper(ptr->left, id);
        }
        else   //Node to to be deleted is found
        {
            if ( ptr->right != NULL )
            {
                // Delete its inorder succesor
                successor = ptr->right;                 // Go right...
                while ( successor->left != NULL )       // ...then go deep left
                    successor = successor->left;
                
                // Transfer data from successor to ptr
                ptr->setID( successor->getID() );
                ptr->setFName( successor->getFName() );
                ptr->setLName( successor->getLName() );
                ptr->setMajor( successor->getMajor() );
                ptr->setGpa( successor->getGpa() );
                
                // Now reset ptr's right child
                ptr->right = removeHelper( ptr->right, ptr->getID() );
            }
            else
                return (ptr->left);
        }
    }
    return (ptr);
}

SplayNode* Splay::splay(SplayNode* ptr, int id)
{
    
    //Base Case
    
    if( ptr == NULL || ptr -> getID() == id)
    {
        
        return ptr;
        
    }
    
    //Go left subtree
    
    if( id < ptr -> getID())
    {
        if(ptr -> left == NULL)
        {
            
            return ptr;
        }
        //Go right subtree
        if( id < ptr -> left -> getID())
        {
            
            ptr -> left -> left = splay(ptr -> left -> left, id);
            
            ptr = rightRotate(ptr);
            
        }
        else if( id > ptr -> left -> getID())
        {
            
            ptr -> left -> right = splay(ptr -> left -> right, id);
            
            if(ptr -> left -> right != NULL)
            {
                ptr -> left = leftRotate(ptr -> left);
                
            }
            
        }
        
        return(ptr -> left == NULL) ? ptr: rightRotate(ptr);
    }//End If
    else
    {
        
        if(ptr -> right == NULL)
        {
            
            return ptr;
            
        }
        
        if( id > ptr -> right -> getID())
        {
            ptr -> right -> right = splay( ptr -> right -> right, id);
            ptr = leftRotate(ptr);
            
        }
        else if( id < ptr -> right -> getID())
        {
            
            ptr -> right -> left = splay(ptr -> right -> left, id);
            
            if(ptr -> right -> left != NULL)
            {
                
                ptr -> right = rightRotate(ptr -> right);
            }
        }
        
        return(ptr -> right == NULL)? ptr: leftRotate(ptr);
        
    }//End Else
    
} //End splay

SplayNode* Splay::leftRotate(SplayNode* ptr)
{
    
    SplayNode* rightChild;
    
    rightChild = ptr -> right;
    ptr -> right = rightChild -> left;
    rightChild -> left = ptr;
    
    
    return rightChild;
}

SplayNode* Splay::rightRotate(SplayNode* ptr)
{
    
    SplayNode* leftChild;
    
    leftChild = ptr -> left;
    ptr -> left = leftChild -> right;
    leftChild -> right = ptr;
    
    return leftChild;
}

string Splay::inOrderHelper(SplayNode* ptr)
{
    string str = "";
    
    if ( ptr != NULL )
    {
        str.append( inOrderHelper(ptr->left) );
        
        str.append( to_String( ptr->getID() ) );
        str.append(" [");
        str.append( getLeftID(ptr) );
        str.append(", ");
        str.append( getRightID(ptr) );
        str.append("]\t   ");
        
        string Fname = ptr->getFName();
        while (Fname.size() < 20)
        {
            Fname.append(" ");
        }
        str.append( Fname );
        
        string Lname = ptr->getLName();
        while (Lname.size() < 20)
        {
            Lname.append(" ");
        }
        str.append( Lname );
        
        string theMajor = ptr->getMajor();
        while (theMajor.size() < 20)
        {
            theMajor.append(" ");
        }
        str.append( theMajor );
        
        string theGpa = to_String(ptr->getGpa());
        while (theGpa.size() < 20)
        {
            theGpa.append(" ");
        }
        str.append(theGpa);
        
        
        
        str.append( "\n");
        
        str.append( inOrderHelper(ptr->right) );
    }
    return str;
} //End In-order Helper

string Splay::preOrderHelper(SplayNode* ptr)
{
    string str = "";
    
    if ( ptr != NULL )
    {
        str.append( to_String( ptr->getID() ) );
        str.append(" [");
        str.append( getLeftID(ptr) );
        str.append(", ");
        str.append( getRightID(ptr) );
        str.append("]\t   ");
        
        string FName = ptr->getFName();
        while (FName.size() < 20)
        {
            FName.append(" ");
        }
        str.append( FName );
        
        string LName = ptr->getLName();
        while (LName.size() < 20)
        {
            LName.append(" ");
        }
        str.append( LName );
        
        string theMajor = ptr->getMajor();
        while (theMajor.size() < 20)
        {
            theMajor.append(" ");
        }
        str.append( theMajor );
        
        string theGpa = to_String(ptr->getGpa());
        while (theGpa.size() < 20)
        {
            theGpa.append(" ");
        }
        str.append( theGpa );
        
        
        
        str.append( "\n");
        
        str.append( preOrderHelper(ptr->left) );
        str.append( preOrderHelper(ptr->right) );
    }
    return str;
} //End Pre-order



string Splay::postOrderHelper(SplayNode* ptr)
{
    string str = "";
    
    if ( ptr != NULL )
    {
        str.append( postOrderHelper(ptr->left) );
        str.append( postOrderHelper(ptr->right) );
        
        str.append( to_String( ptr->getID() ) );
        str.append(" [");
        str.append( getLeftID(ptr) );
        str.append(", ");
        str.append( getRightID(ptr) );
        str.append("]\t   ");
        
        string FName = ptr->getFName();
        while (FName.size() < 20)
        {
            FName.append(" ");
        }
        str.append( FName );
        
        string LName = ptr->getLName();
        while (LName.size() < 20)
        {
            LName.append(" ");
        }
        str.append( LName );
        
        string theMajor = ptr->getMajor();
        while (theMajor.size() < 20)
        {
            theMajor.append(" ");
        }
        str.append( theMajor );
        
        /*float theGpa = ptr->getGpa();
        while (to_String(theGpa).size() < 20) {
            to_String(theGpa).append(" ");
        }
        str.append(to_String(theGpa));*/
        
         string theGpa = to_String(ptr->getGpa());
        while (theGpa.size() < 20)
        {
            theGpa.append(" ");
        }
        str.append( theGpa );
        
        
        
        str.append( "\n");
    }
    return str;
}//End Post-order Helper

string Splay::to_String ( int i )
{
    std::stringstream ss;
    ss << i;
    return ss.str();
}

string Splay::to_String ( float i )
{
    std::stringstream ss;
    ss << i;
    return ss.str();
}



string Splay::getLeftID(SplayNode* cur)
{
    SplayNode* left = cur->left;
    if (left == NULL)
        return "NULL        ";
    else
        return to_String( left->getID() );
}



string Splay::getRightID(SplayNode* cur)
{
    SplayNode* right = cur->right;
    if (right == NULL)
        return "        NULL";
    else
        return to_String( right->getID() );
}

#endif /* Splay_h */
