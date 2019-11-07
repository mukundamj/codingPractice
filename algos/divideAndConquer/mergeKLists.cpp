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
    ListNode* mergeKLists(vector<ListNode*>&);
  private:
    ListNode* _merge(ListNode*, ListNode*);
};

// High time complexity: n x m. Where n = number of lists and m = average number of elements in each list
//ListNode* Solution::mergeKLists(vector<ListNode*>& lists) {
//  if (!lists.size()) return NULL;
//  vector<ListNode*>::iterator it = lists.begin();
//  ListNode *head1 = *it;
//  ListNode *head2 = NULL;
//  while (++it != lists.end()) {
//    head2 = *it; 
//    head1 = _merge(head1, head2);
//  }
//  return head1;
//}

//Low time complexity: mlog(n). Where n = number of lists and m = total number of elements covering all lists
ListNode* Solution::mergeKLists(vector<ListNode*>& lists) {
  if (lists.size() == 0) return NULL;
  while (lists.size() != 1) {
    lists.push_back(_merge(lists[0], lists[1]));
    lists.erase(lists.begin());
    lists.erase(lists.begin());
  }
  return *lists.begin();
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

int main(int argc, const char * argv[]) {
  Solution S;
  ListNode *head1 = new ListNode(1);
  head1->next = new ListNode(4);
  head1->next->next = new ListNode(7);
  head1->next->next->next = new ListNode(10);
  head1->next->next->next->next = new ListNode(13);
  ListNode *head2 = new ListNode(2);
  head2->next = new ListNode(5);
  head2->next->next = new ListNode(8);
  head2->next->next->next = new ListNode(11);
  head2->next->next->next->next = new ListNode(14);
  ListNode *head3 = new ListNode(3);
  head3->next = new ListNode(6);
  head3->next->next = new ListNode(8);
  head3->next->next->next = new ListNode(12);
  head3->next->next->next->next = new ListNode(15);
  head3->next->next->next->next->next = new ListNode(19);
  vector<ListNode*> lists;  
  lists.push_back(head1);
  lists.push_back(head2);
  lists.push_back(head3);
  ListNode *mergedList = S.mergeKLists(lists);
  while (mergedList) {
    printf("%d ", mergedList->val);
    mergedList = mergedList->next;
  }
  cout << endl;
  return 0;
}

