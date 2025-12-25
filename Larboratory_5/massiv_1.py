def find_min(arr):
    return min(arr)

def multiply_array(arr, multiplier):
    return [x * multiplier for x in arr]

def print_array(arr, name):
    print(f"{name}: {arr}")

def main():
    SIZE = 5
    print(f"Введите {SIZE} элементов для массива A:")
    A_original = [int(input()) for _ in range(SIZE)]
    print(f"Введите {SIZE} элементов для массива B:")
    B_original = [int(input()) for _ in range(SIZE)]

    min_a = find_min(A_original)
    min_b = find_min(B_original)

    A_transformed = multiply_array(A_original, min_a)
    B_transformed = multiply_array(B_original, min_b)

    print("\nИсходные массивы:")
    print_array(A_original, "Массив A")
    print_array(B_original, "Массив B")
    print(f"\nМинимальные элементы: A={min_a}, B={min_b}")
    print("\nПреобразованные массивы (каждый элемент умножен на минимум своего массива):")
    print_array(A_transformed, "Массив A'")
    print_array(B_transformed, "Массив B'")

if __name__ == "__main__":
    main()
