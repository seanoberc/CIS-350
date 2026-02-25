#include <iostream>
#include "Scores.h"  // Assuming this is the header file name

using namespace std;
void insertionSort(vector<GameEntry>& entries, bool ascending);
int main() {
    GameEntry mike("Mike", 1105);
    GameEntry rob("Rob", 750);
    GameEntry paul("Paul", 720);
    GameEntry anna("Anna", 660);
    GameEntry rose("Rose", 590);
    GameEntry jack("Jack", 510);
    GameEntry jill("Jill", 740);

    // 1. create and populate BAM:
    cout << "--- Populating scores ---" << endl;
    Scores BAM;
    BAM.add(mike);
    BAM.add(rob);
    BAM.add(paul);
    BAM.add(anna);
    BAM.add(rose);
    BAM.add(jack);
    BAM.add(jill);

    // cout << "Num of Entries: " << BAM.numEnt() << endl;
    cout << "Initial list of scores:" << endl;
    BAM.printScores();

    // test populated lists
    cout << "\n--- 1. Testing on a populated list ---" << endl;
    cout << "Searching for Rob's score..." << endl;
    int robScore = BAM.searchScore("Rob");
    if (robScore != -1) cout << "Rob's score is: " << robScore << endl;
    else cout << "Rob not found." << endl;

    cout << "Searching for Zelda's score..." << endl;
    int zeldaScore = BAM.searchScore("Zelda");
    if (zeldaScore != -1) cout << "Zelda's score is: " << zeldaScore << endl;
    else cout << "Zelda not found." << endl;

    // calculate average scores:
    cout << "Calculating the average score..." << endl;
    // Expected output shows "725" not "725.0"
    cout << "Average score: " << static_cast<int>(BAM.averageMaxScores()) << endl;

    cout << "Finding minimum and maximum scores..." << endl;
    pair<int, int> minScore1 = BAM.findMinMaxScores();
    cout << "Minimum score: " << minScore1.first << endl;
    cout << "Maximum score: " << minScore1.second << endl;

    // run test on empty list:
    cout << "\n--- 2. Testing on an empty list ---" << endl;
    Scores emptyScores;

    cout << "Searching for player in empty list..." << endl;
    int marioScore = emptyScores.searchScore("Mario");
    if (marioScore != -1) cout << "Mario's score is: " << marioScore << endl;
    else cout << "Mario not found." << endl;

    cout << "Average of empty list: " << static_cast<int>(emptyScores.averageMaxScores()) << endl;

    pair<int, int> minScore2 = emptyScores.findMinMaxScores();
    cout << "Min score in empty list: " << minScore2.first << endl;
    cout << "Max score in empty list: " << minScore2.second << endl;

   //  // Testing removal of an entry
   //  BAM.remove(3);  // Remove the entry at index 3 (Anna)
   //  cout << "After removing entry at index 3:" << endl;
   //  BAM.printScores();
   //
   //  // Explicitly calling insertionSort using getGameEntries()
   // // BAM.insertionSort1(true);
   //  vector<GameEntry> entries = BAM.getGameEntries();
   //  insertionSort(entries, true);
   //  cout << "Sorted Entries in Ascending Order:" << endl;
   //
   //  for (const auto& entry : entries) {
   //      if(!entry.getName().empty())
   //          cout << entry.getName() << " : " << entry.getScore() << endl;
   //  }
   //BAM.printScores();

    return 0;
}

void insertionSort(vector<GameEntry>& entries, bool ascending = true) {
    int numEntries = entries.size();
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
