#include<iostream.h>
#include<conio.h>
#include<stdio.h>
class Stack{
char nm[10],e1,e2,postfix[20];
int p,p1,top,x;

 public:
 Stack()
 {top=-1;
 p=0;
 }
 char ret()
 {return nm[top];
 }
     void push(char ele)
     {if(top==9)
     cout<<"STACK FULL ";
     else
     {
     nm[++top]=ele;


     }


     }
     void disp()
     {
     int i;

     for(i=top;i>=0;i--)
	 cout<<nm[i]<<" ";
     }


char pop()
   {   if(top==-1)
	       return -1;
	       else
  return nm[ top--];
   }



int prec(char s)
{switch(s)
{case '+':
case '-':return 2;
break;
case '*':
case '/':return 3;
break;
case '(':return 1;
break;
default: return -1;
}
}

void conv(char infix[])
{int flag=0;
 for(int i=0;infix[i]!='\0';i++)
 {e2=infix[i];
switch(e2)
  {case '(':push(e2);
   break;
   case ')':
	     if(top!=-1)
	     {     e1=pop();
	     while(e1!='(')
	       { //      e1=pop();
	       postfix[p++]=e1;
		 e1=pop();
	       }
	       }
 break;
 case '+':
 case '-':
 case '*':
 case '/':  {

	//  cout<<e2<<" ";
	 p1=prec(e2);
	 e1=pop();
	// top++;
	   //if(top!=-1)
	  {//cout<<"INVOKED";
		 flag=0;
	  while(p1<=prec(e1))
	   {
	    postfix[p++]=e1;
   //	    cout<<postfix<<endl;
	    if(top!=-1)
	    e1=pop();

	    else
	    break;
	   }                    //end of while
	   if(p1>prec(e1))
	  {//cout<<"INVOKED";
	   push(e1);

	   }
	  }
	   push(e2);

	 //  cout<<endl<<i;
  //	  cout<<"STACK"; disp();cout<<endl;
    //	   cout<<endl;
	}
	   break;
	   default: postfix[p++]=e2;

  }
 }            //eoif

 while(top!=-1)
 {      x=pop();
 if(x!='(')
 postfix[p++]=x;
 }
   postfix[p]='\0';

 cout<<postfix;
}



  }s;


void main()
{clrscr();

int i;
char infix[20];
gets(infix);
s.conv(infix);
//s.disp();
	 getch();

}