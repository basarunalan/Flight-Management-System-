#include <iostream>
using namespace std;
#include "Admin.h"

int Admin::UserLogin(string _username,string _password){
    username = _username;
    password = _password;
    if(check()){
        return true;
    }
    else{
       return false;
    } 
}
bool Admin::check(){
  if(username == "basarunalan" && password == "2003"){
    return true;
  }else if(username == "ezgiyigit" && password == "2002"){
    return true;
  }
  else{
    return false;
  }

}