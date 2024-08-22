#include <thread>
#include <iostream>

using namespace std;

class thread_guard{
std::thread thr;

public:
    //Theory : Constructor will take Rvalue reference argument [so we need to move that object to member object]
    explicit thread_guard(std::thread&& th) : thr(std::move(th))
    {

    }

    ~thread_guard()
    {
        if(thr.joinable()){
            thr.join();
        }
    }

    thread_guard(const thread_guard&) = delete;                 //To prevent copying accidently
    thread_guard& operator=(const thread_guard&) = delete;      //To prevent assignment copying accidently

};

void hello()
{
    //Theory : Exception thrown inside thread MUST be handled withing thread function itself.
    // //         If we handled it in main it will abort the program with unhandled exception.
    try{
        throw std::exception();
    }
    catch(std::exception& ex){
        std::cout<< "Exception caught inside Thread Function : " << ex.what() << std::endl;         //RIGHT Place of exception handling
    }

    std::cout << "Inside Hello() function" << std::endl;
}

int main()
{
    try{
        std::thread thr(hello);
        thread_guard thguard{std::move(thr)};
        
        throw std::exception();
    }
    catch(std::exception& ex){
        std::cout << "Exception caught in main : " << ex.what() << std::endl;                      //This exception will also get caught as we wrote thread_guard class to handle it
    }
}