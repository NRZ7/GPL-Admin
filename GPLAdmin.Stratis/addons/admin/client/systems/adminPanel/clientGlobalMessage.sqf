// ******************************************************************************************
// * This project is licensed under the GNU Affero GPL v3. Copyright © 2017 NRZ7 *
// ******************************************************************************************
//	@file Version: 1.0
//	@file Name: clientGlobalMessage.sqf
//	@file Author: NRZ7
//	@file Created: 17/04/2017 18:53


_callerUID = getPlayerUID player;

if (_callerUID call isAdmin) then
{
	_NR_GlobalMessage = _this select 0;
	
	if(_NR_GlobalMessage == "") exitWith
	{
		hint "ERROR: Message can't be empty";
	};
	if(_NR_GlobalMessage == "Write your global message here") exitWith
	{
		hint "ERROR: Please write something...";
	};
	
	hint format ["%1, %2",_NR_GlobalMessage,_callerUID];

	[_NR_GlobalMessage,_callerUID] remoteExec ["NR_fnc_globalMessage"];
};