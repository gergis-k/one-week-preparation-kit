#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

#define fast_IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)

class TEXT {
    private:
        string text;
        stack<std::string> history;
    public:
        void append(string W)
        {
            history.push(text);
            text.append(W);
        }
        void eraseAt(int k)
        {
            history.push(text);
            text.erase(text.length() - k);
        }
        void print(int k)
        {
            cout << text[k - 1] << endl;
        }
        void undo()
        {
            text = history.top();
            history.pop();
        }
};

TEXT txt;
int ty, k;
string str;

void SOLVE()
{
    cin >> ty;
    switch (ty)
    {
        case 1:
            cin >> str;
            txt.append(str);
            break;
        case 2:
            cin >> k;
            txt.eraseAt(k);
            break;
        case 3:
            cin >> k;
            txt.print(k);
            break;
        default:
            txt.undo();
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
