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











# ahtat204/solarsystem: OpenGL Solar System Visualization 🪐

This repository contains the source code for an OpenGL application that visualizes a **Solar System** using modern C++ and various helper libraries for 3D graphics rendering. The project is structured around object-oriented principles to manage components like the camera, shaders, textures, and the celestial bodies themselves.

## 🚀 Getting Started

The project is configured for **Visual Studio** on Windows, using the C++ package manager **vcpkg** to manage external dependencies.

### Prerequisites

  * **Visual Studio** (The project uses a `.sln` file and `.vcxproj` files).
  * **Git** (for cloning vcpkg).

### Automatic Dependency Setup (Recommended)

To streamline the installation of all necessary libraries, simply run the provided batch file.

1.  **Run the Setup Script:** Locate and **double-click** the `setup.bat` file in the repository's root directory.
2.  **Wait:** The script automatically clones **vcpkg**, bootstraps it, and installs the required dependencies: **GLFW**, **GLM**, and **GLAD**.

### Manual Dependency Setup

If you prefer to manage dependencies manually, you can use the following command (assuming vcpkg is bootstrapped and in your PATH) to install the necessary libraries for a 64-bit Windows build:

```bash
vcpkg install glfw3 glm glad --triplet x64-windows
```

For platform-specific installation guides, you can refer to the official documentation for [GLFW](https://www.glfw.org/), [GLM](https://github.com/g-truc/glm), and [GLAD](https://github.com/Dav1dde/glad).

-----

## 🏗️ Project Architecture

The codebase is built on OpenGL fundamentals, using several custom C++ classes to abstract common rendering concepts.

### Dependencies Overview

| Library | Purpose |
| :--- | :--- |
| **vcpkg** | C/C++ Package Manager for dependency handling. |
| **GLFW** | Manages the **GUI window**, creates the OpenGL context, and handles user input. |
| **GLAD** | A **GL loader** that retrieves the necessary function pointers to interact with the underlying GPU drivers (OpenGL API). |
| **GLM** | **OpenGL Mathematics** library for vectors, matrices, and transformations (essential for 3D graphics). |
| **stb\_image** | Single-file public domain library for loading textures (`.jpg`, etc.). |

### Core Code Structure

The project separates header declarations (`Include/`) from implementation files (`src/`) for modularity.

| Directory | Files | Description |
| :--- | :--- | :--- |
| `src/` | `Main.cpp`, `Camera.cpp`, `Sphere.cpp`, `Window.cpp`, etc. | Contains the implementation logic for all classes, including the main application loop. |
| `Include/` | `Camera.h`, `Mesh.h`, `Sphere.h`, `ShaderClass.h`, etc. | Contains all class header definitions, constants, and utilities. |
| `ressources/` | `Shaders/`, `Earth.jpg`, `mercury.jpg` | Stores external assets like **GLSL shaders** (`.vert`, `.frag`) and **planet textures**. |

-----

## 🎨 Rendering Components

### Celestial Bodies (`Sphere.h`, `SphereFactory.h`)

The core object is the `Sphere` class, which represents a planet or star:

  * **Procedural Geometry:** The sphere's geometry is generated on the **GPU** within the vertex shader (`Sphere.vert`) based on uniform inputs like `stacks` and `slices`, making it highly scalable.
  * **Properties:** It manages the sphere's `radius`, `center` position, and `rotation` properties, which are used to update the world transformation matrix.
  * **Factory Pattern:** The `SphereFactory` suggests the use of a design pattern to easily instantiate different celestial objects (`create_planet`).

### Graphics Pipeline Abstractions

The project uses several classes to abstract standard OpenGL concepts:

| Class | Purpose |
| :--- | :--- |
| `ShaderClass.h` | Encapsulates the compilation and linking of Vertex and Fragment shaders. |
| `VAO.h` / `VBO.h` | Abstractions for **Vertex Array Objects** and **Vertex Buffer Objects**, which manage GPU memory for geometry data. |
| `Texture.h` | Handles loading image data using **stb\_image** and binding it to the GPU. |
| `Mesh.h` | Binds geometry (VAO/VBO), a `Shader`, and a `Texture` to handle a complete draw call. |

### Shaders (`Sphere.vert`, `Sphere.frag`)

The shaders are central to the visualization:

  * **`Sphere.vert` (Vertex Shader):** This shader procedurally generates vertex positions for the sphere geometry using **stacks** and **slices** variables, and calculates texture coordinates (`textCoord`).
  * **`Sphere.frag` (Fragment Shader):** A simple shader that samples a uniform texture (`sphereTexture`) based on the interpolated texture coordinates (`textCoord`) to color the sphere's surface.

<!-- end list -->

```glsl
// Sphere.frag snippet
void main() {
    // Colors the fragment based on the texture at the calculated coordinate
    FragColor = texture(sphereTexture, textCoord);
}
```