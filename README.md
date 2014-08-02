open-inertial-measurement-unit
==============================

This project is a [FreeIMU](http://www.varesano.net/projects/hardware/FreeIMU) fork.

Main objectives of this fork are:
* Build for Arduino Nano v3 with Arduino IDE 1.0.5
* Build for Stellaris Launchpad with Energia IDE 0101E0012 (03/18/2014)
* Build for Tiva C Launchpad with Energia IDE 0101E0012 (03/18/2014)
* Make calibration tool support Ubuntu 14.04
* Port to Beaglebone Black (experimental)
* Support GY-86 breakout board


Arduino Nano v3 and Arduino IDE 1.0.5
-------------------------------------

* Clone this repo
* rename to sketchbook in your home directory
* Connect GY-86 to Arduino Nano v3 i2c interface
* Install Arduino IDE with "apt-get install -y arduino"
* Open Arduino IDE 
* File->Examples->Free_IMU->FreeIMU_serial

Tiva C and Energia IDE 0101E0012
--------------------------------

* Clone this repo
* rename to sketchbook in your home directory
* Connect GY-86 to Stellaris or Tiva C Launchpad i2c interface 
* Install Energia IDE from http://energia.nu/downloads
* Open Energia IDE
* File->Examples->Free_IMU->FreeIMU_serial

Beaglebone Black port 
---------------------

* [Use lastest Debian image](http://beagleboard.org/latest-images/)
* Connect GY-86 to BBB i2c interface
* clone this repo
* make


Calibration tool
----------------

* sensors calibration is mandatory 
* connect Arduino/Tiva C/Stellaris/Beaglebone serial port to PC
* Install all required libraries
* apt-get install -y python-qt4 python-qt4-gl python-opengl pyqt4-dev-tools python-scipy
* wget http://www.pyqtgraph.org/downloads/python-pyqtgraph_0.9.8-1_all.deb
* dpkg -i python-pyqtgraph_0.9.8-1_all.deb
* Open FreeIMU_GUI 
* cd FreeIMU_GUI
* make run
* Youtube Demo

[![youtube demo](http://img.youtube.com/vi/rlGxA3Hqn4Q/0.jpg)](http://www.youtube.com/watch?v=rlGxA3Hqn4Q)

Processing testing and validation tool 
--------------------------------------

* board must be calibrated using FreeIMU_GUI before testing
* Download processing 2.2.1 
* wget http://download.processing.org/processing-2.2.1-windows32.zip
* wget http://download.processing.org/processing-2.2.1-windows64.zip
* wget http://download.processing.org/processing-2.2.1-linux64.tgz
* wget http://download.processing.org/processing-2.2.1-linux32.tgz
* wget http://download.processing.org/processing-2.2.1-macosx.zip
* Open Processing
* File->Sketchbook->proccessing->FreeIMU_cube
* Youtube Demo

[![youtube demo](http://img.youtube.com/vi/zizJOUMH_vE/0.jpg)](http://www.youtube.com/watch?v=zizJOUMH_vE)

Hardware project
----------------

* apt-get install -y kicad





