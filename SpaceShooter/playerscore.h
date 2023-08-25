#include <iostream>
#include <fstream>
#include <string>


struct PlayerScore {
    std::string name;
    int score;

    // Constructor
    PlayerScore() : name(""), score(0) {}
    PlayerScore(const std::string& playerName, int playerScore)
        : name(playerName), score(playerScore) {}
};

// Function to read player scores from a file
int readScoresFromFile(PlayerScore playerScores[])
{
    std::ifstream file("highscores.txt");
    if (!file.is_open()) {
        return 0;
    }

    int numPlayers = 0;
    std::string playerName;
    int score;

    // Read player scores from the file
    while (file >> playerName >> score) {
        playerScores[numPlayers++] = PlayerScore(playerName, score);
    }

    file.close();

    return numPlayers;
}

// Function to write player scores to a file
void writeScoresToFile(const PlayerScore playerScores[], int numPlayers)
{
    std::ofstream file("highscores.txt");
    if (!file.is_open()) {
        std::cout << "Failed to open the file." << std::endl;
        return;
    }

    // Write player scores to the file
    for (int i = 0; i < numPlayers; ++i) {
        file << playerScores[i].name << " " << playerScores[i].score << std::endl;
    }

    file.close();
}

// Function to sort player scores using Bubble Sort
void bubbleSort(PlayerScore playerScores[], int numPlayers)
{
    for (int i = 0; i < numPlayers - 1; ++i) {
        for (int j = 0; j < numPlayers - i - 1; ++j) {
            if (playerScores[j].score < playerScores[j + 1].score) {
                // Swap players if the current score is less than the next score
                PlayerScore temp = playerScores[j];
                playerScores[j] = playerScores[j + 1];
                playerScores[j + 1] = temp;
            }
        }
    }
}
