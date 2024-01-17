
#include <alsa/asoundlib.h>


#include <stdio.h>
#include <stdint.h>
#include <time.h>

#include "lib/ADCPi/ABE_ADCPi.h"



void clearscreen ()
{
    printf("\033[2J\033[1;1H");
}

const int I2C_ADDRESS = 0x68; //see address select jumper on ADC Pi board
const int LEFT_AUDIO_CHANNEL = 0; //corresponds to Pins connected to 3.5mm output
const int RIGHT_AUDIO_CHANNEL = 0; //uses other chip for faster sample rate
const int BIT_DEPTH = 16; //12, 14, 16, 18
const int PGA_GAIN = 1; //1, 2, 4, 8
const int CONVERSION_MODE = 1; //conversion mode set to 1 for continous conversion
int adcMaxValue = (1 << BIT_DEPTH) - 1; // 16 bit ADC


int main(int argc, char **argv){
	setvbuf (stdout, NULL, _IONBF, 0); // needed to print to the command line

	while (1){ 
		clearscreen();

        //Read and normalize raw ADC values.
        uint32_t left_channel_data = read_raw(I2C_ADDRESS, LEFT_AUDIO_CHANNEL, BIT_DEPTH, PGA_GAIN, CONVERSION_MODE);
        uint32_t right_channel_data = read_raw(I2C_ADDRESS + 1, RIGHT_AUDIO_CHANNEL, BIT_DEPTH, PGA_GAIN, CONVERSION_MODE);
		
        float normalizedLeft = ((float)left_channel_data / adcMaxValue) * 2.0 - 1.0;
        float normalizedRight = ((float)right_channel_data / adcMaxValue) * 2.0 - 1.0;
        
        //Processing layer?

        //Convert normalized output to format Amplifier expects (MAX9744 20W Class D)

        //Output to i2c registers on GPIO for Amplifier
	}

	(void)argc;
	(void)argv;


	return (0);
}
