#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

int initFreq(int freq[], int p1, int p2, int p3, int miss) {
    int random = rand() % (p1 + p2 + p3 + miss);
    if (random <= miss)
        freq[0]++;
    else if (random <= p1 + miss)
        freq[1]++;
    else if (random <= p1 + p2 + miss)
        freq[2]++;
    else
        freq[3]++;
}

int getScore(int p1, int p2, int p3, int miss) {
    int freq[4] = {0};
    initFreq(freq, p1, p2, p3, miss);
    for (int i = 0; i < 4; i++)
        if (freq[i]) return i;
    return -1;
}

int playGame() {
    int p1 = 20, p2 = 30, p3 = 10, miss = 40, sum = 0;
    int score = getScore(p1, p2, p3, miss);

    cout << "Score is " << score << " ";
    // sum less than 5 for testing visuals that conditon isnt needed
    while (score != 0) {
        sum += score;
        score = getScore(p1, p2, p3, miss);
        cout << score << " ";
    }
    cout << endl;

    return sum;
}

int main() {
    srand((unsigned int)time(nullptr));
    int sum = playGame();
    cout << "Sum is " << sum << endl;

    return 0;
}

// legacy getScore new version more readable
// int getScore(int p1, int p2, int p3, int miss) {
//     int random = rand() % (p1 + p2 + p3 + miss);
//     int freq[4] = {0};
//     freq[random <= miss ? 0 : random <= p1 + miss ? 1 : random <= p1 + p2 +
//     miss ? 2 : 3]++; for (int i = 0; i < 4; i++)
//         if (freq[i]) return i;
//     return -1;
// }