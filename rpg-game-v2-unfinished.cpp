#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <conio.h>
#include <windows.h>
using namespace std;
HANDLE hOut;//colours handler

#define seledyn() SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY );//seledyn
#define green() SetConsoleTextAttribute( hOut, FOREGROUND_GREEN );  //green

enum States
{
    STATE_START,
    STATE_FIGHT,
    STATE_TALK_WITH_INNKEEPER,
    STATE_HELP_INNKEEPER,
    STATE_INC_RESP,
    STATE_JOIN_TEAM,
    STATE_EXIT
};
struct GameContext
{
    int respect{};
    int rat{5};    //your choice, reputation, rat hp
    States currentState{STATE_START};
};
void showText (string txt)
{
    for (size_t i = 0; i < txt.length(); i++)
    {
        cout << txt[i];
        Sleep(20);
    }
}
void StateStart(GameContext *ctx)
{
    unsigned char choice;
    green();
    showText("You are Drizzt Do'Urden. You came out from the Underdark and you must defeat your enemies and survive.\n");
    showText("You beginns in towern Under Frisky Pony:\n");

    // print choices
    cout<< "1. Talk to the inkeeper.\n2. Look around for a free table.\n";

    // read user choice
    choice = getch();// first decision

    if(choice == '1')
    {
        ctx->currentState = STATE_TALK_WITH_INNKEEPER;
    }
    else if(choice == '2')
    {
        ctx->currentState = STATE_JOIN_TEAM;
    }
    else if(choice == '0')
    {
        ctx->currentState = STATE_EXIT;
    }
    else
    {
        // do nothing, in next iteration this cunction will be called again
    }
}
void StateFight(GameContext *ctx)
{
    bool result=true;
    int attack=rand()%20;   //your randomize attack  from 0 to 15 points

    if(attack>=ctx->rat)
    {
        cout<<"You defeat an enemy.\n";
        //green();
        result=true;
    }
    else
    {
        cout<<"You die! Your enemy was defeat you.";
        result=false;
    }

    if(result==true)
    {
        cout<<"You defeat an enemy! ";
        ctx->currentState = STATE_INC_RESP;
    }
    else
    {
        cout<<"Your enemy was defeated you!\n";
        ctx->currentState = STATE_EXIT;
    }

}
void StateIncResp(GameContext *ctx)
{
    ctx->respect+=1;
    cout<<"REP: "<<ctx->respect<<endl;
    ctx->currentState = STATE_JOIN_TEAM; // from this state always go to join team
}
void StateTalkWithInnkeeper(GameContext *ctx)
{
    unsigned char choice;
    // print options
    cout<<"\n-Hello traveler! Unfortunately, sales stopped because of rats in the basement. If you could help me and kill them..\nIt will be helpful in resume trading. The sooner, the better.\n";
    cout<< "\n1. Help with killing rat.\n2. Refuse help.\n";
    choice = getch(); //get deciison

    if(choice == '1')
    {
        ctx->currentState = STATE_HELP_INNKEEPER;
    }
    else if(choice == '2')
    {
        cout<<"\n-Sorry, I haven't time for your problems. Find someone else.\n";
        ctx->currentState = STATE_START;
    }
    else
        ctx->currentState = STATE_EXIT;
}
void StateHelpInnkeeper(GameContext *ctx)
{
    cout<<"-I will deal with it, as soon as possible.\n";
    cout<<"You see dark basement. A big rat lies next to beer barrels. You tried keep quiet you tried keep quiet but rat wake up.\n";
    ctx->currentState = STATE_FIGHT;
    cout<<"\n-Hey! You helped me so I can do my business again. Give thanks to the stranger! I put everyone in linee!\n\n";
}

void StateJoinTeam(GameContext *ctx)
{
    unsigned int choice;
    cout<<"You found free table near window. You sit down and while drinking beer and look around the room.\n";
    cout<<"You overheard the conversation of the dwarves who were sitting behind you.\n";
    cout<<"You noticed that they want to start looking for an ancient artifact. You must join the company!\n";
    cout<<"You get up and starting conversation with them.\n";

    do
    {
        cout<< "\n1. Try to start conversation.\n2. Do nothing.\n";
        choice = getch();
        if(choice=='1' && ctx->respect>=1)
        {
            cout<<"\n-Okey, you seems to be friendly and helpful. You can joun us and experience the adventure!\n";
            cout<<"And the story goes on...\n";
            cout<<"\n\n";
            break;
        }
        else if(choice=='1' && ctx->respect<1)
        {
            cout<<"\n-Sorry stranger, are you lost or looking for troubles?\n";
            ctx->currentState = STATE_START;
        }
        else
        {
            cout<<"Nothing happened";
            showText(".....................\n");
        }
    }
    while(choice!='1');
    //else break
}
void StateExit(GameContext *ctx)
{
    cout<<"Good Bye!"<<endl;
}
void GameLoopStateMachine()
{
    GameContext ctx;
    hOut = GetStdHandle( STD_OUTPUT_HANDLE );
    srand(time(NULL));

    while(ctx.currentState != STATE_EXIT)
    {
        switch(ctx.currentState)
        {
        case STATE_START:
            StateStart(&ctx);
            break;
        case STATE_FIGHT:
            StateFight(&ctx);
            break;
        case STATE_TALK_WITH_INNKEEPER:
            StateTalkWithInnkeeper(&ctx);
            break;
        case STATE_HELP_INNKEEPER:
            StateHelpInnkeeper(&ctx);
            break;
        case STATE_INC_RESP:
            StateIncResp(&ctx);
            break;
        case STATE_JOIN_TEAM:
            StateJoinTeam(&ctx);
            break;
        default: // unknown state, exit
            ctx.currentState = STATE_EXIT;
            break;
        }
    }
}

int main()
{
    GameLoopStateMachine();
}
