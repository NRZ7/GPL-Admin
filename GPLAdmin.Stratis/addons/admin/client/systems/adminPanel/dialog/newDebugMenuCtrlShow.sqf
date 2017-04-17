// ******************************************************************************************
// * This project is licensed under the GNU Affero GPL v3. Copyright © 2017 NRZ7 *
// ******************************************************************************************
//	@file Version: 1.0
//	@file Name: newDebugMenuCtrlShow.sqf
//	@file Author: NRZ7
//	@file Created: 17/04/2017 12:23

_uid = getPlayerUID player;
if (_uid call isAdmin) then
{
	_switch = _this select 0;
	
	switch (_switch) do
	{
		case 0: // On Load. / Default
		{
			// Test controls
			ctrlShow [1900, false];
			ctrlShow [1901, false];
			
			// Weather controls
			ctrlShow [1902, false];
			ctrlShow [1903, false];
			ctrlShow [1904, false];
			ctrlShow [1905, false];
			ctrlShow [1906, false];
			ctrlShow [1907, false];
			ctrlShow [1908, false];
			ctrlShow [1909, false];
			ctrlShow [1910, false];
			ctrlShow [1911, false];
			ctrlShow [1912, false];
			ctrlShow [1913, false];
			ctrlShow [1914, false];
			ctrlShow [1915, false];
			ctrlShow [1916, false];
			ctrlShow [1917, false];
			ctrlShow [1918, false];
			ctrlShow [1919, false];
			
		};
		
		case 1: // Weather
		{
			// Weather controls
			ctrlShow [1902, true];
			ctrlShow [1903, true];
			ctrlShow [1904, true];
			ctrlShow [1905, true];
			ctrlShow [1906, true];
			ctrlShow [1907, true];
			ctrlShow [1908, true];
			ctrlShow [1909, true];
			ctrlShow [1910, true];
			ctrlShow [1911, true];
			ctrlShow [1912, true];
			ctrlShow [1913, true];
			ctrlShow [1914, true];
			ctrlShow [1915, true];
			ctrlShow [1916, true];
			ctrlShow [1917, true];
			ctrlShow [1918, true];
			ctrlShow [1919, true];
			
		};
	};

};

