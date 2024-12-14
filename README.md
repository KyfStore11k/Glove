  # Glove: Simplified C++ Project Management

Glove is a tool designed to simplify C++ project development by automating setup, dependency management, and compilation for both VSCode and MSVS. With Glove, you can spend less time configuring and more time coding.

---

## Features
- Easy project creation for VSCode and MSVS.
- Simplified dependency management using YAML.
- Flexible compiler support: GCC, G++, CLANG, and MINGW32.
- Build options: debug, release, and distribution.
- Automated setup of IDE configurations.
- Modern C++ library integration for enhanced performance and usability.

---

## Installation
To install Glove, download the latest release from the [GitHub releases page](https://github.com/KyfStore11k/Glove/releases) and download one of the '.zip' files corresponding to your OS and System Type (i.e., glove_windows-x64.zip, glove_linux_x86.zip, ect.). Then unzip the file, and add the /bin directory into your system environment variable and wala! You have installed 'Glove' onto your system!

---

## Commands
Here’s how you can use Glove:

1. Create a new project with:

   `glove -create -name yourproject -vscode`
   
   `glove -create -name yourproject -msvs`

2. Compile your project:

   `glove -compile -debug -project yourproject.gloveconf`
   
   `glove -compile -release -project yourproject.gloveconf`
   
   `glove -compile -dist -project yourproject.gloveconf`

3. Reload dependencies:

   `glove -reload -dependencies`

---

## Configuration
### Project Configuration
The project configuration is defined in the `glove.config` file. Example:

```gloveconf
project:
  name: "YourProject"
  author: "Your Name"
  description: "A short description of your project"
  version: 1.0.0

compiler:
  type: "GCC"
  flags:
    - "-O2"
    - "-Wall"

folder_struct:
  include: "src/include"
  lib_dir: "src/lib"

dependencies:
  - name: "example-lib"
    version: "1.0.0"
    repository: "https://github.com/example/example-lib"
```

---

### Metadata File for Dependencies
Each dependency includes a `metadata.yml` file with details:

```yaml
name: "My Library"
version: "1.0.0"
origin-repo: "https://github.com/someuser/somelibrary"
hard-dependencies: []
soft-dependencies: []
```

---

## Folder Structure
When creating a project, Glove generates the following structure:

```plaintext
.VSCode/
  launch.json
  tasks.json
  c_cpp_properties.json
SRC/
  main.cpp
GLOVE/
  yourproject.gloveconf
  glove.config
```

---

## Contributing
Contributions are welcome! Please see the [CONTRIBUTING.md](https://github.com/KyfStore11k/Glove/blob/master/CONTRIBUTING.md) for guidelines.

---

## Libraries Used
Glove leverages the following libraries:
- `yaml-cpp` for YAML parsing
- `spdlog` for logging
- `fast_io` for efficient file operations
- `zlib` for archive management
- `libcurl` for network operations
- `CLI11` for argument parsing
- `ctime` for timing

For more information, you can visit the [DEPENDENCIES.md](https://github.com/KyfStore11k/Glove/blob/master/DEPENDENCIES.md).

---

## License
Glove is licensed under the MIT License. See [LICENSE](https://github.com/KyfStore11k/Glove/blob/master/LICENSE) for details.
