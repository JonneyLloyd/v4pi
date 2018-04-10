# V4Pi: A Framework To Leverage Video For Linux (V4L2) Performance On The Raspberry Pi

### Install Prerequisites
sudo apt-get install libopencv-dev libtesseract-dev git cmake build-essential libleptonica-dev

sudo apt-get install liblog4cplus-dev libcurl3-dev

git clone https://github.com/openalpr/openalpr.git

Setup the build directory on the Raspberry Pi:

* cd openalpr/src

* mkdir build

* cd build

Then setup the compile environment:

- cmake -DCMAKE\textunderscore INSTALL\textunderscore PREFIX:PATH=\\
		/usr -DCMAKE\textunderscore INSTALL\textunderscore SYSCONFDIR:PATH=/etc ..

Compile the library:

* make

Install the binaries/libraries to your local system (prefix is /usr):

* sudo make install\\

Finally test the library with an image containing a licence plate:

* wget http://plates.openalpr.com/h786poj.jpg -O lp.jpg

* alpr lp.jpg\\


### Setup project 

* git clone git@gitlab.com:JonneyLloyd/FYP.git

* cd FYP/

* cmake .

* make

* ./ fyp

This will build the demo_day.cpp file which contains every component of the framework in use. Note: you will need to insert your own Sighthound API token into the 'key' string in the sighthound function. See https://www.sighthound.com/ for details. This will only effect sighthound functionality i.e. Vehicle make/model recognition.
