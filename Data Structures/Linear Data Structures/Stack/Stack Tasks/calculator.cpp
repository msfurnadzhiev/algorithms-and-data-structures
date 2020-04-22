/*

Calculation of expression define as:

<expression> ::= <expression> |
		 <expression> + <term> |
		 <expression> – <term>
<term> ::= <multiplier>|
	   <term> * <multiplier> |
	   <term> / <multiplier>
<multiplier> ::= <number> | <variable> | (<expression>)|
		 <number> ^ <number> | <variable> ^ <number>| (<expression>) ^ <number> |
		 <number> ^ <variable> | <variable> ^ <variable> | (<expression>) ^ <variable> | 
		 <number> ^ (<expression>) | <variable> ^ (<expression>) | (<expression>) ^ (<expression>)
<number> ::= <digit> | <number> <digit>
<digit> ::= 0|1| ... |9

*/
#include <iostream>
#include <string.h>
#include <stack>
#include <cmath>

using namespace std;


int priority(char operation) {
    int priorityIndex;
    switch (operation) {
        case '+':
        case '-': priorityIndex = 0; break;
        case '*':
        case '/': priorityIndex = 1; break;
        case '^': priorityIndex = 2; break;
        default: priorityIndex = -1;
    }
    return priorityIndex;
}

void translate(char* str, char* new_str)
{
    stack<char> st;
    st.push('(');
    char x;
    int i = 0, j = -1;

    while (i < (int)strlen(str)) {
        if ((str[i] >= '0' && str[i] <= '9') || (str[i] >= 'a' && str[i] <= 'z')) {
            j++;
            new_str[j] = str[i];
        }
        else {
            if (str[i] == '(') {
                st.push(str[i]);
            }
            else {
                if (str[i] == ')') {
                    x = st.top();
                    st.pop();
                    while (x != '(') {
                        j++;
                        new_str[j] = x;
                        x = st.top();
                        st.pop();
                    }
                } else {
                    if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/' || str[i] == '^') {
                        x = st.top();
                        st.pop();
                        while (x != '(' && priority(x) >= priority(str[i])) {
                            j++;
                            new_str[j] = x;
                            x = st.top();
                            st.pop();
                        }
                        j++;
                        new_str[j] = ' ';
                        st.push(x);
                        st.push(str[i]);
                    }
                }
            }
        }
        i++;
    }
    x = st.top();
    st.pop();
    while (x != '(') {
        j++; new_str[j] = x;
        x = st.top();
        st.pop();
    }
    j++;
    new_str[j] = '\0';
}

int reverse(int n) {
    int reversedNumber = 0, remainder;

    while(n != 0)
    {
        remainder = n%10;
        reversedNumber = reversedNumber*10 + remainder;
        n /= 10;
    }

    return reversedNumber;
}

int value(char* s)  {

    stack<int> st;

    int x, y, z;
    unsigned int i = 0;
    int temp = 0, index = 1;
    while (i < (int)strlen(s)) {
        if (s[i] >= '0' && s[i] <= '9') {
            temp += index*((int)s[i]-(int)'0');
            index *= 10;
        }
        else if (s[i] == ' ' && (s[i-1] >= '0' && s[i-1] <= '9')) {
            st.push(reverse(temp));
            temp = 0;
            index = 1;
        }
        else {
            if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/' || s[i] == '^') {
                if(s[i-1] >= '0' && s[i-1] <= '9') {
                    st.push(reverse(temp));
                    temp = 0;
                    index = 1;
                }
                y = st.top();
                st.pop();
                x = st.top();
                st.pop();
                switch (s[i]) {
                    case '+':
                        z = x + y; break;
                    case '-':
                        z = x - y; break;
                    case '*':
                        z = x * y; break;
                    case '/':
                        z = x / y; break;
                    case '^':
                        z = (int)pow(x, y); break;
                    default: return 0;
                }
                st.push(z);
            }
        }
        i++;
    }
    z = st.top();
    st.pop();
    return z;
}

 int main() {

    char str[50] = "(22+32)*(43+21^2)",str2[50];
    translate(str,str2);
    cout << str << " = " << value(str2) << endl;

    return 0;
}
