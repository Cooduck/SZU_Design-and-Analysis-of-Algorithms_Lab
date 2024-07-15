#pragma once
#include <unordered_map>

struct Edge{
    int u, v;

    // 定义 operator== 以便 unordered_map 比较 keys
    bool operator==(const Edge& other) const {
        return u == other.u && v == other.v;
    }
};

// 定义 Edge 的哈希函数
struct edge_hash {
    size_t operator()(const Edge& e) const {
        size_t h1 = std::hash<int>()(e.u);
        size_t h2 = std::hash<int>()(e.v);
        return h1 ^ (h2 * 31); // 混合两个哈希值
    }
};

// 节点结构体
struct Node {
    int data;
    Node* next;

    Node():data(0), next(nullptr){}
    Node(int data) : data(data), next(nullptr) {}
};

// 链表类
class LinkedList {
private:
    Node* head;
    int length;

public:
    // 初始化
    LinkedList():length(0) {
        head = new Node(0);
    }

    // 析构函数
    ~LinkedList() {
        while (head->next != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
        delete head;
    }

    // 在链表插入节点
    void insert(int data) {
        Node* newNode = new Node(data);
        if (head->next == nullptr) {
            head->next = newNode;
        }
        else {
            Node* tmp = head->next;
            while (tmp->next != nullptr) {
                tmp = tmp->next;
            }
            tmp->next = newNode;
            newNode->next = nullptr;
        }
        length++;
    }

    // 在链表中删除节点
    void erase(int data) {
        Node* p = head;
        while (p->next != nullptr) {
            if (p->next->data == data) {
                Node* q = p->next;
                p->next = q->next;
                delete q;
                break;
            }
            else p = p->next;
        }
    }

    // 获取链表长度
    int size() const {
        return length;
    }

    inline Node* get_head() const {
        return head;
    }

    void clear() {
        while (head->next != nullptr) {
            Node* temp = head->next;
            head->next = temp->next;
            delete temp;
        }
    }
};