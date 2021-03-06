/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   main.cpp
 * Author: Ikenna Eke
 *
 * Created on October 18, 2018, 11:18 AM
 */
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <fstream>
using namespace std;

/*
 *
 */
int main(int argc, char** argv) {
    
    srand(static_cast<unsigned int>(time(0)));
    unsigned short card = (rand()%10)+1, wins = 0, lose = 0;
    bool quit = false;
    string input;

    do{
        cout<<"Would you Like to play a round BlackJack\nEnter Yes or No: ";
        cin>>input;
        if(input == "Yes"){
            quit = false;
        }
        else if(input == "No"){
            exit(0);
        }
    }
    while(input != "Yes" && input != "No" );
    input="";
     cout<<"One round of BlackJack is going to be 5 games"<<endl
             <<"Quick Reminder A's are counted as only 1"<<endl
     <<"All Face Cards count as 10"<<endl<<endl;
    
         ofstream results;
         results.open("Results.txt");
        do{
            for(int i = 1; i<=5;i++){
            unsigned short ySum = 0, dSum = 0;
            ySum+= card;
            card = (rand()%10)+1;
            ySum+= card;
            cout<<"Dealer deals you two cards. The sum of  the two cards are "<<ySum<<endl;
            cout<<"Do you want you want to hit or stay: ";
            cin>>input;
            cout<<endl;

            while(input != "stay" && input != "hit"){
                cout<<"The sum of your two cards are "<<ySum<<endl;
                cout<<"Do you want you want to hit or stay: ";
                cin>>input;
            }

            while(input == "hit" && ySum<21){
                card = (rand()%10)+1;
                ySum+= card;
                if(ySum<21){
                    do{
                    cout<<"That makes "<<ySum<<endl;
                    cout<<"Do you want you want to hit or stay: ";
                    cin>>input;
                    }while(input != "stay" && input != "hit");
                    cout<<endl;
                }
            }

            while(input == "stay" &&dSum<=ySum&&dSum<20){
                card = (rand()%10)+1;
                dSum+= card;
            }


            if(ySum == 21){
                cout<<endl;
                cout<<"Congrats!!!! You Won you got 21!!!\n\n";
                wins++;
            }
            else if (ySum>21){
                cout<<endl;
                cout<<"That makes "<<ySum
                        <<", Sorry that over 21. You bust!!!\n\n";
                lose++;
            }
            else if(dSum == 21){
                cout<<"Sorry, You lose! Dealer got 21!!!\n\n";
                lose++;
            }
            else if (dSum>21){
                cout<<"Congrats!!!! You Win, Dealer bust\n\n";
                wins++;
            }
            else if(dSum>ySum){
                cout<<"Sorry, You lose! Dealer has "<<dSum<<endl;
                cout<<"While you have "<<ySum<<endl<<endl;
                lose++;
            }
        }
            cout<<endl;
        
        do{
            input ="";
        cout<<"Would you Like to play another Round\nEnter Yes or for No: ";
        cin>>input;
        if(input == "Yes"){
            quit = false;
        }
        else if(input == "No"){
            quit= true;
        }
    } while(input != "Yes" && input != "No" );

    cout<<endl;

    }while(quit == false);
    results<<"Results of Today's matches of BlackJack: \n";
    results<<"Games Played: "<<wins+lose<<"\n ";
    results<<"Wins: "<<wins<<"\n ";
    results<<"Loses: "<<lose<<"\n ";
    results<<setprecision(2)<<fixed<<"Win percentage of "<<static_cast<float>((wins/(wins+lose)*100));
    results.close();
    return 0;
}

