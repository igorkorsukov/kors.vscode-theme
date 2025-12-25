/*
Header comment
*/

#include <printf.h>

static const int GLOBAL_VAR = 10;

struct MyStruct {
    int x;
    int y;
};

static void func()
{

}

int main() {
    print("Hello, world!");

    func();

    int local_var = 10;

    return 0;
}