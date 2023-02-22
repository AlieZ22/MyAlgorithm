#include <iostream>
#include <unordered_map>
using namespace std;

/*
* 使用哈希表+双向链表，实现O(1) get和put
* 哈希表快速定位，双向链表增删方便
*/

struct DLinkNode{
    int key, value;
    DLinkNode *prev;
    DLinkNode *next;
    DLinkNode():key(0),value(0),prev(nullptr),next(nullptr){}
    DLinkNode(int _key, int _value):key(_key),value(_value),prev(nullptr),next(nullptr){}
};

class LRUCache{
private:
    unordered_map<int, DLinkNode *> cache;
    DLinkNode *head;
    DLinkNode *tail;
    int size;
    int capacity;
public:
    LRUCache(int _capacity):capacity(_capacity),size(0){
        // 使用伪头节点和伪尾节点
        head = new DLinkNode();
        tail = new DLinkNode();
        head->next = tail;
        tail->prev = head;
    }
    int get(int key){
        if(!cache.count(key)){
            return -1;
        }
        // 如果key存在，先通过哈希表定位，再移到头部
        DLinkNode *node = cache[key];
        moveToHead(node);
        return node->value;
    }
    void put(int key, int value){
        if(!cache.count(key)){
            // 若key不存在，创建一个新的节点
            DLinkNode *node = new DLinkNode(key, value);
            cache[key] = node;
            addToHead(node);
            ++size;
            // 如果超出容量，删除尾部节点（最不常使用的）
            if(size > capacity){
                DLinkNode *removed = removeTail();
                cache.erase(removed->key);
                delete removed;
                --size;
            }
        }else{      // 如果key存在，那么通过哈希表定位，修改value，再移到头部
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
    DLinkNode* removeTail(){
        DLinkNode *node = tail->prev;
        removeNode(node);
        return node;
    }
};