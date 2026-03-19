
#include <cstdint>
#include <iostream>

using namespace std;

struct Node {
  Node *r;
  Node *l;
  uint32_t count;
};

Node *gotoNextNode(Node *ptr, bool toRight, uint32_t &count) {
  if (toRight) {
    if (!ptr->r) {
      ptr->r = new Node();
    }
    return ptr->r;

  } else {
    if (!ptr->l) {
      ptr->l = new Node();
    }
    // а сколько чисел уже больше (справа от ptr)
    if (ptr->r) {
      count += ptr->r->count;
    }
    return ptr->l;
  }
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