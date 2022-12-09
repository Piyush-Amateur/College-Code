
marks=[]
n=int(input("Enter the number of students whose marks are to be dispalyed : "))
print("Enter marks for",n, "students:")
for i in range(0,n):
    ele = int(input())
    marks.append(ele)
print("The marks of",n,"students are :")
print(marks)


# Function of Selelction Sort of elements

def Selection_Sort(marks):
    for i in range(len(marks)):

        #Find the minimum element in remaing unsorted array
        min_index = i
        for j in range(i+1,len(marks)):
            if marks[min_index] > marks[j]:
                min_index = j

        #Swap the minimum element with the first elemrnt
        marks[i],marks[min_index] = marks[min_index],marks[i]

    print("Marks of students after performing Selection Sort on the list :")
    for i in range(len(marks)):
        print(marks[i])
Selection_Sort(marks)

#Function of Bubble sort of elements

def Bubble_Sort(marks):
    n = len(marks)
    #Transverse through all array elements
    for i in range(n-1):
        #last i elements are already in place
        for j in range(0,n-i-1):

            #Transverse the array from 0 to n-i-1
            #Swap if the elements found is greater than the next elemets
            if marks[j] >  marks[j+1]:
                marks[j],marks[j+1] = marks[j+1],marks[j]

    print("Marks of elements after performing Bubble Sort on list :")
    for i in range(len(marks)):
        print(marks[i])
Bubble_Sort(marks)

#Fuction for displaying top five marks
def top_five_marks(marks):
    print("Top",len(marks),"Marks are :")
    print(*marks[::-1],sep="\n")
top_five_marks(marks)

flag=1
while flag==1:
    print("1.Selection Sort of marks")
    print("2.Bubble sort of the marks")
    print("3.EXIT")
    ch=int(input("\n\nEnter your choice(from 1 to 3) :"))

    if ch==1:
        Selection_Sort(marks)
        a=input("\nDo you want to display top marks from the list (yes/no) :")
        if a=='yes':
            top_five_marks(marks)
        else:
            print("\nThanks for using this program!")
            flag=0

    elif ch==2:
        Bubble_Sort(marks)
        a = input("\nDo you want to display top marks from the list (yes/no) :")
        if a == 'yes':
            top_five_marks(marks)
        else:
            print("\nThanks for using this program!")
            flag = 0

    elif ch==3:
        print("\nThanks for using this program!!")
        flag=0

    else:
        print("\nEnter a valid choice!!")
        print("\nThanks for using this program!!")
        flag=0

