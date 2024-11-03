#pragma once

#include "parser.h"
#include "token.h"
#include <list>
#include <regex>
#include <string>

std::list<std::string> sort_todo_lines(std::list<std::string> &lines);
