#include <iostream>
#include <list>
using namespace std;

#define MAX_CLIENT_NUM 200
// client number
int N;
// array of client lists
list<string> clientHash[MAX_CLIENT_NUM+1];

int main(int argc, char const *argv[])
{
    // get N
    cin >> N;
    // var for save input value
    int clientAge;
    string clientName;
    // get input
    for (int i = 0; i < N; i++)
    {
        cin >> clientAge >> clientName;
        clientHash[clientAge].push_back(clientName);
    }

    for (int i = 1; i < MAX_CLIENT_NUM+1; i++)
    {
        while (!clientHash[i].empty())
        {
            cout << i << " " << clientHash[i].front() << "\n";
            clientHash[i].pop_front();
        }
    }
    
    
    return 0;
}


