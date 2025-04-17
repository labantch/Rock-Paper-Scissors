#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits>
using namespace std;

enum enGameChoice
{
    Stone = 1,
    Paper,
    Scissors
};
enum enWinner
{
    Player = 1,
    Computer,
    Draw
};

struct stRoundInfo
{
    short RoundNumber = 0;
    enGameChoice PlayerChoice;
    enGameChoice ComputerChoice;
    enWinner Winner;
    string WinnerName;
};

struct StGameResults
{
    short GameRounds = 0;
    short PlayerWinTimes = 0;
    short ComputerWinTimes = 0;
    short DrawTimes = 0;
    enWinner GameWinner;
    string WinnerName = "";
};

int RandomNum(int From, int To)
{
    return rand() % (To - From + 1) + From;
}

int ReadValidNumber(string Message, int From, int To)
{
    int Number;
    while (true)
    {
        cout << Message;
        cin >> Number;

        if (cin.fail() || Number < From || Number > To)
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number between " << From << " and " << To << ".\n";
        }
        else
        {
            return Number;
        }
    }
}

enGameChoice ComputerChoice()
{
    return (enGameChoice)(RandomNum(1, 3));
}

enGameChoice PlayerChoice()
{
    int Choice = ReadValidNumber("\nYour Choice: [1]:Stone, [2]:Paper, [3]:Scissors? ", 1, 3);
    return (enGameChoice)(Choice);
}

enWinner WhoWonTheRound(stRoundInfo RoundInfo)
{
    if (RoundInfo.PlayerChoice == RoundInfo.ComputerChoice)
        return enWinner::Draw;

    switch (RoundInfo.PlayerChoice)
    {
    case enGameChoice::Stone:
        return (RoundInfo.ComputerChoice == enGameChoice::Paper) ? enWinner::Computer : enWinner::Player;
    case enGameChoice::Paper:
        return (RoundInfo.ComputerChoice == enGameChoice::Scissors) ? enWinner::Computer : enWinner::Player;
    case enGameChoice::Scissors:
        return (RoundInfo.ComputerChoice == enGameChoice::Stone) ? enWinner::Computer : enWinner::Player;
    }
    return enWinner::Draw;
}

string ChoiceName(enGameChoice Choise)
{
    string arrGameChoices[3] = {"Stone", "Paper", "Scissors"};
    return arrGameChoices[Choise - 1];
}

string WinnerName(enWinner Winner)
{
    string arrWinnerName[3] = {"Player", "Computer", "Draw"};
    return arrWinnerName[Winner - 1];
}

enWinner GameWinnerName(short PlayerWinTimes, short ComputerWinTimes)
{
    if (ComputerWinTimes > PlayerWinTimes)
        return enWinner::Computer;
    else if (PlayerWinTimes > ComputerWinTimes)
        return enWinner::Player;
    else
        return enWinner::Draw;
}

void ScreenColour(string GameWinner)
{
    if (GameWinner == "Computer")
        system("color 4F");
    else if (GameWinner == "Player")
        system("color 2F");
    else if (GameWinner == "Draw")
        system("color 6F");
}

void PrintRoundResult(stRoundInfo RoundInfo)
{
    system("cls");
    ScreenColour(RoundInfo.WinnerName);
    cout << "\n____________ Round [" << RoundInfo.RoundNumber << "] ____________\n\n";
    cout << "Player1 Choice: " << ChoiceName(RoundInfo.PlayerChoice) << endl;
    cout << "Computer Choice: " << ChoiceName(RoundInfo.ComputerChoice) << endl;
    cout << "Round Winner   : [" << RoundInfo.WinnerName << "]\n";
    cout << "_________________________________________\n"
         << endl;
}

StGameResults GamePlay()
{
    stRoundInfo RoundInfo;
    short PlayerWinsTimes = 0, ComputerWinsTimes = 0, DrawTimes = 0;

    int HowManyRounds = ReadValidNumber("How many games do you want to play? ", 1, 100);

    for (short GameRound = 1; GameRound <= HowManyRounds; GameRound++)
    {
        cout << "\nRound [" << GameRound << "] begins:\n";
        RoundInfo.RoundNumber = GameRound;
        RoundInfo.ComputerChoice = ComputerChoice();
        RoundInfo.PlayerChoice = PlayerChoice();
        RoundInfo.Winner = WhoWonTheRound(RoundInfo);
        RoundInfo.WinnerName = WinnerName(RoundInfo.Winner);

        if (RoundInfo.Winner == enWinner::Computer)
        {
            system("color 4F");
            ComputerWinsTimes += 1;
        }
        else if (RoundInfo.Winner == enWinner::Player)
        {
            system("color 2F");
            PlayerWinsTimes += 1;
        }
        else
        {
            system("color 6F");
            DrawTimes += 1;
        }

        PrintRoundResult(RoundInfo);
    }

    return {
        (short)HowManyRounds,
        PlayerWinsTimes,
        ComputerWinsTimes,
        DrawTimes,
        GameWinnerName(PlayerWinsTimes, ComputerWinsTimes),
        WinnerName(GameWinnerName(PlayerWinsTimes, ComputerWinsTimes))};
}

void DisplayFinalResults(StGameResults GameResults)
{
    system("cls");
    ScreenColour(GameResults.WinnerName);

    cout << "\t\t" << string(90, '-') << endl;
    cout << "\t\t\t\t\t\t+++ G a m e  O v e r +++" << endl;
    cout << "\t\t" << string(90, '-') << endl;
    cout << "\t\t" << string(35, '-') << "[ Game Result ]" << string(40, '-') << endl;
    cout << "\t\tGame Rounds        : " << GameResults.GameRounds << endl;
    cout << "\t\tPlayer Won Times   : " << GameResults.PlayerWinTimes << endl;
    cout << "\t\tComputer Won Times : " << GameResults.ComputerWinTimes << endl;
    cout << "\t\tDraw Times         : " << GameResults.DrawTimes << endl;
    cout << "\t\t" << string(90, '-') << endl;
    cout << "\t\tGame Winner        : " << GameResults.WinnerName << endl;
    cout << "\t\t" << string(90, '-') << endl;
}

void GameStart()
{
    string input;
    char PlayAgain = 'Y';
    do
    {
        system("cls");
        system("color 0F");
        StGameResults GameResults = GamePlay();
        DisplayFinalResults(GameResults);

        do
        {
            cout << "\nDo you want to play again? (Y/N): ";
            getline(cin >> ws, input);
            if (!input.empty())
                PlayAgain = toupper(input[0]);
            else
                PlayAgain = ' ';
        } while (PlayAgain != 'Y' && PlayAgain != 'N');

    } while (PlayAgain == 'Y');
}

int main()
{
    srand((unsigned)time(NULL));
    GameStart();
    return 0;
}
