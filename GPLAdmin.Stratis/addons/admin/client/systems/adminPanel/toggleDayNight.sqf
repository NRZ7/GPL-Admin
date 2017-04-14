if (isDedicated) exitWith {};

if ((getPlayerUID player) call isAdmin) then{
remoteExec ["nr_fnc_daynight"];
};
/*
if ((getPlayerUID player) call isAdmin) then
{
	if ((daytime > 8) && (daytime < 22)) then 
	{ 
		skipTime (22 - daytime + 24 ) % 24; 
	} else 
	{ 
		skipTime (8 - daytime + 24 ) % 24; 
	};
};
*/