/*
Reverse Polish Notation

The program work with expression define as:
 
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
<variable> ::= <letter>
<letter> ::= a| b| c| ... |x| y| z

*/

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

void translate(char* str, char* new_str) {

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
