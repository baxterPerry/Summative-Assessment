# Summative Assessment - Jamie Caughley, Baxter Perry & Sam Morgan

# Masher

<img width="752" alt="Screen Shot 2020-06-21 at 10 59 29 PM" src="https://user-images.githubusercontent.com/61439735/85223561-16071880-b418-11ea-83fc-8ef994d2dfda.png">

### Masher is a simple bit quantisation software plugin, available  in VST, VST3, or AU format. It features:
Bit Quantisation 
Low Pass
High Pass
Dry/Wet Mix
Input Gain
Output Gain
### The state of the plugin is fully recallable, and all parameters are able to be automated. 

### Signal Flow:
Input Signal → Input Gain →  Bit Quantisation → Low Pass → High Pass → Dry/Wet Mix → Output Gain → Output Signal

### Quantisation Process:
The algorithm in charge of this operation takes the floating point value of the current sample, and multiplies it by the “quantisation amount” variable. The result is then rounded to the nearest integer, and so all the data points after the decimal point are lost. This is then divided by the same “quantisation amount” variable to convert the rounded value back into a floating point variable. 

### Example:

0.53627 = current sample value “s”

100 = Bit quantisation amount "q"

s * q = 53.627		

53.627 is rounded to int = 53	

53 / q = 0.53

0.53 = new “s” value

### Filters
The filters are based off of Juce’s dsp library. There are 3 types of filter: High Pass, Low Pass and Band Pass. The masher features both high and low pass after the bit quantisation takes place meaning you can fine tune the tone of the distortion. The filters have a range from 20 to 20000 Hz covering the full spectrum of sound audible to the human ear. 

### Mix
The mix fader takes the wet and dry values and adds them up to 1. To set this up we took the raw inBuffer sample and the overall quantised sample after all of the processing has happened. We then make wet = 1 - dry. In further iterations of the plugin there may be a mix fader pre and post filter so that you can control how much of the filtered signal is audible as well. 

### Gain
Both the input and output gain are a simple multiplication of the buffer by a floating value between 0 and 3. Anything lower than one reduces the amount of signal and anything above 1 increases the signal. The input gain allows the user to control the gating that the quantisation creates.

### GUI 
Ergonomic design with separate colours for each slider
Left and right + Up and down to change parameters 
Different sized sliders given for importance of effect
Separate design for the mix slider

## Install instructions
To download the plugin, you download the masher.pkg file, and then choose your format from there. You will save the plugin, on your computer in a location set by yourself. And then scan for new plugins in your DAW. 


