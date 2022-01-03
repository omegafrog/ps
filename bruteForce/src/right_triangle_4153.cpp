#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    long long len[3];
    while (1)
    {
        cin >> len[0] >> len[1] >> len[2];
        if(len[0]==0 && len[1] == 0 && len[2] == 0) break;

        long long biggest = max(len[0],len[1]);
        long long c;
        long long aPb=0;
        biggest = max(biggest, len[2]);
        for(int i =0; i < 3; ++i){
            if(biggest == len[i]){
                c = biggest*biggest;
            }
            else
                aPb+=len[i]*len[i];
        }
        if(c==aPb) cout << "right" << "\n";
        else cout << "wrong" << "\n";
    }
    
    return 0;
}
