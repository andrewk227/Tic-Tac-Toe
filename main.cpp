#include <iomanip>
#include <iostream>
#include <algorithm>
using namespace std;

//initialize 3x3 Board to play in
char board[3][3];
/*
     |     |
 0 0 | 0 1 | 0 2
____ |____ |____
     |     |
 1 0 | 1 1 | 1 2
____ |____ |____
     |     |
 2 0 | 2 1 | 2 2
____ |____ |____

*/

//function to divide the board to squares
//and returns the square number
int square(int n,int m)
{
    if (n==0 && m==0)
        return 1;
    else if (n==0 && m==1)
        return 2;
    else if (n==0 && m==2)
        return 3;
    else if (n==1 && m==0)
        return 4;
    else if (n==1 && m==1)
        return 5;
    else if (n==1 && m==2)
        return 6;
    else if (n==2 && m==0)
        return 7;
    else if (n==2 && m==1)
        return 8;
    else if (n==2 && m==2)
        return 9;
    else{
        cout<<"Wrong Position/n";
        return -1;}
}

//Function to print updated board
void print_board()
{
    for (int i=0;i<3;i++)
    {
        for (int j=0;j<3;j++)
            cout<<board[i][j]<<" ";
        cout<<endl;
    }
}

//Function to switch turn
bool switch_players(bool &t)
{
    if (t)
        t=false;
    else
        t=true;
    return t;
}
//Declare player class to make 2 players
class Player
{
private:
    string name;
    char sign;

public:

    bool marked[10];

    void set_name(string name)
    {
        this->name=name;
    }
    void set_sign(char sign)
    {
        this->sign=sign;
    }
    string get_name()
    {
        return name;
    }
    char get_sign()
    {
        return sign;
    }
};

//function to get the winner
bool win(bool vec[])
{
    if (vec[1]==true && vec[2]==true && vec[3]==true)
        return true;
    else if (vec[4]==true && vec[5]==true && vec[6]==true)
        return true;
    else if (vec[7]==true && vec[8]==true && vec[9]==true)
        return true;
    else if (vec[1]==true && vec[4]==true && vec[7]==true)
        return true;
    else if (vec[2]==true && vec[5]==true && vec[8]==true)
        return true;
    else if (vec[3]==true && vec[6]==true && vec[9]==true)
        return true;
    else if (vec[1]==true && vec[5]==true && vec[9]==true)
        return true;
    else if (vec[3]==true && vec[5]==true && vec[7]==true)
        return true;
    else
        return false;
}

void play(Player &p1,Player &p2)
{
    string name1,name2;
    char sign1,sign2;

    //get player 1 info
    cout <<"Enter The name of Player 1: ";
    cin>>name1;
    p1.set_name(name1);
    cout <<"Enter your fav sign to play with: ";
    cin>>sign1;
    p1.set_sign(sign1);
    cout<<endl<<endl;

    // get info of player 2
    cout <<"Enter The name of Player 2: ";
    cin>>name2;
    p2.set_name(name2);
    cout <<"Enter your fav sign to play with: ";
    cin>>sign2;
    p2.set_sign(sign2);
    cout<<endl<<endl;

    //set array of two players with value false
    for (int i=0;i<10;i++)
    {
        p1.marked[i]=false;
        p2.marked[i]=false;
    }

    //initialize a boolean variable to switch the turn between players
    bool turn=true;

    int cnt=1;
    //let's start playing the game
    for (int i=0;i<9;i++)
    {
        int n=0,m=0;
        if (turn)
        {
            cout<<"Player 1 Turn"<<endl;
            cout<<"Enter the position you want to put your sign: ";
            while(true){
            cin>>n>>m;
            if (board[n][m]== '-'){
                board[n][m]=p1.get_sign();
                p1.marked[square(n,m)]=true;
                break;
            }
            else
                cout<<"Can't put in That position\n";
                cout<<"Please try again XD\n";
            }
        }
        else
        {
            cout<<"Player 2 Turn "<<endl;
            cout<<"Enter the position you want to put your sign: ";
             while(true){
            cin>>n>>m;
            if (board[n][m]== '-'){
                board[n][m]=p2.get_sign();
                p2.marked[square(n,m)]=true;
                break;
            }
            else
                cout<<"Can't put in That position\n";
                cout<<"Please try again XD\n";
            }
        }
        cnt++;

        turn=switch_players(turn);
        print_board();

        //condition to check the winner
        //when counter equal 5
        if (cnt>=5)
        {
            //check if the player 1 is the winner
            if (win(p1.marked))
                {
                    cout<<"------------------"<<p1.get_name()<<" is the Winner. ------------------"<<endl;
                    return;
                }
            //check if the player 2 is the winner
            if (win(p2.marked))
                {
                    cout<<"------------------"<<p2.get_name()<<" is the Winner. ------------------"<<endl;
                    return;
                }
        }
    }

}

int main()
{
    //Declare The players
    Player p1;
    Player p2;

    //make all positions in the board with value (-)
    for (int i=0;i<3;i++)
    {
        for (int j=0;j<3;j++)
            board[i][j]='-';
    }
    cout<<"---------WELCOME IN TIC TAC TOE GAME------------"<<endl;
    cout<<"--------------Initial Board---------------"<<endl;
    print_board();

    play(p1,p2);



    return 0;
}
