#include <cstddef>
#include <iostream>
#include <string>

struct Node {
  int number = 0;
  Node *next = nullptr;
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

  int n;
  std::cin >> n;
  std::string str;
  Queue queue;
  for (int i = 0; i < n; i++) {
    std::cin >> str;

    if (str[0] == '-') {
      if (queue.empty()) {
        std::cout << "Error: empty queue";
        return 0;
      }
      std::cout << queue.pop_front() << std::endl;
    }

    else if (str[0] == '+') {
      int data;
      std::cin >> data;
      queue.push_back(data);
    }
  }

  queue.free();
}