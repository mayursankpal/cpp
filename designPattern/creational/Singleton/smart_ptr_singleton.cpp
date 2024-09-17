#include <iostream>
#include <memory>
#include <mutex>

class Singleton {
private:
    static std::unique_ptr<Singleton> instance;
    static std::mutex mutex;

    Singleton(){}

public:
    static Singleton* getInstance() {
        if (instance == nullptr) {
            std::lock_guard<std::mutex> lock(mutex);
            if (instance == nullptr) {
                instance.reset(new Singleton());
            }
        }
        return instance.get();
    }

    void someOperation() {
        std::cout << "Performing some operation on the Singleton instance." << std::endl;
    }
};
std::unique_ptr<Singleton> Singleton::instance = nullptr;
std::mutex Singleton::mutex;

int main() {
    //Singleton* singleton = Singleton::getInstance();
    Singleton::getInstance()->someOperation();

    return 0;
}