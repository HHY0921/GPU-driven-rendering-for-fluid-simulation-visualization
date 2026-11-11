# GPU-Driven Rendering for Particle-Based Fluid Simulation

## Overview
This project visualizes aerodynamic flows and fluid dynamics using a massive particle system. Updating and rendering millions of particles traditionally causes a severe CPU-GPU communication bottleneck (Draw Call Overhead). To solve this, we are implementing a **100% GPU-driven rendering pipeline**. 

By utilizing **Compute Shaders**, **Shader Storage Buffer Objects (SSBOs)**, and **Indirect Drawing**, all particle physics and rendering commands are handled exclusively on the GPU. We will eventually use **Curl Noise** and **Signed Distance Fields (SDFs)** to simulate divergence-free fluid flows around interactive 3D obstacles.

## Prerequisites (Windows 11 / VS Code)
To build and run this project, **MSVC compiler** is used, see guide below. (MinGW/GCC can also be used, but expect version error).

1. **Visual Studio 2022** (Community or Build Tools) installed with the **"Desktop development with C++"** workload.
2. **Visual Studio Code** (VS Code).
3. VS Code Extensions:
   - `C/C++` (by Microsoft)
   - `CMake Tools` (by Microsoft)

## Getting Started

1. **Clone the repository:**
   ```bash
   git clone https://github.com/HHY0921/GPU-driven-rendering-for-fluid-simulation-visualization.git
   ```
2. **Open the project in VS Code:**
   Open the root folder (where `CMakeLists.txt` is located) in VS Code.

3. **Select the Compiler (Crucial Step):**
   - Wait for the CMake Tools extension to initialize.
   - Look at the **bottom blue status bar** in VS Code. Click on the compiler name (it might say `No Kit Selected` or `GCC`).
   - Select **`Visual Studio Community 2022 Release - amd64`** (or similar MSVC amd64 option) from the dropdown at the top of the screen.

4. **Build the Project:**
   - Click the **Gear icon (Build)** on the bottom status bar (or press `F7`). 
   - CMake will automatically download `raylib`, force it to use OpenGL 4.3 (required for Compute Shaders), and compile the project.

5. **Run the Project:**
   - Click the **Play icon (Launch)** on the **bottom status bar** to run the compiled `.exe`.

## Troubleshooting & Known Issues

* **Program takes 10+ seconds to launch:**
  This is caused by Windows Defender scanning the newly built `.exe` every time.
  *Fix:* Open Windows Security -> Virus & threat protection -> Manage settings -> Add or remove exclusions. Add the entire project folder to the exclusion list.
* **Red squiggly lines under `#include "raylib.h"`:**
  This is just an IntelliSense lag; the compiler can actually find it.
  *Fix:* Press `Ctrl + Shift + P`, type `Reload Window`, and hit Enter. Alternatively, ensure your C/C++ Configuration Provider is set to `CMake Tools`.
* **Fatal error: `dwmapi.h`: No such file or directory:**
  You are using an outdated MinGW/GCC compiler.
  *Fix:* Switch your CMake Kit to MSVC (Visual Studio 2022 amd64) and delete your `build` folder to clear the old cache before rebuilding.

## Project Milestones

* **Phase 1: Environment & Baseline (Week 1-2) - *Current***
  - Set up CMake, Raylib, and OpenGL 4.3 environment.
  - Establish a traditional CPU rendering baseline for future benchmarking.
* **Phase 2: GPU Pipeline Integration (Week 3-4)**
  - Implement SSBOs to transfer massive instance data.
  - Write initial Compute Shaders (e.g., gravity particle test) and set up Indirect Drawing (`glMultiDrawElementsIndirect`).
* **Phase 3: Fluid Dynamics & Polish (Week 5-6)**
  - Implement Curl Noise for procedural fluid velocity fields.
  - Apply Signed Distance Fields (SDFs) for particle collision and obstacle avoidance.
  - Finalize visual shading and generate performance comparison graphs.