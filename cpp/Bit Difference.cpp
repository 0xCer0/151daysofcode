// Given an integer array of size  N . You have to find sum of bit differences in all pairs that can be formed from array elements. Bit difference of a pair (x, y) is count of different bits at same positions in binary representations of x and y.
// For example, bit difference for 2 and 7 is 2. Binary representation of 2 is 010 and 7 is 111 ( first and last bits differ in two numbers).

// Example :

// Input: N = 2, arr[] = {1, 2}
// Output: 4
// Explanation: All possible pairs are [(1,1) (1,2) 
// (2,1) (2,2)] their respective Bit differences 
// are 0 ,  2 , 2 , 0

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


//User function Template for C++

class Solution{
    public:
    long long sumBitDiff(int arr[], int n) 
    { 
        // Your code goes here
        int sum=0;
        for(int i=0; i<32;i++)
        {
            int res=0;
            for(int j=0; j<n; j++)
                if((arr[j]&(1<<i))==0)
                   res++;
                 sum+=(res*(n-res)*2);
        }
        return sum;
    } 
};

// { Driver Code Starts.
  
int main()
{
	int t;
    cin>>t;
    while(t--)
    {
    	int n;
    	cin>>n;
    	int arr[n];
    	for(int i = 0; i < n; i++)
    		cin >> arr[i];
    	Solution obj;
		cout << obj.sumBitDiff(arr, n) << "\n";
    }
	return 0; 
}
  // } Driver Code Ends