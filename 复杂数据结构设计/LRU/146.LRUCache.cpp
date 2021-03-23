// 运用你所掌握的数据结构，设计和实现一个  LRU (最近最少使用) 缓存机制 。
// 实现 LRUCache 类：

// LRUCache(int capacity) 以正整数作为容量 capacity 初始化 LRU 缓存
// int get(int key) 如果关键字 key 存在于缓存中，则返回关键字的值，否则返回 -1 。
// void put(int key, int value) 如果关键字已经存在，则变更其数据值；如果关键字不存在，则插入该组「关键字-值」。当缓存容量达到上限时，它应该在写入新数据之前删除最久未使用的数据值，从而为新的数据值留出空间。\

#include<iostream>
#include<unordered_map>
#include<list>
using namespace std;

// 104 ms 39.1 MB
class LRUCache {
public:
    LRUCache(int capacity):cap(capacity) {}
    
    int get(int key) {
        if(lru_map.find(key)==lru_map.end()) return -1;
        // 存在则更新
        lru_list.splice(lru_list.begin(),lru_list,lru_map[key]);
        return lru_map[key]->second;
    }
    
    void put(int key, int value) {
        // 分两种情况
        // 注意题目中已经给了value是大于零的所以才能这么判断
        // 不存在
        if(get(key)==-1){
            // 没有空间可用了
            if(cap==0){
                auto del = lru_list.back();
                lru_list.pop_back();
                lru_map.erase(del.first);
                cap++;
            }
            lru_list.emplace_front(key,value);
            lru_map[key] = lru_list.begin();
            cap--;
        }
        else{
            lru_map[key]->second = value;
        }
    }
private:
// 链表结构算count时间开销比较大，通过将cap转为剩余空间的作用规避
    int cap;
    list<pair<int,int>> lru_list;
    unordered_map<int,list<pair<int,int>>::iterator> lru_map;
};