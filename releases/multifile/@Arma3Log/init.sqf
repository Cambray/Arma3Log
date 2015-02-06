/*
File: init.sqf
Author: Arkensor

Desc: this provides the function that the server will use to log things and send them to the dll


!!! DO NOT MODIFY THIS FILE !!!
*/
Arma3Log = {
_log = _this select 0;
"Arma3Log" callExtension format["%1",_log];
};