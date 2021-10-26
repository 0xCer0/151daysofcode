// Given an array of integers and a number K. Find the count of distinct elements in every window of size K in the array.

// Example 1:

// Input:
// N = 7, K = 4
// A[] = {1,2,1,3,4,2,3}
// Output: 3 4 4 3
// Explanation: Window 1 of size k = 4 is
// 1 2 1 3. Number of distinct elements in
// this window are 3. 
// Window 2 of size k = 4 is 2 1 3 4. Number
// of distinct elements in this window are 4.
// Window 3 of size k = 4 is 1 3 4 2. Number
// of distinct elements in this window are 4.
// Window 4 of size k = 4 is 3 4 2 3. Number
// of distinct elements in this window are 3.


#include<bits/stdc++.h>
using namespace std;

void winDist(int, int);

int main(){
    int t, n, k;

    cin >> t;
    while(t--){
        cin >> n >> k;
        winDist(n, k);
        cout << endl;
    }
    return 0;
}

void winDist(int n, int k){
    int arr[n], count = 0;
    unordered_map<int, int> um;

    for(int i = 0; i < n; i++)
        cin >> arr[i];
    for(int i = 0; i < k; i++){
        um[arr[i]]++;
        if(um[arr[i]] == 1)
            count++;
    }
    cout << count << " ";
    for(int i = k; i < n; i++){
        um[arr[i - k]]--;
        if(um[arr[i - k]] == 0)
            count--, um.erase(um[arr[i - k]]);
        um[arr[i]]++;
        if(um[arr[i]] == 1)
            count++;
        cout << count << " ";
    }
}