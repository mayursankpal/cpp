#include <iostream>
#include <thread>

int g_counter = 0 ;

void task(int thread_id)
{
    for(int i = 0; i< 100000 ; i++){
        g_counter++;
    }
}

int main()
{
    std::thread thr1(task,1);
    std::thread thr2(task,2);
    std::thread thr3(task,3);
    std::thread thr4(task,4);
    std::thread thr5(task,5);

    thr1.join();
    thr2.join();
    thr3.join();
    thr4.join();
    thr5.join();

    std::cout << "g_counter value post 5 thread execution : " << g_counter << std::endl;
}