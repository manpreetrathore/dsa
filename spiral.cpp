#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;

    int a[n][m];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }
    // spiral order print
    int row_start = 0, row_end = n - 1, column_start = 0, column_end = m - 1;
    while (row_start <= row_end && column_start <= column_end)
    {
        // for row start
        for (int col = column_start; col <= column_end; col++)
        {
            cout << a[row_start][col] << " ";
            // cout<<"hi1 \n";
        }

        if (++row_start > row_end)
        {
            break;
        }
        // row_start++;

        //for column end
        for (int row = row_start; row <= row_end; row++)
        {
            cout << a[row][column_end] << " ";
            // cout<<"hi2 \n";
        }
        if (--col_end < col_start)
        {
            break;
        }
        // col_end--;

        // for row end
        for (int col = column_end; col >= column_start; col--)
        {
            cout << a[row_end][col] << " ";
            // cout<<"hi3 \n";
            // this one runs again for center one and is repeated.
        }
        if (--row_end < row_start)
        {
            break;
        }
        // row_end--;

        // for column start
        for (int row = row_end; row >= row_start; row--)
        {
            cout << a[row][column_start] << " ";
            // cout<<"hi4 \n";
        }
        if (++col_start > col_end)
        {
            break;
        }
        // col_start++;
    }
    return 0;
}