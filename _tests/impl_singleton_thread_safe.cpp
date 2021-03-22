#include <iostream>
#include <string>
#include <cstdio>
// #include <thread> // thread
#include "mingw.thread.h"
// #include <mutex>
#include "mingw.mutex.h"

class Singleton {
private:
    static Singleton * pinstance_;
    static std::mutex mutex_;   // ensure multi-thread safety

protected:
    Singleton(const std::string value): value_(value) { }
    ~Singleton() {}
    std::string value_;

public:

    Singleton(Singleton &other) = delete;
    void operator=(const Singleton &) = delete;
    static Singleton *GetInstance(const std::string& value);

    void doSomething() {
        // ...
    }
    
    std::string value() const{
        return value_;
    } 
};


Singleton* Singleton::pinstance_{nullptr};  // ensure multi-thread safety
std::mutex Singleton::mutex_;               // ensure multi-thread safety

Singleton *Singleton::GetInstance(const std::string& value)
{
    std::lock_guard<std::mutex> lock(mutex_); // ensure multi-thread safety
    if (pinstance_ == nullptr) {
        pinstance_ = new Singleton(value);
    }
    return pinstance_;
}

void ThreadFoo(){
    std::this_thread::sleep_for(std::chrono::milliseconds(200));
    Singleton* singleton = Singleton::GetInstance("FOO");
    std::printf("%s\n", singleton->value().c_str());
}

void ThreadBar(){
    std::this_thread::sleep_for(std::chrono::milliseconds(200));
    Singleton* singleton = Singleton::GetInstance("BAR");
    std::printf("%s\n", singleton->value().c_str());
}

int main() {   
    std::cout <<"√ two values are same: singleton was reused \n" <<
                "× two values are not same: 2 singletons were created \n\n" <<
                "RESULT:\n";   
    std::thread t1(ThreadFoo);
    std::thread t2(ThreadBar);
    t1.join();
    t2.join();
    
    return 0;
}