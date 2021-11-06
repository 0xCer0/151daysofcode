// Design a system that takes big URLs like “http://www.geeksforgeeks.org/count-sum-of-digits-in-numbers-from-1-to-n/” and converts them into a short URL. It is given that URLs are stored in database and every URL has an associated integer id.  So your program should take an integer id and generate a URL. 

// A URL character can be one of the following

// A lower case alphabet [‘a’ to ‘z’], total 26 characters
// An upper case alphabet [‘A’ to ‘Z’], total 26 characters
// A digit [‘0′ to ‘9’], total 10 characters
// There are total 26 + 26 + 10 = 62 possible characters.

// So the task is to convert an integer (database id) to a base 62 number where digits of 62 base are "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMN
// OPQRSTUVWXYZ0123456789"

// Example 1:

// Input: 
// N = 12345
// Output: 
// dnh
// 12345
// Explanation: "dnh" is the url for id 12345
// Example 2:

// Input: 
// N = 30540
// Output: 
// h6K
// 30540
// Explanation: "h6K" is the url for id 30540

#include<bits/stdc++.h>
#define ll unsigned long long
using namespace std;

void tinyURL(ll);
string id_to_string(ll);
ll string_to_id(string);

int main(){
    ll t, n;

    cin >> t;
    while(t--){
        cin >> n;
        tinyURL(n);
    }
    return 0;
}

void tinyURL(ll n){
    string res1 = id_to_string(n);
    cout << res1 << endl;
    ll res2 = string_to_id(res1);
    cout << res2 << endl;
}

string id_to_string(ll n){
    string str;
    string arr = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";

    while(n){
        str.push_back(arr[n % 62]);
        n /= 62;
    }
    reverse(str.begin(), str.end());
    return str;
}

ll string_to_id(string str){
    ll res = 0;

    for(ll i = 0; i < str.length(); i++){
        if('a' <= str[i] && str[i] <= 'z')
            res = res * 62 + str[i] - 'a';
        else if('A' <= str[i] && str[i] <= 'Z')
            res = res * 62 + str[i] - 'A' + 26;
        else if('0' <= str[i] && str[i] <= '9')
            res = res * 62 + str[i] - '0' + 52;
    }
    return res;
}