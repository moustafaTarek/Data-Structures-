#include <iostream>
#include<bits/stdc++.h>
using namespace std;


struct binaryTreeNode
{
    int info ;
    binaryTreeNode *leftChild;
    binaryTreeNode *rightChild;

};

class binaryTree
{
private :

    int MAX_height(int x , int y)
    {
        if(x>=y)
            return x;
        else
            return y;
    }
    binaryTreeNode * root ;

public :

    binaryTree(void)
    {
        root=NULL;
    }
    binaryTreeNode* getRoot(){
        return root;
    }

    void insertNode(int p)
    {
      binaryTreeNode *newNode;  // pointer to the new node that will be created
      binaryTreeNode *current;
      binaryTreeNode *trailCurrent;
      bool found;

      newNode = new binaryTreeNode ;
      if(newNode!=NULL)
      {

          newNode->info=p;
          newNode->leftChild=NULL;
          newNode->rightChild=NULL;


          if(root ==NULL)   // there is no nodes , tree is empty
          {
              root=newNode;
          }
          else
          {
              current =root;
              trailCurrent=NULL;
              found =false;

              while(current !=NULL && !found)
              {
                  trailCurrent=current;
                  if(current->info == newNode->info) //(newNode->info = p)     //if the item is already in the node , don't insert it again
                  {
                      found=true;
                  }
                  else if(current->info > newNode->info)  // if  the node of the current is bigger than the inserted one take the left root
                  {
                      current=current->leftChild;
                  }
                  else // if  the node of the current is smaller than the inserted one take the right root
                  {
                      current=current->rightChild;
                  }

              }

              if(found)
              {
                  cout<<"The information is already found , can't be inserted again"<<"\n";
              }
              else
              {
                  if(trailCurrent->info > newNode->info)
                  {
                      trailCurrent->leftChild=newNode;
                  }
                  else
                  {
                      trailCurrent->rightChild=newNode;
                  }

              }

          }

       }
    }

    int height(binaryTreeNode *p)
    {
        if(p==NULL)
        {
            return 0;
        }
        else
        {
            return 1+ MAX_height(height(p->leftChild),height(p->rightChild));
        }

    }
    void printInorder(binaryTreeNode *p)
    {
        if(p!=NULL)
        {
            printInorder(p->leftChild);
            cout<<p->info<<"\t";
            printInorder(p->rightChild);
        }

    }
    void printInorderNonRecursive(binaryTreeNode *root){
        binaryTreeNode *curr=root;
        stack<binaryTreeNode *>s;

        while(curr!=NULL || s.empty()==false){

            while(curr!=NULL){
                s.push(curr);
                curr=curr->leftChild;
            }
            curr=s.top();
            s.pop();
            cout<<curr->info<<"\t";
            curr=curr->rightChild;
        }
        cout<<"\n";
    }
    void printPreorder(binaryTreeNode *p)
    {
        if(p!=NULL)
        {
            cout<<p->info<<"\t";
            printPreorder(p->leftChild);
            printPreorder(p->rightChild);
        }
    }
    void printPreorderNonRecursive(binaryTreeNode *root){
        stack<binaryTreeNode*>s;
        binaryTreeNode * curr;
        s.push(root);

        while(!s.empty()){
            curr=s.top();
            s.pop();

            cout<<curr->info<<"\t";

            if(curr->rightChild != nullptr)
            s.push(curr->rightChild);
            if(curr->leftChild != nullptr)
            s.push(curr->leftChild);
        }

    }
    void printPostorder(binaryTreeNode *p)
    {
        if(p!=NULL)
        {
            printPostorder(p->leftChild);
            printPostorder(p->rightChild);
            cout<<p->info<<"\t";
        }

    }

    void deleteTree(binaryTreeNode  *p)
    {
        if(p!=NULL)
        {
            deleteTree(p->leftChild);
            deleteTree(p->rightChild);
            delete p;
            p=NULL;
        }
    }
    bool binarySearch_bool(int item)
    {
        if(root == NULL)
        {
            cout<<" The tree is empty , cant search in empty tree ";
            return false ;
        }

        else
        {
            bool found=false;
            binaryTreeNode *current=root;
            while(current!=NULL&& !found)
            {
                if(current->info == item)
                {
                    found=true;
                }
                else if(current->info > item)
                {
                    current=current->leftChild;
                }
                else
                {
                    current=current->rightChild;
                }

            } // end while

            return found;
        } // end else

    }
    int searchItem(int item)
    {
        binaryTreeNode *current ;
        bool found=false ;
        int  my_item;
        if(root == NULL)
        {
            cout <<" the tree is empty , the item is not found";
            return -1 ;
        }
        else
        {
            current = root ;

            while(current !=NULL )
            {
                if(current->info == item)
                {
                    found =  true ;
                }
                else if(current->info > item)
                {
                    current = current->leftChild;
                }
                else
                {
                    current = current->rightChild;
                }
            }
        }
        if(found==false)
        {
            cout<<" the item is  not found in the tree"<<"\n";
        }
        else if (found == true)
        {
            return item ;
        }
    }
    binaryTreeNode* NodeSearch(int Item)
    {
        binaryTreeNode * ro=root;
        while(ro->info != Item)
        {
            if(ro->info>Item)
            {
                ro=ro->leftChild;
            }
            else
            {
                ro=ro->rightChild;
            }
        }
    return ro;
    }


    void deleteItem( binaryTreeNode * p)
    {
        binaryTreeNode *current ;
        binaryTreeNode *trialCurrent;
        binaryTreeNode * temp ;         // use it for deleting nodes

        if(p == NULL)
        {
            cout<< " The tree is empty you can't delete any item from it " ;
        }
        else if (p->leftChild == NULL && p->rightChild == NULL)
        {
            temp = p;
            p=NULL;
            delete temp;
        }
        else if (p->leftChild == NULL)
        {
            temp = p;
            p = temp->rightChild;
            delete temp;
        }
        else if ( p->rightChild == NULL)
        {
            temp=p;
            p=temp->leftChild;
            delete temp;
        }
        else
        {

            current = p->leftChild;
            trialCurrent = NULL;

            while( current->rightChild != NULL)
            {
                trialCurrent = current;
                current = current->rightChild;
            }
            p->info = current->info ;

            if( trialCurrent == NULL)
            {
                p->leftChild=current->leftChild;
            }
            else
            {
                trialCurrent->rightChild = current->rightChild ;    // current = null ;
            }
            delete current;

        }

    }

    int numberOfNodes(binaryTreeNode * p)
    {

        if(p == NULL)
        {
            return 0 ;
        }
        else if(p->leftChild !=NULL && p->rightChild != NULL)
        {
            return 1 + numberOfNodes(p->leftChild) + numberOfNodes(p->rightChild);
        }
        else if(p->leftChild== NULL && p->rightChild!=NULL)
        {
            return 1+numberOfNodes(p->rightChild);
        }
        else if(p->leftChild!=NULL && p->rightChild==NULL)
        {
            return 1+numberOfNodes(p->leftChild);
        }
        else if (p->leftChild ==NULL && p->rightChild == NULL)
        {
            return 1;
        }

    }

    binaryTreeNode* findPredecessor(binaryTreeNode *p){
        binaryTreeNode *predecessor=nullptr;
        if(p!=nullptr)
        {
            if(p->leftChild !=nullptr )
            {
                predecessor=p->leftChild;
                while(predecessor->rightChild !=nullptr){
                    predecessor=predecessor->rightChild;
                }
                return predecessor;
            }
            else if(p->leftChild ==nullptr)
            {
                binaryTreeNode *first = root;

                while(first->info != p->info){

                    if(first->info < p->info){
                        predecessor=first;
                        first=first->rightChild;
                    }else{
                        first=first->leftChild;
                    }
                }
                return predecessor;
            }
        }
    }
    binaryTreeNode* findSuccessor(binaryTreeNode *p)
    {
        binaryTreeNode *predecessor=nullptr;
        if(p!=nullptr)
        {
            if(p->rightChild !=nullptr)
            {
                predecessor=p->rightChild;
                while(predecessor->leftChild !=nullptr){
                    predecessor=predecessor->leftChild;
                }
                return predecessor;
            }
            else if(p->rightChild == nullptr)
            {
                binaryTreeNode *first = root;
                while(first->info != p->info){

                    if(first->info > p->info){
                        predecessor=first;
                        first=first->leftChild;
                    }
                    else{
                        first=first->rightChild;
                    }
                }
            return predecessor;
          }

       }

    }
    void printAlPredecessor(binaryTreeNode *root1)
    {

        binaryTreeNode *ro = root1;
        binaryTreeNode *p;

        if(ro!=nullptr){
        p = findPredecessor(ro);
        cout<<"the predecessor of node "<<ro->info << " is :" ;
        if(p!=nullptr)
            cout<<p->info<<endl;
        else
            cout<<"No predecessor"<<"\n";
        if(ro->leftChild !=nullptr)
            printAlPredecessor(ro->leftChild);
        if(ro->rightChild != nullptr)
            printAlPredecessor(ro->rightChild);
        }

    }

     void printAlSuccessor(binaryTreeNode *root1){

        binaryTreeNode *ro = root1;
        binaryTreeNode *p;

        if(ro!=nullptr){
        p = findSuccessor(ro);
        cout<<"the Successor of node "<<ro->info << " is :" ;
        if(p!=nullptr)
            cout<<p->info<<endl;
        else
            cout<<"No successor"<<"\n";
        if(ro->leftChild !=nullptr)
            printAlSuccessor(ro->leftChild);
        if(ro->rightChild != nullptr)
            printAlSuccessor(ro->rightChild);
        }

    }

};
