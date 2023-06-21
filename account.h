#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <iostream>
#include <string>
#include <vector>
#include "tweet.h"
#include <map>

using namespace std;



class Account
{  
    friend void Tweet:: likes(Account* currentuser, Account* target, int index);
    friend void Tweet:: show_numberlikes( Account *target, int index);
    friend void Tweet:: show_likers(Account* target, int index);
    friend void Tweet:: dislike(Account* currentuser ,Account* target, int index);
    
    private:
       
        map<int ,Tweet> mtweet;
        string Name;
        string User_Name;
        string Age;
        string Phone_Number;
        string Country;
        string Link;
        string Bio;
        string Header;
        size_t Password;
        int index = 0 ;
    
    public:

        void set_index();
        int get_index(){return index;}

        
        int Set_Name(string Name);
        string Get_Name();

        int Set_User(string User_Name);
        string Get_User();

        int Set_Bio(string Bio);
        string Get_Bio();

        int Set_Country(string Country);
        string Get_Country();

        int Set_Link(string Link);
        string Get_Link();

        int Set_Age(string Age);
        string Get_Age();

        int Set_Phone(string Phone_Number);
        string Get_Phone();

        int Set_Password(string Password);
        size_t Get_Password();

        void Set_Header(string Header);
        string Get_Header();

        void push_tweet(Tweet t);
        void get_tweet();
        void get_tweet1(int index);
        void delete_tweet(int number);
        void edit_tweet(int nUmber) ;
        string backstring(int number) ;
}; 


#endif