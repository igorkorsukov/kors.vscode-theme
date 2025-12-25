/*
Header comment
*/

#pragma once 

#include <string>

namespace my::space {

class MyClass {
public:
    MyClass();
    ~MyClass();

    std::string name() const { return m_name; }

    void foo(bool arg);

    void setValue(int value);
    int value() const;

private:
    int m_value = 42;
    std::string m_name;
};

}