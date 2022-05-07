"""
This example demonstrates list manipulation using audio data processing.
Audio data from a .wav file is read into a 1D list "samples[]".
You do not need to understand the program code in soundfile.py.
"""

import sys       # for the exit function
import soundfile # for manipulating a sound file

# Open audio.wav and return the samples as a list of numbers
samples = soundfile.read("i_like_big_cars.wav")
if not samples: # If samples list is empty (meaning failure to load)
    print("Cannot open the file. Please try again. Goodbye.")
    sys.exit(0)  # Give up and finish the program here

# Play the audio in the processed 1D list
print("The original sound will be played now")
input("Press Enter")
soundfile.play(samples)

# Access the first second of the audio
samples_out=samples[:44100] 
print("The result of samples[:44100] will be played now")
input("Press Enter")
soundfile.play(samples_out)

# Access the third second of the audio
samples_out=samples[44100*2:44100*3] 
print("The result of samples[44100*2:44100*3] will be played now")
input("Press Enter")
soundfile.play(samples_out)

# Access the third second of the audio in reverse
samples_out=samples[44100*3:44100*2:-1]
print("The result of samples[44100*3:44100*2:-1] will be played now")
input("Press Enter")
soundfile.play(samples_out)
