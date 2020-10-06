#include <iostream.h>
#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
class queue{
int front,rear,a[20],ele,size;
public:

queue(){
front=rear=-1;
size=5;
}

void addq()
{                  int flag=0;
cout<<"INSERT ELEMENT \n";
cin>>ele;


if(front==rear+1||(front==0&&rear==size-1))
{
cout<<"OVERFLOW\n";
flag=1;
}
else if(front==-1)
  front=0;

 if(flag==0)
 {
rear=(rear+1)%size;
a[rear]=ele;
//cout<<rear;
  }
}

void delq()
{
if (front==-1)
 cout<<"QUEUE EMPTY ";
       else
if(front==rear)
front=rear=-1;

else if (front==-1)
	   front++;
  else
{
cout<<a[front]<<"BEING DELETED "<<endl;
	   cout<<front<<endl;
		front=(front+1)%size;
 }

}
void disp()
{int i;

if(front==-1)

{cout<<"QUEUE EMPTY\n";
}
else
if(rear>front)
{
     for(i=front;i<=rear;i++)
      cout<<a[i]<<" ";



}

else
{

for(i=0;i<=rear;i++)
cout<<a[i]<<" ";
for(i=front;i<size;i++)

cout<<a[i]<<" ";

}

}


}s;

void main()
{
clrscr();
int x;
while(1)
{
cout<<"\n1 to insert 2 to delete 3 to display ";
cin>>x;
switch(x)
{
case 1:s.addq();
break;
case 2:s.delq();
break;
case 3:s.disp();
break;
default:exit(0);


}
}

//getch();
}
