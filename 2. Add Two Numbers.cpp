#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution{
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if (l1 == NULL) return l2;
        if (l2 == NULL) return l1;
        ListNode *p1 = l1->next, *p2 = l2->next;
        ListNode *head = new ListNode((l1->val + l2->val) %10);
        int addUp = (l1->val + l2->val) / 10;
        ListNode *tail = head;
        while (p1 != NULL || p2 != NULL){
            int value = addUp;
            if (p1 != NULL) value += p1->val;
            if (p2 != NULL) value += p2->val;
            addUp = value / 10;
            value = value % 10;
            ListNode *newNode = new ListNode(value);
            tail->next = newNode;
            tail = newNode;
            if (p1 != NULL) p1 = p1->next;
            if (p2 != NULL) p2 = p2->next;
        }
        if (addUp != 0){
            ListNode *newNode = new ListNode(addUp);
            tail->next = newNode;
        }
        return head;
    }
};

int main(){
    Solution s;
    ListNode *p1 = new ListNode(2);
    ListNode *p2 = new ListNode(4);
    ListNode *p3 = new ListNode(3);
    p1->next = p2; p2->next = p3;
    ListNode *pp1 = new ListNode(5);
    ListNode *pp2 = new ListNode(6);
    //ListNode *pp3 = new ListNode(5);
    pp1->next = pp2; //pp2->next = pp3;
    ListNode *head = s.addTwoNumbers(p1, pp1);
    while (head != 0){
        cout << head->val << ' ';
        head = head->next;
    }
    return 0;
}
