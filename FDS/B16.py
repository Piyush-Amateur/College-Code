def partition(a, low, high):
    pivot = a[high]
    i = low
    for j in range(low, high):
        if a[j] <= pivot:
            (a[i], a[j]) = (a[j], a[i])
            i = i + 1
    (a[i], a[high]) = (a[high], a[i])
    return i


def quick_sort(a, low, high):
    if low < high:
        pi = partition(a, low, high)
        quick_sort(a, low, pi - 1)
        quick_sort(a, pi + 1, high)


array = []
stud_num = int(input("Enter number of students: "))
for i in range(stud_num):
    array.append(float(input(f"Enter percentage of student {i+1}: ")))

print("Percentage of students are (unsorted): ")
for i in array:
    print(i, end=" ")

print("\nPercentage of students are (sorted): ")
quick_sort(array, 0, len(array) - 1)
print("Top Five Scores are...")
for i in range(len(array) - 1, len(array) - 6, -1):
    print(array[i], end=" ")

