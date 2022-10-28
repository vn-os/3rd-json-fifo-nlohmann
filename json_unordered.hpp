#ifndef NLOHMANN_JSON_UNORDERED_HPP
#define NLOHMANN_JSON_UNORDERED_HPP

#include "nlohmann/json.hpp"
#include "nlohmann/fifo_map.hpp"

template<class K, class V, class dummy_compare, class A>
using unordered_fifo_map = nlohmann::fifo_map<K, V, nlohmann::fifo_map_compare<K>, A>;
using json = nlohmann::basic_json<unordered_fifo_map>;

// using json = nlohmann::json; // ordered

#endif  // NLOHMANN_JSON_UNORDERED_HPP