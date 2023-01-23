# Arduino + Python -> Holodeck

Code for Max Fonseca's project
To use this project you need to install few libraries for Arduino and Python.
## Arduino Libraries
The first library that you need to install is '''Picovoice_EN.h'''.
To create it you need to go to [Picovoice](https://picovoice.ai/) create an account and train a Wake word and some commands.

The second library that you need to install is '''Arduino_APDS9960.h'''.

## Python Installing
*[Credits to PackeTsar](https://github.com/PackeTsar/Install-Python/blob/master/README.md)*
### Option 1: Install the official Python release
1. Browse to the [Python Downloads Page](https://www.python.org/downloads/)
2. Click on the "Download Python 3.x.x" button on the page
3. Walk through the steps of the installer wizard to install Python3
4. Once installed, the wizard will open a Finder window with some `.command` files in it
    - Double-click the `Install Certificates.command` file and the `Update Shell Profile.command` file to run each of them
    - Close the windows once they are finished
6. Open your **Terminal** application and run the command `python3` to enter the Python interactive command line. Issue the command `quit()` to exit. Also make sure PIP (the Python package manager) is installed by issuing the command `pip3 -V`. It should display the current version of PIP as well as Python (which should be some release of Python3).
7. You're all done. Python is installed and ready to use.

### Option 2: Install with Homebrew
[Homebrew](https://brew.sh/) is a MacOS Linux-like package manager. Walk through the below steps to install Homebrew and an updated Python interpreter along with it.

1. Open your **Terminal** application and run: `xcode-select --install`. This will open a window. Click **'Get Xcode'** and install it from the app store.
2. Install Homebrew. Run: `/bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"`
   - You can also find this command on the [Homebrew website](https://brew.sh/)
3. Install latest Python3 with `brew install python`
4. Once Python is installed, you should be able to open your **Terminal** application, type `python3`, hit ENTER, and see a Python 3.X.X prompt opened. Type `quit()` to exit it. You should also be able to run the command `pip3` and see its options. If both of these work, then you are ready to go.
  - Here are some additional resources on [Installing Python 3 on Mac OS X](https://docs.python-guide.org/starting/install3/osx/)

## Python Libraries
The first library that you will need is '''pyautogui''' that you can find it [here](https://pypi.org/project/PyAutoGUI/).
The first library that you will need is '''serial''' that you can find it [here](https://pypi.org/project/pyserial/).
