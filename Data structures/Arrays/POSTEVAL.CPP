#include<iostream.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
class  conv{
char a[10];
int top;
char e1,e2;
int op1,op2,res;
public:
conv(){
top=-1;
       }
void push(char ele)
{
if(top==9)
cout<<"OVERFLOW ";
else
a[++top]=ele;


}
char pop()
{
if(top==-1)
cout<<"UNDERFLOW ";
return a[top--];
}
void disp()
{int i;
for(i=top;i>=0;i--)
 cout<<endl<<a[i]<<"X";
 cout<<endl;

}
void eval(char st[])
{
int i;
//strrev(st);
for(i=0;st[i]!='\0';i++)
{e1=st[i];

if(isdigit(e1))
 push(e1-'0');
else
{
    op2=pop();
    op1=pop();
    res=prec(op1,op2,e1);

push(res);

//cout<<op1<<" "<<op2<<" ;"<<res;
}


}

cout<<res;
}
char prec(char op1,char op2, char e1)
{
switch(e1)
{
case '+':return op1+op2;
break;
case '-':return op1-op2;
break;
case '*':return op1*op2;
break;
case '/':return op1/op2;

}

}


}s;

void main()
{ clrscr();
  char st[10];
  gets(st);
  s.eval(st);



getch();
}

