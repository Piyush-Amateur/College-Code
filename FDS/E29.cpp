#include <iostream>
#define MAX 10
using namespace std;

class queue{
public:
    int data[MAX];
    int r,f;

    queue(){
        r=-1;
        f=-1;
    }

    void enqueue();
    void dequeue();
    int empty();
    int full();
    void display();
};

void queue::enqueue(){
    if (full()){
        cout<<"Queue is overflow!!!\n";
    }
    else{
        if (f==-1)
            f++;
        r++;
        int x;
        cout<<"Enter data:  ";
        cin>>x;
        data[r]=x;
        cout<<"job added \n";
    }
}

void queue::dequeue(){
    if (empty()){
        cout<<"Queue is underflow!!!\n";
    }
    else{
        int x;
        x=data[f];
        f++;
        cout<<x<<" deleted\n";
    }
}

int queue::empty(){
    if(f==-1)
        return 1;
    return 0;
}

int queue::full(){
    if (r>=MAX)
        return 1;
    return 0;
}

void queue::display(){
    if (empty()){
        cout<<"Queue is underflow!!!\n";
    }
    else{
        for(int i=f;i<=r;i++){
        cout<<data[i]<<" ";
        }
    } 
}

int main(){ 
    queue obj;
    int ch;
    do{    
        cout<<"\n 1.Insert Job\n 2.Delete Job\n 3.Display\n 4.Exit\n Enter your choice : ";
        cin>>ch;
        switch(ch)
        {   
        case 1: obj.enqueue();break;
        case 2: obj.dequeue();break;
        case 3: obj.display();break;
        case 4: cout<<"\n Exiting Program.....";break;
        default:cout<<"Invalid Choice\n";
        }
    }while(ch!=4);
return 0;
}
