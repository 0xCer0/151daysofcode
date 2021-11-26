// Given an unsigned integer N. The task is to swap all odd bits with even bits. For example, if the given number is 23 (00010111), it should be converted to 43(00101011). Here, every even position bit is swapped with adjacent bit on the right side(even position bits are highlighted in the binary representation of 23), and every odd position bit is swapped with an adjacent on the left side.

// Example :
// Input: N = 23
// Output: 43

#include<bits/stdc++.h>
using namespace std;

int swap(int n){
    int even = stoi("0101010101010101010101010101010", nullptr, 2);
    int odd = stoi("1010101010101010101010101010101", nullptr, 2);

    even = (n & even) >> 1;
    odd = (n & odd) << 1;
    return (even | odd);
}

int main(){
	int t, n;

	cin >> t;
	while(t--){
	    cin >> n;
	    cout << swap(n) << endl;
	}
	return 0;
}