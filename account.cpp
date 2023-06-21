#include <iostream>
#include <string>
#include <vector>
#include "account.h"
#include "tweet.h"


using namespace std;


int Account::Set_Name(string Name)//This function set the name
{
    this-> Name = Name;
}


string Account::Get_Name()//This function set the name
{
    return Name;
}


int Account::Set_User(string User_name)//This function set the username (validation)
{
    
    int counter = 0 , counter2 = 0;
   
    string User = "" ;
    
    if(User_name.size()>=5)
    {
        for (char c : User_name)
        {
        int num = c - '0'; // convert character to integer
        char ascii = static_cast<char>(num + '0'); // convert integer to ASCII 
        User += ascii;
        }
        for( int i=0 ;i<User.size() ;i++)
        {
            if(User[0]>=65 && User[0]<=90 || User[0]>=97 && User[0]<=122 || User[0])// the first char should not be numbers
            {

                if(User[i]>=65 && User[i]<=90 || User[i]>=97 && User[i]<=122 || User[i]>=48 && User[i]<=57)
                {
                    counter++ ;
                }
                else
                {
                    cout << "! Your Username should only contains characters and numbers .\n" ;
                    return ++counter2;
                }
            }
            else
            {
                cout << "! your Username should not start with numbers.\n" ;
                return ++counter2;
            }
        }
    }
    else
    {
        cout << "! Your Username should be more than 5 characters.\n" ;
        return ++counter2;
          

    }
    if(counter == User.size())
    {
        User_Name = User;
        return 0;
    }
  
}



string Account::Get_User()
{
    return User_Name;
}


int Account::Set_Bio(string Bio)//160 char(checked)
{
    
    if(Bio.size() < 161)
    { 
        this-> Bio = Bio;
        return 1; 
    }
    else if (Bio == "")
    {
        this-> Bio = Bio;
    }
    else
    {
        cout << "! Error please Enter another Biography.\n";
        return 0 ;
    }
}


string Account::Get_Bio()
{
    return Bio;
}


int Account::Set_Country(string Country)
{
    if(Country.size() < 51)
    { 
        this-> Country = Country;
        return 1; 
    }
    else if (Country == "")
    {
        this-> Country = Country;
    }
    else
    {
        cout << "! Error please Enter another Country.\n";
        return 0 ;
    }
}


string Account::Get_Country()
{
    return Country;
}


int Account::Set_Link(string Link)
{
    if(Link.size() < 500)
    { 
        this-> Link = "https://" + Link;
        return 1; 
    }
    else if (Link == "")
    {
        this-> Link = Link;
        return 0;
    }
    else
    {
        cout << "! Error please Enter another Link.\n";
        return 0 ;
    }
    
}


string Account::Get_Link()
{
    return Link;
}


int Account::Set_Age(string Age)
{
    if(Age[0]>=48 && Age[0]<=57 &&
       Age[1]>=48 && Age[1]<=57 &&
       Age[2]>=48 && Age[2]<=57 &&
       Age[3]>=48 && Age[3]<=57 &&
       Age[4]==47 &&
       Age[5]>=48 && Age[5]<=57 &&
       Age[6]>=48 && Age[6]<=57 &&
       Age[7]==47 &&
       Age[8]>=48 && Age[8]<=57 &&
       Age[9]>=48 && Age[9]<=57 )
    {
       this->Age = Age;
       return 1 ;  
    }
    else
    {
       cout << "! Error please Enter your birthday correctly.\n";
       return 0 ;
    }
}


string Account::Get_Age()
{
    return Age;
}


int Account::Set_Phone(string Phone_Number)
{
    int counter = 0;
    if(Phone_Number.size()==12)
    {
        for( int i=0 ;i<Phone_Number.size();i++)
        {
            if(Phone_Number[i]>='0' && Phone_Number[i]<='9')
            {
                counter++;
            }

        }
        if (counter == 12)
        {
            this->Phone_Number = Phone_Number;
            return 1 ;  
        }
        else
        {
            cout << "! You are only allowed to enter numbers in this section.\n";
        }
    }
    else
    {
       cout << "! Error please Enter your phone number correctly.\n" ;
       return 0 ;
    }
    

}

string Account::Get_Phone()
{
    return Phone_Number;
}


int Account::Set_Password(string password)
{
    hash<string> mystdhash;
    int counter = 0;
    bool ch = false; //character
    bool num = false; //numbers
    string pass = "" ;
    if(password.size()> 4 )
    {
         for (char c : password )
        {
        int num = c - '0'; // convert character to integer
        char ascii = static_cast<char>(num + '0'); // convert integer to ASCII 
        pass += ascii;
        }

        for( int i=0 ;i<pass.size() ;i++)
        {
            if(pass[i]>=65 && pass[i]<=90 || pass[i]>=97 && pass[i]<=122 )
            {
                ch = true;
            }
            else if(pass[i]>=48 && pass[i]<=57 )
            {
                num = true;
            }
        }
    }
    else
    {
        cout << "! Your password must be more than 4 characters.\n";
        return ++counter ;    
    }
    
    if (ch == false || num == false)
    {
        cout << "! Password should contain both character and number.\n" ;
        return ++counter;
    }
    else if ( ch == false && num == true || ch== true && num==false)
    {
         cout << "! Password should contain both character and number.\n" ;
        return ++counter;
    }
    else
    {
        Password = mystdhash(pass);
        return 0;
    }

}


size_t Account::Get_Password()
{
    return Password;
}


void Account::Set_Header(string Header)
{
    this -> Header = Header;
}


string Account::Get_Header()
{
    return Header;
}


void Account::push_tweet(Tweet word) //class Tweet
{
    mtweet[word.get_number()] = word; 
    cout << "* Your tweet has been successfully registered.\n";
}


void Account::get_tweet()
{
    if(mtweet.size()==0)
    {
        cout << "! No tweet has been created.\n" ; 
    }
    else
    {
        for(auto i: mtweet)
        {
            cout << "-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-\n";
            cout << i.first << ": " << i.second.get_classtweet() << endl << "likes : " <<  i.second.liker_size() <<endl ;
            cout << i.second.get_Date();
          
        }
            cout << "-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-\n";

    }
}


void Account::get_tweet1(int index)
{
    if(mtweet.count(index)==1)
    {
        cout << "-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-\n";
        cout << mtweet[index].get_number() << ":" << mtweet[index].get_classtweet()<< endl << mtweet[index].get_Date() << endl;
    }
    else
    {
        cout << "! this Tweet does not exist.\n" ;
    }
}


void Account::set_index()
{
    index++;
}
void Account::delete_tweet(int Number)
{
    if(mtweet.find(Number)!=mtweet.end())
    {
        mtweet.erase(Number) ;
        cout << "* Your tweet has successfully deleted.\n" ;
     
    }
    else
    {
        cout << "! We can not find this tweet.\n" ;
    }
}


void Account::edit_tweet(int nUmber)
{
    if(mtweet.find(nUmber)!=mtweet.end())
    {
        int totall=stoi(Age.substr(0 ,4)) ;
        if(totall>2005)
        {
            cout << "! cant edit tweet because You are under 18.\n"  ;
        }
        else
        {
            cout << "* Enter new text for tweet" << nUmber << ": " ;
            string newtwe ; //new tweet
            getline(cin , newtwe) ;
            mtweet[nUmber].Set_Tweet(newtwe) ;
            cout << "* Your tweet has been edited successfully.\n" ;
        }
    }
    else
    {
        cout << "! We can not find this tweet.\n" ;
    }    
}
 
string Account::backstring(int number)
 {
    if(mtweet.count(number)==1)
    {
        return mtweet[number].get_classtweet();
    }
 }