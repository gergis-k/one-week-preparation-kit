#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'timeConversion' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 * 
 * Gergis Adel
 */

// =========================================================================
// =========================================================================
string timeConversion(string s) {
    string hstr = s.substr(0, 2);
    int hour = stoi(hstr);
    size_t AM = s.find("AM");
    if (AM != string::npos)
    {
        if (hour == 12)
            hstr = "00";
    }
    else
    {
        if (hour + 12 < 24)
            hstr = to_string(hour + 12);
    }
    return s.replace(0, 2, hstr).erase(s.size() - 2);
}
// =========================================================================
// =========================================================================

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = timeConversion(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
