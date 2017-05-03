// *****************************************************************************************
// * This script is licensed under the GNU Affero GPL v3. Copyright © 2017 				   *
// *****************************************************************************************
//	@file Version: 1
//	@file Name: checkDebugMenu.sqf
//	@file Author: [404] Deadbeat, AgentRev, NRZ7
//	@file Created: 03/05/2017 05:19
//	@file Args:

private ["_uid","_handle"];
_uid = getPlayerUID player;

if (!isNull (uiNamespace getVariable ["AdminMenu", displayNull])) exitWith {};

switch (true) do
{
	case ([_uid, serverOwners] call isAdmin || isServer):
	{
		createDialog "debugMenu";
	};
	case ([_uid, highAdmins] call isAdmin):
	{
		createDialog "debugMenu";
	};
	case ([_uid, lowAdmins] call isAdmin):
	{
		createDialog "debugMenu";
	};
	case (serverCommandAvailable "#kick"):
	{
		createDialog "debugMenu";
	};
};
