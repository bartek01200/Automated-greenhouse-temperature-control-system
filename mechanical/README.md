## Mechanical 

The mechanical ssystem was designed in Autodesk Fusion 360 to support the  electronics and provide a servo actuated ventilation window.

The design integrates the window mechanism, SG90 servo motor which connects to metal rod, metal rod,roof mount,connector between rod and roof mount, environmental sensor and custom PCB into a complete electromechanical assembly.

## Mechanical Assembly
The greenhouse structure consists of several individual components assembled into the final enclosure and ventilation mechanism.

## CAD Design
Main mechanical components:
- Base plate
- Back panel
- Left and right side panels
- Front brace
- Fixed roof section
- Hinged ventilation roof/window
- SG90 servo mounting arrangement
- Push rod
- roof mount
- push rod connector
- Servo rotator/linkage
- PCB  standoff mounts 4x on each corner to help with cooling and preventing shorting
- Sensor mounting provision
- OLED mounting provision

The assembly was designed to support and integrate the custom PCB, MCU daughter board, BMP180 sensor, OLED display and SG90 servo motor.

**DISCLAIMER**
Intial design was to have PCB on the back and MCU however whilst assembling together i realised its better to have the pcb on top of the MCU as they need to connect thus i did not want to have cables all over the inisde of greenhouse.So i connected both PCB ontop of each other 

## Window Mechanism:
The ventilation window is actuated using an SG90 micro servo mounted to the side of the greenhouse structure.

The servo transfers rotational motion through a mechanical linkage consisting of:
Servo → Rotator → Push Rod → Push-Rod Connector → Hinged Window
This converts the rotational movement of the servo horn into controlled movement of the ventilation window.

The firmware commands two calibrated servo positions:
150° — Window closed
90° — Window open

The linkage geometry and servo positions were selected to provide sufficient window movement while remaining within the mechanical limits of the assembly.

## Electronics Integration
The mechanical assembly was designed around the electronic subsystems rather than treating the electronics and enclosure separately.

The Fusion 360 assembly includes representations of:

- Custom controller PCB
- MCU / I/O daughter board
- BMP180 environmental sensor
- SSD1306 OLED display
- SG90 servo motor

PCB support pins and mounting features were incorporated to secure the electronics while maintaining clearance for components, wiring and moving parts.

## Fabrication
The project used a combination of fabricated structural components and custom designed mechanical parts.
- CAD contains the original Fusion 360 mechanical designs
- STL contains exported models for 3D-printed components
- DXF contains profiles used for laser cut components
**DESIGN FILES ARE SHOWN WITHIN MECHANICAL FOLDER**

## Final Assembly
The completed mechanical system integrates the greenhouse structure, ventilation linkage, servo actuator, sensor and electronics into a single working prototype.

The servo driven linkage successfully converts rotational motion into controlled opening and closing of the hinged greenhouse window.
