// Given an array of size n such that each element contains either a 'P' for policeman or a 'T' for thief. Find the maximum number of thieves that can be caught by the police. 
// Keep in mind the following conditions :

// Each policeman can catch only one thief.
// A policeman cannot catch a thief who is more than K units away from him.
// Example :

// Input:
// N = 5, K = 1
// arr[] = {P, T, T, P, T}
// Output: 2
// Explanation: Maximum 2 thieves can be 
// caught. First policeman catches first thief 
// and second police man can catch either second 
// or third thief.


#include <bits/stdc++.h>
using namespace std;



class Solution{
    public:
    int catchThieves(char arr[], int n, int k) 
    {
        queue<int> police,thief;
        for(int i=0;i<n;i++){
            if(arr[i] == 'P') police.push(i);
            else thief.push(i);
        }
        int ans = 0;
        while(!police.empty() && !thief.empty()){
            int x = police.front();
            int t = thief.front();
            if(abs(t-x) <= k){
                police.pop();
                thief.pop();
                ans++;
                continue;
            }
            if(t < x){
                thief.pop();
                continue;
            }
            if(t > x){
                police.pop();
                continue;
            }
        }
        return ans;
    }
};

// { Driver Code Starts.

int main() 
{ 
	int t;
	cin>>t;
	while(t--)
	{
		int n, k;
		cin>>n >> k;
		char arr[n];
		for (int i = 0; i < n; ++i)
			cin>>arr[i];
		Solution obj;
		cout<<obj.catchThieves(arr, n, k) << endl;
	}
	return 0; 
} 

  // } Driver Code Ends