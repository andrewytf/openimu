open-inertial-measurement-unit
==============================

This project is a [FreeIMU](http://www.varesano.net/projects/hardware/FreeIMU) fork.

Main objectives of this fork are:
* Build for Arduino Nano v3 with Arduino IDE 1.0.5
* Build for Stellaris Launchpad with Energia IDE
* Build for Tiva C Launchpad with Energia IDE
* Make calibration tool support Ubuntu 14.04
* Port to Beaglebone Black


Arduino Firmware (version 1.0.x)
--------------------------------

apt-get install -y arduino


FreeIMU_GUI required packages (Ubuntu 14.04)
--------------------------------------------
Required calibration tool

apt-get install -y python-qt4 python-qt4-gl python-opengl pyqt4-dev-tools python-scipy

wget http://www.pyqtgraph.org/downloads/python-pyqtgraph_0.9.8-1_all.deb

dpkg -i python-pyqtgraph_0.9.8-1_all.deb


Debug with OpenGL 3D Cube
--------------------------
Required test and validation tool

Download processing 2.2.1 

http://download.processing.org/processing-2.2.1-windows32.zip

http://download.processing.org/processing-2.2.1-windows64.zip

http://download.processing.org/processing-2.2.1-linux64.tgz

http://download.processing.org/processing-2.2.1-linux32.tgz

http://download.processing.org/processing-2.2.1-macosx.zip

Hardware project
----------------

apt-get install -y kicad





