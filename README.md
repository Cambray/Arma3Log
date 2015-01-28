## Arma3Log

I got bored waiting for other people to develop it so i wrote my own.
This is an external logging extension for arma 3 servers, written in c++ only. 


#### Known Servers using Arma3Log
- [GER] Zero-One [01] http://zero-one.cc/
- [GER] Altislife-Germany [ALG] http://www.altislife-germany.de/


### Features

- Fast and simple logging
- Log roation automatism
- Log information is splittet into diffrent logs if you want 


### Installation

1. Download the latest realse from https://github.com/Arkensor/Arma3Log/releases
2. Copy the @Arma3Log in the root/main directory of your server. The directory where the arma3server.exe is in.
3. Go into your mission and open the initServer.sqf and paste this into it: [] call compile PreprocessFileLineNumbers "\@Arma3Log\init.sqf";
4. Done


### Usage

For TAWTonic's Altis-Life:

Call the Log via this function: [[0:Text],"Arma3Log",false,false] spawn life_fnc_MP;

Default Arma 3 Missions:

Call the Log via this function: [[0:Text],"Arma3Log",false,false] spawn BIS_fnc_MP;

Explanation:

1. ..[0:Text].. = The numer decides in which log the information should go, if it can not finde the numer, the logger will put it into a deafult case 0. The text is about what should go into the log.
2. The other stuff calls the information and sends it to the serverside loaded extenstion, which calls the dll.


#### Thanks to

- killzonekid for his blog http://killzonekid.com/ and discription how to make a dll for Arma 3
- IamSorry for helping me with some c++ code
 
