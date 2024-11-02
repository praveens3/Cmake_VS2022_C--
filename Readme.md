# Simple C++ Project with CMake and Visual Studio 2022

## Setting Up CMake 3.30 in Visual Studio Code

This guide will walk you through creating a simple C++ executable project using CMake 3.30 and Visual Studio 2022, and integrating Conan for package management.
Then walks you through setting up CMake 3.30 in Visual Studio Code (VSCode) or your favorite editor. We'll cover creating essential CMake configuration files and using VSCode's CMake extension to build your project.

## Prerequisites

- **CMake 3.30**: Ensure you have CMake 3.30 or later installed.
- **VSCode**: Install Visual Studio Code and the [CMake Tools Extension](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cmake-tools).
- **Visual Studio 2022**: Ensure you have Visual Studio 2022 installed for targeting.
- **Conan 2.x**: Ensure you have installed with conana version greatter than 2.0. ```pip install conan==<version>```

##
### Create `CMakeLists.txt`

In your project directory, create a file named `CMakeLists.txt` and add with your project's configuration details.

### Create `CMakePresets.txt`
In your project directory, create a file named `CMakePresets.txt` and add with your configuration preset's and build preset's details.

### Run `Set_Build` with build targets
Run the build with your desired target

### Enable CMake Extension in VSCode
Open Visual Studio Code.
Press Ctrl+Shift+P (Windows/Linux) or Cmd+Shift+P (macOS) to open the Command Palette.
Type >Reload Window and hit enter. This reloads the VSCode window and ensures that the CMake extension is ready.

### Set the Build Target
Now that your environment is set, you’ll need to choose which build target to work with.
Press Ctrl+Shift+P and type >CMake: Set Build Target.
From the list, choose either vs2022-debug or vs2022-release, depending on whether you're debugging or building a release version of your project.

---
### Download Third-Party packages and link the TP lib with project using CMake (Optional)
### The Package Manager Used Here is Conan 2.0

1. **Install Conan**  
   Ensure you have Conan version 2.0 or higher installed.

2. **Create `conanfile.txt`**  
   Add the needed packages. For example, add the `spdlog` library.

3. **Build the Package**  
   Use the following commands to install and build the packages:

   - For Debug Build:
     ```bash
     conan install . --build=missing -s build_type=Debug
     ```

   - For Release Build:
     ```bash
     conan install . --build=missing
     ```

     to generate files in specific directory --output-folder=build

4. **Add the package deps to `CMakeLists.txt`**
   ```bash
   find_package(spdlog REQUIRED)
   target_link_libraries(testpro PRIVATE spdlog::spdlog)
   ```
---
### Build the Project
With your target selected, you can now build the project using the CMake extension:
Open the CMake Tools sidebar.
Click on Build to start compiling your project.

   Alternatively, Generate Build Files: Run CMake to generate build files:
   ```bash
   cmake --preset <preset-name>
   Ex: cmake --preset vs2022-debug
   ```

### Check the Build Directory
Finally, navigate to the build directory to verify your build files have been generated as expected.
you can open .sln by visual studio IDE and build the project

   Alternately, Build the Project: Build your project:
   ```bash
   cmake --build build --preset <preset-name>
   Ex: cmake --build build --preset build-debug
   ```
