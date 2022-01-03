// Given a 2D matrix M of dimensions RxC. Find the maximum sum subarray in it.

// Example 1:

// Input:
// R=4
// C=5
// M=[[1,2,-1,-4,-20],
// [-8,-3,4,2,1],
// [3,8,10,1,3],
// [-4,-1,1,7,-6]]
// Output:
// 29

#include<bits/stdc++.h>
using namespace std;

int maxSum(int, int);
int kadanes(int[], int);

int main(){
    int t, n, m;

    cin >> t;
    while(t--){
        cin >> n >> m;
        cout << maxSum(n, m) << endl;
    }
    return 0;
}

int maxSum(int n, int m){
    int mat[n][m], res = INT_MIN;

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> mat[i][j];
    for(int l = 0; l < m; l++){
        int arr[n] = {0};
        for(int r = l; r < m; r++){
            for(int i = 0; i < n; i++)
                arr[i] += mat[i][r];
            res = max(res, kadanes(arr, n));
        }
    }
    return res;
}

int kadanes(int arr[], int n){
    int res = INT_MIN, curr = 0;

    for(int i = 0; i < n; i++){
        curr += arr[i];
        res = max(res, curr);
        if(curr < 0)
            curr = 0;
    }
    return res;
}