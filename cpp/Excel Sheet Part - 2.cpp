// Given a string S that represents column title of an Excel sheet, find the number that represents that column.
// In excel A column is number 1, AA is 27 and so on.

// Example 1:

// Input:
// S = A
// Output: 1

#include<bits/stdc++.h>
using namespace std;

int excel(string);

int main(){
	int t;
	string str;

	cin >> t;
	while(t--){
	    cin >> str;
	    cout << excel(str) << endl;
	}
	return 0;
}

int excel(string str){
    int res = 0, temp = 1;

    for(int i = str.length() - 1, j = 0; i >= 0; i--, j++){
        res = res + temp * (str[i] - 'A' + 1);
        temp = temp * 26;
    }
    return res;
}