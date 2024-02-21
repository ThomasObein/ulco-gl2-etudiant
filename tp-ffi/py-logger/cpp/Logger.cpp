#include "Logger.hpp"

#include <algorithm>
#include <iomanip>
#include <map>
#include <sstream>

void Logger::addItem(Level l, const std::string & m) {
  _items.push_back(std::make_tuple(l, m));
}

std::string Logger::reportByAdded() const {
  std::string output = "**** report_by_added ****\n";
  for (const auto& tuple : _items) {
    switch (std::get<0>(tuple))
    {
    case Level::Info:
      output += "[I] ";
      break;
    case Level::Warning:
      output += "[W] ";
      break;
    case Level::Error:
      output += "[E] ";
      break;
    }
    output += std::get<1>(tuple) + "\n";
  }
  return output;
}

std::string Logger::reportByLevel() const {
  std::vector<Item> infos;
  std::vector<Item> warnings;
  std::vector<Item> errors;

  for (const auto& tuple : _items) {
    Level level = std::get<0>(tuple);
    switch (level)
    {
    case Level::Info:
      infos.push_back(tuple);
      break;
    case Level::Warning:
      warnings.push_back(tuple);
      break;
    case Level::Error:
      errors.push_back(tuple);
      break;
    }
  }

  std::string output = "**** report_by_level ****\n";

  for (const auto& info : infos) {
      output += "[I]" + std::get<1>(info) + "\n";
  }

  for (const auto& warning : warnings) {
      output += "[W]" + std::get<1>(warning) + "\n";
  }

  for (const auto& error : errors) {
      output += "[E]" + std::get<1>(error) + "\n";
  }
  return output;
}

