// Given an array A[ ] of positive integers of size N, where each value represents the number of chocolates in a packet. Each packet can have a variable number of chocolates. There are M students, the task is to distribute chocolate packets among M students such that :
// 1. Each student gets exactly one packet.
// 2. The difference between maximum number of chocolates given to a student and minimum number of chocolates given to a student is minimum.

// Example 1:

// Input:
// N = 8, M = 5
// A = {3, 4, 1, 9, 56, 7, 9, 12}
// Output: 6
// Explanation: The minimum difference between 
// maximum chocolates and minimum chocolates 
// is 9 - 3 = 6 by choosing following M packets :
// {3, 4, 9, 7, 9}

#include<bits/stdc++.h>
using namespace std;

int chocoDis(int *arr, int n, int m){
    int res = INT_MAX;

    sort(arr, arr + n);
    for(int i = 0; i + m - 1 < n; i++)
        res = min(res, arr[i + m - 1] - arr[i]);
    return res;
}

int main(){
	int t, n, m;

	cin >> t;
	while(t--){
	    cin >> n;
	    int arr[n];

	    for(int i = 0; i < n; i++)
	        cin >> arr[i];
	    cin >> m;
	    cout << chocoDis(arr, n, m) << endl;
	}
	return 0;
}