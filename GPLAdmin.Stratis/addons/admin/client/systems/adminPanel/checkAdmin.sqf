// *****************************************************************************************
// * This script is licensed under the GNU Affero GPL v3. Copyright © 2015 A3Wasteland.com *
// *****************************************************************************************
//	@file Version: 1.1
//	@file Name: checkAdmin.sqf
//	@file Author: [404] Deadbeat, AgentRev
//	@file Created: 20/11/2012 05:19
//	@file Args:

private ["_uid","_handle"];
_uid = getPlayerUID player;

if (!isNull (uiNamespace getVariable ["AdminMenu", displayNull])) exitWith {};

switch (true) do
{
	case ([_uid, serverOwners] call isAdmin || isServer):
	{
		execVM "addons\admin\client\systems\adminPanel\loadServerAdministratorMenu.sqf";
		hint "Welcome Boss";
	};
	case ([_uid, highAdmins] call isAdmin):
	{
		execVM "addons\admin\client\systems\adminPanel\loadAdministratorMenu.sqf";
		hint "Welcome High Admin";
	};
	case ([_uid, lowAdmins] call isAdmin):
	{
		execVM "addons\admin\client\systems\adminPanel\loadModeratorMenu.sqf";
		hint "Welcome Low Admin";
	};
	case (serverCommandAvailable "#kick"):
	{
		execVM "addons\admin\client\systems\adminPanel\loadServerAdministratorMenu.sqf";
		hint "Welcome Boss";
	};
};
