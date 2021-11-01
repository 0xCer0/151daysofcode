// Given two function, one is h(x) which is the product of all the number in an array A[ ] having size N and another
// function f(x) which denotes the GCD of all the numbers in an array. Your task is to find the value of  h(x)f(x).
// Note: Since the answer can be very large, use modulo 109+7.

// Example 1:

// Input:
// N = 2, A[] = {2, 4}
// Output:
// 64
// Explanation:
// h(x) = 8, f(x) = 2, Therefore, the
// answer is 82 = 64.

#include<bits/stdc++.h>
using namespace std;

int GCD(int);
int _gcd(int, int);

int main(){
    int t, n;

    cin >> t;
    while(t--){
        cin >> n;
        cout << GCD(n) << endl;
    }
    return 0;
}

int _gcd(int a, int b){
    if(b == 0)
        return a;
    return _gcd(b, a % b);
}

int GCD(int n){
    int arr[n];
    int res;

    for(int i = 0; i < n; i++)
        cin >> arr[i];
    res = arr[0];
    for(int i = 1; i < n; i++)
        res = _gcd(res, arr[i]);
    return res;
}