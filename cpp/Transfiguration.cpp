// Professor McGonagall teaches transfiguration at Hogwarts. She has given Harry the task of changing himself into a cat. She explains that the trick is to analyze your own DNA and change it into the DNA of a cat. The transfigure spell can be used to pick any one character from the DNA string, remove it and insert it in the beginning. 
// Help Harry calculates minimum number of times he needs to use the spell to change himself into a cat.

// Example :

// Input: 
// A = "GEEKSFORGEEKS" 
// B = "FORGEEKSGEEKS"
// Output: 3
// Explanation:The conversion can take place 
// in 3 operations:
// 1. Pick 'R' and place it at the front, 
//    A="RGEEKSFOGEEKS"
// 2. Pick 'O' and place it at the front, 
//    A="ORGEEKSFGEEKS"
// 3. Pick 'F' and place it at the front, 
//    A="FORGEEKSGEEKS"

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution{
    
    public:
    int transfigure (string a, string b)
    {
        
        int n=a.size();
        unordered_map<char,int>mp;
        for(int i=0;i<n;i++)
        {
            mp[a[i]]++;
            mp[b[i]]--;
        }
        
        for(auto x:mp)
        {
            if(x.second!=0)
            {
                return -1;
            }
        }
        
        int i=n-1;
        int j=n-1;
        int count=0;
        
        while(i>=0 and j>=0)
        {
            if(a[i]==b[j])
            {
                i--;
                j--;
            }
            else
            {
                count++;
                i--;
            }
        }
        return count;
    	
    }
};

// { Driver Code Starts.


int main () 
{
    int t; cin >> t;
    while (t--)
    {
        string A, B; 
        cin >> A >> B;
        Solution obj;
        cout << obj.transfigure (A, B) << endl;
    }
}  // } Driver Code Ends
