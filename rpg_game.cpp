//three possible endings
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <conio.h>
#include <windows.h>
using namespace std;

#define seledyn() SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY );//seledyn
#define green() SetConsoleTextAttribute( hOut, FOREGROUND_GREEN );  //green

void logo()
{
    HANDLE hOut;//colours handler
    hOut = GetStdHandle( STD_OUTPUT_HANDLE );
    SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_RED ); //gold
    // A Raw string
    string logo =R"(
    .---.                    .   .                 .--.            .
    |                       _|_ _|_                |   )           |
    |---  .-. .--. .-.. .-.  |   |   .-. .--.      |--'  .-.  .-.  | .--.--. .--.
    |    (   )|   (   |(   ) |   |  (.-' |  |      |  \ (.-' (   ) | |  |  | `--.
    '     `-' '    `-`| `-'  `-' `-' `--''  `-     '   ` `--' `-'`-`-'  '  `-`--'
                   ._.'                                                          )";
    cout << logo<< endl<<endl;
}
void end()
{
    HANDLE hOut;//colours handler
    hOut = GetStdHandle( STD_OUTPUT_HANDLE );
    SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_RED ); //gold
    // A Raw string
    string end =R"(
                                     (
              (           (      )\ )           (
 (            )\ )        )\ )  (()/( (         )\      (  (     (     (
 )\    (     (()/(    (  (()/(   /(_)))(    (  ((_) (   )\))(   ))\   ))\
((_)   )\ )   ((_))   )\  /(_)) (_)) (()\   )\  _   )\ ((_))\  /((_) /((_)
| __| _(_/(   _| |   ((_)(_) _| | _ \ ((_) ((_)| | ((_) (()(_)(_))( (_))
| _| | ' \))/ _` |  / _ \ |  _| |  _/| '_|/ _ \| |/ _ \/ _` | | || |/ -_) _  _
|___||_||_| \__,_|  \___/ |_|   |_|  |_|  \___/|_|\___/\__, |  \_,_|\___|(_)(_)
                                                       |___/                    )";
    cout << end<< endl<<endl;
}
void showText (string txt)
{
    for (int i = 0; i < txt.length(); i++)
    {
        cout << txt[i];
        Sleep(20);
    }
}
bool fight(int enemy)
{
    HANDLE hOut;//colours handler
    hOut = GetStdHandle( STD_OUTPUT_HANDLE );
    SetConsoleTextAttribute( hOut, FOREGROUND_RED );    //red
    int attack=rand()%20;   //your randomize attack  from 0 to 15 points
    if(attack>=enemy)
    {
        cout<<"You defeat an enemy.\n";
        green();
        return true;
    }
    else
    {
        cout<<"You die! Your enemy was defeat you.";
        return false;
    }
}
int main()
{
    HANDLE hOut;//colours handler
    hOut = GetStdHandle( STD_OUTPUT_HANDLE );
    srand(time(NULL));
    unsigned char choice;
    int reputation=0, rat=5;    //your choice, reputation, rat hp
    bool result=true;

    logo();
    green();
    showText("You are Drizzt Do'Urden. You came out from the Underdark and you must defeat your enemies and survive.\n");
    Sleep(300);
    showText("You beginns in towern Under Frisky Pony:\n");
    do
    {
        seledyn();
        cout<< "1. Talk to the inkeeper.\n2. Look around for a free table.\n";

        choice = getch();// first decision
        if(choice=='1')
        {
            cout<<"\n-Hello traveler! Unfortunately, sales stopped because of rats in the basement. If you could help me and kill them..\nIt will be helpful in resume trading. The sooner, the better.\n";
            cout<< "\n1. Help with killing rat.\n2. Refuse help.\n";
            choice = getch();  //2.1 decision.    ?
            if(choice=='1')
            {
                cout<<"-I will deal with it, as soon as possible.\n";
                green();
                cout<<"You see dark basement. A big rat lies next to beer barrels. You tried keep quiet you tried keep quiet but rat wake up.\n";
                result = fight(rat);
                if(result==true)
                {
                    cout<<"REP: "<<++reputation<<endl;
                    seledyn();
                    cout<<"\n-Hey! You helped me so I can do my business again. Give thanks to the stranger! I put everyone in linee!\n\n";

                    green();
                    cout<<"You found free table near window. You sit down and while drinking beer and look around the room.\n";
                    cout<<"You overheard the conversation of the dwarves who were sitting behind you.\n";
                    cout<<"You noticed that they want to start looking for an ancient artifact. You must join the company!\n";
                    cout<<"You get up and starting conversation with them.\n";
                    do
                    {
                        seledyn();
                        cout<< "\n1. Try to start conversation.\n2. Do nothing.\n";
                        choice = getch();
                        if(choice=='1' && reputation>=1)
                        {
                            cout<<"\n-Okey, you seems to be friendly and helpful. You can joun us and experience the adventure!\n";
                            cout<<"And the story goes on...\n";
                            end();
                            cout<<"\n\n";
                            break;
                        }
                        else if(choice=='1' && reputation<1)
                        {
                            cout<<"\n-Sorry stranger, are you lost or looking for troubles?\n";
                        }
                        else
                        {
                            cout<<"Nothing happened";
                            showText(".....................\n");
                        }
                    }
                    while(choice!='1');
                }
                else
                    break;
            }

            else if (choice=='2')
            {
                seledyn();
                cout<<"\n-Sorry, I haven't time for your problems. Find someone else.\n";
            }
            else
                choice='0';
        }
        else if(choice=='2')
        {
            green();
            cout<<"You found free table near window. You sit down and while drinking beer and look around the room.\n";
            cout<<"You overheard the conversation of the dwarves who were sitting behind you.\n";
            cout<<"You noticed that they want to start looking for an ancient artifact. You must join the company!\n";
            cout<<"You get up and starting conversation with them.\n";

            seledyn();
            cout<< "\n1. Try to start conversation.\n2. Do nothing.\n";
            choice = getch();
            if(choice=='1' && reputation>=1)
            {
                cout<<"\n-Okey, you seems to be friendly and helpful. You can joun us and experience the adventure!\n";
                cout<<"And the story goes on...\nEND of Prologue..\n\n";
                break;
            }
            else if(choice=='1' && reputation<1)
            {
                cout<<"\n-Sorry stranger, are you lost or looking for troubles?\n\n";
            }
            else
            {
                cout<<"Nothing happened";
                showText(".....................");
                system( "cls" );
            }
        }
        else
            choice='0';
        if(choice=='0')
            break;
    }
    while(reputation<1);
    system("pause");
    return 0;
}
