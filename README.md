# Diamond Kata in C

## Scope

Practice the [Diamond Kata](https://www.dyalog.com/blog/2015/01/the-diamond-kata/) in C.

## Goals

Goals:
  * Practice small tests (e.g., baby steps) in C
  * Show how to create and use 2-dimensional array, dynamically allocated
  
## Running it

Build it:
```
cmake -DCMAKE_BUILD_TYPE=Debug -G "CodeBlocks - Unix Makefiles" . -B cmake-build 
make -C cmake-build all
```

Unit tests:
```
./cmake-build/tests/unit_tests
```

Production code:

```
./cmake-build/prod
```

It will show the usage

## Library dependency

This session depends on CMocka. It needs to be included.

You can achieve this by running CMake.

Either manually, or using CLion.

Manually:

```bash
make install-dependencies
```

CLion:

* Open the project, import the CMake configuration

Checking the installation:

* You should see a folder `_deps` inside your cmake build folder
* If you run the tests (either manually or from CLion), 4 tests should pass.

