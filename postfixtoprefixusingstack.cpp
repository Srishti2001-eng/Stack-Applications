#include<iostream>
#include<stack>

using namespace std;

bool isOperand(char c)
{
    if((c >= 'a' && c <='z')|| (c >='A' && c <='Z'))
    {
        return true;
    }
    else
    {
        return false;
    }
    
}

string PostfixToprefix(string postfix)
{
    stack <string> s;
    for(int i=0;i<postfix.length();i++)
    {
        if(isOperand(postfix[i]))
        {
            string op(1,postfix[i]);
            s.push(op);
        }
        else 
        {
           string op1=s.top();
           s.pop();
           string op2=s.top();
           s.pop();
           s.push(postfix[i]+op2+op1);
        }
    }
    return s.top();
}

int main()
{
    string postfix_exp,prefix_exp;
    cout<<" Enter the Postfix Expression:"<<endl;
    cin>>postfix_exp;
    stack <char> stack;
    cout<<"POSTFIX EXPRESSION :"<<postfix_exp<<endl;
    prefix_exp=PostfixToprefix(postfix_exp);
    cout<<" IPREFIX EXPRESSION :"<<prefix_exp<<endl;

    return 0;
}