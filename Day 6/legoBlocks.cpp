#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'legoBlocks' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. INTEGER m
 *
 * Gergis Adel
 */
 
// =========================================================================
// =========================================================================
typedef long long ll;
#define N 1000
#define mod 1000000007
ll wall[N + 2][N + 2];
ll ld[N + 2];
ll ru[N + 2];
bool once = true;
void buildWall()
{
    wall[1][0] = 1;    
    for (int i = 1; i <= N; ++i)
    {
        wall[1][i] = wall[1][i - 1];
        if (i >= 2) wall[1][i] += wall[1][i - 2];
        if (i >= 3) wall[1][i] += wall[1][i - 3];
        if (i >= 4) wall[1][i] += wall[1][i - 4];
        wall[1][i] %= mod;
    }
    for (int i = 2; i <= N; ++i)
        for (int j = 1; j <= N; ++j) 
        {
            wall[i][j] = wall[i - 1][j] * wall[1][j];
            wall[i][j] %= mod;
        }
}
int legoBlocks(int n, int m)
{
    if (once) 
    {
        once = false;
        buildWall();
    }
    ld[1] = 0;
    ru[1] = 1;
    for (int i = 2; i <= N; ++i)
    {
        ld[i] = 0;
        for (int j = 0; j < i; ++j)
        {
            ld[i] += wall[n][i-j] * ru[j];
            ld[i] %= mod;
        }
        ru[i] = (wall[n][i] + mod - ld[i]) % mod;
    }
    return ru[m];
}
// =========================================================================
// =========================================================================

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string t_temp;
    getline(cin, t_temp);

    int t = stoi(ltrim(rtrim(t_temp)));

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string first_multiple_input_temp;
        getline(cin, first_multiple_input_temp);

        vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

        int n = stoi(first_multiple_input[0]);

        int m = stoi(first_multiple_input[1]);

        int result = legoBlocks(n, m);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
