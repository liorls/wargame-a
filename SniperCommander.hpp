#include <iostream>
#include "Soldier.hpp"

class SniperCommander : public Soldier {

public:
    SniperCommander(int sc): Soldier(sc, 120, 100) {}

   // void attack(vector<vector<Soldier*>> &b, pair<int,int> location);
};