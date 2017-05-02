// *****************************************************************************************
// * This script is licensed under the GNU Affero GPL v3. Copyright © 2015 A3Wasteland.com *
// *****************************************************************************************
//	@file Version: 1.1
//	@file Name: init.sqf
//	@file Author: [404] Deadbeat, [GoT] JoSchaap, AgentRev
//	@file Created: 20/11/2012 05:19
//	@file Description: The server init.
//	@file Args:

// All the "hasInterface" and "isServer" checks are to allow this file to be executed on a headless client to offload object saving

if (!isServer && hasInterface) exitWith {};

externalConfigFolder = "\GPLAdmin_settings";

if (isServer) then
{
	[] execVM "addons\admin\server\admins.sqf";
	[] execVM "addons\admin\server\broadcaster.sqf";
};

[] execVM "addons\admin\server\functions\compileServerFuncs.sqf";

diag_log "Admin - Server Compile Finished";