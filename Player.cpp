#include <iostream>
using namespace std;

class Player{
protected:
int Health;
int Damage;
int maxHealth;
public:
virtual int doDamage() = 0;
virtual void takeDamage(int damage) = 0;
virtual void Heal() = 0;
virtual int getHealth() = 0;
void displayAttack(){
  int r = 9;
  for (int i = 0; i<1 ; i++){
    for (int j =0 ; j<r; j++){
      if(j==4){
        cout << "*";
      }
      else{
        cout << " ";
      }
    }
    cout << endl;
  }
  for (int i = 1; i<r-3 ; i++){
    for (int j = 0; j<r-3 ;j++){
      if(j == 3 || j == 5){
        cout << "*";
      }
      else{
        cout << " ";
      }
    }
    cout << endl;
  }
  for (int i = r-3; i<r-2 ; i++){
    for (int j = 0; j<r ;j++){
      if(j == 3 || j == 5 || j == 2 || j == 6){
        cout << "*";
      }
      else{
        cout << " ";
      }
    }
    cout << endl;
  }
  for (int i = r-2; i<r ; i++){
    for (int j = 0; j<r ;j++){
      if(j>=3 && j<=5){
        cout << "*";
      }
      else{
        cout << " ";
      }
    }
    cout << endl;
  }
}
void displayHealth(){
  int r = 6;
  for (int i = 0; i<r-4 ; i++){
    for (int j =0 ; j<r; j++){
      if(j==3){
        cout << "+";
      }
      else{
        cout << " ";
      }
    }
    cout << endl;
  }
  for (int i = r-2; i<r-1 ; i++){
    for (int j =0; j<r+1; j++){
      if(j%2==0){
        cout << "+";
      }
      else{
        cout << " ";
      }
    }
    cout << endl;
  }
  for (int i = 0; i<r-4 ; i++){
    for (int j =0 ; j<r; j++){
      if(j==3){
        cout << "+";
      }
      else{
        cout << " ";
      }
    }
    cout << endl;
  }
}
};
class Brainy:public Player{
  public:
  Brainy(){
    Health = 150;
    Damage = 15;
    maxHealth = Health;
  }
  int doDamage()
  {
    cout<<"\e[2J\e[H";
    displayAttack();
    Damage += 1 + rand()%((20+1)-1);
    return Damage;
  }
  void takeDamage(int damage){
    Health -= damage; 
  }
  void Heal(){
    displayHealth();
    if(Health<maxHealth){
      Health += 1 + rand()%((15+1)-1);
      if(Health>maxHealth){
        Health = maxHealth;
      }
    }
  }
  int getHealth(){
    return Health;
  }
};
class Assaulter:public Player{
  public:
  Assaulter(){
    Health = 100;
    Damage = 20;
    maxHealth = Health;
  }
  int doDamage()
  {
    cout<<"\e[2J\e[H";
    displayAttack();
    Damage += 1 + rand()%((20+1)-1);
    return Damage;
  }
  void takeDamage(int damage){
    Health -= damage; 
  }
  void Heal(){
    displayHealth();
    if(Health<maxHealth){
      Health += 1 + rand()%((15+1)-1);
      if(Health>maxHealth){
        Health = maxHealth;
      }
    }
  }
  int getHealth(){
    return Health;
  }
};
class Defender:public Player{
  public:
  Defender(){
    Health = 200;
    Damage = 10;
    maxHealth = Health;
  }
  int doDamage()
  {
    cout<<"\e[2J\e[H";
    displayAttack();
    Damage += 1 + rand()%((20+1)-1);
    return Damage;
  }
  void takeDamage(int damage){
    Health -= damage; 
  }
  void Heal(){
    displayHealth();
    if(Health<maxHealth){
      Health += 1 + rand()%((10+1)-1);
      if(Health>maxHealth){
        Health = maxHealth;
      }
    }
  }
  int getHealth(){
    return Health;
  }
};
