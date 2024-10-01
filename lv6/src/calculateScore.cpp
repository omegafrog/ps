#include <iostream>
#include <map>
using namespace std;

map<string, double> score({{"A+", 4.5}, {"A0", 4.0}, {"B+", 3.5}, {"B0", 3.0}, {"C+", 2.5}, {"C0", 2.0}, {"D+", 1.5}, {"D0", 1.0}, {"F", 0.0}});

int main(int argc, char const *argv[])
{
    double result = 0;
    int sum = 0;
    for (int i = 0; i < 20; i++)
    {
        string tmp;
        double gradeScore;
        string getScore;
        cin >> tmp >> gradeScore >> getScore;
        if (getScore.compare("P") == 0)
        {
            continue;
        }
        result += gradeScore * score[getScore];
        sum += gradeScore;
    }
    printf("%.6f", result / sum);

    return 0;
}
