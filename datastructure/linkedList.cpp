#include <iostream>
#include <memory>
#include <mutex>
#include <thread>
#include <vector>
#include <chrono>
#include <random>
#include <algorithm>

using namespace std;

class Node {
public:
    int data;
    Node* next;
    std::mutex mutex;

    Node(int data) : data(data), next(nullptr) {}
};

class LinkedList {
private:
    Node* head;
    std::mutex head_mutex;

public:
    LinkedList() : head(nullptr) {}

    void push(int data) {
        std::unique_lock<std::mutex> lock(head_mutex);
        Node* new_node = new Node(data);
        new_node->next = head;
        head = new_node;
    }

    bool remove(int data) {
        std::unique_lock<std::mutex> lock(head_mutex);
        Node* prev = nullptr;
        Node* curr = head;

        while (curr != nullptr) {
            if (curr->data == data) {
                if (prev == nullptr) {
                    head = curr->next;
                } else {
                    prev->next = curr->next;
                }
                delete curr;
                return true;
            }
            prev = curr;
            curr = curr->next;
        }
        return false;
    }

    void print() {
        std::unique_lock<std::mutex> lock(head_mutex);
        Node* curr = head;
        while (curr != nullptr) {
            std::cout << curr->data << " ";
            curr = curr->next;
        }
        std::cout << std::endl;
    }
};

void worker(LinkedList& list, int id, int num_operations) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 100);

    for (int i = 0; i < num_operations; ++i) {
        int random_number = dis(gen);
        if (random_number <= 50) {
            list.push(id * 100 + i);
        } else {
            list.remove(id * 100 + i);
        }
    }
}

int main() {
    LinkedList list;
    std::vector<std::thread> threads;

    int num_threads = 4;
    int num_operations = 100;

    for (int i = 0; i < num_threads; ++i) {
        threads.emplace_back(worker, std::ref(list), i, num_operations);
    }

    for (auto& thread : threads) {
        thread.join();
    }

    list.print();

    return 0;
}