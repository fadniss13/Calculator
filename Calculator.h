/****************************************************************************
 * Class Name: Calculator 
 *
 * Description: The Class includes all the functions required to perform calculations 
 * 				 in the main file
 * Constructors: Calculator()
 * Destructor: N/A
 *
 * public :  
 *	void add(double, double)  :   Adds up the two values that are inputted and stacked on top of stack
 *	void add(double)          :   Adds up the value that is inputted to the top value of the stack
 *	void add()                :   Adds up the last and the next to last values on the top of the stack
 *	void operator+(double)    :   Overloads the add function using the "+" operator
 *	
 *	void sub(double, double)  :   Subtracts the two values that are inputted and stacked on top of stack
 *	void sub(double)          :   Subtracts the value that is inputted from the top value of the stack
 *	void sub()                :   Subtracts the top-most value of the stack from the next to top-most value
 *	void operator-(double)    :   Overloads the sub function using the "-" operator
 *	
 *	void mult(double, double) :  Multiplies the two values that are inputted and stacked on top of stack
 *	void mult(double)         :  Multiplies the value that is inputted to the top value of the stack
 *	void mult()               :  Multiplies the last and the next to last values on the top of the stack
 *	void operator*(double)    :  Overloads the mult function using the "*" operator
 *	
 *	void div(double, double)  :   Divides the two values that are inputted and stacked on top of stack
 *	void div(double)          :   Divides the value that is inputted to the top value of the stack
 * void div()                :   Divides the top-most value of the stack from the next to top-most value
 *		   								(if divided by zero, prints out an error message)
 *	void operator/(double)    :   Overloads the div function using the "/" operator
 *	
 *	void clear()              :  Clears out the stack completely and pushes "0" on the top
 *	void enter(double)		  :  Feeds in a value that is inputted by the user
 *	void prt()                :  Prints out the top-most element of the stack
 *	void operator=(double)    :  Overloads the print function using the "=" operator
 * int stackStatus();        :  Returns 0,1 or 2 depending on status of the stack
 *	
 * protected: 
 *  friend ostream & operator<<(ostream &os, const Calculator cal)  :  Overloads the print function using the "<<" operator
 * private:  N/A
 * 
 * public: N/A
 * protected: N/A
 * private: 
 *	double a               :  Used in the member functions to set the top-most stack value to it to perform calculations
 *	double b               :  Used in the member functions to set the top-most stack value to it to perform calculations
 *	stack<double> answer   :  The stack created to do all the calculations
 * 
 ***************************************************************************/

#ifndef CALC_H
#define CALC_H
#include <iostream>
#include <stack>
using namespace std;

class Calculator { 

	public:
		Calculator(); 
		void add(double, double);
		void add(double);
		void add();
		void sub(double, double);
		void sub(double);
		void sub();
		void mult(double, double);
		void mult(double);
		void mult();
		void div(double, double);
		void div(double);
		void div();
		void clear();
		void enter(double);
		void prt();	
		void operator+(double);
		void operator-(double);
		void operator*(double);
		void operator/(double);
		void operator=(double);
		int stackStatus();		
	protected: 
		friend ostream & operator<<(ostream &os, const Calculator cal);
	private:
		double a; double b;
		stack<double> answer;
};

#endif