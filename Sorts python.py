data = []
with open("D:\\Hristo_10b\\Books.txt", "r") as file:
    data = file.readlines()

for line in data:
    line.replace('\n', '')
    
books = []

i = 0
while i < len(data):
    books.append([data[i], data[i + 1], data[i + 2], data[i + 3], data[i + 4], data[i + 5]])
    i += 7

with open("D:\\Hristo_10b\\Books.txt", "w") as file:
    for line in data:
        file.write(line)
    n = int(input("Do you want to add anything to the list?\nHow many?\n"))
    for i in range(n):
        for j in range(6):
            line = input() + '\n'
            data.append(line)
            file.write(line)
        file.write('\n')

element = int(input("Sort by?\nName - 1\nAuthor-2\nPublisher-3\nPrice-4\nYear-5\nStock-6\n")) - 1

def BubbleSort(array):
    for i in range(len(array)):
        for j in range(len(array) - i - 1):
            if array[j][element] > array[j+1][element]:
                array[j], array[j+1] = array[j+1], array[j]

def MergeSort(array):
    if len(array) > 1:
        mid = len(array) // 2
        L = array[:mid]
        R = array[mid:]
        MergeSort(L)
        MergeSort(R)

        i = j = k = 0
        while i < len(L) and j < len(R):
            if L[i][element] < R[j][element]:
                array[k] = L[i]
                i += 1
            else:
                array[k] = R[j]
                j += 1
            k += 1

        while i < len(L):
            array[k] = L[i]
            i += 1
            k += 1

        while j < len(R):
            array[k] = R[j]
            j += 1
            k += 1

def RadixSortLSD(array):
    digitNumber = 0
    for item in array:
        if item[element] == 0:
            continue
        import math
        if int(math.log10(int(item[element]))) + 1 > digitNumber:
            digitNumber = int(math.log10(int(item[element]))) + 1
    power = 1
    queues = [
        [],
        [],
        [],
        [],
        [],
        [],
        [],
        [],
        [],
        []
    ]

    i = 0
    while i < digitNumber:
        j = 0
        while j < len(array):
            queues[int(int(array[j][element]) / power % 10)].append(array[j])
            j += 1

        l = 0
        m = 0
        while l < len(array):
            n = 0
            length = len(queues[m])
            while n < length:
                array[l] = queues[m].pop()
                l += 1
                n += 1
            m += 1

        power *= 10
        i += 1

def Heapify(arr, n, i): 
    largest = i 
    l = 2 * i + 1
    r = 2 * i + 2
  
    if l < n and arr[i][element] < arr[l][element]: 
        largest = l 
  
    if r < n and arr[largest][element] < arr[r][element]: 
        largest = r 
  
    if largest != i: 
        arr[i],arr[largest] = arr[largest],arr[i]
  
        Heapify(arr, n, largest) 
  
def HeapSort(arr): 
    n = len(arr) 
  
    for i in range(n, -1, -1): 
        Heapify(arr, n, i) 
  
    for i in range(n-1, 0, -1): 
        arr[i], arr[0] = arr[0], arr[i]
        Heapify(arr, i, 0) 

def InsertionSort(arr): 
  
    for i in range(1, len(arr)): 
  
        key = arr[i]
  
        j = i-1
        while j >= 0 and key[element] < arr[j][element] : 
                arr[j + 1] = arr[j] 
                j -= 1
        arr[j + 1] = key 

    for i in range(len(arr)): 
        
        min_idx = i 
        for j in range(i+1, len(arr)): 
            if arr[min_idx][element] > arr[j][element]: 
                min_idx = j 
                
        arr[i], arr[min_idx] = arr[min_idx], arr[i] 

def Partition(arr,low,high): 
    i = ( low-1 )
    pivot = arr[high]
  
    for j in range(low , high): 
  
        if   arr[j][element] < pivot[element]: 
          
            i = i+1 
            arr[i],arr[j] = arr[j],arr[i] 
  
    arr[i+1],arr[high] = arr[high],arr[i+1] 
    return ( i+1 ) 
  
def QuickSort(arr,low,high): 
    if low < high: 
        pi = Partition(arr,low,high) 
  
        QuickSort(arr, low, pi-1) 
        QuickSort(arr, pi+1, high) 

if element == 0:
    HeapSort(books)
if element == 1:
    MergeSort(books)
if element == 2:
    InsertionSort(books)
if element == 3:
    QuickSort(books, 0, len(books) - 1)
if element == 4:
    BubbleSort(books)
if element == 5:
    RadixSortLSD(books)

for book in books:
    print(book)

# 3
# Random
# Stoqn
# Malinino
# 1.00
# 2018
# 500
# Mega
# Simeon
# hexa
# 9.99
# 2002
# 10000
# Hello
# Hristo
# hi
# 13.69
# 2019
# 4000