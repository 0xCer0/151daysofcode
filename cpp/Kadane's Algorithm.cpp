// Given an array Arr[] of N integers. Find the contiguous sub-array(containing at least one number) which has the maximum sum and return its sum.

// Example :

// Input:
// N = 5
// Arr[] = {1,2,3,-2,5}
// Output:
// 9
// Explanation:
// Max subarray sum is 9
// of elements (1, 2, 3, -2, 5) which 
// is a contiguous subarray.

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    long long maxSubarraySum(int arr[], int n){
        
        // Your code here
        long long best=arr[0];
        long long sum=arr[0];
        for(int i=1;i<n;i++){
            sum=max((long long)arr[i],sum+arr[i]);
            best=max(best,sum);
        }
        return best;
    }
};

// { Driver Code Starts.

int main()
{
    int t,n;
    
    cin>>t; //input testcases
    while(t--) //while testcases exist
    {
        
        cin>>n; //input size of array
        
        int a[n];
        
        for(int i=0;i<n;i++)
            cin>>a[i]; //inputting elements of array
            
        Solution ob;
        
        cout << ob.maxSubarraySum(a, n) << endl;
    }
}
  // } Driver Code Ends