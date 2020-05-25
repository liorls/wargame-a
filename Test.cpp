// #include <iostream>
// #include <string>
// #include <iostream>
// #include "doctest.h"
// #include "DemoGame.hpp"
// #include "Soldier.hpp"
// #include "Board.hpp"
// #include "FootCommander.hpp"
// #include "FootSoldier.hpp"
// #include "Sniper.hpp"
// #include "SniperCommander.hpp"
// #include "Paramedic.hpp"
// #include "ParamedicCommander.hpp"
// #include <cassert>

// using namespace std;
// using namespace WarGame;




// TEST_CASE("Test case 1") {
//    	for(int i = 0 ; i < 100 ; i++){
//         CHECK(true);
//         CHECK_NOTHROW(FootSoldier s = FootSoldier(1));
//         CHECK_NOTHROW( FootCommander s = FootCommander(1));
//         CHECK_NOTHROW( Sniper s = Sniper(1));
//         CHECK_NOTHROW( SniperCommander s = SniperCommander(1));
//         CHECK_NOTHROW( Paramedic s = Paramedic(1));
//         CHECK_NOTHROW( ParamedicCommander s = ParamedicCommander(1));
//        // CHECK_NOTHROW( Board board(8,8));
        
//         Board board(8,8);
//         CHECK_NOTHROW((board[{0,0}] = new FootSoldier(1)));
//         CHECK_NOTHROW((board[{0,1}] = new FootCommander(1)));
//         CHECK_NOTHROW((board[{0,2}] = new Paramedic(1)));
//         CHECK_NOTHROW((board[{0,3}] = new ParamedicCommander(1)));
//         CHECK_NOTHROW((board[{0,4}] = new Sniper(1)));
//         CHECK_NOTHROW((board[{0,5}] = new SniperCommander(1)));

//         CHECK_THROWS((board[{0,3}] = new SniperCommander(1))); // throws exeption there is allready soldier there
//         CHECK_THROWS((board[{0,5}] = new SniperCommander(1)));
        
//         CHECK_NOTHROW((board[{7,0}] = new FootSoldier(2)));
//         CHECK_NOTHROW((board[{7,1}] = new FootCommander(2)));
//         CHECK_NOTHROW((board[{7,2}] = new Paramedic(2)));
//         CHECK_NOTHROW((board[{7,3}] = new ParamedicCommander(2)));
//         CHECK_NOTHROW((board[{7,4}] = new Sniper(2)));
//         CHECK_NOTHROW((board[{7,5}] = new SniperCommander(2)));

// };
    
// }


 