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
