// ******************************************************************************************
// * This project is licensed under the GNU Affero GPL v3. Copyright © 2014 A3Wasteland.com *
// ******************************************************************************************
//	@file Version: 1.0
//	@file Name: toggleServerFPS.sqf
//	@file Author: NRZ7 (github.com/NRZ7)
//	@file Created: 09/04/2017
//	@file Args:

if ((getPlayerUID player) call isAdmin) then
{
	if(isNil "NR_toggleServerFPS") then
	{
		NR_toggleServerFPS = 0;
	};
	if (NR_toggleServerFPS == 1) then 
	{ 
		hint "Server FPS OFF";
		NR_toggleServerFPS=0;
		
	} else 
	{ 
		hint "Server FPS in Chat";
		NR_toggleServerFPS=1;
		while {NR_toggleServerFPS == 1} do
		{
		systemchat format["Server FPS: %1",serverFPS];
		sleep 3;
		};
	};
};	