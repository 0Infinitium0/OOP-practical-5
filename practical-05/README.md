# Practical 05: Single and Multilevel Inheritance

- **Student Name:** Satinderpal Singh Chaney
- **Roll Number:** E26B00S2034

## Aim
To understand base and derived classes and how data and behaviour can be reused.

## Question
Implement a university-management example using inheritance: `Person` -> `Student` -> `GraduateStudent`.

## Inheritance Diagram

```text
+-----------------------------------+
|              Person               |  <-- Base Class
|-----------------------------------|
| # name_ : std::string             |
| # age_  : int                     |
|-----------------------------------|
| + Person(name, age)               |
| + displayPersonDetails()          |
+-----------------------------------+
                  ^
                  |  Single Inheritance (public)
                  |
+-----------------------------------+
|              Student              |  <-- Derived Class (Level 1)
|-----------------------------------|
| # studentId_ : std::string        |
| # course_    : std::string        |
|-----------------------------------|
| + Student(name, age, id, course)  |
| + displayStudentDetails()         |
+-----------------------------------+
                  ^
                  |  Multilevel Inheritance (public)
                  |
+-----------------------------------+
|          GraduateStudent          |  <-- Derived Class (Level 2)
|-----------------------------------|
| - researchTopic_ : std::string    |
| - supervisor_    : std::string    |
|-----------------------------------|
| + GraduateStudent(...)            |
| + displayGraduateStudentDetails() |
+-----------------------------------+
```

## Inherited Members & Access Explanation
- **`Person` (Base Class):** Defines common attributes (`name_`, `age_`) and `displayPersonDetails()`.
- **`Student` (Single Inheritance from `Person`):**
  - Inherits `name_`, `age_` (accessible as `protected` members inside `Student`), and `displayPersonDetails()` (accessible as a `public` member function).
  - Adds `studentId_`, `course_`, and `displayStudentDetails()`.
- **`GraduateStudent` (Multilevel Inheritance through `Student` from `Person`):**
  - Inherits `name_` and `age_` from `Person` (via `Student`), plus `displayPersonDetails()` and `displayStudentDetails()` as `public` member functions.
  - Inherits `studentId_` and `course_` from `Student` (accessible as `protected` members inside `GraduateStudent`).
  - Adds `researchTopic_`, `supervisor_`, and `displayGraduateStudentDetails()`.

## Compilation & Execution

### Windows (PowerShell / MinGW `g++`)
```powershell
g++ -std=c++17 -Wall -Wextra practical5.cpp -o practical5.exe
.\practical5.exe
```

### Linux / macOS (`g++` / `clang++`)
```bash
g++ -std=c++17 -Wall -Wextra practical5.cpp -o practical5
./practical5
```

## Memory-Checking Instructions

### Option 1: AddressSanitizer & UndefinedBehaviorSanitizer (GCC / Clang — Linux, macOS, WSL)
```bash
g++ -std=c++17 -g -O1 -fsanitize=address,undefined practical5.cpp -o practical5_asan
./practical5_asan
```

### Option 2: Valgrind (Linux / WSL)
```bash
g++ -std=c++17 -g practical5.cpp -o practical5_dbg
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./practical5_dbg
```

## Uploading to GitHub
1. Create a new repository on GitHub (for example, `practical-05-inheritance` or `practical 5`).
2. Extract the ZIP archive into a local folder and push:
   ```bash
   git init
   git add .
   git commit -m "Add Practical 05: Single and Multilevel Inheritance"
   git branch -M main
   git remote add origin <YOUR_GITHUB_REPOSITORY_URL>
   git push -u origin main
   ```
