// Given an array of 0s and 1s, If any particular index i has value 1 then it is a safe index and if the value is 0 then it is an unsafe index. A man is standing at index -1(source) can only land on a safe index and he has to reach the Nth index (last position). At each jump, the man can only travel a distance equal to any Fibonacci Number. You have to minimize the number of steps, provided man can jump only in forward direction.
// Note: First few Fibonacci numbers are – 0, 1, 1, 2, 3, 5, 8, 13, 21….
// Examples: 
 

// Input: arr[]= {0, 0, 0, 1, 1, 0, 1, 0, 0, 0, 0} 
// Output: 3
// The person will jump from: 
// 1) index -1 to index 4 (a distance of jump = 5) 
// 2) index 4 to index 6 (a distance of jump = 2) 
// 3) index 6 to the destination (a distance of jump = 5)

 
#include<bits/stdc++.h>
using namespace std;

int minJumps(int *arr, int n){
    int fib[30], res = 0;
    int dp[n + 2];

    fib[0] = 0, fib[1] = 1;
    for(int i = 2; i < 30; i++)
        fib[i] = fib[i - 1] + fib[i - 2];
    dp[0] = 0;
    for(int i = 1; i <= n + 1; i++){
        dp[i] = INT_MAX;
        for(int j = 0; j < 30; j++)
            if(arr[i - 1] == 1 || i == n + 1 && i - fib[j] >= 0)
                dp[i] = min(dp[i], 1 + dp[i - fib[j]]);
    }
    return dp[n + 1] == INT_MAX ? -1 : dp[n + 1];
}

int main(){
    int t, n;

    cin >> t;
    while(t--){
        cin >> n;
        int arr[n];

        for(int i = 0; i < n; i++)
            cin >> arr[i];
        cout << minJumps(arr, n) << endl;
    }
    return 0;
}