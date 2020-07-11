//
// Created by 成翔昊 on 2020/7/6.
//

#include <iostream>
#include <list>
#include <unordered_map>

using namespace std;

class LRUCache {
private:
    // 缓存节点
    struct CacheNode{
        int key;
        int value;
        CacheNode(int k, int v): key(k), value(v) {}
    };
public:
    LRUCache(int capacity) {
        this->capacity=capacity;
    }

    int get(int key) {
        auto position=cacheMap.find(key);
        if(position==cacheMap.end()) return -1;

        // 更新lru队列
        cacheList.erase(position->second);
        cacheList.push_front(*(position->second));

        // 更新map
        cacheMap[key]=cacheList.begin();

        // 返回value
        return cacheList.begin()->value;
    }

    void set(int key, int value) {
        // 如果key不在lru队列中
        auto position = cacheMap.find(key);
        if(position == cacheMap.end()) {
            // lru队列已满
            if (cacheList.size()==capacity) {
                // 删除队尾节点
                cacheMap.erase(cacheList.back().key);
                cacheList.pop_back();
            }
            // 添加节点到队列头
            cacheList.push_front(CacheNode(key, value));
            // 更新cacheMap
            cacheMap[key] = cacheList.begin();
        }
        // 如果key在lru队列中
        else {
            position->second->value=value;

            // 更新lru队列
            cacheList.erase(position->second);
            cacheList.push_front(*(position->second));

            // 更新map
            cacheMap[key]=cacheList.begin();
        }
    }

    void print() {
        for (auto iter = cacheList.begin(); iter != cacheList.end(); iter++)
            cout << iter->key << ":" << iter->value << " ";
        cout << endl;
    }

private:
    // lru队列，使用双向链表，插入和删除效率高
    list<CacheNode> cacheList;
    // lru队列的容量
    int capacity;

    // 保存lru队列，key到节点地址的映射，保证O(1)时间内查找节点
    unordered_map<int, list<CacheNode>::iterator> cacheMap;
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