#include <iostream>
#include <string>
#include <cstdio>
// #include <thread> // thread

#include "mingw.thread.h"

class Singleton {

protected:
    Singleton(const std::string value): value_(value) { }
    static Singleton* singleton_;
    std::string value_;

public:

    Singleton(Singleton &other) = delete;
    void operator=(const Singleton &) = delete;

    static Singleton *GetInstance(const std::string& value);

    void doSomething() {
        // ...
    }

    std::string value() const {
        return value_;
    }
};

Singleton* Singleton::singleton_ = nullptr;;

Singleton *Singleton::GetInstance(const std::string& value) {
    if (singleton_ == nullptr) {
        singleton_ = new Singleton(value);
    }
    return singleton_;
}

void ThreadFoo() {
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    Singleton* singleton = Singleton::GetInstance("FOO");
    std::cout << singleton->value() << std::endl;
}

void ThreadBar() {
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    Singleton* singleton = Singleton::GetInstance("BAR");
    std::cout << singleton->value() << std::endl;
}


int main() {
    std::cout << "√ two same value: singleton reused !\n" <<
              "× two different values: 2 singletons created \n" <<
              "OUTPUT: ";
    std::thread t1(ThreadFoo);
    std::thread t2(ThreadBar);
    t1.join();
    t2.join();

    return 0;
}