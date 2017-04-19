// ******************************************************************************************
// * This project is licensed under the GNU Affero GPL v3. Copyright © 2015 A3Wasteland.com *
// ******************************************************************************************
//	@file Version: 1.0
//	@file Name: toggleInvisMode.sqf
//	@file Author: NRZ
//	@file Created: 19/04/2017 9:45

if ((getPlayerUID player) call isAdmin) then
{
	if(isNil "NR_toggleInvisible") then
	{
		NR_toggleInvisible = false;
	};
	if (NR_toggleInvisible) then 
	{ 
		hint "Invisible Mode OFF";
		NR_toggleInvisible=false;
		[player,NR_toggleInvisible] remoteExec ["NR_fnc_serverInvisAdmin",2];
		
	} else 
	{
		hint "Invisible Mode ON";
		NR_toggleInvisible=true;
		[player,NR_toggleInvisible] remoteExec ["NR_fnc_serverInvisAdmin",2];
	};
};
	