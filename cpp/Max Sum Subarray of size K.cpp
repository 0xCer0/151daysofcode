// Given an array of integers Arr of size N and a number K. Return the maximum sum of a subarray of size K.

// Example 1:

// Input:
// N = 4, K = 2
// Arr = [100, 200, 300, 400]
// Output:
// 700
// Explanation:
// Arr3  + Arr4 =700,
// which is maximum.

#include<bits/stdc++.h>
using namespace std;

int maxSum(int, int);

int main(){
	int t, n, k;

	cin >> t;
	while(t--){
	    cin >> n >> k;
	    cout << maxSum(n, k) << endl;
	}
	return 0;
}

int maxSum(int n, int k){
    int arr[n], sum = 0, res = 0;

    for(int i = 0; i < n; i++)
        cin >> arr[i];
    for(int i = 0; i < k; i++)
        sum += arr[i];
    res = max(res, sum);
    int i = 0, j;
    for(j = k; j < n; j++, i++){
        sum = sum - arr[i] + arr[j];
        res = max(res, sum);
    }
    return res;
}