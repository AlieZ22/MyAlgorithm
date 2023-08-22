#include <bits/stdc++.h>
#include <mutex>
#include <ctime>
using namespace std;

const int TTL = 5;         // 过期时间间隔，5s

struct DLinkNode{
    int key, value;
    time_t expire_time;    // 带过期时间
    DLinkNode *prev;
    DLinkNode *next;
    DLinkNode():key(0), value(0), prev(nullptr), next(nullptr){}
    DLinkNode(int k, int v): key(k), value(v), prev(nullptr), next(nullptr){}
    DLinkNode(int k, int v, time_t et):key(k),value(v),expire_time(et),prev(nullptr),next(nullptr){}
};

class LRUCache {
private:
    unordered_map<int, DLinkNode*> cache;
    DLinkNode *head;
    DLinkNode *tail;
    int capacity;
    int size;
    //mutex _mutex;   // 实现多线程安全
public:
    LRUCache(int _capacity):capacity(_capacity),size(0) {
        // 伪头节点和伪尾节点
        head = new DLinkNode();
        tail = new DLinkNode();
        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        //lock_guard<mutex> lock(_mutex);       // RAII思想，用对象管理资源
        if(!cache.count(key)){
            return -1;
        }
        DLinkNode *node = cache[key];
        // 访问时判断该元素是否过期
        if(difftime(node->expire_time, time(nullptr)) <= 0){   // 返回-1
            removeNode(node);
            return -1;
        }
        moveToHead(node);
        return node->value;
    }
    
    void put(int key, int value) {
        //lock_guard<mutex> lock(_mutex);        // get,put方法都需要加锁
        if(!cache.count(key)){
            // 创建新的节点
            DLinkNode *node = new DLinkNode(key, value);
            // 创建带过期时间的节点
            DLinkNode *node = new DLinkNode(key, value, time(nullptr)+TTL);   // time(nullptr)表示当前时间
            cache[key] = node;
            addToHead(node);
            ++size;
            if(size > capacity){         // 超出容量，删除过期->尾部节点
                DLinkNode *node = nullptr;
                // 先试图找一个过期节点
                time_t currTime = time(nullptr);
                for(auto it=cache.begin(); it!=cache.end(); ++it){
                    if(difftime(it->second->expire_time, currTime) <= 0){
                        node = it->second;
                        break;
                    }
                }
                // 没找到过期节点，就删除尾部节点
                if(node == nullptr){
                    node = tail->prev;
                }
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