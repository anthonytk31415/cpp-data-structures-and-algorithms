#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/description/?envType=study-plan-v2&envId=leetcode-75
// 2095. Delete the Middle Node of a Linked List


class Solution {

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
public:
    ListNode* deleteMiddle(ListNode* head) {
        ListNode dummy = ListNode(); 
        dummy.next = head; 
        ListNode *fast =  &dummy, *slow = &dummy; 
        while (fast->next != nullptr && fast->next->next != nullptr){
            slow = slow->next; 
            fast = fast->next->next; 
        }

        slow->next =slow->next->next;
        return dummy.next; 

    }
};