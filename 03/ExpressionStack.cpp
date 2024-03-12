#include <iostream>
#include <string>
using namespace std;

template <class T>
class StackNode{
public:
	T data;
	StackNode<T> *next;
};

template <class T>
class Stack{
private:
	StackNode<T> *top = NULL;

public:
	void push(T val){
		if (top == NULL){
			top = new StackNode<T>;
			top->data = val;
			top->next = NULL;
		}
		else{
			StackNode<T> *temp = new StackNode<T>;
			temp->data = val;
			temp->next = top;
			top = temp;
		}
	}

	T pop(){
		if (isEmpty()){
			return '\0';
		}
		T data = top->data;
		StackNode<T> *temp = top;
		top = top->next;
		delete temp;
		return data;
	}

	T peek(){
		if (top == NULL){
			return -1;
		}
		else{
			return top->data;
		}
	}

	bool isEmpty(){
		return top == NULL;
	}
};

string reverse(string str){
	int start = 0;
	int end = str.length() - 1;

	while (start < end){
		char temp = str[start];
		str[start] = str[end];
		str[end] = temp;

		start++;
		end--;
	}
	return str;
}

class InfixToPostfixConversion{
public:
	string s;
	Stack<char> stack;
	string postfix = "";

public:
	void get(){
		cout << "Enter a valid infix expression: ";
		cin >> s;
	}

	int precedence(char op){
		if (op == '^'){
			return 3;
		}
		else if (op == '*' || op == '/'){
			return 2;
		}
		else if (op == '+' || op == '-'){
			return 1;
		}
		else{
			return 0;
		}
	}

	void solve(){
		for (int i = 0; i < s.length(); i++){
			char ch = s[i];
			if (isalnum(ch)){
				postfix = postfix + ch;
			}
			else if (ch == '('){
				stack.push(ch);
			}
			else if (ch == ')'){
				while (!stack.isEmpty() && stack.peek() != '('){
					postfix += stack.pop();
				}
				stack.pop();
			}
			else{
				while (!stack.isEmpty() && precedence(ch) <= precedence(stack.peek())){
					postfix += stack.pop();
				}
				stack.push(ch);
			}
		}
		while (!stack.isEmpty()){
			postfix += stack.pop();
		}
		cout << "Postfix Expression: " << postfix << endl;
	}
};

class InfixToPrefixConversion{
public:
	string s;
	Stack<char> stack;
	string prefix = "";

public:
	void get(){
		cout << "Enter a valid infix expression: ";
		cin >> s;
		s = reverse(s);
	}

	int precedence(char op){
		if (op == '^'){
			return 3;
		}else if (op == '*' || op == '/'){
			return 2;
		}else if (op == '+' || op == '-'){
			return 1;
		}else{
			return 0;
		}
	}

	void solve(){
		for (int i = 0; i < s.length(); i++){
			char ch = s[i];
			if (isalnum(ch)){
				prefix = prefix + ch;
			}
			else if (ch == ')'){
				stack.push(ch);
			}
			else if (ch == '('){
				while (!stack.isEmpty() && stack.peek() != ')'){
					prefix += stack.pop();
				}
				stack.pop();
			}
			else{
				while (!stack.isEmpty() && precedence(ch) < precedence(stack.peek())){
					prefix += stack.pop();
				}
				stack.push(ch);
			}
		}
		while (!stack.isEmpty()){
			prefix += stack.pop();
		}
		prefix = reverse(prefix);
		cout << "Prefix Expression: " << prefix << endl;
	}
};

class PostfixEvaluation{
public:
	string postfix;
	Stack<int> stack;

	int evaluate(){
		for (char c : postfix){
			if (isalpha(c)){
				int value;
				cout << "Enter value for evalution : ";
				cin >> value;
				stack.push(value);
			}
			else{
				int operand2 = stack.peek();
				stack.pop();
				int operand1 = stack.peek();
				stack.pop();

				switch (c){
				case '+':
					stack.push(operand1 + operand2);
					break;
				case '-':
					stack.push(operand1 - operand2);
					break;
				case '*':
					stack.push(operand1 * operand2);
					break;
				case '/':
					stack.push(operand1 / operand2);
					break;
				}
			}
		}
		return stack.peek();
	}
};

class PrefixEvaluation{
public:
	string prefix;
	Stack<int> stack;

	int evaluate(){
		prefix = reverse(prefix);

		for (char c : prefix){
			if (isdigit(c)){
				int value;
				cout << "Enter element for evaluation: ";
				cin >> value;
				stack.push(value);
			}
			else{
				int operand1 = stack.peek();
				stack.pop();
				int operand2 = stack.peek();
				stack.pop();

				switch (c){
				case '+':
					stack.push(operand1 + operand2);
					break;
				case '-':
					stack.push(operand1 - operand2);
					break;
				case '*':
					stack.push(operand1 * operand2);
					break;
				case '/':
					stack.push(operand1 / operand2);
					break;
				}
			}
		}
		return stack.peek();
	}
};

int main(){
	int choice;
	while (true){
		cout << "\nChoose an operation:" << endl;
		cout << "1. Infix to Prefix" << endl;
		cout << "2. Infix to Postfix" << endl;
		cout << "3. Postfix Evaluation" << endl;
		cout << "4. Prefix Evaluation" << endl;
		cout << "5. Exit" << endl;
		cout << "Enter your choice: ";
		cin >> choice;

		switch (choice){
		case 1:
		{
			InfixToPrefixConversion ipc;
			ipc.get();
			ipc.solve();
			break;
		}
		case 2:
		{
			InfixToPostfixConversion ipc;
			ipc.get();
			ipc.solve();
			break;
		}
		case 3:
		{
			PostfixEvaluation pe;
			cout << "Enter a valid postfix expression: ";
			cin >> pe.postfix;
			int result = pe.evaluate();
			cout << "Result: " << result << endl;
			break;
		}
		case 4:
		{
			PrefixEvaluation pe;
			cout << "Enter a valid prefix expression: ";
			cin >> pe.prefix;
			int result = pe.evaluate();
			cout << "Result: " << result << endl;
			break;
		}
		case 5:
		{
			cout << "Exiting the program." << endl;
			return 0;
		}
		default:
			cout << "Invalid choice. Please choose a valid operation." << endl;
			break;
		}
	}
	return 0;
}