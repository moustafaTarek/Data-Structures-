#include <iostream>
using namespace std;

struct node
{
    int id ;
    node *next;
    node *previous;
};



class double_linked_list
{
private :
    node *head;
    node *tail;
    node wrongnode;
    int counter;

public :
    double_linked_list(void)
    {
      head=NULL;
      tail=NULL;
      counter=0;
      wrongnode.id=0;
      wrongnode.next=NULL;
      wrongnode.previous=NULL;
    }
    void insert_first(node d)
    {
        node *ptr = new node; // open new node pointed to it by ptr
        *ptr=d; // put data in the new node
        ptr->previous=NULL;
        ptr->next=head;

        if(head != NULL) // u can't access a null pointer
        {
            head->previous=ptr;
        }
        if(head == NULL) // it means that its the first index in the list
        {
          tail = ptr;
        }
        head=ptr;

    }
    void insert_last(node d)
    {
        if(head == NULL){insert_first(d);}
        else
        {
            tail->next= new node ;
            *(tail->next)=d;
            tail->next->previous = tail;
            tail->next->next=NULL;
            tail=tail->next;
        }

    }
    node return_first(void)
    {
        if(head ==NULL){cout<<"linked list is empty , please try again later "<<endl;  return wrongnode ;}
        else
        {
            return *head ;
        }
    }
    node return_last(void)
    {
        if(head ==NULL){cout<< "linked list is empty , please try again later"<<endl ; return wrongnode;}
        else
        {
            return *tail ;
        }

    }

    void print_linst()
    {
      node *ptr;
      int i=1 ;
      for(ptr=head ; ptr!=NULL ; ptr=ptr->next)
      {
            cout<< " the data of node number :"<<i<<" = "<<(*ptr).id<<endl;
            i++;
            cout<<" the address of the node : "<<ptr<< " the next address : "<< ptr->next << " the previous address"<< ptr->previous << endl;
      }
      cout<<" THE head address is : "<<head<<endl;
      cout<<" THE tail address is : "<<tail<<endl;

    }
    int get_counter()
    {
        if(head==NULL){return 0;}
        counter=0;
        node *ptr;
        for(ptr=head ; ptr!=NULL ; ptr=ptr->next)
        {
            counter++;
        }
        return counter;
    }

    node return_index(int index)
    {
        if(head==NULL){cout<<"linked list is empty "<<endl; return wrongnode ;}
        else if(index == 1){return *head ;}

        else
        {
            int nodes_num = get_counter();
            int i;
            node *ptr;
            if(index <= nodes_num/2) // index is near for the head
            {
                ptr=head;
                for(i=1;i<index;i++)
                {
                    if(ptr->next==NULL){cout<<"the index is not found"<<endl; return wrongnode;}
                    ptr=ptr->next;

                }
                return *(ptr);

            }
            else if( index > nodes_num/2) // index is near for the tail
            {
                ptr=tail;
                for(i=nodes_num-index;i>0;i--)
                {
                    if(ptr->previous==NULL){cout<<"the index is not found"<<endl; return wrongnode;}
                    ptr=ptr->previous;

                }
                return *(ptr);

            }
        }


    }
    node return_ID(int ID)
    {
        bool found=false;
        if(head==NULL){cout<<"linked list is empty"<<endl ; return wrongnode ;}
        else if(head->id == ID){ return *head ; }
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
                return wrongnode ;
            }
        }

    }

    void insert_index(int index , node d)
    {
        if(head==NULL){insert_first(d);}
        else if(head->next==NULL){insert_last(d);}
        else
        {
            int nodes_num =get_counter();
            int i ;
            node *ptr;
            if(index <= nodes_num/2) // index is near for the head
            {
                ptr=head;
                for(i=1;i<index;i++)
                {
                    if(ptr->next==NULL){cout<<"the linked list is shorter than that index "<<endl; break; }
                    ptr=ptr->next;
                }
                node *temp = new node ;
                *temp=d;

                ptr->previous->next=temp;
                temp->previous=ptr->previous;
                temp->next=ptr;
                ptr->previous=temp;


            }
            else if( index > nodes_num/2) // index is near for the tail
            {
                ptr=tail;
                for(i=1;i<(nodes_num-index+2);i++)    //i=nodes_num-index;i>0;i--)
                {
                    if(ptr->previous == NULL){cout<<"the linked list is shorter than that index"<<endl; break;}
                    ptr=ptr->previous;
                }
                node *temp2 = new node ;
                *temp2=d;

                ptr->next->previous=temp2;
                temp2->next=ptr->next;
                temp2->previous=ptr;
                ptr->next=temp2;


            }


       }

    }
};
