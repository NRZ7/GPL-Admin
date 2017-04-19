// @file Name: refreshZeus.sqf
// @file Author:  wiking.at
// @file Author: www.armajunkies.de
// Refresh of all Mission Objects and set Owner on Zeus Keypress


_uid = getPlayerUID player;

if(_uid in (call zeusAdmins)) then
	{
	_zeusUID =  Format ["aj_var_moduleZeus%1",_uid];
	[_zeusUID] remoteExec ["fn_aj_s_refreshZeus",2];  //trigger zeus refresh on server
	};
