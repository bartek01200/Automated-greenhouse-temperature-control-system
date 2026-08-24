## Hardware 

The harware system uses a custom PCB designed to interface the MCU with the environmental sensor,OLED display, user controls, alarm indicators and servo controlled ventilation mechanism.

The PCB was designed, assembled and soldered as a part of the project before being intergrated with the firmware and the mechanical system.

### Hardware features

-MCU mating headers for connection to the controller board

-BMP180 temperature and atmospheric pressure sensor interface

-SSD1306 OLED display interface over I²C

-Analogue potentiometer input for adjustable temperature threshold control

-Two push-button inputs for manual open and close override

-SG90 servo interface for ventilation control

-Relay-controlled servo power switching

-2N4401 NPN transistor relay driver

-1N4004 flyback diode for inductive transient protection

-LED status indicators

-Audible buzzer output

-Local power-supply decoupling capacitors

-External relay output connection

-PCB mounting holes for mechanical integration

### Relay Driver Circuit:

The relay is driven using a 2N4401 NPN transistor rather than directly from the MCU output.

The MCU controls the transistor through a base resistor, allowing the transistor to switch the higher relay-coil current.

A 1N4004 flyback diode is connected across the relay coil to suppress the inductive voltage spike generated when the relay is switched off.

The relay is used to switch power to the servo motor during movement. Once the required window position has been reached, the firmware disables the relay to remove idle servo power and reduce unnecessary power consumption and servo jitter.

### Potentiometer Interface:

The potentiometer forms an analogue voltage divider between the supply and ground rails.

Its wiper is connected to the MCU's analogue input A0, allowing the firmware to sample its position using the ADC.

The resulting ADC value is mapped in firmware to an adjustable temperature threshold between:
20°C and 35°C

This provides real-time hardware adjustment of the ventilation temperature without requiring firmware modification.

### PCB Layout:
The PCB layout integrates the MCU connectors and supporting circuitry onto a single board while providing connections for the sensor, display, servo and user controls.

During layout, component placement was arranged around the required MCU mating headers and mechanical constraints of the greenhouse assembly.

### PCB Assembly:
The PCB was manually assembled and soldered before system commissioning.

Following assembly, continuity and component connections were checked before the board was connected to the MCU and integrated with the complete system.

### Main Components:

- BMP180 - Temperature and atmospheric pressure sensing

- SSD1306 OLED - Real time system information display

- Potentiometer - User-adjustable temperature threshold

- SG90 Servo - Greenhouse window actuation

- Relay - Servo power switching

- 2N4401- Relay-driver transistor

- 1N4004- Relay flyback protection

- Push Buttons- Manual open/close override

- LEDs- Visual status indication

- Buzzer- Audible over temperature indication

- Decoupling Capacitors- Supply filtering and stability
