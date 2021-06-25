// Given a sorted linked list of distinct nodes (no two nodes have the same data) and an integer X. Count distinct triplets in the list that sum up to given integer X.

// Example :

// Input: LinkedList: 1->2->4->5->6->8->9, X = 17
// Output: 2
// Explanation: Distinct triplets are (2, 6, 9) 
// and (4, 5, 8) which have sum equal to X i.e 17

#include<bits/stdc++.h>
using namespace std;
 
/* Link list node */
struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};

void push(struct Node** head_ref, int new_data)
{
   
    struct Node* new_node = new Node(new_data);
    
    new_node->next = (*head_ref);
    (*head_ref)    = new_node;
} 

int countTriplets(struct Node* head, int x) ;

/* Driver program to test count function*/
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n , x ,i , num;
        struct Node *head = NULL;
        cin>>n>>x;
        for(i=0;i<n;i++)
        {
            cin>>num;
            push(&head,num);
        }
 
    /* Check the count function */
    cout <<countTriplets(head, x)<< endl;
    }
    return 0;
}// } Driver Code Ends


//User function Template for C++

int countTriplets(struct Node* head, int x) 
{ 
    map<int, Node*> mp;
    Node* curr = head;
    while(curr != NULL){
        mp[curr->data] = curr;
        curr = curr->next;
    }
    
    int ans = 0;
    for(Node* i = head; i != NULL; i = i->next){
        for(Node* j = i->next; j != NULL; j = j->next){
            int y = i->data + j->data;
            if(mp.count(x-y) and mp[x-y] != i and mp[x-y] != j)
                ans++;
        }
    }
    
    return ans/3;
} 