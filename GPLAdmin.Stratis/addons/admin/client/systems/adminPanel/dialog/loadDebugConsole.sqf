// ******************************************************************************************
// * This project is licensed under the GNU Affero GPL v3. Copyright © 2017 NRZ7 *
// ******************************************************************************************
//	@file Version: 1.0
//	@file Name: loadDebugConsole.sqf
//	@file Author: NRZ7
//	@file Created: 22/04/2017 12:23

#define debugConsoleMenuDialog 62111

_dialogPlayer = findDisplay debugConsoleMenuDialog;
_functionsNameList = _dialogPlayer displayCtrl 1954;

disableSerialization;

if (isNil "inDebugConsole") then
{

NR_consoleLog = "";
NR_monitor = "getPos player";
NR_monitor2 = "count allPlayers";
NR_monitor3 = "typeOf cursorTarget";
NR_monitor4 = "count allUnits - count allPlayers";
NR_monitor5 = "vehicle player";
NR_monitor6 = "group player";
};

if (nr_inPlayerMenu) then
{
	ctrlSetText [1976, name nr_target];
} else {
	ctrlEnable [1976, false]; 
};

inDebugConsole = true;

ctrlSetText [1953, NR_consoleLog];

ctrlSetText [1962, NR_monitor];
ctrlSetText [1965, NR_monitor2];
ctrlSetText [1969, NR_monitor3];
ctrlSetText [1971, NR_monitor4];
ctrlSetText [1977, NR_monitor5];
ctrlSetText [1979, NR_monitor6];

if(cba_index < 1) then {
				ctrlEnable [1956, false];
			};
			
if(cba_index <= (count cba_prevStatements)) then {
				ctrlEnable [1960, false];
			};

private ["_uid"];

_uid = getPlayerUID player;

if (_uid call isAdmin) then
{
	_NR_customNames = profileNamespace getVariable ["NR_customNames",[]];
	{
		_namestr = _x;
		_index = _functionsNameList lbAdd _namestr;
		_functionsNameList lbSetData [_index, str(_x)];
	} forEach _NR_customNames;
	[] spawn { 
		while {inDebugConsole} do {
						
			_NR_monitorBox = str (call compile ctrlText 1962); 
			ctrlSetText [1963, _NR_monitorBox]; 
			
			_NR_monitorBox2 = str (call compile ctrlText 1965); 
			ctrlSetText [1966, _NR_monitorBox2]; 
			
			_NR_monitorBox3 = str (call compile ctrlText 1969); 
			ctrlSetText [1970, _NR_monitorBox3]; 
			
			_NR_monitorBox4 = str (call compile ctrlText 1971); 
			ctrlSetText [1972, _NR_monitorBox4];

			_NR_monitorBox5 = str (call compile ctrlText 1977); 
			ctrlSetText [1978, _NR_monitorBox5]; 
			
			_NR_monitorBox6 = str (call compile ctrlText 1979); 
			ctrlSetText [1980, _NR_monitorBox6]; 
			
			sleep 1;
		};
	};
	
};

