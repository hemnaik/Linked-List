//DOUBLY LINKED LIST //
//DATA STRUCTURE//
//AUTHOR-HEM.V.NAIK//
#include <iostream>
#include<conio.h>
#include<stdlib.h>
using namespace std;
struct node
{

     int data;
     struct node *nextlink,*previouslink;
}*head=NULL,*ptr=NULL,*current=NULL,*start=NULL,*newnode=NULL;
int choice,temp1,flag=0,key=0,update,max1=0,val,min1=0,pos,search1;
void create(void);
void traverse(struct node *temp);
void ascending(struct node *aa,struct node *bb);
void descending(struct node *aa,struct node *bb);
void insert_ending(struct node *temp,struct node *newnode);
void delete_ending(struct node *temp);
void insert_begining(void);
void delete_begining(void);
void updatenode(void);
int maximum(struct node *temp,int max1);
int minimum(struct node *temp,int min1);
int sizeoflinkedlist(struct node *temp,int key);
void delete_atany_position(void);
void insert_beforegiven_position(void);
void insert_aftergiven_position(void);
void searching(void);
int main()
{
    for(;;)
    {
          cout<<"1--->CREATE NODE"<<endl;
          cout<<"2--->TRAVERSE"<<endl;
          cout<<"3--->INSERTION FROM ENDING"<<endl;
          cout<<"4--->DELETION FROM ENDING"<<endl;
          cout<<"5--->INSERTION FROM BEGINING"<<endl;
          cout<<"6--->DELETION FROM BEGINING"<<endl;
          cout<<"7--->SORTING"<<endl;
          cout<<"8--->UPDATE NODE"<<endl;
          cout<<"9--->MAXIMUM & MINIMUM"<<endl;
          cout<<"10-->SIZE OF LIST"<<endl;
          cout<<"11-->DELETE AT ANY POSITION"<<endl;
          cout<<"12-->INSERTION AFTER GIVEN  POSITION"<<endl;
          cout<<"13-->INSERTION BEFORE GIVEN  POSITION"<<endl;
          cout<<"14-->SEARCHING"<<endl;
          cout<<"15-->EXIT"<<endl;
          cout<<"ENTER CHOICE:";
          cin>>choice;
          switch(choice)
          {
            case 1:
            create();
            break;
            case 2:
            if(head==NULL)
            {
                  cout<<"LIST IS EMPTY"<<endl;

            }
            else
            {
                  cout<<"TRAVERSE"<<endl;
                  traverse(head);
            }
            break;
            case 3:
                struct node *newnode;
                start=head;
                if(head==NULL)
                {
                      cout<<"LIST IS EMPTY"<<endl;
                }
                else
                {
                      newnode=(struct node*)malloc(sizeof(struct node));
                      cout<<"ENTER DATA:";
                      cin>>newnode->data;
                      insert_ending(head,newnode);
                      cout<<"DELETION FROM ENDING"<<endl;
                      traverse(head);

                }
                break;
            case 4:
                start=head;
                if(head==NULL)
                {
                      cout<<"LST IS EMPTY"<<endl;
                }
                else
                {
                      delete_ending(head);
                      cout<<"DELETION FROM ENDING"<<endl;
                      traverse(head);
                }
                break;
            case 5:
                insert_begining();
                break;
            case 6:
                delete_begining();
                break;
            case 7:
                struct node *aa,*bb;
                if(head==NULL)
                {
                     cout<<"LIST IS EMPTY"<<endl;
                }
                else
                {
                     cout<<"1--->ASCENDING ORDER"<<endl;
                     cout<<"2--->DESCENDING ORDER"<<endl;
                     cout<<"ENTER CHOICE:";
                     cin>>choice;
                     switch(choice)
                     {
                        case 1:
                        aa=head;
                        bb=head;
                        ascending(aa,bb);
                        cout<<"SORTED LIST"<<endl;
                        traverse(head);
                        break;
                        case 2:
                        aa=head;
                        bb=head;
                        descending(aa,bb);
                        cout<<"SORTED LIST"<<endl;
                        traverse(head);
                        break;
                        default:
                        cout<<"INVALID CHIOICE!!!"<<endl;
                     }

                }
                break;
            case 8:
               updatenode();
              break;
            case 9:
                if(head==NULL)
                {
                     cout<<"LIST IS EMPTY"<<endl;
                }
                else
                {
                     max1=0;
                     maximum(head,max1);
                     cout<<"MAXIMUM="<<maximum(head,max1)<<endl;
                     min1=maximum(head,max1);
                     minimum(head,min1);
                     cout<<"MINIMUM="<<minimum(head,min1)<<endl;
                }
                break;
            case 10:
                key=0;
                sizeoflinkedlist(head,key);
                cout<<"SIZE OF LIST="<<sizeoflinkedlist(head,key)<<endl;
                break;
            case 11:
                delete_atany_position();
                break;
            case 12:
                insert_aftergiven_position();
                break;
            case 13:
                insert_beforegiven_position();
                break;
            case 14:
                searching();
                break;
            case 15:
                exit(1);
                break;
            default:
                cout<<"INVALID CHOICE!!!"<<endl;
          }
    }
    return 0;
}
  void create(void)
  {
         ptr=(struct node*)malloc(1*sizeof(struct node));
         cout<<"ENTER DATA:";
         cin>>ptr->data;
         if(head==NULL)
         {
               current=ptr;
               head=ptr;
               current->nextlink=current->previouslink=NULL;
         }
        else
        {
             current->nextlink=ptr;
             ptr->previouslink=current;
             current=ptr;
             ptr->nextlink=NULL;
        }
  }
  void traverse(struct node *temp)
  {

            if(temp!=NULL)
            {
                  cout<<temp->data<<endl;
                  temp=temp->nextlink;
                  traverse(temp);
                  return;
            }
  }
  void ascending(struct node *aa,struct node *bb)
  {
      if(aa!=NULL)
      {

            if(bb!=NULL)
            {
                  if(aa->data<bb->data)
                  {
                        temp1=aa->data;
                        aa->data=bb->data;
                        bb->data=temp1;
                  }
                  bb=bb->nextlink;
                  ascending(aa,bb);
                  return;
            }
             bb=head;
             aa=aa->nextlink;
             ascending(aa,bb);
      }

  }
  void  descending(struct node *aa,struct node *bb)
  {
      if(aa!=NULL)
      {

            if(bb!=NULL)
            {
                  if(aa->data>bb->data)
                  {
                        temp1=aa->data;
                        aa->data=bb->data;
                        bb->data=temp1;
                  }
                  bb=bb->nextlink;
                  descending(aa,bb);
                  return;
            }
             bb=head;
             aa=aa->nextlink;
             descending(aa,bb);
      }

  }
  void insert_ending(struct node *temp,struct node *newnode)
  {
         if(temp->nextlink==NULL)
         {
             temp->nextlink=newnode;
             newnode->previouslink=temp;
             newnode->nextlink=NULL;
             head=start;
             return;
         }
         else
         {
              temp=temp->nextlink;
              insert_ending(temp,newnode);
         }
  }
  void delete_ending(struct node *temp)
  {
         if(temp->nextlink==NULL)
         {
              temp->previouslink->nextlink=NULL;
              temp->previouslink=NULL;
              temp->nextlink=NULL;
              free(temp);
              head=start;
              return;
         }
         else
         {
              temp=temp->nextlink;
              delete_ending(temp);
         }
  }
  void insert_begining(void)
  {
        start=head;
        if(head==NULL)
        {
              cout<<"LIST IS EMPTY"<<endl;
        }
        else
        {
           newnode=(struct node*)malloc(sizeof(struct node));
           cout<<"ENTER DATA:";
           cin>>newnode->data;
           head=newnode;
           newnode->previouslink=NULL;
           newnode->nextlink=start;
           start->previouslink=newnode;
           start=newnode;
           head=start;
           cout<<"INSERTION FROM BEGINING"<<endl;
           traverse(head);
        }
}
void delete_begining(void)
{
    struct node *x=NULL;
    start=head;
    if(head==NULL)
    {
          cout<<"LIST IS EMPTY"<<endl;
    }
    else
    {
          x=start;
          start=start->nextlink;
          x->nextlink=NULL;
          start->previouslink=NULL;
          free(x);
          head=start;
          cout<<"DELETION FRPM BEGINING"<<endl;
          traverse(head);
    }
}
void updatenode(void)
{
     struct node *t;
     if(head==NULL)
     {
           cout<<"LIST IS EMPTY"<<endl;
     }
     else
     {
           cout<<"ENTER VAL FOR UPDATION:";
           cin>>update;
           cout<<"ENTER VAL:";
           cin>>val;
           flag=0;
           for(t=head;t!=NULL;t=t->nextlink)
           {
                if(t->data==val)
                {
                     t->data=update;
                     flag=1;
                     break;
                }
           }
           if(flag==1)
           {
                cout<<"AFTER UPDATION"<<endl;
                traverse(head);
           }
           else
           {
                cout<<"UPDATING NOT POSSIBLE"<<endl;
           }
     }

}


int maximum(struct node *temp,int max1)
{
        if(temp==NULL)
        {
             return max1;
        }
        else
        {
            if(temp->data>max1)
            {
                 max1=temp->data;
            }
            temp=temp->nextlink;
            maximum(temp,max1);
        }

}
int minimum(struct node *temp,int min1)
{
        if(temp==NULL)
        {
            return min1;
        }
        else
        {
            if(temp->data<min1)
            {
                 min1=temp->data;
            }
            temp=temp->nextlink;
            minimum(temp,min1);
        }
}
int sizeoflinkedlist(struct node *temp,int key)
{
      if(temp==NULL)
      {
           return key;
      }
      else
      {
           key=key+1;
           temp=temp->nextlink;
           sizeoflinkedlist(temp,key);
      }
}
void delete_atany_position(void)
{

       struct node *kk=NULL,*jj=NULL,*ptr=NULL;
       start=head;
       if(head==NULL)
       {

             cout<<"LIST IS EMPTY"<<endl;
       }
       else
       {
             cout<<"ENTER POSITION FOR DELETION:";
             cin>>pos;
             key=1;
             flag=0;
             ptr=head;
             jj=ptr;
             for(ptr=head;ptr!=NULL;ptr=ptr->nextlink)
             {
                    if(pos==key)
                    {
                         kk=ptr->nextlink;
                         ptr->previouslink=NULL;
                         ptr->nextlink=NULL;
                         free(ptr);
                         jj->nextlink=kk;
                         kk->previouslink=jj;
                         head=start;
                         flag=1;
                         break;
                    }
                    else
                    {
                         key++;
                         jj=ptr;

                    }
             }
             if(flag==1)
             {
                   cout<<"DELETTION AT ANY POSITION"<<endl;
                   traverse(head);
             }
             else
             {
                   cout<<"DELETION NOT POSSIBLE"<<endl;
             }
       }
}
void insert_aftergiven_position(void)
{

      struct node *i,*j,*s,*x;
      if(head==NULL)
      {
          cout<<"LIST IS EMPTY"<<endl;
      }
      else
      {
            newnode=(struct node*)malloc(sizeof(struct node));
            cout<<"ENTER DATA:";
            cin>>newnode->data;
            cout<<"ENTER VAL:";
            cin>>val;
            flag=0;
            for(i=head;i!=NULL;i=i->nextlink)
            {
                   if(i->data==val)
                   {
                         flag=1;
                         break;
                   }
            }
            if(flag==1)
            {
                   if(start->data==val)
                   {
                       x=start;
                       start=start->nextlink;
                       x->nextlink=newnode;
                       newnode->previouslink=x;
                       newnode->nextlink=start;
                       start->previouslink=newnode;
                       start=x;
                       head=start;
                       cout<<"INSERTION AFTER GIVEN POSITION"<<endl;
                       traverse(head);
                   }
                   else
                   {
                       j=head;
                       s=j;
                       while(s->data!=val)
                       {
                             s=j;
                             j=j->nextlink;
                       }
                       s->nextlink=newnode;
                       newnode->previouslink=s;
                       newnode->nextlink=j;
                       j->previouslink=newnode;
                       cout<<"INSERTION AFTER GIVEN POSITION"<<endl;
                       traverse(head);
                   }
            }
            else
            {
                  cout<<"INSERTION NOT POSSIBLE"<<endl;
            }
      }
}
void insert_beforegiven_position(void)
{

      struct node *m,*n,*l;
      if(head==NULL)
      {
          cout<<"LIST IS EMPTY"<<endl;
      }
      else
      {
            newnode=(struct node*)malloc(sizeof(struct node));
            cout<<"ENTER DATA:";
            cin>>newnode->data;
            cout<<"ENTER VAL:";
            cin>>val;
            flag=0;
            for(m=head;m!=NULL;m=m->nextlink)
            {
                   if(m->data==val)
                   {
                         flag=1;
                         break;
                   }
            }
            if(flag==1)
            {
                   if(start->data==val)
                   {
                       head=newnode;
                       newnode->previouslink=NULL;
                       newnode->nextlink=start;
                       start->previouslink=newnode;
                       start=newnode;
                       head=start;
                       cout<<"INSERTION BEFORE GIVEN POSITION"<<endl;
                       traverse(head);
                   }
                   else
                   {
                       n=head;
                       l=n;
                       while(n->data!=val)
                       {
                             l=n;
                             n=n->nextlink;
                       }
                       l->nextlink=newnode;
                       newnode->previouslink=l;
                       newnode->nextlink=n;
                       n->previouslink=newnode;
                       head=start;
                       cout<<"INSERTION AFTER GIVEN POSITION"<<endl;
                       traverse(head);
                   }
            }
            else
            {
                  cout<<"INSERTION NOT POSSIBLE"<<endl;
            }
      }
}
void searching(void)
{

      struct node *p;
      if(head==NULL)
      {
            cout<<"LIST IS EMPTY"<<endl;
      }
      else
      {
           cout<<"ENTER SEARCH:";
           cin>>search1;
           flag=0;
           pos=1;
           for(p=head;p!=NULL;p=p->nextlink)
           {
                 if(p->data==search1)
                 {
                      flag=1;
                      break;
                 }
                 pos++;
           }
           if(flag==1)
            cout<<"DATA IS AT POSITION:"<<pos<<endl;
           else
            cout<<"DATA NOT FOUND"<<endl;
      }
}
