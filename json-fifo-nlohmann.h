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

#endif  // INCLUDE_JSON_FIFO_NLOHMANN_H_