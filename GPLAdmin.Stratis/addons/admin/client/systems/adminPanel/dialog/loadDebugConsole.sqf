// ******************************************************************************************
// * This project is licensed under the GNU Affero GPL v3. Copyright © 2017 NRZ7 *
// ******************************************************************************************
//	@file Version: 1.0
//	@file Name: loadDebugConsole.sqf
//	@file Author: NRZ7
//	@file Created: 22/04/2017 12:23

#define debugConsoleMenuDialog 62111

disableSerialization;

_dialogPlayer = findDisplay debugConsoleMenuDialog;
_functionsNameList = _dialogPlayer displayCtrl 1954;

_NR_consoleLog = profileNamespace getVariable ["NR_profileConsoleLog",""];
_NR_monitor = profileNamespace getVariable ["NR_profileMonitor","getPos player"];
_NR_monitor2 = profileNamespace getVariable ["NR_profileMonitor2","count allPlayers"];
_NR_monitor3 = profileNamespace getVariable ["NR_profileMonitor3","typeOf cursorTarget"];
_NR_monitor4 = profileNamespace getVariable ["NR_profileMonitor4","count allUnits - count allPlayers"];
_NR_monitor5 = profileNamespace getVariable ["NR_profileMonitor5","vehicle player"];
_NR_monitor6 = profileNamespace getVariable ["NR_profileMonitor6","group player"];

inDebugConsole = true;

if (isNil "nr_inPlayerMenu") then
{
nr_inPlayerMenu = false;
};

if (nr_inPlayerMenu) then
{
	ctrlSetText [1976, name nr_target];
} else {
	ctrlEnable [1976, false]; 
};


ctrlSetText [1953, _NR_consoleLog];

ctrlSetText [1962, _NR_monitor];
ctrlSetText [1965, _NR_monitor2];
ctrlSetText [1969, _NR_monitor3];
ctrlSetText [1971, _NR_monitor4];
ctrlSetText [1977, _NR_monitor5];
ctrlSetText [1979, _NR_monitor6];

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

