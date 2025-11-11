# 🕹️ miniRT

**miniRT** is a simplified 3D raytracer project from the 42 curriculum. The program reads a scene description from a file, parses objects, lights, and camera information, and renders a 3D image using ray tracing. It supports spheres, planes, cylinders, lights, shadows, reflections, and basic camera controls.  

📦 **Features**

- 🧱 Scene parsing with validation for objects, lights, and camera  
- ✅ Ray tracing with shadows and lighting  
- 💡 Support for spheres, planes, and cylinders  
- 🎨 Simple rendering with MiniLibX  
- 🖱️ Keyboard controls for camera movement and window updates  
- 💥 Memory-safe and robust against invalid input  

🗺️ **Program Rules**

- Scene files must define at least one camera, one light, and one object  
- Only valid coordinates, directions, and colors are accepted  
- The program opens a window and renders the scene in real time  
- Actions and updates are handled via keyboard input  

🚀 **Build & Run**  
⚙️ **Requirements**

- `gcc` or `clang`  
- `MiniLibX` library  

🏗️ **Compilation**

1. Navigate to the project directory:  
```bash
cd miniRT

    Compile using the provided Makefile:

make

    Generates the executable miniRT

    Available make commands:

make clean   # Remove object files
make fclean  # Remove object files and executable
make re      # Recompile everything from scratch

💻 Running the Program

./miniRT [scene.rt]

    Example:

./miniRT scenes/test_scene.rt

    This reads the scene description and opens a window rendering the 3D scene.

📁 Scene File Format (.rt)

    Contains definitions for:

        Camera: C x,y,z dirX,dirY,dirZ fov

        Light: L x,y,z brightness r,g,b

        Objects:

            Sphere: sp x,y,z diameter r,g,b

            Plane: pl x,y,z normalX,normalY,normalZ r,g,b

            Cylinder: cy x,y,z dirX,dirY,dirZ diameter height r,g,b

    All coordinates, directions, and colors must be valid numbers.

    The program will ignore malformed lines and print errors if necessary.

