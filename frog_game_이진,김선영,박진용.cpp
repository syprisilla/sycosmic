#include <iostream>
#include <random>
#include <ctime>
#include <string>

using namespace std;

class FrogGame {
private:
    random_device rd;
    mt19937 gen;
    uniform_int_distribution<> distrib{ 0, 2 };
    const int timeLimit = 3;
    int UserNum = 0;
    int ComputerNum;
    int PlayAgain;
    bool flag_1 = false;
    string UserInput;
    string UserAnswer;
    string rockPaperScissors[3] = { "rock", "paper", "scissors" };

public:
    FrogGame() : gen(rd()), ComputerNum(distrib(gen)) {
        cout << "Frog Rock-paper-scissors game starts." << endl;
    }

    void PrintIntro() {
        cout << "Please input rock, paper, or scissors: ";
        cin >> UserInput;
    }

    void StrIntoNum() {
        if (UserInput == "rock")
            UserNum = 0;
        else if (UserInput == "paper")
            UserNum = 1;
        else if (UserInput == "scissors")
            UserNum = 2;
    }

    bool StartGame() {
        cout << "The opponent chose [" << rockPaperScissors[ComputerNum] << "] : ";
        time_t startTime = time(NULL);
        cin >> UserAnswer;
        time_t endTime = time(NULL);

        if (endTime - startTime < timeLimit) {
            flag_1 = true;
            return flag_1;
        }
        else {
            return flag_1;
        }
    }

    int CalculResult() {
        if (!flag_1) {
            cout << "You lose due to timelimit" << endl;
            return 0;
        }

        int result = -1;

        if (UserNum == ComputerNum)
            result = 2;
        else if ((UserNum == 0 && ComputerNum == 2) ||
            (UserNum == 1 && ComputerNum == 0) ||
            (UserNum == 2 && ComputerNum == 1))
            result = 0;
        else
            result = 1;

        if ((result == 0 && UserAnswer == "lose") || (result == 1 && UserAnswer == "win") || (result == 2 && UserAnswer == "tie"))
            cout << "You win" << endl;
        else
            cout << "You lose" << endl;

        return 0;
    }

    int PrintOuttro() {
        cout << "Input 1 to play again or Input 2 to quit" << endl;
        cin >> PlayAgain;
        if (PlayAgain == 1)
            return 1;
        else if (PlayAgain == 2)
            return 0;
        else {
            cout << "Invalid input. Please input 1 to play again or 2 to quit." << endl;
            return PrintOuttro();
        }
    }
};

int main() {
    int playAgain = 1;
    while (playAgain == 1) {
        FrogGame game;
        game.PrintIntro();
        game.StrIntoNum();
        bool flag = game.StartGame();
        game.CalculResult();
        playAgain = game.PrintOuttro();
    }
    return 0;
}