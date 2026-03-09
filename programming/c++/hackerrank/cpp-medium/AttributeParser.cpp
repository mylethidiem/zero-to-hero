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

int x() {
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