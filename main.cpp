#include <iostream> //for std::cout
#include <iomanip> //for setw()
#include <fstream> //for the files (if we use them)
#define cls system("clear");
#define choose(c) if (choice == c)
using namespace std; //bc im too lazy for std::cout
int showmenu(void); //display the main menu
int setupdevice(void); //function prototype to set device generation
void loadibec(int); //loads openiboot.img3 to the device
void instructions(void); //displays the instruction menu
void oibc(int); //opens an oibc developer console
void showcredits(void); //displays the credits
bool supported(int); // returns true if device is supported, false if not
int main(int argc,char**argv) //we need to have this....
{
  int device = -1, choice;
  bool supported;
  while (true)
  {
	do
	{
		cls
		choice = showmenu(); //display the main menu and return the selection
	} while (choice == -1);
		choose(1)
		{
			do
			{
				cls
  				device = setupdevice(); //allow user to change the device
			} while (device == -1);
		}
		choose(2)
		{
  			loadibec(device); //load openiboot.img3 to the device
		}
		choose(3)
		{
			cls
  			instructions(); //display the install instructions
  			oibc(device); //start a console
		}
		choose(4)
			showcredits();
		choose(5)
			exit(EXIT_SUCCESS);
  }
}
int showmenu(void)
{
  cout << "####################################################################" << endl;
  cout << "#####iLoader v3 Copyright (C) 2012 phyrrus9 <phyrrus9@gmail.com>####" << endl;
  cout << "####################################################################" << endl;
  cout << "#please select an option from the list below ...                   #" << endl;
  cout << "#1. Set device generation: REQUIRED for ALL flashes                #" << endl;
  cout << "#2. Load the standard OiB img3 into flash memory and jump to it    #" << endl;
  cout << "#3. Display install instructions, then launch the OIBC console ... #" << endl;
  cout << "#4. Credits and special thank-yous from the developer :)           #" << endl;
  cout << "#5. Exit iLoader v3 ... Please don't ... ;(                        #" << endl;
  cout << "####################################################################" << endl;
  cout << "%";
  int input; //define a new input
  cin >> input; //get the input number
  if (input < 1 || input > 5) // you best aint be cheatin
	return -1; //so the main function can redisplay this window
  else //if everything is good
	return input; //thats good
  //just in case nothing works
  return -1; //something went wrong
}
int setupdevice(void)
{
  cout << "####################################################################" << endl;
  cout << "#####iLoader v3 Copyright (C) 2012 phyrrus9 <phyrrus9@gmail.com>####" << endl;
  cout << "####################################################################" << endl;
  cout << "#please select your device from the lise below ...                 #" << endl;
  cout << "#1. iPhone (original... not the iphone 2g, the original iphone).   #" << endl;
  cout << "#2. iPhone 2G (i hate all of you who call it the iPhone 3G         #" << endl;
  cout << "#3. iPhone 3G[S] (either bootrom)                                  #" << endl;
  cout << "#4. iPhone 4 (AT&T prefered, though Verizon is okay as well)       #" << endl;
  cout << "#0. iPhone 4[S] (dont even bother...)                              #" << endl;
  cout << "#5. iPod Touch (the original, MA bootrom, all that jazz...)        #" << endl;
  cout << "#6. iPod Touch 2G (MB BOOTROM ONLY!!!!!) do not ask for the MC     #" << endl;
  cout << "#0. iPod Touch 3G (was never even worked on to begin with) sorry   #" << endl;
  cout << "#7. iPod Touch 4G (Black or white, it dosn't matter....)           #" << endl;
  cout << "#0. iPad *all* (none of them have been tested, watch for updates)  #" << endl;
  cout << "####################################################################" << endl;
  cout << "%";
    int input; //define a new input
  cin >> input; //get the input number
  if (input < 1 || input > 7) // you best aint be cheatin
	return -1; //so the main function can redisplay this window
  else //if everything is good
	return input; //thats good
  //just in case nothing works
  return -1; //something went wrong
}
void loadibec(int device)
{
  if (!supported(device)) //bad device or unsupported, cross referenced by list
    return;
  char buffer[10];
  string img3_path = "/usr/share/iloader/openiboot_";
  img3_path += device + ".img3"; //set up the path
  string loadibec_path = "/usr/share/iloader/loadibec "; //set up the binary path
  string command = loadibec_path;
  command += img3_path; //make the command
  system(command.c_str()); //run it (flashes the image to the memory of the device and jumps to it)
}
void instructions(void)
{
  cout << "####################################################################" << endl;
  cout << "#####iLoader v3 Copyright (C) 2012 phyrrus9 <phyrrus9@gmail.com>####" << endl;
  cout << "####################################################################" << endl;
  cout << "#This will open a console in exactly ten seconds, on the following #" << endl;
  cout << "# devices, you must type \"install\" and hit enter. This command is#" << endl;
  cout << "# the OpeniBoot installer, using the image currently in memory and #" << endl;
  cout << "# writes it to the NOR (permanent). PROCEED WITH CAUTION! This CAN #" << endl;
  cout << "# brick your device. This tool is not responsible for any damage   #" << endl;
  cout << "# caused to your device. Though we appreciate you using it ... :)  #" << endl;
  cout << "#iPhone, iPhone 2G, iPod Touch 1G, the other installers are off.   #" << endl;
  cout << "####################################################################" << endl;
  system("sleep 10"); //wait exactly ten seconds
}
void oibc(int device)
{
  string oibc_path = "/usr/share/iloader/oibc "; //set up path to oibc (iphone, iphone 2g, ipod touch)
  string oibc_beta_path = "/usr/share/iloader/oibc2 "; //set up path to oibc_beta (everything else)
  if (device < 3 || device == 5)
    system(oibc_path.c_str()); //run oibc
  else
    system(oibc_beta_path.c_str()); //run oibc_beta
}
bool supported(int device)
{
 return true;
}
void showcredits(void)
{
  cout << "####################################################################" << endl;
  cout << "#####iLoader v3 Copyright (C) 2012 phyrrus9 <phyrrus9@gmail.com>####" << endl;
  cout << "####################################################################" << endl;
  cout << "#iLoader is copyright (c) 2012 phyrrus9 <phyrrus9@gmail.com> fully #" << endl;
  cout << "#special thanks to the following people and their works            #" << endl;
  cout << "#The iDroid team : OpeniBoot and iDroid projects                   #" << endl;
  cout << "#Jaywalker : OpeniBoot flash for iPod Touch 2G                     #" << endl;
  cout << "#Anybody whom I may have forgotten (sorry im swamped with projects)#" << endl;
  cout << "####################################################################" << endl;
  system("pause"); //windows test
  system("sleep 5");
}