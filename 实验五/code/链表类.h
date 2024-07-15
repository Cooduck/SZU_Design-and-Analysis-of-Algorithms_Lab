#pragma once
#include <unordered_map>

struct Edge{
    int u, v;

    // ���� operator== �Ա� unordered_map �Ƚ� keys
    bool operator==(const Edge& other) const {
        return u == other.u && v == other.v;
    }
};

// ���� Edge �Ĺ�ϣ����
struct edge_hash {
    size_t operator()(const Edge& e) const {
        size_t h1 = std::hash<int>()(e.u);
        size_t h2 = std::hash<int>()(e.v);
        return h1 ^ (h2 * 31); // ���������ϣֵ
    }
};

// �ڵ�ṹ��
struct Node {
    int data;
    Node* next;

    Node():data(0), next(nullptr){}
    Node(int data) : data(data), next(nullptr) {}
};

// ������
class LinkedList {
private:
    Node* head;
    int length;

public:
    // ��ʼ��
    LinkedList():length(0) {
        head = new Node(0);
    }

    // ��������
    ~LinkedList() {
        while (head->next != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
        delete head;
    }

    // ���������ڵ�
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

    // ��������ɾ���ڵ�
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

    // ��ȡ������
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