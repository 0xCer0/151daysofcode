// gallery with plants is divided into n parts, numbered : 0,1,2,3...n-1. There are provisions for attaching water sprinklers at every partition. A sprinkler with range x at partition i can water all partitions from i-x to i+x.
// Given an array gallery[ ] consisting of n integers, where gallery[i] is the range of sprinkler at partition i (power==-1 indicates no sprinkler attached), return the minimum number of sprinklers that need to be turned on to water the complete gallery.
// If there is no possible way to water the full length using the given sprinklers, print -1.

// Example :
// Input:
// n = 6
// gallery[ ] = {-1, 2, 2, -1, 0, 0}
// Output:
// 2
// Explanation: Sprinklers at index 2 and 5
// can water thefull gallery, span of
// sprinkler at index 2 = [0,4] and span
// â€‹of sprinkler at index 5 = [5,5].

// driver code

#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int min_sprinklers(int gallery[], int n)
    {

        vector<pair<int, int> > V;
 
    for (int i = 0; i < n; i++) {
        if (gallery[i] > -1) {
            V.push_back(
                pair<int, int>(i - gallery[i], i + gallery[i]));
        }
    }
   
    sort(V.begin(), V.end());
 
    int maxRight = 0;
   
    int res = 0;
 
    int i = 0;
 
    while (maxRight < n) {

 
        if (i == V.size() || V[i].first > maxRight) {
            return -1;
        }
    
        int currMax = V[i].second;
 
 
        while (i + 1 < V.size()
               && V[i + 1].first <= maxRight) {
 
       
            i++;
  
            currMax = max(currMax, V[i].second);
        }
 
        if (currMax < maxRight) {
            // Return -1
            return -1;
        }
        // Increment res by 1
        res++;
 
        // Update maxRight
        maxRight = currMax + 1;
 
        // Increment i by 1
        i++;
    }
    // Return res as answer
    return res;
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
        
        int gallery[n];
        for(int i=0; i<n; i++)
            cin>> gallery[i];
        Solution obj;
        cout<< obj.min_sprinklers(gallery,n) << endl;
    }
	return 1;
}
  // } Driver Code Ends