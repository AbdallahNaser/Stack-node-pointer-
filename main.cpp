#include <iostream>
#include <string>
using namespace std;

template<class t>
class stack{
    struct node{
    t item;
    node *next;
    };
    node*top,*cur;
public:
    stack(){
    top=NULL;
    }

    void push(t newItem)
    {

        node *newItemPtr = new node;
        if(newItemPtr==NULL)
        {
            cout<<"STACK push cannot allocate memory";
        }
        else{
            newItemPtr->item = newItem;
            newItemPtr->next=top;
            top=newItemPtr;
        }
    }

    bool isEmpty()
    {
        return top==NULL;
    }
    void pop(){
    if(isEmpty())
    {
        cout<<"stack is empty"<<"\n";
    }
    else
    {
        node*temp = top;
        top=top->next;
        temp = temp->next=NULL;
        delete temp;

    }
    }

    void pop(t&stackTop){
    if(isEmpty())
    {
        cout<<"stack is empty"<<"\n";
    }
    else
    {
        stackTop=top->item;

        node*temp = top;
        top=top->next;
        temp = temp->next=NULL;
        delete temp;

    }
    }

    void getTop(t&stackTop){
    if(isEmpty())
    {
        cout<<"stack is empty"<<"\n";
    }
    else
    {
        stackTop=top->item;

    }
    }
    void display(){
        cur=top;
        cout<<"[";
    while(cur!=NULL)
    {
        cout<<cur->item<<"  ";
        cur=cur->next;
    }
    cout<<"]\n";


}
};

int main()
{

    stack<string> SP;
    SP.push("Abdallah");
    SP.push("Ali");
    SP.push("Hello");
    SP.push("hero");
    SP.push("hi");

    SP.display();


    return 0;
}
