m=[]
def student():
    n=int(input("Enter the number of students:"))
    for i in range (n):
        a=int(input("Enter the marks of students:"))
        m.append(a)
    print(m)
student()

def absent():
    count=0
    for i in range(len(m)):
        if m[i]==-1:
            count+=1
    print("Number of absent students:",count)
absent()

def avg_marks():
    sum=0
    count=0
    for i in range(len(m)):
        if m[i]!=-1:
            count+=1
            sum=sum+m[i]
            Avg=sum/count
    print("Total marks:",sum)
    print("Average marks:",Avg)
avg_marks()

def min_max():
    temp=m[0]
    for i in range(len(m)):
        if temp<m[i]:
            temp=m[i]
    print("maximum marks",temp)
    temp=m[0]
    for i in range(len(m)):
        if m[i]!=-1:
            if temp>m[i]:
                temp=m[i]
    print("minimum marks",temp)
min_max()

def high_freq():
    freq=[]
    for i in range(len(m)):
        if m[i]!=-1:
            freq.append(m.count(m[i]))
    print(freq)
    k=max(freq)
    print("Highest frequency=",k)
    print("Highest marks=",m[k])
high_freq()


while(True):
    print("1.The average score of class")
    print("2.Highest score and lowest score of class")
    print("3.Count of students who were absent for test")
    print("4.Display marks with hoghest frequency")
    print("Enter choice")
    choice=int(input())
    if(choice==1):
        avg_marks()
    if(choice==2):
        min_max()
    if(choice==3):
        absent()
    if(choice==4):
        high_freq()
    if(choice==5):
        exit()
