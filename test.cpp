#include <iostream>
#include<fstream>
#include<conio.h>
#include<algorithm>
#include<regex>
using namespace std;
int sum=0, i;
char y;
char regpass[100];
void display();
struct user
{
    string username;
    string password;
    string email;
    string phone_num;
    string name_n;
};


string name;
string l_user;
map<string, user>users;
//----------------------------------------------
void loadusers(map<string, user> &users)
{
    ifstream file;
    file.open("users.txt");
    user temp;
    while(!file.eof())
    {
        getline(file, temp.username);
        getline(file, temp.password);
        getline(file, temp.email);
        getline(file, temp.phone_num);
        getline(file, temp.name_n);
        users.insert({temp.username, temp});
    }
    file.close();
}
//----------------------------------------------
//-------------------------------------------------------------


void pass()
{
    int i=0;
    char ch;

    printf("\nThe password must be at least 8 characters"
            "\nThe password may contain lowercase letters,uppercase letters, digits and special characters ");
    printf("\nEnter the password: ");
   while((ch=_getch())!=13)
   {
       regpass[i]=ch;
       i++;
       printf("*");
   }
    regpass[i]='\0';

    int dig=0,low_alpha=0,upper_alpha=0,special=0;
    for(int o=0;o<i;o++)
    {
        if(regpass[o]>='0'&&regpass[o]<='9')
            dig+=1;
    }
    for(int o=0;o<i;o++)
    {
        if(regpass[o] >= 'a' && regpass[o] <= 'z' )
            low_alpha+=1;
    }
    for(int o=0;o<i;o++)
    {
        if(regpass[o] >= 'A' && regpass[o] <= 'Z')
            upper_alpha+=1;
    }
    for(int o=0;o<i;o++)
    {
        if(regpass[o]=='!'||regpass[o]=='@'||regpass[o]=='#'||regpass[o]=='$'||regpass[o]=='%'||regpass[o]=='^'||regpass[o]=='&'||regpass[o]=='*'||regpass[o]=='>'||regpass[o]=='<'||regpass[o]==','||regpass[o]=='.'||regpass[o]=='+'||regpass[o]=='='||regpass[o]=='-')
            special+=1;
    }
    if(dig==0||low_alpha==0||upper_alpha==0||special==0||i<8)
        {
            cout<<"\nPassword is weak , enter another password!! ";
             pass();
        }
    else
    {
      i=0;
       char pwd2[100];
       char e[100];
       printf("\nRepeat the password: ");
       while((ch=_getch())!=13)
       {
          pwd2[i]=ch;
          i++;
          printf("*");
        }
       pwd2[i]='\0';
       if (strcmp(regpass,pwd2)==0)
        {
         for(int h=0;h<i;h++)
            {
              encryption(regpass[h]);
              e[h]=y;
            }
          ofstream reg("users.txt",ios::app);
          reg<<e<<endl;
          reg.close();
         }
       else
        {
          printf("The passwords do not match");
          pass();
        }
    }
  }

//------------------------------------------
//----------------------------------------------------------
void r_username()
{
    bool check= true;
    ofstream reg("users.txt",ios::app);
    string reguser;
    cout<<"\nEnter the username :";
    cin>>reguser;
    ifstream input;
    size_t pos;
    string line;
    input.open("users.txt");
    if(input.is_open())
    {
        while(getline(input,line))
        {
            pos = line.find(reguser);
            if(pos!=string::npos)
            {
                cout <<"Found username,enter another username!! "<<endl;
                check=false;
                break;
            }
        }
    }
    if(check== 1)
    {
       reg<<reguser<<endl;
         reg.close();
    }
    else
        r_username();
}
//----------------------------------------------------------
//------------------------------------------
bool email_check(string c_email)
{
    const regex pattern("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");
    return regex_match(c_email,pattern);
}
//-------------------------------------------
void reemail()
{
    string email;
    bool check= true;
    //email register:
    ofstream reg("users.txt",ios::app);
    cout<<"\n\nEnter the email :";
    cin>>email;
    ifstream input;
    size_t pos;
    string line;
    input.open("users.txt");
    if(input.is_open())
    {
        while(getline(input,line))
        {
            pos = line.find(email);
            if(pos!=string::npos)
            {
                cout <<"Found email,enter another email!! "<<endl;
                check=false;
                break;
            }
        }
    }
    if(check== 1)
    {
        if(email_check(email))
        {
            reg<<email<<endl;
            reg.close();
        }
        else
        {
            cout<<"invalid email!!! "<<endl;
            reemail();
        }
    }
    else
        reemail();
}
//------------------------------------------------
//------------------------------------------------
void phone_check()
{
    string phone;
    cout<<"\nEnter the phone number: ";
    cin>>phone;
    if(phone[0]=='0'&&phone[1]=='1')
    {
        if(phone.length()!=11)
        {
            cout<<"invalid number!!! ";
            phone_check();
        }
        for (int j = 0; j < phone.length(); ++j)
        {
            if(!(phone[j]>='0'&&phone[j]<='9'))
            {
                cout<<"invalid number!!! ";
                phone_check();
            }
        }
    }
    else
    {
        cout<<"invalid number!!! ";
        phone_check();
    }
    ofstream reg("users.txt",ios::app);
    reg<<phone<<endl;
    reg.close();

}
//---------------------------------------------