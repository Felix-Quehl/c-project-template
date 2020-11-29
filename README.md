  ![PIPELINE](https://github.com/Felix-Quehl/c89-project-template/workflows/Continuous%20Integration/badge.svg?branch=main&event=push)

# ISO9899:1990 (C89, C90, ANSI) Project Example

This repository features a **example project** for the **ISO9899:1990 (C89, C90, ANSI) language standard** with **build system**, **test execution**, **coverage report and check**, all in a **automated pipeline**.

## Why ISO9899:1990

* portability
* compatibility
* little syntactic sugar
* full control
* low level

## Why no Frameworks and only standard tooling?

Having external dependecies or foreign code can cause problems.
So writing everthing by yourself has advandages:

* Having no frameworks is a lean approche with low overhead
* Writing own tooling help to understand the projects needs
* Solving problems on your own increases the developers skills
* Not having foreign code means not having to rely on others
* Can be setup and compiled off-line
* reduced binary size because only whats needed is implemented
* fully compartible with your target platform
* no exotic dependecies

## Documentation

For a detailed tour of the code take a look at [the project page](https://felix-quehl.github.io/c-project-template/).

## Quick Guide

```bash
# install needed packages
sudo apt install make clang llvm

# clean relase build
make clean release

# clean debug build
make clean debug

# clean debug build
make clean debug
```

To add tests search for the `struct TestInfo tests[]`  in `./src/main_test.c` and add a entry at the end like `{my_test_function, "Cool Test"}`.

## Stuff that might be added in the future

* Logging
* API
* Configuration File
