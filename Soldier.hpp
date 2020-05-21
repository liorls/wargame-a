#pragma once

#include <stdexcept>
#include <math.h>
#include <vector>
#include <iostream>

using namespace std;
class Soldier
{

public:
    int numPlayer;    //uint ??
    int numHealth;
    int numDamage;
    Soldier(int numP, int numH, int numD): numPlayer(numP), numHealth(numH), numDamage(numD) {}
    ~Soldier() {}
  //  virtual void attack (std::vector<std::vector<Soldier*>> &b, pair<int,int> location) = 0;


};