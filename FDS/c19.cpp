#include<iostream>
#include<string>
using namespace std;

class node{
public:
    int prn;
    string name;
    node *next;
};

class list{
    node *head, *p;
public:
    list(){
        head = NULL;
    }
    node* create();
    void add_beg();
    void add_end();
    void add_mid();
    void del_beg();
    void del_end();
    void del_mid();
    void count();
    void display();
    void concatenate(list A,list B);
    void option();
};

node* list::create(){
    int no;
    string nam;
    cout<<"Enter PRN: ";
    cin>>no;
    cout<<"Enter Name: ";
    cin>>nam;
    p = new node;
    p-> prn = no;
    p-> name = nam;
    p->next = NULL;
    return p; 
}

void list::add_beg(){
    if (head == NULL){
        head=create();
    }
    else{
        node *q;
        q=create();
        q->next=head;
        head=q;
    }
    cout<<"President added succesfully!!!\n";
}

void list::add_end(){
    node *q,*r;
    if (head == NULL){
        cout<<"Add President first";
    }
    else{
        for (q=head;q->next!=NULL;q=q->next);
        r=create();
        q->next=r;
        cout<<"Secretary added succesfully!!!\n";
    }
}

void list::add_mid(){
    node *q,*r;
    if (head == NULL || head->next == NULL){
        cout<<"First Add President and Secretary first\n";
    }
    else{
        r=create();
        for (q=head;q->next->next!=NULL;q=q->next);
        r->next=q->next;
        q->next=r;
        cout<<"Member added succesfully!!!\n";
    }
}

void list::del_beg(){
    node *q;
    if (head == NULL){
        cout<<"Presindent position is vacant\n";
    }
    else{
        q=head;
        head=q->next;
        delete q;
        cout<<"President deleted succesfully\n";
    }   
}

void list::del_end(){
    node *q,*r;
    if (head == NULL || head->next == NULL){
        cout<<"Secretary position is vacant\n";
    }
    else{
        for (q=head;q->next->next!=NULL;q=q->next);
        r=q->next;
        q->next=NULL;
        delete r;
        cout<<"Secretary deleted succesfully\n"; 
    } 
}

void list::del_mid(){
    int no;
    node *q,*r;
    if (head == NULL || head->next == NULL){
        cout<<"Member not present\n";
    }
    else{
        cout<<"Enter PRN: ";
        cin>>no;
        for(q=head;q->next->prn!=no && q->next->next!=NULL;q=q->next);
        if (q->prn!=no){
            cout<<"Member not present\n";
        }
        else{
            r=q->next;
            q->next=r->next;
            delete r;
            cout<<"Member deleted succesfully\n";
        }
    }
}

void list::count(){
    node *q;
    int cnt = 0;
    for(q=head;q!=NULL;q=q->next){
        cnt=cnt+1;
    }
    cout<<"Total number of members: "<<cnt;
}

void list::display(){
    node *q;
    cout<<"PRN No\tName\n";
    for(q=head;q!=NULL;q=q->next){
        cout<<q->prn<<"\t"<<q->name<<"\n";
    }
}

void list::concatenate(list A,list B){
    node *head1, *head2, *q;
    head = A.head;
    head2 = B.head;
    for(q=head;q->next!=NULL;q=q->next);
    q->next=head2;
}

void list::option(){
    int choice1,choice2;
    while (true){
        cout<<"\nEnter: \n1.Add \n2.Delete \n3.Total Members \n4.Display \n5.Previous Menu\n";
        cin>>choice1;
        switch(choice1){
            case 1:
                cout<<"\nEnter: \n1.Add President \n2.Add Secretary \n3.Add Member\n";
                cin>>choice2;
                switch(choice2){
                    case 1:add_beg();break;
                    case 2:add_end();break;
                    case 3:add_mid();break; 
                }
                break;
            case 2: 
                cout<<"\nEnter: \n1.Delete President \n2.Delete Secretary \n3.Delete Member\n";
                cin>>choice2;
                switch(choice2){
                    case 1:del_beg();break;
                    case 2:del_end();break;
                    case 3:del_mid();break;
                }
                break;
            case 3:count();break;
            case 4:display();break; 
            case 5:return;
            default:cout<<"\nInvalid Choice\n";
        }
    }
}

 
int main(){
    list A,B,C;
    int choice;
    while (true){
        cout<<"\n----  MENU  ----\n";
        cout<<"Enter: \n1.List A \n2.List B \n3.Concatenate \n4.Exit\n";
        cin>>choice;
        switch (choice)
        {
            case 1: cout<<"\nList A: ";A.option();break;
            case 2: cout<<"\nList B: ";B.option();break;
            case 3: C.concatenate(A,B);C.display();break;
            case 4: cout<<"\nThank you!!!";exit(0);
            default:cout<<"\nInvalid Choice\n";
        }
    }
    return 0;  
}
