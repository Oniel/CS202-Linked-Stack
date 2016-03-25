//  Main program
//  Test stack implementation

#include <iostream>
#include <string>
#include "linkedStack.h"

using namespace std;

int main()
{

// ---------------------------------------------------------------
//  Initial declarations and headers...

	string stars, bars;
	stars.append(70,'*');
	bars.append(70,'-');

	cout << stars << endl << "CS 202 - Assignment #13" << endl;
	cout << "Linked List Stacks" << endl;
	cout << "Testing for Stack Operations" << endl << endl;

// ---------------------
//  Basic tests for linked stack implementation.
//  Integers

	linkedStack<int> iStack;
	int	inums[] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
	int	ilen = ( sizeof(inums) / sizeof(inums[0]) );
	int	iVal, iTmp;

	cout << bars << endl << "Stack Testing -> Integers" << endl << endl;

	cout << "Original List:  ";
	for (int i=0; i<ilen; i++) {
		iStack.push(inums[i]);
		cout << iStack.peek() << " ";
	}

	iVal = iStack.stackSum();
	cout << endl << endl << "Sum is: " << iVal << endl;

	linkedStack<int> iStackA(iStack);
	linkedStack<int> iStackB;
	iStackB = iStack;

	if ( iStackB != iStack )
		cout << "Stack assignment operator failed." << endl;

	cout << endl << "Reverse Original List:  ";
	while (!iStack.isStackEmpty())
		cout << iStack.pop() << " ";

	iTmp = iStackB.pop();
	if ( iTmp != iStackA.peek() )
		cout << "Stack peek or pop error." << endl;

	if (iStackA == iStackB)
		cout << "Equality operator failed." << endl;
	iTmp += 1;
	iStackB.push(iTmp);

	if (iStackA == iStackB)
		cout << "Equality operator failed." << endl;

	cout << endl << "Reverse, copy A:  ";
	while (!iStackA.isStackEmpty())
		cout << iStackA.pop() << " ";

	if (iStackA == iStackB)
		cout << "Stack equality operator error." << endl;

	cout << endl << "Reverse, copy B (modified):  ";
	while (!iStackB.isStackEmpty())
		cout << iStackB.pop() << " ";
	cout << endl;

	cout << endl << "Stack empty errors..." << endl;
	iStackA.deleteStack();						// ok
	iStackB.deleteStack();						// ok
	iStackA.pop();							// err
	iStackA.peek();							// err
	iStackB.pop();							// err
	iStackB.peek();							// err

	cout << endl << endl;

// ---------------------
//  Doubles

	linkedStack<double> dStack;
	double	dnums[] = {1.1, 3.3, 5.5, 7.7, 9.9, 11.11, 13.13, 15.15, 12.1};
	int	dlen = ( sizeof(dnums) / sizeof(dnums[0]) );
	double	dVal, dTmp;

	cout << bars << endl << "Stack Testing -> Doubles" << endl << endl;

	cout << "Original List:  ";
	for (int i=0; i<dlen; i++) {
		dStack.push(dnums[i]);
		cout << dStack.peek() << " ";
	}

	dVal = dStack.stackSum();
	cout << endl << endl << "Sum is: " << dVal << endl;

	linkedStack<double> dStackA(dStack);
	linkedStack<double> dStackB;
	dStackB = dStack;

	if ( dStackB != dStack )
		cout << "Stack assignment operator failed." << endl;

	cout << endl << "Reverse Original List:  ";
	while (!dStack.isStackEmpty())
		cout << dStack.pop() << " ";

	dTmp = dStackB.pop();
	if ( dTmp != dStackA.peek() )
		cout << "Stack peek or pop error." << endl;

	if (dStackA == dStackB)
		cout << "Equality operator failed." << endl;
	dTmp += 1.0;
	dStackB.push(dTmp);

	if (dStackA == dStackB)
		cout << "Equality operator failed." << endl;

	cout << endl << "Reverse, copy A:  ";
	while (!dStackA.isStackEmpty())
		cout << dStackA.pop() << " ";

	if (dStackA == dStackB)
		cout << "Stack equality operator error." << endl;

	cout << endl << "Reverse, copy B (modified):  ";
	while (!dStackB.isStackEmpty())
		cout << dStackB.pop() << " ";
	cout << endl;

	cout << endl << "Stack empty errors..." << endl;
	dStackA.deleteStack();						// ok
	dStackB.deleteStack();						// ok
	dStackA.pop();							// err
	dStackA.peek();							// err
	dStackB.pop();							// err
	dStackB.peek();							// err

	cout << endl << endl;

// ---------------------
//  Strings

	linkedStack<string> strStack;

	string words[] = {"enters", "green", "in", "a", "jumps", "big",
			"familiar", "dog", "hills"};
	int	slen = sizeof(words) / sizeof(string);
	string	sTmp;

	cout << bars << endl << "Stack Testing -> Strings" << endl << endl;

	cout << "Original List:  ";
	for (int i=0; i<slen; i++) {
		strStack.push(words[i]);
		cout << strStack.peek() << " ";
	}

	linkedStack<string> strStackA(strStack);
	linkedStack<string> strStackB;
	strStackB = strStack;

	if ( strStackB != strStack )
		cout << "Stack assignment operator failed." << endl;


	cout << endl << "Reverse Original List:  ";
	while (!strStack.isStackEmpty())
		cout << strStack.pop() << " ";

	sTmp = strStackB.pop();
	if ( sTmp != strStackA.peek() )
		cout << "Stack peek or pop error." << endl;

	if (strStackA == strStackB)
		cout << "Equality operator failed." << endl;
	sTmp = "hello";
	strStackB.push(sTmp);

	if (strStackA == strStackB)
		cout << "Equality operator failed." << endl;

	cout << endl << "Reverse, copy A:  ";
	while (!strStackA.isStackEmpty())
		cout << strStackA.pop() << " ";

	if (strStackA == strStackB)
		cout << "Stack equality operator error." << endl;

	cout << endl << "Reverse, copy B (modified):  ";
	while (!strStackB.isStackEmpty())
		cout << strStackB.pop() << " ";
	cout << endl;
    cout << strStackB.pop();

	cout << endl << "Stack empty errors..." << endl;
	strStackA.deleteStack();						// ok
	strStackB.deleteStack();						// ok
	strStackA.pop();							// err
	strStackA.peek();       					// err
	strStackB.pop();							// err
	strStackB.peek();							// err

	cout << endl << endl;

// ---------------------------------------------------------------
//  All done.

	cout << bars << endl << "Game Over, thank you for playing." << endl;

	return 0;
}

