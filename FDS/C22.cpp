#include<iostream>
#include<string>
using namespace std;

class node{
public:
    int roll;
    node *next;
};

class SEclass{
public:
    node* head;

    SEclass(){
        head = NULL;
    }
    node* create(int n);
    void display(node *);
    node* union1(SEclass X, SEclass Y);
    node* intersection(SEclass X, SEclass Y);
    node* difference(SEclass X, SEclass Y);
};

node* SEclass::create(int n){
    node *p;
    for (int i=0;i<n;i++){
        if(head == NULL){
            head = new node;
            cout<<"Enter Roll No. of Student: ";
            cin>>head->roll;
            head->next=NULL;
            p=head;
        }
        else{
            p->next = new node;
            p=p->next;
            cout<<"Enter Roll No. of student: ";
            cin>>p->roll;
            p->next=NULL;
        }
    }
    return head;
}

void SEclass::display(node *head){
    node *p;
    cout<<"\nRoll of Students are: \n";
    for(p=head;p!=NULL;p=p->next){
        cout<<p->roll<<"\t";
    }
}

node* SEclass::union1(SEclass X,SEclass Y){
    node *p,*q,*r,*s,*t,*p1,*q1;
    p = X.head;
    q = Y.head;
     for (p1=p;p1!=NULL;p1=p1->next){
         for(q1=q;q1!=NULL;q1=q1->next){
             if (q1->roll == p1->roll){
                 if (head==NULL){
                     head=new node;
                     head->roll=p1->roll;
                     head->next=NULL;
                     r=head;
                 }else{
                     r->next=new node;
                     r=r->next;
                     r->roll=p1->roll;
                     r->next=NULL;
                 }
                 p=p->next;
             }
         }
     }
     p = X.head;
     q = Y.head;
     for(p1=p;p1!=NULL;p1=p1->next){
         int flag = 0;
         for(q1=q;q1!=NULL;q1=q1->next){
             if (p1->roll == q1->roll){
                 flag=1;
             }
         }
         if(flag==0){
             if (head==NULL){
                     head=new node;
                     head->roll=p1->roll;
                     head->next=NULL;
                     r=head;
             }else{
                     r->next=new node;
                     r=r->next;
                     r->roll=p1->roll;
                     r->next=NULL;
             }
          
         }
     }
     q = X.head;
     p = Y.head;
     for(p1=p;p1!=NULL;p1=p1->next){
         int flag = 0;
         for(q1=q;q1!=NULL;q1=q1->next){
             if (p1->roll == q1->roll){
                 flag=1;
             }
         }
         if(flag==0){
             if (head==NULL){
                     head=new node;
                     head->roll=p1->roll;
                     head->next=NULL;
                     r=head;
             }else{
                     r->next=new node;
                     r=r->next;
                     r->roll=p1->roll;
                     r->next=NULL;
             }
          
         }
     }
     return head;
 }

node* SEclass::intersection(SEclass X, SEclass Y){
    node *p,*q,*p1,*q1,*r;
    p = X.head;
    q = Y.head;
    for (p1=p;p1!=NULL;p1=p1->next){
        for(q1=q;q1!=NULL;q1=q1->next){
            if (q1->roll == p1->roll){
                if (head==NULL){
                    head=new node;
                    head->roll=p1->roll;
                    head->next=NULL;
                    r=head;
                }else{
                    r->next=new node;
                    r=r->next;
                    r->roll=p1->roll;
                    r->next=NULL;
                }
                p=p->next;
            }
        }
    }
    return head;
}

node* SEclass::difference(SEclass X, SEclass Y){
    node *p,*q,*p1,*q1,*r;
    p = X.head;
    q = Y.head;
    for(p1=p;p1!=NULL;p1=p1->next){
        int flag = 0;
        for(q1=q;q1!=NULL;q1=q1->next){
            if (p1->roll == q1->roll){
                flag=1;
            }
        }
        if(flag==0){
            if (head==NULL){
                    head=new node;
                    head->roll=p1->roll;
                    head->next=NULL;
                    r=head;
            }else{
                    r->next=new node;
                    r=r->next;
                    r->roll=p1->roll;
                    r->next=NULL;
            }
           
        }
    }
    return head;
}

int main(){
    SEclass A,B,U,L,K,M,N,O;
int a,b,c;
   
    node *p,*q,*head1,*head2,*head3;
    
cout<<"Enter Total no. of students: ";
cin>>a;
head3=U.create(a);
cout<<"Enter no. of students like vanilla ";
cin>>b;
head1=A.create(b);
cout<<"Enter no. of students like butterscotch ";
cin>>c;
head2=B.create(c);

    cout<<"\nVanilla:";
    A.display(head1);
    cout<<"\nButterscotch:";
    B.display(head2);
    cout<<"\nUniversal:";
    U.display(head3);
    int choice;
    while (true){
        cout<<"\n----  MENU  ----\n";
        cout<<"Enter: \n1. Number of students who like both vanilla and butterscotch"
        "\n2. Number of students who like either vanilla or butterscotch but not both"
        "\n3. Number of students who like neither vanilla nor butterscotch \n4.Exit\n";
        cin>>choice;
        switch (choice)
        {
            case 1: cout<<"\nNumber of students who like both vanilla" 
                    " and butterscotch: ";L.display(L.intersection(A,B));;break;

            case 2: cout<<"\nNumber of students who like either vanilla" 
                    " or butterscotch but not both: ";
                        M.difference(A,B);
                        N.difference(B,A);
                        O.display(O.union1(M,N));break;

            case 3: cout<<"Number of students who like neither vanilla nor "
            "butterscotch";K.display(K.difference(U,O));break;

            case 4: cout<<"\nThank you!!!";exit(0);

            default:cout<<"\nInvalid Choice\n";
        }
    }
    return 0; 
}
