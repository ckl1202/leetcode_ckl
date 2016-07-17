#include <iostream>
#include <vector>
using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL){}
};

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (k <= 1) return head;
        if (head == NULL) return NULL;
        ListNode *newHead = new ListNode(0);
        newHead->next = head;
        ListNode *p1 = newHead, *p2 = newHead;
        ListNode *returnHead = newHead;
        while (p2 != NULL){
            bool flag = false;
            for (int i = 0; i < k; ++i){
                p2 = p2->next;
                if (p2 == NULL){
                    flag = true;
                    break;
                }
            }
            if (flag) break;
            vector<ListNode*> tempList;
            for (int i = 0; i < k; ++i){
                p1 = p1->next;
                tempList.push_back(p1);
            }
            p1 = p1->next;
            for (int i = k - 1; i > 0; --i){
                tempList[i]->next = tempList[i - 1];
            }
            tempList[0]->next = p1;
            newHead->next = tempList[k - 1];
            newHead = p1 = p2 = tempList[0];

        }
        returnHead = returnHead->next;
        return returnHead;
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
    ListNode *head = s.reverseKGroup(p1, 6);
    while (head != NULL){
        cout << head->val << ' ';
        head = head->next;
    }
    return 0;
}
