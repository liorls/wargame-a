#include <iostream>
#include "Soldier.hpp"

class FootSoldier : public Soldier {

public:
    FootSoldier(int fs): Soldier(fs, 100, 10) {}

    //void attack(vector<vector<Soldier*>> &b, pair<int,int> location);
};