// *****************************************************************************************
// * This script is licensed under the GNU Affero GPL v3. Copyright © 2015 A3Wasteland.com *
// *****************************************************************************************
//@file Version: 1.1
//@file Name: init.sqf
//@file Author: [404] Deadbeat, [GoT] JoSchaap, AgentRev, [KoS] Bewilderbeest
//@file Created: 20/11/2012 05:19
//@file Description: The client init.

//if (isDedicated) exitWith {};

[] execVM "addons\admin\client\checkBan.sqf";
[] execVM "addons\admin\client\camera\functions.sqf";

isAdmin = "addons\admin\client\systems\adminPanel\isAdmin.sqf" call mf_compile;//

[] execVM "addons\admin\client\functions\compileClientFuncs.sqf";

////////////// Defining variables (for admins)
cba_index = -1;
cba_prevStatements = [];
////////////// End of variables

diag_log "GPL Admin - Client Compile Complete";

waitUntil {!isNull findDisplay 46 && getPlayerUID player != ''}; 

_UID = getPlayerUID player;
if (_UID call isAdmin) then
{
	[] spawn {
		while{true} do {
			waitUntil{inputAction "user20" > 0};
			execVM "addons\admin\client\systems\adminPanel\checkPlayerMenu.sqf";
			waitUntil{inputAction "user20" == 0};
		};
	};
	[] spawn {
		while{true} do {
			waitUntil{inputAction "user19" > 0};
			execVM "addons\admin\client\systems\adminPanel\checkdebugMenu.sqf";
			waitUntil{inputAction "user19" == 0};
		};
	};
	[] spawn {
		while{true} do {
			waitUntil{inputAction "user18" > 0};
			execVM "addons\admin\client\systems\adminPanel\checkdebugConsole.sqf";
			waitUntil{inputAction "user18" == 0};
		};
	};
};