/*
maor levi 328301981
sadna 8.1
we create use in stack by vector, the user put value in the stack.
the program recive string with math phrase stirng and translte this to phrase math
*/
#include "Vector.h"
#include "StackVector.h"
#include <string>
#include <unordered_map>
#include <iostream>
using namespace std;

unordered_map<char, int>precedence
{
  {'+', 1},
  {'-', 1},
  {'*', 2},
  {'/', 2}
};

bool ISoperator(char ch)
{//check which operator this
	if (ch == '*' || ch == '+' || ch == '-' || ch == '/')
	{
		return true;
	}
	else
		return false;
}

string infixToPostfix(const string& expression)
{
	string postfix;
	StackVector<char>Stack(100);
	bool flag = false;
	for (char ch : expression)
	{
		if (ch == '(')
		{
			Stack.push(ch);
			flag = false;
		}
		else
			if (ch == ')')
			{
				postfix += ' ';
				while ((!Stack.isEmpty()) && Stack.top() != '(')
				{
					postfix += Stack.pop();
					

				}
				Stack.pop();
				flag = false;
			}
			else
				if (ISoperator(ch))
				{
					while ((!Stack.isEmpty()) && (Stack.top() != '(') && (precedence[Stack.top()] >= precedence[ch]))
					{
						
						postfix += Stack.pop();
						
					}
					Stack.push(ch);
					flag = false;
				}
				else {
					if (flag ==false ) {
						if(postfix.empty())
							postfix += ch;
						else {
							postfix += ' ';
							postfix += ch;
						}
					}
					else {
						postfix += ch;
					}
						flag = true;
					
				}
		
	 
	}
	while (!Stack.isEmpty())
	{
		postfix += ' ';
		postfix += Stack.pop();
		
	}
		
	return postfix;

}

template <class T>
int calcPostfix(const string expression)//calculate the value of the string
{
	bool flag = false;
	StackVector<int>Stack(100);
	int x;
	for (char ch : expression)
	{
		int result = 0;
		switch (ch)
		{
		case '*':
		{
			result = Stack.pop() * Stack.pop();
			Stack.push(result);
			flag = false;
			break;
		}
		case '/':
		{
			int y = Stack.pop();
			int z= Stack.pop();
			result = z / y;
			Stack.push(result);
			flag = false;
			break;
		}
		case '+':
		{
			result = Stack.pop() + Stack.pop();
			Stack.push(result);
			flag = false;
			break;
		}
		case '-':
		{
			int y = Stack.pop();
			int z = Stack.pop();
			result = z-y;
			Stack.push(result);
			flag = false;
			break;
		}
		case ' ':
		{
			flag = false;
			break;
		}

		default: {
			if (flag == true) {
				x = 10*Stack.pop();
				Stack.push(x);
			}
			else {
				result = ch - 48;
				Stack.push(result);
				flag = true;
			}
			break;
		}
	}
		
	}
	
	return Stack.top();

}

int main() {

	string exp;
	cout << "enter an infix expression as a string" << endl;
	cin >> exp;
	string postfix = infixToPostfix(exp);
	cout << "in postfix form: " << postfix << endl;
	cout << "calculated value: " << calcPostfix<string>(postfix) << endl;
	return 0;
}

