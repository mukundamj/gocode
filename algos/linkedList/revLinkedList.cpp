#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
  public:
    ListNode* reverseList(ListNode*);
};

//Iterative approach
ListNode* Solution::reverseList(ListNode* head) {
  ListNode *next, *prev = NULL; 
  while (head != NULL) {
    next = head->next;
    head->next = prev;
    prev = head;
    head = next;
  }
  return prev;
}

//Recursive approach borrowed from LeetCode solution
/*
ListNode* Solution::reverseList(ListNode* head) {
  if (!head || !(head->next)) return head;
  ListNode *node = reverseList(head->next); 
  head->next->next = head;
  head->next = NULL;
  return node;
}
*/

int main(int argc, const char * argv[]) {
  Solution S;
  ListNode *head = new ListNode(0);
  ListNode *h1, *h2;
  h1 = h2 = head;
  for (int i = 1; i < 10 ; i++) {
    head->next = new ListNode(i);
    head = head->next;
  }
  cout << "Input list is:" << endl;
  while (h1 != NULL) {
    cout << h1->val << " ";
    h1 = h1->next;
  }
  cout << endl;
  ListNode *reversedList = S.reverseList(h2);
  cout << "Reversed list is:" << endl;
  while (reversedList != NULL) {
    cout << reversedList->val << " ";
    reversedList = reversedList->next;
  }
  cout << endl;
  return 0;
}

