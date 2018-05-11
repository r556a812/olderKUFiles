----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    09:43:57 03/25/2015 
-- Design Name: 
-- Module Name:    my_xor3_gate - Behavioral 
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

entity my_xor3_gate is
	PORT (
		D,E,F : IN STD_LOGIC;
		G		: OUT STD_LOGIC);
end my_xor3_gate;

architecture Structural of my_xor3_gate is
	COMPONENT my_xor_gate IS 
		PORT (
			A,B : IN STD_LOGIC;
			C	 : OUT STD_LOGIC);
			END COMPONENT my_xor_gate;
			
			SIGNAL AxorB: STD_LOGIC;
			

begin
	GATE1: my_xor_gate
		PORT MAP (
			A => D,
			B => E,
			C => AxorB);
			
	GATE2: my_xor_gate
		PORT MAP (
			A => AxorB,
			B => F,
			C => G);

end Structural;

