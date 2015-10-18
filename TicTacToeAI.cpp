/*
Name of the Program     : Tic Tac Toe Unbeatable AI
Made by                 : Rohan Sharma (racy.rohan@gmail.com)
*/

#include <iostream> //for cout & cin
#include <windows.h>    //for gotoxy()
#include <time.h>   //for delay()
#include <stdio.h>  //for gets()

using namespace std;

COORD coord={0,0};  //global variable (used for gotoxy)

void gotoxy(int x,int y)    //function for gotoxy
{
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

void delay(unsigned int mseconds)   //function for delay
{
    clock_t goal=mseconds+clock();
    while(goal>clock());
}

//global variables
int draw=0,comp=0,p=0;   //to count number of wins/draws
int ar[3][3],x,y,n,turn;  //'ar' is a 2D array, 'x' & 'y' are coordinates, 'n' and 'turn' are for turn status
int count_turn=0;  //to count number of turns
int sq_num; //for input of square number
int i,j;

//functions declaration
void initialize();   //to initialize each coordinate of 'ar' to '0'
void input();
int AI();
int win_or_draw_check();

int main()
{
    int ai_check,win_draw_check;
    char choice;
    cout<<"\t\t\t\tTIC TAC TOE";
    START:
    turn=1;
    count_turn=0;
    system("cls");
    initialize();
    cout<<"\t\t\t\tTIC TAC TOE";
    gotoxy(28,9);
    cout<<"   |   |   ";
    gotoxy(28,10);
    cout<<"(1)|(2)|(3)       Computer's Wins (0) : "<<comp;
    gotoxy(28,11);
    cout<<"   |   |   ";
    gotoxy(28,12);
    cout<<"___________";
    gotoxy(28,13);
    cout<<"   |   |   ";
    gotoxy(28,14);
    cout<<"(4)|(5)|(6)       Your Wins (X) : "<<p;
    gotoxy(28,15);
    cout<<"   |   |   ";
    gotoxy(28,16);
    cout<<"___________";
    gotoxy(28,17);
    cout<<"   |   |   ";
    gotoxy(28,18);
    cout<<"(7)|(8)|(9)       Draw : "<<draw;
    gotoxy(28,19);
    cout<<"   |   |   ";
    TURN:
    if(turn%2!=0)   //for turn status
    {
        gotoxy(1,5);
        cout<<"                                                           ";
        gotoxy(30,3);
        cout<<"Computer's Turn (0)\t\t";
        n=1;
        delay(1000);
        goto AI_START;
    }
    else
    {
        gotoxy(30,3);
        cout<<"Your Turn (X)\t\t";
        n=2;
    }
    input();
    goto AI_END;
    AI_START:
    ai_check=AI();
    AI_END:
    if(ai_check==1)
    {
        gotoxy(1,20);
        cout<<"AI for this case not yet built...\n\n\n";
        system("pause");
        goto END;
    }
    ar[x-1][y-1]=n;
    gotoxy(29+4*(x-1)-1,10+4*(y-1));   //for placement of '0' or 'X'
    if(n==1)
        cout<<" 0 ";
    else if(n==2)
        cout<<" X ";
    win_draw_check=win_or_draw_check();
    if(win_draw_check==1)
        goto END;
    goto TURN;
    END:
    gotoxy(46,10);
    cout<<"Computer's Wins (0) : "<<comp;
    gotoxy(46,14);
    cout<<"Your Wins (X) : "<<p;
    gotoxy(46,18);
    cout<<"Draw : "<<draw;
    gotoxy(1,23);
    cout<<"Do you want to play again (y/n) :                          \b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b";
    cin>>choice;
    if(choice=='y' || choice=='Y')
        goto START;
    else if(choice=='n' || choice=='N')
        goto EXIT;
    else
    {
        gotoxy(45,20);
        cout<<"Invalid Choice!";
        delay(1000);
        goto END;
    }
    EXIT:
    return 0;
}

void initialize()
{
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
            ar[i][j]=0;
    }
}

void input()
{
    INPUT:
    gotoxy(1,5);
    cout<<"Enter Square Number :                           \b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b";
    gotoxy(23,5);
    cin>>sq_num;
    if(sq_num>=1 && sq_num<=3)
    {
        x=sq_num;
        y=1;
    }
    else if(sq_num>=4 && sq_num<=6)
    {
        x=sq_num-3;
        y=2;
    }
    else if(sq_num>=7 && sq_num<=9)
    {
        x=sq_num-6;
        y=3;
    }
    else if(sq_num<1 || sq_num>9)
    {
        gotoxy(35,5);
        cout<<"Invalid Input!";
        delay(1000);
        goto INPUT;
    }
    if(ar[x-1][y-1]!=0)
    {
        gotoxy(35,5);
        cout<<"Invalid Input!";
        delay(1000);
        goto INPUT;
    }
    count_turn++;
    ar[x-1][y-1]=n;
    gotoxy(29+4*(x-1)-1,10+4*(y-1));   //for placement of '0' or 'X'
    if(n==1)
        cout<<" 0 ";
    else if(n==2)
        cout<<" X ";
}

int AI()
{
    //--------------------------------
    //5->4->2 & 5->8->6 not build
    //--------------------------------
    count_turn++;
    //template
    //if(ar[1-1][1-1]==0 && ar[2-1][1-1]==0 && ar[3-1][1-1]==0 && ar[1-1][2-1]==0 && ar[2-1][2-1]==0 && ar[3-1][2-1]==0 && ar[1-1][3-1]==0 && ar[2-1][3-1]==0 && ar[3-1][3-1]==0)
    if(turn==1)
        sq_num=1;
    if(turn==3)
    {
        if(ar[1-1][1-1]==1 && (ar[2-1][1-1]==2 || ar[1-1][2-1]==2 || ar[3-1][2-1]==2 || ar[2-1][3-1]==2))
            sq_num=5;
        else if(ar[1-1][1-1]==1 && (ar[3-1][1-1]==2 || ar[1-1][3-1]==2))
            sq_num=9;
        else if(ar[1-1][1-1]==1 && ar[3-1][3-1]==2)
            sq_num=3;
        else if(ar[1-1][1-1]==1 && ar[2-1][2-1]==2)
            sq_num=9;
        else
            return 1;
    }
    if(turn==5)
    {
        if(ar[1-1][1-1]==1 && ar[2-1][2-1]==1 && ar[2-1][1-1]==2 && ar[3-1][3-1]==2)
            sq_num=7;
        else if(ar[1-1][1-1]==1 && ar[2-1][2-1]==1 && ar[3-1][3-1]!=2 && (ar[2-1][1-1]==2 || ar[1-1][2-1]==2))
            sq_num=9;
        else if(ar[1-1][1-1]==1 && ar[2-1][2-1]==1 && ar[2-1][1-1]==2 && ar[3-1][3-1]==2)
            sq_num=7;
        else if(ar[1-1][1-1]==1 && ar[2-1][2-1]==1 && ar[1-1][2-1]==2 && ar[3-1][3-1]==2)
            sq_num=3;
        else if(ar[1-1][1-1]==1 && ar[3-1][3-1]==1 && ar[3-1][1-1]==2 && ar[2-1][2-1]==2)
            sq_num=7;
        else if(ar[1-1][1-1]==1 && ar[3-1][3-1]==1 && ar[1-1][3-1]==2 && ar[2-1][2-1]==2)
            sq_num=3;
        else if(ar[1-1][1-1]==1 && ar[3-1][3-1]==1 && (ar[3-1][1-1]==2 || ar[1-1][3-1]==2) && ar[2-1][2-1]!=2)
            sq_num=5;
        else if(ar[1-1][1-1]==1 && ar[2-1][2-1]==1 && ar[3-1][3-1]==2)
        {
            if(ar[3-1][2-1]==2)
                sq_num=3;
            else if(ar[2-1][3-1]==2)
                sq_num=7;
        }
        else if(ar[1-1][1-1]==1 && ar[2-1][2-1]==1 && (ar[3-1][2-1]==2 || ar[2-1][3-1]==2) && ar[3-1][3-1]!=2)
            sq_num=9;
        else if(ar[1-1][1-1]==1 && ar[3-1][1-1]==1 && ar[3-1][3-1]==2)
        {
            if(ar[2-1][1-1]==2)
                sq_num=7;
            else
                sq_num=2;
        }
        else if(ar[1-1][1-1]==1 && ar[3-1][3-1]==1 && ar[2-1][2-1]==2)
        {
            if(ar[2-1][1-1]==2)
                sq_num=8;
            else if(ar[3-1][1-1]==2)
                sq_num=7;
            else if(ar[3-1][2-1]==2)
                sq_num=4;
            else if(ar[2-1][3-1]==2)
                sq_num=2;
            else if(ar[1-1][3-1]==2)
                sq_num=3;
            else if(ar[1-1][2-1]==2)
                sq_num=6;
        }
        else
            return 1;
    }
    if(turn==7)
    {
        if(ar[1-1][1-1]==1 && ar[2-1][2-1]==1 && ar[1-1][3-1]==1 && ar[2-1][1-1]==2 && ar[3-1][3-1]==2)
        {
            if(ar[3-1][1-1]==2)
                sq_num=4;
            else if(ar[1-1][2-1]==2)
                sq_num=3;
            else
                sq_num=3;
        }
        else if(ar[1-1][1-1]==1 && ar[2-1][2-1]==1 && ar[3-1][1-1]==1 && ar[1-1][2-1]==2 && ar[3-1][3-1]==2)
        {
            if(ar[1-1][3-1]==2)
                sq_num=2;
            else if(ar[2-1][1-1]==2)
                sq_num=7;
            else
                sq_num=2;
        }
        else if(ar[1-1][1-1]==1 && ar[3-1][3-1]==1 && ar[1-1][3-1]==1 && ar[3-1][1-1]==2 && ar[2-1][2-1]==2)
        {
            if(ar[1-1][2-1]==2)
                sq_num=8;
            else if(ar[2-1][3-1]==2)
                sq_num=4;
            else
                sq_num=4;
        }
        else if(ar[1-1][1-1]==1 && ar[3-1][3-1]==1 && ar[3-1][1-1]==1 && ar[1-1][3-1]==2 && ar[2-1][2-1]==2)
        {
            if(ar[2-1][1-1]==2)
                sq_num=6;
            else if(ar[3-1][2-1]==2)
                sq_num=2;
            else
                sq_num=2;
        }
        else if(ar[1-1][1-1]==1 && ar[2-1][2-1]==1 && ar[1-1][3-1]==1 && ar[3-1][3-1]==2 && ar[2-1][3-1]==2)
        {
            if(ar[3-1][1-1]==2)
                sq_num=4;
            else if(ar[1-1][2-1]==2)
                sq_num=3;
            else
                sq_num=3;
        }
        else if(ar[1-1][1-1]==1 && ar[3-1][1-1]==1 && ar[1-1][3-1]==1 && ar[2-1][1-1]==2 && ar[3-1][3-1]==2)
        {
            if(ar[2-1][2-1]==2)
                sq_num=4;
            else if(ar[1-1][2-1]==2)
                sq_num=5;
            else
                sq_num=4;
        }
        else if(ar[1-1][1-1]==1 && ar[2-1][2-1]==1 && ar[3-1][1-1]==1 && ar[3-1][2-1]==2 && ar[3-1][3-1]==2)
        {
            if(ar[1-1][3-1]==2)
                sq_num=2;
            else if(ar[2-1][1-1]==2)
                sq_num=7;
            else
                sq_num=2;
        }
        else if(ar[1-1][1-1]==1 && ar[3-1][3-1]==1 && ar[2-1][2-1]==2)
        {
            if(ar[2-1][1-1]==2 && ar[1-1][3-1]==2)
                sq_num=3;
            else if(ar[2-1][1-1]==2 && ar[1-1][3-1]!=2)
                sq_num=7;
            else if(ar[3-1][2-1]==2 && ar[1-1][3-1]==2)
                sq_num=3;
            else if(ar[3-1][2-1]==2 && ar[1-1][3-1]!=2)
                sq_num=7;
            else if(ar[2-1][3-1]==2 && ar[3-1][1-1]==2)
                sq_num=7;
            else if(ar[2-1][3-1]==2 && ar[3-1][1-1]!=2)
                sq_num=3;
            else if(ar[1-1][2-1]==2 && ar[3-1][1-1]==2)
                sq_num=7;
            else if(ar[3-1][2-1]==1 && ar[1-1][2-1]==2 && ar[3-1][1-1]!=2)
                sq_num=3;
        }
        else
        {
            return 1;
        }
    }
    else if(turn==9)
    {
        if(ar[1-1][1-1]==1 && ar[3-1][3-1]==1 && ar[3-1][1-1]==1 && ar[2-1][3-1]==1 && ar[2-1][1-1]==2 && ar[2-1][2-1]==2 && ar[1-1][3-1]==2)
        {
            if(ar[1-1][2-1]==2)
                sq_num=6;
            else if(ar[3-1][2-1]==2)
                sq_num=4;
        }
        else if(ar[1-1][1-1]==1 && ar[3-1][3-1]==1 && ar[3-1][1-1]==1 && ar[1-1][2-1]==1 && ar[2-1][2-1]==2 && ar[3-1][2-1]==2 && ar[1-1][3-1]==2)
        {
            if(ar[2-1][1-1]==2)
                sq_num=8;
            else if(ar[2-1][3-1]==2)
                sq_num=2;
        }
        else if(ar[1-1][1-1]==1 && ar[3-1][2-1]==1 && ar[3-1][3-1]==1 && ar[1-1][3-1]==1 && ar[2-1][2-1]==2 && ar[3-1][1-1]==2 && ar[2-1][3-1]==2)
        {
            if(ar[1-1][2-1]==2)
                sq_num=6;
            else if(ar[3-1][2-1]==2)
                sq_num=4;
        }
        else if(ar[1-1][1-1]==1 && ar[2-1][1-1]==1 && ar[3-1][3-1]==1 && ar[1-1][3-1]==1 && ar[3-1][1-1]==2 && ar[2-1][2-1]==2 && ar[2-1][3-1]==2)
        {
            if(ar[1-1][2-1]==2)
                sq_num=6;
            else if(ar[3-1][2-1]==2)
                sq_num=7;
        }
        else
            return 1;
    }
    if(sq_num>=1 && sq_num<=3)
    {
        x=sq_num;
        y=1;
    }
    else if(sq_num>=4 && sq_num<=6)
    {
        x=sq_num-3;
        y=2;
    }
    else if(sq_num>=7 && sq_num<=9)
    {
        x=sq_num-6;
        y=3;
    }
    return 0;
}

int win_or_draw_check()
{
    if((ar[0][0]==ar[1][0] && ar[0][0]==ar[2][0] && ar[0][0]!=0) || (ar[0][0]==ar[0][1] && ar[0][0]==ar[0][2] && ar[0][0]!=0) || (ar[0][0]==ar[1][1] && ar[0][0]==ar[2][2] && ar[0][0]!=0) || (ar[0][1]==ar[1][1] && ar[0][1]==ar[2][1] && ar[0][1]!=0) || (ar[2][0]==ar[2][1] && ar[2][0]==ar[2][2] && ar[2][0]!=0) || (ar[2][0]==ar[1][1] && ar[2][0]==ar[0][2] && ar[2][0]!=0) || (ar[0][2]==ar[1][2] && ar[0][2]==ar[2][2] && ar[0][2]!=0))  //for winning status
    {
        if(turn%2!=0)
        {
            gotoxy(27,21);
            cout<<"Computer Wins (0)\t\t";
            comp++;
        }
        else
        {
            gotoxy(27,21);
            cout<<"You Win (X)\t\t";
            p++;
        }
        return 1;
    }
    if(count_turn==9)
    {
        gotoxy(27,21);
        cout<<"It's a DRAW...";
        draw++;
        return 1;
    }
    turn++;
    return 0;
}
