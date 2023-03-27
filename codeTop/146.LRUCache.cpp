#include <bits/stdc++.h>
using namespace std;

struct DLinkNode{
    int key, value;
    DLinkNode *prev;
    DLinkNode *next;
    DLinkNode():key(0), value(0), prev(nullptr), next(nullptr){}
    DLinkNode(int k, int v): key(k), value(v), prev(nullptr), next(nullptr){}
};

class LRUCache {
private:
    unordered_map<int, DLinkNode*> cache;
    DLinkNode *head;
    DLinkNode *tail;
    int capacity;
    int size;
public:
    LRUCache(int _capacity):capacity(_capacity),size(0) {
        // 伪头节点和伪尾节点
        head = new DLinkNode();
        tail = new DLinkNode();
        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        if(!cache.count(key)){
            return -1;
        }
        DLinkNode *node = cache[key];
        moveToHead(node);
        return node->value;
    }
    
    void put(int key, int value) {
        if(!cache.count(key)){
            // 创建新的节点
            DLinkNode *node = new DLinkNode(key, value);
            cache[key] = node;
            addToHead(node);
            ++size;
            if(size > capacity){         // 超出容量，删除尾部节点
                DLinkNode *node = tail->prev;
                removeNode(node);
                cache.erase(node->key);
                delete node;
                --size; 
            }
        }else{
            DLinkNode *node = cache[key];
            node->value = value;
            moveToHead(node);
        }
    }
    void removeNode(DLinkNode *node){
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }
    void addToHead(DLinkNode *node){
        node->prev = head;
        node->next = head->next;
        head->next->prev = node;
        head->next = node;
    }
    void moveToHead(DLinkNode *node){
        removeNode(node);
        addToHead(node);
    }
};