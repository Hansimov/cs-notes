#include <iostream>
#include <string>
#include <cstdio>
// #include <thread> // thread
#include "mingw.thread.h"
// #include <mutex>
#include "mingw.mutex.h"

/**
 * The Singleton class defines the `GetInstance` method that serves as an
 * alternative to constructor and lets clients access the same instance of this
 * class over and over.
 */

class Singleton {
private:
    static Singleton * pinstance_; // ensure multi-thread safety
    static std::mutex mutex_;      // ensure multi-thread safety

protected:
    Singleton(const std::string value): value_(value) { }
    ~Singleton() {}
    std::string value_;

public:
    /**
     * Singletons should not be cloneable.
     */
    Singleton(Singleton &other) = delete;
    /**
     * Singletons should not be assignable.
     */
    void operator=(const Singleton &) = delete;
    /**
     * This is the static method that controls the access to the singleton
     * instance. On the first run, it creates a singleton object and places it
     * into the static field. On subsequent runs, it returns the client existing
     * object stored in the static field.
     */
    static Singleton *GetInstance(const std::string& value);

    /**
     * Finally, any singleton should define some business logic, which can be
     * executed on its instance.
     */
    void doSomething() {
        // ...
    }
    
    std::string value() const{
        return value_;
    }
};


/**
 * Static methods should be defined outside the class.
 */
Singleton* Singleton::pinstance_{nullptr};  // ensure multi-thread safety
std::mutex Singleton::mutex_;               // ensure multi-thread safet
/**
 * The first time we call GetInstance we will lock the storage location
 *      and then we make sure again that the variable is null and then we
 *      set the value. RU:
 */
Singleton *Singleton::GetInstance(const std::string& value)
{
    std::lock_guard<std::mutex> lock(mutex_); // ensure multi-thread safety
    if (pinstance_ == nullptr) {
        pinstance_ = new Singleton(value);
    }
    return pinstance_;
}

void ThreadFoo(){
    // Following code emulates slow initialization.
    std::this_thread::sleep_for(std::chrono::milliseconds(200));
    Singleton* singleton = Singleton::GetInstance("FOO");
    std::printf("%s\n", singleton->value().c_str());
}

void ThreadBar(){
    // Following code emulates slow initialization.
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