#!/bin/bash

# Check for Genesis file

#directory="./CardGame"

#if [ -d "$directory" ]; then
#    echo "Folder exists."
#else
#    sudo python3 -m venv ./CardGame
#    sudo chmod -R a+rwx ./CardGame
#    source ./CardGame/bin/activate
#    pip install conan==1.64.0
#    echo "Created folder"
#fi

# output directory

target="Targets/$1"
platform="linux"

# activate python env

#source ./CardGame/bin/activate

#install conan dependencies

#conan install . --install-folder $target --build missing -s build_type=$1 -c tools.system.package_manager:sudo=True -c tools.system.package_manager:mode=install

# generate cmake build files

cmake -S . -B $target -DCMAKE_BUILD_TYPE=$1 -DBUILD_PLATFORM=$platform #-DCMAKE_TOOLCHAIN_FILE="conanbuildinfo.cmake"

# compile cmake build files

cmake --build $target --config $1
