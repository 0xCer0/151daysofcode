// Given a linked list, delete N nodes after skipping M nodes of a linked list until the last of the linked list.

// Input:
// First line of input contains number of testcases T. For each testcase, first line of input contains number of elements in the linked list and next M and N respectively space separated. The last line contains the elements of the linked list.

// Output:
// Function should not print any output to stdin/console.

// User Task:
// The task is to complete the function linkdelete() which should modify the linked list as required.

// Example:
// Input:
// 2
// 8
// 2 1
// 9 1 3 5 9 4 10 1
// 6
// 6 1
// 1 2 3 4 5 6

// Output: 
// 9 1 5 9 10 1
// 1 2 3 4 5 6

void linkdelete(Node  *head, int m, int n){
    Node *temp1 = nullptr, *temp2 = nullptr;
    int k = m, l = n;

    temp1 = head;
    while(k > 1){
        if(temp1 == nullptr)
            return;
        k--;
        temp1 = temp1->next;
    }
    while(temp1 != nullptr || temp1->next != nullptr){
        l = n;
        temp2 = temp1;
        while(l--){
            temp2 = temp2->next;
            if(temp2 == nullptr){
                temp1->next = nullptr;
                return;
            }
        }
        temp1->next = temp2->next;
        k = m;
        while(k--){
            temp1 = temp1->next;
            if(temp1 == nullptr)
                return;
        }
    }
}
