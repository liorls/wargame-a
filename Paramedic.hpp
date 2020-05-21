#include <iostream>
#include "Soldier.hpp"

class Paramedic : public Soldier {

public:
    Paramedic(int p): Soldier(p, 100, 50) {}

   // void attack(vector<vector<Soldier*>> &b, pair<int,int> location);
};