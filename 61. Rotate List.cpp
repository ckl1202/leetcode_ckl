#include <iostream>
using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL){}
};

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL) return NULL;
        if (k == 0) return head;
        ListNode *p1 = head, *p2 = head;
        int n_size = 0;
        while (p2 != NULL){
            ++n_size;
            p2 = p2->next;
        }
        k %= n_size;
        p2 = head;
        for (int i = 0; i < k; ++i){
            p2 = p2->next;
        }
        if (p1 == p2) return head;
        ListNode *newTail, *tail;
        while (p2 != NULL){
            newTail = p1;
            p1 = p1->next;
            tail = p2;
            p2 = p2->next;
        }
        tail->next = head;
        newTail->next = NULL;
        return p1;
    }
};

int main(){
    Solution s;
    ListNode *p1 = new ListNode(1);
    ListNode *p2 = new ListNode(2);
    ListNode *p3 = new ListNode(3);
    ListNode *p4 = new ListNode(4);
    ListNode *p5 = new ListNode(5);
    p1->next = p2; p2->next = p3; //p3->next = p4; p4->next = p5;
    ListNode *ans = s.rotateRight(p1, 2);
    while (ans != NULL){
        cout << ans->val << ' ';
        ans = ans->next;
    }
    return 0;
}
