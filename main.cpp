#include <iostream>
using namespace std;
#include "Player.cpp"

int main() {
  int option;
  srand(time(NULL));
  //Start Page
  cout<<"\e[2J\e[H";
  cout << "               Welcome to Valorant-Text based game...!!!"<<endl;
  cout << "                              2-Player text based game "<<endl;
  cout << "                              Made by Anvit "<<endl;
  cout << "        Press 1 to Start\n        Press 2 to Quit"<<endl;
  cin >> option;
  switch(option){
    case 1:
    start:
      cout<<"\e[2J\e[H";
    characterSelectP1:
      cout << "Character Selection"<<endl;
      cout << "Player 1\nChoose your Character\n1.Astra(Controller)\n2.Jett(Duelist)\n3.KillJoy(Sentinal)"<<endl;
      cin >> option;
      Player *player1;
      switch(option){
        case 1:{
          Brainy Player1;
          player1 = &Player1;
          cout << "My plan may sound irrational, only because you cannot see what i can!" << endl;
          cin.ignore();
          cout << "Press Enter to continue";
          cin.get();

          
          break;}
        case 2:{
          Assaulter Player1;
          player1 = &Player1;
          cout << "I know i dash around a lot, but i promise I'm looking out for y'all. Take them out while they're busy with me." << endl;
          cout << endl << "Press any key to continue" << endl ;
          cin.ignore();
          cout << "Press Enter to continue";
          cin.get();
          break;}
        case 3:{
          Defender Player1;
          player1 = &Player1;
          cout << "Okay, I put together some data on our last six combat missions. Did you read it? Did anyone...read it? Oh God...can anyone here read?" << endl;
          cin.ignore();
          cout << "Press Enter to continue";
          cin.get();
          break;}
        default:
          goto characterSelectP1; 
      }
      cout<<"\e[2J\e[H";
    characterSelectP2:
      cout << "Character Selection"<<endl;
      cout << "Player 2\nChoose your Character\n1.Astra(Controller)\n2.Jett(Duelist)\n3.KillJoy(Sentinal)"<<endl;
      cin >> option;
      Player *player2;
      switch(option){
        case 1:{
          Brainy Player2;
          player2 = &Player2;
          cout << "My plan may sound irrational, only because you cannot see what i can!" << endl;
          cin.ignore();
          cout << "Press Enter to continue";
          cin.get();
          break;}
        case 2:{
          Assaulter Player2;
          player2 = &Player2;
          cout << "I know i dash around a lot, but i promise I'm looking out for y'all. Take them out while they're busy with me." << endl;
          cin.ignore();
          cout << "Press Enter to continue";
          cin.get();
          break;}
        case 3:{
          Defender Player2;
          player2 = &Player2;
          cout << "Okay, I put together some data on our last six combat missions. Did you read it? Did anyone...read it? Oh God...can anyone here read?" << endl;
          cin.ignore();
          cout << "Press Enter to continue";
          cin.get();
          break;}
        default:
          goto characterSelectP2; 
      }
    fightBeginsP1:
      cout<<"\e[2J\e[H";
      cout << "Player 1\nChoose what you would like to do"<<endl;
      cout << "1.Attack\n2.Heal"<<endl;
      cin >> option;
      switch(option){
        case 1:{
          player2->takeDamage(player1->doDamage());
          cout << "Player 2 Health = " << player2->getHealth() << endl;
          cout << "\nPress any key to Continue" << endl;
          cin >> option;
          if(player2->getHealth()<=0){
            goto GamewonP1;
          }
          else{
            switch(option){
            case 1:
              goto fightBeginsP2;
            default:
              goto fightBeginsP2;
            }
          }
        }
        case 2:{
          cout << "Before Heal health was " << player1->getHealth() << endl;
          player1->Heal();
          cout << "After Heal health is " << player1->getHealth() << endl;
          cout << "\nPress any key to Continue" << endl;
          cin >> option;
          switch(option){
            case 1:
              goto fightBeginsP2;
            default:
              goto fightBeginsP2;
          }
        }
        default:
          goto fightBeginsP1;
      }
    fightBeginsP2:
      cout<<"\e[2J\e[H";
      cout << "Player 2\nChoose what you would like to do"<<endl;
      cout << "1.Attack\n2.Heal"<<endl;
      cin >> option;
      switch(option){
        case 1:{
          player1->takeDamage(player2->doDamage());
          cout << "Player 1 Health = " << player1->getHealth() << endl;
          cout << "\nPress any key to Continue" << endl;
          cin >> option;
          if(player1->getHealth()<=0){
            goto GamewonP2;
          }
          else{
            switch(option){
            case 1:
              goto fightBeginsP1;
            default:
              goto fightBeginsP1;
            }
          }
        }
        case 2:{
          cout << "Before Heal health was " << player2->getHealth() << endl;
          player2->Heal();
          cout << "After Heal health is " << player2->getHealth();
          cout << "\nPress any key to Continue" << endl;
          cin >> option;
          switch(option){
            case 1:
              goto fightBeginsP1;
            default:
              goto fightBeginsP1;
          }
        }
        default:
          goto fightBeginsP2;
      }
    GamewonP1:
      cout<<"\e[2J\e[H";
      cout << "!!!! Player 1 has won !!!!" << endl;
      cout << "Press\n1 to Playe Again\n2 to Quit" << endl;
      cin >> option;
      switch(option){
        case 1:
          goto start;
        case 2:
          goto stop;
        default:
          goto GamewonP1;
      }
    GamewonP2:
      cout<<"\e[2J\e[H";
      cout << "!!!! Player 2 has won !!!!" << endl;
      cout << "Press\n1 to Playe Again\n2 to Quit" << endl;
      cin >> option;
      switch(option){
        case 1:
          goto start;
        case 2:
          goto stop;
        default:
          goto GamewonP2;
      }
      break;
    case 2:
    stop:
      cout<<"\e[2J\e[H";
      cout << "               Thanks for Playing!\n               Have a Nice Day"<<endl;
      break;
    default:
    invainput:
      int dflt;
      cout<<"\e[2J\e[H";
      cout << "Invalid Input Try Again"<< endl;
      cout << "Press 1 to Start\nPress 2 to Quit"<<endl;
      cin >> dflt;
      switch(dflt){
          case 1:
            goto start;
          case 2:
            goto stop;
          default:
            goto invainput;
      }
  }

};