def linear_search(a, x):
    for i in range(len(a)):
        if a[i] == x:
            return i
    return -1


def sentinel_search(a, x):
    count = len(a)
    a.append(x)
    i = 0
    while a[i] != x:
        i = i + 1
    if i != count:
        return i
    else:
        return -1


def binary_search(a, x):
    start = 0
    end = len(a)-1
    while start <= end:
        mid = (start + end) // 2
        if a[mid] == x:
            return mid
        elif a[mid] < x:
            start = mid + 1
        else:
            end = mid - 1
    return -1


def fibonacci_search(a, x):
    fib1, fib2 = 1, 0
    fibn = fib2 + fib1
    a_len = len(a)
    while fibn < a_len:
        fib2 = fib1
        fib1 = fibn
        fibn = fib2 + fib1
    ind = -1
    while fibn > 1:
        n = min(ind + fib2, a_len - 1)
        if a[n] > x:
            fibn = fib2
            fib1 = fib1 - fib2
            fib2 = fibn - fib1
        elif a[n] < x:
            fibn = fib1
            fib1 = fib2
            fib2 = fibn - fib1
            ind = n
        else:
            return n
    if a[ind + 1] == n and fib1 == 1:
        return ind + 1
    return -1


sorted_arr = []
unsorted_arr = []

stud_num = int(input("Enter the number of Students who attended training program: "))

print("\nEnter Roll Numbers of students who attended training program in random order")
for i in range(0, stud_num):
    unsorted_arr.append(int(input(f"Enter the Roll Number of student {i + 1} : ")))

print("\nEnter Roll Numbers of students who attended training program in sorted order")
for i in range(0, stud_num):
    sorted_arr.append(int(input(f"Enter the Roll Number of student {i + 1} : ")))

print("\nRoll Numbers of students who attended training program in random order")
for i in range(0, len(unsorted_arr)):
    print("\t", unsorted_arr[i], end=" ")

print("\nRoll Numbers of students who attended training program in sorted order")
for i in range(0, len(sorted_arr)):
    print("\t", sorted_arr[i], end=" ")

stud_roll = int(input("\nEnter Roll Number of student to be search"))

while True:
    print('''
    ------ ------ ------  MENU  ------ ------ ------ 
    1. Linear Search 
    2. Sentinel Search 
    3. Binary Search 
    4. Fibonacci Search
    5. Exit  ''')

    choice = int(input("Enter your choice : "))

    if choice == 1:
        index = linear_search(unsorted_arr, stud_roll)
        if index != -1:
            print("Roll number", stud_roll, " at the index", index, "has Attended the training program")
        else:
            print("Roll number", stud_roll, "has not Attended the training program")

    elif choice == 2:
        index = sentinel_search(unsorted_arr, stud_roll)
        if index != -1:
            print("Roll number", stud_roll, " at the index", index, "has Attended the training program")
        else:
            print("Roll number", stud_roll, "has not Attended the training program")

    elif choice == 3:
        index = binary_search(sorted_arr, stud_roll)
        if index != -1:
            print("Roll number", stud_roll, " at the index", index, "has Attended the training program")
        else:
            print("Roll number", stud_roll, "has not Attended the training program")

    elif choice == 4:
        index = fibonacci_search(sorted_arr, stud_roll)
        if index != -1:
            print("Roll number", stud_roll, " at the index", index, "has Attended the training program")
        else:
            print("Roll number", stud_roll, "has not Attended the training program")

    elif choice == 5:
        print("Thank you!!1")
        break

    elif choice == 6:
        print("Enter a valid choice")