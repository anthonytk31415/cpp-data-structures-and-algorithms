
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// https://leetcode.com/problems/maximum-twin-sum-of-a-linked-list/description/?envType=study-plan-v2&envId=leetcode-75
// 2130. Maximum Twin Sum of a Linked List


class Solution {

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};



public:
    ListNode* reverseList(ListNode* head) {
        ListNode *front = nullptr, *newcur;
        while (head){
            newcur = head->next; 
            head->next = front;             
            front = head;       
            head = newcur;       
        } 
        return front;
    };

// traversing twice
public:
    int pairSum1(ListNode* head) {
        ListNode *node = head, *reverse = head; 
        int numNodes = 0;
        while (node){
            ++numNodes;
            node = node->next; 
        }
        node = head; 
        for (int i = 0; i < numNodes /2 - 1; ++i){
            node = node->next; 
        }
        reverse = reverseList(node->next); 
        node->next = nullptr; 
        node = head; 
        int res = 0; 
        while (node && reverse){
            res = max(res, node->val + reverse->val); 
            node = node->next; 
            reverse = reverse->next; 
        }
        return res; 
    };

// Using Tortoise/Hare

public:
    int pairSum1(ListNode* head) {
        ListNode *slow = head, *fast = head, *node = head, *toReverse, *reverse; 
        int res = 0;
        while (fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next; 
        }
        toReverse = slow->next; 
        slow->next = nullptr; 
        reverse = reverseList(toReverse);
        while (node && reverse){
            res = max(res, node->val + reverse->val); 
            node = node->next; 
            reverse = reverse->next; 
        }    
        return res; 
    }

};
