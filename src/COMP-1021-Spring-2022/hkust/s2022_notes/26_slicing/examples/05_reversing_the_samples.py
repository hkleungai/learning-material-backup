"""
This example demonstrates list manipulation using audio data processing.
Audio data from a .wav file is read into a 1D list "samples[]".
You do not need to understand the program code in soundfile.py.
"""

import sys       # for the exit function
import soundfile # for manipulating a sound file

# The following demonstrates the techniques with an integer list
print("The following demonstrates the techniques with an integer list.")
print()
samples = [0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20]
print("samples =", samples)
print("samples[ : : -1] =", samples[ : : -1])
print("samples[int(len(samples)/2): :-1] =", samples[int(len(samples)/2): :-1])
print("samples[int(len(samples)*0.25): :-1] =", samples[int(len(samples)*0.25): :-1])
print("samples[ :int(len(samples)/2):-1] =", samples[ :int(len(samples)/2):-1])
print("samples[ :int(len(samples)*0.75):-1] =", samples[ :int(len(samples)*0.75):-1])
print()
print()

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

# Reversing all the audio
samples_out = samples[::-1]
print("The result of samples[::-1] will be played now")
input("Press Enter")
soundfile.play(samples_out)

# Reverse the first half of the audio
samples_out=samples[int(len(samples)/2): :-1]
print("The result of samples[int(len(samples)/2): :-1] will be played now")
input("Press Enter")
soundfile.play(samples_out) 

# Reverse the first 25% of the audio
samples_out=samples[int(len(samples)*.25): :-1]
print("The result of samples[int(len(samples)*.25): :-1] will be played now")
input("Press Enter")
soundfile.play(samples_out)

# Reverse the last half of the audio
samples_out=samples[ :int(len(samples)/2):-1]
print("The result of samples[ :int(len(samples)/2):-1] will be played now")
input("Press Enter")
soundfile.play(samples_out)

# Reverse the last 25% of the audio
samples_out=samples[ :int(len(samples)*.75):-1]
print("The result of samples[ :int(len(samples)*.75):-1] will be played now")
input("Press Enter")
soundfile.play(samples_out)
