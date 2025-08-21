#include <bits/stdc++.h>
using namespace std;

deque<int> dq;
int ans;

void left()
{
    dq.push_front(dq.back());
    dq.pop_back();
}

void right()
{
    dq.push_back(dq.front());
    dq.pop_front();
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        dq.push_back(i + 1);
    }

    int m;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int tg;
        cin >> tg;

        if (dq.front() == tg)
        {
            dq.pop_front();
        }
        else
        {
            int tgci;
            for (int j = 0; j < dq.size(); j++)
            {
                if (tg == dq[j])
                {
                    tgci = j;
                    break;
                }
            }

            if (dq.size() / 2 >= tgci)
            {
                while (tgci--)
                {
                    right();
                    ans++;
                }
            }
            else
            {

                tgci = dq.size() - tgci;
                while (tgci--)
                {
                    left();
                    ans++;
                }
            }
            dq.pop_front();
        }
    }

    cout << ans;

    return 0;
}
