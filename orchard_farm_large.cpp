#include <bits/stdc++.h>
using namespace std;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input_large.txt", "r", stdin);
    freopen("output_large.txt", "w", stdout);
#endif

    int t, income;
    cin >> t;
    while (t--)
    {
        int n, d;
        cin >> n >> d;
        int tree = n;
        int arr[5][2] = {{12000, 10},
                         {10000, 6},
                         {27500, 15},
                         {7500, 5},
                         {8000, 15}};
        vector<int> per_tree_income;
        for (int i = 0; i < 5; i++)
        {
            int temp = arr[i][0] * (d / arr[i][1]);
            per_tree_income.push_back(temp);
            tree--;
        }
        income = 0;
        for (int i = 0; i < 5; i++)
        {
            income = income + per_tree_income.at(i);
        }
        // cout<<income <<endl;
        sort(per_tree_income.begin(), per_tree_income.end(), greater<int>());

        int max_capacity = (n * 0.4) - 1;
        int i = 0;
        while (tree > 0)
        {
            if (tree > max_capacity)
            {
                income = income + (per_tree_income.at(i) * max_capacity);
                i++;
                tree = tree - max_capacity;
            }
            else
            {
                income = income + (per_tree_income.at(i) * tree);
                i++;
                tree = tree - max_capacity;
            }
        }
        /* for(int i=0;i<5;i++)
        {
            cout<<per_tree_income.at(i)<<endl;
        } */
        cout << income << endl;
    }
}
