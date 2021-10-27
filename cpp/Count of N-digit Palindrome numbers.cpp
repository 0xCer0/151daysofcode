// Given an integer N, the task is to count the number of N digit palindromic numbers containing digits from 1 to 9 and divisible by 9. 
// Examples: 
 

// Input: N = 1 
// Output: 1 
// Explanation: 
// Only 9 is 1 digit number which is palindrome and divisible by 9.
// Input: N = 3 
// Output: 9 
// Explanation: 
// Three digit numbers those are palindrome and divisible by 9 are – 
// {171, 252, 333, 414, 585, 666, 747, 828, 999} 

#include<bits/stdc++.h>
using namespace std;

int countNPalin(int);
int createPalin(int, int);

int main(){
    int t, n;

    cin >> t;
    while(t--){
        cin >> n;
        cout << countNPalin(n) << endl;
    }
    return 0;
}

int countNPalin(int n){
    int isOdd, s, count = 0, m = n;
    if(n % 2 == 0){
        isOdd = 0;
        n = n / 2;
        s = 1;
        n--;
        while(n--)
            s = s * 10;
    }
    else{
        isOdd = 1;
        n = n / 2;
        s = 1;
        while(n--)
            s = s * 10;
    }
    int e = 9;
    m--;
    while(m--){
        e = e * 10 + 9;
    }
    for(int i = s; i <= e; i++)
        if(createPalin(i, isOdd) <= e)
            count++;
        else
            break;
    return count;
}

int createPalin(int num, int isOdd){
    int palin = num;

    if(isOdd)
        num /= 10;
    while(num){
        palin = palin * 10 + (num % 10);
        num /= 10;
    }
    return palin;
}