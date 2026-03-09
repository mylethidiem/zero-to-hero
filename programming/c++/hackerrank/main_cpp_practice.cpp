#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include "Windows.h"

using namespace std;
/*
* Explain and document experiences/knowledge after testing
* Link: https://www.hackerrank.com/domains/cpp?badge_type=cpp
*/


//======================== STAGE 1
/*
*  3rd March 2026
*/

void dataType()
{
    int i;
    long l;
    char ch;
    float f;
    double d;
    scanf_s("%d %ld %c %f %lf", &i, &l, &ch, (unsigned int)sizeof(ch), &f, &d);
    //GCC: scanf("%d %ld %c %f %lf", &i, &l, &ch, &f, &d);
    printf("%d\n%ld\n%c\n%.3f\n%.9lf\n", i, l, ch, f, d);
}

// q2 ConditionalStatements()

/*#include <bits/stdc++.h>

using namespace std;

string ltrim(const string&);
string rtrim(const string&);



int main()
{
    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    // Write your code here
    if (n == 1)
    {
        printf("one");
    }
    else if (n == 2)
    {
        printf("two");
    }
    else if (n == 3)
    {
        printf("three");
    }
    else if (n == 4)
    {
        printf("four");
    }
    else if (n == 5)
    {
        printf("five");
    }
    else if (n == 6)
    {
        printf("six");
    }
    else if (n == 7)
    {
        printf("seven");
    }
    else if (n == 8)
    {
        printf("eight");
    }
    else if (n == 9)
    {
        printf("nine");
    }
    else
    {
        printf("Greater than 9");
    }

    return 0;
}

string ltrim(const string& str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string& str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}*/

/// q3

/*int main() {
    // Complete the code.
    unsigned int a, b;

    scanf("%d", &a);
    scanf("%d", &b);//b>=a>=1

    int i = a;
    for (; i <= b; i++)
    {
        if (i == 1)
        {
            printf("one");
        }
        else if (i == 2)
        {
            printf("two");
        }
        else if (i == 3)
        {
            printf("three");
        }
        else if (i == 4)
        {
            printf("four");
        }
        else if (i == 5)
        {
            printf("five");
        }
        else if (i == 6)
        {
            printf("six");
        }
        else if (i == 7)
        {
            printf("seven");
        }
        else if (i == 8)
        {
            printf("eight");
        }
        else if (i == 9)
        {
            printf("nine");
        }
        else
        {
            if (i % 2 == 0)
            {
                printf("even");
            }
            else {
                printf("odd");
            }
        }
        printf("\n");
    }
    system("pause");
    return 0;
}*/

// q4
/*
Add `int max_of_four(int a, int b, int c, int d)` here.
*/
/*int max_of_four(int a, int b, int c, int d)
{
    int max = (a > b) ? a : b;
    max = (max > c) ? max : c;
    max = (max > d) ? max : d;
    return max;
}

int main() {
    int a, b, c, d;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    int ans = max_of_four(a, b, c, d);
    printf("%d", ans);

    return 0;
}*/
///q5
/*
* #include <stdio.h>

void update(int *a,int *b) {
    // Complete this function
    int tong = *a + *b;
    int hieu = *a - *b;
    if (hieu < 0)
    {
        *b = -hieu;
    }
    else
    {
       *b = hieu; 
    }
    *a = tong;
}

int main() {
    int a, b;
    int *pa = &a, *pb = &b;
    
    scanf("%d %d", &a, &b);
    update(pa, pb);
    printf("%d\n%d", a, b);

    return 0;
}
*/

///q6 system("pause");
/*
int main() {
    //Enter your code here. Read input from STDIN. Print output to STDOUT
int n;
int arr[10000];
std::cin >> n;
for (int i = 0; i < n; i++)
{
    std::cin >> arr[i];
}

for (int i = n - 1; i >= 1; i--)
{
    std::cout << arr[i] << " ";
}
std::cout << arr[0];
system("pause");
return 0;
}
*/

//======================== STAGE 2

///7

/*
* Sample Input

2 2
3 1 5 4
5 1 2 8 9 3
0 1
1 3
Sample Output

5
9
*/

/*#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n, q;
    std::cin >> n >> q;

    std::vector<std::vector<int>> a(n);

    //input array for each i line
    for (int i = 0; i < n; i++)
    {
        int k;
        std::cin >> k;//number of elements for each array i-th
        a[i].resize(k);
        for (int j = 0; j < k; j++)
        {
            std::cin >> a[i][j];//input value for each elements
        }

    }

    //queries
    for (int k = 0; k < q; k++)
    {
        int i, j;
        std::cin >> i >> j;
        std::cout << a[i][j] << std::endl;///for each array i-th, get the element j-th
    }

    return 0;
}*/

//======================== STAGE 3

/*
*  3rd March 2026
*/