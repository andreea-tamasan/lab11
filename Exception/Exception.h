//
// Created by Home on 17.05.2022.
//

#ifndef LAAB9_EXCEPTION_H
#define LAAB9_EXCEPTION_H
#include "iostream"
using namespace std;
class MyException : exception {
private:
    const char *message;
public:
    MyException(const char *message) : message(message) {}

    const char *what() const noexcept override {
        return message;
    }
};
#endif //LAAB9_EXCEPTION_H
