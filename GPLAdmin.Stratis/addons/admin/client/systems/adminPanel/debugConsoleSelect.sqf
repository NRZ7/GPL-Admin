// *****************************************************************************************
// * This script is licensed under the GNU Affero GPL v3. Copyright © 2017 NRZ7
// *****************************************************************************************
//	@file Version: 1.0
//	@file Name: debugLog.sqf
//	@file Author: NRZ7
//	@file Created: 25/11/2012 05:19
//	@file Args:

#define debugConsoleMenuDialog 62111

disableSerialization;

private ["_uid","_dialog","_switch"];

_uid = getPlayerUID player;
if (_uid call isAdmin) then
{
	_dialog = findDisplay debugConsoleMenuDialog;
	_switch = _this select 0;
};



	switch (_switch) do
	{
		case 0: // Log Statement
		{		 
			_update = true;
			_count = count cba_prevStatements - 1;
			if( _count >= 0) then {
				if((cba_prevStatements select _count) == NR_consoleLog) then {
					_update = false;
				};
			};
			if(_update) then {
				
		 
				if(count cba_prevStatements > 9) then {
					cba_prevStatements deleteAt 0;
				};
				cba_prevStatements pushback NR_consoleLog;
				if((count cba_prevStatements) > 1) then {
					ctrlEnable [1956, true];
				} else {
				ctrlEnable [1956, false];
				};
			};
			ctrlEnable [1960, false];
			cba_index = count cba_prevStatements -1;
			//cba_index = (cba_index + 1) min 9;
		};
		 
		case 1: // Previous Statement
		{
			cba_index = ((cba_index - 1) min (((count cba_prevStatements)-1) max 0)) min 9;		
		 
			if(cba_index > -1) then {
				ctrlEnable [1960, true];
			};
			
			if(cba_index <= 0) then {
				ctrlEnable [1956, false];
			};
			
			_prevStatement = cba_prevStatements select cba_index;
			ctrlSetText [1953,_prevStatement];
			NR_consoleLog = ctrlText 1953;
		};
		 
			// 1956 Previous
			// 1960 Next
		case 2: // Next Statement 
		{
			cba_index = (cba_index + 1) max 0;
			_nextStatement = cba_prevStatements select cba_index;
			ctrlSetText [1953,_nextStatement];
			NR_consoleLog = ctrlText 1953;
		 
			if((count cba_prevStatements) > 0) then {
				ctrlEnable [1956, true];
			};
		 
			if(cba_index == 0) then {
				ctrlEnable [1960, false];
			};
			
			if(cba_index == (count cba_prevStatements -1)) then {
				ctrlEnable [1960, false];
			};
		};
		case 3: // Load
		{				
				_storedFunctions = profilenamespace getVariable ["NR_customFuncs",[]];
				ctrlSetText [1953,_storedFunctions select nr_fncIndex];
				NR_consoleLog = ctrlText 1953;
			
		};
		case 4: // Save
		{
			_variableNameList = _dialog displayCtrl 1954;
			
			_variableName = ctrlText 1955;
			_variableContent = ctrlText 1953;
			
			_storedFunctionNames = profileNamespace getVariable ["NR_customNames",[]];
			_storedFunctionNames pushBack _variableName;
			
			_storedFunctions = profilenamespace getVariable ["NR_customFuncs",[]];
			_storedFunctions pushBack _variableContent;
			
			profileNamespace setVariable ["NR_customNames", _storedFunctionNames];
			profileNamespace setVariable ["NR_customFuncs", _storedFunctions];
			
			lbClear _variableNameList;
			{
				_namestr = _x;
				_index = _variableNameList lbAdd _namestr;
				_variableNameList lbSetData [_index, str(_x)];
			} forEach _storedFunctionNames;
		
		};
		case 5: // Delete
		{
			_variableNameList = _dialog displayCtrl 1954;
			
			_storedFunctions = profileNamespace getVariable ["NR_customFuncs",[]];
			_storedFunctionNames = profileNamespace getVariable ["NR_customNames",[]];
			
			_storedFunctions deleteAt nr_fncIndex;
			_storedFunctionNames deleteAt nr_fncIndex;
			
			profileNameSpace setVariable ["NR_customFuncs",_storedFunctions];
			profileNameSpace setVariable ["NR_customNames",_storedFunctionNames];
			
			lbClear _variableNameList;
			{
				_namestr = _x;
				_index = _variableNameList lbAdd _namestr;
				_variableNameList lbSetData [_index, str(_x)];
			} forEach _storedFunctionNames;
			
		};
		case 6: // Execute Server
		{
			_NR_codeExec = _this select 1;
			[_NR_codeExec,2] call NR_fnc_remoteCode;
			[0] execVM 'addons\admin\client\systems\adminPanel\debugConsoleSelect.sqf';
		};
		case 7: // Execute Global
		{
			_NR_codeExec = _this select 1;
			[_NR_codeExec,0] call NR_fnc_remoteCode;
			[0] execVM 'addons\admin\client\systems\adminPanel\debugConsoleSelect.sqf';
		};
		case 8: // Execute Local
		{
			_NR_codeExec = _this select 1;
			call _NR_codeExec;
			[0] execVM 'addons\admin\client\systems\adminPanel\debugConsoleSelect.sqf';
		};
		case 9: // Execute Target
		{
			_NR_codeExec = _this select 1;
			_target = nr_target;
			[_NR_codeExec,_target] call NR_fnc_remoteCode;
			[0] execVM 'addons\admin\client\systems\adminPanel\debugConsoleSelect.sqf';
		};
	};