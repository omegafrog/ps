#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

int main()
{
    vector<int> a = {0, 1, 2, 3, 4, 5, 6, 7};
    ofstream myfile("out.txt");

    do
    {
        for (auto it : a)
        {
            myfile << it;
        }
        myfile << "\n";
    } while (next_permutation(a.begin(), a.end()));
}