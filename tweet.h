#ifndef TWEET_H
#define TWEET_H

#include <iostream>
#include <vector>
#include <ctime>

using namespace std;


class Account;
class Tweet
{
    private:

        vector<Account*>likers;
        string tweet;
        string Date ;    
        int number;
        

    public:

        void Set_Tweet(string);
        void set_number(int);
        string get_classtweet();
        int get_number();
        void likes(Account* ,Account* , int);
        void dislike(Account* ,Account* , int);
        void show_numberlikes(Account*, int);
        void show_likers(Account*, int);
        int liker_size();
        void Set_date();
        string get_Date();


};


#endif