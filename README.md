# C89 Project with Tests and Code Coverage
 
Modern software development is more then just writing code.  
Tooling like pipelines, testing, code analysis count as standard.  
Even when aged well, C is one of the most powerful programming languages and up to the task.  
To help programmers this reposity should offer a easy starting point for new projects.   
It featuring all the boiler plate code for building and testing a C89 program.  

The **make build system** is ready to use, custom **vanillia C89 testing** examples are setup and **gcov code coverage checking** is scripted in make.
All summed up in a **automated build and test pipeline** using github actions.

What is planed to be implemented:

* Logging
* API
* Configuration File

## How to

```bash
# clean relase build
make clean release

# clean debug build
make clean debug

# performs a clean test build,
# executes the tests and
# makes a code coverage terminal-prompt and check.
make clean test check coverage
```
