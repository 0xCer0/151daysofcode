// Given an infix expression in the form of string str. Convert this infix expression to postfix expression.

// Infix expression: The expression of the form a op b. When an operator is in-between every pair of operands.
// Postfix expression: The expression of the form a b op. When an operator is followed for every pair of operands.
// â€‹Note: The order of precedence is: ^ greater than * equals to / greater than + equals to -. 
// Example 1:

// Input: str = "a+b*(c^d-e)^(f+g*h)-i"
// Output: abcd^e-fgh*+^*+i-
// Explanation:
// After converting the infix expression 
// into postfix expression, the resultant 
// expression will be abcd^e-fgh*+^*+i-


#include<bits/stdc++.h>
using namespace std;

void infix2postfix(string);
int prec(string);

int main(){
	int t;
	string str;

	cin >> t;
	while(t--){
	    cin >> str;
	    infix2postfix(str);
	    cout << endl;
	}
	return 0;
}

int prec(string str){
    if(str == "^")
        return 3;
    else if(str == "*" || str == "/")
        return 2;
    else if(str == "+" || str == "-")
        return 1;
    return -1;
}

void infix2postfix(string str){
    stack<string> s1, s2;

    for(int i = 0; i < str.length(); i++){
        string x(1, str[i]);
        if(("a" <= x && x <= "z") || ("A" <= x && x <= "Z"))
            s1.push(x);
        else{
            if(x == "(")
                s2.push(x);
            else if(x == ")"){
                while(!s2.empty() && s2.top() != "("){
                    string temp1 = s1.top();
                    s1.pop();
                    string temp2 = s1.top();
                    s1.pop();
                    string temp3 = temp2 + temp1 + s2.top();
                    s1.push(temp3);
                    s2.pop();
                }
                s2.pop();
            }
            else{
                while(!s2.empty() && (prec(s2.top()) >= prec(x))){
                    string temp1 = s1.top();
                    s1.pop();
                    string temp2 = s1.top();
                    s1.pop();
                    string temp3 = temp2 + temp1 + s2.top();
                    s1.push(temp3);
                    s2.pop();
                }
                s2.push(x);
            }
        }
    }
    while(!s2.empty()){
        string temp1 = s1.top();
        s1.pop();
        string temp2 = s1.top();
        s1.pop();
        string temp3 = temp2 + temp1 + s2.top();
        s1.push(temp3);
        s2.pop();
    }
    cout << s1.top();
}