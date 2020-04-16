//
// Created by 成翔昊 on 2020/4/15.
//

#include <iostream>
#include <list>
#include <unordered_map>

using namespace std;

class LRUCache {
private:
    struct CacheNode {
        int key;
        int value;

        CacheNode(int k, int v) : key(k), value(v) {}
    };

public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }

    int get(int key) {
        // 不存在，返回-1
        if (cacheMap.find(key) == cacheMap.end()) return -1;
        // 存在，将节点移到对头
        auto position = cacheMap[key];
        cacheList.erase(position);
        cacheList.push_front(*position);
        // 更新cacheMap
        cacheMap[key] = cacheList.begin();
        // 返回value
        return cacheList.begin()->value;
    }

    void set(int key, int value) {
        // 如果不存在
        if (cacheMap.find(key) == cacheMap.end()) {
            // 队列已满，清空队尾
            if (cacheList.size() == capacity) {
                cacheMap.erase(cacheList.back().key);
                cacheList.pop_back();
            }
            // 添加节点到队列头
            cacheList.push_front(CacheNode(key, value));
            // 更新cacheMap
            cacheMap[key] = cacheList.begin();
        }
            // 如果已存在
        else {
            auto position = cacheMap[key];
            // 更新值
            position->value = value;
            // 将节点移到队头
            cacheList.erase(position);
            cacheList.push_front(*position);
            // 更新cacheMap
            cacheMap[key] = cacheList.begin();
        }
    }

    void print() {
        for (auto iter = cacheList.begin(); iter != cacheList.end(); iter++)
            cout << iter->key << ":" << iter->value << " ";
        cout << endl;
    }

private:
    // 双向链表插入和删除效率高，维护lru队列
    list<CacheNode> cacheList;
    // 保存每个节点的地址，保证O(1)时间内查找节点
    unordered_map<int, list<CacheNode>::iterator> cacheMap;
    int capacity;
};

int main() {
    auto lru = LRUCache(3);
    cout << lru.get(1) <<endl;
    lru.set(1,1);
    lru.set(2,2);
    lru.set(3,3);
    lru.print();
    lru.set(4,4);
    lru.print();
    lru.set(1,1);
    lru.print();
    lru.set(2,2);
    lru.print();
    lru.set(1,-1);
    lru.print();
    cout << lru.get(1) <<endl;
    cout << lru.get(2) <<endl;
    cout << lru.get(4) <<endl;
}
