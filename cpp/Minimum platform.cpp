// Given arrival and departure times of all trains that reach a railway station. Find the minimum 
// number of platforms required for the railway station so that no train is kept waiting.Consider 
// that all the trains arrive on the same day and leave on the same day. Arrival and departure 
// time can never be the same for a train but we can have arrival time of one train equal 
// to departure time of the other. At any given instance of time, same platform can not 
// be used for both departure of a train and arrival of another train. In such cases, we 
// need different platforms.

// Example 1:
// Input: n = 6 
// arr[] = {0900, 0940, 0950, 1100, 1500, 1800}
// dep[] = {0910, 1200, 1120, 1130, 1900, 2000}
// Output: 3

#include<bits/stdc++.h>
using namespace std;

int minimumPlatform(int);

int main(){
	int t, n;

	cin >> t;
	while(t--){
	    cin >> n;
	    cout << minimumPlatform(n) << endl;
	}
	return 0;
}

int minimumPlatform(int n){
    int arr[n], dep[n];
    int dp[2400], res = 0;

    memset(dp, 0, sizeof(dp));
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    for(int i = 0; i < n; i++)
        cin >> dep[i];
    for(int i = 0; i < n; i++){
        for(int j = arr[i]; j <= dep[i]; j++){
            dp[j]++;
            if(dp[j] > res)
                res = dp[j];
        }
    }
    return res;
}
