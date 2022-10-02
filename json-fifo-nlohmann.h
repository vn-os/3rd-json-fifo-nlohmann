#ifndef INCLUDE_JSON_FIFO_NLOHMANN_H_
#define INCLUDE_JSON_FIFO_NLOHMANN_H_

#include "nlohmann/json.hpp"
#include "nlohmann/fifo_map.hpp"

// using json = nlohmann::json; // ordered

template<class K, class V, class dummy_compare, class A>
using unordered_fifo_map = nlohmann::fifo_map<K, V, nlohmann::fifo_map_compare<K>, A>;
using json = nlohmann::basic_json<unordered_fifo_map>;

template <typename value_t>
value_t json_get(const json& jobject, const std::string& name, const value_t def)
{
  return jobject.contains(name) ? jobject[name].get<value_t>() : def;
}

#include <fstream>

bool json_load_from_file(const std::string& file_path, json& data)
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

bool json_save_to_file(const std::string& file_path, const json& data)
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

#endif  // INCLUDE_JSON_FIFO_NLOHMANN_H_