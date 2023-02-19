#include<iostream>

#pragma pack(1)

using namespace std;

template<class T>
struct snode
{
    T data;
    struct snode * next;
};
template<class T>
struct dnode
{
    T data;
    struct dnode * prev;
    struct dnode * next;
};

template<class T>
class SinglyLL
{
    public:
        struct snode <T> * First;

        SinglyLL();
        void InsertFirst(T);
        void InsertLast(T);
        void InsertAtPos(T,int);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int);

        void Display();
        int Count();

        int SerchFirstOcc(T);
        int SerchLastOcc(T);
    	int Freq(T);
        void Reverse();
        
};

template<class T>
class SinglyCLL
{
    public:
        struct snode<T> * First;
        struct snode<T> * Last;

        SinglyCLL();
        void InsertFirst(T);
        void InsertLast(T);
        void InsertAtPos(T,int);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int);

        void Display();
        int Count();

        int SerchFirstOcc(T);
        int SerchLastOcc(T);
    	int Freq(T);
};

template<class T>
class DoublyLL
{
    public:
        struct dnode<T> * First;

        DoublyLL();
        void InsertFirst(T);
        void InsertLast(T);
        void InsertAtPos(T,int);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int);

        void Display();
        int Count();

        int SerchFirstOcc(T);
        int SerchLastOcc(T);
    	int Freq(T);
        void Reverse();
};

template<class T>
class DoublyCLL
{
    public:
        struct dnode<T> * First;
        struct dnode<T> * Last;

        DoublyCLL();
        void InsertFirst(T);
        void InsertLast(T);
        void InsertAtPos(T,int);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int);

        void Display();
        int Count();

        int SerchFirstOcc(T);
        int SerchLastOcc(T);
    	int Freq(T);
};
template<class T>
class Queue
{
    public:
        struct node<T> * First;
        int iCount;

        Queue();

        bool isStackEmpty();
        void enQueue(T no);
        int deQueue();
        void Display();
};

class Stack
{
    public:
        struct node<T> * First;
        int iCount;

        Stack();

        bool isStackEmpty();
        void Push(T no);
        T Pop();
        void Display();
};

template<class T>
SinglyLL<T>::SinglyLL()
{
    First = NULL;
}
template<class T>
void SinglyLL<T>::InsertFirst(T no)
{
    struct snode<T> * newn=new snode<T>;
    newn->data=no;
    newn->next=NULL;

    if(First==NULL)
    {
        First=newn;
    }
    else
    {
        newn->next=First;
        First=newn;
    }
}
template<class T>
void SinglyLL<T>::InsertLast(T no)
{
    struct snode<T> * newn=new snode<T>;
    struct snode<T> * temp = NULL;
    newn->data=no;
    newn->next=NULL;

    if(First==NULL)
    {
        First=newn;
    }
    else
    {
        temp=First;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newn;

    }
}
template<class T>
void SinglyLL<T>::DeleteFirst()
{
    struct snode<T> * = NULL;

    if(First==NULL)
    {
        return;
    }
    else if((First)->next==NULL)
    {
        delete(First);
        First = NULL;
    }
    else
    {
        temp = First;
        First = (First)->next;
        delete(temp);
        
    }
}
template<class T>
void SinglyLL<T>::DeleteLast()
{
    struct snode<T> * temp = NULL;

    if(First == NULL)
    {
        return;
    }
    else if((First)->next == NULL)
    {
        delete(First);
        First = NULL;
    }
    else
    { 
        temp = First;  
        while(temp->next->next != NULL)
        {
            temp = temp->next;
        }
        delete(temp->next);
        temp->next = NULL;
    }
}
template<class T>
void SinglyLL<T>::InsertAtPos(T no,int ipos)
{
    int counter = Count();
    struct snode<T> * temp = NULL;
    struct snode<T> * newn = NULL;
    int i = 0;
 
    if(ipos == 1)
    {
        InsertFirst(no);
    }
    else if(ipos == (counter+1))
    {
        InsertLast(no);
    }
    else
    {
        temp = First;
        newn = new struct node<T>;
        newn->data = no;
        newn->next = NULL;

        for(i=1 ;i< ipos-1;i++)
        {
            temp = temp->next;
        }
        
        newn->next = temp->next;
        temp->next= newn;
    }
}
template<class T>
void SinglyLL<T>::DeleteAtPos(int ipos)
{
    int i = 1;
    struct snode<T> * temp1 = NULL;
    struct snode<T> * temp2 = NULL;

    if(ipos == 1)
    {
        DeleteFirst();
    }
    else if (ipos == (Count()))
    {
        DeleteLast();
    }
    else
    {
        temp1 = First; 
        for(i == 1;i < ipos-1;i++)
        {
            temp1 = temp1->next;
        }
        temp2 = temp1->next;
        temp1->next = temp2->next;
        delete(temp2);
    }
}
template<class T>
void SinglyLL<T>::Display()
{
   struct snode<T> * temp=First;
   
    while(temp!=NULL)
    {
        cout<<"|"<< temp->data<<" |->";
        temp=temp->next;
    }
   cout<<"NULL"<<"\n";

}
template<class T>
int SinglyLL<T>::Count()
{
    struct snode<T> * temp=First;
    int iCnt=0;

    while(temp!=NULL)
    {
        iCnt++;
        temp=temp->next;
    }
    return iCnt;

}
template<class T>

SinglyCLL<T>::SinglyCLL()
{
    First=NULL;
    Last=NULL;
}
template<class T>
void SinglyCLL<T>::InsertFirst(T no)
{
    struct snode<T> * newn=new struct snode<T>;
    newn->data=no;
    newn->next=NULL;

    if((First)==NULL && (Last)==NULL)
    {
        First=Last=newn;
    }
    else
    {
        newn->next=First;
        First=newn;
    }
    Last->next=newn;
}
template<class T>
void SinglyCLL<T>::InsertLast(T no)
{
    struct snode<T> * newn=new struct snode<T>;
    newn->data=no;
    newn->next=NULL;

    if((First)==NULL && (Last)==NULL)
    {
        First=Last=newn;
    }
    else
    {
       Last->next=newn;
       Last=newn;
    }
    Last->next=newn;
}
template<class T>
void SinglyCLL<T>::DeleteFirst()
{
    if(First==NULL && Last==NULL)
    {
        return;
    }
    else if(First==Last)
    {
        delete(First);
        First=Last=NULL;
    }
    else
    {
        First=(First)->next;
        delete((Last)->next);
        Last->next=First;
    }
}
template<class T>
void SinglyCLL<T>::DeleteLast()
{
    struct snode<T> * temp=NULL;
   
    if(First==NULL && Last==NULL)
    {
        return;
    }
    else if(First==Last)
    {
        delete(First);
        First=Last=NULL;
    }
    else
    {
        temp = First;  
        while(temp->next->next != (Last)->next)
        {
            temp = temp->next;
        }
        Last = temp;
        delete(temp->next);
        Last->next = First;

    }
}
template<class T>
void SinglyCLL<T>::InsertAtPos(T no,int ipos)
{
    int snodeCnt=Count();
    int iCnt=0;
    struct snode<T> * temp = NULL;
    struct snode<T> * newn = NULL;

    if(ipos==1)
    {
        InsertFirst(no);
    }
    else if(ipos==(snodeCnt+1))
    {
        InsertLast(no);
    }
    else
    {
        temp=First;
        newn = new struct snode<T>;
        newn->data=no;
        newn->next=NULL;

        for(iCnt=1;iCnt<ipos-1;iCnt++)
        {
            temp=temp->next;        
        }
        newn->next=temp->next;
        temp->next=newn;
    }
}
template<class T>
void SinglyCLL<T>::DeleteAtPos(int ipos)
{
    int snodeCnt=Count();
    int iCnt=0;
    struct snode<T> * temp1=First;
    struct snode<T> * temp2=NULL;

    if(ipos==1)
    {
        DeleteFirst();
    }
    else if(ipos==(snodeCnt))
    {
        DeleteLast();
    }
    else
    {
        for(iCnt=1;iCnt<ipos-1;iCnt++)
        {
            temp1=temp1->next;        
        }
        temp2=temp1->next;
        temp1->next=temp2->next;
        delete(temp2);
    }
}
template<class T>
void SinglyCLL<T>::Display()
{
   struct snode<T> * temp=First;
   if((First)==NULL && (Last)==NULL)
    {
        cout<<"Empty link list\n";
        return;
    }
    cout<<"Elements of linkedlist are :"<<"\n";
    do
    {
        cout<<"|"<< temp->data<<" |->";
        temp=temp->next;
    }while(temp!=Last->next);
    
   cout<<"\n";

}
template<class T>

int SinglyCLL<T>::Count()
{
    struct snode<T> * temp=First;
    int iCnt=0;
    if((First)==NULL && (Last)==NULL)
    {
        cout<<"Empty link list\n";
        return 0;
    }
   
    do
    {
        iCnt++;
        temp=temp->next;
    }while(temp!=Last->next);
    return iCnt;

}
template<class T>
class DoublyLL
{
    public:
        struct dnode<T> * First;

        DoublyLL();
        void InsertFirst(T);
        void InsertLast(T);
        void InsertAtPos(T,int);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int);

        void Display();
        int Count();
};
template<class T>
DoublyLL<T>::DoublyLL()
{
    First=NULL;
}
template<class T>
void DoublyLL<T>::InsertFirst(T no)
{
    struct dnode<T> * newn=new struct dnode<T>;
    newn->data=no;
    newn->prev=NULL;
    newn->next=NULL;

    if(First==NULL)
    {
        First=newn;
    }
    else
    {
        newn->next=First;
        (First)->prev=newn;
        First=newn;
    }
}
template<class T>
void DoublyLL<T>::InsertLast(T no)
{
    struct dnode<T> * newn=new struct dnode<T>;
    struct dnode<T> * temp = NULL;
    newn->data=no;
    newn->prev=NULL;
    newn->next=NULL;

    if(First==NULL)
    {
        First=newn;
    }
    else if((First)->next==NULL)
    {
        newn->next=First;
        (First)->prev=newn;
        First=newn;
    }
    else
    {
        temp = First;

        while(temp->next!=NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
        newn->prev = temp;
    }
}
template<class T>
void DoublyLL<T>::DeleteFirst()
{
    if(First==NULL)
    {
        return;
    }
    else if((First)->next==NULL)
    {
        delete(First);
        First=NULL;
    }
    else
    {
        First=First->next;
        delete(First->prev);
        First->prev=NULL;
    }
}
template<class T>
void DoublyLL<T>::DeleteLast()
{
    struct dnode<T> * temp = NULL;
    if(First==NULL)
    {
        return;
    }
    else if(First->next==NULL)
    {
        delete(First);
        First=NULL;
    }
    else
    {
        temp=First;
        while(temp->next->next!=NULL)
        {
            temp=temp->next;
        }
        delete(temp->next->next);
        temp->next=NULL;
    }
}
template<class T>
void DoublyLL<T>::InsertAtPos(T no,int ipos)
{
    int iCounter=0;
    iCounter=Count();
    int iCnt=0;
    struct dnode<T> * temp;
    
    if(ipos==1)
    {
        InsertFirst(no);
    }
    else if(ipos==(iCounter+1))
    {
        InsertLast(no);
    }
    else
    {
        temp=First;
        struct dnode<T> * newn=new struct dnode<T>;
        newn->data=no;
        newn->prev=NULL;
        newn->next=NULL;

        for(iCnt=1;iCnt<ipos-1;iCnt++)
        {
            temp=temp->next;
        }
        newn->next=temp->next;
        temp->next->prev=newn;
        newn->prev=temp;
        temp->next=newn;
    }
}
template<class T>
int DoublyLL<T>::Count()
{
    int iCnt=0;
    struct dnode<T> * temp=First;
    //cout<<"Number of dnode in linked list are : ";

    while(temp!=NULL)
    {
        iCnt++;
        temp=temp->next;
    }

    return iCnt;
}
template<class T>
void DoublyLL<T>::DeleteAtPos(int ipos)
{
    int iCounter=0;
    iCounter=Count();
    int iCnt=0;
    struct dnode<T> * temp1 = NULL;
    struct dnode<T> * temp2 = NULL;
    
    if(ipos==1)
    {
        DeleteFirst();
    }
    else if(ipos==(iCounter))
    {
        DeleteLast();
    }
    else
    {
        temp1=First;

        for(iCnt=1;iCnt<ipos-1;iCnt++)
        {
            temp1=temp1->next;
        }
        temp2=temp1->next;
        temp1->next=temp2->next;
        temp2->next->prev=temp1;
        delete(temp2);
    }
}
template<class T>
void DoublyLL<T>::Display()
{
    //cout<<"Elements in linked list are :"<<"\n";
    struct dnode<T> * temp=First;

    while(temp != NULL)
    {
        cout<<"|"<< temp->data << " |<=>";
        temp = temp->next;
    }
    cout<<"NULL"<<"\n";
}
template<class T>
DoublyCLL<T>::DoublyCLL()
{
    First=NULL;
    Last=NULL;
}
template<class T>
void DoublyCLL<T>::InsertFirst(T no)
{
    struct dnode<T> * newn=new struct dnode<T>;
    newn->data=no;
    newn->prev=NULL;
    newn->next=NULL;

    if(First==NULL && Last==NULL)
    {
        First=Last=newn;
    }
    else
    {
        newn->next=First;
        First->prev=newn;
        First=newn;
    }
    First->prev=Last;
    Last->next=First;
}
template<class T>
void DoublyCLL<T>::InsertLast(T no)
{
    struct dnode<T> * newn=new struct dnode<T>;
    newn->data=no;
    newn->prev=NULL;
    newn->next=NULL;

    if(First==NULL && Last==NULL)
    {
        First=Last=newn;
    }
    else
    {
        Last->next=newn;
        newn->prev=Last;
        Last=newn;
    }
    First->prev=Last;
    Last->next=First;
}
template<class T>
void DoublyCLL<T>::DeleteFirst()
{
    if(First==NULL && Last==NULL)
    {
        return;
    }
    else if(First==Last)
    {
        delete(First);
        First=NULL;
        Last=NULL;
    }
    else
    {
        First=First->next;
        delete(Last->next);
        First->prev=Last;
        Last->next=First; 
    }
}
template<class T>
void DoublyCLL<T>::DeleteLast()
{
    if(First==NULL && Last==NULL)
    {
        return;
    }
    else if(First==Last)
    {
        delete(First);
        First=NULL;
        Last=NULL;
    }
    else
    {
        Last=Last->prev;
        delete(Last->next);
        First->prev=Last;
        Last->next=First; 
    }
}
template<class T>
void DoublyCLL<T>::InsertAtPos(T no,int ipos)
{
    int inodeCnt=Count();
    int iCnt=0;
    struct dnode<T> * temp = NULL;
    struct dnode<T> * newn = NULL;

    if(ipos==1)
    {
        InsertFirst(no);
    }
    else if(ipos==(inodeCnt+1))
    {
        InsertLast(no);
    }
    else
    {
        temp=First;
        newn=new struct dnode<T>;
        newn->data=no;
        newn->next=NULL;
        newn->prev=NULL;

        for(iCnt=1;iCnt<ipos-1;iCnt++)
        {
            temp=temp->next;
        }
        newn->next=temp->next;
        temp->next->prev=newn;
        newn->prev=temp;
        temp->next=newn;
    }
}
template<class T>
int DoublyCLL<T>::Count()
{
    int iCnt=0;
    struct dnode<T> * temp=First;

    if(First==NULL && Last==NULL)
    {
        cout<<"Empty link list\n";
        return 0;
    }
    
    do
    {
        iCnt++;
        temp=temp->next;
    }while(temp!=Last->next);
    return iCnt;
}
template<class T>
void DoublyCLL<T>::DeleteAtPos(int ipos)
{
    int idnodeCnt=Count();
    int iCnt=0;
    struct dnode<T> * temp = NULL;

    if(ipos==1)
    {
        DeleteFirst();
    }
    else if(ipos==(idnodeCnt))
    {
        DeleteLast();
    }
    else
    {
        temp=First;

        for(iCnt=1;iCnt<ipos-1;iCnt++)
        {
            temp=temp->next;
        }
        temp->next=temp->next->next;
        delete(temp->next->prev);
        temp->next->prev=temp;        
    }
}
template<class T>
void DoublyCLL<T>::Display()
{
    struct dnode<T> * temp=First;

    if(First==NULL && Last==NULL)
    {
        cout<<"Empty link list\n";
        return;
    }
    cout<<"Elements of linkedlist are :"<<"\n";
    do
    {
        cout<<"|"<< temp->data<<" |<=>";
        temp=temp->next;
    }while(temp!=Last->next);
    
}
template<class T>
Queue<T>::Queue()
{
    First=NULL;
    iCount=0;
}
template<class T>
bool Queue<T>::isStackEmpty()
{
    if(iCount==0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
template<class T>
void Queue<T>::enQueue(T no)  //InsertLast
{
    struct node<T> * newn=new snode<T>;
    newn->data=no;
    newn->next=NULL;

    if(First==NULL)
    {
        First=newn;
    }
    else
    {
        struct node<T> * temp=First;

        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newn;
    }
    iCount++;

    cout<<"Get pushed in Stack Successfully \n";
}
template<class T>
int Queue<T>::deQueue()//DeleteFirst
{
    if(First==NULL)
    {
        cout<<"Unable to pop element as stack is empty"<<"\n";
        return -1;
    }
    else
    {
        int value=First->data;
        struct node<T> * temp=First;

        First=First->next;
        delete(temp);

        iCount--;

        return value;
    }
}
template<class T>
void Queue<T>::Display()
{
    if(First==NULL)
    {
        cout<<"Stack is Empty "<<"\n";
    }
    else
    {
        struct node<T> *temp=First;

        while(temp!=NULL)
        {
            cout<<"| "<<temp->data<<"| ->";
            temp=temp->next;
        }
        cout<<"NULL"<<"\n";
    }
}
template<class T>
Stack<T>::Stack()
{
    First=NULL;
    iCount=0;
}
template<class T>
bool Stack<T>::isStackEmpty()
{
    if(iCount==0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
template<class T>
void Stack<T>::Push(T no)  //InsertFirst
{
    struct node<T> * newn=new snode<T>;
    newn->data=no;
    newn->next=NULL;

    if(First==NULL)
    {
        First=newn;
    }
    else
    {
        newn->next=First;
        First=newn;
    }
    iCount++;

    cout<<"Get pushed in Stack Successfully \n";
}
template<class T>
T Stack<T>::Pop()//DeleteFirst
{
    if(First==NULL)
    {
        cout<<"Unable to pop element as stack is empty"<<"\n";
        return -1;
    }
    else
    {
        T value=First->data;
        struct node<T> * temp=First;

        First=First->next;
        delete(temp);

        iCount--;

        return value;
    }
}
template<class T>
void Stack<T>::Display()
{
    if(First==NULL)
    {
        cout<<"Stack is Empty "<<"\n";
    }
    else
    {
        struct node<T> *temp=First;

        while(temp!=NULL)
        {
            cout<<"| "<<temp->data<<"| ->";
            temp=temp->next;
        }
        cout<<"NULL"<<"\n";
    }
}
template< class T>
void SinglyLL<T>::Reverse()
{
    struct node<T> *Previous;
    struct node<T>*Next;
    struct node<T>*Current;

    Previous = NULL;
    Next = NULL;
    Current = First;

    while(Current != NULL)
    {
        Next = Current->next;
        Current->next =Previous;
        Previous =Current;

        Current = Next;
    }
    First = Previous;
}
template< class T>
void DoublyLL<T>::Reverse()
{
    struct node<T> *Previous;
    struct node<T>*Next;
    struct node<T>*Current;

    Previous = NULL;
    Next = NULL;
    Current = First;

    while(Current != NULL)
    {
        Next = Current->next;
        Current->next =Previous;
        Previous =Current;

        Current = Next;
    }
    First = Previous;
}
template< class T>
int SinglyLL<T>::SerchFirstOcc(T No)
{
    int counter =0,iPos=0;
    struct node<T> * temp = First;

    while(temp != NULL)
    {
        if(temp->data == No)
        {
            iPos = counter;
            break;
        }
        temp = temp->next;
        counter++;
    }
    return iPos;
}
template< class T>
int SinglyLL<T>::SerchLastOcc(T No)
{
    int counter =0,iPos=0;
    struct node<T> * temp = First;

    while(temp != NULL)
    {
        if(temp->data == No)
        {
            iPos = counter;
            
        }
        temp = temp->next;
        counter++;
    }
    return iPos;
}
template< class T>
int SinglyLL<T>::Freq(T No)
{
    int counter =0;
    struct node<T> * temp = First;

    while(temp != NULL)
    {
        if(temp->data == No)
        {
            counter++;
            
        }
        temp = temp->next;
        
    }
    return counter;
}
template< class T>
int DoublyLL<T>::SerchFirstOcc(T No)
{
    int counter =0,iPos=0;
    struct node<T> * temp = First;

    while(temp != NULL)
    {
        if(temp->data == No)
        {
            iPos = counter;
            break;
        }
        temp = temp->next;
        counter++;
    }
    return iPos;
}
template< class T>
int DoublyLL<T>::SerchLastOcc(T No)
{
    int counter =0,iPos=0;
    struct node<T> * temp = First;

    while(temp != NULL)
    {
        if(temp->data == No)
        {
            iPos = counter;
            
        }
        temp = temp->next;
        counter++;
    }
    return iPos;
}
template< class T>
int DoublyLL<T>::Freq(T No)
{
    int counter =0;
    struct node<T> * temp = First;

    while(temp != NULL)
    {
        if(temp->data == No)
        {
            counter++;
            
        }
        temp = temp->next;
        
    }
    return counter;
}
template< class T>
int SinglyCLL<T>::SerchFirstOcc(T No)
{
    
    int counter =0,iPos=0;
    struct node<T> * temp = First;

    if(First == NULL && Last == NULL)
    {
        cout<<"Empty linked list \n";
        return -1;
    }

    do
    {
        if(temp->data == No)
        {
            iPos = counter;
            break;
        }
        counter++;
        temp = temp->next;
    }while(temp != Last->next);

    
    return iPos;
    
}
template< class T>
int SinglyCLL<T>::SerchLastOcc(T No)
{
    int counter =0,iPos=0;
    struct node<T> * temp = First;

    if(First == NULL && Last == NULL)
    {
        cout<<"Empty linked list \n";
        return -1;
    }

    do
    {
        if(temp->data == No)
        {
            iPos = counter;
            
        }
        counter++;
        temp = temp->next;
    }while(temp != Last->next);

    
    return iPos;
}
template< class T>
int SinglyCLL<T>::Freq(T No)
{
    int counter =0;
    struct node<T> * temp = First;

    if(First == NULL && Last == NULL)
    {
        cout<<"Empty linked list \n";
        return -1;
    }

    do
    {
        if(temp->data == No)
        {
            counter++;
            
        }
        
        temp = temp->next;
    }while(temp != Last->next);
    
    return counter;
    
}
template< class T>
int DoublyCLL<T>::SerchFirstOcc(T No)
{
    
    int counter =0,iPos=0;
    struct node<T> * temp = First;
    if(First == NULL && Last == NULL)
    {
        cout<<"Empty linked list \n";
        return -1;
    }
    do
    {
        if(temp->data == No)
        {
            iPos = counter;
            break;
        }
        counter++;
        temp = temp->next;
    }while(temp != Last->next);
    
    return iPos;
    
}
template< class T>
int DoublyCLL<T>::SerchLastOcc(T No)
{
    int counter =0,iPos=0;
    struct node<T> * temp = First;

    if(First == NULL && Last == NULL)
    {
        cout<<"Empty linked list \n";
        return -1;
    }
    do
    {
        if(temp->data == No)
        {
            iPos = counter;
            
        }
        counter++;
        temp = temp->next;
    }while(temp != Last->next);
 
    return iPos;
}
template< class T>
int DoublyCLL<T>::Freq(T No)
{
    int counter =0;
    struct node<T> * temp = First;

    if(First == NULL && Last == NULL)
    {
        cout<<"Empty linked list \n";
        return -1;
    }

    do
    {
        if(temp->data == No)
        {
            counter++;
            
        }
        
        temp = temp->next;
    }while(temp != Last->next);
    
    return counter;
    
}

int main()
{ 
    return 0;
}
