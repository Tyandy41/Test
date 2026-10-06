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

Im gonna connect all of them with the simulator class to make it more centralized.
*/

class simulator{ //maybe to track ingame time(?)
    
    public:
    int Time = 0;
    
};

class Robot : public simulator{

private:
    bool Robotisactive = true;
    
//gotta add position, speed, orientaion(?)




    
public:

//robot location

};

class Field : public simulator{ //maybe I could use this to track the position of the robot and ball (NOTE: robot doesnt know where the ball is0)
    private:
    Robot robot1;
    public:
char map[12][18] =
{
{ '.', '.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.'},
{ '.', '.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.'},
{ '.', '.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','R'},
{ '.', '.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','#'},
{ '.', '.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','#'},
{ '.', '.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','#'},
{ '.', '.','.','.','.','.','.','.','.','.','.','.','O','.','.','.','.','#'},
{ '.', '.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','#'},
{ '.', '.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','#'},
{ '.', '.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.'},
{ '.', '.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.'},
{ '.', '.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.'},
};

//robot location
int xrobot;
int yrobot;
bool robotlocation = false; //true = is on field, false = not on field

//ball location
int xball;
int yball;
bool balllocation = false;

//find robot location
void findlocation(){
    for(int x = 0;  x < 18; x++){
        if(robotlocation == true && balllocation == true){
            break;
        }
        for(int y = 0; y < 12; y++){
            if(map[y][x] == 'R'){
                xrobot = x;
                yrobot = y; 
                robotlocation = true;
            }

            if(map[y][x] == 'O'){
                xball = x;
                yball = y;
                balllocation = true;
            }
        }
    }

    //cout << xrobot << " " << yrobot << endl;
    //cout << xball << " " << yball;
}
};

class Ball : public simulator{ //probably for speed calculation
    bool Active = false;
    

};

class stricker : public Robot{ // stricker is inheriting from both the simulator and robot class;

};


int main(){
    simulator b;
    Field a;

//while(!(goal == true))

    for(int i = 0; i < 12; i++){
        for(int j = 0; j < 18; j++){
            cout << a.map[i][j] << " ";
        }  
        cout << endl;
    }


    a.findlocation();

}