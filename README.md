open-inertial-measurement-unit
==============================

This project is a [FreeIMU](http://www.varesano.net/projects/hardware/FreeIMU) fork.

Main objectives of this fork are:
* Build for Arduino Nano v3 with Arduino IDE 1.0.5
* Build for Stellaris Launchpad with Energia IDE 0101E0012 (03/18/2014)
* Build for Tiva C Launchpad with Energia IDE 0101E0012 (03/18/2014)
* Make calibration tool support Ubuntu 14.04
* Support GY-86 breakout board
* Port to Beaglebone Black (experimental)
* Port to STM32F103 with [MBED](https://mbed.org/platforms/ST-Nucleo-F103RB/)
* Port to FRDM-KL25Z with [MBED](https://mbed.org/handbook/mbed-FRDM-KL25Z)

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


Windows Dev setup
-----------------

#python

https://www.python.org/ftp/python/2.7.8/python-2.7.8.amd64.msi

#numpy

http://www.lfd.uci.edu/~gohlke/pythonlibs/wyxyx8e9/numpy-MKL-1.9.1.win-amd64-py2.7.exe

#scipy

http://www.lfd.uci.edu/~gohlke/pythonlibs/wyxyx8e9/scipy-0.14.0.win-amd64-py2.7.exe

#pyqt4

http://ufpr.dl.sourceforge.net/project/pyqt/PyQt4/PyQt-4.11.3/PyQt4-4.11.3-gpl-Py2.7-Qt4.8.6-x64.exe

#pyqtgraph

http://www.pyqtgraph.org/downloads/pyqtgraph-0.9.8.win-amd64.exe

#pyopengl

https://pypi.python.org/packages/any/P/PyOpenGL/PyOpenGL-3.0.2.win-amd64.exe#md5=b02e6a5e7b547e0968c34a2a43de7da1

#pyserial

http://www.lfd.uci.edu/~gohlke/pythonlibs/wyxyx8e9/pyserial-2.7.win-amd64-py2.7.exe




