//You are given an unordered array consisting of consecutive integers [1, 2, 3, ..., n]
//without any duplicates. You are allowed to swap any two elements. You need to find the
//minimum number of swaps required to sort the array in ascending order.
//Since we need to get the sorted array into order, we can compare a given element
//to the index of the next, if they are the same, it is in the correct spot

#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the minimumSwaps function below.
int minimumSwaps(vector<int> arr)
{
    //Initalize swaps counter
    int swaps = 0;
    //Initalize loop for length of the array
    for (int i = 0; i < arr.size(); i++)
    {
        //If element arr[i] is equal to i+1, then iterate loop
        if (arr[i] == (i+1))
        {
            continue;
        }
        //Swap element with element at index of current element's value - 1
        swap(arr[i], arr[arr[i]-1]);
        swaps++;
        i--;
    }
    return swaps;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split_string(arr_temp_temp);

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    int res = minimumSwaps(arr);

    fout << res << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
