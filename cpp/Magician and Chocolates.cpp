// Given N bags, each bag contains Bi chocolates. There is a kid and a magician. In one unit of time, kid chooses a random bag i, eats Bi chocolates, then the magician fills the ith bag with floor(Bi/2) chocolates.

// Find the maximum number of chocolates that kid can eat in A units of time.

// Example Input
// Input 1:

//  A = 3
//  B = [6, 5]
// Input 2:

//  A = 5
//  b = [2, 4, 6, 8, 10]


// Example Output
// Output 1:
//  14
// Output 2:
//  33

#include<bits/stdc++.h>
#define ll unsigned long long
#define MAX 1000000007
using namespace std;

int Solution::nchoc(int A, vector<int> &B){
    priority_queue<ll> pq;
    ll res = 0;

    for(ll i = 0; i < B.size(); i++)
        pq.push(B[i]);
    while(A--){
        ll temp = pq.top();
        res = (res + temp) % MAX ;
        pq.pop();
        pq.push(temp / 2);
    }
    return res;
}