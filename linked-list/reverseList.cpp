
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// https://leetcode.com/problems/reverse-linked-list/?envType=study-plan-v2&envId=leetcode-75
// 206. Reverse Linked List


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

// a recurisve solution

public: 
    ListNode* helper(ListNode* head, ListNode* res) {
        if (head == nullptr)
            return res; 
        ListNode *newRes = head, *newHead = head->next; 
        newRes->next = res; 
        return helper(newHead, newRes);
    };

public: 
    ListNode* reverseList(ListNode* head) {        
        ListNode *res = nullptr; 
        return helper(head, res);
    };
};
