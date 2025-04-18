Rock Paper Scissors Game
Overview
This is a console-based Rock Paper Scissors game implemented in C++. The game allows a player to compete against the computer in multiple rounds, with the option to play again after each game. The program tracks wins, losses, and draws, and displays the results with colored console output for an enhanced user experience.
Features

Interactive Gameplay: Players choose between Stone (Rock), Paper, or Scissors.
Random Computer Choices: The computer randomly selects its move.
Round-Based System: Users can specify the number of rounds to play (1–100).
Winner Determination: The game determines the winner of each round and the overall game based on standard Rock Paper Scissors rules.
Colored Output: The console changes color based on the winner (green for player, red for computer, yellow for draw).
Play Again Option: Players can choose to start a new game after the results are displayed.
Input Validation: Ensures valid user input for choices and round numbers.

Prerequisites

A C++ compiler (e.g., g++, Visual Studio, or any IDE supporting C++).
Standard C++ libraries (included in the code: iostream, cstdlib, ctime, limits).

How to Run

Compile the Code:
Save the source code in a file (e.g., rock_paper_scissors.cpp).
Compile using a C++ compiler. For example, with g++:g++ rock_paper_scissors.cpp -o rock_paper_scissors




Run the Program:
Execute the compiled program:./rock_paper_scissors




Play the Game:
Enter the number of rounds you want to play (1–100).
For each round, choose:
1 for Stone
2 for Paper
3 for Scissors


After each round, the result (player choice, computer choice, and winner) is displayed.
At the end, the final results (total rounds, wins, draws, and overall winner) are shown.
Choose Y to play again or N to exit.



Code Structure

Enums:
enGameChoice: Defines the possible choices (Stone, Paper, Scissors).
enWinner: Defines the possible round outcomes (Player, Computer, Draw).


Structs:
stRoundInfo: Stores information about each round (round number, player/computer choices, winner).
StGameResults: Stores game statistics (total rounds, wins, draws, overall winner).


Key Functions:
RandomNum: Generates a random number for the computer's choice.
ReadValidNumber: Ensures valid user input for numbers within a range.
PlayerChoice and ComputerChoice: Handle player and computer move selection.
WhoWonTheRound: Determines the winner of a round.
PrintRoundResult: Displays the result of each round.
GamePlay: Manages the game loop for the specified number of rounds.
DisplayFinalResults: Shows the final game statistics.
GameStart: Controls the overall game flow, including the play-again feature.
ScreenColour: Changes the console color based on the winner.



Example Output
How many games do you want to play? 3

Round [1] begins:
Your Choice: [1]:Stone, [2]:Paper, [3]:Scissors? 1

____________ Round [1] ____________
Player1 Choice: Stone
Computer Choice: Scissors
Round Winner   : [Player]
_________________________________________

...

+++ G a m e  O v e r +++
----------------------------------------
[ Game Result ]
----------------------------------------
Game Rounds        : 3
Player Won Times   : 2
Computer Won Times : 1
Draw Times         : 0
----------------------------------------
Game Winner        : Player
----------------------------------------

Do you want to play again? (Y/N): N

Notes

The game uses the system("color") command for colored output, which is Windows-specific. For cross-platform compatibility, you may need to modify the ScreenColour function or remove color functionality.
The random number generator is seeded with the current time to ensure different computer choices each run.
Input validation prevents crashes from invalid inputs (e.g., non-numeric input or out-of-range numbers).

License
This project is open-source and available under the MIT License.
