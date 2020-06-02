#include <iostream>
#include "Soldier.hpp"

class ParamedicCommander : public Soldier {

public:
    ParamedicCommander(int pc): Soldier(pc, 200, 0, 200) {}

    void attack(vector<vector<Soldier*>> &b, pair<int,int> location);
};