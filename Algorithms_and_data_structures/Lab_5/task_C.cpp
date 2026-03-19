#include <cmath>
#include <cstddef>
#include <iostream>
#include <string>

#define DEGREE 1 << 30

struct Node {
  int number = 0;
  Node *next = nullptr;
  Node *prev = nullptr;
};

struct Queue {
  Node *head = nullptr;
  Node *tail = nullptr;

  bool empty() { return head == nullptr; }

  void push_back(int data) {
    Node *node = new Node();
    node->number = data;
    if (tail) {
      tail->next = node;
      tail = node;
    } else {
      head = tail = node;
    }
  }

  void push_front(int data) {
    Node *node = new Node();
    node->number = data;
    if (head) {
      head->prev = node;
      head = node;
    } else {
      head = tail = node;
    }
  }

  int pop_front() {
    Node *node = head;
    head = head->next;
    if (head == nullptr) {
      tail = nullptr;
    }
    int data = node->number;
    delete node;
    return data;
  }

  int pop_back() {
    Node *node = tail;
    tail = tail->prev;
    if (tail == nullptr) {
      head = nullptr;
    }
    int data = node->number;
    delete node;
    return data;
  }

  void free() {
    while (head) {
      Node *next = head->next;
      delete head;
      head = next;
    }
  }
};

int main() {

  // Обязательно !!!
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  // Ускоряет в разы

  int n, k;
  std::cin >> n >> k;

  int x, y;
  Queue queue;
  for (int i = 0; i < n; i++) {
    std::cin >> x;
    queue.push_back(x);
  }
  for (int i = 0; i < k; i++) {

    x = queue.head->number;
    y = queue.tail->number;

    if (x < y) {
      queue.push_back((x + y) % (DEGREE));
      queue.pop_front();
    } else {
      queue.push_front((y - x) % (DEGREE));
      queue.pop_back();
    }
  }

  while (!queue.empty()) {
    std::cout << queue.pop_front() << " ";
  }
}