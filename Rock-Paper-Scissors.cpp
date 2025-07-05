#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits>

using namespace std;

enum enChoices
{
    Rock = 1,
    Paper = 2,
    Scissors = 3
};

struct stGame
{
    int RoundsNumber = 0;
    enChoices PlayerChoice;
    enChoices ComputerChoice;
    int PlayerWonTimes = 0;
    int ComputerWonTimes = 0;
    int DrawTimes = 0;
    string RoundWinner;
};

int RandomNumber(int From, int To)
{
    return rand() % (To - From + 1) + From;
}

int GetPositiveNumber(const string& message, int From, int To)
{
    int number;
    while (true)
    {
        cout << message << endl;
        cin >> number;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number." << endl;
            continue;
        }

        if (number < From || number > To)
        {
            cout << "Number must be between " << From << " and " << To << ". Try again." << endl;
            continue;
        }
        break;
    }
    return number;
}

void StartOfTheGame(stGame &Game)
{
    system("cls && color 0F");
    cout << "\n\t\tWelcome to Rock Paper Scissors Game\n\n";
    Game.RoundsNumber = GetPositiveNumber("How many rounds do you want to play? [1-100]", 1, 100);
}

string ChoiceConvert(enChoices Choice)
{
    switch (Choice)
    {
    case Rock: return "Rock";
    case Paper: return "Paper";
    case Scissors: return "Scissors";
    default: return "Unknown";
    }
}

enChoices ReadPlayerChoice()
{
    int choice = GetPositiveNumber("Your choice: [1]:Rock, [2]:Paper, [3]:Scissors?", 1, 3);
    return static_cast<enChoices>(choice);
}

enChoices GenerateComputerChoice()
{
    return static_cast<enChoices>(RandomNumber(1, 3));
}

bool PlayerWins(enChoices player, enChoices computer)
{
    return (player == Rock && computer == Scissors) ||
           (player == Paper && computer == Rock) ||
           (player == Scissors && computer == Paper);
}

void RoundStatus(stGame &Game)
{
    if (Game.PlayerChoice == Game.ComputerChoice)
    {
        Game.RoundWinner = "[No Winner]";
        Game.DrawTimes++;
    }
    else if (PlayerWins(Game.PlayerChoice, Game.ComputerChoice))
    {
        Game.RoundWinner = "Player";
        Game.PlayerWonTimes++;
    }
    else
    {
        Game.RoundWinner = "Computer";
        Game.ComputerWonTimes++;
    }
}

void ColorDisplay(const string& Winner)
{
    if (Winner == "Player") system("color 2F");
    else if (Winner == "Computer") system("color 4F");
    else system("color 6F");
}

void DisplayRoundStatus(const stGame &Game, int Round)
{
    system("cls && color 0F");
    ColorDisplay(Game.RoundWinner);
    cout << string(19, '_') << " Round [ " << Round << " ] " << string(18, '_') << endl;
    cout << "Player choice   : " << ChoiceConvert(Game.PlayerChoice) << endl;
    cout << "Computer choice : " << ChoiceConvert(Game.ComputerChoice) << endl;
    cout << "Round winner    : " << Game.RoundWinner << endl;
    cout << string(50, '_') << endl;
}

void DisplayGameStatus(const stGame &Game)
{
    system("cls && color 0F");

    string FinalWinner;
    if (Game.PlayerWonTimes > Game.ComputerWonTimes) FinalWinner = "Player";
    else if (Game.ComputerWonTimes > Game.PlayerWonTimes) FinalWinner = "Computer";
    else FinalWinner = "Draw";

    ColorDisplay(FinalWinner);
    cout << string(4, '\t') << string(80, '_') << "\n\n";
    cout << string(7, '\t') << "+ + G a m e  O v e r + +" << endl;
    cout << string(4, '\t') << string(28, '_') << " [ Game results ] " << string(34, '_') << "\n\n\n";
    cout << string(4, '\t') << "Player won times   : " << Game.PlayerWonTimes << endl;
    cout << string(4, '\t') << "Computer won times : " << Game.ComputerWonTimes << endl;
    cout << string(4, '\t') << "Draw times         : " << Game.DrawTimes << endl;
    cout << string(4, '\t') << "Final winner       : " << FinalWinner << endl;
    cout << string(4, '\t') << string(80, '_') << "\n\n";
}

void Game()
{
    char PlayAgain;
    do
    {
        stGame Game;
        StartOfTheGame(Game);
        for (int Round = 1; Round <= Game.RoundsNumber; ++Round)
        {
            Game.PlayerChoice = ReadPlayerChoice();
            Game.ComputerChoice = GenerateComputerChoice();
            RoundStatus(Game);
            DisplayRoundStatus(Game, Round);
        }
        DisplayGameStatus(Game);

        cout << "Do you want to play again? [Y/N]: ";
        cin >> PlayAgain;
        PlayAgain = toupper(PlayAgain);
        while (cin.fail() || (PlayAgain != 'Y' && PlayAgain != 'N'))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Please enter Y or N: ";
            cin >> PlayAgain;
            PlayAgain = toupper(PlayAgain);
        }
    } while (PlayAgain == 'Y');

    cout << "\nThanks for playing!\n";
}

int main()
{
    srand(static_cast<unsigned>(time(NULL)));
    Game();
    
}
