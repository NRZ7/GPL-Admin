//	@file Name: GPLAdmin_settings\admins.sqf

// Admin menu (6 key) access levels

/*******************************************************
 Player UID examples :
	"1234567887654321", // Meatwad
	"8765432112345678", // Master Shake
	"1234876543211234", // Frylock
	"1337133713371337"  // Carl
 Important: The player UID must always be placed between
            double quotes (") and all lines need to have
            a comma (,) except the last one.
********************************************************/

gpl_CommandPassword = "mySecretPassword";

// Low Administrators: manage & spectate players, remove hacked vehicles
lowAdmins = 
[
	// Put player UIDs here
];

// High Administrators: manage & spectate players, remove hacked vehicles, show player tags
highAdmins = 
[
	// Put player UIDs here
];

// Server Owners: access to everything, including god mode, money, guns, and vehicles
serverOwners = 
[
	// Put player UIDs here
];

///////////////////////////////////////////////////////////////////////////////
/*																			 */
/* BANLIST is an emergency tool. Please, use Arma3Server\bans.txt instead	 */
/*																			 */
///////////////////////////////////////////////////////////////////////////////

banList = // These users can't acces to game.
[
	// Put player UIDs here
];