/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   main.cpp
 * Author: Ikenna Eke
 * Purpose: Game of BlackJacks
 * Created on November 3, 2018, 11:18 AM
 */
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <fstream>
#include <cmath>
using namespace std;

/*
 *
 */
char getCard();
int main(int argc, char** argv) {
    
    srand(static_cast<unsigned int>(time(0)));
    unsigned short wins = 0, //Games Won
            lose = 0;  //Games lost
    char card; //Card Drawn
    bool quit = false; //True - games End, False - game continues 
    string input; //What the User inputs

    do{
        //ask User if they want to play a game
        cout<<"Would you Like to play a round BlackJack\nEnter Yes or No: ";
        cin>>input;
        if(input == "Yes"){
            quit = false; //User enter Yes game starts
        }
        else if(input == "No"){
            exit(0); //User enter no the program exits
        }
    }
    while(input != "Yes" && input != "No" );
    input="";
     cout<<"Quick Reminder A's are counted as only 1"<<endl
     <<"All Face Cards count as 10"<<endl<<endl;
    
         ofstream results; //File reader
         results.open("Results.txt"); //Opens File That will store results
         
        do{
            unsigned short ySum = 0, //User's Sum 
                    dSum = 0; //Dealer's sum
            //Loops twice to give the user the total of his first two cards
            for(int i = 0; i<2;i++){
            card = getCard();
            // If Card comes out as Q,J, T, or K gives User a value of 10
                if(card =='Q'||card=='J'||card=='T'||card =='K'){
                    ySum+= 10;
                }
                // IF Card come out as A give user value of 1
                else if(card == 'A'){
                    ySum+=1;
                }
                
                //Else gives user a value of 2-9
                else{
                    ySum += (static_cast<int>(card)-48);
                }
            }
            //Shows user the value of their two cards and ask them enter either hit or stay
            cout<<"Dealer deals you two cards. The sum of  the two cards are "<<ySum<<endl;
            cout<<"Do you want you want to hit or stay: ";
            cin>>input;
            cout<<endl;
            
            //If the user input is neither hit or stay the program will keep looping to this
            //till the user enter hit or stay
            while(input != "stay" && input != "hit"){
                cout<<"The sum of your two cards are "<<ySum<<endl;
                cout<<"Do you want you want to hit or stay: ";
                cin>>input;
            }
            
            //calculates the uses sum
            while(input == "hit" && ySum<21){
                card = getCard();
                if(card =='Q'||card=='J'||card=='T'||card =='K'){
                    ySum+= 10;
                }
                else if(card == 'A'){
                    ySum+=1;
                }
                else{
                    ySum += (static_cast<int>(card) -48);
                }
                if(ySum<21){
                    do{
                    cout<<"That makes "<<ySum<<endl;
                    cout<<"Do you want you want to hit or stay: ";
                    cin>>input;
                    }while(input != "stay" && input != "hit");
                    cout<<endl;
                }
            }
            //User enter stay, calculates the dealers sum 
            while(input == "stay" &&dSum<=ySum&&dSum<20){
                 card = getCard();
                if(card =='Q'||card=='J'||card=='T'||card =='K'){
                    dSum+= 10;
                }
                else if(card == 'A'){
                    dSum+=1;
                }
                else{
                    dSum += (static_cast<int>(card)-48);
                }
            }

            //Checks the user sum and deal sums and prints the out results of 
            //either the user wins or the dealer wins
            if(ySum == 21){
                cout<<endl;
                cout<<"Congrats!!!! You Won you got 21!!!\n\n";
                wins++;
            }
            else if (isgreater(ySum,21)){
                cout<<endl;
                cout<<"That makes "<<ySum
                        <<", Sorry that over 21. You bust!!!\n\n";
                lose++;
            }
            else if(dSum == 21){
                cout<<"Sorry, You lose! Dealer got 21!!!\n\n";
                lose++;
            }
            else if (isgreater(dSum,21)){
                cout<<"Congrats!!!! You Win, Dealer bust\n\n";
                wins++;
            }
            else if(dSum>ySum){
                cout<<"Sorry, You lose! Dealer has "<<dSum<<endl;
                cout<<"While you have "<<ySum<<endl<<endl;
                lose++;
            }
            cout<<endl;
        
        //Ask User if they would like to play again
        do{
            input ="";
        cout<<"Would you Like to play another game\nEnter Yes or for No: ";
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
    //Outputs the results of the games played to a file called Result.txt
    results<<"Results of Today's matches of BlackJack: \n";
    results<<"Games Played: "<<wins+lose<<"\n ";
    results<<"Wins: "<<wins<<"\n ";
    results<<"Loses: "<<lose<<"\n ";
    results<<setprecision(2)<<fixed<<"Win percentage of "<<static_cast<float>((wins/(wins+lose)*100));
    results.close();
    return 0;
}

char getCard(){
    //Declare variables
    fstream in;
    string rCard;
    int nLines;
    //Initialize variables
    in.open("card.dat");
    nLines=rand()%52+1;//Possible 52 cards in the file
    //Look through file to find the random color
    for(int line=1;line<=nLines;line++){
        in>>rCard;
    }
    //Close the file
    in.close();
    //Return the random color
    
    return rCard.at(0);
}


