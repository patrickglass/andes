#
# bootstrap.sh
#
# SwissTech Consulting
# Created on: April 23, 2016
# Author: Patrick Glass
# Copyright: SwissTech Consulting 2016
# Proprietary and confidential
#
# Description:
#
# Usage:
#       ./bootstrap.sh
#   OR
#       source bootstrap.sh
#
echo "Building Andes!"
mkdir -p build
pushd build
rm * -rf
# Build with GCC
# cmake .. && make && /usr/bin/ctest
# rm * -rf
# Build with Clang
# cmake -DCMAKE_C_COMPILER=clang -DCMAKE_CXX_COMPILER=clang++ .. && make && /usr/bin/ctest
cmake -DCMAKE_BUILD_TYPE=Debug -DCMAKE_C_COMPILER=clang -DCMAKE_CXX_COMPILER=clang++ .. && make && /usr/bin/ctest
popd
