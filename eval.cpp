//Oniel Toledo          Assignment 13-eval.cpp client           CS202
//The following file is the client file 'eval.cpp' source code
//the program takes into account that the user has provided arguments for looping
//in the format ./eval -c <countnumber> if this argument is improperly entered
//the program outputs an error and exits.
//Assuming the arguments are valid the program will prompt the user to input a
//mathematical expression of the Polish Postfix form.
//If the expression is passed incorrectly error messages will be displayed accordingly
//if the expression is correct it will be performed based on the linkedStack class
//and its corresponding stack, there will be one final entry in the stack, this entry
//will be outputted as the result of the expression.

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "linkedStack.h"
using namespace std;

//prototypes
bool isValidNumber(const string);
int stringToInt(const string);

int main(int argc, char *argv[]){
  cout << "--------------------------------------------------------------------" << endl;

//First part- make sure that program arguments are valid
//-------------------------------------------------------------------------------------------------
  int count;

    //argc must be at least 3, if it is 0 then program executed correctly
    if(argc==0){
        cout << "Usage: ./eval -c <countvalue>" << endl;
        return 0;
        }

    //argc must be 3 for proper execution, if not output error and end program
    if(argc!=3){
        cout << "Usage: ./eval -c <countvalue>" << endl;
        return 0;
        }

    //if argc is equal to 3, verify that -c was provided
    //if the string form of argv[1] is not -c then it was not inputted correctly, end program
    if(string(argv[1])!="-c"){
        cout << "Error, must specify '-c' count specifier." << endl;
        return 0;
        }

    //verify the passed count argc 3 is within an integer greater than 0 and less than 9
    if(isValidNumber(string(argv[2])))
        count = stringToInt(string(argv[2]));
    else{
        cout << "Error, must provide expression prompt count." << endl;
        return 0;
        }

    //program arguments are valid...loop for the specified argument count
    for(int progRuns=0; progRuns<count; progRuns++){

        linkedStack<int> postFixStack;
        string inputStr, word;
        int tmp, pushToStack;
	bool print = true;

//Ask user for postfix expression
//-------------------------------------------------------------------------------------------

    cout << "Enter Postfix Expression:" << endl;
    getline(cin, inputStr);
    //input user string into the stringstream buffer input
    std::istringstream input(inputStr);
    //loop until there is no more input
    
    input >> word;
    while(input){
     
      //if the inputted word is a number add it to the stack
      if(isValidNumber(word)){
	pushToStack = stringToInt(word);
	postFixStack.push(pushToStack);
      }
      //if it is not a number it can either be an operand of type +,-,*,/
      //or it is some other invalid operator, error check for this
      else{
	
	//if word IS an operator error check to see that there is at least 2 stack entries
	if(word=="+" || word=="-" || word=="*" || word=="/"){

	  //if there is at least 2 data sets in the stack perform the arithmetic
	  if(postFixStack.stackCount()>=2){
	    tmp = postFixStack.peek();//store top value and delete it
	    postFixStack.pop();
	    
	    //based on the operator, perform it and...
	    if(word=="+")
	      tmp = postFixStack.peek() + tmp;
	    else
	      if(word=="-")
		tmp = postFixStack.peek() - tmp;
	      else
		if(word=="*")
		  tmp = postFixStack.peek() * tmp;
		else
		  if(word=="/")
		    tmp = postFixStack.peek() / tmp;
		    
	    postFixStack.pop();//delet the top value
	    postFixStack.push(tmp);//set the new calculation to the stack top
	  }
	  else
	    if(postFixStack.stackCount()<2){
	      cout << "Error, invalid expression." << endl;
	      print = false;
	    }
	}
	//if word is not a valid operator dsply error message and exit program
	else
	  if(word!="+" || word!="-" || word!="*" || word!="/"){
	    cout << "Error, invalid expression." << endl;
	    print = false;
	  }
      }
      input >> word;
    }//end of while loop

    //now output the result
    //-------------------------------------------------------------------------------------
    if(print){
      cout << "Postfix Expression: " << inputStr << endl;
      cout << " evaluated is: " << postFixStack.peek() << endl;
    }
    cout << endl;
    
    }//end of for loop
    
    return 0;
}

//make sure the passed number is actually a number
bool isValidNumber(const string nStr){
    unsigned int i;
    for(i=0; i< nStr.length(); i++)
        if(nStr[i]<'0'|| nStr[i]>'9')
            return false;
    return true;
}

//function that returns a passed string to an integer, assuming it is an integer
int stringToInt(const string nStr){
    int x;
    stringstream buff(nStr);
    buff >> x;
    return x;
}
