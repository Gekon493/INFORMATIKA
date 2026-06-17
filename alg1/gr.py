import time
import matplotlib.pyplot as plt

def remove_all_from_set(s):
    for elem in list(s):   
        s.remove(elem)

ns = [10, 100, 1000, 5000, 10000, 20000, 50000, 100000, 200000, 500000, 1000000]
times = []

for n in ns:
    s = set(range(n))        
    start = time.perf_counter()
    remove_all_from_set(s)      
    end = time.perf_counter()
    times.append(end - start)

# График
plt.figure(figsize=(10, 6))
plt.plot(ns, times, marker='o', label='Удаление всех элементов из множества')
plt.xlabel('Количество элементов (N)', fontsize=12)
plt.ylabel('Время работы (секунды)', fontsize=12)
plt.title('Удаление элемента из множества (Python set)', fontsize=14)
plt.legend()
plt.grid(True)
plt.xscale('log')
plt.yscale('log')
plt.tight_layout()
plt.show()
