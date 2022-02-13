//
// 
//
//  417001974
//  AVLTree.h
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


//#define _GLIBCXX_USE_CX11_ABI 0
#ifndef AVLTree_h
#define AVLTree_h
#include <string>
#include <sstream>
using namespace std;

class AVLNode {
private:
    int ID;
    string fName;
    string lName;
    string major;
    float  gpa;
    int height;
    
    
public:
    AVLNode* Left;
    AVLNode* Right;
    
    // Constructors
    AVLNode() {ID = gpa = 0; fName = lName = major = ""; height = 0; Right = Left = NULL;}
    AVLNode(int Id, string first, string last, string maj, float mark);

    // Mutators
    void setID ( int Id ) {ID = Id;}
    void setFName(string first ) {fName = first;}
    void setLName(string last ) {lName = last;}
    void setMajor(string maj ) {major = maj;}
    void setGPA(float mark ) {gpa = mark;}
    void setHeight(int theHeight) {height = theHeight;}
    
    // Accessors
    int getID(void) {return ID;}
    string getFName() {return fName;}
    string getLName() {return lName;}
    string getMajor() {return major;}
    float getGPA(void) {return gpa;}
    int getHeight() {return height;}
   
    
};

AVLNode::AVLNode(int Id, string first, string last, string maj, float mark) {
    ID = Id;
    fName = first;
    lName = last;
    major = maj;
    gpa = mark;
    
    Right=Left=NULL;
}
class AVLTree {
private:
    AVLNode* root;
    
    AVLNode* insertHelper(AVLNode*, int iD, string first, string last, string theMaj, float theMark);
    
    AVLNode* removeHelper(AVLNode*, int);
    string inOrderHelper(AVLNode*);
    string preOrderHelper(AVLNode*);
    string postOrderHelper(AVLNode*);
    
    int AVLheight(AVLNode*);
    int calcBalance(AVLNode*);
    
    AVLNode* leftRotate(AVLNode*);
    
    AVLNode* specialCaseLeftRotate(AVLNode*);
    
    AVLNode* rightRotate(AVLNode*);
    
    AVLNode* specialCaseRightRotate(AVLNode*);
    
    AVLNode* rotateDoubleLeft(AVLNode*);
    
    AVLNode* rotateDoubleRight(AVLNode*);
    
    int max(int num,int num1);
    void resetHeight(AVLNode*);
    // End of private functions
    
    
public:
    // Constructor and Destructor
    AVLTree() {root = NULL;}
    ~AVLTree() {root = NULL;}
    
    // Mutators
    void insert(int Id, string first, string last, string maj, float mark) 
    {root = insertHelper(root, Id, first, last, maj, mark);}
    void remove (int Id) {root = removeHelper(root, Id);}
    
    string to_String(int i);
    string to_String(float i);
    // Accessors
    AVLNode *getRoot() {return root;}
    string preOrder() {return preOrderHelper(root);}
    string postOrder() {return postOrderHelper(root);}
    string inOrder() {return inOrderHelper(root);}
    string getLeftID(AVLNode*);
    string getRightID(AVLNode*);
    int getWeight(AVLNode*);
     bool isEmpty();
    
};


bool AVLTree::isEmpty()
{
    if(root == NULL)
        return true;
    else
        return false;
    
}

AVLNode* AVLTree::insertHelper(AVLNode* ptr, int iD, string first, string last, string theMaj, float theMark) {
    if (ptr == NULL) {
        ptr = new AVLNode(iD, first, last, theMaj, theMark);
        //return ptr;
    }
    
    else if (iD >= ptr->getID())
    {
        ptr->Right = insertHelper(ptr->Right, iD, first, last, theMaj, theMark);
        if (calcBalance(ptr) == -2)  // Right unbalance
        {
            if (iD >= ptr->Right->getID())          // Regular right unbalance
                ptr = rotateDoubleRight(ptr);
            else                                    // Special case
                ptr = specialCaseLeftRotate(ptr);
        }
    }
    
    else if (iD < ptr->getID())    // choose which sub-tree to follow
    {
        ptr->Left = insertHelper(ptr->Left, iD, first, last, theMaj, theMark);
        if (calcBalance(ptr) ==2)  // Left unbalance
        {
            if (iD < ptr->Left->getID())           // Regular left unbalance
                ptr = rotateDoubleLeft(ptr);
            else                                    // Special case
                ptr = specialCaseRightRotate(ptr);
        }
    }
    
    resetHeight(ptr);
    
    return ptr;
    
}

AVLNode* AVLTree::removeHelper(AVLNode* ptr, int iD) {
    AVLNode* successor;
    
    if ( ptr == NULL)           // Node location is empty i.e. Node not found!
    {
        return NULL;
    }
    else
    {
        if( iD > ptr->getID() )                // Search in Right sub-tree
        {
            ptr->Right = removeHelper(ptr->Right, iD);
            
            // If tree is off balanced to the left
            if ( calcBalance(ptr) == 2)
            {
                // If left sub-tree is left heavy
                if(calcBalance(ptr->Left) >= 0)
                    ptr = rightRotate(ptr);
                else
                    ptr = specialCaseRightRotate(ptr);
            }
        }
        else
        {
            if( iD < ptr->getID() )          // Search the Left sub-tree
            {
                // If tree is off balanced to the right
                ptr->Left = removeHelper(ptr->Left, iD);
                if( calcBalance(ptr) == -2 )
                {
                    // If right sub-tree is right heavy
                    if( calcBalance(ptr->Right) <= 0)
                        ptr = leftRotate(ptr);
                    else
                        ptr = specialCaseLeftRotate(ptr);
                }
            }
            else        //Node to to be deleted is found
            {
                if ( ptr->Right != NULL)
                {
                    //delete its inorder succesor
                    successor = ptr->Right;        // Go right...
                    while ( successor->Left != NULL)    // ...then go deep left
                        successor = successor->Left;
                    
                    // Transfer data from successor to ptr
                    ptr->setID( successor->getID() );
                    ptr->setFName( successor->getFName() );
                    ptr->setLName( successor->getLName() );
                    ptr->setMajor(successor->getMajor());
                    ptr->setGPA( successor->getGPA() );
                   ptr->setHeight( successor->getHeight() );
                    
                    // Now reset ptr's right child
                    ptr->Right = removeHelper( ptr->Right, ptr->getID() );
                    
                    // If tree is off balanced to the left
                    if(calcBalance(ptr) == 2)
                    {
                        // If left sub-tree is left heavy
                        if(calcBalance(ptr->Left) >= 0)
                            ptr = rightRotate(ptr);
                        else
                            ptr = specialCaseRightRotate(ptr);
                    }
                }
                else
                    return(ptr->Left);
                
            }
        }
    }
    resetHeight(ptr);
    
    return ptr;
}

string AVLTree::inOrderHelper(AVLNode *ptr) {
    string theString = "";
    
    if ( ptr != NULL )
    {
        theString.append( inOrderHelper(ptr->Left) );
        
        theString.append( to_String( ptr->getID() ) );
        theString.append(" [");
        theString.append( getLeftID(ptr) );
        theString.append(", ");
        theString.append( getRightID(ptr) );
        theString.append("]\t   ");
        
        string Fname = ptr->getFName();
        while (Fname.size() < 20)
        {
            Fname.append(" ");
        }
        theString.append( Fname );
        
        string Lname = ptr->getLName();
        while (Lname.size() < 20)
        {
            Lname.append(" ");
        }
        theString.append( Lname );
        
        string theMajor = ptr->getMajor();
        while (theMajor.size() < 20)
        {
            theMajor.append(" ");
        }
        theString.append( theMajor );
        
        string theGpa = to_String(ptr->getGPA());
        while (theGpa.size() < 20)
        {
           theGpa.append(" ");
        }
        theString.append( theGpa );
        
        
        
        theString.append( "        [" );
        theString.append( to_String(getWeight(ptr)) );
        theString.append( "]" );
        theString.append( "\n");
        
        theString.append( inOrderHelper(ptr->Right) );
    }
    return theString;
}

string AVLTree::preOrderHelper(AVLNode *ptr) {
    string theString = "";
    
    if ( ptr != NULL )
    {
        theString.append( to_String( ptr->getID() ) );
        theString.append(" [");
        theString.append( getLeftID(ptr) );
        theString.append(", ");
        theString.append( getRightID(ptr) );
        theString.append("]\t   ");
        
        string fName = ptr->getFName();
        
            fName.append(" ");
        
        theString.append( fName );
        
        string lName = ptr->getLName();
        
            lName.append(" ");
        
        theString.append( lName );
        
        string theMajor = ptr->getMajor();
        
            theMajor.append(" ");
        
        theString.append( theMajor );
        
        
        string theGpa = to_String(ptr->getGPA());
        
            theGpa.append("");
        
        theString.append(theGpa);
        
       
        
        
        theString.append( "        [" );
        theString.append( to_String(getWeight(ptr)) );
        theString.append( "]" );
        theString.append( "\n");
        
        theString.append( preOrderHelper(ptr->Left) );
        theString.append( preOrderHelper(ptr->Right) );
    }
    return theString;
}


string AVLTree::postOrderHelper(AVLNode *ptr) {
    string theString = "";
    
    if ( ptr != NULL )
    {
        theString.append( postOrderHelper(ptr->Left) );
        theString.append( postOrderHelper(ptr->Right) );
        
        theString.append( to_String( ptr->getID() ) );
        theString.append(" [");
        theString.append( getLeftID(ptr) );
        theString.append(", ");
        theString.append( getRightID(ptr) );
        theString.append("]\t   ");
        
        string Fname = ptr->getFName();
        while (Fname.size() < 20)
        {
            Fname.append(" ");
        }
        theString.append( Fname );
        
        string Lname = ptr->getLName();
        while (Lname.size() < 20)
        {
            Lname.append(" ");
        }
        theString.append( Lname );
        
        string theMajor = ptr->getMajor();
        while (theMajor.size() < 20)
        {
            theMajor.append(" ");
        }
        theString.append( theMajor );
        
        string theGpa = to_String(ptr->getGPA());
        while (theGpa.size() < 20)
        {
            theGpa.append(" ");
        }
        theString.append( theGpa );
        
                
        theString.append( "        [" );
        theString.append( to_String(getWeight(ptr)) );
        theString.append( "]" );
        theString.append( "\n");
    }
    return theString;
}




int AVLTree::AVLheight(AVLNode* ptr)
{
    if (ptr == NULL)
        return -1;
    else
        return ptr->getHeight();
}



int AVLTree::calcBalance(AVLNode* ptr)
{
    int leftHeight, rightHeight;
    
    if(ptr == NULL)
        return (0);
    
    if(ptr->Left == NULL)
        leftHeight = 0;
    else
        leftHeight = 1 + ptr->Left->getHeight();
    
    if(ptr->Right == NULL)
        rightHeight = 0;
    else
        rightHeight = 1 + ptr->Right->getHeight();
    
    return(leftHeight - rightHeight);
}



AVLNode* AVLTree::rightRotate(AVLNode* ptr)
{
    AVLNode* rightChild;
    rightChild = ptr->Left;
    ptr->Left = rightChild->Right;
    rightChild->Right = ptr;
    
    resetHeight(ptr);
    resetHeight(rightChild);
    
    return rightChild;
}



AVLNode* AVLTree::specialCaseRightRotate(AVLNode* ptrl)
{
    ptrl->Left = leftRotate(ptrl->Left);
    return rightRotate(ptrl);
}



AVLNode* AVLTree::leftRotate(AVLNode* ptr)
{
    AVLNode* leftChild;
    leftChild = ptr->Right;
    ptr->Right = leftChild->Left;
    leftChild->Left = ptr;
    
    resetHeight(ptr);
    resetHeight(leftChild);
    
    return leftChild;
}



AVLNode* AVLTree::specialCaseLeftRotate(AVLNode* ptrl)
{
    ptrl->Right = rightRotate(ptrl->Right);
    //ptr1 = leftRotate(ptr1);
    return leftRotate(ptrl);
}

AVLNode* AVLTree::rotateDoubleRight(AVLNode* ptrl)
{
    ptrl = leftRotate(ptrl);
    return (ptrl);
}

AVLNode* AVLTree::rotateDoubleLeft(AVLNode* ptrl)
{
    ptrl = rightRotate(ptrl);
    return (ptrl);
}





int AVLTree::max(int value1, int value2)
{
    return ((value1 > value2) ? value1 : value2);
}



void AVLTree::resetHeight(AVLNode* ptr)
{
    int lh, rh, ht;
    lh = AVLheight(ptr->Left);
    rh = AVLheight(ptr->Right);
    ht = max(lh, rh);
    ptr->setHeight(ht + 1);
}


string AVLTree::to_String ( int i )
{
    std::stringstream ss;
    ss << i;
    return ss.str();
}

string AVLTree::to_String (float i)
{
    std::stringstream ss;
    ss << i;
    return ss.str();
}
 /*string AVLTree::to_String ( float i )
{
    std::stringstream ss;
    ss << i;
    return ss.str();
}*/




string AVLTree::getLeftID(AVLNode* cur)
{
    AVLNode* left = cur->Left;
    if (left == NULL)
        return "NULL        ";
    else
        return to_String( left->getID() );
}



string AVLTree::getRightID(AVLNode* cur)
{
    AVLNode* right = cur->Right;
    if (right == NULL)
        return "        NULL";
    else
        return to_String( right->getID() );
}

int AVLTree::getWeight(AVLNode* current)
{
    if (calcBalance(current) < 0)
        return 1;
    else if (calcBalance(current) == 0)
        return 0;
    else
        return -1;
}

#endif /* AVLTree_h */
