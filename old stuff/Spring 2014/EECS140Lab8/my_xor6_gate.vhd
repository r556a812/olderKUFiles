----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    10:00:29 03/25/2015 
-- Design Name: 
-- Module Name:    my_xor6_gate - Behavioral 
-- Project Name: 
-- Target Devices: 
-- Tool versions: 
-- Description: 
--
-- Dependencies: 
--
-- Revision: 
-- Revision 0.01 - File Created
-- Additional Comments: 
--
----------------------------------------------------------------------------------
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.STD_LOGIC_ARITH.ALL;
use IEEE.STD_LOGIC_UNSIGNED.ALL;

---- Uncomment the following library declaration if instantiating
---- any Xilinx primitives in this code.
--library UNISIM;
--use UNISIM.VComponents.all;

entity my_xor6_gate is
	PORT (
		U,V,W,X,Y,Z : IN STD_LOGIC;
		R				: OUT STD_LOGIC);
end my_xor6_gate;

architecture Structural of my_xor6_gate is
	COMPONENT my_xor_gate IS
		PORT (
			A,B : IN STD_LOGIC;
			C	 : OUT STD_LOGIC);
end COMPONENT my_xor_gate;

	COMPONENT my_xor3_gate IS 
		PORT (
			D,E,F : IN STD_LOGIC;
			G		: OUT STD_LOGIC);
end COMPONENT my_xor3_gate;

SIGNAL UxorVxorW: STD_LOGIC;
SIGNAL XxorYxorZ: STD_LOGIC;

begin
UVW: my_xor3_gate
	PORT MAP (
		D => U,
		E => V,
		F => W,
		G => UxorVxorW);
		
XYZ: my_xor3_gate
	PORT MAP (
		D => X,
		E => Y,
		F => Z,
		G => XxorYxorZ);
		
UVWXYZ: my_xor_gate
	PORT MAP (
		A => UxorVxorW,
		B => XxorYxorZ,
		C => R);

end Structural;

