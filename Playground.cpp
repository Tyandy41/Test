#include <iostream>
#include <functional>
#include <vector>
using namespace std;

//this what ive been doing fyi

class Map{
    private:
    bool robotfound = false;
    
    //robot position to give to field
    int Rx = 0;
    int Ry = 0;

    public:

    int getRx() const {
        return Rx;
    }
    int getRy() const {
        return Ry;
    }

    char field[12][18] = {
        { '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.' },
        { '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.' },
        { '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.' },
        { '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '#' },
        { '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '#' },
        { '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '#' },
        { '.', '.', '.', '.', '.', '.', 'R', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '#' },
        { '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '#' },
        { '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '#' },
        { '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.' },
        { '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.' },
        { '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.' },
        
    };

    //location finder, return "not found" if not on field
    void checklocation(){
        for(int i = 0; i < 12; i++){
            if(robotfound == true){
                break;
            }
            for(int j = 0; j < 18; j++){
                
                if(field[i][j] == 'R'){  
                    Rx = j;
                    Ry = i;
                    robotfound = true;
                    cout << "robot Found at (" << Rx + 1 << ", " << Ry + 1 << ")" << endl;
                    
                    
                }

            }
        }

        if(robotfound == false){
            cout << "robot not found" << endl;
        }
    }



};

class Robot{
    private:
    //robot location

    //AI assisted
    vector<function<void(int, int)>> moveCallbacks; //this is what allows the lambda to function

    Map A;
    int xrobot = 0;
    int yrobot = 0;

    public: 

    //ai assisted
    Robot(Map& map) : A(map){}


    void mapcondition(){
        for(int i = 0; i <12; i++){
            for(int j = 0; j< 18; j++){
                cout << A.field[i][j] << " ";
            }
            cout << endl;
        }
    }
    void location(){
        A.checklocation();
    }
    //AI assited
     void registerOnMove(function<void(int, int)> callback) {
        moveCallbacks.push_back(callback);
    } //a lambda (whatever that is) (suppose to help update the robot position on the map)

    //getter function
    int getxrobot() const {
        return xrobot;
    }
    int getyrobot() const {
        return yrobot;
    }

    void updatelocation(){
        xrobot = A.getRx();
        yrobot = A.getRy();
    }

    void moveright(){
        updatelocation();
        if(A.field[yrobot][xrobot + 1] == '.'){
           
        A.field[yrobot][xrobot] = '.';
        xrobot++;
        A.field[yrobot][xrobot] = 'R';
        //AI assisted
        for (const auto& callback : moveCallbacks) {
            callback(xrobot, yrobot);
        }

        cout << "callback recieved (" << xrobot + 1 << ", " << yrobot + 1 << ")" << endl;
        }
    }

    void moveleft(){
        updatelocation();
        if(A.field[yrobot][xrobot - 1] == '.'){
           
        A.field[yrobot][xrobot] = '.';
        xrobot--;
        A.field[yrobot][xrobot] = 'R';
        //AI assisted
        for (const auto& callback : moveCallbacks) {
            callback(xrobot, yrobot);
        }

        cout << "callback recieved (" << xrobot + 1 << ", " << yrobot + 1 << ")" << endl;
        }
    }
    
};

int main(){
    Map mapclass;
    Robot robotclass  (mapclass);

    robotclass.registerOnMove([&mapclass](int x, int y) {
    });

    

    robotclass.location();
    robotclass.mapcondition();
    robotclass.moveleft();
    robotclass.mapcondition();
}