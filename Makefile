CMAKE_DEBUG_OPTION = -DCMAKE_BUILD_TYPE=Debug
CMAKE_RELEASE_OPTION = -DCMAKE_BUILD_TYPE=Release

third_party_init:
	./third_party_init.sh

third_party_update:
	git submodule update --remote --recursive

gcc_d
	cmake -S . -B build $(CMAKE_DEBUG_OPTION) -DCMAKE_C_COMPILER=gcc -DCMAKE_CXX_COMPILER=g++

clang_d
	cmake -S . -B build $(CMAKE_DEBUG_OPTION) -DCMAKE_C_COMPILER=clang -DCMAKE_CXX_COMPILER=clang++

gcc_r
	cmake -S . -B build $(CMAKE_RELEASE_OPTION) -DCMAKE_C_COMPILER=gcc -DCMAKE_CXX_COMPILER=g++

clang_r
	cmake -S . -B build $(CMAKE_RELEASE_OPTION) -DCMAKE_C_COMPILER=clang -DCMAKE_CXX_COMPILER=clang++
