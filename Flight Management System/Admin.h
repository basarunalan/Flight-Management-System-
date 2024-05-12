#ifndef ADMIN_H
#define ADMIN_H
#include <iostream>
using namespace std;
class Admin
{
 public:
 int UserLogin(string _username,string _password);
 private:
 bool check();
 string username,password;
 
};


#endif