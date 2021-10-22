// Given below is a binary tree. The task is to print the top view of binary tree. Top view of a binary tree is the set of nodes visible when the tree is viewed from the top. For the given below tree

//        1
//     /     \
//    2       3
//   /  \    /   \
// 4    5  6   7

// Top view will be: 4 2 1 3 7
// Note: Return nodes from leftmost node to rightmost node.

// Example 1:

// Input:
//       1
//    /    \
//   2      3
// Output: 2 1 3

//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
};

Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

Node* buildTree(string str)
{
 
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str; )
        ip.push_back(str);

    Node* root = newNode(stoi(ip[0]));


    queue<Node*> queue;
    queue.push(root);

  
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

      
        Node* currNode = queue.front();
        queue.pop();

      
        string currVal = ip[i];

      
        if (currVal != "N") {

          
            currNode->left = newNode(stoi(currVal));

            queue.push(currNode->left);
        }

        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        if (currVal != "N") {

            currNode->right = newNode(stoi(currVal));

            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


class Solution
{
    public:
   
    vector<int> topView(Node *root)
    {
       vector<int>vect;
        map<int,int>  mp; 
        queue <pair<Node*,int>> q;
        q.push({root,0});
        while(!q.empty())
         {
           Node* curr=q.front().first;
           int level=q.front().second;
           q.pop();
           if(mp.find(level)==mp.end())
           mp[level]=curr->data;
           if(curr->left)
           q.push({curr->left,level-1});
           if(curr->right)
           q.push({curr->right,level+1});
         }
        for(auto it:mp)
        vect.push_back(it.second);
        
        return vect;
         
        
        
    }

};


int main() {
    int tc;
    cin>>tc;
    cin.ignore(256, '\n');
    while (tc--) {
        string treeString;
        getline(cin, treeString);
        Solution ob;
        Node *root = buildTree(treeString);
        vector<int> vec = ob.topView(root);
        for(int x : vec)
            cout<<x<<" ";
        cout<<endl;
    }
    return 0;
} 