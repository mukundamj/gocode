#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
  public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) { 
      ListNode head(0), *h = &head; 
      int carry = 0;
      while (l1 || l2 || carry) {
        int sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + carry;
        h->next = new ListNode(sum % 10);
        carry = sum / 10;
        h = h->next;
        l1 = l1 ? l1->next : l1;
        l2 = l2 ? l2->next : l2;
      }
      return head.next;
    }
};

int main(int argc, const char * argv[]) {
  Solution S;
  ListNode head1(0), *l1 = &head1;
  l1->next = new ListNode(8);
  l1 = l1->next;
  l1->next = new ListNode(9);
  l1 = l1->next;
  l1->next = new ListNode(5);
  ListNode head2(0), *l2 = &head2;
  l2->next = new ListNode(2);
  l2 = l2->next;
  l2->next = new ListNode(5);
  l2 = l2->next;
  l2->next = new ListNode(6);
  ListNode *sum = S.addTwoNumbers(head1.next, head2.next);
  cout << "Sum = ";
  while (sum) {
    cout << sum->val;
    sum = sum->next;
  }
  cout << endl;
  return 0;
}

