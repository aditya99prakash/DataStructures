#include<iostream.h>
#include<conio.h>
#include<stdlib.h>

#include<string.h>


class node{
int data;
public:
node*lcl;
int d;
node*rcl;
node*next;
node*con;
node*ins(node*);
void disp2(node*);
void disp(node*,int level);
void inorder(node*);
void parent(node*,int,node*);
void preorder(node*);
void postorder(node*);
void lvlorder(node*);
int depth(node*);
void leaf(node*);
void ancestor(node*,int ele,node*);
};
void node::disp2(node*root)
{
if(root!=NULL)
 {// cout<<root->data;
  disp2(root->lcl);
   cout<<"  "<<root->data;
   disp2(root->rcl);

 }
}
void node:: leaf(node*root)
{ if(root!=NULL)
{
  leaf(root->lcl);
if(root->lcl==NULL&&root->rcl==NULL)
 cout<<root->data;
  leaf(root->rcl);

		 //C
}
}
int  node::depth(node*root)
{
 if(root==NULL)
return 0;
else{

int    ldepth=depth(root->lcl);
   int  rdepth=depth(root->rcl);

    if(ldepth>rdepth)
     return (ldepth+1);
    else return (rdepth+1);
    }
   }



void node::ancestor(node*root,int ele ,node*prev)
{
static int k=0;
static node*orig=new node;
if(k==0){
 orig=root;
k++; }
  con=new node;
  node*tmp=new node;
if(root!=NULL)
{ root->con=prev;
 ancestor(root->lcl,ele,root);

 if(root->data==ele)
{  for(tmp=root->con;tmp!=orig;tmp=tmp->con)
    cout<<tmp->data;
    cout<<orig->data;    }

//  k=0;
  ancestor(root->rcl,ele,root);

}
}
void node::lvlorder(node*root)
{
int f=-1,r=-1,d=1;
node*q[10];
q[++r]=root;
while(f!=r)
{
 root=q[++f];
 if(root!=NULL){
    cout<<root->data;
       if(root->lcl!=NULL)
      {	q[++r]=root->lcl;

      }

	if(root->rcl!=NULL)
	{
	q[++r]=root->rcl;
	 }
		}
		 }


}
void node::parent(node*root,int ele,node*prev)
{
 if(root!=NULL)
{

      parent(root->lcl,ele,root);
//       cout<<root->data<<"X";
      if(ele==root->data)
      {
       cout<<prev->data;
      //	prev->data=ele;
       return;
      }
   parent(root->rcl,ele,root);
    }

}
void node::postorder(node*root)
{int top=-1;  node*temp=new node;
node*s[20];
while(1)
{ //for(;root;root=root->rcl)
while(root!=NULL)
{
s[++top]=root->rcl;
s[++top]=root;
root=root->lcl;
}
if(root==NULL)
{root=s[top--];
 if(root->rcl!=NULL&&root->rcl==s[top])
  {temp=s[top--];
   s[++top]=root;
   root=temp;
  }  else{    if(root->data!=0)
    cout<<root->data<<"->";
    root=NULL;
  }

  if(top<0)
    break;
}

}

}
void node::preorder(node*root)
{
int top=-1;
node*s[10];
while(1)
{
for(;root;root=root->lcl)
{
cout<<root->data<<"->";
s[++top]=root;
}
if(top>=0)
root=s[top--];
else break;
root=root->rcl;




}


}
void node::inorder(node*ptr)
{    int top=-1;
   node*s[10];
//   ptr=root;
while(1)
{
for(;ptr!=NULL;ptr=ptr->lcl)
{
s[++top]=ptr;
}
if(top>=0)
{//1 cout<<ptr->data<<" X";
// cout<<endl<<top<<endl;
// cout<<s[top]->data;
ptr=s[top--];


}
else {   //getch();
break;
}
cout<<ptr->data<<"->";
ptr=ptr->rcl;

}
}





node*node::ins(node*root)
{char dir[10];
node*temp=new node;

cout<<"ENTER ELEMENT ";
cin>>temp->data;
temp->lcl=NULL;
temp->rcl=NULL;

if(root==NULL)
{
return temp;
}
 node*prev=NULL;
      node*curr=root;
cout<<"ENTER DIRECTION ";
cin>>dir;
for(int i=0;i<strlen(dir);i++)
{if(curr==NULL)
break;
prev=curr;
if(dir[i]=='L')
curr=curr->lcl;
else
curr=curr->rcl;
}
if(curr!=NULL||i!=strlen(dir))
{
cout<<"IMPOSSIBLE";
delete(temp);
return root;
}
if(dir[i-1]=='L')
prev->lcl=temp;
else prev->rcl=temp;
return root;




}

void node::disp(node*root,int level)
{int i;
if(root==NULL)
return ;
disp(root->rcl,level+1);
for(i=0;i<level;i++)
cout<<"  ";
cout<<root->data<<endl;
disp(root->lcl,level+1);


}
void main()
{clrscr();
int x;
node s;                           int ch;
node*root=NULL;
while(1)
{   cin>>x;
switch(x)
{
case 1:
       root=s.ins(root);

break;
case 2:cout<<endl;
 s.disp(root,0);
break;
case 3: s.inorder(root);
break;
case 4: s.preorder(root);
break;
case 5: s.postorder(root);
break;
case 6: cout<<"ENTER CHILD NODE ";
cin>>ch;
 s.parent(root,ch,NULL);
break;
case 7: s.lvlorder(root);
break;
case 8: s.ancestor(root,4,NULL);
break;
case 9:cout<< s.depth(root);
//1111cout<<s.d;
break;
case 10: s.leaf(root);
  break;
  case 11: s.disp2(root);
break;

default:exit(0);
}

}

}