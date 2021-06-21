// Geek wants to send an encrypted message in the form of string S to his friend Keeg along with instructions on how to decipher the message. To decipher the message, his friend needs to iterate over the message string from left to right, if he finds a '*', he must remove it and add all the letters read so far to the string. He must keep on doing this till he gets rid of all the '*'.
// Can you help Geek encrypt his message string S? 

// Note: If the string can be encrypted in multiple ways, find the smallest encrypted string. 

// Example 1:

// Input: S = "ababcababcd"
// Output: ab*c*d
// Explanation: We can encrypt the string 
// in following way : "ababcababcd" -> 
// "ababc*d" -> "ab*c*d"

//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


//User function Template for C++

// return a string formed by compressing string s
// do not print anything

class Solution{
    public:
    string compress(string s)
    {
    int n=s.size();
    vector<int> v(n);
    for(int i=1;i<n;i++){
        int j=v[i-1];
        while(j>0 && s[i]!=s[j]){
            j=v[j-1];
        }
        if(s[i]==s[j]) j++;
        v[i]=j;
    }
    string ans;
    for(int i=n-1;i>=0;i--){
        if(i%2){
            if(v[i]>=(i+1)/2 && (i+1)%(2*(i+1-v[i]))==0){
                ans.push_back('*');
                i/=2; i++;
            }else{
                ans.push_back(s[i]);
            }
        }else{
            ans.push_back(s[i]);
        }
    }
    reverse(ans.begin(),ans.end());
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
        string s;
        cin>>s;
        Solution obj;
        cout<< obj.compress(s) << "\n";
    }
    return 0;
}
  // } Driver Code Ends