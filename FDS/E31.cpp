#include<iostream>
using namespace std;
#define SIZE 5
class dequeue
{

    int a[10],front,rear;

public:
    dequeue()
    {
        front=-1;
        rear=-1;
    }
    void add_at_beg(int);
    void add_at_end(int);
    void delete_fr_front();
    void delete_fr_rear();
    void display();
};

void dequeue::add_at_beg(int item)
{   
    int i;
    if(rear>=SIZE-1){
        cout<<"\nInsertion is not possible,overflow!!!!";
    }
    else{
        if (front==-1)
            front++;
        rear++;
        for(i=rear;i>0;i--)
        {
            a[i]=a[i-1];
        }
        a[i]=item;
    }
}

void dequeue::add_at_end(int item)
{
    if(rear>=SIZE-1){
        cout<<"\nInsertion is not possible,overflow!!!";
    }
    else{
        if(front==-1)
            front++;
        rear++;
        a[rear]=item;
    }
}

void dequeue::delete_fr_front()
{
    if(front==-1){
        cout<<"Dequeue is empty\n";
    }
    else{
        if(front==rear)
        {
            front=rear=-1;
        }
        else{
            cout<<"The deleted element is "<<a[front];
            front++;
        }
    }
}

void dequeue::delete_fr_rear()
{
    if(front==-1){
        cout<<"Dequeue is empty\n";
    }
    else{
        if(front==rear)
        {
            front=rear=-1;
        }
        else{
            cout<<"The deleted element is "<< a[rear];
            rear--;
        }
    }
}

void dequeue::display()
{   
    if ((front==-1)||(rear==-1)){
        cout<<"Dequeue is empty";
    }
    else{
        for(int i=front;i<=rear;i++){
            cout<<a[i]<<" ";    
        }
    }
    
}

int main()
{
    int c,item;
    dequeue d1;
    do
    {
        cout<<"\n\n****DEQUEUE OPERATION****\n";
        cout<<"\n1 Insert at beginning";
        cout<<"\n2 Insert at end";
        cout<<"\n3 Deletion from front";
        cout<<"\n4 Deletion from rear";
        cout<<"\n5 Display";
        cout<<"\n6 Exit";
        cout<<"\nEnter your choice:";
        cin>>c;

        switch(c)
        {
        case 1:
            cout<<"Enter the element to be inserted:";
            cin>>item;
            d1.add_at_beg(item);
            break;

        case 2:
            cout<<"Enter the element to be inserted:";
            cin>>item;
            d1.add_at_end(item);
            break;

        case 3:
            d1.delete_fr_front();break;

        case 4:
            d1.delete_fr_rear();break;

        case 5:
            d1.display();break;

        case 6:
            exit(0);break;

        default:
            cout<<"Invalid choice";break;
        }

    }while(c!=7);
    return 0;
}
