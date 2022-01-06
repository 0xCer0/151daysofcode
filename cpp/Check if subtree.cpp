// Given two binary trees with head reference as T and S having at most N nodes. The task is to check if S is present as subtree in T.
// A subtree of a tree T1 is a tree T2 consisting of a node in T1 and all of its descendants in T1.

// Example 1:

// Input:
// T:      1          S:   3
//       /   \            /
//      2     3          4
//    /  \    /
//   N    N  4
// Output: 1 
// Explanation: S is present in T

bool isSubTree(Node *T, Node *S) {
    if(S == nullptr && T == nullptr)
        return true;
    if(T == nullptr || S == nullptr)
        return false;
    else{
        bool temp = false;
        if(T->data == S->data)
            temp = isSubTree(T->left, S->left) && isSubTree(T->right, S->right);
        return temp || isSubTree(T->left, S) || isSubTree(T->right, S);
    }
}