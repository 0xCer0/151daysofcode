// Given an array containing 0s and 1s. Find the number of subarrays having equal number of 0s and 1s.

// Example 1:

// Input:
// n = 7
// A[] = {1,0,0,1,0,1,1}
// Output: 8

#include<bits/stdc++.h>
using namespace std;

int array01(int);

int main(){
    int t, n;

    cin >> t;
    while(t--){
        cin >> n;
        cout << array01(n) << endl;
    }
	return 0;
}

int array01(int n){
    int arr[n], curr = 0, result = 0;
    unordered_map<int, vector<int>> um;

    for(int i = 0; i < n; i++){
        cin >> arr[i];
        if(arr[i] == 0)
            arr[i] = -1;
    }
    for(int i = 0; i < n; i++){
        curr += arr[i];
        if(curr == 0)
            result++;
        if(um.find(curr) != um.end())
            result += um[curr].size();
        um[curr].push_back(i);
    }
    return result;
}