![Alt Text](header.jpg)
Date: 02-01-2022
# Sea-Border-Alert-System-For-FisherMen-using-RSSI-AND-GPS
We have been hearing about fishermen being seized by custody from other end and even killed. This is purely because of unawareness and unable to identify sea border between countries. So, we have initiated a systems using Global Positioning System (GPS) and Received Signal Strength Indicator (RSSI) to notify and resist the fishermen crossing the border. We use Global Positioning System to get the current location (latitude and longitude) of fishermen’s boat and Received Signal Strength Indicator to know the strength of the signal, followed further measures. This paper in brief states about various methods of tracking and resisting the fishermen on crossing the border. Navigation in the seawater areas is considered to be important aspect worn by any fishermen who goes for hunting. Basically, the tracking system is designed to make use of electronic device and a software installed in a system to track the current latitude and longitude measures and also detecting signal strength using Wi-Fi ports in the marine borders. 

Now-a-days, Global positioning system has been widely used in market to detect the current or another location and Received signal strength has been populated much well than before as the telecommunication driving through it. These two distinct methods would be a safe tool in terms of navigation. Eventually, our paper makes a comparative analysis on both methods in the fishermen border alert system and gives detailed description of working procedure



| AUTHORS          | EMAIL                                                                |
| ----------------- | ------------------------------------------------------------------ |
| Indra D  | indra.d2018@vitstudent.ac.in |
| Dutta Yasaswi | dutta.yasaswi2018@vitstudent.ac.in |
| Swathi J | swathi.j2018@vitstudent.ac.in |
| Unnikrishnan Rajesh | unnikrishnan.rajesh2018@vitstudent.ac.in |


## Project Setup Instructions
- Unzip the files
- Upload the code into ArduinoUno
- Follow the Connection
- Enable the wifi  hotspot, and Power On the System 
- Open the ip address in web browser displayed in the LCD
- Take the device away from the system to view the Safe zone,Moderate zone,Danger Zone.
- Open the Adafruit.io website to see the location (Latitude and Longitude)

# Sea-border-alert-system

we are creating 2 border alert system models here in our project. Its basically an IOT based project. one model is done using gps nad teh other model is done using RSSI.

Project Demo : https://drive.google.com/file/d/10O_rIqCxXwRd9tMJqDJF_T9wZZq5vYqj/view?usp=sharing

## 🔗 Links
[![portfolio](https://img.shields.io/badge/my_portfolio-000?style=for-the-badge&logo=ko-fi&logoColor=white)](https://drive.google.com/file/d/10O_rIqCxXwRd9tMJqDJF_T9wZZq5vYqj/view?usp=sharing)


########################################################

1st sea border alert system using gps module

#######################################################

##components required:

*Arduino uno

*buzzer

*12v DC motor

*16 x 2 LCD Display

*Gps Module

*Bread Board

*adaptor

*Jumperires for connecting the components.

## Steps to follow.
* so this arduino uno is a microcontroller which acts and a sandwich between the hardware and the software components.

* take a jumper wire and connect 5v power supply from arduino to bread board, now take another jumper and connect the ground terminal of arduino uno to breadboard again.

* we are doing this step, as we need power supply port and ground port for multiple components.

* refer the gps_module_connection.png image to connect the hardware part.

* once that connection is done, install arduino ide software and connect your arduino board 
with your Laptop[using USB AB cable] where you have installed the arduino ide software. 

* In arduino ide software go to ->tools ->board and make sure your arduino board is connected to teh software.

* copy paste the "sea border alert system using_gps_module" code in the software and upload the code to your arduino uno board[using USB AB cable].

Note:
I have used different border values according to my location, so kindly change the stored border values, according to your location and execute.


#######################################################





