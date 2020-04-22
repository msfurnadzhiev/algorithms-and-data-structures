void insert_at_bottom(stack<int>* S, int data) {
    if(S->size() == 0) {
        S->push(data);
    }
    else {
        int temp = S->top();
        S->pop();
        insert_at_bottom(S, data);
        S->push(temp);
    }
}

void reverse(stack<int>* S) {
    if(S->empty()) {
        return;
    }
    int a = S->top();
    S->pop();
    reverse(S);
    insert_at_bottom(S,a);
}

