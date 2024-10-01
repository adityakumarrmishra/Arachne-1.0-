Arachne 1.0 is a quadruple bot designed for remote surveillance in challenging terrains. Using a sophisticated servo system, it can perform precise movements, making it ideal for various applications, including military operations, disaster relief, and environmental monitoring. This repository contains the Arduino code to control the bot's servo movements and functionalities.

Key Features
Quadruple Arm Design: Ensures stability on rugged terrain with precise servo control.
Servo Control: Implements PWM servo control for smooth and accurate movements.
Leg Movement Sequences: Predefined movement patterns for efficient locomotion.
Remote Control: Capable of being operated remotely via a web interface or mobile app.
Customizable Angles: Users can adjust servo angles to optimize movement based on terrain requirements.
Required Components
To build and operate Arachne 1.0, you will need the following hardware:

Microcontroller: Arduino Uno or compatible board.
PWM Servo Driver: Adafruit PCA9685 or similar.
Servo Motors: 12 servos for the arms and movement.
Power Supply: Battery pack (7.4V or 12V).
Connecting Wires: Jumper wires for connections.
Chassis: Custom-built to house all components.
Setup Instructions
1. Hardware Setup
Connect the servos to the PWM driver according to the specified pins in the code.
Ensure proper power connections to the microcontroller and servo driver.
Assemble the chassis and mount all components securely.
2. Software Setup
Clone the Repository:

bash
Copy code
git clone https://github.com/yourusername/arachne-1.0.git
Open the Code in Arduino IDE.

Install Required Libraries:

Wire Library
Adafruit_PWMServoDriver Library
Upload the Code:

Open the Arachne_1_0.ino file in Arduino IDE.
Connect your Arduino to the computer and upload the code.
3. Adjusting Servo Angles
In the code, you may need to adjust the servo angles to suit different terrains:

Locate the setServoAngle function and modify the angle values for the specific servos based on the terrain type.
Example adjustments can be made in functions like leg1, leg2, stance, and others.
Code Overview
The main logic for controlling the servos is in the loop() function, which manages the timing of movements.
The angles for leg movements are defined in the leg1Angles and leg2Angles arrays, allowing for sequential movement control.
Functions like hello() and stance() enable additional movements and gestures.
Usage
Power on the bot.
Connect to the bot's control interface (if implemented).
Monitor the live feed and control the bot's movements.
Adjust servo angles dynamically for optimal performance in various terrains.
Contributing
Contributions are welcome! If you have ideas for improvements or new features, please fork the repository and submit a pull request.

 
