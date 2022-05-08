import sounds

class drumset:
  def __init__(self, sound, x=0, y=0, z=0, radius=5):
    self.x = x
    self.y = y
    self.z = z
    self.radius = radius
    
  def play_sound():
    pass # Play sound somehow    
  
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
