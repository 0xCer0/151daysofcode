// Given a string s and an integer k, the task is to reduce the string by applying the following operation:
// Choose a group of k consecutive identical characters and remove them.

// The operation can be performed any number of times until it is no longer possible.

// Example :

// Input:
// k = 2
// s = "geeksforgeeks"
// Output:
// gksforgks
// Explanation:
// Modified String after each step: 
// "geeksforgeeks" -> "gksforgks"

#include <iostream>
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    string Reduced_String(int k,string s){
        // Your code goes here
        
        string ans;
        stack<pair<char,int>> st;
        
        for(int i=0;i<s.length();i++){
            if(st.empty()){
                st.push({s[i],1});
            }
            else{
                auto x=st.top();
                st.pop();
                x.second%=k;
                
                if(x.first==s[i]){
                    st.push({x.first,x.second+1});
                }
                else{
                    if(x.second>0)
                        st.push(x);
                    st.push({s[i],1});
                }
                
                x=st.top();
                st.pop();
                x.second%=k;
                if(x.second){
                    st.push(x);
                }
                
            }
        }
        
        while(!st.empty()){
            auto x=st.top();st.pop();
            for(int i=0;i<x.second%k;i++){
                ans+=x.first;
            }
        }
        reverse(ans.begin(),ans.end());
        
        return ans;
    }


};

// { Driver Code Starts.

int main() {
    
    
    int t;cin>>t;
    while(t--)
    {
        int k;
        cin>>k;
        string s;
        cin>>s;
        Solution obj;
        cout<<obj.Reduced_String(k,s)<<"\n";
        
    }
    
	return 0;
}  // } Driver Code Ends