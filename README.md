LILYGO T-Display-S3 KY-003 Hall Magnetic Sensor Module Project

This code reads the digital signal from the KY-003 module and displays the sensor state on the built-in screen of the LilyGO T-Display-S3 using the TFT_eSPI library. The screen is only updated if there is a change in the sensor state.

Pin Connections:
 - KY-003 VCC  -> 3.3V
 - KY-003 GND  -> GND
 - KY-003 D0   -> GPIO1

KY-003 Specifications:
 - Operating Voltage: 3.3V to 5.5V
 - Operating Temperature: -40°C to 85°C
 - Output: Digital

Notes:
 - Signal on GPIO1 is active low, this means that when a magnetic field is detected, there is 0V on the pin. If no magnetic field is detected, there is 3.3V on the pin. We start with sensor state HIGH.
