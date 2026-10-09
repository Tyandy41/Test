#include <iostream>
#include <vector>
#include <functional>
using namespace std;

/*
    pygame 2d simulation
    mujoco 3d simulation (Physics I.e kinemaitcs, etc)
    webots 3d simulation (Movement)
    urdf Darwin OP 2
    OOP (Object Oriented Pro)
    KPP day one

    I think im just gonna find a way to connect all these classes first
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
    bool Robotispresent = false;
    bool Patroling = false;
    bool running = false;
    bool balldetected = false;
    bool kickkingrange = false;

    int x = 0;
    int y = 0;




    //AI assisted
    vector<function<void(int x, int y)>> movecomunication;
    //storage for the callback
//tbh idk if im gonna use all of this :D
//gotta add position, speed, orientaion(?)

public:

    int getxrobot() const {return x;}
    int getyrobot() const {return y;}
    //AI assited
    void comunication(function<void(int x, int y)> callback){
        movecomunication.push_back(callback);
    } //to comunicate between classes

    //AI assisted
    void move(int dx, int dy){
        x += dx;
        y += dy;

        for (const auto& callback : movecomunication) {
            callback(x, y);
        }
    }

    virtual void think(){

    }

}; 

class Field : public simulator{ //maybe I could use this to track the position of the robot and ball (NOTE: robot doesnt know where the ball is0)
    private:
    
    public:
char map[12][18] =
{
{ '.', '.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.'},
{ '.', '.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.'},
{ '.', '.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.'},
{ '.', '.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','#'},
{ '.', '.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','#'},
{ '.', '.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','#'},
{ '.', '.','.','.','.','.','.','R','.','.','.','.','.','.','O','.','.','#'},
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

//ball location (side note, maybe I couldve used struct?) (another side note, Do I even need this???)
//(another nother sidenote, maybe I can use it to make sure that its a valid map in the first place?)
int xball;
int yball;
bool balllocation = false;

void onmove(int x, int y){
     for(int i = 0; i < 12; i++){
        for(int j = 0; j < 18; j++){
            cout << map[i][j] << " ";
        }  
        cout << endl;
    }
}

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

            /**/
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

class scan : public simulator{
    private:
    Field a;
//with the robot's position as its basis    
//im so lost rn
    public:

    bool ballislocated = false;
    int counter1 = 1; //for x
    int counter2 = 0; //for y(?)
    
    void scanning(){
    
        //assume robot location = (0, 0)
    /*  
    for(int i = a.yrobot; i < 10; i++){ //y
        for(int j = a.xrobot; j < 10; j++){ //x
            if(a.map[i][j] == '.'){
                a.map[i][j] == '@';
            }
        }
    }
    
*/  
    }
    

//di saat x = 1, scan (y, x+1), (y+1,x+1), (y-1,x+1)
//saat x = 2, scan
};

int main(){
    simulator Main;
    Field Map;
    scan c;

//while(!(goal == true))



    for(int i = 0; i < 12; i++){
        for(int j = 0; j < 18; j++){
            cout << Map.map[i][j] << " ";
        }  
        cout << endl;
    }

}