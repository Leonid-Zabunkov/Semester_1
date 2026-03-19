#include "lab1.h"
#include <iostream>
class String {
public:
  const int i = 0;
  String() { std::cout << "String()" << std::endl; };
  String(int i) : i(i) { std::cout << "String(int)" << std::endl; };
  String(const String &other) {
    std::cout << "String(const String& other)" << std::endl;
  }
  String(const String &&other) {
    std::cout << "String(const String&& other)" << std::endl;
  }
  ~String() { std::cout << "~String()" << std::endl; }

  String &operator=(const String &other) {
    std::cout << "operator=(const String& other)" << std::endl;
    return *this;
  }
};

void test(String s) { String x = s; }

int main() {
  String a(5);
  {
    auto b = a;
    b = a;
  }
  test(a);
}
