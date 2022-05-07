"""
This example demonstrates list manipulation using audio data processing.
Audio data from a .wav file is read into a 1D list "samples[]".
You do not need to understand the program code in soundfile.py.
"""

import sys       # for the exit function
import soundfile # for manipulating a sound file

# The following demonstrates the techniques with an audio list
print("The following demonstrates the techniques with an audio list.")
print()

# Open audio.wav and return the samples as a list of numbers
samples = soundfile.read("i_like_big_cars.wav")
if not samples: # If samples list is empty (meaning failure to load)
    print("Cannot open the file. Please try again. Goodbye.")
    sys.exit(0)  # Give up and finish the program here

# Play the audio in the processed 1D list
print("The original sound will be played now")
input("Press Enter")
soundfile.play(samples)

# The first half of the audio
samples_out=samples[ :int(len(samples)/2)]
print("The result of samples[ :int(len(samples)/2)] will be played now")
input("Press Enter")
soundfile.play(samples_out)

# The first 25% of the audio
samples_out=samples[ :int(len(samples)*.25)]
print("The result of samples[ :int(len(samples)*.25)] will be played now")
input("Press Enter")
soundfile.play(samples_out)

# The last half of the audio
samples_out=samples[int(len(samples)/2): ]
print("The result of samples[int(len(samples)/2): ] will be played now")
input("Press Enter")
soundfile.play(samples_out)

# The last 25% of the audio
samples_out=samples[int(len(samples)*.75): ]
print("The result of samples[int(len(samples)*.75): ] will be played now")
input("Press Enter")
soundfile.play(samples_out)
