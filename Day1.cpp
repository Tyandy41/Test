#include <iostream>
using namespace std;

/*
    pygame 2d simulation
    mujoco 3d simulation (Physics I.e kinemaitcs, etc)
    webots 3d simulation (Movement)
    urdf Darwin OP 2
    OOP (Object Oriented Pro)
    KPP day one
*/

class simulator{ //maybe to track ingame time(?)
    public:
};

class Field{ //maybe I could use this to track the position of the robot and ball (NOTE: robot doesnt know where the ball is0)
    public:
char array[12][18] =
{
{ '.', '.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.'},
{ '.', '.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.'},
{ '.', '.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.'},
{ '.', '.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','#'},
{ '.', '.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','#'},
{ '.', '.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','#'},
{ '.', '.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','#'},
{ '.', '.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','#'},
{ '.', '.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','#'},
{ '.', '.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.'},
{ '.', '.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.'},
{ '.', '.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.'},
};
};

class Ball{ //probably for speed calculation
    
};

class Robot{
private:
    bool Robotisactive = true;
//gotta add position, speed, orientaion(?)
    int xrobot;
    int yrobot;
    
public:
    //ytta

/* Brainstorming
what I need:
- Locate the robot & Ball (for now, scan every )

- Movement algorithm

this is the state of the robot
- Make a Patroling algorithm
- make a chasing algorithm
- make a shooting algorithm

Note:
This is the scan area
      @
    @ @
  @ @ @
R @ @ @
  @ @ @
    @ @
      @


@           @
@ @       @ @
@ @ @   @ @ @
@ @ @ R @ @ @
@ @ @   @ @ @
@ @       @ @
@           @


Scanning radius is 7x7

area 18 x 12

I should add the moving algorithm first

The task is composed of 
- The field
- the goal
- the robot
- the ball
*/

};

class stricker : public Robot{

};


int main(){
    Field a;

//while(!(goal == true))

    for(int i = 0; i < 12; i++){
        for(int j = 0; j < 18; j++){
            cout << a.array[i][j] << " ";
        }  
        cout << endl;
    }

}