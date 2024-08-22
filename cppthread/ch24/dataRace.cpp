#include <iostream>
#include <thread>

void display(std::string input)
{
    for(int i = 0 ; i< 5 ;i++){
        std::cout << input[0] << input[1] << input[2] << std::endl;
        std::threa(1ms);
    }
}

int main()
{
    std::thread thr1(display,"abc");
    std::thread thr2(display,"---");
    std::thread thr3(display,"123");

    thr1.join();
    thr2.join();
    thr3.join();
}