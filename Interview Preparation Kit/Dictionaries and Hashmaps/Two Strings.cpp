#include <bits/stdc++.h>

using namespace std;

// Complete the twoStrings function below.
string twoStrings(string s1, string s2)
{
    //initialize hashmap and string length variables
    int str1_len = s1.length();
    int str2_len = s2.length();
    unordered_map<char, char> mapo;

    //initialize char arrays and convert strings to c strings
    const char* char1;
    const char* char2;
    char1 = s1.c_str();
    char2 = s2.c_str();

    //set hashmap using first string; iterate mapping each character to its neighbour
    for(int i = 0; i < str1_len - 1; i++)
    {
        mapo[char1[i]] = char1[i + 1];
    }

    //compare second string to hashmap, if match then return YES, otherwise return NO
    for (int i = 0; i < str2_len; i++)
    {
      if(mapo[char2[i]] != NULL)
      {
          return "YES";
      }
    }

    return "NO";

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s1;
        getline(cin, s1);

        string s2;
        getline(cin, s2);

        string result = twoStrings(s1, s2);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
