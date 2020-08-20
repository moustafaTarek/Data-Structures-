#include <iostream>
using namespace std;

struct node
{
    int id ;
    node *next;

};

class linked_list
{
private :
    struct node *head ;
    int counter ;
    struct node wrongNode;

public :
    linked_list()
    {
        head=NULL;
        counter=0;
        wrongNode.id=0;
        wrongNode.next=NULL;
    }
    void insert_first(node d)
    {
        /*
        node *ptr;
        ptr=new node;
        ptr ->next=head;
        head=ptr;
        *ptr=d;   // node d is sent to the function without putting its address so if we wrote the code like this the linked list will fail
        */
        node *ptr;
        ptr=new node;
        *ptr=d;
        ptr ->next=head;
        head=ptr;

    }
    void print_list()
    {
        int i=1;
        node *ptr;
        for(ptr=head ; ptr!=NULL ; ptr=ptr->next)
        {
           // cout<<" The address of the node number : "<<i <<" = "<<ptr<< endl;
            cout<<" The ID of the node number : "<< i << " = "<<ptr->id<<endl;
            i++;
        }
    }
    void insert_last(node d)
    {
        if(head==NULL)
        {
            insert_first(d);
        }
        else
        {
            node *ptr;
            for(ptr=head;ptr->next!=NULL;ptr=ptr->next)
            {
                continue;
            }
            /*
            ptr->next= new node ;
            ptr=ptr->next;
            *ptr=d;
            ptr->next=NULL;
            */

            node *temp=new node;
            *temp=d;
            temp->next= ptr->next; // ptr->next = NULL;
            ptr->next=temp;
        }
    }
    node return_first(void)
    {
        if(head == NULL){cout<<" linked list is empty "<<endl; return wrongNode ;}
        return *head ;

    }
    node return_index(int index)
    {
        if(head==NULL)
        {
           return wrongNode;
        }
        else if(index==1 )
        {
            return *head ;
        }
        else
        {
            node*ptr=head;
            int k;
            for(k=1;k<index;k++)  // for (k=0 ; k<index-1 ; k++)
            {
                if(ptr->next==NULL) { cout<<"the index is not found"<<endl; return wrongNode ;}
                ptr=ptr->next;
            }

            return *(ptr);

        }

    }
    void delete_first(void)
    {
        if(head==NULL){ cout<<" linked_list is empty"<<endl; }
        else
        {
        node *ptr=head;
        head=ptr->next;
        delete ptr;
        }
    }
    void delete_last(void)
    {
        if(head == NULL) {cout<<" linked_list is empty"<<endl;}
        else if (head->next==NULL){delete_first();}
        else
        {
            node *ptr;
            for(ptr=head ; ptr->next->next!=NULL ;ptr=ptr->next)
            {
                continue;
            }
            node *temp ;

            temp=ptr->next;
            ptr->next=temp->next;  // temp->next = NULL
            delete temp ;

        }

    }
    void delete_index(int index)
    {
        if(head==NULL){cout<<" the linked list is empty"<<endl;}
        else if(index == 1)
        {
            delete_first();
        }
        else
        {
            node*ptr=head;
            int k ;
            for(k=1;k<index-1;k++)
            {
                if(ptr->next==NULL){ cout<<" wrong index , linked list is shorter than that length"<<endl; break;}
                ptr=ptr->next;
            }
            node *temp = ptr->next ;
            ptr->next=ptr->next->next;
            delete temp ;
        }
    }
    void delete_ID(int ID )
    {
        bool found =false;
        if(head == NULL) { cout<<" linked list is empty u can't delete "<<endl ;}
        else if(head->id == ID) { delete_first();}
        else
        {
            node *ptr;
            for(ptr=head ; ptr->next!=NULL ; ptr=ptr->next)
            {
                if(ptr->next->id ==ID)
                {
                   found =true ;
                   ptr->next = ptr->next->next;
                   delete ptr->next;
                   break;
                }
            }
            if(found == false)
            {
                cout<<"you entered wrong id , please try again" << endl ;
            }
        }


    }
    node search_ID(int ID)
    {
        bool found=false;
        if(head==NULL){cout<<"linked list is empty"<<endl ;}
        else if(head->id == ID){return_first(); }
        else
        {
            node *ptr;
            for(ptr=head ; ptr->next!=NULL ; ptr=ptr->next)
            {
                if(ptr->next->id == ID)
                {
                    found=true;
                    return *(ptr->next);
                    break;
                }
            }
            if(found == false)
            {
                cout<<" you entered wrong ID"<<endl;
                return wrongNode ;
            }
        }
    }
    int get_counter(void)
    {
        if(head==NULL){return 0 ;}
        counter=0;
        node*ptr;
        for(ptr=head ; ptr!=NULL ; ptr=ptr->next)
        {
            counter++;
        }
        return counter ;

    }

};

int main()
{
    int i ,x ;
    linked_list link1 ;
    node n1;

    cout<<" ****************************************************************** "<<endl;
    cout<<" the number of nodes is : "<<link1.get_counter()<<endl;
    cout<<" ****************************************************************** "<<endl;
    n1.id=5;
    link1.insert_last(n1);
    n1.id=6;
    link1.insert_last(n1);
    n1.id=7;
    link1.insert_last(n1);
    n1.id=8;
    link1.insert_last(n1);

    cout<<" ****************************************************************** "<<endl;
    link1.print_list();
    cout<<" ****************************************************************** "<<endl;

    cout<<" ****************************************************************** "<<endl;
    cout<<" the number of nodes is : "<<link1.get_counter()<<endl;
    cout<<" ****************************************************************** "<<endl;
    /*link1.delete_first();
    link1.delete_last();
    link1.delete_last();*/

    link1.delete_index(2);
    cout<<" i deleted the second index"<<endl;

    cout<<" ****************************************************************** "<<endl;
    link1.print_list();
    cout<<" ****************************************************************** "<<endl;

    cout<<" ****************************************************************** "<<endl;
    cout<<" the number of nodes is : "<<link1.get_counter()<<endl;
    cout<<" ****************************************************************** "<<endl;


    cout<<" i deleted the node which has ID = 7"<<endl;
    link1.delete_ID(7);
    cout<<" ****************************************************************** "<<endl;
    link1.print_list();
    cout<<" ****************************************************************** "<<endl;

    cout<<" ****************************************************************** "<<endl;
    cout<<" the number of nodes is : "<<link1.get_counter()<<endl;
    cout<<" ****************************************************************** "<<endl;

    cout<<" i searched for node which has id = 5 "<<endl;

    cout<<" ****************************************************************** "<<endl;
    cout<<"The result of searching by ID is  :" << link1.search_ID(5).id<<endl;
    cout<<" ****************************************************************** "<<endl;


    cout<<" ****************************************************************** "<<endl;
    n1=link1.return_index(1);
    cout<<"searching by index for first index: " <<n1.id<<endl;
    cout<<" ****************************************************************** "<<endl;

    cout<<" ****************************************************************** "<<endl;
    n1=link1.return_index(2);
    cout<<"searching by index for second index:" <<n1.id<<endl;
    cout<<" ****************************************************************** "<<endl;

    cout<<" ****************************************************************** "<<endl;
    n1=link1.return_index(3);
    cout<<"searching by index for third index: : " <<n1.id<<endl;
    cout<<" ****************************************************************** "<<endl;

    cout<<" ****************************************************************** "<<endl;
    n1=link1.return_index(4);
    cout<<"searching by index for fourth index::" <<n1.id<<endl;
    cout<<" ****************************************************************** "<<endl;

    cout<< " return the first node : "<< link1.return_first().id << endl;

    return 0 ;
}
