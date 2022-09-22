#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

class black_jack
{
protected:
int card1, card2, dealerCV, bet;
int playerCV = 0;
int cash = 1000;
public:
int GetCardValue()
{
    int x;

    x = 1 + rand() % 15;

    if (x >= 12)
        return 10;
    else
        return x;

}


void Input1()
{

    char choice;
    cout << endl;

    cin >> choice;

    switch (choice)
    {
    case 'q':
        card1 = 1;
        break;
    case 'w':
        card1 = 11;
        break;
    }

}

void Input2()
{

    char choice;
    cout << endl;

    cin >> choice;

    switch (choice)
    {
    case 'z':
        card2 = 1;
        break;
    case 'x':
        card2 = 11;
        break;
    }

}

void Continue()
{
    char key;
    cout << endl;
    cout << "Press R then <enter> to restart game" << endl;
    cin >> key;
    system("CLS");
}


void DisplayCardValue()
{
    int flag1, flag2;

    playerCV = 0;
    flag1 = 0;
    flag2 = 0;
    card1 = GetCardValue();
    card2 = GetCardValue();

    cout << "Cash: $" << cash << endl << endl;

    if (cash <= 0)
    {
        cout << "Your bankrupt, GAME OVER!" << endl;
        cash = 500;
        Continue();
        DisplayCardValue();
    }

    if (cash >= 10000)
    {
        cout << "You Win!" << endl;
        cash = 500;
        Continue();
        DisplayCardValue();
    }

    if (card1 == 11)
    {
        cout << "Your first card is: " << "ACE";
        flag1 = 1;
    }
    else if (card1 == 1)
    {
        cout << "Your first card is: " << "ACE";
        flag1 = 1;
    }
    else
        cout << "Your first card is: " << card1;

    cout << endl << endl << "Place your bet: $";
    cin >> bet;

    if (bet > cash)
    {
        cout << endl;
        cout << "You cannot bet more than you have" << endl;
        Continue();
        DisplayCardValue();
    }

    cout << endl;

    if (card2 == 11)
    {
        cout << "Your second card is: " << "ACE" << endl;
        flag2 = 1;
    }
    else if (card2 == 1)
    {
        cout << "Your second card is: " << "ACE" << endl;
        flag2 = 1;
    }
    else
        cout << "Your second card is: " << card2 << endl;

    cout << endl;

    if (flag1 == 1)
    {
        cout << "(Q)First card is 1 | (W)First card is 11" << endl;
        Input1();
    }

    if (flag2 == 1)
    {
        cout << "(Z)Second card is 1 | (X)Second card is 11" << endl;
        Input2();
    }

    playerCV = card1 + card2;

    cout << "Your total card value is " << playerCV << endl;

    if (playerCV == 21)
    {
        system("CLS");
        cout << endl << "BLACKJACK!!!" << endl;
        cash = cash + bet * 5;
        Continue();
        DisplayCardValue();
    }

    cout << endl;

    Stand_Hit();

}


void Stand_Hit()
{
    char choice;

    cout << "(S)stand | (H)hit" << endl;

    cout << endl;
    cin >> choice;

    switch (choice)
    {
    case 'h':
        playerCV = playerCV + GetCardValue();
        if (playerCV > 21)
        {
            system("CLS");
            cout << "Your total card value is " << playerCV << endl;
            cout << "You bust" << endl;
            cash = cash - bet;
            Continue();
            DisplayCardValue();
        }
        system("CLS");
        cout << "Your total card value is " << playerCV << endl << endl;
        Stand_Hit();
        break;
    case 's':
        system("CLS");
        Result();
        break;
    }

}

void Result()
{
    dealerCV = Dealer();

    cout << "Your total card value is " << playerCV << endl;
    if (playerCV > 21)
    {
        cout << "You bust" << endl;
        cash = cash - bet;
        Continue();
        DisplayCardValue();
    }
    else
        cout << "Dealer's total card value is " << dealerCV << endl << endl;
    if (dealerCV > 21)
    {
        cout << "Dealer busts" << endl;
        cash = cash + bet;
        Continue();
        DisplayCardValue();
    }
    else
    {
        if (playerCV > dealerCV)
        {
            cout << "You win" << endl;
            cash = cash + bet;
        }
        if (playerCV == dealerCV)
            cout << "It's a draw" << endl;
        if (playerCV < dealerCV)
        {
            cout << "You lose" << endl;
            cash = cash - bet;
        }
        Continue();
        DisplayCardValue();
    }
}

int Dealer()
{
    int c1, c2, cv, f1, f2;

    c1 = GetCardValue();
    c2 = GetCardValue();

    if (c1 == 11)
        f1 = 1;

    if (c2 == 11)
        f2 = 1;

    cv = c1 + c2;

    while (cv <= 16)
        cv = cv + GetCardValue();

    if (cv > 21 & f1 == 1)
    {
        while (cv <= 16)
            cv = 1 + c2 + GetCardValue();
    }

    if (cv > 21 & f2 == 1)
    {
        while (cv <= 16)
            cv = c1 + 1 + GetCardValue();
    }

    return cv;
}

};
int main()
{
    black_jack game;
    srand(time(NULL));
    game.DisplayCardValue();
     return 0;
}
