#include <iostream>
#include "tweet.h"
#include "account.h"
#include <ctime>



void Tweet:: Set_Tweet(string tweet)
{
    this -> tweet = tweet;
}


string Tweet::get_classtweet()
{
    return tweet;
}


void Tweet::set_number(int num)
{
    number = num;
}


int Tweet::get_number()
{
    return number;
}


void Tweet::likes(Account* user ,Account* purpose, int index) //liking tweet
{
    bool flag = false;
    if(purpose->mtweet[index].likers.size() != 0)
    {
        for (auto i : purpose->mtweet[index].likers )
        {
            if (i == user)
            {
                flag = true;
            }
        } 
        if (flag == false)
        {
            purpose->mtweet[index].likers.push_back(user);
            cout << "* liked.\n" ;
        }
        else 
        {
            cout << "! you can not like this tweet again.\n";
        } 
    }

    else 
    {
        purpose->mtweet[index].likers.push_back(user);
        cout << "* liked.\n" ;
    }

}


void Tweet:: show_numberlikes( Account *purpose, int index) //number of likes
{
    cout << "Likes : " << purpose->mtweet[index].likers.size()<< endl ;
}


void Tweet:: show_likers(Account* purpose, int index) //showing users (likes tweet)
{
    for(auto i : purpose->mtweet[index].likers)
    {
        cout << i->Get_User()<<endl;
    }
}


void Tweet::dislike(Account* user ,Account* purpose, int index)
{
    for (int i = 0 ; i < purpose->mtweet[index].likers.size() ; i++ )
    {
        if (purpose->mtweet[index].likers.at(i) == user )
        {
            purpose->mtweet[index].likers.erase(purpose->mtweet[index].likers.begin() + i);
        }
    }
}


void Tweet:: Set_date()
{
    time_t now = time(0);
    string dt = ctime(&now);
    Date = dt;
}


string Tweet::get_Date()
{
    return Date ;
}


int Tweet::liker_size()
{
    return likers.size();
}
