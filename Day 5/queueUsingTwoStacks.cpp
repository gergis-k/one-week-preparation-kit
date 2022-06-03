#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;

#define fast_IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)

class butterfly_queue
{
    private:
        stack<int> _new, _old;
    public:
        void push_butterfly(int butterfly)
        {
            _new.push(butterfly);
        }
        void pop_butterfly()
        {
            if (_old.empty())
            {
                while (!_new.empty())
                {
                    _old.push(_new.top());
                    _new.pop();
                }
            }
            _old.pop();
        }
        int front_butterfly()
        {
            if (_old.empty())
            {
                while (!_new.empty())
                {
                    _old.push(_new.top());
                    _new.pop();
                }
            }
            return _old.top();
        }
};

butterfly_queue btr_q;
int ty, x;

void SOLVE()
{
    cin >> ty;
    switch (ty)
    {
        case 1:
            cin >> x;
            btr_q.push_butterfly(x);
            break;
        case 2:
            btr_q.pop_butterfly();
            break;
        default:
            cout << btr_q.front_butterfly() << endl;
            break;
    }
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    // Gergis Adel
    fast_IO;
    int q; cin >> q;
    while (q--) SOLVE();
    return 0;
}
