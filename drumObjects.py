import sounds
import pyaudio  
import wave  

class drumset:
  def __init__(self, sound, x=0, y=0, z=0, radius=5):
    self.x = x
    self.y = y
    self.z = z
    self.radius = radius
    
  def play_sound(soundFile):
    #define stream chunk   
    chunk = 1024  

    #open a wav format music  
    f = wave.open(soundFile,"rb")  
    #instantiate PyAudio  
    p = pyaudio.PyAudio()  
    #open stream  
    stream = p.open(format = p.get_format_from_width(f.getsampwidth()),  
                    channels = f.getnchannels(),  
                    rate = f.getframerate(),  
                    output = True)  
    #read data  
    data = f.readframes(chunk)  

    #play stream  
    while data:  
        stream.write(data)  
        data = f.readframes(chunk)  

    #stop stream  
    stream.stop_stream()  
    stream.close()  

    #close PyAudio  
    p.terminate()  
    
class snare(drumset):
  def __init__(self, sound, x=0, y=0, z=0, radius=5):
    self.x = x
    self.y = y
    self.z = z
    self.radius = radius
    self.sound = sound

class hi_tom(drumset):
  def __init__(self, sound, x=0, y=0, z=0, radius=5):
    self.x = x
    self.y = y
    self.z = z
    self.radius = radius
    self.sound = sound
    
class med_tom(drumset):
  def __init__(self, sound, x=0, y=0, z=0, radius=5):
    self.x = x
    self.y = y
    self.z = z
    self.radius = radius
    self.sound = sound

class floor_tom(drumset):
  def __init__(self, sound, x=0, y=0, z=0, radius=5):
    self.x = x
    self.y = y
    self.z = z
    self.radius = radius
    self.sound = sound

class crash_cymbal(drumset):
  def __init__(self, sound, x=0, y=0, z=0, radius=5):
    self.x = x
    self.y = y
    self.z = z
    self.radius = radius
    self.sound = sound

class ride_cymbal(drumset):
  def __init__(self, sound, x=0, y=0, z=0, radius=5):
    self.x = x
    self.y = y
    self.z = z
    self.radius = radius
    self.sound = sound
