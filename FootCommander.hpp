#include <iostream>
#include "Soldier.hpp"

class FootCommander : public Soldier {

public:
    FootCommander(int fc): Soldier(fc, 150, 20, 150) {}

    void attack(vector<vector<Soldier*>> &b, pair<int,int> location);
};