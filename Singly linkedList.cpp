//Muhammad Khizar Irfan                             0248-BSCS-22
#include <iostream>
using namespace std;

class node
{
public:
    int value;
    node* pNextNode;
    node()
    {
        this->pNextNode=NULL;
        this->value=0;
    }
    node(int value)
    {
        this->value=value;
        pNextNode=NULL;
    }
};

class linkedList
{
public:
    node* pHead;               //acts as starting block
    linkedList()
    {
        pHead= nullptr;       //empty when linkedList object is created
    }
    ~linkedList()
    {
        node* temp;                   //this deconstructor working perfectly but try to use pHead through some other variables
        while(pHead!= nullptr)          //like temp1 etc just dont use pHead directly
        {
            temp=pHead;
            pHead=pHead->pNextNode;
            delete(temp);
        }
    }
    void add(int value)
    {
        node* newNode=new node(value); //new node to be added in the list
        if(pHead== nullptr)   //i.e of the list is empty
        {
            pHead=newNode;
        }
        else
        {
            node* temp=pHead;
            while(temp->pNextNode!=NULL)
            {
                temp=temp->pNextNode;
            }
            temp->pNextNode=newNode;     // since we are using pointers so for example if temp stores pHead then
                                            //whatever we do to temp occurs to pHead
        }
    }
    void printList()
    {
        node* temp = pHead;
        while(temp->pNextNode!=NULL)
        {
            cout<<temp->value<<endl;
            temp=temp->pNextNode;
        }
        cout<<temp->value<<endl;
    }
    void remove(int index)
    {
        int listLength=0;

        node* temp1=pHead;
        node* temp2=NULL;
        while(temp1->pNextNode!=NULL)       //counts the length
        {
            temp1=temp1->pNextNode;
            listLength++;
        }

        if(index==0)      //if i used 1 then the list would start from 1
        {
            if(pHead==nullptr) {
                cout << "list is already empty";
                return;
            }
            else
            {
                temp1=pHead;
                pHead=pHead->pNextNode;
                delete(temp1);
                return;
            }
        }

        if(index<=listLength)
        {
            temp1=pHead;
            while(index >0)
            {

                temp2=temp1;              //in this way at the end of this loop temp1 will be the node we want
                temp1=temp1->pNextNode;   // to delete and temp2 will be n-1 node(the node right behind)
                index--;
            }
            temp2->pNextNode=temp1->pNextNode;      //since node middle(n) node is removed so we change the
                                                    //pNextNode of n-1 node to n+1
            return;
        }
        else
        {
            cout<<"index out of bounds";
            return;
        }
    }

};

int main()
{
    linkedList* list=new linkedList();

    list->add(1);
    list->add(24);
    list->add(90);
    list->add(67);
    list->add(42);

    list->printList();

    cout<<"--------------------------------"<<endl;
    list->remove(4);

    list->printList();



}
