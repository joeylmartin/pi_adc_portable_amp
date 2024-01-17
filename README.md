PI ADC Remote AMP Source Code
=====

This is the C source code used for a portable audio processor and amplifier I created for my electric guitar. It uses a PI ADC (https://www.abelectronics.co.uk/p/69/adc-pi-raspberry-pi-analogue-to-digital-converter) to read the analog input, a Raspberry PI Zero 2 W to process the audio, and a Max9744(https://www.analog.com/en/products/max9744.html) as a DAC and amplifier.

However unlikely it is that someone may want to reuse this code, here's some important information:
----------

The left and right audio channnels  are connected to the 1st and 5th analogue pins on the ADC; this is done to process each channel seperately in both MCP3424 chips, which doubles the effective sample rate.

