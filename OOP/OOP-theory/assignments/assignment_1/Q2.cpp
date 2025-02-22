/*

? |Football Game Simulation
Your task is to create a football game simulation where two teams, each with a robot player,
attempt to move a ball towards a predefined goal. The game determines the winner based on
which team reaches the goal in the fewest number of hits.

- The Robot class represents a robot and should have two key attributes: 
    - name, which holds the name of the robot as a string, and 
    - hits, which keeps track of the number of hits made by the robot. 
- The class must include 
    - a method hitBall(int &ballX, int &ballY, const string &direction).
        - This method will update the ball's position based on the direction given by the robot (either up, down, left, or right), 
        - and it will also increment the robot's hit count each time the ball is hit.

- For ball position on the field specify by x and y, representing the ball's current position on the field. 
- The class should provide methods such as getX() and getY() to return the current x and y coordinates of the ball, respectively.
- Additionally, the method move(int dx, int dy) will update the ball's position based on the movement made by the robot, 
- and the method getPosition() will return the ball's position as a tuple (x, y) formate..

Goal's position on the field designed by x and y, which define the coordinates of the goal (set to
(3, 3) for this assignment. isGoalReached(int ballX, int ballY), which will check whether the
ball's position matches the goal's coordinates.
The Team class represents a football team, which consists of robot player. The team has a
teamName attribute to store the name of the team and a robot attribute that holds a pointer to a
Robot object, which represents the player.
The Game class manages the entire game flow. It holds two Team objects (teamOne and
teamTwo), a Ball object, and a Goal object. The class includes the method startGame(), which
starts the game, letting each team play its turn. The play(Team *team) method simulates the
game for a given team, moving the ball towards the goal and counting the number of hits made
by the robot. After both teams have played, the declareWinner() method compares the number of
hits made by each robot and declares the team with the fewer hits as the winner.
you are required to design and implement a C++ program that simulates a simple football game.
The program should follow Object-Oriented Programming (OOP) principles, particularly
focusing on "Has-A" relationship

* Name:         Rafay Siddiqui
* roll number:  24k-0009
* section:      BAI-2A


*/

#include <iostream>

using namespace std;

class Robot
{
public:
    string name;
    int hits;
    

    void hitBall(int &ballX, int &ballY, const string &direction){
        if (direction == "up")
        {
            ballY++;
        }
        else if (direction == "down")
        {
            ballY--;
        }
        else if (direction == "left")
        {
            ballX--;
        }
        else if (direction == "right")
        {
            ballX++;
        }
        this->hits++;
    }

    Robot(){
        this->name = "NA";
        this->hits = 0;
    }

};


class ball
{

    int x,y;
public:
    int getX(){
        return x;
    }
    int getY(){
        return y;
    }
    void move(int dx, int dy){
        this->x += dx;
        this->y += dy;
    }
    /* ball(){
        this->x = 0;
        this->y = 0;
    } */
    ball(int x=0, int y=0){
        this->x = x;
        this->y = y;
    }
};

class goal
{
public:
    int x,y;
    bool isGoalReached(int &ballX, int &ballY){
       if (ballX == this->x && ballY == this->y)
       {
           return true;
       }
       return false;
    }
    goal(int x = 3, int y = 3){
        this->x = x;
        this->y = y;
    }

};

class Team
{

public:
    string teamName;
    Robot *robot;

    Team(string teamName="NA", Robot *robot = new Robot()){
        this->teamName = teamName;
        this->robot = robot;
    }

    ~Team(){
        cout << "Team object destroyed." << endl;
        delete robot;
    }

};

class game
{

public:
    Team teamOne, teamTwo;
    ball Ball;
    goal Goal;

    void play(Team *team){
        int ballX = Ball.getX();
        int ballY = Ball.getY();
        string direction;
        
        cout<< "ball position: " << Ball.getX()<<", "<< Ball.getY() << endl;
        cout<< "enter direction for " << team->teamName << " robot: ";
        cin >> direction;
        cout<< "enter x direction for " << team->teamName << " robot: ";
        cin >> ballX;
        cout<< "enter y direction for " << team->teamName << " robot: ";
        cin >> ballY;
        // TODO: hit ball / move ball conflict, which one should move the ball?, 
        team->robot->hitBall(ballX, ballY, direction);
        Ball.move(ballX, ballY);
    }
    void declareWinner(){
        if (teamOne.robot->hits < teamTwo.robot->hits)
        {
            cout << "Team One Wins!" << endl;
        }
        else if (teamOne.robot->hits > teamTwo.robot->hits)
        {
            cout << "Team Two Wins!" << endl;
        }
        else
        {
            cout << "It's a draw!" << endl;
        }
    }
    

    void startGame(){
        int ballX = Ball.getX();
        int ballY = Ball.getY();
        cout << "Game Started!" << endl;
        cout << "Team One: " << teamOne.teamName << endl;
        cout << "Team Two: " << teamTwo.teamName << endl;
        cout << "goal position: " << Goal.x<<", "<< Goal.y<< endl;
        while (!Goal.isGoalReached(ballX, ballY))
        {
            play(&teamOne);
            play(&teamTwo);
        }
        declareWinner();
    }
    game(){
        teamOne;
        teamTwo;
        Ball = ball(0, 0);
        Goal = goal();
    }

};




int main(){

    // all members are public
    game game1;

    game1.teamOne.teamName = "Team One";
    game1.teamTwo.teamName = "Team Two";

    game1.teamOne.robot->name = "Robot One";
    game1.teamTwo.robot->name = "Robot Two";
    


    game1.startGame();


    return 0;
}