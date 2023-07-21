# ISO9899:1990 (C89, C90, ANSI) Linux Project Example

This repository features a **example project** targeting Linux for the **ISO9899:1990 (C89, C90, ANSI) language standard** with **make files**, **test execution**.

## Why ISO9899:1990

* portability
* compatibility
* little syntactic sugar
* full control
* low level

## Why no Frameworks and only standard tooling?

Having external dependencies or foreign code can cause problems.
So writing everything by yourself has advantages:

* Having no frameworks is a lean approach with low overhead
* Writing own tooling help to understand the projects needs
* Solving problems on your own increases the developers skills
* Not having foreign code means not having to rely on others
* Can be setup and compiled off-line
* reduced binary size because only whats needed is implemented
* fully compatible with your target platform
* no exotic dependencies

## Quick Guide

```bash:
# install needed packages
sudo apt install build-essential make gcc

# run tests
cd ./project/test
make clean test

# compile executble
cd ./project/executable
make clean release
```
