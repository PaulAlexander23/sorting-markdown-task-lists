#include <fstream>
#include <iostream>
#include <list>
#include <string>

#include "processor.h"

using namespace std;

int main(int argc, char *argv[]) {
  // Check if we have the right number of arguments.
  if (argc != 2) {
    cerr << "Incorrect number of arguments." << endl;
    return 1;
  }
  // Read the filename and open the file.
  string filename;
  ifstream input_stream;
  try {
    filename.assign(argv[1]);
    input_stream.open(filename);
  } catch (const exception &e) {
    cerr << "Unable to read filename or open file." << endl;
    return 1;
  }

  // Store the context of the file as a list.
  list<string> lines;
  string current_line;
  while (getline(input_stream, current_line)) {
    lines.push_back(current_line);
  }
  // Close the input file.
  input_stream.close();

  // Process the contents of the file
  lines = sort_todo_lines(lines);

  // Output the contents list of lines to the console.
  while (!lines.empty()) {
    string line = lines.front();
    lines.pop_front();
    cout << line << endl;
  }

  // Return succesful.
  return 0;
}
