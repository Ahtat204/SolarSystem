Here is an improved and more elegant README section, expanding on the original content for clarity and professionalism.

-----

# Dependency Management

This project utilizes modern tools to simplify the setup process and ensure consistent builds across development environments. We use **vcpkg** as our primary package manager to handle external libraries.

## 🛠️ Key Dependencies

| Dependency | Purpose |
| :--- | :--- |
| **vcpkg** | The cross-platform command-line package manager for C/C++ libraries. |
| **GLFW** | Manages the **GUI window**, input handling, and context creation for OpenGL. |
| **GLAD** | A **GL loader** library that provides the necessary function pointers to interact with the underlying **GPU drivers** (OpenGL API). |
| **GLM** | (Implicit) Likely included with the provided setup, this is the **OpenGL Mathematics** library for vectors, matrices, and transformations. |

-----

## 📦 Setting up Dependencies (Recommended)

To streamline the installation of all necessary libraries (GLFW, GLM, and GLAD), simply use the provided setup script.

1.  **Run the Setup Script:** Locate and **double-click** the `setup.bat` file in the root of the repository.
2.  **Wait:** The script will automatically clone vcpkg, bootstrap it, and then install all required dependencies for the project.

This method is highly recommended to ensure you have the correct versions and build configurations.

## ⚙️ Manual Installation

If you prefer to manage dependencies yourself, you can manually install the required libraries using vcpkg or by following the instructions on their respective project websites:

```bash
# Example vcpkg command (assuming vcpkg is bootstrapped and in your PATH)
vcpkg install glfw3 glm glad --triplet x64-windows
```

For platform-specific installation guides, please refer to the official documentation for [GLFW](https://www.glfw.org/), [GLM](https://github.com/g-truc/glm), and [GLAD](https://github.com/Dav1dde/glad).