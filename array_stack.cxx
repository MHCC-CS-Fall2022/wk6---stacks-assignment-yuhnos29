// File: array_stack.cxx
// A small demonstration program for a stack with static array.
// Task1: Prints out the values in the stack from bottom to top.
// Task2: Returns true if the two stacks have the same values in the same order 
// 
// Author: Son Phan
// Date: 11/08/2022


// TEMPLATE CLASS IMPLEMENTED: stack<Item> (see stack2.h for documentation)
// This file is included in the header file, and not compiled separately.
// INVARIANT for the stack class:
//   1. The items in the stack are stored in a static array, with the top of the
//      stack stored at the head node, down to the bottom of the stack at the
//      final node.
//   2. The member variable top_ptr is the head pointer of the linked list.




#include <cassert>  // Provides assert
#include "stack1.h"  // Stack template class
#include <cctype>     // Provides isdigit
#include <cstdlib>    // Provides EXIT_SUCCESS
#include <iostream>   // Provides cout, cin, peek, ignore
//#include <stack>      // Provides the stack template class
using namespace std;
using namespace son_phan;
//PROTOTYPES
//template <class Item>
//void showBottomToTop(stack<Item> s);
// prints out the values in the stack from bottom to top
//bool compareStacks(stack, stack);
// returns true if the two stacks have the same values in the same order

template <class Item>
void showBottomToTop(stack<Item> s)
{
	stack<Item> temp;
	while(s.empty() == false)
	{
		temp.push(s.top());
		s.pop();
	}
	while(temp.empty() == false)
	{
		Item t = temp.top();
		cout << t << " ";
		temp.pop();
		//s.push(t);
	}
}
template <class Item>
bool compareStacks(stack<Item> s1, stack<Item> s2)
{
	bool flag = true;
	if(s1.size() != s2.size())
	{
		return false;
	}
	
	while(s1.empty() == false)
	{
		if(s1.top() != s2.top())
		{
			return false;
		}	
		else 
		{
			s1.pop();
			s2.pop();
		}
	}
	return true;
}

int main()
{
	stack<int> s1;
    	s1.push(1);
    	s1.push(2);
    	s1.push(3);
    	s1.push(4);
 	stack<int> s2;
    	s2.push(1);
    	s2.push(2);
    	s2.push(3);
    	s2.push(4);
    	stack<int> s3;
    	s3.push(2);
    	s3.push(2);
    	s3.push(2);
    	s3.push(2);
    	
    	cout << endl;
    	cout << "S1: "; showBottomToTop(s1);
    	cout << endl;
    	cout << "S2: "; showBottomToTop(s2); 
    	cout << endl;
    	cout << "S3: ";  showBottomToTop(s3);
    	
    	
    	cout << endl;
    	cout << endl;
    	cout << endl;
    	//Compare s1 & s2
    	if(compareStacks(s1,s2) == true)
    	{
    		cout << "S1: ";  showBottomToTop(s1);
    		cout << endl; 
    		cout << "S2: ";  showBottomToTop(s2);
    		cout << endl; 
    		cout << "S1 & S2 are same!!!!" << endl;
    	}
    	else 
    	{
    		cout << "S1: ";  showBottomToTop(s1);
    		cout << endl; 
    		cout << "S2: ";  showBottomToTop(s2);
    		cout << endl; 
    		cout << "S1 & S2 are not same!!!!" << endl;
    	}
    	//Compare s1 & s3
    	cout << endl;
    	if(compareStacks(s1,s3) == true)
    	{
    		cout << "S1: ";  showBottomToTop(s1);
    		cout << endl; 
    		cout << "S3: ";  showBottomToTop(s2);
    		cout << endl; 
    		cout << "S1 & S3 are same!!!!" << endl;
    	}
    	else 
    	{
    		cout << "S1: ";  showBottomToTop(s1);
    		cout << endl; 
    		cout << "S3: ";  showBottomToTop(s2);
    		cout << endl; 
    		cout << "S1 & S3 are not same!!!!" << endl;
    	}
    	cout << endl;
	return EXIT_SUCCESS; 
}



