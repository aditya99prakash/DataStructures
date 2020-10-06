#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<string.h>
class node{
int data;
node*lcl;
node*rcl;
public:
node*ins(node*root,int n);
void print(node*root,int level);
node*newnode(int ele)
{
node*temp=new node;
temp->lcl=NULL;
temp->rcl=NULL;
temp->data=ele;
return temp;

}
};

node*node::ins(node*root,int n)
{       int ele;
node*temp;


root=newnode(n);
//cout<<root->data<<"ENTERED ";
cout<<"ENTER LEFT CHILD OF "<<root->data<<endl;
cin>>ele;
if(ele!=0)
root->lcl=ins(root->lcl,ele);
cout<<"ENTER RIGHT CHILD OF "<<root->data<<endl;
cin>>ele;
if(ele!=0)
root->rcl=ins(root->rcl,ele);
  return root;
}
void node::print(node*root,int level)
{    int i;
//cout<<root->lcl->data<<"X";
if (root==NULL)
return;
 print(root->rcl,level+1);
for(i=0;i<level;i++)
cout<<"   ";
cout<<root->data<<endl;
print(root->lcl,level+1);

}

void main()
{
clrscr();
node s;
node*root=NULL;
root=s.ins(root,1);
cout<<endl;

s.print(root,1);
getch();
}