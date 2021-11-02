// Given an input stream of A of n characters consisting only of lower case alphabets. The task is to find the first non repeating character, each time a character is inserted to the stream. If there is no such character then append '#' to the answer.
 

// Example 1:

// Input: A = "aabc"
// Output: "a#bb"

// Explanation: For every character first non
// repeating character is as follow-
// "a" - first non-repeating character is 'a'
// "aa" - no non-repeating character so '#'
// "aab" - first non-repeating character is 'b'
// "aabc" - first non-repeating character is 'b'

#include<bits/stdc++.h>
using namespace std;

void nonRepeat(int);

int main(){
	int t, n;

	cin >> t;
	while(t--){
	    cin >> n;
	    nonRepeat(n);
	    cout << endl;
	}
	return 0;
}

void nonRepeat(int n){
    char arr[n];
    list<char> dq;
    unordered_map<char, list<char>::iterator> um;
    unordered_set<char> us;

    for(int i = 0; i < n; i++)
        cin >> arr[i];
    for(int i = 0; i < n; i++){
        if(us.find(arr[i]) == us.end()){
            us.insert(arr[i]);
            dq.push_front(arr[i]);
            um[arr[i]] = dq.begin();
        }
        else{
            if(um.find(arr[i]) != um.end()){
                dq.erase(um[arr[i]]);
                um.erase(arr[i]);
            }
        }
        if(dq.empty())
            cout << -1 << " ";
        else
            cout << dq.back() << " ";
    }
}
