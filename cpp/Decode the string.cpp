// An encoded string (s) is given, the task is to decode it. The pattern in which the strings are encoded is as follows. 

// <count>[sub_str] ==> The substring 'sub_str' 
//                       appears count times.
// Examples:  
// Input : str[] = "1[b]"
// Output : b

#include<bits/stdc++.h>
using namespace std;

string decode(string);

int main(){
    int t;
    string str;

    cin >> t;
    while(t--){
        cin >> str;
        cout << decode(str) << endl;
    }
    return 0;
}

string decode(string str){
    stack<string> s;

    for(int i = 0; i < str.length(); i++){
        // line below is something you are looking for
        string x(1, str[i]);
        while('0' <= str[i] && str[i] <= '9' && '0' <= str[i + 1] && str[i + 1] <= '9'){
            x = x + str[i + 1];
            i++;
        }
        if(x == "]"){
            string temp1, temp2;
            while(s.top() != "["){
                temp1 = s.top() + temp1;
                s.pop();
            }
            s.pop();
            int num = stoi(s.top());
            s.pop();
            while(num--)
                temp2 = temp2 + temp1;
            s.push(temp2);
        }
        else
            s.push(x);
    }
    return s.top();
}