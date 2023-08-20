#include <iostream>
#include"string.h"
#include<string>
using namespace std;
int main()
{
    int mode;
    cout << "Enter 0 to safe state mode or 1 for immediate request mode" << endl;
    cin >> mode;
    int n, m, i, j, k;
    int end;
    cout << "Enter the number of process:";
    cin >> n;
    cout << "Enter the number of Resources:";
    cin >> m;
    int l = 0;
    int need[6][5];
    int alloc[6][5]; // Allocation Matrix
    for (int i = 0; i < n; i++)
    {
        cout << "Enter the Allocation matrix of P" << i << endl;
        for (int j = 0; j < m; j++)
        {
            cin >> alloc[i][j];
        }
    }

    int max[6][5]; // P0 // MAX Matrix
    for (int i = 0; i < n; i++)
    {
        cout << "Enter the Maximum matrix of P" << i << endl;
        for (int j = 0; j < m; j++)
        {
            cin >> max[i][j];
        }
    }

    int avail[5]; // Available Resources
    cout << "Enter the Available Resources" << endl;
    for (int i = 0; i < m; i++)
    {
        cin >> avail[i];
    }
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++)
            need[i][j] = max[i][j] - alloc[i][j];
    }
    if (mode == 0)
    {
        int f[6], ans[6], ind = 0;
        for (k = 0; k < n; k++) {
            f[k] = 0;
        }
        int y = 0;
        for (k = 0; k < n; k++) {
            for (i = 0; i < n; i++) {
                if (f[i] == 0) {

                    int flag = 0;
                    for (j = 0; j < m; j++) {
                        if (need[i][j] > avail[j]) {
                            flag = 1;
                            break;
                        }
                    }

                    if (flag == 0) {
                        ans[ind++] = i;
                        l++;
                        for (y = 0; y < m; y++)
                            avail[y] += alloc[i][y];
                        f[i] = 1;
                    }
                }
            }
        }

        if (l == n)
        {
            cout << "Need matrix" << endl;
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    cout << need[i][j] << "  ";
                }
                cout << endl;
            }
            cout << "Yes,it's safe state: " << endl << "<";
            for (i = 0; i < n - 1; i++) {
                cout << "P" << ans[i] << ",";
            }
            cout << "P" << ans[n - 1] << ">" << endl;
        }
        else {
            cout << "Need matrix" << endl;
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    cout << need[i][j] << "  ";
                }
                cout << endl;
            }
            cout << "it's not safe";
        }
    }
    if (mode == 1)
    {
        int index;
        int l2 = 0;
        int flag2 = 0;
        string process, number;
        int Req[5];
        cout << "Enter the Request process" << endl;
        cin >> process;
        number = process[1];
        index = stoi(number);
        cout << "Enter the Request" << endl;
        for (int i = 0; i < m; i++)
        {
            cin >> Req[i];
        }
        for (int i = 0; i < m; i++)
        {
            if (Req[i] <= avail[i] && Req[i] <= need[index][i])
            {
                flag2++;
            }
        }
        for (int i = 0; i < m; i++)
        {
            alloc[index][i] = alloc[index][i] + Req[i];
            avail[i] = avail[i] - Req[i];
        }
        for (i = 0; i < n; i++) {
            for (j = 0; j < m; j++)
                need[i][j] = max[i][j] - alloc[i][j];
        }
        cout << "Need matrix" << endl;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cout << need[i][j] << "  ";
            }
            cout << endl;
        }
        if (flag2 == m)
        {
            for (i = 0; i < n; i++) {
                for (j = 0; j < m; j++)
                    need[i][j] = max[i][j] - alloc[i][j];
            }
            int f[6], ans[6], ind = 0;
            for (k = 0; k < n; k++) {
                f[k] = 0;
            }
            for (i = 0; i < n; i++) {
                for (j = 0; j < m; j++)
                    need[i][j] = max[i][j] - alloc[i][j];
            }
            int y = 0;
            for (k = 0; k < n; k++) {
                for (i = 0; i < n; i++) {
                    if (f[i] == 0) {

                        int flag = 0;
                        for (j = 0; j < m; j++) {
                            if (need[i][j] > avail[j]) {
                                flag = 1;
                                break;
                            }
                        }

                        if (flag == 0) {
                            ans[ind++] = i;
                            l2++;
                            for (y = 0; y < m; y++)
                                avail[y] += alloc[i][y];
                            f[i] = 1;
                        }
                    }
                }
            }
            if (l2 == n)
            {
                cout << "Yes request can be granted with safe state " << endl << "<";
                for (i = 0; i < n - 1; i++) {

                    cout << "P" << ans[i];
                    if (index == ans[i])
                    {
                        cout << "req";
                    }
                    cout << ",";
                }
                cout << "P" << ans[n - 1] << ">" << endl;
            }
            if (l2 != n)
            {
                cout << "No,it's not safe state" << endl;
            }

        }
        else
        {
            cout << "No,it's not safe state" << endl;
        }
    }
    cin >> end;
    return 0;
}