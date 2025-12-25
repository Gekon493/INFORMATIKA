def Intersection(set_a, set_b):
    intersection = set_a & set_b 
    even_elements = {x for x in intersection if x % 2 == 0} 
    return even_elements

def main():
    print("Введите элементы множества A через пробел:")
    A = set(map(int, input().split()))
    
    print("Введите элементы множества B через пробел:")
    B = set(map(int, input().split()))
    
    result = Intersection(A, B)
    
    if result:
        print("Четные элементы из пересечения множеств A и B:", sorted(result))
    else:
        print("В пересечении множеств A и B нет четных элементов.")

if __name__ == "__main__":
    main()
