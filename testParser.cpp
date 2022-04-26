#include<iostream>
#include<fstream>
#include<string>
using namespace std;

//=====================================================
// File scanner.cpp written by: Group Number: 10
//=====================================================

// --------- Two DFAs ---------------------------------

// WORD DFA 
// Done by: Sophia
bool word(string s)
{
    int state = 0;
    int charpos = 0;
    // replace the following todo the word dfa  **
    while (s[charpos] != '\0')
    {
        //trs(q0,V) = q0q1
        if (state == 0 && (s[charpos] == 'a' || s[charpos] == 'i' || s[charpos] == 'u' || s[charpos] == 'e' || s[charpos] == 'o' || s[charpos] == 'I' || s[charpos] == 'E'))
        {
            state = 1;
        }
        //trs(q0,'c') = qC
        else if (state == 0 && s[charpos] == 'c')
        {
            state = 2;
        }
        //trs(q0,'s') = qS
        else if (state == 0 && s[charpos] == 's')
        {
            state = 3;
        }
        //trs(q0,'t') = qT
        else if (state == 0 && s[charpos] == 't')
        {
            state = 4;
        }
        //trs(q0,'bghkmnpr') = qY
        else if (state == 0 && (s[charpos] == 'b' || s[charpos] == 'g' || s[charpos] == 'h' || s[charpos] == 'k' || s[charpos] == 'm' || s[charpos] == 'n' || s[charpos] == 'p' || s[charpos] == 'r'))
        {
            state = 5;
        }
        //trs(q0,'dwzyj') = qSa
        else if (state == 0 && (s[charpos] == 'd' || s[charpos] == 'w' || s[charpos] == 'z' || s[charpos] == 'y' || s[charpos] == 'j'))
        {
            state = 6;
        }
        //trs(qSa,V) = q0q1
        else if (state == 6 && (s[charpos] == 'a' || s[charpos] == 'i' || s[charpos] == 'u' || s[charpos] == 'e' || s[charpos] == 'o' || s[charpos] == 'I' || s[charpos] == 'E'))
        {
            state = 1;
        }
        //trs(qY,V) = q0q1
        else if (state == 5 && (s[charpos] == 'a' || s[charpos] == 'i' || s[charpos] == 'u' || s[charpos] == 'e' || s[charpos] == 'o' || s[charpos] == 'I' || s[charpos] == 'E'))
        {
            state = 1;
        }
        //trs(qY,'y') = qSa
        else if (state == 5 && s[charpos] == 'y')
        {
            state = 6;
        }
        //trs(qT,V) = q0q1
        else if (state == 4 && (s[charpos] == 'a' || s[charpos] == 'i' || s[charpos] == 'u' || s[charpos] == 'e' || s[charpos] == 'o' || s[charpos] == 'I' || s[charpos] == 'E'))
        {
            state = 1;
        }
        //trs(qT,'s') = qSa
        else if (state == 4 && s[charpos] == 's')
        {
            state = 6;
        }
        //trs(qS,V) = q0q1
        else if (state == 3 && (s[charpos] == 'a' || s[charpos] == 'i' || s[charpos] == 'u' || s[charpos] == 'e' || s[charpos] == 'o' || s[charpos] == 'I' || s[charpos] == 'E'))
        {
            state = 1;
        }
        //trs(qS,'h') = qSa
        else if (state == 3 && s[charpos] == 'h')
        {
            state = 6;
        }
        //trs(qC,'h') = qSa
        else if (state == 2 && s[charpos] == 'h')
        {
            state = 6;
        }
        //trs(q0q1,V) = q0q1
        else if (state == 1 && (s[charpos] == 'a' || s[charpos] == 'i' || s[charpos] == 'u' || s[charpos] == 'e' || s[charpos] == 'o' || s[charpos] == 'I' || s[charpos] == 'E'))
        {
            state = 1;
        }
        //trs(q0q1,'c') = qC
        else if (state == 1 && s[charpos] == 'c')
        {
            state = 2;
        }
        //trs(q0q1,'s') = qS
        else if (state == 1 && s[charpos] == 's')
        {
            state = 3;
        }
        //trs(q0q1,'t') = qT
        else if (state == 1 && s[charpos] == 't')
        {
            state = 4;
        }
        //trs(q0q1,'bghkmpr') = qY
        else if (state == 1 && (s[charpos] == 'b' || s[charpos] == 'g' || s[charpos] == 'h' || s[charpos] == 'k' || s[charpos] == 'm' || s[charpos] == 'p' || s[charpos] == 'r'))
        {
            state = 5;
        }
        //trs(q0q1,'dwzyj') = qSa
        else if (state == 1 && (s[charpos] == 'd' || s[charpos] == 'w' || s[charpos] == 'z' || s[charpos] == 'y' || s[charpos] == 'j'))
        {
            state = 6;
        }
        //trs(q0q1,'n') = q0qY   **new state
        else if (state == 1 && s[charpos] == 'n')
        {
            state = 7;
        }
        //trs(q0qY,V) = q0q1
        else if (state == 7 && (s[charpos] == 'a' || s[charpos] == 'i' || s[charpos] == 'u' || s[charpos] == 'e' || s[charpos] == 'o' || s[charpos] == 'I' || s[charpos] == 'E'))
        {
            state = 1;
        }
        //trs(q0qY,'c') = qC
        else if (state == 7 && s[charpos] == 'c')
        {
            state = 2;
        }
        //trs(q0qY,'s') = qS
        else if (state == 7 && s[charpos] == 's')
        {
            state = 3;
        }
        //trs(q0qY,'t') = qT
        else if (state == 7 && s[charpos] == 't')
        {
            state = 4;
        }
        //trs(q0qY,'bghkmnpr') = qY
        else if (state == 7 && (s[charpos] == 'b' || s[charpos] == 'g' || s[charpos] == 'h' || s[charpos] == 'k' || s[charpos] == 'm' || s[charpos] == 'n' || s[charpos] == 'p' || s[charpos] == 'r'))
        {
            state = 5;
        }
        //trs(q0qY,'dwzyj') = qSa
        else if (state == 7 && (s[charpos] == 'd' || s[charpos] == 'w' || s[charpos] == 'z' || s[charpos] == 'y' || s[charpos] == 'j'))
        {
            state = 6;
        }
        //trs(q0qY,'y') = qSa
        else if (state == 7 && s[charpos] == 'y')
        {
            state = 6;
        }
        else
        {
            return(false);
        }

        charpos++;
    }//end of while

    // where did I end up????
    if (state == 1 || state == 7)
    {
        return(true);  // end in a final state
    }
    else
    {
        return(false);
    }
}

// PERIOD DFA 
// Done by: Sophia
bool period(string s)
{  // complete this **
    int state = 0;
    int charpos = 0;
    while (s[charpos] != '\0')
    {
        if (state == 0 && s[charpos] == '.')
        {
            state = 1;
        }
        else
        {
            return(false);
        }
        charpos++;
    } //end of while

    // where did I end up????
    if (state == 1)
    {
        return(true);  // end in a final state
    }
    else
    {
        return(false);
    }
}

// ------ Three  Tables : tokentype, tokenName, reservedWords--------------------

// TABLES Done by: Sophia
// ** Update the tokentype to be WORD1, WORD2, PERIOD, ERROR, EOFM, etc.
enum tokentype { ERROR, WORD1, WORD2, PERIOD, VERB, VERBNEG, 
                VERBPAST, VERBPASTNEG, IS, WAS, OBJECT, SUBJECT, DESTINATION, 
                PRONOUN, CONNECTOR, EOFM };

// ** For the display names of tokens - must be in the same order as the tokentype.
string tokenName[30] = { "ERROR", "WORD1", "WORD2", "PERIOD", "VERB", "VERBNEG", 
                        "VERBPAST", "VERBPASTNEG", "IS", "WAS", "OBJECT", "SUBJECT", "DESTINATION",
                        "PRONOUN", "CONNECTOR", "EOFM"};

// ** Need the reservedwords table to be set up here. 
// ** Do not require any file input for this. Hard code the table.
// ** a.out should work without any additional files.
string reservedWords[20][2] =
{
  "masu", "VERB",
  "masen", "VERBNEG",
  "mashita", "VERBPAST",
  "masendeshita", "VERBPASTNEG",
  "desu", "IS",
  "deshita", "WAS",
  "o", "OBJECT",
  "wa", "SUBJECT",
  "ni", "DESTINATION",
  "watashi", "PRONOUN",
  "anata", "PRONOUN",
  "kare", "PRONOUN",
  "kanojo", "PRONOUN",
  "sore", "PRONOUN",
  "mata", "CONNECTOR",
  "soshite", "CONNECTOR",
  "shikashi", "CONNECTOR",
  "dakara", "CONNECTOR",
  "eofm", "EOFM"
};


// ------------ Scanner and Driver ----------------------- 

ifstream fin;  // global stream for reading from the input file

// Scanner processes only one word each time it is called
// Gives back the token type and the word itself
// ** Done by: Jake 
int scanner(tokentype & tt, string & w)
{
    fin >> w;                               // ** Grab the next word from the file via fin
    
    if (w == "eofm") return 0;              // 1. If it is eofm, return right now.   
    
      
    //2. Call the token functions (word and period) one after another (if-then-else).
    //   Generate a lexical error message if both DFAs failed. Let the tokentype be ERROR in that case.
    
    if (word(w)) {
        bool reserved = false;
        //w is a recognized word, do step 3 check against reserved
        int resSize = sizeof(reservedWords) / sizeof(reservedWords[0][0]);
        for (int i = 0; i < resSize/2; i++) {
            if (w == reservedWords[i][0]) {
                string tokenType = reservedWords[i][1];         //if we find a match in the reservedWords list
                int numOfEle = sizeof(tokenName) / sizeof(tokenName[0]);
                
                for (int j = 0; j < numOfEle; j++) {            //go through until we find the correct token type then break
                    if (tokenType == tokenName[j]) {
                        tt = (tokentype)j;
                        reserved = true;                        //allows us to shortcut out of the scanner
                        break;
                    }
                }
                break;
            }   
        }

        if (reserved) return 0;             //if the word was found to be a reserved word our work is done
        
	char back = *w.rbegin();
        if (back == 'I' || back == 'E') {       //if the word wasn't reserved, it becomes a WORD1 if it does not have a capital I or E
            tt = WORD2;
        }
        else {
            tt = WORD1;
        }
    }
    else if(period(w)) {                    //if it wasn't a word, it must be a period
        //s is a period
        tt = PERIOD;
    }
    else {                                  //otherwise it is an error
        //lexical error
        tt = ERROR;
        cout << "LEXICAL ERROR" << endl;
    }
    
    return 0;

}//the end of scanner

// The temporary test driver to just call the scanner repeatedly  
// This will go away after this assignment
// DO NOT CHANGE THIS!!!!!! 
// Done by:  Louis
int main()
{
    tokentype thetype;
    string theword;
    string filename;

    cout << "Enter the input file name: ";
    cin >> filename;

    fin.open(filename.c_str());

    // the loop continues until eofm is returned.
    while (true)
    {
        scanner(thetype, theword);  // call the scanner which sets
                                    // the arguments  
        if (theword == "eofm") break;  // stop now

        cout << "Type is:" << tokenName[thetype] << endl;
        cout << "Word is:" << theword << endl << endl;
    }

    cout << "End of file is encountered." << endl;
    fin.close();

}// end of scanner section


//=========================================================================
/* INSTRUCTION:  Complete all ** parts.
   You may use any method to connect this file to scanner.cpp
   that you had written.
  e.g. You can copy scanner.cpp here by: cp ../ScannerFiles/scanner.cpp .
       and then append the two files into one: cat scanner.cpp parser.cpp > myparser.cpp
*/

//=================================================
// File parser.cpp written by Group Number: **
//=================================================

// ----- Four Utility Functions and Globals -----------------------------------

// ** Need syntaxerror1 and syntaxerror2 functions (each takes 2 args)
//    to display syntax error messages as specified by me.  

// Type of error: **
// Done by: ** 
void syntaxerror1() {    }
// Type of error: **
// Done by: ** 
void syntaxerror2() {    }

// ** Need the updated match and next_token with 2 global vars
// saved_token and saved_lexeme

// Purpose: Probably to read the next token, such that we dont have nondeterministic input?
// Done by: **
token_type next_token() {
    //return the type of the next token
}

// Purpose: If the next token is the expected type we can pop the stack (or something like that)
// Done by: **
boolean match(tokentype expected) {
    //if(next_token() == expected)
}

// ----- RDP functions - one per non-term -------------------

// ** Make each non-terminal into a function here
// ** Be sure to put the corresponding grammar rule above each function
// ** Be sure to put the name of the programmer above each function

// Grammar: **
// Done by: **

string filename;

//----------- Driver ---------------------------

// The new test driver to start the parser
// Done by:  **
int main()
{
    cout << "Enter the input file name: ";
    cin >> filename;
    fin.open(filename.c_str());

    //** calls the <story> to start parsing
    //** closes the input file 

}// end
//** require no other input files!
//** syntax error EC requires producing errors.txt of error messages
//** tracing On/Off EC requires sending a flag to trace message output functions
