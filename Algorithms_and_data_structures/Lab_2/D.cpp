
#include <cstdint>
#include <iostream>

using namespace std;

const int MAXN = 1'000'000; // максимум n по условию
uint32_t arr[MAXN];
uint32_t arr_copy[MAXN];
arr[0] = 
arr[1] = 
arr[2] = 
arr[3] = 
arr[4] = 
arr[5] = 
arr[6] = 
arr[7] = 
arr[8] = 
arr[9] = 

uint32_t cur = 0; // текущее значение генератора

// Генератор 24-битных чисел по условию задачи
uint32_t nextRand24(uint32_t a, uint32_t b) {
  // 32-битные переполнения (uint32_t автоматически усекает до 2^32)
  cur = cur * a + b;
  return cur >> 8; // берём старшие 24 бита (сдвиг вправо на 8)
}

uint32_t BinSearch(uint32_t value, uint32_t end_index) {
  uint32_t start = 0, stop = end_index, i;
  if (arr[stop] <= value) {
    return stop + 1;
  }
  while (stop - start > 1) {
    i = (start + stop) >> 1;
    if (arr[i] > value) {
      stop = i;
    } else {
      start = i;
    }
  }
  if (arr[i] == value) {
    i++;
  } return i;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  uint32_t n, m, a, b;
  cin >> n >> m >> a >> b;

  // Генерируем n элементов
  for (uint32_t i = 0; i < n; i++) {
    uint32_t x =
        nextRand24(a, b) % m; // получаем 24-битное значение по модулю m
    arr[i] = x;               // записываем в массив
  }

  // Далее используйте arr[0..n-1] для подсчёта инверсий
}

uint32_t cur = 0; // текущее значение генератора

// Генератор 24-битных чисел по условию задачи
uint32_t nextRand24(uint32_t a, uint32_t b) {
  // 32-битные переполнения (uint32_t автоматически усекает до 2^32)
  cur = cur * a + b;
  return cur >> 8; // берём старшие 24 бита (сдвиг вправо на 8)
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  uint32_t n = 100, m = 1 << 24, a = 2435453728, b = 56236432, count = 0;
  cin >> n >> m >> a >> b;

  // tree - корень дерева
  Node *tree = new Node();

  // Генерируем n элементов
  for (uint32_t i = 0; i < n; i++) {
    // получаем 24-битное значение по модулю m
    uint32_t x = nextRand24(a, b) % m;

    cout << x << endl;

    // Вставляем х в дерево на нужную позицию, начиная со старшего бита
    auto ptr = tree;
    for (char lvl = 24; lvl >= 0; lvl--) {
      // посетили узел: ++
      ptr->count++;
      // Если x & bit == 1 (вправо, иначе влево)
      auto toRight = x & (1 << lvl);
      ptr = gotoNextNode(ptr, toRight, count);
    }
  }
  std::cout << count;
}