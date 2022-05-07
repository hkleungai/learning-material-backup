"""
This is the library for handling opening and playing of wav files.
You do not need to understand the code in this file.
"""

# import the required library
import wave     # for processing wav file
import os       # for removing a file
import array    # for converting between types of array

# save a wave file with filename "path",
# wav parameters "params" and wav samples "samples"
def save(path, params, samples):
    # create a new wav write object
    file = wave.open(path, 'wb')

    # set the wav parameters
    file.setparams(params)
    
    # write the all samples in string
    file.writeframes(samples.tobytes())

    # close the wav object
    file.close()

# read a wave file with 'filename'
def read(filename):
    global params

    # return nothing if the audio file does not exist
    if not os.path.exists(filename):
        return False
    
    # open a wav read object
    file = wave.open(filename, 'rb')
    
    # read the wav parameters
    params = file.getparams()
    
    # read the samples (in string) into a 1D array (in bytes)
    samples = array.array('h', file.readframes(file.getnframes()))
    
    return samples

# play an audio data from a 1D array
def play(samples):
    # create a temporary wav file
    tempname = "temp_result.wav"
    save(tempname, params, samples)

    # Now we play the temporary file
    from sys import platform
    
    # Here we check what platform you are using,
    # then we play the soundfile using the appropriate technique
    if platform.lower().startswith('win'): # Microsoft Windows is "win32" or maybe "windows"
        import winsound
        winsound.PlaySound(tempname, winsound.SND_FILENAME)
    elif platform.lower().startswith('dar'): # MacOS is "darwin"
        import subprocess
        subprocess.run( ['afplay', tempname] ) # All recent MacOs has the afplay program
    else: # Linux is "linux" or maybe "linux2"
        print("You are not using a Windows or a Mac system!")
        print("Maybe you are using a Linux system - ?")
        print("Unfortunately, I don't know how to reliably play sounds")
        print("on your system (without any extra Python installations).")
        print("So sorry about that! DR")
        
    # delete the temporary file
    os.remove(tempname)
