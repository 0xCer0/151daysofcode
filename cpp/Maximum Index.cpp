// Given an array A[] of N positive integers. The task is to find the maximum of j - i subjected to the constraint of A[i] < A[j] and i < j.
 
// Example 1:

// Input:
// N = 2
// A[] = {1, 10}
// Output:
// 1

#include<bits/stdc++.h>
using namespace std;

int maximumIndex(int);

int main(){
	int t, n;

	cin >> t;
	while(t--){
	    cin >> n;
	    cout << maximumIndex(n) << endl;
	}
	return 0;
}

int maximumIndex(int n){
    int arr[n], rmax[n], lmin[n], temp;

    for(int i = 0; i < n; i++)
        cin >> arr[i];
    temp = 0;
    for(int i = n - 1; i >= 0; i--){
        temp = max(temp, arr[i]);
        rmax[i] = temp;
    }
    temp = INT_MAX;
    for(int i = 0; i < n; i++){
        temp = min(temp, arr[i]);
        lmin[i]= temp;
    }
    temp = 0;
    int j = 0, i = 0;
    while(i < n && j < n){
        if(lmin[i] <= rmax[j]){
            temp = max(temp, j - i);
            j++;
        }
        else
            i++;
    }
    return temp;
}