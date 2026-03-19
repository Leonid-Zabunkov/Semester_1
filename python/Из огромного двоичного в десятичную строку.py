# python

def binary_to_decimal(bin_str):
    decimal_str = "0"
    for bit in bin_str:
        # Умножаем decimal_str на 2
        decimal_str = multiply_str_by_digit(decimal_str, 2)
        # Если бит == '1', прибавляем 1
        if bit == '1':
            decimal_str = add_str_numbers(decimal_str, "1")
    return decimal_str

def multiply_str_by_digit(num_str, digit):
    carry = 0
    result = []
    for n in reversed(num_str):
        prod = int(n) * digit + carry
        carry = prod // 10
        result.append(str(prod % 10))
    if carry > 0:
        result.append(str(carry))
    return ''.join(reversed(result))

def add_str_numbers(num_str1, num_str2):
    carry = 0
    result = []
    i, j = len(num_str1) - 1, len(num_str2) - 1
    while i >= 0 or j >= 0 or carry:
        digit1 = int(num_str1[i]) if i >= 0 else 0
        digit2 = int(num_str2[j]) if j >= 0 else 0
        s = digit1 + digit2 + carry
        carry = s // 10
        result.append(str(s % 10))
        i -= 1
        j -= 1
    return ''.join(reversed(result))
