#include "Calculator.h"
 
Calculator::Calculator(){}
 
// Addition Functions including overloaded function
void Calculator::add(double a, double b){
	answer.push(a + b);
	cout << "ENTER: " << a << " + " << b << endl;
}
void Calculator::add(double b){
	a = answer.top();
	answer.pop();
	answer.push(a + b);
	cout << "ENTER: + " << b << endl;
}
void Calculator::add(){
	b = answer.top();
	answer.pop();
	a = answer.top();
	answer.pop();
	answer.push(a + b);
	cout << "ENTER: Next on stack " << a << " + " << " top of the stack " << b << endl;
}
void Calculator::operator+(double a){
	answer.push(answer.top() + a);
	cout << "ENTER: + " << a << endl;
}


// Subtraction Functions including overloaded function
void Calculator::sub(double a, double b){
	answer.push(a - b);
	cout << "ENTER: " << a << " - " << b << endl;
}
void Calculator::sub(double b){
	a = answer.top();
	answer.pop();
	answer.push(a - b);
	cout << "ENTER: - " << b << endl;
}
void Calculator::sub(){
	b = answer.top();
	answer.pop();
	a = answer.top();
	answer.pop();
	answer.push(a - b);
	cout << "ENTER: Next on stack " << a << " - " << " top of the stack " << b << endl;
}
void Calculator::operator-(double a){
	answer.push(answer.top() - a);
	cout << "ENTER: - " << a << endl;
}



// Multiplication Functions including overloaded function
void Calculator::mult(double a, double b){
	answer.push(a * b);
	cout << "ENTER: * " << a << endl;
}
void Calculator::mult(double b){
	a = answer.top();
	answer.pop();
	answer.push(a * b);
	cout << "ENTER: * " << b << endl;
}
void Calculator::mult(){
	b = answer.top();
	answer.pop();
	a = answer.top();
	answer.pop();
	answer.push(a * b);
	cout << "ENTER: Next on stack " << a << " * " << " top of the stack " << b << endl;
}
void Calculator::operator*(double a){
	answer.push(answer.top() * a);
	cout << "ENTER: * " << a << endl;
}
 

// Division Functions including overloaded function
void Calculator::div(double a, double b){
	answer.push(a / b);
	cout << "ENTER: " << a << " / " << b << endl;
}
void Calculator::div(double b){
	a = answer.top();
	answer.pop();
	answer.push(a / b);
	cout << "ENTER: / " << b << endl;
}
void Calculator::div(){
	b = answer.top();
	answer.pop();
	a = answer.top();
	if(b != 0){
		answer.pop();
		answer.push(a / b);
		cout << "ENTER: Next on stack " << a << " / " << " top of the stack " << b << endl;
	}
	else{
		cout << "Syntax error: Cannot divide by zero!\n\n";
		answer.push(a);
	}
}
void Calculator::operator/(double a){
	answer.push(answer.top() / a);
	cout << "ENTER: / " << a << endl;
}



// Clear Function
void Calculator::clear(){
	while(!answer.empty()) {
		answer.pop();
	}
	answer.push(0);
	cout << "CLEARED ANSWER "<< endl;
}

// Enter Function
void Calculator::enter(double a){
	answer.push(a);
	cout << "ENTER: " << a << endl;
}

// Print Function
void Calculator::prt(){
	cout << "ANSWER: " << answer.top() << endl << endl; 
}

// Overloaded enter function
void Calculator::operator=(double a){
	answer.push(a);
	cout << "ENTER: " << a << endl;
}

// Overloaded print function
ostream & operator<<(ostream &os, const Calculator cal){
	return os << "ANSWER: " << cal.answer.top() << endl << endl;
}

//Checks the status of the stack and returns 0,1 or 2 accordingly
int Calculator::stackStatus(){
   if(!answer.empty()){
      double a = answer.top(); 
      answer.pop();
		if(!answer.empty()){ 
         answer.push(a);
         return 0;
      }
		else{
			answer.push(a);
			return 1;
		}
   }
   else{
		return 2;
   }
}