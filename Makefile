TARGET := main
SOURCES := main.cpp Servo.cpp
CPPFLAGS := -DARDUINO_ARCH_AVR
BOARD := nano
include arduino.mk
