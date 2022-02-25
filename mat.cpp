#include<iostream>
#include<fstream>
#include<vector>
using namespace std;

//--------------------------------------
// CS421 File mat.cpp for HW2A Matrix Practice
// Your name: Jake Tremblay
//--------------------------------------

// the following can be changed and the rest of the code should work
int const R = 3;  // number of rows
int const C = 4;  // number of columns
int const VM = 3; // table entry (vector) length

vector<char>  T[R][C];  // 3 rows and 4 columns table for now 

// ------------------ Functions --------------------------------
//only converts the column character to a number
//Chose to make a switch statement here as it is probably the quickest way we can "map" the 
//values together, also is easiest to alter for future projects.
int convert(char x)
{
    switch (x) {
    case 'm':
        return 0;
    case 'n':
        return 1;
    case 'o':
        return 2;
    case 'p':
        return 3;
    }
}

//Read table will pick up all the data in the files.txt file according to the guidelines 
//we were given in the assignment. A local vector is used to store each character one by one, which
//then gets iterated through and put into our global matrix variable T[R][C]. 
int readTable()
{
    int row, col;  // row and col numbers
    char col_c;     // column indicator
    ifstream fin("lines.txt", ios::in);

    // Read in the file into T
    while (fin >> row) // next line of file
    {
        fin >> col_c; col = convert(col_c);  // convert to a slot number
        vector<char> v;  // a vector to fill
        char c; // one char from the file

        // ** Fill v with chars from the file (there are VM chars)
        for(int i = 0; i < VM; i++) {
            fin >> c;                   //get character into c
            v.push_back(c);             //push it into local vector v
        }
        // ** Put  v in T[row][col]
        for (int i = 0; i < VM; i++) {
            T[row][col].push_back(v[i]);   //push into global matrix T
        }

    }//end of while

    fin.close();            //be sure to close the file
    return 0;
}

// Displays a vector or "---" if the vector is empty
void showVector(vector<char> v)
{
    if (v.size() == 0) {  // empty entry
        for (int i = 1; i <= VM; i++) cout << "- ";
        cout << "|";
    }
    else {                  //if the size of our vector is > 0
        for (int i = 0; i < VM; i++) cout << v[i] << " ";
        cout << "|";
    }
}

// Displays T as a table, separating entries with "|" 
void displayTable()
{
    // ** display T nicely labeled with row numbers (col numbers not needed)
    //    by calling showVector 
    for (int i = 0; i < R; i++) {
        cout << endl;
        for (int j = 0; j < C; j++) {
            showVector(T[i][j]);        //shows either --- or the contents of T[i][j]
        }
    }
}

// Driver
int main()
{
    cout << "Reading table from lines.txt..." << endl;
    readTable();
    displayTable();
}//the end
