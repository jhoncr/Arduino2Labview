# Arduino2Labview


THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF
ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO
THE IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
PARTICULAR PURPOSE

This code allows the control of any Arduino Board through the Serial port. 

Created by: Jhonatam Cordeiro

#The commands are:

PWM/port1>val1/port2>val2/.../\n
----------------------------------------------------------------------------------------------------------------------------
where a PWM port port1 is set to value val1, PWM port port2 is set to value val2, PWM port port3 is set to value val3 and so on.

the port numbers (port1, port2,...portn) correspond to the PWM port number one wants to control:
the PWM values (val1, val2, ...,valn) is a value from 0 to 255 

DO/port1>val1/port2>val2/.../\n
-----------------------------------------------------------------------------------------------------------------------------
where a Digital port port1 is set to value val1, Digital port port2 is set to value val2, Digital port port3 is set to value val3 and so on.

the port numbers (port1, port2,...portn) correspond to the Digital port number one wants to control:
the values (val1, val2, ...,valn) is a value from are considered "off" if 0 or "on" if different than 0

AI/port1/port2/port3/.../\n
------------------------------------------------------------------------------------------------------------------------------
Read the analogic input of Analog ports port1, port2, port3, ..., portn

example:
AI/0/
return: 123

AI/0/2/
Return: 123,1023

DI/port1,port2,port3/.../\n
-----------------------------------------------------------------------------------------------------------------------------
Read the Digital input of Digital ports port1, port2, port3, ..., portn

example:
DI/0/
return: 0

DI/0/2/3/
Return: 0,1,0

-----------------------------------------------------------------------------------------------------------------------------


 
