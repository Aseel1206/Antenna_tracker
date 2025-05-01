# Arduino Antenna Tracker

This project uses pymavlink to get gps data from drone and calculate azimuth for antenna direction. Arduino is connected to two servos: pan and titl servo.
Always start with nort facing.

pan servo: 

  90 - north
  0 - east
  180 - west
  90 (180 tilt servo) - south

titl servo:

  0 - forward (north)
  90 - perpendicular
  180 - backward (south)
