#include "processor.h"


std::list<std::string> sort_todo_lines(std::list<std::string> &lines) {

  std::list<std::string> new_lines;
  std::list<std::string> completed_tasks_list;

  // Loop over the lines, parse each one and sort in the different lists to
  // be merged at the end.

  while (!lines.empty()) {
    std::string line = lines.front();
    lines.pop_front();

    // Parse
    Token token = parser(line);

    std::string completed_task_regex = R"(- \[x\])";
    std::regex regex_pattern(completed_task_regex);
    std::string blank_line_regex = R"(^\s*$)";
    std::regex blank_regex_pattern(blank_line_regex);

    if (regex_search(line, regex_pattern)) {
      // Action
      completed_tasks_list.push_back(line);
    } else if (regex_search(line, blank_regex_pattern)) {
      new_lines.splice(new_lines.end(), completed_tasks_list);
      new_lines.push_back(line);
    } else {
      new_lines.push_back(line);
    }
  }
  new_lines.splice(new_lines.end(), completed_tasks_list);

  return new_lines;
}
