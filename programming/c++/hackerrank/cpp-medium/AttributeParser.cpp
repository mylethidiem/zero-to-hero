#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include "Windows.h"

using namespace std;
/*
* Explain and document experiences/knowledge after testing
* Link: https://www.hackerrank.com/domains/cpp?badge_type=cpp
*/


//======================== STAGE 1 MEDIUM
/*
*  3rd March 2026
*/
//Attribute Parser

/*
Sample Input

4 3
<tag1 value = "HelloWorld">
<tag2 name = "Name1">
</tag2>
</tag1>
tag1.tag2~name
tag1~name
tag1~value
Sample Output

Name1
Not Found!
HelloWorld
*/

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <map>

using namespace std;

int cach1() {
    int n, q;

    cin >> n >> q;

    cin.ignore(); // Clear the buffer after entering n, q

    map<string, string> hrml; // Store: "tag1.tag2~name" -> "value"

    vector<string> tag_stack; // Keep track of open tags

    for (int i = 0; i < n; i++) {// for each line in data

        string line;

        getline(cin, line);

        if (line.substr(0, 2) == "</") {

            // Case of closed tag: </tag1>

            if (!tag_stack.empty()) tag_stack.pop_back();

        }
        else {
            // Case of opening tag: <tag1 value = "Hello">
            // Remove < and >

            line.erase(0, 1); // Remove <

            if (line.back() == '>') line.pop_back(); // Remove >

            stringstream ss(line);

            string tag_name, attr, equal, value;

            ss >> tag_name; // Get tag name (e.g., tag1)

            tag_stack.push_back(tag_name);

            // Process attribute = "value" pairs

            while (ss >> attr >> equal >> value) {

                // Remove double quotes around value

                // value is in the form "HelloWorld" -> HelloWorld

                if (value.front() == '\"') value.erase(0, 1);

                if (value.back() == '\"') value.pop_back();

                // Create key according to structure: tag1.tag2~attr
                string full_path = "";
                for (int j = 0; j < tag_stack.size(); j++) {
                    full_path += tag_stack[j] + (j == tag_stack.size() - 1 ? "" : ".");
                }
                hrml[full_path + "~" + attr] = value;
            }
        }
    }

    // Handle q questions 
    for (int i = 0; i < q; i++) {
        string query;
        getline(cin, query);
        if (hrml.count(query)) {
            cout << hrml[query] << endl;
        }
        else {
            cout << "Not Found!" << endl;
        }
    }

    return 0;
}
int cach2()// dung 1 case
{

    int n, q;
    cin >> n >> q;
    
    //input val into the map
    std::map <string, string> hrml;
    cin.ignore();
    string current = "";
    
    while(n--)
    {
        std::string s;

        getline(cin, s);
    
        //for each line
        int j = 0;
        
        if (s[j] == '<' && s[j+1] != '/')
        {
            j++;
            if (!current.empty())
            {
                current += '.';
            }
            while(s[j] != ' ')
            {
                current += s[j];
                
                j++;
            } //tag
            //cout << "tag" << current << endl;
            //attribute
            j++;
            while(s[j] != '>')
            {
                //cout << "check2" << endl;
                string path = current + '~';
                while (s[j] != ' ' && s[j] != '=')
                {
                    
                    path += s[j];
                    j++;
                }
                //cout << "path: "<< path << endl;
                if (s[j] == ' ')//problem here
                {
                    j += 4;
                }
                if (s[j] == '=')
                {
                    j += 2;
                }
                //val of map
                string val = "";
                while(s[j] != '"')
                {
                    //cout << "check4" << endl;
                    val += s[j];
                    j++;
                }//done val
                //cout << "val: " << val << endl;
                //add map
                hrml[path] = val;
                
                j++;
                
            }
        }
    }
    int i = 0;
    std::map<string, string>::iterator it = hrml.begin();
    for (; it != hrml.end(); it++)
    {
        std::cout << it->first << endl;
        std::cout << it->second << endl;
    }
    for(;i< q; i++)//for each query
    {
        string query;
        getline(cin, query);
        //std::cout << "query = " << query << endl;
        std::map<string, string>::iterator it = hrml.find(query);
        if (it != hrml.end())
        {
            std::cout << it->second <<endl;
            
        }
        else {
            cout << "Not Found!" <<endl;
        }
    }
    return 0;
}
int c3()
{
    int n, q;
    cin >> n >> q;
    cin.ignore();

    string tag = "";
    map<string, string> hrml;
    while (n--)
    {
        int j = 1; // default 0 char is '<'
        string s;
        getline(cin, s);
        if (s[j] == '/')
        {
            n--;
            continue;
        }
        if (!tag.empty())
        {
            tag += '.';
        }

        while (s[j] != ' ')
        {
            tag += s[j];
            j++;
        }
        j++;

        string currentPath = tag;
        while (s[j] != '>')
        {
            currentPath += '~';

            while (s[j] != ' ' && s[j] != '=')
            {
                currentPath += s[j];
                j++;
            }
            if (s[j] == ' ')
            {
                j += 4;
            }
            if (s[j] == '=')
            {
                j += 2;
            }

            string val = "";
            while (s[j] != '"')
            {
                val += s[j];
                j++;
            }

            //add map
            hrml[currentPath] = val;
        }

        //query
        while (q--)
        {
            string query;
            cin >> query;

            map<string, string>::iterator it = hrml.find(query);
            if (it != hrml.end())
            {
                cout << it->second << endl;
            }
            else {
                cout << "Not Found!" << endl;
            }
        }
    }
}
int main()
{
    cach2();
    return 0;
}