// ******************************************************************************************
// * This project is licensed under the GNU Affero GPL v3. Copyright © 2017 NRZ7 *
// ******************************************************************************************
//	@file Version: 1.0
//	@file Name: clientSendViewDistance.sqf
//	@file Author: NRZ7
//	@file Created: 17/04/2017 19:23


_callerUID = getPlayerUID player;
_NR_ViewDistance = _this select 0;

if (_callerUID call isAdmin) then
{	
	if(_NR_ViewDistance <= 199) exitWith
	{
		hint "ERROR: Please, put a value > 199";
	};
	if(_NR_ViewDistance > 10000) exitWith
	{
		hint "ERROR: Max. value is 10000.";
	};
	
	hint format ["%1, %2",_NR_ViewDistance,_callerUID];

	[_NR_ViewDistance] remoteExec ["NR_fnc_ViewDistance",0];
};