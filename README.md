# Automatic Train Track Management System 

This project is designed to detect the presence of trains on multiple platforms and control track signals accordingly. Using Light Dependent Resistor (LDR) sensors, the system detects train occupancy on two platforms and adjusts servo motor positions to manage track switching and signal lights. This system is intended for railway applications where automated detection and signaling are needed for efficient train track management and platform safety.

## Key Features
- **Train Detection on Platforms**: Two LDR sensors are used to monitor train presence on each platform. The sensors detect trains based on changes in light intensity, and occupancy status is determined by a defined threshold.
- **Track Switching Mechanism**: A servo motor manages track switching based on platform occupancy. It sets the track to a minimum angle for Platform 1 and to a maximum angle for Platform 2, directing train movement appropriately.
- **Signal Lights Control**: LEDs provide signal indications for each platform. A central LED is activated if both platforms are occupied, while individual platform LEDs indicate track status and guide trains safely when only one platform is occupied.
- **Serial Monitoring for Debugging**: The system outputs the occupancy status of each platform to the Serial Monitor, along with real-time LDR readings for easy monitoring and debugging.

## How it Works
1. **Platform Occupancy Detection**: Each platform is equipped with an LDR sensor connected to analog pins. The LDR sensors detect changes in light intensity when a train is present, with values below a set threshold indicating occupancy.
2. **Track and Signal Management**: 
   - If both platforms are occupied, a central LED is activated to indicate that both tracks are in use, and track switching is paused.
   - If only one platform is occupied, the servo motor adjusts to guide the train along the appropriate track, setting the angle to match the occupied platform.
   - LEDs provide visual feedback for train operators, signaling which platform is clear and safe for entry.
3. **Real-Time Feedback**: All data, including occupancy status and LDR values, are logged to the Serial Monitor, enabling real-time status updates and facilitating maintenance.

This project demonstrates a simplified yet effective approach to automated train detection and track signaling, which can be extended for use in larger railway management systems.
