#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include "Windows.h"
#include <string>

using namespace std;
/*
* Explain and document experiences/knowledge after testing
* Link: https://www.hackerrank.com/domains/cpp?badge_type=cpp
*/


//======================== STAGE 1 EASY
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

/*#include <bits/stdc++.h> // only run in Hackerrank

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
void ForLoop()
{
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
}
/*int main() {
    // Complete the code.
   ForLoop();
    system("pause");
    return 0;
}*/

// q4
/*
Add `int max_of_four(int a, int b, int c, int d)` here.
*/

int max_of_four(int a, int b, int c, int d)
{
    int max = (a > b) ? a : b;
    max = (max > c) ? max : c;
    max = (max > d) ? max : d;
    return max;
}
void Function()
{
    int a, b, c, d;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    int ans = max_of_four(a, b, c, d);
    printf("%d", ans);
}

/*

int main() {
    Function();
    return 0;
}*/


///q5
void update(int* a, int* b) {
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
void Pointer()
{
    int a, b;
    int* pa = &a, * pb = &b;

    scanf("%d %d", &a, &b);
    update(pa, pb);
    printf("%d\n%d", a, b);
}

/*
* 
int main() {
    Pointer();
    return 0;
}
*/

///q6 system("pause");
void ArraysIntroduction()
{
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
}
/*
int main() {
ArraysIntroduction();
system("pause");
return 0;
}
*/

//======================== STAGE 1.2 EASY

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

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
void VariableSizedArrays()
{
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
}

//int main() {
//    
//    VariableSizedArrays()
//    return 0;
//}

//======================== STAGE 2 EASY
//q8
/*
*  3rd March 2026
*/

/*#include <sstream>
#include <vector>
#include <iostream>
using namespace std;

vector<int> parseInts(string str) {
    // Complete this function
    vector<int> v;
    int temp;
    char ch;
    stringstream ss(str);
    while (ss >> temp)
    {
        v.push_back(temp);
        ss >> ch;
    }

    return v;
}

int main() {
    string str;
    cin >> str;
    vector<int> integers = parseInts(str);
    for (int i = 0; i < integers.size(); i++) {
        cout << integers[i] << "\n";
    }
    system("pause");
    return 0;
}*/

//q9
void Strings()
{
    string a, b;
    std::cin >> a;
    std::cin >> b;
    std::cin.ignore();

    std::cout << a.length() << " " << b.length() << std::endl;
    std::string sum = a + b;
    std::cout << sum << std::endl;

    auto temp = a.at(0);
    a.at(0) = b.at(0);
    b.at(0) = temp;
    std::cout << a << " " << b << std::endl;
}

//q10 Input and Output => super very easy

//q11 Classes Structs
struct Student1
{
    int age;
    string  first_name;
    string  last_name;
    int standard;
};

void ClassesStructs() {
    Student1 st;

    cin >> st.age >> st.first_name >> st.last_name >> st.standard;
    cout << st.age << " " << st.first_name << " " << st.last_name << " " << st.standard;
}

//q12 Classes Class
class Student
{
public:
    int m_age;
    string  m_first_name;
    string  m_last_name;
    int m_standard;

    void set_age(int age);
    int get_age();

    void set_standard(int standard);
    int get_standard();

    void set_first_name(string first_name);
    string get_first_name();

    void set_last_name(string last_name);
    string get_last_name();

    string to_string();
    
};
void Student::set_age(int age)
{
    m_age = age;
}

int Student::get_age()
{
    return m_age;
}

void Student::set_standard(int standard)
{
    m_standard = standard;
}

int Student::get_standard()
{
    return m_standard;
}

void Student::set_first_name(string first_name)
{
    m_first_name = first_name;
}

string Student::get_first_name()
{
    return m_first_name;
}

void Student::set_last_name(string last_name)
{
    m_last_name = last_name;
}

string Student::get_last_name()
{
    return m_last_name;
}

string Student::to_string()
{
    return std::to_string(m_age) + "," + m_first_name + "," + m_last_name + "," + std::to_string(m_standard);
}

void Class()
{
    int age, standard;
    string first_name, last_name;

    cin >> age >> first_name >> last_name >> standard;

    Student st;
    st.set_age(age);
    st.set_standard(standard);
    st.set_first_name(first_name);
    st.set_last_name(last_name);

    cout << st.get_age() << "\n";
    cout << st.get_last_name() << ", " << st.get_first_name() << "\n";
    cout << st.get_standard() << "\n";

    cout << "\n";
    cout << st.to_string();
}

//q13 Classes and Objects
class Student2
{
public:
    int m_scores[5];
    void input();
    int calculateTotalScore();
};
void Student2::input()
{
    for (int i = 0; i < 5; i++)
    {
        cin >> m_scores[i];
    }
}
int Student2::calculateTotalScore()
{
    int totalScores = 0;
    for (int i = 0; i < 5; i++)
    {
        totalScores += m_scores[i];
    }
    return totalScores;
}
void ClassesAndObjects()
{
    int n; // number of students
    cin >> n;
    Student2* s = new Student2[n]; // an array of n students

    for (int i = 0; i < n; i++) {
        s[i].input();
    }

    // calculate kristen's score
    int kristen_score = s[0].calculateTotalScore();

    // determine how many students scored higher than kristen
    int count = 0;
    for (int i = 1; i < n; i++) {
        int total = s[i].calculateTotalScore();
        if (total > kristen_score) {
            count++;
        }
    }

    // print result
    cout << count;
}

//q14 Box It!
//#include<bits/stdc++.h>

using namespace std;


//Implement the class Box  
//l,b,h are integers representing the dimensions of the box
class Box
{
public:
    Box() : l(0), b(0), h(0) {}
    Box(int length, int breadth, int height) {
        l = length;
        b = breadth;
        h = height;
    }
    Box(const Box& B) { // Copy Constructor
        l = B.l;
        b = B.b;
        h = B.h;
    }
    int getLength(); // Return box's length
    int getBreadth(); // Return box's breadth
    int getHeight();  //Return box's height
    long long CalculateVolume(); // Return the volume of the box

    bool operator<(Box& b);
    friend ostream& operator<<(ostream& out, Box& B);

private:
    int l, b, h;//length , breadth , and height .

};

int Box::getLength()
{
    return l;
}
int Box::getBreadth()
{
    return b;
}
int Box::getHeight()
{
    return h;
}
long long Box::CalculateVolume()
{
    return (long long)l * b * h;
}
bool Box::operator<(Box& b)
{
    if (this->getLength() < b.getLength())
        return true;
    else if (this->getBreadth() < b.getBreadth() && this->getLength() == b.getLength())
    {
        return true;
    }
    else if (this->getHeight() < b.getHeight() && this->getBreadth() == b.getBreadth() && this->getLength() == b.getLength())
    {
        return true;
    }
    return false;
}
// 4. Overload <, cach gon hon
//bool operator<(const Box& b) {
//    if (l < b.l) return true;
//    if (b.l == l && this->b < b.b) return true;
//    if (b.l == l && b.b == this->b && h < b.h) return true;
//    return false;
//}

ostream& operator<<(ostream& out, Box& B)
{
    out << B.l << " " << B.b << " " << B.h;
    return out;
}
// The class should have the following functions : 

// Constructors: 
// Box();
// Box(int,int,int);
// Box(Box);


// int getLength(); // Return box's length
// int getBreadth (); // Return box's breadth
// int getHeight ();  //Return box's height
// long long CalculateVolume(); // Return the volume of the box

//Overload operator < as specified
//bool operator<(Box& b)

//Overload operator << as specified
//ostream& operator<<(ostream& out, Box& B)


void check2()
{
    int n;
    cin >> n;
    Box temp;
    for (int i = 0; i < n; i++)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            cout << temp << endl;
        }
        if (type == 2)
        {
            int l, b, h;
            cin >> l >> b >> h;
            Box NewBox(l, b, h);
            temp = NewBox;
            cout << temp << endl;
        }
        if (type == 3)
        {
            int l, b, h;
            cin >> l >> b >> h;
            Box NewBox(l, b, h);
            if (NewBox < temp)
            {
                cout << "Lesser\n";
            }
            else
            {
                cout << "Greater\n";
            }
        }
        if (type == 4)
        {
            cout << temp.CalculateVolume() << endl;
        }
        if (type == 5)
        {
            Box NewBox(temp);
            cout << NewBox << endl;
        }

    }
}

void BoxIt()
{
    check2();
}

//q15 Vector-Sort
void VectorSort()
{

}

//q16 Vector-Erase
void VectorErase()
{

}

//q17 Lower Bound-STL
void LowerBoundSTL()
{

}

//q18 Sets-STL
void SetsSTL()
{

}


//q19 Maps-STL
void MapsSTL()
{

}

//q20 Print Pretty
void PrintPretty()
{

}

//q21 Inheritance Introduction
void InheritanceIntroduction()
{

}

//q22 Rectangle Area
void RectangleArea()
{

}

//q23 Multi Level Inheritance
void MultiLevelInheritance()
{

}

//q24 C++ Class Templates
void CClassTemplates()
{

}

//q25 Preprocessor Solution
void PreprocessorSolution()
{

}

//q26 Overload Operators
void OverloadOperators()
{

}


int main() {
    // Complete the program
    //Strings();
    //ClassesStructs();
   // Class();
    ClassesAndObjects();
    return 0;
}

