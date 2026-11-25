def heapify(arr, n, i):
    smallest = i
    left = 2 * i + 1
    right = 2 * i + 2

    if left < n and arr[left] < arr[smallest]:
        smallest = left

    if right < n and arr[right] < arr[smallest]:
        smallest = right

    if smallest != i:
        arr[i], arr[smallest] = arr[smallest], arr[i]
        heapify(arr, n, smallest)

def heapSort(arr):
    n = len(arr)

    # Create Min Heap
    for i in range(n // 2 - 1, -1, -1):
        heapify(arr, n, i)

    # Sort scores
    for i in range(n - 1, 0, -1):
        arr[0], arr[i] = arr[i], arr[0]
        heapify(arr, i, 0)

scores = [85, 45, 95, 60, 75]
heapSort(scores)

print("Player Scores in Descending Order:")
print(scores)
