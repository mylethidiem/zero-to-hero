#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include "Windows.h"
#include <string>
#include <algorithm>
#include <set>

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
    Box() : l(0), b(0), h(0) {} //default contructor initialize data members to 0
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
    int n;
    std::cin >> n;
    std::vector<int> v;
    for (int i = 0; i < n; i++)
    {
        int e;
        std::cin >> e;
        v.push_back(e);
    }
    std::sort(v.begin(), v.end());
    for (int i = 0; i < n - 1; i++)
    {
        std::cout << v[i] << " ";
    }
    std::cout << v[n - 1];
}

//q16 Vector-Erase
//Sample Input
//
//6
//1 4 6 2 8 9
//2
//2 4
//Sample Output
//
//3
//1 8 9
void VectorErase()
{
    int n;
    std::cin >> n;
    std::vector<int> v;
    for (int i = 0; i < n; i++)
    {
        int e;
        std::cin >> e;
        v.push_back(e);
    }
    int pos;
    std::cin >> pos;
    if (pos <= v.size())
        v.erase(v.begin() + pos-1);

    int start, end;
    std::cin >> start >> end;
    
    v.erase(v.begin() + start - 1, v.begin() + end - 1);
    std::cout << v.size() << std::endl;

    if (!v.empty())
    {
        for (int i = 0; i < v.size(); i++)
        {
            std::cout << v[i] << (i == v.size() - 1 ? "" : " ");
        }
    }
}

//q17 Lower Bound-STL
void LowerBoundSTL()
{
    int n;
    std::cin >> n;
    std::vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        std::cin >> v[i];
    }
    std::sort(v.begin(), v.end());

    int q;
    std::cin >> q;

    while(q--)
    {
        std::vector<int>::iterator low;
        int val;
        std::cin >> val;
        low = std::lower_bound(v.begin(), v.end(), val); //binary search Ologn
        if (low != v.end() && *low == val)
        {
            std::cout << "Yes" << " ";
        }
        else
        {
            std::cout << "No" << " ";
        }
        std::cout << low - v.begin() + 1 << std::endl;
    }

}

//q18 Sets-STL
void SetsSTL()
{
    int q;
    std::cin >> q;
    std::set<int> s;

    while (q--)
    {
        int u;
        std::cin >> u;
        int val;
        std::cin >> val;
        if (u == 1) // add element
        {
            s.insert(val);
        }
        else if (u == 2)
        {
            s.erase(val);// for vector val is a postion
        }
        else if (u == 3)
        {
            std::set<int>::iterator it = s.find(val);
            if (it != s.end())
            {
                std::cout << "Yes" << std::endl;
            }
            else
            {
                std::cout << "No" << std::endl;
            }
        }
        else
        {
            //std::cout << "Not a query type (value = 1,2,3)";
        }
    }


}


//q19 Maps-STL
#include <map>
void MapsSTL()
{
    std::map<std::string, int> m1;
    int length = m1.size();
    m1.insert(std::make_pair("hello", 9));

    int q;
    std::cin >> q;
    std::map<std::string, int> m;
    while (q--)
    {
        int t;
        std::cin >> t;
        std::string name;
        std::cin >> name;
        std::map<std::string, int>::iterator it_find = m.find(name);
        if (t == 1)
        {
            int mark;
            std::cin >> mark;
            if (it_find != m.end())
            {
                it_find->second += mark;
            }
            else
            { 
                m.insert(std::make_pair(name, mark));
            }
        }
        else if (t == 2)
        {
            m.erase(name);
        }
        else  if (t == 3) {
            //show mark
            if (it_find != m.end())
            {
                std::cout << it_find->second << std::endl;
            }
            else
            {
                std::cout << 0 << std::endl;
            }
            
            
        }
    }

}

//q20 Print Pretty
/*Sample Input

1
100.345 2006.008 2331.41592653498
Sample Output

0x64
_______ + 2006.01
2.331415927E+03*/

#include <iomanip>
void PrintPretty()
{
    int T; cin >> T;
    cout << setiosflags(ios::uppercase);
    cout << setw(0xf) << internal;
    while (T--) {
        double A; cin >> A; //hexadecimal
        double B; cin >> B;
        double C; cin >> C;//scientific 
 
        //  HEX:
        // showbase: add 0x prefix, (long long) A: trip decimal, nouppercase: lowercase
        cout << left << hex << showbase << nouppercase << (long long)A << endl;

        // PADDED FIXED
        // showpos: the sign (+, -), setprecision and fixed:force to show decimals
        // We use 'right' and 'setw(15)' with 'setfill'
        cout << right << setw(15) << setfill('_') << showpos << fixed << setprecision(2) << B << endl;

        //  SCIENTIFIC
        // scientific: 1234.56 becomes 1.234560e+03.
        // Important: noshowpos resets the '+' from the previous line
        cout << scientific << uppercase << setprecision(9) << noshowpos << C << endl;
    }
}
//q21 Inheritance Introduction

class Triangle {
public:
    void triangle() {
        cout << "I am a triangle\n";
    }
};

class Isosceles : public Triangle {
public:
    void isosceles() {
        cout << "I am an isosceles triangle\n";
    }
    //Write your code here.
    void description() {
        cout << "In an isosceles triangle two sides are equal\n";
    }
};


void InheritanceIntroduction()
{
    Isosceles isc;
    isc.isosceles();
    isc.description();
    isc.triangle();
}

//q22 Rectangle Area
class Rectangle
{
protected:
    int m_width, m_height;
public:
    virtual void display() {
        cout << m_width << " " << m_height << endl;
    }
};

class RectangleArea : public Rectangle
{
public:
    void read_input() {
        std::cin >> m_width >> m_height;
    }
    void display() override {
        std::cout << m_width * m_height << endl;
    }
};

void RectangleAreaf()
{
    /*
     * Declare a RectangleArea object
     */
    RectangleArea r_area;

    /*
     * Read the width and height
     */
    r_area.read_input();

    /*
     * Print the width and height
     */
    r_area.Rectangle::display();

    /*
     * Print the area
     */
    r_area.display();
}

//q23 Multi Level Inheritance
class Triangle1 {
public:
    void triangle() {
        cout << "I am a triangle\n";
    }
};

class Isosceles1 : public Triangle1 {
public:
    void isosceles() {
        cout << "I am an isosceles triangle\n";
    }
};

//Write your code here.
class Equilateral : public Isosceles1 {
public:
    void equilateral() {
        cout << "I am an equilateral triangle\n";
    }
};

void MultiLevelInheritance()
{
    Equilateral eqr;
    eqr.equilateral();
    eqr.isosceles();
    eqr.triangle();
}

//q24 C++ Class Templates
#include <cassert>

template <class T>
class AddElements
{
    T m_element;
public:
    AddElements(T element) { m_element = element; }
    T add(T element) {
        return (m_element + element);
    }

    T concatenate(T element) {
        return (m_element + element);
    }
};

void CClassTemplates()
{
    int n, i;
    cin >> n;
    for (i = 0; i < n; i++) {
        string type;
        cin >> type;
        if (type == "float") {
            double element1, element2;
            cin >> element1 >> element2;
            AddElements<double> myfloat(element1);
            cout << myfloat.add(element2) << endl;
        }
        else if (type == "int") {
            int element1, element2;
            cin >> element1 >> element2;
            AddElements<int> myint(element1);
            cout << myint.add(element2) << endl;
        }
        else if (type == "string") {
            string element1, element2;
            cin >> element1 >> element2;
            AddElements<string> mystring(element1);
            cout << mystring.concatenate(element2) << endl;
        }
    }
}

//q25 Preprocessor Solution
#define INF 1000000000
#define FUNCTION(name, op) \
void name(int &current, int candidate) { \
    if (candidate op current) current = candidate; \
}

#define toStr(x) #x
#define io(v) std::cin >> v
#define foreach(v, i) for (int i = 0; i < v.size(); ++i)

#if !defined toStr || !defined io || !defined FUNCTION || !defined INF
#error Missing preprocessor definitions
#endif 

FUNCTION(minimum, < )
FUNCTION(maximum, > )

void PreprocessorSolution()
{
    int n; cin >> n;
    vector<int> v(n);
    foreach(v, i) {
        io(v)[i];
    }
    int mn = INF;
    int mx = -INF;
    foreach(v, i) {
        minimum(mn, v[i]);
        maximum(mx, v[i]);

        /*cout << mx << endl;
        cout << mn << endl;
        cout << v[i] << endl;
        cout << v.size() << endl;*/

    }
    
    int ans = mx - mn;
    cout << toStr(Result = ) << ' ' << ans;
}

//q26 Overload Operators
class Complex
{
public:
    int a, b;
    void input(string s)
    {
        int v1 = 0;
        int i = 0;
        while (s[i] != '+')
        {   
/*            size_t pos = s.find('+');
            if (pos != string::npos) {
                int v1 = std::stoi(s.substr(0, pos)); // Cut from index 0, 3 characters -> "123" -> 123
                a = v1;
            }*/

            //convert char to number: s[i] - '0', xu ly nhanh thuong dung cho lap trinh nhung, ung dung can toc do
            v1 = v1 * 10 + s[i] - '0';
            i++;
        }
        while (s[i] == ' ' || s[i] == '+' || s[i] == 'i')
        {
            i++;
        }
        int v2 = 0;
        while (i < s.length())
        {
            v2 = v2 * 10 + s[i] - '0';
            i++;
        }
        a = v1;
        b = v2;
    }
};

Complex operator+(const Complex c1, const Complex c2)
{
    Complex result;
    result.a = c1.a + c2.a;
    result.b = c1.b + c2.b;
   /* cout << c1.a << " and " << c1.b << endl;
    cout << c2.a << " and " << c2.b << endl;
    cout << result.a << " and " << result.b << endl;*/
    return result;
}
//Friend function allows access to private/protected members if needed
ostream& operator<<(ostream& out, const Complex& c)
{
    out << c.a << "+i" << c.b;
    return out;
}

//Overload operators + and << for the class complex
//+ should add two complex numbers as (a+ib) + (c+id) = (a+c) + i(b+d)
//<< should print a complex number in the format "a+ib"

void OverloadOperators()
{
    Complex x, y;
    string s1, s2;
    cin >> s1;
    cin >> s2;
    x.input(s1);
    y.input(s2);
    Complex z = x + y;
    cout << z << endl;
}


int main() {
    // Complete the program
    //Strings();
    //ClassesStructs();
   // Class();
    //ClassesAndObjects();
    //VectorSort();
    //VectorErase();
    //LowerBoundSTL();
    //SetsSTL();
    //MapsSTL();
    //PreprocessorSolution();
    OverloadOperators();
    return 0;
}

