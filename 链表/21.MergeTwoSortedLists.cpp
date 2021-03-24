// 合成两个有序链表是归并排序的基础
// HOT

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    ListNode* head = new ListNode(),*p=head;
    while(l1&&l2){
        if(l1->val<l2->val){
            p->next = l1;
            l1 = l1->next;
        }else{
            p->next = l2;
            l2 = l2->next;
        }
        p = p->next;
    }
    p->next = l1==nullptr?l2:l1;
    return head->next;
}
