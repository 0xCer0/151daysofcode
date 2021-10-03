// Given a text txt[0..n-1] and a pattern pat[0..m-1], write a function search(char pat[], char txt[]) that prints all occurrences of pat[] in txt[]. You may assume that n > m.

// Examples:

// Input:  txt[] = "THIS IS A TEST TEXT"
//         pat[] = "TEST"
// Output: Pattern found at index 10

#include<bits/stdc++.h>
using namespace std;

int KMP(string, string);
void getLPS(int[], int, string);

int main(){
    int t;
    string txt, pat;

    cin >> t;
    while(t--){
        cin >> txt >> pat;
        cout << KMP(txt, pat) << endl;
    }
    return 0;
}

int KMP(string txt, string pat){
    int n = txt.length(), m = pat.length();
    int lps[m], count = 0;

    getLPS(lps, m, pat);
    int i = 0, j = 0;
    while(i < n){
        if(txt[i] == pat[j]){
            i++;
            j++;
        }
        if(j == m){
            count++;
            j = lps[j - 1];
        }
        else if(i < n && pat[j] != txt[i]){
            if(j != 0)
                j = lps[j - 1];
            else
                i++;
        }
    }
    return count;
}

void getLPS(int lps[], int n, string str){
    int i = 1, len = 0;
    lps[0] = 0;

    while(i < n){
        if(str[i] == str[len]){
            len++;
            lps[i] = len;
            i++;
        }
        else{
            if(len == 0){
                lps[i] = 0;
                i++;
            }
            else
                len = lps[len - 1];
        }
    }
}