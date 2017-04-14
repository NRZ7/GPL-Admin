// *****************************************************************************************
// * This script is licensed under the GNU Lesser GPL v3. Copyright © 2015 A3Wasteland.com *
// *****************************************************************************************
//@file Version: 1.1
//@file Name: init.sqf
//@file Author: [404] Deadbeat, [GoT] JoSchaap, AgentRev, [KoS] Bewilderbeest
//@file Created: 20/11/2012 05:19
//@file Description: The client init.

//if (isDedicated) exitWith {};

[] execVM "addons\admin\client\camera\functions.sqf";

isAdmin = "addons\admin\client\systems\adminPanel\isAdmin.sqf" call mf_compile;//
A3W_fnc_titleTextMessage = "addons\admin\client\titleTextMessage.sqf" call mf_compile;

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

NR_fnc_kick = {
	_target = _this select 0;
	_adminName = _this select 1;
	_targetUID = getPlayerUID _target;
	if (_targetUID == getPlayerUID player) then
	{
		["You are kicked by "+_adminName] spawn BIS_fnc_guiMessage; sleep 0.5;
		endMission "LOSER";		
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

diag_log "A3WAdmin - Client Compile Complete";