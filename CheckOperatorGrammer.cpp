#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    cout << "OPERATOR Grammer CHECK :\n\n";

    int count = 0;

    char a[30][20];
    char b;

    int nofp;
    cout << "Number of Production" << endl;
    cin >> nofp;

    cout << "\nEnter grammar productions\n";

    while (nofp--)
    {
        cin >> a[count];
        count++;
    }

    cout << endl;
    cout << "Grammar is \n";

    for (int j = 0; j < count; j++)
    {
        cout << a[j] << endl;
    }

    cout << endl
         << endl;

    char operators[20] = {'!', '%', '^', '*', '(', ')', '-', '+', '=', '/', '{', '}', '[', ']', '<', '>', '|', '&', '~', '0'};
    int flag = 0;

    for (int j = 0; j < count; j++)
    {
        int temp;
        int i = 0, k = 0;
        int cnt1 = 0, cnt2 = 0;
        int cnt = 0;

        while (a[j][k] != '\0')
        {
            cnt++;
            k++;
        }

        if (cnt == 3 && a[j][cnt - 1] == '#')
        {
            flag = 1;
            break;
        }

        while (a[j][i] != '\0')
        {
            for (int k = 0; k < 19; k++)
            {
                if (a[j][i] == operators[k])
                {
                    temp = 0;
                    break;
                }
                else
                {
                    temp = 1;
                }
            }

            if (temp == 1)
            {
                cnt2 = cnt1;
                cnt1 = i;
            }

            i++;

            if (cnt1 - cnt2 == 1)
            {
                flag = 1;
                break;
            }
        }
    }

    if (flag == 1)
    {
        cout << "Grammer in not Operator Grammer\n\n";
    }
    else
    {
        cout << "Grammer is Operator Grammer";
    }

    return 0;
}