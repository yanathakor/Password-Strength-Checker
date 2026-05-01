#include<iostream>
#include<conio.h>
#include<string>
#include<cctype>
using namespace std;

string checkstrength(string p)
{
    int sc = 0;

    if(p.length() >= 8)
    {
        sc++;
    }

    for(int i = 0; i < p.length(); i++)
    {
        if(isupper(p[i]))
        {
            sc++;
            break;
        }
    }

    for(int i = 0; i < p.length(); i++)
    {
        if(islower(p[i]))
        {
            sc++;
            break;
        }
    }

    for(int i = 0; i < p.length(); i++)
    {
        if(isdigit(p[i]))
        {
            sc++;
            break;
        }
    }

    for(int i = 0; i < p.length(); i++)
    {
        if(!isalnum(p[i]))
        {
            sc++;
            break;
        }
    }

    if(sc <= 2)
    {
        return "weak";
    }
    else if(sc <= 4)
    {
        return "medium";
    }
    else
    {
        return "strong";
    }
}

string getpassword()
{
    string p = "";
    char ch;

    cout << "enter password: ";

    while(true)
    {
        ch = getch();

        if(ch == 13)
        {
            break;
        }
        else if(ch == 8)
        {
            if(!p.empty())
            {
                p.pop_back();
            }
        }
        else
        {
            if(ch != ' ')
            {
                p += ch;
            }
        }

        cout << "\r";
        for(int i = 0; i < 80; i++)
        {
            cout << " ";
        }

        cout << "\renter password: ";

        for(int i = 0; i < p.length(); i++)
        {
            cout << "*";
        }

        string s = checkstrength(p);
        cout << "  [" << s << "]";
    }

    cout << endl;
    return p;
}

void givesuggestions(string p)
{
    bool u=false, l=false, d=false, s=false;

    for(int i=0;i<p.length();i++)
    {
        if(isupper(p[i])) u=true;
        else if(islower(p[i])) l=true;
        else if(isdigit(p[i])) d=true;
        else s=true;
    }

    cout << "suggestions:" << endl;

    if(p.length() < 8)
        cout << "- use at least 8 characters" << endl;

    if(!u)
        cout << "- add uppercase letters" << endl;

    if(!l)
        cout << "- add lowercase letters" << endl;

    if(!d)
        cout << "- include numbers" << endl;

    if(!s)
        cout << "- use special characters" << endl;
}

int main()
{
    int a = 3;

    while(a > 0)
    {
        cout << endl;
        cout << "attempts left: " << a << endl;

        string p1 = getpassword();
        string p2 = getpassword();

        if(p1 != p2)
        {
            cout << "not match" << endl;
            a--;
            continue;
        }

        string s = checkstrength(p1);
        cout << "strength: " << s << endl;

        if(s == "weak")
        {
            cout << "too weak" << endl;
            givesuggestions(p1);
            a--;
            continue;
        }

        if(s == "medium")
        {
            givesuggestions(p1);

            char c;
            cout << "retry? (y/n): ";
            cin >> c;

            if(c == 'y' || c == 'Y')
            {
                a--;
                continue;
            }
            else
            {
                cout << "accepted" << endl;
                break;
            }
        }

        if(s == "strong")
        {
            cout << "accepted" << endl;
            break;
        }
    }

    if(a == 0)
    {
        cout << "too many attempts" << endl;
    }

    return 0;
}
