// Структуры, Объединения

// struct Point
// {
//     int x;
//     int y;
// } pt1, pt2, pt3;

// Point p4;
//  // * Объявления структуры определяют тип

// // Инициализация
// Point p1 = {1, 2};
// Point p2 = {.x = 1, .y = 2};

// Rect r1 = { {1, 2}, p2};
// Rect r2 = { .pt1 = {1, 2}, .pt2 = p2};

// struct Button {
//     struct {
//         int x;
//         int y;
//     };

//     struct {
//         size_t width;
//         size_t height;
//     }
// };
// Button ......

// Операции над структурами

// Point AddPoint(
//     Point p1,
//     Point p2
// ) {
//     p1.x += p2.x;
//     p1.y += p2.y;

//     return p1;
// }

// массивы структур

// struct Record{
//     char name[10];
//     char surname[10];
//     long fhone;
// }

// Record* FindRecord(
//     long fhone,
//     Record* records,
//     int count
// ) {
//     for(int i = 0; i < count; ++i)
//     //не успел дописать
// }

#include <cassert>
#include <cstddef>
#include <cstdint>
#include <format>
#include <iostream>
#include <ostream>

struct Point {
  int x; // 4Б
  int y; // 4Б
};
// а x x x x x x x b b b b b b b b c x x x d d d d
struct Foo {
  char a;     // 0Б
  int64_t b;  // 8Б
  uint8_t c;  // 16Б
  uint32_t d; // 20Б
};
// !!! Если поменять местами строчки в структуре Foo, то она будет занимать
// другое кол-во памяти !!! оптимальнее, когда от большего к меньшему b b b b b
// b b b d d d d a c x x
struct Foo1 {
  int64_t b;  // 8Б
  uint32_t d; // 4Б
  char a;     // 1Б
  uint8_t c;  // 1Б
};

int main() {
  std::cout << std::format("Size if int {}", sizeof(Point)) << std::endl;
}

// Выравнивание структур:
// без выравнивания
#pragma pack(1)
struct F1oo {
  char a;     // 0Б
  int64_t b;  // 8Б
  uint8_t c;  // 16Б
  uint32_t d; // 20Б
};
#pragma pop

// выбираем кратность байт
struct alignas(64) F2oo {

  char a;     // 0Б
  int64_t b;  // 8Б
  uint8_t c;  // 16Б
  uint32_t d; // 20Б
};

// Объединение:

union Name {
  struct {
    char name[13]; // 13
    char code[3];  // 3
  };

  struct {
    int32_t i1;
    int32_t i2;
    int32_t i3;
    int32_t i4;
  };
};

using Key = char*;

bool Compare(Key *a, Key *b) {
  // return (a->name == b-> name && a ->code == b->code);
  return (std::strcmp(a->name, b->name) == 0) &&
         (std::strcmp(a->code, b->code) == 0);
}

int main(int, char **) {
  Key k1 = {.name = "0123456789AB", .code = "10"};
  Key k2 = {.name = "0123456789AB", .code = "10"};

  std::cout << Compare(&k1, &k2) <<
}

//  Google benchmark - смотреть какой код быстрее

// в следующий раз понадобится ассемблер

struct Triangle {
  Point a;
  Point b;
  Point c;
};

struct Rect {
  Point left_top;
  Point right_top;
  Point left_bottom;
};

// 12
struct Circle {
  Point center;
  float r;
};

enum FigureType {
  ETriangle,
  ERect,
  ECircle //
};

struct Figure {
  union {
    Triangle tr; // 24
    Rect re;     // 24
    Circle ce;   // 12
  };
  FigureType type; // 4
};

void printFigure(Figure f) {
  if (f.type == ETriangle) {
    // ......
  }
}

int main(int, char **) {
  std::cout << sizeof(Figure) << std::endl;

  // Figure figures_1 = {{.c = {{0, 0}, 1}}, type = ECircle};
}

//---------------------------------------------------------------

#include <iostream>

int foo(int) { return 0; }

int FuncMax(int* array, size_t size, bool (*compare)(int a, int b)) {
  assert(array != nullptr);
  assert(size > 0);
  int result = array[0];

  for (int i = 1; i < size; ++i) {
    if (!compare(result, array[i])) {
      result = array[i];
    }
  }
}