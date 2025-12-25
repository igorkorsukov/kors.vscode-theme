/*
Header comment
*/

#include <iostream>
#include "sample.h"

using namespace my::space;

const int GLOBAL_VAR = 10;
constexpr int GLOBAL_VAR_2 = 20;

MyClass::MyClass()
    : m_name("MyClass") 
{
}

MyClass::~MyClass() 
{
}

static int func() 
{
    return 10;
}

void MyClass::foo(bool arg)
{
    // comment

    bool ok = arg ? true : false;

    int local_var = 30;
    local_var += 10;

    local_var = static_cast<int>(local_var);
    local_var = dynamic_cast<int>(local_var);
    local_var = reinterpret_cast<int>(local_var);

    std::string local_str = "Hello";

    auto local_lambda = [&](int x) {
        return x + local_var;
    };

    std::cout << local_lambda(10) << std::endl;

    for(int i = 0; i < 10; i++) {
        std::cout << i << std::endl;
    }

    if (m_value == 10) {
        std::cout << "m_value is 10" << std::endl;
    } else {
        std::cout << "m_value is not 10" << std::endl;
    }

    while(true) {
        std::cout << "Hello, world!" << std::endl;
    }
}

void MyClass::setValue(int value)
{
    m_value = value;
}

int MyClass::value() const
{
    return m_value;
}

int main() {
    std::cout << "Hello, world!" << std::endl;
    return 0;
}