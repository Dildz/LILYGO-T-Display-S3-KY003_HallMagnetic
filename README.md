LILYGO T-Display-S3 KY-004 Push Button Module Project (read pin)

This code reads the digital signal from the KY-004 module and demonstrates debouncing of the push button signal.
The debounced signal is displayed on the built-in screen of the LilyGO T-Display-S3 using the TFT_eSPI library.
The screen is only updated if there is a change in the button state.

Pin Connections:
 - KY-004 VCC  -> 3.3V
 - KY-004 GND  -> GND
 - KY-004 D0   -> GPIO1

KY-004 Specifications:
 - Protocol: Digital
 - Operating Voltage: 3.3V to 5.5V
 - Operating Temperature: -25°C to 105°C

Notes:
 - Signal on GPIO1 is active low, this means that when the button is pressed there is 0V on the pin.
   If the button is released there is 3.3V on the pin. We start with button state HIGH.
 - Try not to touch the 4 button pins on the underside of the module as this will cause the button to switch.
   Mount or hold the module on the edges when pressing the button.
