#include <iostream>
#include <unordered_map>
#include "account.h"
#include "tweet.h"
#include <string>
#include <vector>

using namespace std;

class Twitterak
{
    friend void Tweet:: likes(Account* currentuser, Account* target, int index);
    friend void Tweet:: show_numberlikes( Account *target, int index);
    friend void Tweet:: show_likers(Account* target, int index);
    friend void Tweet:: dislike(Account* currentuser ,Account* target, int index);

    private:
        unordered_map<string , Account*> users;
        
    public:
        bool checkin = 0;
        string temp = "";
        string color ;
        void login(vector<string>&vec2);
        void signup(vector<string> &vec1);
        void logout();
        void menu();
        void ckeck_id(string &id);
        void choice_login();
        void show(string);
        void help();
        void edit_profile(string , string);
        void delete_account();
        void check_space(string&) ;

};
