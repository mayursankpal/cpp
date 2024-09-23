/**
 * Threads serving and eating soup
 */
#include <thread>
#include <queue>
#include <mutex>
#include <condition_variable>

class ServingLine {
    public:
        void serve_soup(int i) {
            std::unique_lock<std::mutex> soup_lock(mtx_soup);
            soup_queue.push(i);
            soup_lock.unlock();
            soup_served.notify_one();
        }

        int take_soup() {
            std::unique_lock<std::mutex> soup_lock(mtx_soup);
            while (soup_queue.empty()) {
                soup_served.wait(soup_lock);
            }
            int bowl = soup_queue.front();
            soup_queue.pop();
            return bowl;
        }
        
    private:
        std::queue<int> soup_queue;
        std::mutex mtx_soup;
        std::condition_variable soup_served;
};

ServingLine serving_line = ServingLine();

void soup_producer() {
    for (int i=0; i<10000; i++) { // serve a 10,000 bowls of soup
        serving_line.serve_soup(1);
    }
    serving_line.serve_soup(-1); // indicate no more soup
    printf("Producer is done serving 10,000 bowls of soup!\n");
}

void soup_consumer(std::string threadName) {
    int soup_eaten = 0;
    while (true) {
        int bowl = serving_line.take_soup();
        if (bowl == -1) { // check for last bowl of soup
            printf("%s ate %d bowls of soup.\n",threadName.data(), soup_eaten);
            serving_line.serve_soup(-1); // put back last bowl for other consumers to take
            return;
        } else {
            soup_eaten += bowl; // eat the soup
        }
    }
}

int main() {
    std::thread sari    (soup_producer);
    std::thread mayur   (soup_consumer,"Mayur");
    std::thread ojas    (soup_consumer,"Ojas");
    std::thread gauri   (soup_consumer,"Gauri");
    std::thread manjiri (soup_consumer,"Manjiri");
    sari.join();
    mayur.join();
    ojas.join();
    gauri.join();
    manjiri.join();
}