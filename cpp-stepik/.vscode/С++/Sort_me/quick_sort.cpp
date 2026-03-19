#include <iostream>

void print(int *lst, int len) {
  for (int i = 0; i < len; i++) {
    std::cout << lst[i];
    if (i < len - 1) {
      std::cout << " ";
    }
  }
  //   std::cout << std::endl;
}

void quick_sort(int a[], int start, int stop) {
  if (start >= stop) {
    return;
  }

  int i = start;
  int j = stop;
  int k = j;
  int t;

  // берём рандомный элемент
  int x = start + rand() % (stop - start);
  t = a[j];
  a[j] = a[x];
  a[x] = t;

  while (i < j) {
    if ((i == j - 1) && (a[i] > a[j])) {
      t = a[k];
      a[k] = a[i];
      a[i] = t;
      j--;
      k--;
      break;
    }
    if (a[i] == a[j]) {
      t = a[j - 1];
      a[j - 1] = a[i];
      a[i] = t;
      j--;
    } else if (a[i] > a[j]) {
      t = a[j - 1];
      a[j - 1] = a[k];
      a[k] = a[i];
      a[i] = t;
      k--;
      j--;

    } else {
      i++;
    }
  }

  quick_sort(a, start, i - 1);
  quick_sort(a, k + 1, stop);
}

int main2() {
  int n;
  std::cin >> n;
  int *a = new int[n];
  for (int i = 0; i < n; ++i) {
    std::cin >> a[i];
  }

  quick_sort(a, 0, n - 1);

  print(a, n);
}

int main() {
  int min = 10;
  int max = 100;
  int x = min + rand() % (max - min + 1);
  std::cout << x;
}