#include <fstream>
#include <iostream>
#include <queue>
#include <string>

using namespace std;

// CommandLineArgumentParser
// Parses and stores the command line arguments as useful data.
class CommandLineArgumentParser {
private:
  string filename_;

public:
  CommandLineArgumentParser(int &argc, char *argv[]) : filename_("") {
    if (argc != 2) {
      cout << "Wrong number of arguments." << endl;
    } else {
      filename_ = argv[1];
    }
  }

  string get_filename() { return filename_; }
};

// Token
// An enum which tells the parser the return type of the scanner.
enum Token {
  error,
  incomplete_task,
  completed_task,
  bullet_point,
  comment,
  normal_line
};

// Item
// An abstract class that is inherited by task, bullet_point, comment,
// normal_line
class Item {
public:
  virtual void print() = 0;
};

class normal_line {
private:
  string _text;

public:
  normal_line(string const &text) : _text(text) {}
  void print() { cout << _text << endl; }
};

class Scanner {
private:
  string _line;

public:
  Scanner(const string &line) : _line(line) {}

  Token get_token() {
    if (_line.find("- [x] ") != string::npos) {
      return Token::completed_task;
    } else if (_line.find("- [ ] ") != string::npos) {
      return Token::incomplete_task;
    } else if (_line.find("%%") != string::npos) {
      return Token::comment;
    } else if (_line.find("- ") != string::npos) {
      return Token::bullet_point;
    }

    return Token::normal_line;
  }

  string text() { return _line; }
};

class Parser {
public:
  Parser(const string &line) {}

  Token get_item() { return Token::normal_line; }
};

// Processor
// Takes the input from the parser and if the task is completed, it stores it,
// otherwise it passes it to the printer. If the input is an end of paragraph,
// then it prints the completed tasks.
class Processor {
private:
  ifstream _input_stream;
  queue<string> _completed_tasks;

public:
  Processor(string const &filename) : _input_stream(filename) {

    string line;
    while (getline(_input_stream, line)) {
      Scanner scanner(line);
      switch (scanner.get_token()) {
      case Token::normal_line:
        while (!_completed_tasks.empty()) {
          cout << _completed_tasks.front() << endl;
          _completed_tasks.pop();
        }
        cout << scanner.text() << endl;
        break;
      case Token::completed_task:
        _completed_tasks.push(scanner.text());
        break;
      case Token::incomplete_task:
        cout << scanner.text() << endl;
        break;
      case Token::comment:
        cout << scanner.text() << endl;
        break;
      case Token::bullet_point:
        cout << scanner.text() << endl;
        break;
      case Token::error:
        std::cout << "Error" << std::endl;
        break;
      default:
        std::cout << "Error: bad token" << std::endl;
        break;
      }
    }
    while (!_completed_tasks.empty()) {
      cout << _completed_tasks.front() << endl;
      _completed_tasks.pop();
    }
  }

  ~Processor() { _input_stream.close(); }
};

int main(int argc, char *argv[]) {
  CommandLineArgumentParser cmd_parser(argc, argv);

  Processor processor(cmd_parser.get_filename());

  return 0;
};
