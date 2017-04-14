// ******************************************************************************************
// * This project is licensed under the GNU Affero GPL v3. Copyright © 2014 A3Wasteland.com *
// ******************************************************************************************
//	@file Version: 1.0
//	@file Name: toggleStamina.sqf
//	@file Author: NRZ7 (github.com/NRZ7)
//	@file Created: 09/04/2017
//	@file Args:

if ((getPlayerUID player) call isAdmin) then
{
	if(isNil "NR_adminStamina") then
	{
		NR_adminStamina = false;
	};
	if (NR_adminStamina) then 
	{ 
		player enableStamina false;
		hint "Stamina OFF";
		NR_adminStamina=false;
		
	} else 
	{ 
		player enableStamina true;
		hint "Stamina ON";
		NR_adminStamina=true;
	};
};