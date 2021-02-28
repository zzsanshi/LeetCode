/*
 * @Author: chenruifeng
 * @Date: 2021-03-01 00:01:23
 * @LastEditTime: 2021-03-01 01:07:58
 * @LastEditors: Please set LastEditors
 * @Description: 快慢指针例子
 * @FilePath: /LeetCode/双指针算法/142.LinkedListCycleII.cpp
 */
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// 本题从直觉上并不会想到使用双指针，环的开头应该是被指向了两次的节点,用一个哈希set就可一记录了，但是效率很差
// 16 ms 9.3mb
ListNode *detectCycle_v1(ListNode *head)
{
    auto p = head;
    unordered_set<ListNode*> s;
    while(p!=NULL){
        if(s.find(p)!=s.end()){
            return p;
        }else{
            s.insert(p);
            p = p->next;
        }
    }
    return nullptr;
}
// 快慢指针的写法，快指针每次走两格，慢指针每次走一格
// 如果存在环快慢指针一定相遇，并且不会指到nullptr
// 当快指针与慢指针相遇时，f=2s;
// f=a+mb;s=a+nb => f-s = b的整数倍 -> f=2s=b的整数倍
// 相遇后将快节点f归到起点，慢节点不变，下次相遇位置即所求位置
// f = x; s=mb+x;当x=a时，正好慢节点转完一个环回到环的入口处与快节点相遇。
// 8ms 7.4mb
ListNode *detectCycle(ListNode *head)
{
    auto fast = head,low=head;
    while(fast){
        
        if(fast->next&&fast->next->next){
            fast = fast->next->next;
            low = low->next;
        }else{
            return nullptr;
        }      
        if(fast==low){
            fast = head;
            while(fast!=low){
                fast=fast->next;
                low=low->next;
            }
            return fast;
        }
    };
    return nullptr;
}