#include <iostream>
using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL){}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head == NULL) return NULL;
        ListNode *newHead = new ListNode(0);
        newHead->next = head;
        ListNode *p1 = head, *p2 = head->next;
        if (p2 == NULL) return p1;
        head = p2;
        while (p2 != NULL){
            p1->next = p2->next;
            p2->next = p1;
            newHead->next = p2;
            newHead = p1;
            p1 = p1->next;
            if (p1 != NULL){
                p2 = p1->next;
            }
            else p2 = NULL;
        }
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
    ListNode *head = s.swapPairs(p1);
    while (head != NULL){
        cout << head->val << ' ';
        head = head->next;
    }
    return 0;
}
