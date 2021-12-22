// Find out the maximum sub-array of non negative numbers from an array.

// The sub-array should be contiguous i.e., a sub-array created by choosing the second and fourth element and skipping the third element is invalid.

// Maximum sub-array is defined in terms of the sum of the elements in the sub-array. Sub-array A is greater than sub-array B if sum(A) > sum(B).

// Example:
// A : [1, 2, 5, -7, 2, 3]
// The two sub-arrays are [1, 2, 5] [2, 3].
// The answer is [1, 2, 5] as its sum is larger than [2, 3]

// Example 1:

// Input:
// N = 3
// A[] = {1, 2, 3}
// Output: 1 2 3
// Explanation: In the given array every
// element is non-negative.

#include<bits/stdc++.h>
using namespace std;

void maxSubarray(int);

int main(){
    int t, n;

    cin >> t;
    while(t--){
        cin >> n;
        maxSubarray(n);
        cout << endl;
    }
    return 0;
}

void maxSubarray(int n){
    int arr[n], curr_sum = 0, max = INT_MIN;

    for(int i = 0; i < n; i++)
        cin >> arr[i];
    int i = 0, s, e;
    for(int j = 0; j < n; j++){
        if(arr[j] >= 0){
            curr_sum += arr[j];
        }
        else{
            if(max < curr_sum){
                max = curr_sum;
                s = i;
                e = j - 1;
            }
            else if(max == curr_sum){
                int a = e - s;
                int b = j - i;
                if(a < b){
                    s = i;
                    e = j - 1;
                }
            }
            i = j + 1;
            curr_sum = 0;
        }
    }
    if(max < curr_sum){
        s = i;
        e = n - 1;
    }
    for(int k = s; k <= e; k++)
        cout << arr[k] << " ";
}