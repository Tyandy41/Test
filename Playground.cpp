#include <iostream>
#include <functional>
#include <vector>
#include <utility>

using namespace std;

//this is my 2 hour b4 the deadline 

class Map{
    private:
    
    bool robotfound = false;
    
    //robot position to give to field
    int Rx = 0;
    int Ry = 0;

    public:

    //self-explanitory (update the position after moving)
    void updatelocation(int x, int y){
        Rx = x;
        Ry = y;
    }

    void mapcondition(){
        for(int i = 0; i <12; i++){
            for(int j = 0; j< 18; j++){
                cout << field[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

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
        { '.', '0', '.', 'R', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '#' },
        { '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '#' },
        { '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '#' },
        { '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.' },
        { '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.' },
        { '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.' },
        
    };

    //location finder, return "not found" if not on field
    void checklocation(){
        robotfound = false; // Reset robotfound before searching

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

    //ai assisted
   
    
    Map& A;
    int xrobot = 0;
    int yrobot = 0;
    int xscan = 0;
    int yscan = 0;

    public: 

    
    //ai assisted
    vector<pair<int, int>> scanlocation;
    
    //ai assisted
    Robot(Map& Map) : A(Map) {}
        // This is a constructor, to initialize the class with other class.
    

    
    void location(){
        A.checklocation();
    }
    /*AI assited
     void registerOnMove(function<void(int, int)> callback) {
        moveCallbacks.push_back(callback);
    } //a lambda (whatever that is) (suppose to help update the robot position on the map)
    */

    //getter function
    int getxrobot() const {
        return xrobot;
    }

    int getyrobot() const {
        return yrobot;
    }
   
    //AI assisted
    vector<pair<int, int>> getScanLocation() const {
        return scanlocation;
    }

    //getter function

    void updatelocation(){
        xrobot = A.getRx();
        yrobot = A.getRy();
    }

    void moveright(){
        updatelocation();
        unscan();
        if(A.field[yrobot][xrobot + 1] == '.'){
           
        A.field[yrobot][xrobot] = '.';
        xrobot++;
        A.field[yrobot][xrobot] = 'R';

        A.updatelocation(xrobot, yrobot); // Update the map's robot location
        
        

        //AI assisted
        /*
        for (const auto& callback : moveCallbacks) {
            callback(xrobot, yrobot);
        }
        */

        cout << "callback recieved (" << xrobot + 1 << ", " << yrobot + 1 << ")" << endl;
        }
    }

    void moveleft(){
        updatelocation();
        unscan();
        if(A.field[yrobot][xrobot - 1] == '.'){
           
        A.field[yrobot][xrobot] = '.';
        xrobot--;
        A.field[yrobot][xrobot] = 'R';

         A.updatelocation(xrobot, yrobot);
        /*
        //AI assisted
        for (const auto& callback : moveCallbacks) {
            callback(xrobot, yrobot);
        }
        */

        cout << "callback recieved (" << xrobot + 1 << ", " << yrobot + 1 << ")" << endl;
        }
    }
    
    void moveup(){
        updatelocation();
        unscan();
        if(A.field[yrobot - 1][xrobot] == '.'){
           
        A.field[yrobot][xrobot] = '.';
        yrobot--;
        A.field[yrobot][xrobot] = 'R';

         A.updatelocation(xrobot, yrobot);

        cout << "callback recieved (" << xrobot + 1 << ", " << yrobot + 1 << ")" << endl;
        }
    }

    void movedown(){
        updatelocation();
        unscan();
        if(A.field[yrobot + 1][xrobot] == '.'){
           
        A.field[yrobot][xrobot] = '.';
        yrobot++;
        A.field[yrobot][xrobot] = 'R';

         A.updatelocation(xrobot, yrobot);

        cout << "callback recieved (" << xrobot + 1 << ", " << yrobot + 1 << ")" << endl;
        }
    }

    void scanright(){

        for(int i = 1; i <= 3; i++){
            for(int j = 0; j <= i; j++){
                if(!(A.field[yrobot - j][xrobot + i] == '.')){

                } else {
                    A.field[yrobot - j][xrobot + i] = '@';
                }

                if(!(A.field[yrobot + j][xrobot + i] == '.')){
                    
                } else {
                    A.field[yrobot + j][xrobot + i] = '@';
                }
            

                /*
                if(!(A.field[yrobot][xrobot + i] == '.')){

                } else {
                    A.field[yrobot][xrobot + i] = '@';
                }
                */


            }//nested for
            
        }//for

       

    }//void 

    void scanleft(){

        for(int i = 1; i <= 3; i++){
            for(int j = 0; j <= i; j++){
                if(!(A.field[yrobot - j][xrobot - i] == '.')){

                } else {
                    A.field[yrobot - j][xrobot - i] = '@';
                }
                if(!(A.field[yrobot + j][xrobot - i] == '.')){
                    
                } else {
                    A.field[yrobot + j][xrobot - i] = '@';
                }

                /*
                if(!(A.field[yrobot][xrobot - i] == '.')){

                } else {
                    A.field[yrobot][xrobot - i] = '@';
                }
                */

            }//nested for
            
        }//for

       

    }//void 

    void unscan(){
        for(int i = 0; i < 12; i++){
            for(int j = 0; j < 18; j++){
                if(A.field[i][j] == '@'){
                    A.field[i][j] = '.';
                }
            }
        }
    }

    void surrounding(){
        scanlocation.clear(); 
        for(int i = yrobot - 3; i <= yrobot + 3; i++){
            if(i < 0 || i >= 12) {
            continue; 
            }

            for(int j = xrobot - 3; j <= xrobot + 3; j++){
                if(j < 0 || j >= 18) {
                    continue;
                }

                if(A.field[i][j] == '@' || A.field[i][j] == '0'){
                    //ai assisted
                    scanlocation.push_back({i, j});
                }
            }

        }
    }

    void rotate2(){
        surrounding();
        unscan();
        for(int i = 0; i < scanlocation.size(); i++){
            int y = scanlocation[i].first;
            int x = scanlocation[i].second;
            
            if(A.field[x - xrobot + yrobot][xrobot + yrobot - y] == '0'){

            } else {
                A.field[x - xrobot + yrobot][xrobot + yrobot - y] = '@';
            }
            

            //A.mapcondition();
        }
    }

};


int main(){
    Map mapclass;
    Robot robotclass (mapclass);

    /*
    robotclass.registerOnMove([&mapclass](int x, int y) {
    });
    */
    
    
    robotclass.location();
    robotclass.updatelocation();
    robotclass.scanright();
    mapclass.mapcondition();

    
    robotclass.rotate2();
    mapclass.mapcondition();
    robotclass.rotate2();
    mapclass.mapcondition();
    robotclass.rotate2();
    mapclass.mapcondition();
   

}