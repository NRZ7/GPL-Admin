// *****************************************************************************************
// * This script is licensed under the GNU Affero GPL v3. Copyright © 2015 A3Wasteland.com *
// *****************************************************************************************
//	@file Name: server\admins.sqf

if (!isServer) exitWith {};

if (loadFile (externalConfigFolder + "\admins.sqf") != "") then
{
	call compile preprocessFileLineNumbers (externalConfigFolder + "\admins.sqf");
	diag_log "GPL Admin - External admins.sqf loaded";
}
else
{
	// Admin menu (U key) access levels

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

	
	// Low Administrators: manage & spectate players, remove hacked vehicles
	lowAdmins = compileFinal str
	[
		// Put player UIDs here
	];

	// High Administrators: manage & spectate players, remove hacked vehicles, show player tags
	highAdmins = compileFinal str
	[
		// Put player UIDs here
	];

	// Server Owners: access to everything, including god mode, money, guns, and vehicles
	serverOwners = compileFinal str
	[
		// Put player UIDs here
	];
	
	zeusAdmins = 
		[
			// Put player UIDs here
			"76561198086857419"
		];
	
	banList = // These users can't acces to game.
	[
		// Put player UIDs here
	];

	/********************************************************/
	diag_log "GPL Admin - ERROR! \GPLAdmin_settings\admins.sqf not found!";
	diag_log "GPL Admin - This folder must be in the server directory";
};

if (typeName lowAdmins == "ARRAY") then { lowAdmins = compileFinal str lowAdmins };
if (typeName highAdmins == "ARRAY") then { highAdmins = compileFinal str highAdmins };
if (typeName serverOwners == "ARRAY") then { serverOwners = compileFinal str serverOwners };
if (typeName zeusAdmins == "ARRAY") then { zeusAdmins = compileFinal str zeusAdmins };

publicVariable "lowAdmins";
publicVariable "highAdmins";
publicVariable "serverOwners";
publicVariable "zeusAdmins";
publicVariable "banList";

_zeusAdminList =  call zeusAdmins;
	
	    // Create Zeus Module if zeusAdmins are defined
	if (count _zeusAdminList > 0 && isNil "aj_var_centerSideLogic_Zeus") then
		{
		aj_var_centerSideLogic_Zeus = createCenter sideLogic; publicVariable "aj_var_centerSideLogic_Zeus";  //Create game side for Zeus
		aj_var_groupSideLogic_Zeus = createGroup aj_var_centerSideLogic_Zeus; publicVariable "aj_var_groupSideLogic_Zeus";  //Create group for Zeus
			
			//now create the curators for all zeusAdmins
		   {       
		   Call Compile Format ["aj_var_modulezeus%1 = aj_var_groupSideLogic_Zeus createUnit ['ModuleCurator_F',[0,0,0] , [], 0, ''];",_x];
		   Call Compile Format ["aj_var_moduleZeus%1 setVariable ['showNotification', false, true];",_x];
		   Call Compile Format ["aj_var_moduleZeus%1 setVariable ['birdType', '', true];",_x];
		   Call Compile Format ["aj_var_moduleZeus%1 setVariable ['Owner', '%1', true];",_x];
		   Call Compile Format ["aj_var_moduleZeus%1 setVariable ['Addons', 3, true];",_x];
		   Call Compile Format ["aj_var_moduleZeus%1 setVariable ['Forced', 0, true];",_x];
		   Call Compile Format ["publicVariable 'aj_var_moduleZeus%1'; ",_x];
		   }
		   forEach _zeusAdminList;
		};	