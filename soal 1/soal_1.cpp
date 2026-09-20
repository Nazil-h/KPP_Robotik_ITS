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

string maze[7] = {
    "# # # # # # #",
    "# S # . . . #",
    "# . # . # G #",
    "# . . . # . #",
    "# # # . . . #",
    "# X . . F . #",
    "# # # # # # #"
};

class Game{
public:
    void position(Robot& R, string move, int step){
        int x = R.ry/2;
        int y = R.rx;

        cout << "\nSTEP " << step << " - MOVE " << move << " - POSITION (" << x << "," << y << ")" << endl;
    }

    void printMaze(Robot& R){
    for(int i = 0; i < 7; i++){
        for(int j = 0; j < 14; j++){
            if(i == R.rx && j == R.ry){
                cout << "R";
            }
            else {
                cout << maze[i][j];
            }
        } cout << "\n";
    }
};

    void robotMove(Robot& R, int dx,int dy){
    int nx = R.rx + dx;
    int ny = R.ry + dy;

    if(maze[nx][ny] == '#'){
        cout << "ROBOT MENABRAK DINDING!\n"; return;
    }

    if(maze[nx][ny] == 'X'){
        cout << "ROBOT MENGINJAK LAND MINE!\n"; return;
    }

    R.rx = nx;
    R.ry = ny;

    if(maze[nx][ny] == 'F'){
        cout << GREEN << "[FLAG CAPTURED]" << RESET << endl;
        R.hasFlag = true;
        maze[nx][ny] = '.';
    }
    if(maze[nx][ny] == 'G' && R.hasFlag){
        cout << "\nTOTAL STEP = " << R.step << endl;
        cout << GREEN << "== MISSION COMPLETE ==" << RESET << endl;
        exit(0);
    } else if(maze[nx][ny] == 'G' && !R.hasFlag){
        cout << "AMBIL FLAG TERLEBIH DAHULU!\n";
    }
};
};

int main(){
    Game game;
    Robot R;
    string command;

    while(true){
        game.position(R,command,R.step);
        game.printMaze(R);
        cout << "> ";
        cin >> command;
        R.step++;
        
        if(command == "UP") game.robotMove(R, -1, 0);
        else if(command == "DOWN") game.robotMove(R, 1, 0);
        else if(command == "RIGHT") game.robotMove(R, 0, 2);
        else if(command == "LEFT") game.robotMove(R, 0, -2);
        else if(command == "QUIT") break;
    }
    

    return 0;
}