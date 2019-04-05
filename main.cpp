/****************************************************************************
* Description: This program creates a postfix (RPN) calculator that asks the user for values
*					and operations to be done and returns the calculated value. 
*
* Inputs: 1) The values and operations that the user inputs to be calculated
*			 2) Input 'X' 
*			 3) Input 'C' 
*
* Output: 1) The calculated answer of the user inputs
*			 2) Terminates the program and returns "Goodbye!"
*			 3) Clears the calculator and previous operations and values
*
***************************************************************************/
 
#include "Calculator.h"
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

bool isOperator(const string& input, int& opNum);
void performOp(const int opNum, Calculator& calc);

int main (){

	Calculator calc;
	string input;
	int opNum;
	double d;
	char decimal = '.';

	cout << "RPN calculator using postfix notation\n";

	while(true){
	
		cout << "Next: ";
		cin >> input;
		cout << endl; 

		if(isOperator(input, opNum)){
			if(calc.stackStatus() == 0 || input == "="){
				performOp(opNum, calc);
			}
			else if(calc.stackStatus() == 2){
				cout << "Syntax error: Please enter a value before operation!\n\n";
			}
			else{
				cout << "Syntax error: Please enter at least two values before the operator!\n\n";
			}
		}
		else if(istringstream(input) >> d){
			if(input.find(decimal) == input.rfind(decimal)){
			  calc.enter(d);
			  calc.prt();
			}
			else{
			  cout << "Syntax error: Input can only have one decimal point\n\n";
			}
		}
		else if(input == "C" || input == "c"){
			calc.clear();
			calc.prt();
		}
		else if(input == "X" || input == "x"){
			cout << "Goodbye!" << endl;
			return 0;
		}
		else{
			cout << "Syntax error: Please enter supported operators and commands only!\n\n";
		}
	}
}


//Function to check for the operators validity
bool isOperator(const string& input, int& opNum){
	string operations[] = {"+", "-", "*", "/", "="};
	int i;
	for(i = 0; i < 5; ++i){
		if(input == operations[i]){
		    opNum = i + 1;
			return true;
		}
	}
	return false;
}


//Function to perform the operation
void performOp(const int opNum, Calculator& calc){
   switch(opNum) {
      case 1 :
         calc.add();
         calc.prt();
         break;

      case 2 :
         calc.sub();
         calc.prt();
         break;

      case 3 :
         calc.mult();
         calc.prt();
         break;

      case 4 :
			calc.div();
			calc.prt();
			break;

      case 5 :
         if(calc.stackStatus() == 2){
            cout << "Syntax error: Please enter a value before operation!\n\n";
            break;
         }
         else {
            calc.prt();
            break;
         }

      default :
         cout << "Syntax error: Please enter supported operators and commands only!\n";
         break;
   }
}
