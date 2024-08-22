#include <iostream>
#include <thread>
#include <chrono>
#include <vector>
#include <string>

using namespace std::literals;
using namespace std::chrono;

void hello()
{
    auto start = high_resolution_clock::now();
    std::cout << "Hello from thread function" << std::endl;
    std::cout << "Hello thread ID from function : " << std::this_thread::get_id() << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(2));
    std::this_thread::sleep_for(2s);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<std::chrono::microseconds>(stop - start);
    std::cout << "Thread Function execution time : " << duration.count() << std::endl;
    std::vector<std::string> msg{"Hi","hello"};
    std::string temp = msg.at(0);
    std::cout << "vector has message 0 : " << temp << std::endl ;
}

int main()
{
    std::cout << "Main thread ID from main() : " << std::this_thread::get_id() << std::endl;
    
    std::thread thr(hello);

    std::cout << "Native handle of hello thr : " << thr.native_handle() << std::endl;

    std::cout << "Hello thread ID from main() : " << thr.get_id() << std::endl;

    thr.join();

    std::cout << "Post thread execution native handle of hello thr : " << thr.native_handle() << std::endl;
}

