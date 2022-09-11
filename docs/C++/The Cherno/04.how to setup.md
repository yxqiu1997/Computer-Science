## 04 How to Setup C++ on Linux

### CMakeLists.txt

```
cmake_minimum_required (VERSION 3.5)
project (HelloWorld)
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror -std=c++14")
set (source_dir "${PROJECT_SOURCE_DIR}/src/")

file (GLOB source_files "${source_dir}/*.cpp")
add_executable (HelloWord ${source_files})
```

### build.sh

```bash
#!/bin/sh

cmake -G "CodeLite - Unix Makefiles" -DCMAKE_BUILD_TYPE=Debug
```

