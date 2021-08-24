// Penelope and her classmates are lost in the Forbidden Forest and the Devil is out to get them. But Penelope has magical powers that can build bridges across the dangerous river and take her friends to safety. The only bridges that can withstand the Devil's wrath are the ones built between two similar trees in the forest. 
// Given str1 and str2 denoting the order of trees on either side of the river, find the maximum number of bridges that Penelope can build and save everyone from the Devil. 
// Note: Each tree in the forest belongs to one of the 3 categories represented by * or # or @

// Example 1:

// Input:
// str1 = "*@#*" 
// str2 = "*#"
// Output:
// 2
// Explanation:
// str1 = "*@#*" and str2 = "*#" 
// Two bridges can be built between the banks 
// of the river in the following manner. 
// * @ # *
// |      |
// *     #

#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    int build_bridges_util(int i , int j , string str1 , string str2 , int n , int m , int dp[105][105])
    {
        if (n <= i or m <= j)
            return 0;
        
        int ans = dp[i][j];
        if (ans != -1)
            return ans;
        
        ans = 0;
        if (str1[i]==str2[j])
            ans = 1 + build_bridges_util(i+1, j+1, str1, str2,n, m, dp);
        
        ans = max(ans, build_bridges_util(i+1, j, str1, str2, n, m, dp));
        ans = max(ans, build_bridges_util(i, j+1, str1, str2, n, m, dp));
        
        return dp[i][j] = ans;
    }
    
    int build_bridges(string str1, string str2)
    {
        int dp[105][105];
        memset(dp, -1, sizeof dp);
        int n = str1.size();
        int m = str2.size();
        return build_bridges_util(0,0,str1,str2,n,m,dp);
    }
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        string str1,str2;
        cin >> str1 >> str2;
        Solution obj;
        cout<<obj.build_bridges(str1,str2)<<endl;
    }
    return 0;
}