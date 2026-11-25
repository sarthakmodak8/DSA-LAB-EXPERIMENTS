size = 10
table = [-1] * size

def insert(key):
    index = key % size

    if table[index] == -1:
        table[index] = key
    elif table[index] % size != index:
        temp = table[index]
        table[index] = key
        index = (index + 1) % size
        while table[index] != -1:
            index = (index + 1) % size
        table[index] = temp
    else:
        index = (index + 1) % size
        while table[index] != -1:
            index = (index + 1) % size
        table[index] = key

def display():
    print("Hash Table:")
    for i in range(size):
        print(i, ":", table[i])

n = int(input("Enter number of elements: "))
for i in range(n):
    key = int(input("Enter key: "))
    insert(key)

display()
