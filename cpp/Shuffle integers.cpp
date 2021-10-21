// Given an array arr[] of n elements in the following format {a1, a2, a3, a4, ….., an/2, b1, b2, b3, b4, …., bn/2}, the task is shuffle the array to {a1, b1, a2, b2, a3, b3, ……, an/2, bn/2} without using extra space.

// Example 1:

// Input: n = 4, arr[] = {1, 2, 9, 15}
// Output:  1 9 2 15
// Explanation: a1=1 , a2=2 , b1=9 , b2=9
// So the final array will be :  
// a1, b1, a2, b2 = { 1, 9, 2, 15 }

#include<bits/stdc++.h>
using namespace std;

void shuffle(int);
void _shuffle(int[], int, int);

int main(){
    int t, n;

    cin >> t;
    while(t--){
        cin >> n;
        shuffle(n);
        cout << endl;
    }
    return 0;
}

void shuffle(int n){
    int arr[n], m;

    for(int i = 0; i < n; i++)
        cin >> arr[i];
    _shuffle(arr, 0, n - 1);
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
}

void _shuffle(int arr[], int s, int e){
    int m, mf, ss;

    if(s > e)
        return;
    if(s + 1 == e)
        return;
    m = (s + e) / 2;
    mf = (s + m) / 2;
    ss = m + 1;
    for(int i = mf + 1; i <= m; i++)
        swap(arr[i], arr[ss++]);
    for(int i = s; i <= e; i++)
        cout << arr[i] << " ";
    cout << endl;
    _shuffle(arr, s, m);
    _shuffle(arr, m + 1, e);
}