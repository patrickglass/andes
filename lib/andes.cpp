/*
* andes.cpp
*
* SwissTech Consulting
* Created on: April 21, 2016
* Author: Patrick Glass
* Copyright: SwissTech Consulting 2016
* Proprietary and confidential
*
* Description:
*
* Usage:
*/

#include <string>
#include "andes.hpp"


st::Andes::Andes() {}
st::Andes::Andes(struct Config config) : _config(config) {}

std::string st::Andes::get(std::string name) {
    return _db.data[name];
}

std::string st::Andes::get(std::string name, std::string def_value) {
    if (_db.data.find(name) != _db.data.end()) {
        return _db.data[name];
    } else {
        return def_value;
    }
}

std::string st::Andes::operator[](const std::string& name) {
    return _db.data[name];
}

// const std::string& st::Andes::operator[](const std::string& name) const {
//     return _db.data[name];
// }

void st::Andes::put(std::string name, std::string value) {
    _db.data[name] = value;
}

void st::Andes::insert(std::string name, std::string value) {
    put(name, value);
}

void st::Andes::set(std::string name, std::string value) {
    put(name, value);
}
