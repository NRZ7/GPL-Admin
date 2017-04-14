// *****************************************************************************************
// * This script is licensed under the GNU Lesser GPL v3. Copyright © 2015 A3Wasteland.com *
// *****************************************************************************************
//	@file Version: 1.1
//	@file Name: init.sqf
//	@file Author: [404] Deadbeat, [GoT] JoSchaap, AgentRev
//	@file Created: 20/11/2012 05:19
//	@file Description: The server init.
//	@file Args:
// bAdmin Exile by Biabock

// All the "hasInterface" and "isServer" checks are to allow this file to be executed on a headless client to offload object saving

if (!isServer && hasInterface) exitWith {};

externalConfigFolder = "\bAdmin_settings";

if (isServer) then
{
	[] execVM "addons\admin\server\admins.sqf";
	[] execVM "addons\admin\server\broadcaster.sqf";
};

nr_fnc_daynight =
{
	if ((daytime > 8) && (daytime < 22)) then 
	{ 
		skipTime (22 - daytime + 24 ) % 24; 
	} else 
	{ 
		skipTime (8 - daytime + 24 ) % 24; 
	};
};

diag_log "Admin - Server Compile Finished";