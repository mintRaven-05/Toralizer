<h1 align=center> TORALIZER </h1>


## Purpose

Take control of your digital footprint. This tool operates behind the scenes,  rerouting your socket connections through the Tor network and thus masking you IP. Your IP address remains hidden, whether you're using curl, SSH, or any tool reliant on socket connections. It hijacks the default socket connect function and replaces it temporarily with my custom connect() function. The custom connect function is valid till the end of the session of the tool that is using the function. You will understand it all after reading the whole document.

 >[!IMPORTANT]
 >This tool is only supported by Linux-based OS and is not made for Windows users. This project is still under development and undergoing heavy modifications. You can put this project to watch list if you wish to use this.
 >
 >Prerequisites
 > - Tor must be installed in your system before installing this tool
 > - You may take help from any youtube video, as per your preference
 > - The port number configured for the SOCKS connection in the Tor configuration file must be **9050**
 > - The link below is the best guide i could find over YouTube, you can follow this to setup your tor network
 > - https://www.youtube.com/watch?v=KTfWu0GFKTc&t=653s
 
 >[!CAUTION]
 >I am not responsible for any kind of damage caused by this tool to you or to anyone else. Use this at your own risk.

## Installation

Copy this repository

```bash
git clone https://github.com/mintRaven-05/Toralizer.git
```

Run the `install.sh` script to install the tool.

```bash
cd Toralizer
chmod +x install.sh
./install.sh
```

and this will add Toralizer to `/usr/bin` path and install essential dependencies.

## Update

Inside the `~/.toralizer` folder, an update script is present with the name `update.sh`
Run that script to update Toralizer.
```bash
sudo ./update.sh
```

## Usage
>[!NOTE]
>This tool is slow, because of the fact it is using tor servers. Also it works the best with SSH. 
>I would avoid using curl with it, since it often prompts for a verification from middle man like Cloud flare, and we can do nothing about those verification pages except for grabbing a piece of HTML code it provides 

This is an example usage. If you have `ssh` setup for GitHub, then you can use the example mentioned below. Similarly any tool that uses socket connect function can be hijacked using Toralizer to reroute connections via tor network circuit. 

```bash
toralize ssh -T git@github.com
```

If you don't have `ssh` setup for you GitHub account, then in that case you can try the following.

```bash
toralize curl mittip.se 
```

you can use the same command without Toralizer and see the difference for yourself. 
## Demo Screenshot
![240724_16h11m34s_screenshot](https://github.com/user-attachments/assets/bbaa6412-f6ce-4bcf-b360-9a37dca8bfa6)


## Uninstallation

Once installed it make a copy of the repository in the home directory inside a hidden folder. The folder is named `.toralizer`. Now you need to navigate into that folder and run the uninstaller. Execute the following commands

```bash
cd ~/.toralizer
./uninstall.sh
```

<p align="center">Copyright &copy; 2024 <a href="https://github.com/mintRaven-05" target="_blank">Debjeet Banerjee</a>
<p align="center"><a href="https://github.com/mintRaven-05/Toralizer/blob/main/LICENSE"><img src="https://img.shields.io/static/v1.svg?style=for-the-badge&label=License&message=MIT&logoColor=d9e0ee&colorA=363a4f&colorB=b7bdf8"/></a></p>
