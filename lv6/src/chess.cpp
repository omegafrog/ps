#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int king, queen, bishop, look, pon, knight;
    cin >> king >> queen >> look >> bishop >> knight >> pon;
    cout << 1 - king << " " << 1 - queen << " " << 2 - look << " " << 2 - bishop << " " << 2 - knight << " " << 8 - pon;
    return 0;
}
