// *****************************************************************************************
// * This script is licensed under the GNU Affero GPL v3. Copyright © 2015 A3Wasteland.com *
// *****************************************************************************************
//@file Version: 1.1
//@file Name: init.sqf
//@file Author: [404] Deadbeat, [GoT] JoSchaap, AgentRev, [KoS] Bewilderbeest
//@file Created: 20/11/2012 05:19
//@file Description: The client init.

//if (isDedicated) exitWith {};

[] execVM "addons\admin\client\checkBan.sqf";
[] execVM "addons\admin\client\camera\functions.sqf";

isAdmin = "addons\admin\client\systems\adminPanel\isAdmin.sqf" call mf_compile;//
A3W_fnc_titleTextMessage = "addons\admin\client\titleTextMessage.sqf" call mf_compile;

NR_fnc_tempBanClient = {
	_targetUID = _this select 0;
	_adminName = _this select 1;
	if (_targetUID == getPlayerUID player) then
	{
		["banned",false,0.5] call BIS_fnc_endMission;	
	};
};

NR_fnc_freeze = {
	_target = _this;
	_targetUID = getPlayerUID _target;
	if (_targetUID == getPlayerUID player) then
	{
		disableUserInput true;
		hint "An admin disables your controls.";
	};
};

NR_fnc_unfreeze = {
	_target = _this;
	_targetUID = getPlayerUID _target;
	if (_targetUID == getPlayerUID player) then
	{
		disableUserInput false;
	};
};

NR_fnc_arsenal = {
	_target = _this;
	_targetUID = getPlayerUID _target;
	if (_targetUID == getPlayerUID player) then
	{
		["Open",true] spawn BIS_fnc_arsenal;
	};
};

NR_fnc_removeGear = {
	_target = _this;
	_targetUID = getPlayerUID _target;
	if (_targetUID == getPlayerUID player) then
	{
	removeAllWeapons player;
	removeBackpackGlobal player;
	removeVest player;
	removeHeadgear player;
	};
};


NR_fnc_globalMessage = {
	_NR_globalMessage = _this select 0;
	_callerUID = _this select 1;
	if (_callerUID call isAdmin) then
	{
		titleText [_NR_globalMessage, "PLAIN", 0];
	};
};

NR_fnc_weatherChange = {
	_UID = _this select 7;
	_NR_weather_Over = _this select 0;
	_NR_weather_Fog = _this select 1;
	_NR_weather_Rain = _this select 2;
	_NR_weather_Waves = _this select 3;
	_NR_weather_Lightnings = _this select 4;
	_NR_weather_windEast = _this select 5;
	_NR_weather_windNorth = _this select 6;

	10 setOvercast _NR_weather_Over;
	10 setFog _NR_weather_Fog;
	10 setRain _NR_weather_Rain;
	10 setWaves _NR_weather_Waves;
	10 setLightnings _NR_weather_Lightnings;
	setWind [_NR_weather_windEast, _NR_weather_windNorth, true];
	forceWeatherChange;

};

NR_fnc_remoteCode = {
	_UID = getPlayerUID player;
	if (_UID call isAdmin) then
	{
		_codeToExec = _this select 0;
		_target = _this select 1;
		hint format ["%1, %2, %3",_codeToExec,_UID,_target];

		[_codeToExec,_UID] remoteExec ["NR_fnc_remoteExecution",_target];
		
	};
};

NR_fnc_remoteExecution = {
	_codeToExec = _this select 0;
	_callerUID = _this select 1;
	if (_callerUID call isAdmin) then
	{
		call _codeToExec;
		
	};
};

NR_fnc_RRR = {
	_target = _this;
	_targetUID = getPlayerUID _target;
	if (_targetUID == getPlayerUID player) then {
		if ((vehicle player) == player) then {
		cursorTarget setVehicleAmmo 1; cursorTarget setFuel 1; cursorTarget setDamage 0;
		} else {
		(vehicle player) setVehicleAmmo 1;(vehicle player) setfuel 1;(vehicle player) setDamage 0;
		};
	};
};

NR_fnc_flip = {
	_target = _this;
	_targetUID = getPlayerUID _target;
	if (_targetUID == getPlayerUID player) then 
	{
		private ["_obj","_pos","_xPos","_yPos","_zPos"];

		if ((vehicle player) == player) then {
			_obj = cursorobject;
		} else {
			_obj = vehicle player;
		};
			_pos = getPos _obj;
			_xPos = _pos select 0;
			_yPos = _pos select 1;
			_zPos = _pos select 2;
			_zPos = _zPos +1;
			_obj setPos [_xPos,_yPos,_zPos];
			_obj setVectorUp [0,0,1];
	};
};

////////////// Defining variables (for admins)
cba_index = -1;
cba_prevStatements = [];
////////////// End of variables

diag_log "GPL Admin - Client Compile Complete";

waituntil {!isNull findDisplay 46 && getPlayerUID player != ''};

_UID = getPlayerUID player;
if (_UID call isAdmin) then
{
	[] spawn {
		while{true} do {
			waitUntil{inputAction "user20" > 0};
			execVM "addons\admin\client\systems\adminPanel\playerMenu.sqf";
			waitUntil{inputAction "user20" == 0};
		};
	};
	[] spawn {
		while{true} do {
			waitUntil{inputAction "user19" > 0};
			createDialog "debugMenu";
			waitUntil{inputAction "user19" == 0};
		};
	};
	[] spawn {
		while{true} do {
			waitUntil{inputAction "user18" > 0};
			createDialog "debugConsoleMenu";
			waitUntil{inputAction "user18" == 0};
		};
	};
};