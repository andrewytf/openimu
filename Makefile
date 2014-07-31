CFLAGS=-c -Wall -std=c++0x -I./libraries/FreeIMU -I./libraries/MS561101BA -I./libraries/HMC58X3 -I./libraries/bma180 -I./libraries/MPU60X0 -I./libraries/adxl345driver -I./libraries/itg3200filv05 -I./libraries/I2Cdev -I./libraries/bmp085driver -I./arduino_compat -I./libraries/DebugUtils -o freeimu-serial
SOURCES=./arduino_compat/Arduino.cpp ./arduino_compat/freeimu-serial.cpp ./libraries/bmp085driver/BMP085.cpp ./libraries/I2Cdev/I2Cdev.cpp ./libraries/itg3200filv05/ITG3200.cpp ./libraries/adxl345driver/ADXL345.cpp ./libraries/MPU60X0/MPU60X0.cpp ./libraries/bma180/bma180.cpp ./libraries/HMC58X3/HMC58X3.cpp ./libraries/MS561101BA/MS561101BA.cpp ./libraries/FreeIMU/FreeIMU.cpp ./libraries/FreeIMU/CommunicationUtils.cpp 
CC=g++
LDFLAGS=
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=freeimu-bbb-test

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -v $(OBJECTS) $(EXECUTABLE)
