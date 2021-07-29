Given a BST (Binary Search Tree), find the shortest range [x, y], such that, at least one node of every level of the BST lies in the range.
If there are multiple ranges with the same gap (i.e. (y-x)) return the range with the smallest x.

Example 1:

Input:
              8
          /   \
         3     10
       /  \      \
      2    6      14
          / \     /
         4   7   12
                /  \
               11   13
Output: 6 11
Explanation: Level order traversal of the tree 
is [8], [3, 10], [2, 6, 14], [4, 7, 12], [11, 13]. 
The shortest range which satisfies the above 
mentioned condition is [6, 11]. 

// Initial Template for C++

#include <bits/stdc++.h>

using namespace std;

// Tree Node
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function to Build Tree
Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size()) break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}



 // } Driver Code Ends


// User function Template for C++

class Solution{
    void inOrder(Node* root,int depth,vector<int>& level,vector<int>& in){
        if(!root) return;
        
        inOrder(root->left, depth+1, level, in);
        
        in.push_back(root->data);
        level.push_back(depth);
        
        inOrder(root->right, depth+1,level, in);
    }
    
    public:
    pair<int, int> shortestRange(Node *root) {
        vector<int> level, in;
        inOrder(root,0,level,in);
        
        int max_depth = *max_element(level.begin(),level.end()) + 1;
        
        int i = 0,j = find(in.begin(), in.end(), root->data) - in.begin();
        int mid = j;
        
        unordered_map<int,int> m; //{node value, level at which present} pairs
        
        for(int k=0;k<=j;k++) m[level[k]]++;
        
        int l = 0,r = INT_MAX; //lower and upper bounds/limits of range
        
        //for(auto p:m) cout<<p.first<<" "<<p.second<<endl;
        
        if(m.size()==max_depth)
        l = in[0], r = in[j];
        
        while(i<=mid && j<in.size()){
            // if(m.size()==max_depth && (in[j]-in[i])<(r-l)){ 
            //     //cout<<in[i]<<" "<<in[j]<<endl;
            //     l = in[i], r = in[j];
            // }
                
            while(i<=mid && m.size()==max_depth){
                if((in[j]-in[i])<(r-l)) 
                l = in[i], r = in[j];
                
                m[level[i]]--;
                if(m[level[i]]==0) m.erase(level[i]);
                i++;
            }
            
            while(m.size()<max_depth && j<in.size()){
                j++;
                if(j==in.size()) break;
                m[level[j]]++;
            }
            //cout<<j<<endl;
        }
        // if(m.size()==max_depth && (in[j]-in[i])<(r-l)){ 
        //     //cout<<in[i]<<" "<<in[j]<<endl;
        //     l = in[i], r = in[j];
        // }
        
        return {l,r};
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    scanf("%d ", &tc);
    while (tc--) {
        string treeString;
        getline(cin, treeString);
        Node *root = buildTree(treeString);
        Solution obj;
        pair<int, int> range = obj.shortestRange(root);
        cout << range.first << " " << range.second << "\n";
    }

    return 0;
}  // } Driver Code Ends