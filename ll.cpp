
#include<iostream>
#include<stdlib.h>
#include<fstream>
#include <stack>
#include<vector>
#include<string>
using namespace std;

//---------------------------------------
// CS421 File ll1.cpp for HW3A LL1 Table-Driven Parser
// Your name: Jake Tremblay
//---------------------------------------

// Complete this to fit the HW3A specification - look for **
// Must have the same types of tracing couts as my demo program.

// Feel free to use a stack class or use a vector
// to implement your stack.  The stack will contain characters.
stack<char> st;

vector<string> M[3][2];  // the table of rules 
                       // 3 rows for S, A, B
                       // 2 cols for 2, 3
                       // Each slot contains a rule's right side
                        // which is a vector of characters

//  ------- conversion functions ------------------------

// added the functionality to check for incorrect input in the conversion functions
// will throw an exception if the entered input isn't switchable

// to convert non-terms S, A, B to table rows 0, 1, 2
int toRow(char C)
{
    switch (C) {
    case 'S': return 0;
    case 'A': return 1;
    case 'B': return 2;
    default: throw "incorrect input";
    }
}

// to convert '2' and '3' to table columns 0 and 1 
int toCol(char c)
{
    switch (c) {
    case '2': return 0;
    case '3': return 1;
    default: throw "incorrect input";
    }
}

// to convert row 0, 1, 2 to non-terms S, A and B
char toNonterm(int r)
{
    switch (r) {
    case 0: return 'S';
    case 1: return 'A';
    case 2: return 'B';
    default: throw "incorrect input";
    }
}


// to display a rule's rhs which is in vector V
void displayVector(vector<string> V)
{
    if(!V.empty()) std::cout << V[0] << " ";
}

// to read in the rules into M, make sure ; is not stored
void readRules()
{
    fstream fin("rules.txt", ios::in);

    //was getting some errors, adding this to save sanity
    if (!fin.is_open()) {
        std::cout << "error opening file" << endl;
        throw;
    }

    // For each line of "rules" (e.g. S  2 A 2 ;) 
    string s;
    int row, col;

    while (getline(fin >> std::ws, s)) {    //get rid of extra spaces in the input, we dont need them
        // The first char of a line determines the row of M
        row = toRow(s[0]);
        // The second char of a line determine the column of M  
        s.erase(0, 3);          //because of format of file, we can remove first few characters after we read the S, A, B
        s.erase(s.size() - 2);   //also remember to remove trailing semi-colon and spaces
        col = toCol(s[0]);
        // Nowe we should get rid of first and last chars so we can store RHS
        // From second character on to ; is RHS 
     

        M[row][col].push_back(s);
    }

    // ** Display the table nicely  
    //    use toNonterm to show row labels (S, A, B)
    std::cout << "___RULES:___ " << endl;
    for (int i = 0; i < 3; i++) {
        std::cout << toNonterm(i) << "  ";
        for (int j = 0; j < 2; j++) {
            displayVector(M[i][j]);
            std::cout << "  ";
        }
        std::cout << endl;
    }
}

//  pushes V contents to the stack, also will print the contents after adding stuff to it
void addToStack(vector<string> V)
{
    std::cout << "Pushing rhs of a rule to the stack." << endl;
    string s = V[0];
    for (int i = 0; i < s.length(); i++) {
        if(s[i] != ' ') st.push(s[i]);
    }
  
    // ** display the stack vertically from top to bottom
    std::cout << "Stack:" << endl;
    stack<char> cpy;
    while (!st.empty()) {
        cpy.push(st.top());
        st.pop();
    }
    while (!cpy.empty()) {
        cout << cpy.top() << endl;
        char c = cpy.top();
        cpy.pop();
        st.push(c);
    }
}

int main()
{
    readRules();  // M is filled and displayed 
    
    string ss;
    std::cout << "Enter a string made of 2's and/or 3's: ";
    cin >> ss;

    // ** push 'S' onto the stack to start
    st.push('S');
    
    //putting the primary code loop into try block so we can catch exceptions generated from conversion functions
    try {
        int i = 0;  // index for ss
        while (ss[i] != '\0')  // for each char of ss
        {
            if (st.empty()) {           // ** note that empty stack will cause immediate failure  
                throw "stack empty with more chars to process";
                return EXIT_FAILURE;
            }
            std::cout << "Current character is: " << ss[i] << endl;
            // Based on ss[i] and 
            // the top of stack, update the stack: 
            if (st.top() == 'S') {
                int row = toRow('S');
                int col = toCol(ss[i]);
                st.pop();
                addToStack(M[row][col]);
            }
            else if (st.top() == 'A') {
                int row = toRow('A');
                int col = toCol(ss[i]);
                st.pop();
                addToStack(M[row][col]);
            }
            else if (st.top() == 'B') {
                int row = toRow('B');
                int col = toCol(ss[i]);
                st.pop();
                addToStack(M[row][col]);
            }

            if (st.top() == ss[i]) {                        // ** note that top of stack terminal and ss[i] mismatching
                std::cout << "Match found" << endl;           //    will cause immediate failure 
                st.pop();
            }
            else {
                throw "input mismatch with top of stack";
                return EXIT_FAILURE;
            }

            i++;
   
        } // end of string


        if (st.empty()) {
            cout << "Success!" << endl;
            return 0;
        }
        else {
            throw "stack not empty.";
            return EXIT_FAILURE;
        }
    }
    catch (const char* msg) {
        std::cout << "Failed with: " << msg << endl;
        return EXIT_FAILURE;
    }

    
}// end of main
