// Geek Land has a population of N people and each person's ability to rule the town is measured by a numeric value arr[i]. The two people that can together rule Geek Land must be compatible with each other i.e., the sum of digits of their ability arr[i] must be equal. Their combined ability should be maximum amongst all the possible pairs of people. Find the combined ability of the Ruling Pair.

// Example :

// Input:
// N = 5
// arr[] = {55, 23, 32, 46, 88}
// Output:
// 101
// Explanation:
// All possible pairs that are 
// compatible with each other are- (23, 32) 
// with digit sum 5 and (55, 46) with digit 
// sum 10. Out of these the maximum combined 
// ability pair is (55, 46) i.e. 55 + 46 = 101

//Initial Template for C++

//Initial Template for C++

#include <bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends


//User function Template for C++

//Back-end complete function Template for C++

class Solution{
    
    public:
    int sum(int n)
    {
        int s=0;
        while(n>0)
        {
            s+=n%10;
            n=n/10;
        }
        return s;
    }
    int RulingPair(vector<int> arr, int n) 
    { unordered_map<int,int>mp;
    int ans=0;
    	
    	for(auto a:arr)
    	{
    	    int s=sum(a);
    	    if(!mp.count(s))
    	    mp[s]=a;
    	    else
    	    {
    	        ans=max(ans,mp[s]+a);
    	        mp[s]=max(mp[s],a);
    	    }
    	}
    	return ans?ans:-1;
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
		vector<int> arr(n);
		for (int i = 0; i < n; ++i)
			cin>>arr[i];
	    Solution obj;
		cout << obj.RulingPair(arr,n)<<"\n";
	}
	return 0; 
} 

  // } Driver Code Ends