// *****************************************************************************************
// * This script is licensed under the GNU Affero GPL v3. Copyright © 2015 A3Wasteland.com *
// *****************************************************************************************
//	@file Version: 1.0
//	@file Name: playerSelect.sqf
//	@file Author: [404] Deadbeat
//	@file Created: 20/11/2012 05:19
//	@file Args:

#define playerMenuDialog 55500
#define playerMenuPlayerList 55505
#define playerMenuSpectateButton 55506
#define playerMenuWarnMessage 55509

disableSerialization;

private ["_dialog","_playerListBox","_spectateButton","_switch","_index","_modSelect","_playerData","_target","_check","_spectating","_camadm","_rnum","_warnText","_targetUID","_playerName"];
_uid = getPlayerUID player;
if (_uid call isAdmin) then
{
	_dialog = findDisplay playerMenuDialog;
	_playerListBox = _dialog displayCtrl playerMenuPlayerList;
	_spectateButton = _dialog displayCtrl playerMenuSpectateButton;
	_warnMessage = _dialog displayCtrl playerMenuWarnMessage;

	_switch = _this select 0;
	_index = lbCurSel _playerListBox;
	_playerData = _playerListBox lbData _index;

	{
		if (str(_x) == _playerData) then {
			_target = _x;
			_check = 1;
		};
	} forEach playableUnits;
	
	if (isNil "_check") exitWith {hint "You need to select a target first!" };
	if (_check == 0) exitWith{};
};

	switch (_switch) do
	{
		case 0: //Spectate
		{
			if (!isNil "_target") then
			{
				closeDialog 0;
				["Initialize", [_target, [], false, true, true, true, true, true, true, true]] call BIS_fnc_EGSpectator;
				waituntil {!IsNull (findDisplay 60492)}; 
				keyDown = (findDisplay 60492) displayAddEventHandler ["KeyDown", "if (_this select 1 == 1) then {['Terminate'] call BIS_fnc_EGSpectator;}"];
			} else {
				closeDialog 0;
				["Initialize", [player, [], false, true, true, true, true, true, true, true]] call BIS_fnc_EGSpectator;
				waituntil {!IsNull (findDisplay 60492)}; 
				keyDown = (findDisplay 60492) displayAddEventHandler ["KeyDown", "if (_this select 1 == 1) then {['Terminate'] call BIS_fnc_EGSpectator;}"];
			};
		};
		case 1: //Warn
		{
			_warnText = ctrlText 55509;
			_playerName = name player;
			_warnText remoteExec ["A3W_fnc_titleTextMessage",_target,false];
		};
		case 2: //Kill
		{
			if (isNil "_target") exitWith {hint "You need to select a target first!" };
			_target setDamage 1;
		};
		case 3: //Kick
		{
			if (isNil "_target") exitWith {hint "You need to select a target first!" };
			_targetName = name _target;
			_target remoteExec ["NR_fnc_kickTarget", 2, false];
			hint format ["%1 has kicked of the game",_targetName];
		};
		case 4: //Unlock Team Killer
		{
			systemChat "Option Disabled";
		};
		case 5: //Open Arsenal on Target
		{
			if (isNil "_target") exitWith {hint "You need to select a target first!" };
			_targetName = name _target;
			_target remoteExec ["NR_fnc_arsenal", _target, false];
			hint format ["Arsenal opened on %1",_targetName];
		};
		case 6: //Remove All Weapons
		{
			if (isNil "_target") exitWith {hint "You need to select a target first!" };
			_targetName = name _target;
			_target remoteExec ["NR_fnc_removeGear", _target, false];
			hint format ["Removed gear from %1",_targetName];
		};
		case 7: //Check Player Gear
		{
			/*_targetUID = getPlayerUID _target;
			{
				if(getPlayerUID _x == _targetUID) exitWith
				{
					createGearDialog [_x, "RscDisplayInventory"];
				};
			}forEach playableUnits;*/
			["This option has been disabled due to having never worked at all in the first place."] spawn BIS_fnc_guiMessage;
		};
		
		case 8: //TPtoME
		{
			if (isNil "_target") exitWith {hint "You need to select a target first!" };
			_adminPos = getPos player;
			_targetName = name _target;
			_target setPos _adminPos;
			hint format ["%1 was teleported to You!",_targetName]
		};
		
		case 9: //TPMeTo
		{
			if (isNil "_target") exitWith {hint "You need to select a target first!" };
			_targetPos = getPos _target;
			_targetName = name _target;
			player setPos _targetPos;
			hint format ["You are teleported to %1!",_targetName]
		};
		
		case 10: //Heal
		{
			if (isNil "_target") exitWith {hint "You need to select a target first!" };
			_targetUID = getPlayerUID _target;
			{
				if(getPlayerUID _x == _targetUID) exitWith
				{
					_x setDamage 0;
				};
			}forEach playableUnits;
		};
		
		case 11: //Kill
		{
			if (isNil "_target") exitWith {hint "You need to select a target first!" };
			_targetUID = getPlayerUID _target;
			{
				if(getPlayerUID _x == _targetUID) exitWith
				{
					_x setDamage 1;
				};
			}forEach playableUnits;
		};
		
		case 12: //UnFreeze
		{
			if (isNil "_target") exitWith {hint "You need to select a target first!" };
			_targetName = name _target;
			_target remoteExec ["NR_fnc_unfreeze", _target, false];
			hint format ["Input enabled on %1",_targetName];
		};
		
		case 13: //Freeze
		{
			if (isNil "_target") exitWith {hint "You need to select a target first!" };
			_targetName = name _target;
			_adminName = name player;
			if (_targetName == _adminName) then
			{
				hint "Your cannot disable your own input!";
			}
			else
			{
				_target remoteExec ["NR_fnc_freeze", _target, false];
				hint format ["Input disabled on %1",_targetName];
			};
		};
		
		case 14: //Repair Refuel Rearm
		{
			if (isNil "_target") exitWith {hint "You need to select a target first!" };
			_target remoteExec ["NR_fnc_RRR", _target, false];

		};
		
		case 15: //Flip
		{
			if (isNil "_target") exitWith {hint "You need to select a target first!" };
			_target remoteExec ["NR_fnc_flip", _target, false];

		};
		
		case 16: //Temp-Ban
		{
			if (isNil "_target") exitWith {hint "You need to select a target first!" };
			_targetName = name _target;
			_adminName = name player;
			if (_targetName == _adminName) then
			{
				hint "BAN yourself is not the best idea";
			}
			else 
			{
			_targetUID = getPlayerUID _target;
			[_targetUID,_adminName] remoteExec ["NR_fnc_tempBanServer", 2, false];

			};
		
		};
		
		case 17: // Execute Code on Target
		{
			if (isNil "_target") exitWith {hint "You need to select a target first!" };
			createDialog "debugConsoleMenu";
			nr_target = _target;
		};
		
		case 18: // Show on map
		{
			if (isNil "_target") exitWith {hint "You need to select a target first!" };
			[_target] execVM "addons\admin\client\systems\adminPanel\targetTeleport.sqf";;
			closeDialog 0;
		};
		
		case 19: // BAN!
		{
			if (isNil "_target") exitWith {hint "You need to select a target first!" };
			_targetName = name _target;
			_adminName = name player;
			if (_targetName == _adminName) then
			{
				hint "BAN yourself is not the best idea";
			}
			else 
			{
			_target remoteExec ["NR_fnc_banTarget", 2, false];
			};
		};
	
	};

