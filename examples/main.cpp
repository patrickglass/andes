/*
* main.cpp
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

#include <iostream>
#include "andes.hpp"

// void test_int_kvp(st::Andes &db) {
//     db.insert(1, 2);
//     db.insert(3, 4);
//     db.insert(5, 6);
// }

void test_string_kvp(st::Andes &db) {
    db.set("key.name", "some string value");
    db["key.name2"] = 234;
    db["key.name"] = "some string value";
    db["key.name2"] = 234;
}

int main() {
    std::cout << "Starting Tests..." << std::endl;

    st::Andes dbmem;

    st::Config cfg = {.filename="tmp.adb", .create_if_missing=true};
    st::Andes db_disk(cfg);

    // test_int_kvp(dbmem);
    // test_int_kvp(db_disk);

    test_string_kvp(dbmem);
    test_string_kvp(db_disk);

    std::cout << "Tests Complete!" << std::endl;
    return 0;
}
