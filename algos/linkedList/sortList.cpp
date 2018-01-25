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
    ListNode* sortList(ListNode*);
  private:
    ListNode* _merge(ListNode*, ListNode*);
};

ListNode* Solution::sortList(ListNode* head) {
  if (!head || !head->next) return head;
  ListNode *slow, *fast, *head2;
  slow = head;
  fast = head->next;
  while (fast && fast->next) {
    slow = slow->next;
    fast = fast->next->next;
  }
  head2 = slow->next;
  slow->next = NULL;
  return _merge(sortList(head), sortList(head2));
}

ListNode* Solution::_merge(ListNode* head, ListNode* head2) {
  ListNode *ret = new ListNode(0);
  ListNode *t = ret;
  while(head or head2) {
    if (head and (!head2 or (head->val <= head2->val))) {
      t = t->next = head;
      head = head->next;
    }
    if (head2 and (!head or (head2->val <= head->val))) {
      t = t->next = head2;
      head2 = head2->next;
    }
  }
  return ret->next; 
}

/* This below merge funcion has some bug
ListNode* Solution::_merge(ListNode* head, ListNode* head2) {
  ListNode *temp, *prev, *low, *high;
  low = head;
  high = head2;
  while(low and high) {
    if (low->val > high->val) {
      temp = low;
      low = high; 
      high = temp;
    }
    while(high && low && high->val >= low->val) {
      prev = low;
      low = low->next;
    }
    prev->next = high;
    temp = high->next;
    high->next = low;
    high = temp;
  }
  if (high) prev->next->next = high;
  return head->val <= head2->val ? head : head2; 
}
*/

int main(int argc, const char * argv[]) {
  Solution S;
  ListNode *head = new ListNode(1);
  head->next = new ListNode(-2);
  head->next->next = new ListNode(-3);
  head->next->next->next = new ListNode(-4);
  head->next->next->next->next = new ListNode(-5);
  ListNode *sortedList = S.sortList(head);
  cout << "Reversed list is:" << endl;
  while (sortedList) {
    cout << sortedList->val << " ";
    sortedList = sortedList->next;
  }
  cout << endl;
  return 0;
}

