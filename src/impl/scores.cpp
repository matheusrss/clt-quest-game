#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <cstring>

using namespace std;

const int MAX_SCORES = 1000; 

struct Score {
    char name[50];
    int level;
    double pontuation;

    Score() : level(0), pontuation(0.0) {
        name[0] = '\0';
    }

    Score(const string& n, int l, double p) : level(l), pontuation(p) {
        strncpy(name, n.c_str(), sizeof(name) - 1);
        name[sizeof(name) - 1] = '\0';
    }

    bool isHigher(const Score& other) const {
        return pontuation > other.pontuation;
    }
};

void swapScores(Score& a, Score& b) {
    Score temp = a;
    a = b;
    b = temp;
}

void sortScores(Score* scores, int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (scores[j + 1].isHigher(scores[j])) {
                swapScores(scores[j], scores[j + 1]);
            }
        }
    }
}

void addAndSortScores(const string &name, int level, double pontuation) {
    const char* filePath = "./Scores/High_scores.txt";

    Score scores[MAX_SCORES];
    int scoreCount = 0;

    ifstream inputFile(filePath);
    if (inputFile.is_open()) {
        string line;
        while (getline(inputFile, line) && scoreCount < MAX_SCORES) {
            int position;
            char playerName[50];
            int playerLevel;
            double playerScore;

            if (sscanf(line.c_str(), "%d. %49s %d %lf", &position, playerName, &playerLevel, &playerScore) == 4) {
                scores[scoreCount++] = Score(playerName, playerLevel, playerScore);
            }
        }
        inputFile.close();
    }

    if (scoreCount < MAX_SCORES) {
        scores[scoreCount++] = Score(name, level, pontuation);
    }

    sortScores(scores, scoreCount);

    ofstream outputFile(filePath);
    if (outputFile.is_open()) {
        for (int i = 0; i < scoreCount; ++i) {
            outputFile << (i + 1) << ". " << scores[i].name << " "
                       << scores[i].level << " "
                       << fixed << setprecision(2) << scores[i].pontuation << "\n";
        }
        outputFile.close();
    } else {
        cerr << "Erro ao abrir o arquivo para gravação!" << endl;
        return;
    }

    for (int i = 0; i < scoreCount; ++i) {
        if (strcmp(scores[i].name, name.c_str()) == 0 && scores[i].level == level && scores[i].pontuation == pontuation) {
            cout << "\n==============================\n";
            cout << "   Rank: #" << (i + 1) << "\n";
            cout << "   Name: " << name << "\n";
            cout << "   Level: " << level << "\n";
            cout << "   Score: " << fixed << setprecision(2) << pontuation << "\n";
            cout << "==============================\n";
            break;
        }
    }
}