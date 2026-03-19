def task_1():
    n = int(input())
    lst = [int(x) for x in input().split()]
    count = 0
    for i in range(1, n - 1):
        last, x, next = lst[i - 1 : i + 2]
        # last = lst[i - 1]
        # x = lst[i]
        # next = lst[i + 1]
        if x > last and x > next:
            count += 1
    print(count)


# task_1()


def task_2():

    n = int(input())
    lst = [int(x) for x in input().split()]
    digit = int(input())

    close_digit = 0
    distance = 100000
    for x in lst:
        dist = abs(digit - x)
        if dist < distance:
            close_digit = x
            distance = dist

    print(close_digit)


# task_2()


# st = input()

# max_ord = 0

# for x in st:
#     x_ord = ord(x)
#     if x_ord > max_ord:
#         max_ord = x_ord
# print(chr(max_ord))


# n = int(input())
# lst = [int(x) for x in input().split()]

# m1 = m2 = 100000


# for x in lst:
#     if x < m1:
#         m1, m2 = x, m1
#     elif x < m2:
#         m2 = x
# print(m1, m2)

def task_f():

    n, m, k = map(int, input().split())
    a = []
    for _ in range(n):
        lst = [int(x) for x in input().split()]
        a.append(lst)

    b = []
    for _ in range(m):
        lst = [int(x) for x in input().split()]
        b.append(lst)

    for i in range(n):
        lst = []
        for j in range(k):
            s = 0
            for x in range(m):
                s += a[i][x] * b[x][j]
            lst.append(s)
        print(*lst)
