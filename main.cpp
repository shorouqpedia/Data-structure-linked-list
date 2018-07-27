#include <iostream>
using namespace std;

struct Student
{
    string F_name,L_name ;
    int ID;
    int Age;
    float GPA;

};


class DoubleLinkedList
{
   private:struct node
    {
        Student data;
        node *next;
        node *prev;
    }*L;
    private: void fillnode(node *p,Student x);

    public: int ListDouble (Student x); //Done
    public: int InsertOrderd (Student x); //Done
    public: void Display(); //done
    public: int SearchById (int x); //done
    public: int SearchByFn (string x); //done
    public: int SearchByLn (string x); //done
    public: int SearchByGPA (int x); //done
    public: int Del(int x); //done
    public: int print(int x); //done
    public: void destroy ();

};

void DoubleLinkedList::fillnode(node* p,Student x)
{
    p->data.Age=x.Age;
    p->data.GPA=x.GPA;
    p->data.ID=x.ID;
    p->data.F_name=x.F_name;
    p->data.L_name=x.L_name;
}

int DoubleLinkedList::ListDouble(Student x)
{
    node* p;
    p= new node;
    if (p==NULL)
        return 0;
    fillnode(p,x);

    p->next=NULL;
    p->prev=NULL;
    L=p;
    return 1;

}

int DoubleLinkedList::InsertOrderd(Student x)
{
    node* p ,*q,*s;
    p= new node;
    if (p==NULL) return 0;

    fillnode(p,x);

    q=L;
    //at front
    if (x.ID < q->data.ID)
    {
        p->next=q;
        p->prev=NULL;
        q->prev=p;
        L=p;

        return 1;
    }

    q=L;
    s=L;
// isn't at last
    while (q->next!=NULL)
    {
        if(x.ID < q->data.ID)
        {
            p->next=q;
            p->prev=q->prev;
            q->prev->next=p;
            q->prev=p;
            return 1;
        }
        q=q->next;
        s=q->prev;
    }

    //at last
    if(x.ID > q->data.ID)
    {
        p->next=NULL;
        p->prev=q;
        q->next=p;
        return 1;
    }

}

void DoubleLinkedList::Display()
{
    node* q;
    q=L;
    while(q!=NULL)
    {
        cout<<"Student Info is "<< q->data.F_name<<" "<<q->data.L_name <<", ID is "<< q->data.ID <<", GPA is "<< q->data.GPA<<", Age is "<< q->data.Age<<endl;
        q=q->next;
    }
}

int DoubleLinkedList::SearchById (int x)
{
    node *q;
    q=L;
    while (q!=NULL)
    {
        if (x==q->data.ID) return 1;
        q=q->next;
    }
    return 0;
}

int DoubleLinkedList::SearchByFn(string x)
{
    node *q;
    q=L;
    while (q!=NULL)
    {
        if (x==q->data.F_name) return 1;
        q=q->next;
    }
    return 0;
}

int DoubleLinkedList::SearchByLn(string x)
{
    node *q;
    q=L;
    while (q!=NULL)
    {
        if (x==q->data.L_name) return 1;
        q=q->next;
    }
    return 0;
}

int DoubleLinkedList::SearchByGPA(int x)
{
    node *q;
    q=L;
    while (q!=NULL)
    {
        if (x==q->data.GPA) return 1;
        q=q->next;
    }
    return 0;
}

int DoubleLinkedList::Del( int x)
{
    node* q;
    q=L;

    //first node occured
    if (x==q->data.ID)
        {
            L=q->next;
            q->next->prev=NULL;
            q->next=NULL;
            delete q;
            return 1;
        }

    while (q->next!=NULL)
    {
        if (x==q->data.ID)
        {
            q->next->prev=q->prev;
            q->prev->next=q->next;
            q->next=q->prev=NULL;
            delete q;
            return 1;
        }
        q=q->next;
    }
    //at the rear
    if (x==q->data.ID)
    {
        q->prev->next=NULL;
        q->prev=NULL;
        delete q;
        return 1;
    }
    return 0;
}

int DoubleLinkedList::print( int x)
{
     node *q;
    q=L;
    while (q!=NULL)
    {
        if (x==q->data.ID)
        {
        cout<<"Student Info is "<< q->data.F_name<<" "<<q->data.L_name <<", ID is "<< q->data.ID <<", GPA is "<< q->data.GPA<<" Age is "<< q->data.Age<<endl;
        return 1;
        }
        q=q->next;
    }
    return 0;

}

void DoubleLinkedList::destroy()
{
    node *q;
    q=L;
    while(q->next!=NULL){q=q->next;}
    while(q!=L)
    {
        q=q->prev;
        delete q->next;
    }
    L=NULL;
}


int main()
{
    DoubleLinkedList l;
    Student a;

    int x,y;
    float p;
    string z;

    cout<<"Welcom , insert Info of your first student"<<endl;
        cout<<"First name   ";
        cin>>a.F_name;
        cout<<"Last name    ";
        cin>>a.L_name;
        cout<<"GPA   ";
        cin>>a.GPA;
        cout<<"Age   ";
        cin>>a.Age;
        cout<<"ID    ";
        cin>>a.ID;
        l.ListDouble(a);


    while (x!=9)
    {
        cout<<"1 : insert new student."<<endl;
        cout<<"2 : Search about student by ID ."<<endl;
        cout<<"3 : Search about student by First Name ."<<endl;
        cout<<"4 : Search about student by Last Name ."<<endl;
        cout<<"5 : Search about student By GPA ."<<endl;
        cout<<"6 : Delete student by ID ."<<endl;
        cout<<"7 : Print informations of student by ID ."<<endl;
        cout<<"8 : Destroy The list ."<<endl;
        cout<<"9 : Exit ."<<endl;

        cin >>x;
switch (x)
{
    case 1:
    {
        cout<<"First name   ";
        cin>>a.F_name;
        cout<<"Last name    ";
        cin>>a.L_name;
        cout<<"GPA   ";
        cin>>a.GPA;
        cout<<"Age   ";
        cin>>a.Age;
        cout<<"ID    ";
        cin>>a.ID;

        l.InsertOrderd(a);
    }
    break;

    case 2:
    {
       cout<<"Enter the Id you would know if it found";
       cin>>y;
       if (l.SearchById(y)==1)
        cout<<"Found"<<endl;
       else
        cout<<"Not Found"<<endl;
    }
    break;

    case 3:
    {
       cout<<"Enter the First name you would know if it found";
       cin>>z;
       if (l.SearchByFn(z)==1)
        cout<<"Found";
       else
        cout<<"Not Found";
    }
    break;

    case 4:
    {
       cout<<"Enter the Last name you would know if it found";
       cin>>z;
       if (l.SearchByLn(z)==1)
        cout<<"Found";
       else
        cout<<"Not Found";

    }
    break;

    case 5:
    {
       cout<<"Enter the GPA you would know if it found";
       cin>>p;
       if (l.SearchByGPA(p)==1)
        cout<<"Found";
       else
        cout<<"Not Found";

    }
    break;

    case 6:
    {
        cout<<"ID : ";
        cin>>y;
        if (l.Del(y)==1)
            cout<<"Done";
        else
            cout<<"Error";
    }
    break;

    case 7:
    {
        cout<<"ID : ";
        cin>>y;
        if(l.print(y)==0)
            cout<<"can't found the student";
        else
            l.print(y);
    }
    break;

    case 8:
        l.destroy();
    break;

    default : cout<< "Thanks for your visit ^_^ "<<endl;
    break;
}
    }


    return 0;
}
