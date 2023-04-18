#include <iostream>

#include <string>
#include <vector>

using namespace std;

struct User
{
    int id;
    int discountRateToBuy;
    int costToPlus;
};
struct Emoji
{
    int id;
    int price;
};

int discountRate[4] = {10, 20, 30, 40};

vector<int> backTracking(vector<User> &user, vector<Emoji> &emojis, int level, vector<pair<Emoji, int>> &selected)
{
    vector<int> res = {-1, -1};
    if (level == emojis.size())
    {
        // 가입자, 판매액 로직 작성
        int plusUser = 0;
        int totalPurchasedFee = 0;
        for (User curUser : user)
        {
            int purchasedValue = 0;
            for (pair<Emoji, int> finalEmoji : selected)
            {
                Emoji selectedEmoji = finalEmoji.first;
                int discountRate = finalEmoji.second;
                if (discountRate >= curUser.discountRateToBuy)
                {
                    purchasedValue += selectedEmoji.price * (1 - discountRate * 0.01);
                }
            }
            totalPurchasedFee += purchasedValue;
            if (purchasedValue >= curUser.costToPlus)
            {
                plusUser++;
                totalPurchasedFee -= purchasedValue;
            }
        }
        return vector<int>({plusUser, totalPurchasedFee});
    }
    else
    {
        for (int i = 0; i < 4; ++i)
        {
            selected.push_back({emojis[level], discountRate[i]});
            vector<int> candidate = backTracking(user, emojis, level + 1, selected);
            if (res[0] < candidate[0])
            {
                res = candidate;
            }
            else if (res[0] == candidate[0])
            {
                if (res[1] < candidate[1])
                {
                    res = candidate;
                }
            }
            selected.pop_back();
        }
        return res;
    }
}

vector<int> solution(vector<vector<int>> users, vector<int> emoticons)
{
    vector<int> answer;
    vector<User> user;
    for (int i = 0; i < users.size(); ++i)
    {
        user.push_back({i, users[i][0], users[i][1]});
    }
    vector<Emoji> emojis;
    for (int i = 0; i < emoticons.size(); ++i)
    {
        emojis.push_back({i, emoticons[i]});
    }
    vector<pair<Emoji, int>> selected;
    answer = backTracking(user, emojis, 0, selected);

    return answer;
}

int main()
{
    vector<vector<int>> user({{40, 10000}, {25, 10000}});
    vector<int> emoji({7000, 9000});

    auto res = solution(user, emoji);
    cout << res[0] << res[1];
}