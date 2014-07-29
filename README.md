FreeIMU
=======
http://www.varesano.net/projects/hardware/FreeIMU

FreeIMU is an ongoing research project which aims to design Open Hardware 9/10 DOM/DOF Inertial Measurement Units as well as easy to use Orientation and Motion Sensing libraries, built on top of the Arduino platform.

The goal of the FreeIMU Framework is to simplify the development of projects based upon the most powerful and new consumer grade inertial, magnetic and pressure sensors.

The main application of FreeIMU is orientation sensing: by reading the data from the various sensors is possible to compute precisely the orientation of FreeIMU in the space. Recent boards also feature an high resolution barometer allowing to precisely track the device altitude. This can be useful in many applications: human-computer interaction device prototyping, flying machines, robots, human movement tracking and everywhere orientation sensing is a key aspect.

As FreeIMU breakout the sensors interrupt pins, it's also possible to detect per axis single and double taps, free fall as well as activity or inactivity. This makes FreeIMU a very good choice for Human-Computer devices prototyping. Interrupts pins are also very useful if you are into interrupt based reading of the sensors, useful to develop high frequency interrupt based sensor reading.



FreeIMU_GUI required packages (Ubuntu 14.04)
--------------------------------------------

apt-get install -y python-qt4 python-qt4-gl python-opengl pyqt4-dev-tools python-scipy

wget http://www.pyqtgraph.org/downloads/python-pyqtgraph_0.9.8-1_all.deb

dpkg -i python-pyqtgraph_0.9.8-1_all.deb


Processing demos - 3D Cube
--------------------------

Download processing 2.2.1 

http://download.processing.org/processing-2.2.1-windows32.zip

http://download.processing.org/processing-2.2.1-windows64.zip

http://download.processing.org/processing-2.2.1-linux64.tgz

http://download.processing.org/processing-2.2.1-linux32.tgz

http://download.processing.org/processing-2.2.1-macosx.zip




