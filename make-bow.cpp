// Arthur Koehl
// reads in a text file and makes bow representation of that file
// writes the bow to a new file
// format: word1 <count> word2 <count> word3 <count> ...
//
//
// can be easily used with gnu parallel in bash


#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char**argv)
{
  if (argc < 2) {
    cout << "no input file specified" << endl;
    return -1;
  }
  
  ifstream infile(argv[1]);
  
  // read file line by line
  // assumption is newlines signify document breaks
  for (string line; getline(ifile, line); )
  {
    // loop through all the words and update counts for unique words
    // create array of all the words (split line on whitespace)
    // create string vector (unique words)
    // create int vector  (count, index should match vector)
    // for each word in word array:
    //    if w in uw vector 
    //    	count[index in vector] ++
    //    else
    //      uw.append(w)
    //      count[len(vector)] = 1

    // write results to file
    // for i=0 in range len(vector)
    //     cout << uw[i] << " " <<  count[i]
    // count << endl;
  }
  


  return 0;
}
