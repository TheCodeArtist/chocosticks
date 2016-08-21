#1. Introduction

This page will take you through the steps to download, setup and run chocosticks on Windows.

If you want to obtain code and build your own version of chocosticks, steps can be found here.

*[ TODO: Link building chocosticks link. ]*

#2. Running Natively on windows

*Note1: This section explains running chocosticks on DOS/Windows95/98/ME/2000/XP. chocosticks is built using TurboC 3.0 which is a 16-bit compiler. The above systems allow 16-bit binaries to be executed natively.*

*Note2: If you are running Windows-Vista/Win7/Win8/Win10 then refer Section 3 - [Running chocosticks in Dosbox emulator on Windows](https://github.com/TheCodeArtist/chocosticks/blob/master/Documentation/running-chocosticks.md#3-running-chocosticks-in-dosbox-emulator-on-windows)* below.

###2.1. Download the archive [choco.zip](https://github.com/TheCodeArtist/chocosticks/raw/master/Misc/choco.zip?raw=true)

###2.2. Extract the archive at some place on your PC.

###2.3. It will create a "choco" directory containing :

    GAME.exe The chocosticks binary.  
    BGI The Borland Graphics Interface libraries.

###2.4. Run the executable GAME.exe and enjoy! ;-)

Note: When run, the executable looks for the `BGI` directory in the current directory. If any file is missing from the `BGI` directory or the `BGI` directory does NOT exist in the current directory, then `GAME.exe` will exit with the following message:

    BGI ERROR: Graphics not initialized (use 'initgraph')

#3. Running chocosticks in Dosbox emulator on windows

###3.1. Download and run the Dosbox installer.

###3.2. Download the archive choco.zip

###3.3. Extract the archive at some place on your PC. (say d:\choco)

###3.4. Now launch Dosbox.

![Launching Dosbox](../Misc/1.dosbox-launch.png?raw=true)

###3.5. Type the following command

    mount x: d:/choco

where "d:/choco" is the path to the extracted choco.zip

![Mounting Dosbox](../Misc/2.dosbox-mounting.png?raw=true)

###3.6. Next type the following commands

    x:
    game.exe

![Dosbox mounted](../Misc/3.dosbox-mounted.png?raw=true)

This will launch chocosticks in Dosbox. Enjoy! ;-)

![chocosticks homescreen](../Misc/4.chocosticks-homescreen.png?raw=true)

By default, Dosbox emulator may run at 3,000cycles(3Khz).  
Configuring it to atleast 40,000cycles is recommended to run chocosticks as intended.  
*CTRL+F12 increases the emulator's virtual-CPU speed by one step.*  
*CTRL+F11 reduces the emulator's virtual-CPU speed by one step.*
