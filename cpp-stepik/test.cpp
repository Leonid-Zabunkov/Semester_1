
// static void hello() { cout << "Help me" };

// int main() {
//   cout << "Hello";
//   cout << "Hello";
//   hello();
// }

// #include <iostream>
// int main() {
//   std::cout << "Hello, World!" << std::endl;
//   return 0;
// }

// ``` [1](https://cppscripts.com/hello-world-program-cpp)

// **Объяснение кода по строчкам**:

#include <cstdint>
#include <cstdio>
#include <iostream>

// void hello(int x) { std::cout << "hello:" << x; }

int main() {
  // std::cout << (sizeof(char) == sizeof('a'));

  // hello(15);

  // auto ptr = &hello;

  // ptr(12);
  int x = 125;
  // std::cout << (x << 33) << std::endl;
  std::cout << (x >> 2) << std::endl;

  // unsigned int y = x;
  std::cout << INT32_MIN - 1 << std::endl;
  // unsigned int t = -1;
  // std::cout << (t) << std::endl;
}
