# DSA01 – Assignment 4

**Name:** Sarathi.M  
**Register Number:** 1965260151  
**Department:** Cyber Security  
**Course:** Object Oriented Programming with C++ (DSA01)

## Repository structure

- `Assignment4_Answers.pdf` – written assignment answers.
- `Task01/` – reusable payroll hierarchy.
- `Task02/` – virtual inheritance and diamond problem.
- `Task03/` – constructor/member initialization examples.
- `Task04/` – polymorphism, virtual destructor and smart pointers.
- `Task05/` – Cart class, `this` pointer and method chaining.
- `Task06/` – vehicle rental hierarchy and extension example.

## Compiler

Use a C++17 compiler such as g++.

## Compile and run

From the repository root, compile a task using:

```bash
g++ -std=c++17 -Wall -Wextra Task01/main.cpp -o task01
./task01
```

Repeat with the relevant folder for each task. For the AddressSanitizer experiment in Task04, use:

```bash
g++ -std=c++17 -Wall -Wextra -fsanitize=address -fno-omit-frame-pointer Task04/main.cpp -o task04
./task04
```

## Task results

- Task01: Demonstrates a common abstract Staff interface and category-specific pay calculations.
- Task02: Demonstrates virtual inheritance to share one Person base in a diamond hierarchy.
- Task03: Demonstrates base/member construction order and the required initializer-list solution.
- Task04: Demonstrates runtime polymorphism, virtual destruction and unique ownership.
- Task05: Demonstrates object access, the `this` pointer and chainable methods.
- Task06: Demonstrates an extensible abstract Vehicle hierarchy and a new ElectricBus type.

## Submission evidence still to add

The assignment requires the student to execute every task, save genuine output screenshots, and commit progressively (at least one commit per task). Run the programs on your own compiler, add screenshots under each task folder, and record your compiler version below. Do not treat this starter package as proof of execution.

**Compiler/version used:** To be completed by student  
**GitHub repository URL:** To be added after creating the GitHub repository

## Suggested GitHub repository name

`DSA01-1965260151-Assignment4`
