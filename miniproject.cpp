#include <iostream>
#include <string>
using namespace std;
string suggest(string password)
{
    string newPass=password;

    newPass = "A" + newPass;
    newPass = newPass +"1";
    newPass = newPass +"@";

    while (newPass.length()<8)
    {
        newPass = newPass+"x";
    }

    return newPass;
}
void check(string password)
{
    int length=password.length();

    bool upper=false;
    bool lower=false;
    bool digit=false;
    bool special=false;

    for(int i=0;i<length;i++)
    {
        if(password[i]>='A'&& password[i]<='Z')
            upper=true;
        else if(password[i]>='a'&& password[i]<='z')
            lower=true;
        else if(password[i]>='0'&&password[i]<='9')
            digit=true;
        else
            special=true;
    }

    cout << endl;
    cout << "******** Password Analysis ********" << endl;

    bool weak=false;
    if (length<6)
    {
        cout<<"Weak Password"<<endl;
        weak=true;
    }
    else if(length>= 6 && length<=10)
    {
        if (upper && lower && digit)
            cout<<"Medium Password"<<endl;
        else
        {
            cout<<"Weak Password"<<endl;
            weak=true;
        }
    }
    else
    {
        if (upper && lower && digit && special)
            cout<<"Strong Password"<<endl;
        else
            cout<<"Medium Password"<<endl;
    }
    cout<<endl;
    cout<<"Suggestions:"<<endl;

    if(!upper)
        cout<<"Add uppercase letter"<<endl;

    if (!lower)
        cout<<"Add lowercase letter"<<endl;

    if (!digit)
        cout<<"Add digit"<<endl;

    if (!special)
        cout<<"Add special character"<<endl;

    if(length<8)
        cout <<"Increase password length"<<endl;

    if(weak)
    {
        string strongPass=suggest(password);
        cout<<"Suggested Strong Password: "<<strongPass<<endl;
    }

    cout << "**************************************************" << endl;
}

int main()
{
    string password;
    char choice;

    do
    {
        cout << endl;
        cout<<"=*=*Password Strength Checker *=*="<<endl;
        cout<<"Enter your password:";
        cin>>password;
        check(password);
        cout << endl;
        cout<<"Check another password?(y/n):"<<endl;
        cin >> choice;

    } while (choice=='y' || choice== 'Y');
    cout << "Thank you!" << endl;

    return 0;
}
