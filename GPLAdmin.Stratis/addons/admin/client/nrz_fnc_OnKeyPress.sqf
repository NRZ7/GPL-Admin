 //////////// On Key Press Event Handlers
 
 waituntil {!isnull (finddisplay 46)};
(findDisplay 46) displayAddEventHandler ["KeyDown","_this select 1 call nrz_fnc_OnKeyPress;false;"];

nrz_fnc_OnKeyPress = {
switch (_this) do {
	
	//Key 6
	case 7: {
		nul = [] execVM "addons\admin\client\systems\adminPanel\checkAdmin.sqf";
	};
	case 21: {
		execVM "addons\aj\zeus\refreshzeus.sqf";
	};
};
};