#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL){}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *p1 = head, *p2 = head;
        for (int i = 0; i < n; ++i) p2 = p2->next;
        while (p2 != NULL && p2->next != NULL){
            p2 = p2->next;
            p1 = p1->next;
        }
        if (p2 == NULL) head = head->next;
        else if (p1->next != NULL) p1->next = p1->next->next;
        return head;
    }
};

int main(){
    Solution s;
    ListNode *p1 = new ListNode(1);
    ListNode *p2 = new ListNode(2);
    ListNode *p3 = new ListNode(3);
    ListNode *p4 = new ListNode(4);
    ListNode *p5 = new ListNode(5);
    p1->next = p2; p2->next = p3; p3->next = p4; p4->next = p5;
    ListNode *newHead = s.removeNthFromEnd(p1, 1);
    while (newHead != NULL){
        cout << newHead->val << ' ';
        newHead = newHead->next;
    }
    return 0;
}
