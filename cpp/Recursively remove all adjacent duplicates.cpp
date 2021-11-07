// Given a string s, remove all its adjacent duplicate characters recursively. 

// Example 1:

// Input:
// S = "geeksforgeek"
// Output: "gksforgk"
// Explanation: 
// g(ee)ksforg(ee)k -> gksforgkâ€‹

#include<bits/stdc++.h>
using namespace std;

string removeAdjDup(string);
void _removeAdjDup(string, string&);

int main(){
	int t;
	string str;

	cin >> t;
	while(t--){
	    cin >> str;
	    cout << removeAdjDup(str) << endl;
	}
	return 0;
}

string removeAdjDup(string str){
    string res;
    _removeAdjDup(str, res);
    return res;
}

void _removeAdjDup(string str, string &res){
    bool flag = false;

    for(int i = 0; str[i] != '\0'; i++){
        int j = i;
        while(str[j + 1] != '\0' && str[j] == str[j + 1]){
            j++;
            flag = true;
        }
        if(j != i){
            str.erase(i, j - i + 1);
            i--;
        }
    }
    if(flag == false)
        res = str;
    else
        _removeAdjDup(str, res);
}