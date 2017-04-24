// ******************************************************************************************
// * This project is licensed under the GNU Affero GPL v3. Copyright © 2017 NRZ7 *
// ******************************************************************************************
//	@file Version: 1.0
//	@file Name: loadDebugConsole.sqf
//	@file Author: NRZ7
//	@file Created: 22/04/2017 12:23

#define debugConsoleMenuDialog 62111

disableSerialization;

if (isNil "inDebugConsole") then
{
NR_consoleLog = "";
NR_monitor = "";
NR_monitor2 = "";
NR_monitor3 = "";
NR_monitor4 = "";
};


inDebugConsole = true;

ctrlSetText [1953, NR_consoleLog];

ctrlSetText [1962, NR_monitor];
ctrlSetText [1965, NR_monitor2];
ctrlSetText [1969, NR_monitor3];
ctrlSetText [1971, NR_monitor4];



private ["_uid"];

_uid = getPlayerUID player;

if (_uid call isAdmin) then
{
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
			
			sleep 2;
		};
	};
	
};
