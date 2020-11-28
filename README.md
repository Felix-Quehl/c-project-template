**Pipeline Status:**   
![PIPELINE](https://github.com/Felix-Quehl/c89-project-template/workflows/Continuous%20Integration/badge.svg?branch=main&event=push)

# ISO9899:1990 (C89, C90, ANSI) Project Example

This repository features a **example project** for the **ISO9899:1990 (C89, C90, ANSI) language standard** with **build system**, **test execution**, **coverage report and check**, all in **automated in a pipeline**.

## Why ISO9899:1990

* portability
* compatibility
* little syntactic sugar
* full control
* low level

## How to Build

Everything is automated using `make` as a build system.
The project uses the `clang` compiler along with `llvm` as tooling for coder coverage.
Install needed packages via your package manage.

```bash
# install needed packages
sudo apt install make clang llvm
```

To build various targets just type `make` and the target name like `release`, `debug` or `test`.
It is recommented to clean build by adding `clean`.

```bash
# clean relase build
make clean release

# clean debug build
make clean debug

# clean debug build
make clean debug
```

To executed the test you should build a `clean` `test` version and execute it with `check`.
To check how many code is coverd by your test execute the `coverage` recipie.

```bash
# performs a clean test build,
# executes the tests and
# makes a code coverage terminal-prompt and check.
make clean test check coverage
```

## Stuff that might be added in the future

* Logging
* API
* Configuration File
