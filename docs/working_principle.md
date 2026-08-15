# Working Principle

The robot uses three ultrasonic sensors positioned at the front, left,
and right sides.

Each sensor sends an ultrasonic pulse and measures the time taken for
the echo to return. This time is converted into distance.

The ESP32 continuously reads the three distances.

If the front distance is greater than the threshold, the robot moves
forward.

When an obstacle is detected in front, the robot stops and compares
the left and right distances.

If the left side has more available space, the robot turns left.
Otherwise, it turns right.

If both sides are blocked, the robot moves backward.

The threshold distance is currently set to 50 cm.
