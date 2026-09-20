#include <iostream>
#include <string>
#include <cstdlib>
#define RESET   "\033[0m" //warna normal terminal (khusus linux/wsl)
#define GREEN   "\033[32m" //warna hijau (khusus linux/wsl)
using namespace std;

class Robot{
public:
    int rx = 1,ry = 2;
    bool hasFlag = false;
    int step = 0;
};

string maze[11] = {
    "# # # # # # # # # # #",
    "# S . . # . . . . . #",
    "# . # . # . # # # . #",
    "# . # . . . # G # . #",
    "# . . . # . # . # . #",
    "# # # . # . . . # . #",
    "# . . . # # # . # . #",
    "# . # . . X . . # . #",
    "# . # . # # # . # F #",
    "# X . . . . X . . . #",
    "# # # # # # # # # # #"
};

class Game{
public:
    void position(Robot& R,string command, int step){
        int x = R.ry/2;
        int y = R.rx;

        cout << "\nSTEP " << step << " - MOVE " << command << " - POSITION (" << x << "," << y << ")" << endl;
    }

    void printMaze(Robot& R){
        for(int i = 0; i < 11; i++){
            for(int j = 0; j < 22; j++){
                if(i == R.rx && j == R.ry){
                    cout << 'R';
                }else{
                    cout << maze[i][j];
                }
            } cout << endl;
        }
    }

    void move(Robot& R, int dx, int dy){
    int nx = R.rx + dx;
    int ny = R.ry + dy;

    if(maze[nx][ny] == '#'){
        cout << "ROBOT MENABRAK DINDING!\n"; return; 
    } else if(maze[nx][ny] == 'X'){
        cout << "ROBOT MENGINJAK LAND MINE!\n"; return; 
    }

    R.rx = nx;
    R.ry = ny;

    if(maze[nx][ny] == 'F'){
        R.hasFlag = true;
        maze[nx][ny] = '.';
        cout << GREEN <<"[FLAG CAPTURED]" << RESET << endl;
    }
    if(maze[nx][ny] == 'G' && !R.hasFlag){
        cout << "AMBIL FLAG TERLEBIH DAHULU" << endl; return;
    } else if(maze[nx][ny] == 'G' && R.hasFlag){
        cout << "TOTAL STEP = " << R.step << endl;
        cout << GREEN << "== MISSION COMPLETE ==" << RESET << endl;
        exit(0);
    }
    }
};

int main(){
    Robot R;
    Game game;
    string command = "";

    while(true){
        game.position(R,command,R.step);
        game.printMaze(R);
        cout << "> ";
        cin >> command;
        R.step++;

        if(command == "UP") game.move(R,-1,0);
        else if(command == "DOWN") game.move(R,1,0);
        else if(command == "RIGHT") game.move(R,0,2);
        else if(command == "LEFT") game.move(R,0,-2);
        else if(command == "QUIT") break;
    }

    return 0;
}