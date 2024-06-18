#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// https://leetcode.com/problems/odd-even-linked-list/description/?envType=study-plan-v2&envId=leetcode-75
// 328. Odd Even Linked List



class Solution {

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

public:
    ListNode* oddEvenList(ListNode* head) {
        ListNode oddDummy = ListNode(), evenDummy = ListNode(), *node = head, *odd = &oddDummy, *even = &evenDummy; 
        bool isEven = true; 
        while (node != nullptr){
            if (isEven){
                even->next = node; 
                even = even->next; 
            } else {
                odd->next = node;
                odd = odd->next;   
            }            
            isEven = !isEven; 
            node = node->next; 
        }
        odd->next = nullptr; 
        even->next = oddDummy.next; 
        return head;         
    }
};


