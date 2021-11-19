// Given an array arr[ ] of size N having distinct elements, the task is to find the next greater element for each element of the array in order of their appearance in the array.
// Next greater element of an element in the array is the nearest element on the right which is greater than the current element.
// If there does not exist next greater of current element, then next greater element for current element is -1. For example, next greater of the last element is always -1.

// Example 1:

// Input: 
// N = 4, arr[] = [1 3 2 4]
// Output:
// 3 4 4 -1

#include<bits/stdc++.h>
#define ll long long
using namespace std;

void nextLarger(ll);

int main(){
	ll t, n;

	cin >> t;
	while(t--){
	    cin >> n;
	    nextLarger(n);
	    cout << endl;
	}
	return 0;
}

void nextLarger(ll n){
    ll arr[n], res[n];
    stack<ll> s;

    for(ll i = 0; i < n; i++)
        cin >> arr[i];
    ll i = 0;
    while(i < n){
        if(s.empty() || arr[i] < arr[s.top()])
            s.push(i++);
        else{
            ll temp = s.top();
            s.pop();
            res[temp] = arr[i];
        }
    }
    while(!s.empty()){
        ll temp = s.top();
        s.pop();
        res[temp] = -1;
    }
    for(ll i = 0; i < n; i++)
        cout << res[i] << " ";
}