// ******************************************************************************************
// * This project is licensed under the GNU Affero GPL v3. Copyright © 2017 NRZ7 *
// ******************************************************************************************
//	@file Version: 1.1
//	@file Name: ToggleAIESP.sqf
//	@file Author: NRZ7
//	@file Created: 15/04/2017
//	@file Desc: This file toggle 3D and 2D markers to IA

if ((getPlayerUID player) call isAdmin) then
{
	if(isNil "NR_toggleAIESP") then
	{
		NR_toggleAIESP = false;
	};
	if (!NR_toggleAIESP) then 
	{ 
		hint "NPC Markers ON";
		NR_toggleAIESP=true;
		
		// 2D Markers
		[] spawn {
			private["_dir","_pos","_name","_iconColor","_marker","_markerArray"];
			_markerArray = [];
			
			while {NR_toggleAIESP} do {	
				{
					if(!isPlayer _x) then 
					{
						
						_pos = getPos _x;
						_dir = getDir _x;
						_name = name _x;
						
						switch (side _x) do
						{
							case WEST:      { _iconColor = "ColorBlue" }; 
							case EAST:       { _iconColor = "ColorRed" };
							case resistance: { _iconColor = "ColorGreen" };
							default           { _iconColor = "ColorWhite" };
						};
						_marker = createMarkerLocal [_name, _pos];
						_marker setMarkerDirLocal _dir;
						_marker setMarkerShapeLocal "ICON"; 
						_marker setMarkerColorLocal _iconColor;
						_marker setMarkerTypeLocal "mil_start"; 
						_marker setMarkerTextLocal _name;
						_markerArray pushBack _name;
					};
				} foreach allUnits - allPlayers; sleep 0.5; { deleteMarkerLocal _x } forEach _markerArray; _markerArray = [];
			};
		};
		
		//3D Markers
		addMissionEventHandler ["Draw3D", 
		{ 
			private["_vis","_pos","_groupIcon","_iconColor"]; 
			{ 
				if(!isPlayer _x && player distance _x < 2500) then 
				{ 
					_groupIcon = "\a3\ui_f\data\map\Markers\Military\arrow2_CA.paa";
					switch (side _x) do
								{
									case WEST:      	{ _iconColor = [0, 0, 1, 1] }; 
									case EAST:       	{ _iconColor = [1, 0, 0, 1] };
									case resistance: 	{ _iconColor = [1, 1, 0, 1] };
									default           	{ _iconColor = [1, 1, 1, 1] };
								};
							   _pos = visiblePosition _x; 
							   _pos set[2,(getPosATL _x select 2) + 2.2]; 
							   drawIcon3D [_groupIcon,_iconColor,_pos,0.5,0.5,180,format ["[%1] %2",round (_x distance player),name _x],0,0.04]; 
				}; 
			} foreach allUnits  - allPlayers; 
		}];
	} else 
	{ 
		NR_toggleAIESP=false;
		hint "NPC Markers OFF";
		onEachFrame {};		
	};
};
	

