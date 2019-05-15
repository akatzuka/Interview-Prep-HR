#include <bits/stdc++.h>

using namespace std;

// Complete the hourglassSum function below.
int hourglassSum(vector<vector<int>> arr)
{
    int MaxSum = -36985247;    //lower limit for an int

    for (int i = 0; i < 6; i++) //x coord loop
    {
      for (int j = 0; j < 6; j++) //y coord loop
      {
        if (j + 2 < 6 && i + 2 < 6)
        {
            //sum is the sum of the 7 elements of the given hourglass in the array
          int sum = arr[i][j] + arr[i][j + 1] + arr[i][j + 2] + arr[i + 1][j + 1] +
                    arr[i + 2][j] + arr[i + 2][j + 1] + arr[i + 2][j + 2];
          if (sum > MaxSum) //if sum is greater then MaxSum, set MaxSum equal to sum
            MaxSum = sum;
        }
      }
    }
    return MaxSum;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    vector<vector<int>> arr(6);
    for (int i = 0; i < 6; i++) {
        arr[i].resize(6);

        for (int j = 0; j < 6; j++) {
            cin >> arr[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int result = hourglassSum(arr);

    fout << result << "\n";

    fout.close();

    return 0;
}
