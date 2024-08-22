#include <thread>
#include <iostream>

using namespace std;

void hello()
{
    //Theory : Exception thrown inside thread MUST be handled withing thread function itself.
    //         If we handled it in main it will abort the program with unhandled exception.
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
        thr.join();
    }
    catch(std::exception& ex){
        std::cout << "Exception caught : " << ex.what() << std::endl;                               //WRONG Place of exception handling
    }
}