//Chain of responsibility patter in c++
#include <iostream>
#include <string>
using namespace std;

class Handler {
public:
    virtual void handleRequest(int request) = 0;
    virtual ~Handler() {}
};

class ConcreteHandler1 : public Handler {
public:
    void handleRequest(int request) override {
        if (request >= 0 && request < 10) {
            cout << "Handled by ConcreteHandler1" << endl;
        } else if (successor != nullptr) {
            successor->handleRequest(request);
        }
    }
    void setSuccessor(Handler* successor) {
        this->successor = successor;
    }
private:
    Handler* successor = nullptr;
};

class ConcreteHandler2 : public Handler {
public:
    void handleRequest(int request) override {
        if (request >= 10 && request < 20) {
            cout << "Handled by ConcreteHandler2" << endl;
        } else if (successor != nullptr) {
            successor->handleRequest(request);
        }
    }
    void setSuccessor(Handler* successor) {
        this->successor = successor;
    }
private:
    Handler* successor = nullptr;
};

class ConcreteHandler3 : public Handler {
public:
    void handleRequest(int request) override {
        if (request >= 20) {
            cout << "Handled by ConcreteHandler3" << endl;
        } else if (successor != nullptr) {
            successor->handleRequest(request);
        }
    }
    void setSuccessor(Handler* successor) {
        this->successor = successor;
    }
private:
    Handler* successor = nullptr;
};
int main() {
    ConcreteHandler1 handler1;
    ConcreteHandler2 handler2;
    ConcreteHandler3 handler3;
    handler1.setSuccessor(&handler2);
    handler2.setSuccessor(&handler3);
    int requests[] = {2, 12, 22};
    for (int request : requests) {
        handler1.handleRequest(request);
    }
    return 0;
}
