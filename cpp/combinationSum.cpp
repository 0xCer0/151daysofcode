// Given an array of integers and a sum B, find all unique combinations in the array where the sum is equal to B. The same number may be chosen from the array any number of times to make B.

// Note:
//         1. All numbers will be positive integers.
//         2. Elements in a combination (a1, a2, …, ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
//         3. The combinations themselves must be sorted in ascending order.


// Example 1:

// Input:
// N = 4
// arr[] = {7,2,6,5}
// B = 16
// Output:
// (2 2 2 2 2 2 2 2)
// (2 2 2 2 2 6)
// (2 2 2 5 5)
// (2 2 5 7)
// (2 2 6 6)
// (2 7 7)
// (5 5 6)

#include<bits/stdc++.h>
using namespace std;

bool combinations(int, int, vector<int>&, vector<int>&);

int main(){
    int t, n, k;

    cin >> t;
    while(t--){
        cin >> n;
        vector<int> arr(n), res;

        for(int i = 0; i < n; i++)
            cin >> arr[i];
        cin >> k;
        sort(arr.begin(), arr.end());
        if(!combinations(0, k, arr, res))
            cout << "Empty";
        cout << endl;
    }
    return 0;
}

bool combinations(int i, int k, vector<int> &arr, vector<int> &res){
    if(k == 0){
        cout << "(" << res[0];
        for(int i = 1; i < res.size(); i++)
            cout << " " << res[i];
        cout << ")";
        return true;
    }
    else if(i == arr.size() || k < 0)
        return false;
    else{
        bool flag = false;
        res.push_back(arr[i]);
        flag = combinations(i, k - arr[i], arr, res) || flag;
        res.pop_back();
        while(i + 1 < arr.size() && arr[i] == arr[i + 1])
            i++;
        flag = combinations(i + 1, k, arr, res) || flag;
        return flag;
    }
}