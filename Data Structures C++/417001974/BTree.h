// Created by Rashaad Bryan, 400002413.

#ifndef BTREE_H
#define BTREE_H

#include <algorithm>

using namespace std;


class BTreeKey
{
	private:
		int ID;
		string  name;
        string  surname;
        string  major;
        float   gpa;
  
	public:
		BTreeKey(int num, string first, string last, string maj, float mark) 
		{
			ID = num;
            name = first;
            surname = last;
            major = maj;
            gpa = mark;
		}

		// Modifiers
        void setID(int num) {ID = num;}
        void setName(string val) {name = val;}
        void setSurname(string val) {surname = val;}
        void setMajor(string val) {major = val;}
        void setGPA(float val) {gpa = val;}

		// Accessors
		int getID() {return ID;}
		string getName() {return name;}
		string getSurname() {return surname;}
        string getMajor() {return major;}
		float getGPA(){return gpa;}

		string getData()
        {
            string str = "";
            str.append(to_string(ID));
            str.append("\t");
            str.append(name);
            str.append("\t");
            str.append(surname);
            str.append("\t");
            str.append(major);
            str.append("\t");
            str.append(to_string(gpa));
            str.append("\n");
            return str;
        }
};

class BTreeNode
{
	private:
		BTreeKey* firstKey;
		BTreeKey* secondKey;
		BTreeKey* thirdKey;
		BTreeKey* fourthKey;

		BTreeNode* parent;
		BTreeNode* firstChild;
		BTreeNode* secondChild;
		BTreeNode* thirdChild;
		BTreeNode* fourthChild;
		BTreeNode* fifthChild;
	public:
		BTreeNode()
		{
			firstKey = NULL;
			secondKey = NULL;
			thirdKey = NULL;
			fourthKey = NULL;


			parent = NULL;
			firstChild = NULL;
			secondChild = NULL;
			thirdChild = NULL;
			fourthChild = NULL;
			fifthChild = NULL;
		}

		

		void switchKeys(BTreeKey*& a, BTreeKey*& b)
		{
			if (a != NULL && b != NULL)
			{
				if (a->getID() > b->getID())
				{
					swap(a, b);
				}
			} 
			else if(a == NULL && b != NULL)
			{
				swap(a, b);
			}	
		}

		int getAllKeys()
		{
			if (fourthKey != NULL)
			{
				return 4;
			}
			if (thirdKey != NULL)
			{
				return 3;
			}
			else if (secondKey != NULL)
			{
				return 2;
			}
			else if (firstKey != NULL)
			{
				return 1;
			}
			return 0;
		}

		

		
		
		void orderKeys()
		{
			switchKeys(firstKey, secondKey);
			switchKeys(thirdKey, fourthKey);
			switchKeys(firstKey, thirdKey);
			switchKeys(secondKey, fourthKey);
			switchKeys(secondKey, thirdKey);
		}

		bool hasTooManyChildren()
		{
			if (firstChild != NULL && secondChild != NULL && thirdChild != NULL && fourthChild != NULL && fifthChild != NULL)
			{
				return true;
			}
			return false;
		}

		void insert(BTreeKey* i)
		{
			if (firstKey == NULL)
			{
				firstKey = i;
			}
			else if(secondKey == NULL)
			{
				secondKey = i;
			}
			else if(thirdKey == NULL)
			{
				thirdKey = i;
			}
			else
			{
				fourthKey = i;
			}
			orderKeys();
		}

		void remove(int num)
		{
			if (firstKey->getID() == num)
			{
				delete firstKey;
				firstKey = NULL;
			}
			else if (secondKey->getID() == num)
			{
				delete secondKey;
				secondKey = NULL;
			}
			else if (thirdKey->getID() == num)
			{
				delete thirdKey;
				thirdKey = NULL;
			}
			orderKeys();
		}

		string display()
		{
			string result;

			if (firstKey != NULL)
			{
				result.append(firstKey->getData());
			}
			if (secondKey != NULL)
			{
				result.append(secondKey->getData());
			}
			if (thirdKey != NULL)
			{
				result.append(thirdKey->getData());
			}
			result.append("\n\n");
			return result;
		}
		
    int getTotalChildren()
		{
			if (fifthChild != NULL)
			{
				return 5;
			}
			else if (fourthChild != NULL)
			{
				return 4;
			}
			else if (thirdChild != NULL)
			{
				return 3;
			}
			else if (secondChild != NULL)
			{
				return 2;
			}
			else if (firstChild != NULL)
			{
				return 1;
			}
			return 0;
		}

		bool contains(int num)
		{
			if (firstKey != NULL)
			{
				if (firstKey->getID() == num)
				{
					return true;
				}
			}
			if (secondKey != NULL)
			{
				if (secondKey->getID() == num)
				{
					return true;
				}
			}
			if (thirdKey != NULL)
			{
				if (thirdKey->getID() == num)
				{
					return true;
				}
			}
			return false;
		}
		
		bool isFull()
		{
			if (firstKey != NULL && secondKey != NULL && thirdKey != NULL && fourthKey != NULL)
			{
				return true;
			}
			return false;
		}

		// Modifiers
		void setFirstKey(BTreeKey* i) {firstKey = i;}
		void setSecondKey(BTreeKey* i) {secondKey = i;}
		void setThirdKey(BTreeKey* i) {thirdKey = i;}
		void setFourthKey(BTreeKey* i) {fourthKey = i;}

		void setParent(BTreeNode* n) {parent = n;}
		void setFirstChild(BTreeNode* n) {firstChild = n;}
		void setSecondChild(BTreeNode* n) {secondChild = n;}
		void setThirdChild(BTreeNode* n) {thirdChild = n;}
		void setFourthChild(BTreeNode* n) {fourthChild = n;}
		void setFifthChild(BTreeNode* n) {fifthChild = n;}

		// Accessors
		BTreeKey* getFirstKey(){return firstKey;}
		BTreeKey* getSecondKey(){return secondKey;}
		BTreeKey* getThirdKey(){return thirdKey;}
		BTreeKey* getFourthKey(){return fourthKey;}
		BTreeNode* getParent(){return parent;}
		BTreeNode* getFirstChild(){return firstChild;}
		BTreeNode* getSecondChild(){return secondChild;}
		BTreeNode* getThirdChild(){return thirdChild;}
		BTreeNode* getFourthChild(){return fourthChild;}
		BTreeNode* getFifthChild(){return fifthChild;}
};


class BTree
{
	private:
		BTreeNode* root;

		void traverse(BTreeNode*& n, int num, bool istrue = false)
		{
			bool hasNShifted;

			do 
			{
				if (istrue == true && n->contains(num))
				{
					return;
				}
				hasNShifted = false;
				if(n->getAllKeys() == 1 && n->getTotalChildren() != 0)
				{
					if (num <= n->getFirstKey()->getID())
					{
						n = n->getFirstChild();
						hasNShifted = true;
					}
					else if (num >= n->getFirstKey()->getID())
					{
						n = n->getSecondChild();
						hasNShifted = true;
					}
				}
				else if(n->getAllKeys() == 2 && n->getTotalChildren() != 0)
				{
					if (num <= n->getFirstKey()->getID())
					{
						n = n->getFirstChild();
						hasNShifted = true;
					}
					else if(num >= n->getFirstKey()->getID() && num <= n->getSecondKey()->getID())
					{
						n = n->getSecondChild();
						hasNShifted = true;
					}
					else if(num >= n->getSecondKey()->getID())
					{
						n = n->getThirdChild();
						hasNShifted = true;
					}
				}
				else if(n->getAllKeys() == 3 && n->getTotalChildren() != 0)
				{
					if (num <= n->getFirstKey()->getID())
					{
						n = n->getFirstChild();
						hasNShifted = true;
					}
					else if(num >= n->getFirstKey()->getID() && num <= n->getSecondKey()->getID())
					{
						n = n->getSecondChild();
						hasNShifted = true;
					}
					else if(num >= n->getSecondKey()->getID() && num <= n->getThirdKey()->getID())
					{
						n = n->getThirdChild();
						hasNShifted = true;
					}
					else if(num >= n->getThirdKey()->getID())
					{
						n = n->getFourthChild();
						hasNShifted = true; 
					}
				}
				
			}
			while (hasNShifted);	
		}

		

		string displayAllHelper(BTreeNode* n)
		{
			string result;
			if(n != NULL)
			{
				result.append(n->display());
				result.append(displayAllHelper(n->getFirstChild()));
				result.append(displayAllHelper(n->getSecondChild()));
				result.append(displayAllHelper(n->getThirdChild()));
				result.append(displayAllHelper(n->getFourthChild()));
			}
			return result;
		}
		
		void splitNode(BTreeNode* n)
		{
			BTreeNode* left;
			BTreeNode* top;

			if (n->getParent() == NULL && !n->hasTooManyChildren())
			{
				left = new BTreeNode();
				top = new BTreeNode();

				left->insert(n->getFirstKey());
				n->setFirstKey(NULL);

				top->insert(n->getSecondKey());
				n->setSecondKey(NULL);

				left->setParent(top);
				n->setParent(top);
				top->setFirstChild(left);
				top->setSecondChild(n);
				n->orderKeys();

				root = top;
			}
			else if(n->getParent() != NULL && !n->hasTooManyChildren())
			{
				left = new BTreeNode();

				left->insert(n->getFirstKey());
				n->setFirstKey(NULL);

				n->getParent()->insert(n->getSecondKey());
				n->setSecondKey(NULL);

				left->setParent(n->getParent());

				if (n == n->getParent()->getFirstChild())
				{
					n->getParent()->setFifthChild(n->getParent()->getFourthChild());
					n->getParent()->setFourthChild(n->getParent()->getThirdChild());
					n->getParent()->setThirdChild(n->getParent()->getSecondChild());
					n->getParent()->setSecondChild(n->getParent()->getFirstChild());
					n->getParent()->setFirstChild(left);
				}
				else if(n == n->getParent()->getSecondChild())
				{
					n->getParent()->setFifthChild(n->getParent()->getFourthChild());
					n->getParent()->setFourthChild(n->getParent()->getThirdChild());
					n->getParent()->setThirdChild(n->getParent()->getSecondChild());
					n->getParent()->setSecondChild(left);
				}
				else if(n == n->getParent()->getThirdChild())
				{
					n->getParent()->setFifthChild(n->getParent()->getFourthChild());
					n->getParent()->setFourthChild(n->getParent()->getThirdChild());
					n->getParent()->setThirdChild(left);
				}
				else if(n == n->getParent()->getFourthChild())
				{
					n->getParent()->setFifthChild(n->getParent()->getFourthChild());
					n->getParent()->setFourthChild(left);
				}

				n->orderKeys();
			}
			else if (n->getParent() == NULL && n->hasTooManyChildren())
			{
				left = new BTreeNode();
				top = new BTreeNode();

				left->insert(n->getFirstKey());
				n->setFirstKey(NULL);

				top->insert(n->getSecondKey());
				n->setSecondKey(NULL);

				left->setParent(top);
				n->setParent(top);
				top->setFirstChild(left);
				top->setSecondChild(n);
				n->orderKeys();

				left->setFirstChild(n->getFirstChild());
				left->setSecondChild(n->getSecondChild());
				n->getFirstChild()->setParent(left);
				n->getSecondChild()->setParent(left);

				n->setFirstChild(n->getThirdChild());
				n->setSecondChild(n->getFourthChild());
				n->setThirdChild(n->getFifthChild());
				n->setFourthChild(NULL);
				n->setFifthChild(NULL);

				root = top;
			}
			else if(n->getParent() != NULL && n->hasTooManyChildren())
			{
				left = new BTreeNode();

				n->getParent()->insert(n->getSecondKey());
				n->setSecondKey(NULL);

				left->insert(n->getFirstKey());
				n->setFirstKey(NULL);
				left->setFirstChild(n->getFirstChild());
				left->setSecondChild(n->getSecondChild());
				left->getFirstChild()->setParent(left);
				left->getSecondChild()->setParent(left);

				n->setFirstChild(n->getThirdChild());
				n->setSecondChild(n->getFourthChild());
				n->setThirdChild(n->getFifthChild());
				n->setFourthChild(NULL);
				n->setFifthChild(NULL);
				left->setParent(n->getParent());

				if (n == n->getParent()->getFirstChild())
				{
					n->getParent()->setFifthChild(n->getParent()->getFourthChild());
					n->getParent()->setFourthChild(n->getParent()->getThirdChild());
					n->getParent()->setThirdChild(n->getParent()->getSecondChild());
					n->getParent()->setSecondChild(n->getParent()->getFirstChild());
					n->getParent()->setFirstChild(left);
				}
				else if(n == n->getParent()->getSecondChild())
				{
					n->getParent()->setFifthChild(n->getParent()->getFourthChild());
					n->getParent()->setFourthChild(n->getParent()->getThirdChild());
					n->getParent()->setThirdChild(n->getParent()->getSecondChild());
					n->getParent()->setSecondChild(left);
				}
				else if(n == n->getParent()->getThirdChild())
				{
					n->getParent()->setFifthChild(n->getParent()->getFourthChild());
					n->getParent()->setFourthChild(n->getParent()->getThirdChild());
					n->getParent()->setThirdChild(left);
				}
				else if(n == n->getParent()->getFourthChild())
				{
					n->getParent()->setFifthChild(n->getParent()->getFourthChild());
					n->getParent()->setFourthChild(left);
				}

				n->orderKeys();
			}
		}
		

		void purgeHelper(BTreeNode* n)
		{
			if (n != NULL)
			{
				purgeHelper(n->getFirstChild());
				purgeHelper(n->getSecondChild());
				purgeHelper(n->getThirdChild());
				purgeHelper(n->getFourthChild());
				delete n;
			}
		}
	public:
		BTree()
		{
			root = NULL;
		}

		void purge()
		{
			purgeHelper(root);
			root = NULL;
		}

		void insert(int num, string first, string last, string maj, float score)
		{
			BTreeKey* newKey = new BTreeKey(num, first, last, maj, score);

			if (root == NULL)
			{
				root = new BTreeNode();
				root->insert(newKey);
				return;
			}

			BTreeNode* tmp = root;

			traverse(tmp, num);

			tmp->insert(newKey);

			while(tmp != NULL)
			{
				if (tmp->isFull())
				{
					splitNode(tmp);
				}
				tmp = tmp->getParent();
			}
		}

		string findRecord(int num)
		{
			BTreeNode* tmp = root;
			traverse(tmp, num, true);
			string result = "";

		 	if (tmp->contains(num))
		 	{
		 		result.append(tmp->display());
                //return true;
		 	}
		 	else
		 	{
		 		result.append("Record " + to_string(num) + " is not found");
                //return false;
		 	}

		 	return result;
		}

		string displayAll()
		{
			string result;

			if (root == NULL)
			{
				result.append("Empty");
			}
			else
			{
				result.append(displayAllHelper(root));
			}
			return result;
		}
};

#endif
