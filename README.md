# ISO9899:1990 (C89, C90, ANSI) Linux Project Example

This repository features a **example project** targeting Linux for the **ISO9899:1990 (C89, C90, ANSI) language standard** with **make files**, **test execution**.

## Why ISO9899:1990

* portability
* Compatibility
* little syntactic sugar
* Full control
* low level

## Why are there no Frameworks and only standard tooling?

Having external dependencies or foreign code can cause problems.
So writing everything by yourself has advantages:

* Having no frameworks is a lean approach with low overhead
* Writing own tooling help to understand the project's needs
* Solving problems on your increases the developer's skills
* Not having a foreign code means not having to rely on others
* Can be set up and compiled off-line
* reduced binary size because only what's needed is implemented
* fully compatible with your target platform
* no exotic dependencies

## Quick Guide

```bash:
# install needed packages
sudo apt install build-essential make gcc

# run tests
cd ./project/test
make clean test

# compile executable
cd ./project/executable
make clean release
```
