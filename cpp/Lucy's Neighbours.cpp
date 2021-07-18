// Lucy lives in house number X. She has a list of N house numbers in the society. Distance between houses can be determined by studying the difference between house numbers. Help her find out K closest neighbors.
// Note: If two houses are equidistant and Lucy has to pick only one, the house with the smaller house number is given preference.

// Example 1:

// Input:
// N = 5, X = 0, K = 4
// a[] = {-21, 21, 4, -12, 20}, 
// Output:
// -21 -12 4 20
// Explanation:
// The closest neighbour is house
// number 4. Followed by -12 and 20. -21 and 21 
// are both equal distance from X=0. Therefore, 
// Lucy can only pick 1. Based on the given 
// condition she picks -21 as it is the smaller 
// of the two. 



#include <bits/stdc++.h> 
using namespace std; 


//User function Template for C++
#include <utility>
class Solution{
    public:
    vector<int> Kclosest(vector<int>arr, int n, int x, int k) 
    { 
        // Your code goes here 
        sort(arr.begin(),arr.end());
        vector<pair<int,int>> v;
        for(int i=0;i<arr.size();i++)
        {
            v.push_back(make_pair(abs(arr[i]-x),i));
        }
        sort(v.begin(),v.end());
        vector<int>ans;
        for(int i=0;i<k;i++)
        {
            ans.push_back(arr[v[i].second]);
        }
        sort(ans.begin(),ans.end());
        return(ans);
        
    }  
};
