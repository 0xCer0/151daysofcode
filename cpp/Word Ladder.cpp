// Given two distinct words startWord and targetWord, and a list denoting wordList of unique words of equal lengths. Find the length of the shortest transformation sequence from startWord to targetWord.
// Keep the following conditions in mind:

// A word can only consist of lowercase characters.
// Only one letter can be changed in each transformation.
// Each transformed word must exist in the wordList including the targetWord.
// startWord may or may not be part of the wordList.
// The second part of this problem can be found here.


// Example 1:

// Input:
// wordList = {"des","der","dfr","dgt","dfs"}
// startWord = "der", targetWord= "dfs",
// Output:
// 3

#include<bits/stdc++.h>
using namespace std;

int wordLadder(int);

int main(){
    int t, n;

    cin >> t;
    while(t--){
        cin >> n;
        cout << wordLadder(n) << endl;
    }
    return 0;
}

int wordLadder(int n){
    unordered_set<string> us;
    string start, target;
    queue<string> q;
    int level = 0;

    for(int i = 0; i < n; i++){
        string temp;
        cin >> temp;
        us.insert(temp);
    }
    cin >> start >> target;
    if(us.find(target) == us.end())
        return -1;
    q.push(start);
    while(!q.empty()){
        level++;
        int size = q.size();
        while(size--){
            string word = q.front();
            q.pop();


            for(int i = 0; i < word.length(); i++){
                char original_char = word[i];

                for(int j = 'a'; j <= 'z'; j++){
                    word[i] = j;
                    if(us.find(word) == us.end())
                        continue;
                    if(word == target)
                        return level;
                    q.push(word);
                    us.erase(word);
                }
                word[i] = original_char;
            }
        }
    }
    return -1;
}