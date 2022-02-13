//
//  RBTree.h
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

#ifndef RBTree_h
#define RBTree_h
#include <string>
#include <sstream>

class RBTNode {
private:
    int ID;
    string first;
    string last;
    string major;
    float gpa;
    string color;
    
    
public:
    RBTNode* left;
    RBTNode* right;
    RBTNode* parent;
    
    //Constructor Functions
    RBTNode(){right = left = parent = NULL; color = "RED";}
    RBTNode(int, string, string, string, float);
    
    
    
    //Accessor Functions
    int getID() {return ID;}
    string getFName() {return first;}
    string getLName() {return last;}
    string getMajor() {return major;}
    float getGpa() {return gpa;}
    string getAllData();
    string getAllDataRBT();
    string strip(string);
    string getColor() {return color;}
    string to_String(float);
    
    
    
    // Mutator Functions
    void setID(int id) {ID = id;}
    void setName(string fn)         { first = fn; }
    void setSurname(string ln)      { last = ln; }
    void setMajor(string maj)      { major = maj; }
    void setSeason(float mark)       { gpa = mark; }
        
    void setData(int, string, string, string, float);
    void setColor(string col){color = col;}
    
};

RBTNode::RBTNode(int idNo, string fName, string lName, string majj, float markk)
{
    ID = idNo;
    first = fName;
    last = lName;
    major = majj;
    gpa = markk;
        
    color = "RED";
    
    left = NULL;
    right = NULL;
    parent = NULL;
}

void RBTNode::setData(int idNo, string firstName, string lastName,string maj, float mark)
{
    ID    = idNo;
   first = firstName;
    last    = lastName;
    major   = maj;
    gpa  = mark;
    
}

string RBTNode::to_String (float i)
{
    std::stringstream ss;
    ss << i;
    return ss.str();
}




string RBTNode::getAllData()
{
    string str = "";
    
    stringstream numStr;
    
    
    numStr << getID();
    str.append(numStr.str());
    
    str.append("\t");
    str.append(strip(getFName()));
    str.append("\t");
    str.append(strip(getLName()));
    str.append("\t");
    str.append(strip(getMajor()));
    str.append("\t");
    str.append(strip(to_String(getGpa())));
    str.append("\t");
    
    
    return str;
}

string RBTNode::getAllDataRBT()
{
    string str = "";
    string child;
    
    stringstream leftChild;
    stringstream rightChild;
    stringstream numStr;
    
    numStr << getID();
    str.append(numStr.str());
    
    str.append("\t");
    str.append(strip(getFName()));
    str.append("\t");
    str.append(strip(getLName()));
    str.append("\t");
    str.append(strip(getMajor()));
    str.append("\t");
    str.append(to_String(getGpa()));
    str.append("\t\t");
    str.append("[ ");
    str.append(strip(getColor()));
    str.append(" ]");
    str.append("\t");
    
    if (left != NULL && right != NULL) //No ptr's are NULL
    {
        child.append("[ ");
        leftChild << left->getID();
        child.append(leftChild.str());
        child.append(" , ");
        
        rightChild << right->getID();
        child.append(rightChild.str());
        child.append(" ]");
        
        //Add left & right ptr IDs to str
        str.append(child);
        str.append("\n");
    }
    
    if (left == NULL && right != NULL) //left ptr is NULL
    {
        child.append("[ NULL");
        child.append(" , ");
        rightChild << right->getID();
        child.append(rightChild.str());
        child.append(" ]");
        
        //Add left & right ptr IDs to str
        str.append(child);
        str.append("\n");
    }
    
    
    if (left != NULL && right == NULL) //right ptr is NULL
    {
        child.append("[ ");
        leftChild << left->getID();
        child.append(leftChild.str());
        child.append(" , ");
        child.append("Null ]");
        
        //Add left & right ptr IDs to str
        str.append(child);
        str.append("\n");
    }
    
    if (left == NULL && right == NULL) //both left & right are NULL
    {
        str.append("[ NULL , NULL ]");
        str.append("\n");
    }
    
    
    return str;
}

string RBTNode::strip(string str)
{
    for (unsigned int x = 0; x < str.size(); x++)
        if ( (!isalpha(str[x]) ) && (str[x] != '-') && (str[x] != ' ') )
            str[x] = ' ';
        
    //for (unsigned float x = 0; x < str.size(); x++)
      //  if ( (!isalpha(str[x]) ) && (str[x] != '-') && (str[x] != ' ') )
        //    str[x] = ' ';
    
    return str;
}






class RBTree {
private:
    RBTNode* root;
    
    
    // Utility functions
    void     rotateLeft( RBTNode* );
    void     rotateRight(RBTNode* );
    void     fixUp(RBTNode* );
    void    deleteNode(RBTNode* );
    string   inOrderHelper(RBTNode* );
    string   preOrderHelper(RBTNode* );
    string   postOrderHelper(RBTNode* );
    RBTNode* findNode(int );
    RBTNode* getMinimum(RBTNode *);
    RBTNode* getInheritor(RBTNode *);
    RBTNode* getSuccessor(RBTNode *);
    
public:
    RBTree(){ root = NULL;}
    
    //Destructor Function
    ~RBTree() {root = NULL;}
    
    // Mutator functions
    void   insertRBT(int, string, string, string, float);
    string remove( int );
    void   emptyRBT() { root = NULL;}
    
    // Accessor functions
    string inOrder(){ return inOrderHelper(root); }
    string preOrder(){ return preOrderHelper(root); };
    string postOrder(){ return postOrderHelper(root); };
    string showLevels();
    bool isEmpty();
    string to_String(int);
};

bool RBTree::isEmpty()
{
    if(root == NULL)
        return true;
    else
        return false;
}

void RBTree::rotateLeft( RBTNode* ptr )
{
    RBTNode* rightChild = ptr->right;
    ptr->right = rightChild->left;
    
    if (rightChild->left != NULL)
        rightChild->left->parent = ptr;
    
    rightChild->parent = ptr->parent;
    
    if (ptr == root)
        root = rightChild;
    else
    {
        if( ptr == ptr->parent->left)
            ptr->parent->left = rightChild;
        else
            ptr->parent->right = rightChild;
    }
    
    rightChild->left = ptr;
    ptr->parent = rightChild;
}

void RBTree::rotateRight(RBTNode* ptr)
{
    RBTNode* leftChild = ptr->left;
    ptr->left = leftChild->right;
    
    if (leftChild->right != NULL)
        leftChild->right->parent = ptr;
    
    leftChild->parent = ptr->parent;
    
    if (ptr == root)
        root = leftChild;
    else
    {
        if( ptr == ptr->parent->right)
            ptr->parent->right = leftChild;
        else
            ptr->parent->left = leftChild;
    }
    
    leftChild->right = ptr;
    ptr->parent = leftChild;
    
}

RBTNode* RBTree::findNode(int idNo)
{
    RBTNode* ptr = root;
    
    while ( ptr != NULL )
    {
        if  (ptr->getID() == idNo)
        {
            return ptr;
        }
        
        if (idNo < ptr->getID() )
            ptr = ptr->left;
        else
            ptr = ptr->right;
    }
    
    return NULL;            // Tree is empty or not found
}



void RBTree::insertRBT(int studentID, string name, string surname, string majj, float markk)
{
    
    RBTNode* newnode = new RBTNode(studentID, name, surname, majj, markk);
    
    if (root == NULL)                   // Tree is empty - newnode is first node
    {
        newnode->setColor("BLACK");
        root = newnode;
        return;
    }
    else                                // Tree is NOT empty
    {
        RBTNode* ancestor = NULL;
        RBTNode* current = root;
        while (current != NULL)
        {
            ancestor = current;
            
            if ( newnode->getID() < current->getID() )
                current = current->left;
            else
                current = current->right;
        }
        
        newnode->parent = ancestor;
        
        if ( newnode->getID() < ancestor->getID() )
            ancestor->left = newnode;
        else
            ancestor->right= newnode;
        
        fixUp(newnode);
    }
}

void RBTree::fixUp( RBTNode *ptr )
{
    RBTNode *ptrRelative = NULL;
    
    while ( ptr != root && ptr->parent->getColor() == "RED" )
    {
        if ( ptr->parent == ptr->parent->parent->left )
        {       // ptr's parent is a LEFT child
            ptrRelative = ptr->parent->parent->right;
            
            if (  ptrRelative != NULL && ptrRelative->getColor() == "RED" )
            {
                ptr->parent->setColor("BLACK");
                ptrRelative->setColor("BLACK");
                ptr->parent->parent->setColor("RED");
                ptr = ptr->parent->parent;
            }
            else
            {
                if ( ptr == ptr->parent->right )
                {
                    ptr = ptr->parent;
                    rotateLeft( ptr );
                }
                
                ptr->parent->setColor("BLACK");
                ptr->parent->parent->setColor("RED");
                rotateRight( ptr->parent->parent );
            }
        }
        else            // ptr's parent is a RIGHT child
        {
            ptrRelative = ptr->parent->parent->left;
            
            if ( ptrRelative != NULL && ptrRelative->getColor() == "RED" )
            {
                ptr->parent->setColor("BLACK");
                ptrRelative->setColor("BLACK");
                ptr->parent->parent->setColor("RED");
                ptr = ptr->parent->parent;
            }
            else
            {
                if ( ptr == ptr->parent->left )
                {
                    ptr = ptr->parent;
                    rotateRight( ptr );
                }
                ptr->parent->setColor("BLACK");
                ptr->parent->parent->setColor("RED");
                rotateLeft( ptr->parent->parent );
            }
        }
    }
    
    root->setColor("BLACK");
    
    ptrRelative = NULL;
}

RBTNode* RBTree::getInheritor(RBTNode* ptr)
{
    if (ptr->right == NULL)
        return ptr->left;
    else
        return(getMinimum(ptr->right));
}

string RBTree::remove(int val)
{
    RBTNode* markedNode = findNode(val);
    //string theString = markedNode->getAllData();
    string theString = to_String(val);
    deleteNode(markedNode);
    return theString;
}

void RBTree::deleteNode(RBTNode* node2Zap)
{
    if (node2Zap == NULL)    //If node being deleted is NULL then do nothing.
        return;
    else
    {
        RBTNode *successor, *successorChild;
        successor = node2Zap;
        
        if (node2Zap->left == NULL || node2Zap->right == NULL)
            //If either of the children is NULL
            successor = node2Zap;
        else                    // node2Zap has 2 children
            successor = getSuccessor(node2Zap);

        
        if (successor->left == NULL)
            successorChild = successor->right;
        else
            successorChild = successor->right;
        
        if (successorChild != NULL)
            successorChild->parent = successor->parent;
        
        if (successor->parent == NULL)
            root = successorChild;
        else if (successor == successor->parent->left)
            successor->parent->left = successorChild;
        else
            successor->parent->right = successorChild;
        
        if (successor != node2Zap)
            node2Zap->setID(successor->getID());
        
        // Finally... If color is black call fixup otherwise no fixup required
        if (successor->getColor() == "BLACK" && successorChild != NULL)
            fixUp(successorChild);
    }
}

RBTNode* RBTree::getSuccessor(RBTNode* ptr)
{
    if (ptr->right == NULL)
        return ptr->left;
    else
        return(getMinimum(ptr->right));
}


RBTNode* RBTree::getMinimum(RBTNode *ptr)
{
    while(ptr->left != NULL)
        ptr = ptr->left;
    
    return ptr;
}

string RBTree::inOrderHelper(RBTNode* ptr)
{
    string str = "";
    
    if ( ptr != NULL )
    {
        str.append( inOrderHelper(ptr->left) );
        
        str.append( ptr->getAllDataRBT() );
        str.append( "  ");
        str.append( inOrderHelper(ptr->right) );
    }
    return str;
    
}

string RBTree::preOrderHelper(RBTNode* ptr)
{
    
    string str = "";
    
    if ( ptr != NULL )
    {
        str.append( ptr->getAllDataRBT() );
        str.append( "  ");
        
        str.append( preOrderHelper(ptr->left) );
        str.append( preOrderHelper(ptr->right) );
    }
    return str;
}

string RBTree::postOrderHelper(RBTNode* ptr)
{
    string str = "";
    
    if ( ptr != NULL )
    {
        str.append( inOrderHelper(ptr->left) );
        str.append( inOrderHelper(ptr->right) );
        
        str.append( ptr->getAllDataRBT() );
        str.append( "  ");
    }
    return str;
}



string RBTree::to_String (int i)
{
    std::stringstream ss;
    ss << i;
    return ss.str();
}

string RBTree::showLevels()
{
    vector <RBTNode*> listA;
    vector <RBTNode*> listB;
    
    string str = "";
    
    listA.resize(0);
    listB.resize(0);
    
    if (root == NULL)
    {
        str.append("Tree is Empty...\n");
        return str;
    }
    else
        listA.push_back(root);
    
    
    while (!listA.empty())
    {
        //Display the contents of listA
        for (int x = 0; x < listA.size(); x++)
        {
            str.append(listA[x]->getAllDataRBT());
            str.append("{");
            str.append(listA[x]->getColor());
            str.append("} \t");
        }
        str.append("\n");
        
        //Transfer contents of listA to listB
        listB = listA;
        
        // Now purge listA and copy listB's children into listA
        listA.resize(0);
        
        for (int x = 0; x < listB.size(); x++)
        {
            if (listB[x]->left != NULL)
                listA.push_back(listB[x]->left);
            if (listB[x]->right != NULL)
                listA.push_back(listB[x]->right);
        }
    }
    return str;
}
#endif /* RBTree_h */
