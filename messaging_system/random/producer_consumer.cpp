//Producer consumer sample code 
#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <queue>

using namespace std;
const int MAX_QUEUE_SIZE = 10;
queue<int> buffer;
std::mutex mtx;
std::condition_variable cond_var;

//Producer function
void producer(int item) {
    unique_lock<mutex> lock(mtx);
    while (buffer.size() == MAX_QUEUE_SIZE) {
        //Buffer is full, wait
        cond_var.wait(lock);
    }
    buffer.push(item);
    cout << "Produced: " << item << endl;
    cond_var.notify_one();
}

//Consumer function
void consumer() {
    unique_lock<mutex> lock(mtx);
    while (buffer.empty()) {
        //Buffer is empty, wait
        cond_var.wait(lock);
    }
    int item = buffer.front();
    buffer.pop();
    cout << "Consumed: " << item << endl;
    cond_var.notify_one();
}

//client code 
int main() {
    thread producer_threads[5], consumer_threads[5];
    for (int i = 0; i < 5; i++) {
        producer_threads[i] = thread(producer, i);
        consumer_threads[i] = thread(consumer);
    }
    for (int i = 0; i < 5; i++) {
        producer_threads[i].join();
        consumer_threads[i].join();
    }
    return 0;
}

