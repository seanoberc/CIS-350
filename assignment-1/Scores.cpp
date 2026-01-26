// Implementation of Scores class
#include "Scores.h"

Scores::Scores(int maxEnt) : maxEntries(maxEnt), numEntries(0), entries(vector<GameEntry>(maxEnt)) {}

Scores::~Scores() {
    // No need for manual memory management since we use std::vector
}

void Scores::add(const GameEntry& e) {
    if (numEntries < maxEntries) {
        entries[numEntries] = e;
        numEntries++;
       // insertionSort1();
    } else if (e.getScore() > entries[maxEntries - 1].getScore()) {
        entries[maxEntries - 1] = e;
        //insertionSort1();
    }
}

GameEntry Scores::remove(int i) {
    if (i < 0 || i >= numEntries) {
        throw out_of_range("Invalid index");
    }
    GameEntry removed = entries[i];
    for (int j = i; j < numEntries - 1; j++) {
        entries[j] = entries[j + 1];
    }
    numEntries--;
    return removed;
}

const vector<GameEntry>& Scores::getGameEntries() const {
    return entries;
}

void Scores::printScores() const {
    for (int i = 0; i < numEntries; i++) {
        cout << entries[i].getName() << " : " << entries[i].getScore() << endl;
    }
}

int Scores::numEnt() const {
    return numEntries;
}

void Scores::insertionSort1(bool ascending = true) {
    for (int i = 1; i < numEntries; i++) {
        GameEntry key = entries[i];
        int j = i - 1;
        if (ascending) {
            // Sort in ascending order
            while (j >= 0 && entries[j].getScore() > key.getScore()) {
                entries[j + 1] = entries[j];
                j--;
            }
        } else {
            // Sort in descending order
            while (j >= 0 && entries[j].getScore() < key.getScore()) {
                entries[j + 1] = entries[j];
                j--;
            }
        }
        entries[j + 1] = key;
    }
}

/*
* Search the score of a player by name. Return the score if found else return -1.
 */
int Scores::searchScore(const string &playerName) const {
    for (int i = 0; i < numEntries; i++) {
        if (entries[i].getName() == playerName) {
            return entries[i].getScore();
        }
    }

    return -1;
}

/*
 * Calculate and return the average of all scores stored in the Scores list.
 */
double Scores::averageMaxScores() const {
    double result = 0.0;

    if (numEntries == 0) {
        return 0.0;
    }

    long long sum = 0;
    for (int i = 0; i < numEntries; i++) {
        sum += entries[i].getScore();
    }

    result = static_cast<double>(sum) / numEntries;
    return result;
}

/*
* Find and return the minimum and maximum scores as a pair of integers.
 */
pair<int, int> Scores::findMinMaxScores() const {
    if (numEntries == 0) {
        return {0, 0};
    }

    int minScore = entries[0].getScore();
    int maxScore = entries[0].getScore();

    for (int i = 1; i < numEntries; i++) {
        int score = entries[i].getScore();
        if (score < minScore) {
            minScore = score;
        } else if (score > maxScore) {
            maxScore = score;
        }
    }
    return {minScore, maxScore};
}
