# Control 
This is a password manager created entirely in C. Heavily inspired by Suckless
project. 

## Installation
You can install this from github. I will skip that step. After you need to be 
in the control directory before the next step. 

Be sure that the Makefile is in the directory. You can find that out with this 
command.
```bash
ls -a
```
Once you know that you are in the right place you can follow the next command.
```bash
make #Will run the installation from the Makefile.
```
Which completes the installation process.


## Usage
```bash
./control #To create a database
```
If you have an existing database 
```bash
./control <FILENAME> #Will load the file
```
That should be everything to have it running

## TODO
- [ ] Load function needs to be able to hold many accounts.
- [ ] Need to add the insecure database
- [ ] Figure out how to salt passwords
- [ ] Consider adding if a .con exist in the directory it will find it itself.
