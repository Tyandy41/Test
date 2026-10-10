#include <iostream>
#include <functional>
#include <vector>
#include <utility>

using namespace std;

/*this is the last update within the given deadline
i am still going to work on it even after the deadline ends because i am not at all happy
with how it turned out to be. despite me not being able to finish it on the give deadline,
I still wish to Finsih it. if nothing else, for my sake.
*/
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
        { '.', '.', '.', '0', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '#' },
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
    
    Map& A;
    int xrobot = 0;
    int yrobot = 0;
    int xball = 0;
    int yball = 0;

    //point of interest
    int xpoi = 3;
    int ypoi = 3;

    

    //ball condition
    bool ballfound = false;
    bool ballmoving = false;

    //robot condition
    bool robotonpoi = false;
    public: 


    
    //ai assisted
    vector<pair<int, int>> scanlocation;
    
    //ai assisted
    Robot(Map& Map) : A(Map) {}
        // This is a constructor, to initialize the class with other class.
    

    
    void location(){
        A.checklocation();
    }
    

    //getter function
    int getxrobot() const {
        return xrobot;
    }

    int getyrobot() const {
        return yrobot;
    }
   
    int getxball() const {
        return xball;
    }

    int getyball() const {
        return yball;
    }

    bool getballfound() const {
        return ballfound;
    }

    bool getrobotonpoi() const {
        return robotonpoi;
    }
    int getxpoi() const {
        return xpoi;
    }

    int getypoi() const {
        return ypoi;
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


    //movement
    void moveright(){
        updatelocation();
        unscan();
        if(A.field[yrobot][xrobot + 1] == '.'){
           
        A.field[yrobot][xrobot] = '.';
        xrobot++;
        A.field[yrobot][xrobot] = 'R';

        A.updatelocation(xrobot, yrobot); // Update the map's robot location
        
        

        cout << "callback recieved (" << xrobot + 1 << ", " << yrobot + 1 << ")" << endl;
        } else if(A.field[yrobot][xrobot + 1] == '0'){
            xball = xrobot + 1;
            yball = yrobot;
            ballfound = true;
            updatePoi();
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
      

        cout << "callback recieved (" << xrobot + 1 << ", " << yrobot + 1 << ")" << endl;
        } else if(A.field[yrobot][xrobot - 1] == '0'){
            xball = xrobot - 1;
            yball = yrobot;
            ballfound = true;
            updatePoi();
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
        }else if(A.field[yrobot - 1][xrobot] == '0'){
            xball = xrobot;
            yball = yrobot - 1;
            ballfound = true;
            updatePoi();
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
        } else if(A.field[yrobot + 1][xrobot] == '0'){
            xball = xrobot;
            yball = yrobot + 1;
            ballfound = true;
            updatePoi();
        }
    }
    //movement


    //scan
    void scanright(){

        for(int i = 1; i <= 3; i++){
            for(int j = 0; j <= i; j++){
                if((A.field[yrobot - j][xrobot + i] == '0')){
                    xball = xrobot + i;
                    yball = yrobot - j;
                    ballfound = true;
                } else {
                    A.field[yrobot - j][xrobot + i] = '@';
                }

                if((A.field[yrobot + j][xrobot + i] == '0')){
                    xball = xrobot + i;
                    yball = yrobot + j;
                    ballfound = true;
                } else {
                    A.field[yrobot + j][xrobot + i] = '@';
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

                if(A.field[i][j] == '@'){
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
                xball = xrobot + yrobot - y;
                yball = x - xrobot + yrobot;
                ballfound = true;
            } else {
                A.field[x - xrobot + yrobot][xrobot + yrobot - y] = '@';
            }
            

            //A.mapcondition();
        }
    }
    //scan


    //poi
    void updatePoi(){
        if(ballfound){
            xpoi = xball - 1; 
            ypoi = yball;
        } else {
            xpoi = 3;
            ypoi = 3;
        }
    }

    void movetopoi(){
        
    if(A.field[yrobot][xrobot] == A.field[ypoi][xpoi]){
        robotonpoi = (xrobot == xpoi && yrobot == ypoi); //AI assisted
        return;

    }
    
    if(xrobot < xpoi){
            moveright();

        } else if(xrobot > xpoi){
            if(!(A.field[yrobot][xrobot - 1] == '.')){
                moveup();
            } else {
            moveleft();
            }
        } else if(yrobot < ypoi){
            movedown();

        } else if(yrobot > ypoi){
            if(!(A.field[yrobot][xrobot - 1] == '.')){
                moveleft();
            } else {
            moveup();
            }
        }
}
    //poi
};

class stricker : public Robot{

};

int main(){
    Map mapclass;
    Robot robotclass (mapclass);

    /*
    robotclass.registerOnMove([&mapclass](int x, int y) {
    });
    */
    
    cout << robotclass.getxpoi() << " " << robotclass.getypoi() << endl;
        cout << robotclass.getxball() << " " << robotclass.getyball() << endl;
    
    robotclass.location();
    robotclass.updatelocation();
    robotclass.scanright();
    mapclass.mapcondition();

    cout << robotclass.getxpoi() << " " << robotclass.getypoi() << endl;
    cout << robotclass.getxball() << " " << robotclass.getyball() << endl;

    //get robot to POI
    int rotatecounter = 1;
    while(!(robotclass.getrobotonpoi())){
        robotclass.updatePoi();
        robotclass.movetopoi();
        mapclass.mapcondition();

        cout << robotclass.getxpoi() << " " << robotclass.getypoi() << endl;
        cout << robotclass.getxball() << " " << robotclass.getyball() << endl;
    }
   
    

    
   

}