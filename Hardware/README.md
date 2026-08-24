## Hardware 

The harware system uses a custom PCB designed to interface the MCU with the environmental sensor,OLED display, user controls, alarm indicators and servo controlled ventilation mechanism.

The PCB was designed, assembled and soldered as a part of the project before being intergrated with the firmware and the mechanical system.

### Hardware features

- MCU mating headers for connection to the controller board

- BMP180 temperature and atmospheric pressure sensor interface

- SSD1306 OLED display interface over I²C

- nalogue potentiometer input for adjustable temperature threshold control

- Two push-button inputs for manual open and close override

- SG90 servo interface for ventilation control

- Relay controlled servo power switching

- 2N4401 NPN transistor relay driver

- 1N4004 flyback diode for inductive transient protection

- LED status indicators

- Audible buzzer output

- Local power-supply decoupling capacitors

- External relay output connection

- PCB mounting holes for mechanical integration

## Controller Platform
The system interfaces with a supplied **TSC033 ATmega-based controller board**, which provides the MCU, power regulation, programming interface and I/O connections used by the custom PCB.

The controller board was physically assembled and soldered by me as part of the project before integration with the custom top-board PCB.

Available MCU interfaces used by the system include:

- A0 –Potentiometer input for adjustable temperature threshold.
- A4 / SDA –I²C data connection.
- A5 / SCL –I²C clock connection.
  *Digital inputs -Manual control switches.
- Digital outputs –Status indicators, buzzer, relay and servo control.
- 5 V and GND rails –Power distribution to the custom PCB and peripherals.

The custom PCB was designed to mate with the controller board through the supplied board-to-board connector arrangement.

## Provided and Custom Hardware
Several components were supplied as part of the project platform, including:

- ATmega-based controller board
- I/O daughter board
- SG90 micro servo
- Greenhouse structural frame
- Push rod and associated hardware

These components were integrated with the electronics and mechanical system developed for the project.

My hardware work included:

- Designing the custom mating PCB.
- Designing the supporting sensor, actuator and user-interface circuitry.
- Implementing the relay driver and flyback protection circuit.
- Adding power-supply decoupling.
- Integrating the BMP180 and OLED through I²C.
- Integrating the potentiometer through the MCU ADC.
- Providing interfaces for the servo, buzzer, LEDs and manual controls.
- PCB assembly and soldering.
- System wiring, commissioning and debugging


### Relay Driver Circuit:

The relay is driven using a 2N4401 NPN transistor rather than directly from the MCU output.

The MCU controls the transistor through a base resistor, allowing the transistor to switch the higher relay coil current.

A 1N4004 flyback diode is connected across the relay coil to suppress the inductive voltage spike generated when the relay is switched off.

The relay is used to switch power to the servo motor during movement. Once the required window position has been reached, the firmware disables the relay to remove idle servo power and reduce unnecessary power consumption and servo jitter.

### Potentiometer Interface:

The potentiometer forms an analogue voltage divider between the supply and ground rails.

Its wiper is connected to the MCU's analogue input A0, allowing the firmware to sample its position using the ADC.

The resulting ADC value is mapped in firmware to an adjustable temperature threshold between:
20°C and 35°C

This provides real time hardware adjustment of the ventilation temperature without requiring firmware modification.

### PCB Layout:
The PCB layout integrates the MCU connectors and supporting circuitry onto a single board while providing connections for the sensor, display, servo and user controls.

During layout, component placement was arranged around the required MCU mating headers and mechanical constraints of the greenhouse assembly.

### PCB Assembly:
The PCB was manually assembled and soldered before system commissioning.

Following assembly, continuity and component connections were checked before the board was connected to the MCU and integrated with the complete system.

### Main Components:

- BMP180 - Temperature and atmospheric pressure sensing

- SSD1306 OLED - Real time system information display

- Potentiometer - User adjustable temperature threshold

- SG90 Servo - Greenhouse window actuation

- Relay - Servo power switching

- 2N4401- Relay driver transistor

- 1N4004- Relay flyback protection

- Push Buttons- Manual open/close override

- LEDs- Visual status indication

- Buzzer- Audible over temperature indication

- Decoupling Capacitors- Supply filtering and stability
