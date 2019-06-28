#include <bits/stdc++.h>

using namespace std;

// Complete the countingValleys function below.
int countingValleys(int n, string s)
{
    int len = s.length();
    int level = 0, valleys = 0;

    for (int i = 0; i< len; i++)
    {
        if (s[i] == 'U')
        {
            level++;
        }
        if (s[i] == 'D')
        {
            if(level == 0)
            {
                valleys++;
            }
            level--;
        }
    }
    return valleys;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string s;
    getline(cin, s);

    int result = countingValleys(n, s);

    fout << result << "\n";

    fout.close();

    return 0;
}
