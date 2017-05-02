// ******************************************************************************************
// * This project is licensed under the GNU Affero GPL v3. Copyright © 2014 A3Wasteland.com *
// ******************************************************************************************
//	@file Version: 1.0
//	@file Name: playerTags.sqf
//	@file Author: Battleguns, AgentRev
//	@file Created: 30/04/2017 05:19
//	@file Args:

_uid = getPlayerUID player;
if (_uid call isAdmin) then
{
	if (isNil "adminPlayerMarkers") then { adminPlayerMarkers = false };

	if (!adminPlayerMarkers) then
	{
		adminPlayerMarkers = true;
		NR_toggleAIESP = false;
		hint "Player Markers ON";
		//["leadermarkers", "enabled"] call notifyAdminMenu;
		
		[] spawn {
			private["_dir","_pos","_name","_iconColor","_marker","_markerArray"];
			_markerArray = [];
			
			while {adminPlayerMarkers} do {	
				{
					if(isPlayer _x  && _x != player) then 
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
				} foreach allPlayers; sleep 0.5; { deleteMarkerLocal _x } forEach _markerArray; _markerArray = [];
			};
		};
		
		//3D Markers
		onEachFrame 
		{ 
		private["_vis","_pos","_groupIcon","_iconColor"]; 
			{ 
				if(isPlayer _x && player distance _x < 2500 && _x != player) then 
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
			} foreach allPlayers; 
		};
	}
	else
	{
		adminPlayerMarkers = false;
		hint "Player Markers OFF";
	};

};