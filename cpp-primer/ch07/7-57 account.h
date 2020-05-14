#include <string>

using namespace std;

struct Account {
    void calc() {
        amount += amount * interestRate;
    }
    static double rate() {
        return interestRate;
    }
    static void rate(double newRate) {
        interestRate = newRate;
    }

private:
    string owner;
    double amount;
    static double interestRate;
    static constexpr double todayRate = 6.66;
    static double initRate() {
        return todayRate;
    }
};

double Account::interestRate = initRate();