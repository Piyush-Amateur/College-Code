b = []
c = []
f = []
n = int(input("Enter total number of students : "))

# For students who play badminton
# Append elements in list b [Who play badminton]
b_count = int(input("Enter the number of students who play badminton : "))
for i in range(0, b_count, 1):
    a = int(input("Enter the Roll number of students : "))
    b.append(a)

# For students who play cricket
# Append elements in list c [ Who play cricket ]
c_count = int(input("Enter the number of students who play cricket : "))
for i in range(0, c_count, 1):
    x = int(input("Enter the Roll number of students : "))
    c.append(x)

# For students who play football
# Append elements in list f [Who play football ]
f_count = int(input("Enter the number of students who play football : "))
for i in range(0, f_count, 1):
    y = int(input("Enter the Roll number of students : "))
    f.append(y)

    # To display Total number of students and list of students who play badminton cricket and football
    print("Total students are : ", n)
    print("The number of students who play badminton are : ", b)
    print("The number of students who play  are cricket : ", c)
    print("The number of students who play football are : ", f)

    # For option a
    # For students who play both cricket and badminton
    # To get elements which are common in both b and c
    # temp_1 is copy of list c

    temp_1 = []
    for i in c:
        temp_1.append(i)

    b_c = []  # Union of students who play badminton and cricket

    # temp_2 is copy of list b
    temp_2 = []
    for i in b:
        temp_2.append(i)

    for i in temp_1:  # loop 1 copy list of c
        for j in b:  # loop 2 list of b
            if i == j:  # if elements in b and c match append in list b_c [union list]
                b_c.append(i)
            else:
                pass  # else pass
    print("The number of player who play both cricket and badminton are : ", b_c)

    # For the students who play either cricket or badminton but not the both
    # To remove common elements found in b and c list and take union of what's left in both lists

    for i in b_c:  # loop1 for union list of b and c
        for j in temp_1:  # loop 2 for copy list of c
            if i == j:  # if elements in union list and c are same remove from temp_1(copy of c)
                temp_1.remove(j)
            else:
                pass  # else pass

    for i in b_c:  # loop 1 for union list of b and c
        for j in temp_2:  # loop 2 for copy list of b
            if i == j:  # if elements in union list and b are same then remove from temp_2(copy of b)
                temp_2.remove(j)
            else:
                pass
    b__c = []  # empty list of students who play either cricket or badminton but not both

    # append the required libst in b__c list
    for i in temp_1:
        b__c.append(i)

    for i in temp_2:
        b__c.append(i)

    print("The number of students who play either cricket or badminton but not both are ", b__c)

    # For students who neither play cricket nor badminton
    # Remove the students who play cricket and badminton from the list of football players
    temp_3 = []  # copy list of football players
    for i in f:
        temp_3.append(i)

    for i in b:  # remove cricket players from temp_3
        for j in temp_3:
            if i == j:
                temp_3.remove(i)

    for i in c:  # remove badminton players from temp_3
        for j in temp_3:
            if i == j:
                temp_3.remove(i)

    print("The number of students who play neither cricket nor badminton are : ", temp_3)

    # For students who play cricket and football but not badminton
    # From the list of students who play cricket and football subtract badminton players
    f_c = []  # For students playing cricket and badminton
    for i in c:
        for j in f:
            if i == j:
                f_c.append(i)

    for i in f_c:  # subtracting badminton players from f_c
        for j in b:
            if i == j:
                f_c.remove(i)

    print("The number of students playing cricket and football but not badminton are : ", f_c)