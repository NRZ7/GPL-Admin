// ******************************************************************************************
// * This project is licensed under the GNU Affero GPL v3. Copyright © 2014 A3Wasteland.com *
// ******************************************************************************************
//	@file Version: 1.0
//	@file Name: unlimitedAmmo.sqf
//	@file Author: NRZ7 (github.com/NRZ7)
//	@file Created: 09/04/2017
//	@file Args:

if ((getPlayerUID player) call isAdmin) then
{
	if(isNil "NR_adminAmmo") then
	{
		NR_adminAmmo = false;
	};
	if (NR_adminAmmo) then 
	{ 
		player removeEventHandler ["fired", NR_unlimAmmo];
		hint "Unlimited Ammo OFF";
		NR_adminAmmo=false;
		
	} else 
	{ 
		NR_unlimAmmo = player addeventhandler ["fired", {(_this select 0) setvehicleammo 1}];
		hint "Unlimited Ammo ON";
		NR_adminAmmo=true;
	};
};