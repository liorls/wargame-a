#include <iostream>
#include "Soldier.hpp"

class Sniper : public Soldier {

public:
    Sniper(int s): Soldier(s, 100, 50) {}

  //  void attack(vector<vector<Soldier*>> &b, pair<int,int> location);
};