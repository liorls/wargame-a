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


 
#include "doctest.h"
#include "Board.hpp"
#include "FootSoldier.hpp"
#include "FootCommander.hpp"
#include "Sniper.hpp"
#include "SniperCommander.hpp"
#include "Paramedic.hpp"
#include "ParamedicCommander.hpp"

using namespace std;

namespace WarGame{

TEST_CASE("Test 1") {
    Board board(10,10);
    CHECK(board.has_soldiers(2)== false);
    CHECK(board.has_soldiers(3)== false);
    CHECK(board.has_soldiers(4)== false);
    CHECK(board.has_soldiers(8)== false);
    CHECK(board.has_soldiers(9)== false);
    CHECK(board.has_soldiers(1)== false);
	board[{0,1}] = new FootSoldier(1);
    CHECK(board.has_soldiers(1)== true);
    board[{0,3}] = new FootCommander(1);
	board[{0,5}] = new Sniper(1);
    board[{0,6}] = new SniperCommander(1);
    board[{0,7}] = new Paramedic(1);
    board[{0,8}] = new ParamedicCommander(1);
	CHECK(board.has_soldiers(2)== false);
    CHECK(board.has_soldiers(7)== false);
	board[{9,1}] = new FootSoldier(2);
	board[{9,3}] = new FootCommander(2);
	board[{9,5}] = new FootSoldier(2);
	CHECK(board.has_soldiers(2)== true);
    board[{9,6}] = new SniperCommander(2);
    board[{9,7}] = new Paramedic(2);
    board[{9,8}] = new ParamedicCommander(2);
    CHECK_THROWS_AS(board.move(1, {0,2}, Board::MoveDIR::Left),std::invalid_argument);
    CHECK_THROWS_AS(board.move(2, {0,2}, Board::MoveDIR::Left),std::invalid_argument);
    board.move(1, {0,1}, Board::MoveDIR::Right);
    CHECK_THROWS_AS(board.move(1, {0,2}, Board::MoveDIR::Right),std::invalid_argument);
    CHECK_THROWS_AS(board.move(2, {0,5}, Board::MoveDIR::Right),std::invalid_argument);
    CHECK_THROWS_AS(board.move(2, {9,7}, Board::MoveDIR::Right),std::invalid_argument);
    CHECK_THROWS_AS(board.move(1, {9,5}, Board::MoveDIR::Right),std::invalid_argument);
    for (int i = 0; i < 100; i++) {
                CHECK(!board.has_soldiers(10));
    }

}
}



// #include <iostream>
//  #include <string>
//  #include <iostream>
//  #include "Soldier.hpp"
//  #include "doctest.h"
// // #include "DemoGame.hpp"
//  #include "Board.hpp"
//  #include "FootCommander.hpp"
//  #include "FootSoldier.hpp"
//  #include "Sniper.hpp"
//  #include "SniperCommander.hpp"
//  #include "Paramedic.hpp"
//  #include "ParamedicCommander.hpp"
//  #include <cassert>

//  using namespace std;
//  namespace WarGame{

    //  Board fillBoard() {
    //      Board p(6, 6);
    //      p[{1, 0}] = new Sniper(1);
    //      p[{3, 4}] = new FootSoldier(2);
    //      p[{5, 5}] = new FootCommander(1);
    //      p[{3, 5}] = new ParamedicCommander(2);
    //      p[{0, 1}] = new FootSoldier(2);
    //      p[{3, 3}] = new Sniper(2);
    //      p[{2, 1}] = new Paramedic(1);
    //      p[{4, 4}] = new SniperCommander(2);
    //      p[{5, 4}] = new Paramedic(1);
    //      p[{2, 3}] = new SniperCommander(2);
    //      p[{1, 5}] = new ParamedicCommander(1);
    //      p[{4, 1}] = new FootCommander(1);
    //  }

    //  TEST_CASE("Checking initial variables of each soldier"){
    //      FootSoldier* a= new FootSoldier(1);
    //              CHECK(a->numDamage==10);
    //              CHECK(a->numHealth==100);
    //             // CHECK(a->numPlayer==1);

    //      FootCommander* b= new FootCommander(1);
    //              CHECK(b->numDamage==20);
    //              CHECK(b->numHealth==150);
    //             // CHECK(b->numPlayer==1);

    //      Sniper* c= new Sniper(2);
    //              CHECK(c->numDamage==50);
    //              CHECK(c->numHealth==100);
    //             // CHECK(c->numPlayer==2);

    //      SniperCommander* d= new SniperCommander(2);
    //              CHECK(d->numDamage==100);
    //              CHECK(d->numHealth==120);
    //             // CHECK(d->numPlayer==2);

    //      Paramedic* e= new Paramedic(3);
    //              CHECK(e->numDamage==0);
    //              CHECK(e->numHealth==100);
    //             // CHECK(e->numPlayer==3);

    //      ParamedicCommander* f= new ParamedicCommander(4);
    //              CHECK(d->numDamage==0);
    //              CHECK(f->numHealth==200);
    //             // CHECK(f->numPlayer==4);
    //  }
//18
//      TEST_CASE("Empty board & Adding of Soldiers"){
//          Board b(6,6);
//              CHECK(board.has_soldiers(7)== false);

//                  CHECK(b.has_soldiers(1) == false);
//                  CHECK_FALSE(b.has_soldiers(2));
//                  CHECK_FALSE(b.has_soldiers(4));
//          b[{0,1}] = new FootSoldier(1);
//                  CHECK(b.has_soldiers(1));
//          b[{1,1}]= new FootCommander(2);
//                  CHECK(b.has_soldiers(2));
//      }
// //23
//      TEST_CASE("Checking the adding & type of soldier"){
//          Board board = fillBoard();
//                  CHECK(board.has_soldiers(1));
//                  CHECK(board.has_soldiers(2));
//                  CHECK(typeid(board[{1,0}]) == typeid(Sniper));
//                  CHECK(typeid(board[{3,4}]) == typeid(FootSoldier));
//                  CHECK(typeid(board[{5,5}]) == typeid(FootCommander));
//                  CHECK(typeid(board[{3,5}]) == typeid(ParamedicCommander));
//                  CHECK(typeid(board[{0,1}]) == typeid(FootSoldier));
//                  CHECK(typeid(board[{3,3}]) == typeid(Sniper));
//                  CHECK(typeid(board[{2,1}]) == typeid(Paramedic));
//                  CHECK(typeid(board[{4,4}]) == typeid(SniperCommander));
//                  CHECK(typeid(board[{5,4}]) == typeid(Paramedic));
//                  CHECK(typeid(board[{2,3}]) == typeid(SniperCommander));
//                  CHECK(typeid(board[{1,5}]) == typeid(ParamedicCommander));
//                  CHECK(typeid(board[{4,1}]) == typeid(FootCommander));
//      }
//      //37
//      TEST_CASE("Testing moving case"){
//          Board board = fillBoard();
//                  CHECK(board.has_soldiers(1));
//                  CHECK(board.has_soldiers(2));
//                  CHECK_FALSE(board.has_soldiers((3)));
//          //moving up from {1,0} to {2,0}
//                  CHECK(typeid(board[{1,0}]) == typeid(Sniper));
//          board.move(1,{1,0}, Board::MoveDIR::Up);
//                  CHECK(typeid(board[{2,0}]) == typeid(Sniper)) ;
//                  CHECK(typeid(board[{1,0}]) == nullptr) ;

//          //moving down from {2,0} back to {1,0}
//                  CHECK(typeid(board[{2,0}]) == typeid(Sniper));
//          board.move(1,{2,0}, Board::MoveDIR::Down);
//                  CHECK(typeid(board[{1,0}]) == typeid(Sniper)) ;
//                  CHECK(typeid(board[{2,0}]) == nullptr) ;

//          //moving left from {3,4} to {3,3}
//                  CHECK(typeid(board[{3,4}]) == typeid(FootSoldier));
//          board.move(2,{3,4}, Board::MoveDIR::Left);
//                 // CHECK(typeid(board[{3,3]}) == typeid(FootSoldier)) ;
//                  //CHECK(typeid(board[{3,4}]) == nullptr) ;

//          //moving right from {3,3} back to {3,4}
//                  CHECK(typeid(board[{3,3}]) == typeid(FootSoldier));
//          board.move(2,{3,3},Board::MoveDIR::Right);
//                  CHECK(typeid(board[{3,4}]) == typeid(FootSoldier)) ;
//                  CHECK(typeid(board[{3,3}]) == nullptr) ;
//      }

// //52
//      TEST_CASE("Foot soldiers") {
//          Board board(6, 1);
//                  CHECK_FALSE(board.has_soldiers(1));
//                  CHECK_FALSE(board.has_soldiers(2));
//          board[{0, 0}] = new FootSoldier(1);
//          board[{5, 0}] = new FootSoldier(2);
//                  CHECK(board.has_soldiers(1));
//                  CHECK(board.has_soldiers(2));

//          board.move(1, {0, 0}, Board::MoveDIR::Up); //player 1 move to {1,0}:damage 10
//          board.move(1, {1, 0}, Board::MoveDIR::Down); //player 1 move to {0,0}:damage 10
//                  CHECK(board.has_soldiers(1));
//                  CHECK(board.has_soldiers(2));
//          board.move(1, {0, 0}, Board::MoveDIR::Up); //player 1 move to {1,0}:damage 10
//          board.move(1, {1, 0}, Board::MoveDIR::Down); //player 1 move to {0,0}:damage 10
//                  CHECK(board.has_soldiers(1));
//                  CHECK(board.has_soldiers(2));
//          board.move(1, {0, 0},Board::MoveDIR::Up); //player 1 move to {1,0}:damage 10
//          board.move(1, {1, 0},Board::MoveDIR::Down); //player 1 move to {0,0}:damage 10
//                  CHECK(board.has_soldiers(1));
//                  CHECK(board.has_soldiers(2));
//          board.move(1, {0, 0}, Board::MoveDIR::Up); //player 1 move to {1,0}:damage 10
//          board.move(1, {1, 0},Board::MoveDIR::Down); //player 1 move to {0,0}:damage 10
//                  CHECK(board.has_soldiers(1));
//                  CHECK(board.has_soldiers(2));
//          board.move(1, {0, 0}, Board::MoveDIR::Up); //player 1 move to {1,0}:damage 10
//          //the last move of player 1 to kill player 2
//          board.move(1, {1, 0},Board::MoveDIR::Down); //player 1 move to {0,0}:damage 10
//                  CHECK(board.has_soldiers(1));
//                  CHECK_FALSE(board.has_soldiers(2));
//      }
//      //64
//      TEST_CASE("FootCommander"){
//          Board board(6, 1);
//                  CHECK_FALSE(board.has_soldiers(1));
//                  CHECK_FALSE(board.has_soldiers(2));
//          board[{0, 0}] = new FootCommander(1);
//          board[{5, 0}] = new FootCommander(2);
//                  CHECK(board.has_soldiers(1));
//                  CHECK(board.has_soldiers(2));


//          board.move(1, {0, 0}, Board::MoveDIR::Up); //player 1 move to {1,0}:damage 20
//          board.move(1, {1, 0}, Board::MoveDIR::Down); //player 1 move to {0,0}:damage 20
//                  CHECK(board.has_soldiers(1));
//                  CHECK(board.has_soldiers(2));
//          board.move(1, {0, 0}, Board::MoveDIR::Up); //player 1 move to {1,0}:damage 20
//          board.move(1, {1, 0}, Board::MoveDIR::Down); //player 1 move to {0,0}:damage 20
//                  CHECK(board.has_soldiers(1));
//                  CHECK(board.has_soldiers(2));
//          board.move(1, {0, 0}, Board::MoveDIR::Up); //player 1 move to {1,0}:damage 20
//          board.move(1, {1, 0}, Board::MoveDIR::Down); //player 1 move to {0,0}:damage 20
//                  CHECK(board.has_soldiers(1));
//                  CHECK(board.has_soldiers(2));
//          board.move(1, {0, 0}, Board::MoveDIR::Up); //player 1 move to {1,0}:damage 20
//          //last move of player 1 to kill player 2
//          board.move(1, {1, 0}, Board::MoveDIR::Down); //player 1 move to {0,0}:damage 20
//                  CHECK(board.has_soldiers(1));
//                  CHECK_FALSE(board.has_soldiers(2));
//      }
     //76
//      TEST_CASE("Exceptions"){
//         Board board = fillBoard();
//          //Destination is Out of board
//          CHECK_THROWS(board.move(1, {5, 5}, Board::MoveDIR::Up));
//          CHECK_THROWS(board.move(2, {0, 1}, Board::MoveDIR::Down));
//          CHECK_THROWS(board.move(1, {5, 5}, Board::MoveDIR::Right));
//          CHECK_THROWS(board.move(1, {1, 0}, Board::MoveDIR::Left));
//          CHECK_THROWS(board.move(1, {5, 5}, Board::MoveDIR::Up));
//          CHECK_THROWS(board.move(2, {0, 1}, Board::MoveDIR::Down));
//          //Source out of bound
//          CHECK_THROWS(board.move(1, {6, 0}, Board::MoveDIR::Up));
//          CHECK_THROWS(board.move(1, {7, 3}, Board::MoveDIR::Down));
//          CHECK_THROWS(board.move(1, {7, 7}, Board::MoveDIR::Right));
//          CHECK_THROWS(board.move(1, {5, 6}, Board::MoveDIR::Left));
//          CHECK_THROWS(board.move(1, {6, 0}, Board::MoveDIR::Up));
//          CHECK_THROWS(board.move(1, {7, 3}, Board::MoveDIR::Down));
//          CHECK_THROWS(board.move(1, {9, 0}, Board::MoveDIR::Left));
//          CHECK_THROWS(board.move(1, {8, 9}, Board::MoveDIR::Right));
//          //Busy place
//          CHECK_THROWS(board.move(2, {4, 4}, Board::MoveDIR::Up)); //moving it to {5,4} there is already soldier of player 1
//          CHECK_THROWS(board.move(1, {5, 4},Board::MoveDIR::Down)); //moving it to {4,4} there is already soldier of player 2
//          CHECK_THROWS(board.move(2, {3, 4}, Board::MoveDIR::Right));//moving it to {3,5} there is laready soldier of player 1
//         // CHECK_THROWS(board.move(1, {3, 5}, Board::MoveDIR::Left); //moving it to {3,4} there is already soldier of player 2
//          //Null Place
//          CHECK_THROWS(board.move(1, {1, 2},Board::MoveDIR::Up));
//          CHECK_THROWS(board.move(1, {4, 0}, Board::MoveDIR::Down));
//          CHECK_THROWS(board.move(1, {0, 0}, Board::MoveDIR::Left));
//          CHECK_THROWS(board.move(1, {3, 1},Board::MoveDIR::Right));
//          CHECK_THROWS(board.move(1, {1, 2},Board::MoveDIR::Up));
//          CHECK_THROWS(board.move(1, {4, 0}, Board::MoveDIR::Down));
//          CHECK_THROWS(board.move(1, {0, 0}, Board::MoveDIR::Left));
//          CHECK_THROWS(board.move(1, {3, 1}, Board::MoveDIR::Right));
//          CHECK_THROWS(board.move(1, {0, 0}, Board::MoveDIR::Left));
//          CHECK_THROWS(board.move(1, {3, 1}, Board::MoveDIR::Right));
//      }
// //100
 

//  }