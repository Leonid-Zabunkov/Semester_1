// do
// {
//     ()
// }
// while{
// ()
// }

// for (int n = 10; n>0; n--) {
//     std::count << n << ' ';
// }

// for (int n : {0,1,2,3,4,5}) {
//     std::count << n << ' ';
// }

// есть break и continue

// switch(выражение)
// {
//     case константа1;
//     группа операторов1;
//     break

//     case константа2;
//     группа операторов2;\
//     break

// }

// можно в функции написать // declarations и пока не писать её тело
// а потом где -то после вызова нашей функции написать // definitions и написать её тело

// int max(int a, int b); // declaration

// int main() {
//   int c = max(10, 2);
//   max(1, 2);
//   return 0;
// }

// int max(int a, int b) { // definition
//   return a > b ? a : b;
// }

// можно вызывать функции без параметров

// int main (int arg, char*argv[], other_parameters) {...}

// унарные операторы:
// & - выдаёт адрес ячейки объекта зная её значение
// * - выдаёт значение объекта зная её адрес
// размер указателя не зависит от типа на который он указывает

void swap(int* pa, int* pb) {
    int tmp = *pa;
    *pa = *pb;
    *pb = tmp;
}
