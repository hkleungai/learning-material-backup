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
print("samples[ : :2] =", samples[ : :2])
print("samples[ : :3] =", samples[ : :3])
print("samples[ : :4] =", samples[ : :4])
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

# Access every second sample of the audio.
# If you listen to the result, it will be twice as fast.
samples_out=samples[ : :2]
print("The result of samples[ : :2] will be played now")
input("Press Enter")
soundfile.play(samples_out)

# Access every third sample of the audio.
# It will be even faster than the previous example.
samples_out=samples[ : :3]
print("The result of samples[ : :3] will be played now")                     
input("Press Enter")
soundfile.play(samples_out)

# Access every fourth sample of the audio.
# It will be even faster than the previous example.
samples_out=samples[ : :4]
print("The result of samples[ : :4] will be played now")
input("Press Enter")
soundfile.play(samples_out)
