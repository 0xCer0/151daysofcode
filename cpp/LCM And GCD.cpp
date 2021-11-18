// Given two numbers A and B. The task is to find out their LCM and GCD.

// Example 1:
// Input:
// A = 5 , B = 10
// Output:
// 10 5
// Explanation:
// LCM of 5 and 10 is 10, while
// thier GCD is 5.

#include<bits/stdc++.h>
#define ll unsigned long long
using namespace std;

void solve(ll, ll);
ll GCD(ll, ll);

int main(){
    ll t, a, b;

    cin >> t;
    while(t--){
        cin >> a >> b;
        solve(a, b);
        cout << endl;
    }
    return 0;
}

ll GCD(ll a, ll b){
    if(b == 0)
        return a;
    return GCD(b, a % b);
}

void solve(ll a, ll b){
    ll gcd = GCD(a, b);
    ll lcm = (a * b) / gcd;
    cout << lcm << " " << gcd;
}