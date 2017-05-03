// *****************************************************************************************
// * This script is licensed under the GNU Affero GPL v3. Copyright © 2017 				   *
// *****************************************************************************************
//	@file Version: 1.1
//	@file Name: checkPlayerMenu.sqf
//	@file Author: [404] Deadbeat, AgentRev, NRZ7
//	@file Created: 20/11/2012 05:19
//	@file Args:

private ["_uid","_handle"];
_uid = getPlayerUID player;

if (!isNull (uiNamespace getVariable ["AdminMenu", displayNull])) exitWith {};

switch (true) do
{
	case ([_uid, serverOwners] call isAdmin || isServer):
	{
		execVM "addons\admin\client\systems\adminPanel\playerMenu.sqf";
	};
	case ([_uid, highAdmins] call isAdmin):
	{
		execVM "addons\admin\client\systems\adminPanel\playerMenu.sqf";
	};
	case ([_uid, lowAdmins] call isAdmin):
	{
		execVM "addons\admin\client\systems\adminPanel\playerMenu.sqf";
	};
	case (serverCommandAvailable "#kick"):
	{
		execVM "addons\admin\client\systems\adminPanel\playerMenu.sqf";
	};
};
