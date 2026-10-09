#include <iostream>
#include <functional>
#include <vector>
using namespace std;



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
        { '.', '.', '.', 'R', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '#' },
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

    /*AI assisted
    vector<function<void(int, int)>> moveCallbacks; //this is what allows the lambda to function
    */

    
    Map& A;
    int xrobot = 0;
    int yrobot = 0;

    public: 

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
            for(int j = 1; j <= i; j++){
                if(!(A.field[yrobot - j][xrobot + i] == '.')){

                } else {
                    A.field[yrobot - j][xrobot + i] = '@';
                }
                if(!(A.field[yrobot + j][xrobot + i] == '.')){
                    
                } else {
                    A.field[yrobot + j][xrobot + i] = '@';
                }

                if(!(A.field[yrobot][xrobot + i] == '.')){

                } else {
                    A.field[yrobot][xrobot + i] = '@';
                }


            }//nested for
            
        }//for

       

    }//void 

    void scanleft(){

        for(int i = 1; i <= 3; i++){
            for(int j = 1; j <= i; j++){
                if(!(A.field[yrobot - j][xrobot - i] == '.')){

                } else {
                    A.field[yrobot - j][xrobot - i] = '@';
                }
                if(!(A.field[yrobot + j][xrobot - i] == '.')){
                    
                } else {
                    A.field[yrobot + j][xrobot - i] = '@';
                }

                if(!(A.field[yrobot][xrobot - i] == '.')){

                } else {
                    A.field[yrobot][xrobot - i] = '@';
                }


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


    void rotate(){
        for(int i = 1; i <= 3; i++){
            for(int j = 1; j <= i; j++){
                
            }
        }


    }
    /*
    void rotate(){
        
        //wish I knew how to implement the mathmathical equation for this......
        
        unscan();


        //A.field[yrobot][xrobot]
        //right -> down
        if(A.field[yrobot][xrobot + 1] == '@'){

            for(int i = 1; i <= 3; i++){
                for(int j = 1; j <= i; j++ ){
                    if(!(A.field[yrobot - j][xrobot - i] == '.')){

                    } else {
                        A.field[yrobot - i][xrobot - j] = '@';
                    }
                    if(!(A.field[yrobot + i][xrobot - j] == '.')){
                    
                    } else {
                        A.field[yrobot + i][xrobot - j] = '@';
                    }

                    if(!(A.field[yrobot + i][xrobot] == '.')){

                    } else {
                        A.field[yrobot + i][xrobot] = '@';
                    }

                }
            }

        } else if(A.field[yrobot + 1][xrobot] == '@'){ //down -> left

        } else if(A.field[yrobot][xrobot - 1] == '@'){ //left -> up

        } else if(A.field[yrobot - 1][xrobot] == '@'){ // up -> right (might not need this tho)

        }

    }
   */
    /*
    void unscan(){

        for(int i = 1; i <= 3; i++){
            for(int j = 1; j <= i; j++){
                if(!(A.field[yrobot - j][xrobot + i] == '@')){

                } else {
                    A.field[yrobot - j][xrobot + i] = '.';
                }
                if(!(A.field[yrobot + j][xrobot + i] == '@')){
                    
                } else {
                    A.field[yrobot + j][xrobot + i] = '.';
                }

                if(!(A.field[yrobot][xrobot + i] == '@')){

                } else {
                    A.field[yrobot][xrobot + i] = '.';
                }


            }//nested for
            
        }//for

       

    }//void 
    */

};


int main(){
    Map mapclass;
    Robot robotclass  (mapclass);

    /*
    robotclass.registerOnMove([&mapclass](int x, int y) {
    });
    */
    
    
    robotclass.location();
    robotclass.updatelocation();
    robotclass.scanright();
    mapclass.mapcondition();

    robotclass.moveright();
    robotclass.scanright();
    mapclass.mapcondition();
   

}