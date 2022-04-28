#include<iostream>
#include<fstream>
#include<string>
#include "scanner.cpp"
using namespace std;

/* INSTRUCTION:  Complete all ** parts.
   You may use any method to connect this file to scanner.cpp
   that you had written.  
  e.g. You can copy scanner.cpp here by:
          cp ../ScannerFiles/scanner.cpp .  
       and then append the two files into one: 
          cat scanner.cpp parser.cpp > myparser.cpp
*/

//=================================================
// File parser.cpp written by Group Number: **10
//=================================================

// ----- Four Utility Functions and Globals -----------------------------------
enum parserToken { STORY, S , AFTERSUBJECT, AFTERNOUN, AFTEROBJECT, VERBP, TENSE, NOUN, BE };

// ** For the display names of tokens - must be in the same order as the tokentype.
string parserName[30] = { "story", "s", "afterSubject", "afterNoun", "afterObject", "verb", 
                        "tense", "noun", "be"};
// ** Need syntaxerror1 and syntaxerror2 functions (each takes 2 args)
//    to display syntax error messages as specified by me.  

// Type of error: **
// Done by: ** 
void syntaxError1(  ){    }
// Type of error: **
// Done by: ** 
void syntaxError2(parserToken ptoken) 
{
  cout << "SYNTAX ERROR: unexpected argument." << endl;
  exit(1);
}

// ** Need the updated match and next_token with 2 global vars
// saved_token and saved_lexeme
string saved_lexeme;
tokentype saved_token;

// Purpose: **
// Done by: **

tokentype next_token()
{
  scanner(saved_token,saved_lexeme);

  return saved_token;
}

// Purpose: **
// Done by: **
bool match(tokentype expected) {}

// ----- RDP functions - one per non-term -------------------

// ** Make each non-terminal into a function here
// ** Be sure to put the corresponding grammar rule above each function
// ** Be sure to put the name of the programmer above each function

//<tense> := VERBPAST | VERBPASTNEG | VERB | VERBNEG
void tense()
{
  cout << "Process <tense>" << endl;
  if(next_token() == VERBPAST)
  {
    match(VERBPAST);
  }
  else if (next_token() == VERBPASTNEG)
  {
    match(VERBPASTNEG);
  }
  else if (next_token() == VERB)
  {
    match(VERB);
  }
  else if (next_token() == VERBNEG)
  {
    match(VERBNEG);
  }
  else{
    syntaxError2(TENSE);
  }
}

//<be> ::= IS | WAS
void be()
{
  cout << "Process <be>" << endl;
  if(next_token() == IS)
  {
    match(IS);
  }
  else if (next_token() == WAS)
  {
    match(WAS);
  }
  else{
    syntaxError2(BE);
  }
}

//<verb> ::= WORD2
void verb()
{
  cout << "Process <verb>" << endl;
  match(WORD2);
}

//<noun> ::= WORD1 | PRONOUN
void noun()
{
  cout << "Process <noun>" << endl;
   if(next_token() == WORD1)
  {
    match(WORD1);
  }
  else if(next_token() == PRONOUN)
  {
    match(PRONOUN);
  }
  else{
    syntaxError2(NOUN);
  }
}

//<after object> ::= <verb> <tense> PERIOD | <noun> DESTINATION <verb> <tense> PERIOD
void afterObject()
{
  cout << "Process <afterObject>" << endl;
   if(next_token() == WORD1 || next_token() == PRONOUN)
  {
    noun();
    match(DESTINATION);
    verb();
    tense();
    match(PERIOD);
  }
  else if(next_token() == WORD2)
  {
    verb();
    tense();
    match(PERIOD);
  }
  else{
    syntaxError2(AFTEROBJECT);
  }
}

//<after noun> ::= <be> PERIOD | DESTINATION <verb> <tense> PERIOD | OBJECT <after object>
void afterNoun()
{
  cout << "Process <afterNoun>" << endl;
  if(next_token() == IS || next_token() == WAS)
  {
    be();
    match(PERIOD);
  }
  else if(next_token() == DESTINATION)
  {
    match(DESTINATION);
    verb();
    tense();
    match(PERIOD);
  }
  else if(next_token() == OBJECT)
  {
    match(OBJECT);
    afterObject();
  }
  else{
    syntaxError2(AFTERNOUN);
  }
}

//<after subject> ::= <verb> <tense> PERIOD | <noun> <after noun>
void afterSubject()
{
  cout << "Process <afterSubject>" << endl;
  if(next_token() == WORD2)
  {
    verb();
    tense();
    match(PERIOD);
  }
  else if(next_token() == WORD1 || next_token() == PRONOUN)
  {
    noun();
    afterNoun();
  }
  else{
    syntaxError2(AFTERSUBJECT);
  }
}

//<s> ::= [CONNECTOR] <noun> SUBJECT <after subject>
void s() 
{
  cout << "Process <s>" << endl;
  if(next_token() == CONNECTOR)
  {
    match(CONNECTOR);
    noun();
    match(SUBJECT);
    afterSubject();
  }
  else{
    noun();
    match(SUBJECT);
    afterSubject();
  }
}

//<story> ::= <s> { <s> } 
void story()
{
  cout << "Process <story>" << endl;
  s();

  while(true)
  {
    if(next_token() == EOFM)
    {
      cout << "Success" << endl; 
      break;
    }
    s();
  }
}

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
