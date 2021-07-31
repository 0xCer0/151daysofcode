// In Doraland, people have unique Identity Numbers called D-id. Doraemon owns the most popular gadget shop in Doraland. Since his gadgets are in high demand and he has only K gadgets left he has decided to sell his gadgets to his most frequent customers only. N customers visit his shop and D-id of each customer is given in an array array[ ]. In case two or more people have visited his shop the same number of time he gives priority to the customer with higher D-id. Find the D-ids of people he sells his K gadgets to.

// Example :

// Input:
// N = 6
// array[] = {1, 1, 1, 2, 2, 3}
// K = 2
// Output: 
// 1 2
// Explanation: 
// Customers with D-id 1 and 2 are most 
// frequent.
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


class Solution{
    public:
    vector<int> TopK(vector<int>& array, int k)
    {
        map<int ,int >mp;
        
        for (int i=0;i<array.size();i++)
        {
            mp[array[i]]++;
        }
        
        vector<pair<int ,int >>v;
        
        for ( auto i:mp)
        {
            v.push_back({i.second,i.first});
        }
        
        sort(v.begin(),v.end(),greater<pair<int ,int>>());
        
        vector<int >ans;
        
        for (auto i : v)
        {
            if (k>0)
            {
                ans.push_back(i.second);
                k--;
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
        int n,k ;
        cin>>n;
        
        vector<int>array(n);
        
        for(int i=0; i<n; i++)
            cin>>array[i];
            
        cin>>k;
        
        Solution obj;
        vector<int> result = obj.TopK(array,k);
        
        for(int i=0; i<result.size();i++)
            cout<<result[i]<<" ";

        cout<<"\n";

    }
    return 0;
}  // } Driver Code Ends