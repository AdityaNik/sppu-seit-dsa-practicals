// Name = Harish Mahesh Thakre
// Roll No. = 3024
// Branch = IT (SE)   Batch = S4

#include <iostream>
#include <cstring>
using namespace std;

class node{
public:
    char data;
    node *next;
};

class stack{
public:
    node *top;

    stack(){
        top = NULL;
    }

    void push(char value){
        if (top == NULL){
            top = new node;
            top->data = value;
            top->next = NULL;
        }
        else{
            node *add = new node;
            add->data = value;
            add->next = top;
            top = add;
        }
    }

    char pop(){
        if (top == NULL){
            cout << "Stack is empty" << endl;
            return '\0';
        }
        else{
            char value = top->data;
            node *temp = top;
            top = top->next;
            delete temp;
            return value;
        }
    }

    int priority(char op){
        if (op == '+' || op == '-')
            return 1;
        if (op == '*' || op == '/')
            return 2;
        return 0;
    }
};

class expression
{
public:
    stack ST;
    char infix[20];
    char prefix[20];
    char postfix[20];

    void input()
    {
        cout << "Enter an infix expression (up to 20 characters): ";
        cin.getline(infix, 20);
    }

    void infix_to_postfix()
    {
        stack st;
        int i = 0;
        int j = 0;
        while (infix[i] != '\0')
        {
            char current = infix[i];
            if (isalpha(current)){
                postfix[j++] = current;
            }
            else if (current == '+' || current == '-'){
                while (st.top != NULL && st.priority(st.top->data) >= st.priority(current)){
                    postfix[j++] = st.pop();
                }
                st.push(current);
            }
            else if (current == '*' || current == '/'){
                while (st.top != NULL && st.priority(st.top->data) > st.priority(current))
                {
                    postfix[j++] = st.pop();
                }
                st.push(current);
            }
            i++;
        }
        while (st.top != NULL)
        {
            postfix[j++] = st.pop();
        }
        postfix[j] = '\0';
    }

    void display_postfix()
    {
        cout << "Postfix expression: " << postfix << endl;
    }

    void infix_to_prefix()
    {
        char reversedInfix[20];
        int k = 0;
        for (int i = strlen(infix) - 1; i >= 0; i--)
        {
            if (infix[i] == '(')
            {
                reversedInfix[k++] = ')';
            }
            else if (infix[i] == ')')
            {
                reversedInfix[k++] = '(';
            }
            else
            {
                reversedInfix[k++] = infix[i];
            }
        }
        reversedInfix[k] = '\0';

        stack st;
        int i = 0;
        int j = 0;
        while (reversedInfix[i] != '\0')
        {
            char current = reversedInfix[i];
            if (isalpha(current))
            {
                prefix[j++] = current;
            }
            else if (current == '+' || current == '-' || current == '*' || current == '/')
            {
                while (st.top != NULL && st.priority(st.top->data) > st.priority(current))
                {
                    prefix[j++] = st.pop();
                }
                st.push(current);
            }
            i++;
        }
        while (st.top != NULL)
        {
            prefix[j++] = st.pop();
        }
        prefix[j] = '\0';

        int len = strlen(prefix);
        for (int i = 0; i < len / 2; i++)
        {
            char temp = prefix[i];
            prefix[i] = prefix[len - i - 1];
            prefix[len - i - 1] = temp;
        }
    }

    void display_prefix()
    {
        cout << "Prefix expression: " << prefix << endl;
    }
    void evaluate_postfix()
    {
        stack evalpostfix;
        int i = 0;

        while (postfix[i] != '\0')
        {
            char current = postfix[i];
            if (isalpha(current))
            {
                cout << "Enter the value for " << current << ": ";
                int input;
                cin >> input;

                evalpostfix.push(input);
            }
            else if (current == '+' || current == '-' || current == '*' || current == '/')
            {
                int operand2 = evalpostfix.pop();
                int operand1 = evalpostfix.pop();
                int result;

                switch (current)
                {
                case '+':
                    result = operand1 + operand2;
                    break;
                case '-':
                    result = operand1 - operand2;
                    break;
                case '*':
                    result = operand1 * operand2;
                    break;
                case '/':
                    if (operand2 != 0)
                    {
                        result = operand1 / operand2;
                    }
                    else
                    {
                        cout << "Division by zero." << endl;
                        return;
                    }
                    break;
                }

                evalpostfix.push(result);
            }
            i++;
        }

        int finalResult = evalpostfix.pop();
        cout << "Result of the expression: " << finalResult << endl;
    }
    void evaluate_prefix()
    {
        stack evalprefix;
        int len = strlen(prefix);

        for (int i = len - 1; i >= 0; i--)
        {
            char current = prefix[i];

            if (isalpha(current))
            {
                cout << "Enter the value for " << current << ": ";
                int input;
                cin >> input;
                evalprefix.push(input);
            }
            else if (current == '+' || current == '-' || current == '*' || current == '/')
            {
                int operand1 = evalprefix.pop();
                int operand2 = evalprefix.pop();
                int result;

                switch (current)
                {
                case '+':
                    result = operand1 + operand2;
                    break;
                case '-':
                    result = operand1 - operand2;
                    break;
                case '*':
                    result = operand1 * operand2;
                    break;
                case '/':
                    if (operand2 != 0)
                    {
                        result = operand1 / operand2;
                    }
                    else
                    {
                        cout << "Division by zero." << endl;
                        return;
                    }
                    break;
                }

                evalprefix.push(result);
            }
        }

        int finalResult = evalprefix.pop();
        cout << "Result of the expression: " << finalResult << endl;
    }
};

int main()
{
    expression exp;
    exp.input();
    while (true)
    {
        int choice;
        cout << "----------------------------------------------" << endl;
        cout << "Enter your choice: " << endl;
        cout << "1.convert_infix_to_postfix: " << endl;
        cout << "2.convert_infix_to_prefix: " << endl;
        cout << "3.exit." << endl;
        cout << "----------------------------------------------" << endl;
        cout << "choice: ";

        cin >> choice;
        switch (choice)
        {
        case 1:
            exp.infix_to_postfix();
            exp.display_postfix();
            exp.evaluate_postfix();
            cout << "----------------------------------------------" << endl;
            break;
        case 2:
            exp.infix_to_prefix();
            exp.display_prefix();
            exp.evaluate_prefix();
            cout << "----------------------------------------------" << endl;
            break;
        case 3:
            exit(0);
            break;
        default:
            cout << "Invalid choice" << endl;
        }
    }
    return 0;
}
