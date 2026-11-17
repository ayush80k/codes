CGM LAB - TURBO C++ SOURCE FILES

Contents:
01. Basic graphics primitives: line, circle and ellipse
02. Plot a pixel using putpixel()
03. DDA line drawing algorithm
04. Bresenham line drawing algorithm
05. Midpoint circle drawing algorithm
06. Midpoint ellipse drawing algorithm
07. 2D transformations: translation, rotation, scaling, reflection, shearing
08. Cohen-Sutherland line clipping algorithm
09. 3D transformations: translation, rotation, scaling
10. Composite 3D transformations: scaling, rotation, translation
11. 3D wireframe objects: cube, cuboid, pyramid
12. Sierpinski triangle using recursion

SETUP:
All programs use:
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

If your BGI folder is in a different location, change this path in each file.
For example, some installations use:
    "C:\\TC\\BGI"

COMPILE:
Open a source file in Turbo C++, compile and run it.
Run each program separately.

NOTES:
- Experiments 7, 9 and 10 display the original object in WHITE and the
  transformed object in GREEN.
- The 2D program uses a triangle as the sample object. Coordinates are
  entered by the user.
- The 3D programs use a wireframe cube and a simple oblique projection.
- Experiment 10 applies scaling, then rotation, then translation.
- For Experiment 12, recursion levels 0 to 7 are accepted to keep drawing
  time and screen complexity manageable.
