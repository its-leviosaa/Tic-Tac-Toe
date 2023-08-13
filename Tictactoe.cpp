#include<iostream>
using namespace std;

class Player{
    private:
        string name;
        int score;
    public:

};

class Game{
    private:
        char board[9];
        //char 
};


int main()
{
    int choice;
    //infinite loop
    while(1)
    {
        cout<<"-------------MENU---------------"<<endl;
        cout<<" 1. One Player Game"<<endl;
        cout<<" 2. Two Player Game"<<endl;
        cout<<" 3. EXIT..."<<endl;
        cout<<"---------------------------------"<<endl;
        //closing the above line for making our code beautiful
        cout<<" Select any option from menu box."<<endl;
        cin>>choice;
        switch (choice)
        {
        case 1:
            cout<<" One Player Game"<<endl;
            break;
        case 2:
            cout<<" Two Player Game"<<endl;
            break;
        case 3:
            cout<<" Exit"<<endl;
            break;
        default:
            cout<<" Invalid choice"<<endl;
            break;
        }
    }
    return 0;
}