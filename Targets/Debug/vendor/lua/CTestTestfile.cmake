# CMake generated Testfile for 
# Source directory: /home/nesmy/Playground/Chainsaw-engine/vendor/lua
# Build directory: /home/nesmy/Playground/Chainsaw-engine/Targets/Debug/vendor/lua
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(lua-testsuite "lua" "-e" "_U=true" "all.lua")
set_tests_properties(lua-testsuite PROPERTIES  WORKING_DIRECTORY "/home/nesmy/Playground/Chainsaw-engine/vendor/lua/lua--tests" _BACKTRACE_TRIPLES "/home/nesmy/Playground/Chainsaw-engine/vendor/lua/CMakeLists.txt;31;add_test;/home/nesmy/Playground/Chainsaw-engine/vendor/lua/CMakeLists.txt;0;")
subdirs("lua-5.4.6")
