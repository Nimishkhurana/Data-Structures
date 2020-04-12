#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    if (t >= 1 && t <= 100)
    {
        while (t--)
        {
            int n, k;
            cin >> n >> k;
            int arr[k][n];
            for (int i = 0; i < k; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    cin >> arr[i][j];
                }
            }
            int edges[n][n];
            int temp[n][n];
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    edges[i][j] = 0;
                    temp[i][j] = 0;
                }
            }
            for (int i = 0; i < n; i++)
            {
                int first = arr[0][i];
                for (int j = (i + 1); j < n; j++)
                {
                    edges[first][arr[0][j]] = 1;
                }
            }

            /*for(int i=0;i<n;i++){
for(int j=0;j<n;j++){
cout<<edges[i][j]<<"\t";
}
cout<<endl;
}
cout<<endl;*/

            for (int m = 1; m < k; m++)
            {
                for (int i = 0; i < n; i++)
                {
                    int first = arr[m][i];
                    for (int j = (i + 1); j < n; j++)
                    {
                        temp[first][arr[m][j]] = 1;
                    }
                }
                for (int i = 0; i < n; i++)
                {
                    for (int j = 0; j < n; j++)
                    {
                        if (edges[i][j] != temp[i][j])
                            edges[i][j] = 0;
                    }
                }
                for (int i = 0; i < n; i++)
                    for (int j = 0; j < n; j++)
                        temp[i][j] = 0;
            }
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                    cout << edges[i][j] << "\t";
                cout << endl;
            }
        }
    }
    return 0;
}