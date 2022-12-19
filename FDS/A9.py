def add():
    for x in range(len(A)):
        for y in range(len(A[0])):
            C[x][y] = A[x][y] + B[x][y]

    print("Addition")
    for a in C:
        print(a)


def sub():
    for i in range(len(A)):
        for j in range(len(A[0])):
            C[i][j] = A[i][j] - B[i][j]

    print("Subtraction")
    for a in C:
        print(a)


def transpose():
    for i in range(len(A)):
        for j in range(len(A[0])):
            C[i][j] = A[j][i]
    print("Transpose")
    for k in C:
        print(k)


def mult():
    for i in range(len(A)):
        for j in range(len(A[0])):
            for k in range(len(B)):
                C[i][j] += A[i][k] + B[k][j]
    print("Multiplication")
    for a in C:
        print(a)


A = []
B = []
C = []

r1 = int(input("Enter number of rows: "))
c1 = int(input("Enter number of columns: "))

for i in range(r1):
    D = []
    for j in range(c1):
        D.append(int(input(f"Enter A{[i]}{[j]} ")))
    A.append(D)
print("Matrix A")
for k in A:
    print(k)

r2 = int(input("Enter number of rows: "))
c2 = int(input("Enter number of columns: "))

for i in range(r2):
    E = []
    for j in range(c2):
        E.append(int(input(f"Enter B{[i]}{[j]} ")))
    B.append(E)
print("Matrix B")
for k in B:
    print(k)

for i in range(r2):
    F = []
    for j in range(c2):
        F.append(0)
    C.append(F)
print("Matrix C")
for k in C:
    print(k)

while True:
    print('''
    ------ ------ ------ ------ ------ MENU ------ ------ ------ ------ ------ 

    1. Enter 1 for addition of two matrices
    2. Enter 2 for subtraction of two matrices
    3. Enter 3 for multiplication of two matrices
    4. Enter 4 for Transpose of a matrix
    5. Enter 5 to Exit
    ''')
    choice = int(input("Enter you choice:"))
    if choice == 1:
        print("Addition of two matrices:",add())
    elif choice == 2:
        print("Subtraction of two matrices:", sub())
    elif choice == 3:
        print("Multiplication of two matrices:", mult())
    elif choice == 4:
        print("Transpose of matrix is:",transpose())
    elif choice == 5:
        print("Thank you!!!")
        break
    else:
        print("Enter a valid choice")
