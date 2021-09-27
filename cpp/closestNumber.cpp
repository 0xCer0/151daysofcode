// Given an array of sorted integers. We need to find the closest value to the given number. Array may contain duplicate values and negative numbers. 

// Examples:  
// Input : arr[] = {1, 2, 4, 5, 6, 6, 8, 9}
//              Target number = 11
// Output : 9
// 9 is closest to 11 in given array

#include<bits/stdc++.h>
using namespace std;

int closeNum(int, int);

int main(){
	int t, n, m;

	cin >> t;
	while(t--){
	    cin >> n >> m;
	    cout << closeNum(n, m) << endl;
	}
	return 0;
}

int closeNum(int n, int m){
    if(n % m == 0)
        return n;
    int q = n / m;

    int n1 = q * m;
    int n2 = n * m > 0 ? (q + 1) * m : (q - 1) * m;

    if(abs(n - n1) < abs(n2 - n))
        return n1;
    return n2;
}