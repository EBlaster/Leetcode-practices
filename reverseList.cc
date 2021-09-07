#include "headers.h"

struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
 public:
  ListNode* reverseList(ListNode* head) {
    if (!head || !head->next) {
      return head;
    }

    ListNode* ptr = head->next;
    ListNode* listTail = head;
    ListNode* listHead = head;
    while (listTail->next) {
      listTail->next = listTail->next->next;
      ptr->next = listHead;
      listHead = ptr;
      ptr = listTail->next;
    }

    return listHead;
  }
};