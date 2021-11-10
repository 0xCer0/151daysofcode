// Given a non-negative integer N. The task is to check if N is a power of 2. More formally, check if N can be expressed as 2x for some x.
 
// Example 1:
// Input: N = 1
// Output: true


#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
	ll t, n;

	cin >> t;
	while(t--){
	    cin >> n;

	    if(n > 0 && (ll)576460752303423488 % n == 0)
	        cout << "YES" << endl;
	    else
	        cout << "NO" << endl;
	}
	return 0;
}