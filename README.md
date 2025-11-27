A line follower robot is an autonomous mobile robot designed to move along a predefined path, usually a black line on a white background (or the opposite).

Two infrared (IR) sensor modules are placed at the front of the robot, slightly above the ground. Each sensor has an IR LED and a photodiode/phototransistor. When the sensor is over a white surface, most of the IR light is reflected back, and the sensor output is typically HIGH. When it is over a black line, the light is absorbed and the output becomes LOW.

An Arduino Uno continuously reads both sensor outputs:

If both sensors see white, the robot assumes it is centered and moves forward.

If the left sensor sees black and the right sees white, the robot has moved left of the line and must turn left to recenter.

If the right sensor sees black and the left sees white, it must turn right.

If both see black (intersection or sharp curve), it can slow down or keep going straight depending on your logic.

The Arduino does not drive the motors directly. Instead, it controls an L293D motor driver IC (or L298N module). The driver allows higher current to the DC motors and enables direction control (forward/reverse) for each motor. The robot is powered by a battery pack (e.g., 7.4 V Li-ion or 9 V + good motors), while the Arduino is powered from the same pack or via USB.

