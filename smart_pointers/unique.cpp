#include <iostream>
#include <memory>
#include <mutex>
#include <thread>

// unique_ptr is a container that holds a single object, and it is responsible for managing the lifetime of that object.
// It is a scoped pointer, which means that when it goes out of scope, the pointed-to object is automatically deleted.
// unique_ptr is a smart pointer that ensures that only one pointer to an object exists at any given time.
// unique_ptr is a thread-safe implementation of a single-object ownership policy.
// unique_ptr is a lightweight and efficient implementation of a smart pointer, as it does not involve any heap allocation or deallocation operations.
// unique_ptr is a simple and efficient implementation of a smart pointer, as it does not involve any heap allocation or deallocation operations.

class Vehicle {
public:
    virtual void drive() = 0;
};

class car : public Vehicle {
public:
    void drive() override {
        std::cout << "Driving a car" << std::endl;
    }
};

class truck : public Vehicle {
public:
    void drive() override {
        std::cout << "Driving a truck" << std::endl;
    }
};

int main() {
    std::unique_ptr<Vehicle> vehicle;
    std::mutex mtx;

    //Creating 2 thread object t1 & t2 which then creating unique pointer in thread function passed as lambda
    std::thread t1([&]() {
        std::lock_guard<std::mutex> lock(mtx);
        vehicle = std::make_unique<car>();
    });

    std::thread t2([&]() {
        std::lock_guard<std::mutex> lock(mtx);
        vehicle = std::make_unique<truck>();
    });

    t1.join();
    t2.join();

    vehicle->drive();               //either car or truck object created from above two thread.

    vehicle = std::make_unique<truck>();
    vehicle->drive();

    vehicle = std::make_unique<car>();
    vehicle->drive();

    return 0;
}