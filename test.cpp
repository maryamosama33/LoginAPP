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