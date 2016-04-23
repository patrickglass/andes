/*
* andes.hpp
*
* SwissTech Consulting
* Created on: April 20, 2016
* Author: Patrick Glass
* Copyright: SwissTech Consulting 2016
* Proprietary and confidential
*
* Description:
*
* Usage:
*/

#pragma once
#include <string>
#include <vector>
#include <unordered_map>
#include <memory>

namespace st {

struct Config {
    std::string filename;
    bool create_if_missing;
};


class BaseValue {};

template <typename T>
class PrimitiveValue : BaseValue {
 private:
    T _value;
 public:
    T get() {
        return _value;
    }
    void put(T value) {
        _value = value;
    }
};

class IntSet : BaseValue {
 private:
    std::vector<int> _values;
 public:
    std::vector<int> get() {
        return _values;
    }

    int get(size_t index) {
        return _values[index];
    }

    void put(size_t index, int value) {
        _values[index]  = value;
    }
};

class Database {
 public:
    std::string auth;
    // std::unordered_map<std::string, std::unique_ptr<BaseValue>> data;
    std::unordered_map<std::string, std::string> data;
};

class Andes {
 private:
    Config _config;
    Database _db;
 public:
    Andes();
    Andes(struct Config config);
    std::string get(std::string name);
    std::string get(std::string name, std::string def_value);
    std::string operator[](const std::string& name);
    // const std::string& operator[](const std::string& name) const;

    void put(std::string name, std::string value);
    void insert(std::string name, std::string value);
    void set(std::string name, std::string value);
};

} /* End namespace st */
