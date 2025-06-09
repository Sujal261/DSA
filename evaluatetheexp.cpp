#include <iostream>
#include <stack>
#include <cctype> 

using namespace std;

int evaluatePostfix(string expr) {
    stack<int> st;

    for (char ch : expr) {
        if (isdigit(ch)) {
            st.push(ch - '0');
        } else {
            
            int val2 = st.top(); st.pop();
            int val1 = st.top(); st.pop();

            switch (ch) {
                case '+': st.push(val1 + val2); break;
                case '-': st.push(val1 - val2); break;
                case '*': st.push(val1 * val2); break;
                case '/': st.push(val1 / val2); break;
                default:
                    cout << "Invalid operator encountered: " << ch << endl;
                    return -1;
            }
        }
    }

    return st.top(); 
}

int main() {
    string postfix;

    cout << "Enter postfix expression (single-digit operands only, no spaces): ";
    cin >> postfix;

    int result = evaluatePostfix(postfix);
    cout << "Evaluated Result: " << result << endl;

    return 0;
}
