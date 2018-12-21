// Arthur Koehl
// 
// arg1 is input text file name
// outputs arg1.dat as output
// format: word1 <count> word2 <count> word3 <count> ...
//
// can be easily used with gnu parallel in bash


#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <string.h>
#include <algorithm>

using namespace std;

int main(int argc, char**argv)
{
  if (argc < 2) {
    cout << "no input file specified" << endl;
    return -1;
  }
  
  ifstream infile(argv[1]);
  ofstream outfile;
  string fname = string(argv[1]);
  string newfname = fname.substr(0,fname.find_last_of('.')) + ".dat";
  outfile.open(newfname.c_str());
  
  // read file line by line
  // assumption is newlines signify document breaks
  for (string line; getline(infile, line); )
  {
    vector<string> words; //all words in line
    vector<string> unique;
    vector<int> counts;
    
    // read all the words into a vector
    char *token;
    char delims[] = " \t"; // space and tab
    token = strtok(&line[0], delims);
    while (token != NULL)
    {
      words.push_back(token);
      token = strtok (NULL, delims);
    }
    
    // for each word in line
    // check if word is in the vector of unique words
    // if yes:
    //   store the index
    // if index (word was found):
    //   update the count at that index
    // else
    //   add word to unique words vector and initialize its count to 1
    for (int i = 0; i < words.size(); i++)
    {
      int indx = -1;
      for (int j = 0; j < unique.size(); j++)
      {
        if (unique[j] == words[i])
          indx = j;
      }
      if (indx == -1)
      {
        unique.push_back(words[i]);
        counts.push_back(1);
      } 
      else
      {
        counts[indx] ++;
      }
          
    }//for word in line
     
    for (int i = 0; i < unique.size(); i++)
    {
      outfile << unique[i] << " " << counts[i] << " ";
    }
  }//for each line in file

  return 0;
}//main
