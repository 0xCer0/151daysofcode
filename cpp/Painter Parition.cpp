// Dilpreet wants to paint his dog's home that has n boards with different lengths. The length of ith board is given by arr[i] where arr[] is an array of n integers. He hired k painters for this work and each painter takes 1 unit time to paint 1 unit of the board. 

// The problem is to find the minimum time to get this job done if all painters start together with the constraint that any painter will only paint continuous boards, say boards numbered {2,3,4} or only board {1} or nothing but not boards {2,4,5}.

// Example 1:

// Input:
// n = 5
// k = 3
// arr[] = {5,10,30,20,15}
// Output: 35

#include<bits/stdc++.h>
using namespace std;

int minTime(int, int);
int numPainters(int[], int, int);

int main(){
	int t, k, n;

	cin >> t;
	while(t--){
	    cin >> k >> n;
	    cout << minTime(n, k) << endl;
	}
	return 0;
}

int minTime(int n, int k){
    int arr[n], l = 0, r = 0, res;

    for(int i = 0; i < n; i++){
        cin >> arr[i];
        r += arr[i];
        l = max(l, arr[i]);
    }
    while(l <= r){
        int mid = l + (r - l) / 2;
        int paintersRequired = numPainters(arr, n, mid);

        if(paintersRequired <= k){
            r = mid - 1;
            res = mid;
        }
        else
            l = mid + 1;
    }
    return res;
}

int numPainters(int arr[], int n, int t){
    int total = 0, res = 1;

    for(int i = 0; i < n; i++){
        total += arr[i];
        if(total > t){
            total = arr[i];
            res++;
        }
    }
    return res;
}