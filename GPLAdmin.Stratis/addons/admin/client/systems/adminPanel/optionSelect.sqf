// ******************************************************************************************
// * This project is licensed under the GNU Affero GPL v3. Copyright © 2014 A3Wasteland.com *
// ******************************************************************************************
//	@file Version: 1.0
//	@file Name: optionSelect.sqf
//	@file Author: [404] Deadbeat
//	@file Created: 20/11/2012 05:19

#define debugMenu_option 50003
#define adminMenu_option 50001
disableSerialization;

private ["_panelType","_displayAdmin","_displayDebug","_adminSelect","_debugSelect","_money"];
_uid = getPlayerUID player;
if (_uid call isAdmin) then
{
	_panelType = _this select 0;

	_displayAdmin = uiNamespace getVariable ["AdminMenu", displayNull];
	_displayDebug = uiNamespace getVariable ["DebugMenu", displayNull];

	switch (true) do
	{
		case (!isNull _displayAdmin): //Admin panel
		{
			_adminSelect = _displayAdmin displayCtrl adminMenu_option;

			switch (lbCurSel _adminSelect) do
			{
				case 0: //Player Menu
				{
					closeDialog 0;
					execVM "addons\admin\client\systems\adminPanel\playerMenu.sqf";
					//if (!isNil "notifyAdminMenu") then { ["PlayerManagement", "Opened"] call notifyAdminMenu };
				};
				/*
				case 1: //Full Vehicle Management
				{
					closeDialog 0;
					execVM "addons\admin\client\systems\adminPanel\vehicleManagement.sqf";
					//if (!isNil "notifyAdminMenu") then { ["VehicleManagement", "Opened"] call notifyAdminMenu };
				};
				case 2: //Tags
				{
					execVM "addons\admin\client\systems\adminPanel\playerTags.sqf";
					//Is logged from inside target script
				};
				case 3: //Unstuck player
				{
					closeDialog 0;
					execVM "addons\admin\client\systems\adminPanel\unstuck.sqf";
					//if (!isNil "notifyAdminMenu") then { ["UnstuckPlayer", "Used"] call notifyAdminMenu };
				};
				case 4: //Teleport player to me
				{
					closeDialog 0;
					execVM "addons\admin\client\systems\adminPanel\tptome.sqf";
					//if (!isNil "notifyAdminMenu") then { ["TeleportToMe", "Used"] call notifyAdminMenu };
				};
				case 5: //Teleport me to player
				{
					closeDialog 0;
					execVM "addons\admin\client\systems\adminPanel\tpmeto.sqf";
					//if (!isNil "notifyAdminMenu") then { ["TeleportMeTo", "Used"] call notifyAdminMenu };
				};
				*/
				case 1: //Debug Menu
				{
					closeDialog 0;
					execVM "addons\admin\client\systems\adminPanel\loadDebugMenu.sqf";
					//if (!isNil "notifyAdminMenu") then { ["LoadDebugMenu", "Opened"] call notifyAdminMenu };
				};
				/*
				case 7: //Object search menu
				{
					closeDialog 0;
					execVM "addons\admin\client\systems\adminPanel\loadObjectSearch.sqf";
					//if (!isNil "notifyAdminMenu") then { ["ObjectSearch", "Opened"] call notifyAdminMenu };
				};
				*/
				case 2: // New Debug
				{
					closeDialog 0;
					createDialog "newDebugMenu";
				};
			};
		};
		case (!isNull _displayDebug): //Debug panel
		{
			_debugSelect = _displayDebug displayCtrl debugMenu_option;

			switch (lbCurSel _debugSelect) do
			{
				case 0: //Virtual Arsenal
				{
					closeDialog 0;
					createDialog "balca_debug_main";
				};				
				case 1: //Virtual Arsenal
				{
					closeDialog 0;
					["Open",true] spawn BIS_fnc_arsenal;
				};
				case 2: // Virtual Garage
				{
					closeDialog 0;
					_pos = player getPos [30,getDir player];
					_vehicle = createVehicle [ "Land_HelipadEmpty_F", _pos, [], 0, "CAN_COLLIDE" ]; 
					["Open",[ true, _vehicle ]] call BIS_fnc_garage; 
				};
				case 3: //Teleport
				{
					closeDialog 0;
					openmap true;
					onMapSingleClick "vehicle player setPos _pos; onMapSingleClick '';true;";
					hint "Click on map to teleport";
				};
				case 4: // toggle God mode
				{
					execVM "addons\admin\client\systems\adminPanel\toggleGodMode.sqf";
					//Is logged from inside target script
				};
				case 5: // toggle Invisible
				{
					execVM "addons\admin\client\systems\adminPanel\toggleInvisMode.sqf";
					//Is logged from inside target script
				};
				case 6: // Rearm / Refuel / Repair
				{
					closeDialog 0;
					if ((vehicle player) == player) then {
					cursorTarget setVehicleAmmo 1; cursorTarget setFuel 1; cursorTarget setDamage 0;
					} else {
					(vehicle player) setVehicleAmmo 1;(vehicle player) setfuel 1;(vehicle player) setDamage 0;
					};
				};
				case 7: // Unlimited Ammo
				{
					closeDialog 0;
					execVM "addons\admin\client\systems\adminPanel\toggleUnlimAmmo.sqf";
				};
				case 8: //Show server FPS function
				{
					execVM "addons\admin\client\systems\adminPanel\toggleServerFPS.sqf";
					//if (!isNil "notifyAdminMenu") then { ["ServerFPS", "Used"] call notifyAdminMenu };
				};
				case 9: // Open Debug Console
				{
					closeDialog 0;
					execVM "addons\admin\client\systems\adminPanel\toggleDayNight.sqf";
				};
				case 10: // Open Debug Console
				{
					closeDialog 0;
					(finddisplay 46) createdisplay "RscDisplayDebugPublic";
				};
				/*case 8: //Delete Unlocked Base Objects within 15m
				{
					execVM "addons\admin\client\systems\adminPanel\deleteUnlocked.sqf";
					//if (!isNil "notifyAdminMenu") then { ["DeleteUnlockedObjects", "Opened"] call notifyAdminMenu };
				};
				case 9: //Relock objects within 30m
				{
					execVM "addons\admin\client\systems\adminPanel\reLock.sqf";
					//if (!isNil "notifyAdminMenu") then { ["RelockObjects", "Opened"] call notifyAdminMenu };
				};
				case 10: //Access TOParma News
				{
					[] call loadTOParmaInfo;
					//if (!isNil "notifyAdminMenu") then { ["News", "Opened"] call notifyAdminMenu };
				};*/
			};
		};
	};
};
