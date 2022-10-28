#ifndef NLOHMANN_JSON_HELPER_H
#define NLOHMANN_JSON_HELPER_H

#include "json_unordered.hpp"

#include <fstream>
#include <algorithm>

namespace json_helper
{

template <typename value_t>
value_t get(const json& jobject, const std::string& name, const value_t def)
{
  return jobject.contains(name) ? jobject[name].get<value_t>() : def;
}

template <>
inline std::wstring get(const json& jobject, const std::string& name, const std::wstring def)
{
  std::string adef;
  std::transform(def.begin(), def.end(), std::back_inserter(adef), [](wchar_t c) { return char(c); });

  std::string astr = get(jobject, name, adef);
  std::wstring result(astr.begin(), astr.end());

  return result;
}

static bool load_from_file(const std::string& file_path, json& data)
{
  data.clear();

  try
  {
    std::ifstream fs(file_path);
    data = json::parse(fs, nullptr, true, true);
  }
  catch (...)
  {
    return false;
  }

  return true;
}

static bool save_to_file(const std::string& file_path, const json& data)
{
  try
  {
    std::ofstream fs(file_path);
    fs << data.dump(2, ' ');
  }
  catch (...)
  {
    return false;
  }

  return true;
}

}; // json_helper

#endif // NLOHMANN_JSON_HELPER_H